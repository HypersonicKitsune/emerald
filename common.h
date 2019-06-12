#ifndef COMMON_H
#define COMMON_H


/* Engine setup */

void init_allegro();
void release_all();

/* Logfile */

void logfile_init();
void logfile_message(const char *msg, ...);
void logfile_close();

/* User/debugging notifications */

void error(const char *msg);
void warning(const char *header, const char *msg);
void dbg(const char *msg, ...);

#endif // COMMON_H
