#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "hdb.h"

int main(void) {

  struct hdb_opts opts = {
      .readonly = false,
  };

  struct hdb *H;
  struct hdb_tx *tx;

  H = hdb_open("a.db", opts);
  assert(H);

  tx = hdb_begin(H, true);  // opens a writable transaction.
  assert(tx);

  hdb_write(tx, "foo", "bar");
  hdb_commit(tx);

  char buf[32];
  hdb_read(tx, "foo", buf);
  printf("foo = %s\n", buf);

  hdb_close(H);

  return 0;
}
