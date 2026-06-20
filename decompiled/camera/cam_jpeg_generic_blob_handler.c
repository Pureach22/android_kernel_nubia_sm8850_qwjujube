__int64 __fastcall cam_jpeg_generic_blob_handler(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x4

  if ( !a3 || !a1 || !a4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_generic_blob_handler",
      93,
      "Invalid arguments. blob_data: %p user_data: %p blob_size: %u",
      a4,
      a1,
      a3);
    return 4294967274LL;
  }
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_generic_blob_handler",
      97,
      "blob_type: %u, blob_size: %u",
      a2,
      a3);
    if ( a2 == 1 )
      goto LABEL_7;
LABEL_12:
    v7 = "Invalid blob_tye: %u";
    v8 = 512;
    v9 = 1;
    v10 = 105;
    goto LABEL_13;
  }
  if ( a2 != 1 )
    goto LABEL_12;
LABEL_7:
  result = 0;
  *a1 = *a4;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    v7 = "Thumbnail max size: %u bytes";
    v8 = debug_mdl & 0x200;
    v9 = 4;
    v10 = 102;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v8,
      v9,
      "cam_jpeg_generic_blob_handler",
      v10,
      v7);
    return 0;
  }
  return result;
}
