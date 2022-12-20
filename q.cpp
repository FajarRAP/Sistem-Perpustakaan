#include <iostream>

void garis(int x) {
  if (x != 0) {
    std::cout << "=";
    garis(x - 1);
  } else {
    std::cout << std::endl;
  }
}

int main() {
  garis(37);
  std::cout << "|>>           Sorting?            <<|" << std::endl;
  garis(37);
  std::cout << "|>>       1. Judul Asc           <<|" << std::endl;
  garis(37);
  std::cout << "|>>       2. Judul Desc          <<|" << std::endl;
  garis(37);
  std::cout << "|>>       3. Penulis Asc         <<|" << std::endl;
  garis(37);
  std::cout << "|>>       4. Penulis Desc        <<|" << std::endl;
  garis(37);
  std::cout << "|>>       5. Tahun Terbit Asc    <<|" << std::endl;
  garis(37);
  std::cout << "|>>       6. Tahun Terbit Desc   <<|" << std::endl;
  garis(37);
  std::cout << "|>>       7. Stok Asc            <<|" << std::endl;
  garis(37);
  std::cout << "|>>       8. Stok Desc           <<|" << std::endl;
  garis(37);
  std::cout << "Pilih : ";
}