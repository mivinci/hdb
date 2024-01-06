#ifndef HDB_H
#define HDB_H

#ifdef __cplusplus
extern "C" {
#endif

struct hdb_opts {
  bool readonly;
};

struct hdb;
struct hdb_tx;

struct hdb *hdb_open(const char *, struct hdb_opts);
void hdb_close(struct hdb *);
int hdb_sync(struct hdb *);

struct hdb_tx *hdb_begin(struct hdb *, bool);
int hdb_commit(struct hdb_tx *);
int hdb_rollback(struct hdb_tx *);
int hdb_read(struct hdb_tx *, const char *, char *);
int hdb_write(struct hdb_tx *, const char *, const char *);
int hdb_delete(struct hdb_tx *, const char *);

#ifdef __cplusplus
}
#endif

#endif  // HDB_H