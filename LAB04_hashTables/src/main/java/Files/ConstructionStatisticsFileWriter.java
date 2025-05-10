package Files;

import java.io.IOException;

public class ConstructionStatisticsFileWriter extends FileManagerWriter{

    public ConstructionStatisticsFileWriter(String fileName) throws Exception {
        super(fileName);
    }

    public void writeLine(String line) throws IOException {
        String formattedLine = line.replace("[", "").replace("]", "");

        bufferedWriter.write(formattedLine);
        bufferedWriter.newLine();
    }

}
