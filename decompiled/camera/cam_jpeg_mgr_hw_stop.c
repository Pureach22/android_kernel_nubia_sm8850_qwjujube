__int64 __fastcall cam_jpeg_mgr_hw_stop(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20

  if ( !a1 || !a2 || !*(_QWORD *)a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_hw_stop",
      1355,
      "Invalid args");
    return 4294967274LL;
  }
  mutex_lock(a1);
  if ( (*(_BYTE *)(*(_QWORD *)a2 + 104LL) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_hw_stop",
      1362,
      "ctx is not in use");
    mutex_unlock(a1);
    return 4294967274LL;
  }
  v4 = cam_jpeg_mgr_flush(a1);
  if ( v4 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_hw_stop",
      1369,
      "flush failed %d",
      v4);
  mutex_unlock(a1);
  return v4;
}
