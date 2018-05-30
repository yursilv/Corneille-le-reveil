package polytech.corneillelereveil;

import android.app.AlertDialog;
import android.app.TimePickerDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.pm.ActivityInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Set;

public class MainActivity extends AppCompatActivity {

    private TextView nomBT = null;
    private TextView time;
    private BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
    protected ClientBluetooth mBTclient = null;
    String foundDeviceName = null;
    boolean deviceConnected = false;


    private boolean[] joursChecked = {false,false,false,false,false,false,false};
    private int[] joursId = {R.id.checkLundi,R.id.checkMardi,R.id.checkMercredi,R.id.checkJeudi,R.id.checkVendredi,R.id.checkSamedi,R.id.checkDimanche};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        time = findViewById(R.id.time);
        nomBT = findViewById(R.id.nomBT);
        setRequestedOrientation (ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
    }

    public String getTimeDate() {
        Date c = Calendar.getInstance().getTime();
        SimpleDateFormat form = new SimpleDateFormat("ssmmHHuddMMyy");
        return form.format(c);
    }

    public void clickConn(View view) {
        if (bluetoothAdapter == null) {
            Toast.makeText(MainActivity.this, "Bluetooth non trouvé", Toast.LENGTH_SHORT).show();
        } else {
            if (!bluetoothAdapter.isEnabled()) {
                bluetoothAdapter.enable();
            }

            if (foundDeviceName == null) {
                connect(bluetoothAdapter.getBondedDevices());
            } else {
                if (!foundDeviceName.equals(nomBT.getText().toString())) {
                    mBTclient.cancel();
                    mBTclient = null;
                    deviceConnected = false;
                    foundDeviceName = null;
                    connect(bluetoothAdapter.getBondedDevices());
                }
            }

            if (deviceConnected) {
                String heure = time.getText().toString();
                String data = getTimeDate();
                if (!heure.equals("")) {
                    data+=heure.replace(":", "");
                    boolean[] joursUnchecked = {false,false,false,false,false,false,false};
                    if (joursChecked != joursUnchecked) {
                        for (int i=0; i<joursChecked.length; i++) {
                            if (joursChecked[i]) {
                                switch(i) {
                                    case 0: data+="1"; break;
                                    case 1: data+="2"; break;
                                    case 2: data+="3"; break;
                                    case 3: data+="4"; break;
                                    case 4: data+="5"; break;
                                    case 5: data+="6"; break;
                                    case 6: data+="7"; break;
                                }
                            } else {
                                data+="0";
                            }
                        }
                        if (mBTclient.write(data)) {
                            Toast.makeText(MainActivity.this, data, Toast.LENGTH_SHORT).show();
                            Toast.makeText(MainActivity.this, "Envoyé", Toast.LENGTH_SHORT).show();
                        } else {
                            Toast.makeText(MainActivity.this, "Problème d'envoi", Toast.LENGTH_SHORT).show();
                        }
                    } else {
                        Toast.makeText(MainActivity.this, "Jours non définis", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(MainActivity.this, "Heure non définie", Toast.LENGTH_SHORT).show();
                }
            } else {
                Toast.makeText(MainActivity.this, "Non connecté", Toast.LENGTH_SHORT).show();
            }
        }
    }

    void connect(Set<BluetoothDevice> pairedDevices) {
        String enteredDevice = nomBT.getText().toString();
        for (BluetoothDevice device : pairedDevices) {
            if (device.getName().equals(enteredDevice)) {
                mBTclient = new ClientBluetooth(device);
                if (mBTclient.run()) {
                    deviceConnected = true;
                    foundDeviceName = device.getName();
                } else {
                    deviceConnected = false;
                    foundDeviceName = null;
                }
            }
        }
    }

    public void clickTime(View v) {
        Calendar mCurrentTime = Calendar.getInstance();
        int hour = mCurrentTime.get(Calendar.HOUR_OF_DAY);
        int minute = mCurrentTime.get(Calendar.MINUTE);
        TimePickerDialog mTimePicker;
        mTimePicker = new TimePickerDialog(MainActivity.this, AlertDialog.THEME_DEVICE_DEFAULT_DARK, new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker timePicker, int selectedHour, int selectedMinute) {
                //vérifie si les minutes sont composées d'un seul chiffre
                if (String.valueOf(selectedMinute).length() == 1) {
                    time.setText(selectedHour + ":" + "0" + selectedMinute);
                } else {
                    time.setText(selectedHour + ":" + selectedMinute);
                }
            }
        }, hour, minute, true);
        mTimePicker.setTitle(R.string.time_hint);
        mTimePicker.show();
    }

    public void onCheckboxClicked(View view) {
        // Is the view now checked?
        boolean checked = ((CheckBox) view).isChecked();
        int jourId = view.getId();
        for (int i=0; i<joursId.length; i++) {
            if (jourId==joursId[i]) {
                joursChecked[i] = checked;
                break;
            }
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mBTclient.cancel();
    }
}