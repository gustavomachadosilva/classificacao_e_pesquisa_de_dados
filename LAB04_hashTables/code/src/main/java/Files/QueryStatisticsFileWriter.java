package Files;

import java.io.IOException;
import java.io.RandomAccessFile;

public class QueryStatisticsFileWriter extends FileManagerWriter{

    public QueryStatisticsFileWriter(String fileName) throws Exception {
        super(fileName);
    }

    public void writeLine(String line) throws IOException {
        String formattedLine = line.replace("[", "").replace("]", "");

        bufferedWriter.write(formattedLine);
        bufferedWriter.newLine();
    }
}
