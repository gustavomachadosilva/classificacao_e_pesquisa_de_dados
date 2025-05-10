package Files;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class FileManagerWriter implements FileManager{

    protected final String fileName;
    protected BufferedWriter bufferedWriter = null;

    public FileManagerWriter(String fileName) throws Exception {
        this.fileName = fileName;
        this.setup();
    }

    @Override
    public void setup() {
        try {
            this.bufferedWriter = new BufferedWriter(new FileWriter(fileName));
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void close() {
        try {
            bufferedWriter.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());;
        }
    }
}
