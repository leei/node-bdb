// Copyright 2001 Mark Cavage <mark@bluesnoop.com> Sleepycat License
#ifndef BDB_TXN_H_
#define BDB_TXN_H_

#include <db.h>

#include "bdb_object.h"

class DbTxn: public DbObject {
public:
  DbTxn();
  virtual ~DbTxn();

  DB_TXN *&getDB_TXN();

  static void Initialize(v8::Handle<v8::Object>);

  static v8::Handle<v8::Value> New(const v8::Arguments &);
  static v8::Handle<v8::Value> Id(const v8::Arguments &);
  static v8::Handle<v8::Value> Abort(const v8::Arguments &);
  static v8::Handle<v8::Value> Commit(const v8::Arguments &);

private:
  DbTxn(const DbTxn &);
  DbTxn &operator=(const DbTxn &);

  static int EIO_Abort(eio_req *);
  static int EIO_Commit(eio_req *);
  static int EIO_After(eio_req *);

  DB_TXN *_txn;
};

#endif  // BDB_TXN_H_