#!/usr/bin/env node

var exec  = require('child_process').exec;

exec("cp ./deps/db-6*/build_unix/db.h " + process.installPrefix + '/include/node',
     function(err, stdout, stderr) {});

