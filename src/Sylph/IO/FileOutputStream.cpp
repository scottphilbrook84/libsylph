#include "FileOutputStream.h"

SYLPH_BEGIN_NAMESPACE
FileOutputStream::FileOutputStream(File& f, IO::IOType t) {
    fptr = fopen(f.toCanonicalName().utf8(), t & IO::Append ? (t & IO::Binary ?
            "ab" : "a") : (t & IO::Binary ? "w" : "wb"));
    if (fptr == null) {
        sthrow(IOException, (String("Unable to open file ") +
                f.toCanonicalName()).utf8());
    }
}
FileOutputStream::~FileOutputStream() {
    flush();
    close();
}

void FileOutputStream::write(const Array<byte> b, off_t off, size_t len) {
    if (closed) sthrow(IOException, "Tried to write to a closed OutputStream!");
    if (len == 0) len = b.length;
    if (off + len > b.length) sthrow(ArrayException, "Array out of bounds");
    unsigned i = fwrite(b.carray(), 1, b.length, fptr);
    if(i != b.length) sthrow(IOException, "Unable to write to file");
}
void FileOutputStream::close() {
    OutputStream::close();
    fclose(fptr);
}

void FileOutputStream::flush() {
    fflush(fptr);
}

OutputStream & FileOutputStream::operator<<(const byte b) {
    if (closed) sthrow(IOException, "Tried to write to a closed OutputStream!");
    int i = fwrite(&b, 1, 1, fptr);
    if(i != 1) sthrow(IOException, "Unable to write to file");
    return *this;
}
SYLPH_END_NAMESPACE