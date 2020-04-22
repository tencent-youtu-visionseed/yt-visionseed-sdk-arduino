/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.2 at Fri Apr 17 15:16:50 2020. */

#ifndef PB_FILELISTRESULT_PB_H_INCLUDED
#define PB_FILELISTRESULT_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _FileInfo {
    char *name;
    bool isFolder;
    int32_t size;
/* @@protoc_insertion_point(struct:FileInfo) */
} FileInfo;

typedef struct _FileListResult {
    char *folder;
    int32_t total;
    pb_size_t files_count;
    struct _FileInfo *files;
/* @@protoc_insertion_point(struct:FileListResult) */
} FileListResult;

/* Default values for struct fields */

/* Initializer values for message structs */
#define FileInfo_init_default                    {NULL, 0, 0}
#define FileListResult_init_default              {NULL, 0, 0, NULL}
#define FileInfo_init_zero                       {NULL, 0, 0}
#define FileListResult_init_zero                 {NULL, 0, 0, NULL}

/* Field tags (for use in manual encoding/decoding) */
#define FileInfo_name_tag                        1
#define FileInfo_isFolder_tag                    2
#define FileInfo_size_tag                        3
#define FileListResult_folder_tag                1
#define FileListResult_total_tag                 2
#define FileListResult_files_tag                 3

/* Struct field encoding specification for nanopb */
extern const pb_field_t FileInfo_fields[4];
extern const pb_field_t FileListResult_fields[4];

/* Maximum encoded size of messages (where known) */
/* FileInfo_size depends on runtime parameters */
/* FileListResult_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define FILELISTRESULT_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
