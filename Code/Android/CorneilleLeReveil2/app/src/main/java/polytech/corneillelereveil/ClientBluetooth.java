package polytech.corneillelereveil;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import java.io.IOException;
import java.io.OutputStream;
import java.util.UUID;

class ClientBluetooth {
    private final BluetoothSocket mBlueSocket;
    private final OutputStream mOutStream;

    ClientBluetooth(BluetoothDevice device) {
        // On utilise un objet temporaire car blueSocket et blueDevice sont "final"
        BluetoothSocket tmp = null;
        OutputStream tmpOut = null;

        // On récupère un objet BluetoothSocket grâce à l'objet BluetoothDevice
        try {
            tmp = device.createRfcommSocketToServiceRecord(UUID.fromString("00001101-0000-1000-8000-00805F9B34FB")); //UUID (identifiant) utilisé par défaut par les "serial board"
        } catch (IOException e) {e.printStackTrace();}
        mBlueSocket = tmp;

        try {
            tmpOut = mBlueSocket.getOutputStream();
        } catch (IOException e) {e.printStackTrace();}
        mOutStream = tmpOut;
    }

    boolean run() {
        try {
            // On se connecte. Cet appel est bloquant jusqu'à la réussite ou la levée d'une erreur
            mBlueSocket.connect();
            return true;
        } catch (IOException connectException) {
            connectException.printStackTrace();
            // Impossible de se connecter, on ferme la socket et on tue le thread
            try {
                mBlueSocket.close();
            } catch (IOException e) {e.printStackTrace();}
            return false;
        }
    }

    boolean write(String input) {
        byte[] bytes = input.getBytes();           //converts entered String into bytes
        try {
            mOutStream.write(bytes);
            return true;
        } catch (IOException e) {e.printStackTrace(); return false;}
    }

    // Annule toute connexion en cours et tue le thread
    void cancel() {
        try {
            mBlueSocket.close();
        } catch (IOException e) {e.printStackTrace();}
    }
}