/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.2 at Fri Apr 17 15:16:49 2020. */

#include "YtMsg.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t ResultDataNG_fields[3] = {
    PB_FIELD(  1, STRING  , REQUIRED, CALLBACK, FIRST, ResultDataNG, key, key, 0),
    PB_FIELD(  2, FLOAT   , REPEATED, CALLBACK, OTHER, ResultDataNG, values, key, 0),
    PB_LAST_FIELD
};

const pb_field_t YtResult_fields[6] = {
    PB_FIELD(  1, UINT64  , OPTIONAL, STATIC  , FIRST, YtResult, frameId, frameId, 0),
    PB_FIELD(  2, UINT64  , OPTIONAL, STATIC  , OTHER, YtResult, frameTimestampUs, frameId, 0),
    PB_ONEOF_FIELD(data,   3, MESSAGE , ONEOF, STATIC  , OTHER, YtResult, faceDetectionResult, frameTimestampUs, &FaceDetectionResult_fields),
    PB_ONEOF_FIELD(data,   5, STRING  , ONEOF, POINTER , UNION, YtResult, msgOutput, frameTimestampUs, 0),
    PB_FIELD(101, BYTES   , OPTIONAL, POINTER , OTHER, YtResult, dataV2, data.msgOutput, 0),
    PB_LAST_FIELD
};

const pb_field_t YtRpc_fields[14] = {
    PB_FIELD(  1, UENUM   , REQUIRED, STATIC  , FIRST, YtRpc, func, func, 0),
    PB_FIELD(  2, INT32   , OPTIONAL, STATIC  , OTHER, YtRpc, sequenceId, func, 0),
    PB_ONEOF_FIELD(params,   3, STRING  , ONEOF, STATIC  , OTHER, YtRpc, strParams, sequenceId, 0),
    PB_ONEOF_FIELD(params,   4, INT32   , ONEOF, STATIC  , UNION, YtRpc, intParams, sequenceId, 0),
    PB_ONEOF_FIELD(params,  10, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, cameraExposureParams, sequenceId, &CameraExposureParams_fields),
    PB_ONEOF_FIELD(params,  11, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, flasherParams, sequenceId, &FlasherParams_fields),
    PB_ONEOF_FIELD(params,  21, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, filePart, sequenceId, &FilePart_fields),
    PB_ONEOF_FIELD(params,  53, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, registerFaceIdWithPicParams, sequenceId, &RegisterFaceIdWithPicParams_fields),
    PB_ONEOF_FIELD(params,  54, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, registerFaceIdFromCameraParams, sequenceId, &RegisterFaceIdFromCameraParams_fields),
    PB_ONEOF_FIELD(params,  55, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, setFaceIdParams, sequenceId, &SetFaceIdParams_fields),
    PB_ONEOF_FIELD(params,  56, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, listFaceIdParams, sequenceId, &ListFaceIdParams_fields),
    PB_ONEOF_FIELD(params,  57, MESSAGE , ONEOF, STATIC  , UNION, YtRpc, registerFaceIdWithTraceIdParams, sequenceId, &RegisterFaceIdWithTraceIdParams_fields),
    PB_FIELD(100, STRING  , OPTIONAL, STATIC  , OTHER, YtRpc, auth, params.registerFaceIdWithTraceIdParams, 0),
    PB_LAST_FIELD
};

const pb_field_t YtRpcResponse_fields[8] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, YtRpcResponse, sequenceId, sequenceId, 0),
    PB_FIELD(  2, UENUM   , REQUIRED, STATIC  , OTHER, YtRpcResponse, code, sequenceId, 0),
    PB_ONEOF_FIELD(data,   3, STRING  , ONEOF, POINTER , OTHER, YtRpcResponse, strData, code, 0),
    PB_ONEOF_FIELD(data,   4, INT32   , ONEOF, STATIC  , UNION, YtRpcResponse, intData, code, 0),
    PB_ONEOF_FIELD(data,  20, MESSAGE , ONEOF, STATIC  , UNION, YtRpcResponse, fileListResult, code, &FileListResult_fields),
    PB_ONEOF_FIELD(data,  40, MESSAGE , ONEOF, STATIC  , UNION, YtRpcResponse, filePart, code, &FilePart_fields),
    PB_ONEOF_FIELD(data,  50, MESSAGE , ONEOF, STATIC  , UNION, YtRpcResponse, faceIdListData, code, &FaceIdListData_fields),
    PB_LAST_FIELD
};

const pb_field_t YtMsg_fields[2] = {
    PB_ONEOF_FIELD(values,   3, MESSAGE , ONEOF, STATIC  , FIRST, YtMsg, result, result, &YtResult_fields),
    PB_LAST_FIELD
};




/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(YtResult, data.faceDetectionResult) < 65536 && pb_membersize(YtRpc, params.cameraExposureParams) < 65536 && pb_membersize(YtRpc, params.flasherParams) < 65536 && pb_membersize(YtRpc, params.filePart) < 65536 && pb_membersize(YtRpc, params.registerFaceIdWithPicParams) < 65536 && pb_membersize(YtRpc, params.registerFaceIdFromCameraParams) < 65536 && pb_membersize(YtRpc, params.setFaceIdParams) < 65536 && pb_membersize(YtRpc, params.listFaceIdParams) < 65536 && pb_membersize(YtRpc, params.registerFaceIdWithTraceIdParams) < 65536 && pb_membersize(YtRpcResponse, data.fileListResult) < 65536 && pb_membersize(YtRpcResponse, data.filePart) < 65536 && pb_membersize(YtRpcResponse, data.faceIdListData) < 65536 && pb_membersize(YtMsg, values.result) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_ResultDataNG_YtResult_YtRpc_YtRpcResponse_YtMsg)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(YtResult, data.faceDetectionResult) < 256 && pb_membersize(YtRpc, params.cameraExposureParams) < 256 && pb_membersize(YtRpc, params.flasherParams) < 256 && pb_membersize(YtRpc, params.filePart) < 256 && pb_membersize(YtRpc, params.registerFaceIdWithPicParams) < 256 && pb_membersize(YtRpc, params.registerFaceIdFromCameraParams) < 256 && pb_membersize(YtRpc, params.setFaceIdParams) < 256 && pb_membersize(YtRpc, params.listFaceIdParams) < 256 && pb_membersize(YtRpc, params.registerFaceIdWithTraceIdParams) < 256 && pb_membersize(YtRpcResponse, data.fileListResult) < 256 && pb_membersize(YtRpcResponse, data.filePart) < 256 && pb_membersize(YtRpcResponse, data.faceIdListData) < 256 && pb_membersize(YtMsg, values.result) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_ResultDataNG_YtResult_YtRpc_YtRpcResponse_YtMsg)
#endif


/* @@protoc_insertion_point(eof) */
