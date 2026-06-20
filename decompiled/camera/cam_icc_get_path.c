__int64 __fastcall cam_icc_get_path(__int64 a1, int a2, int a3, const char *a4, char a5)
{
  const char *v6; // x10
  const char *v7; // x19
  __int64 v8; // x20

  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    v6 = "Y";
    v7 = a4;
    if ( (a5 & 1) == 0 )
      v6 = "N";
    v8 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_icc_get_path",
      1085,
      "Get icc path name: %s src_id:%d dst_id:%d use_path_name:%s",
      a4,
      a2,
      a3,
      v6);
    a1 = v8;
    a4 = v7;
    if ( (a5 & 1) != 0 )
      return of_icc_get(a1, a4);
  }
  else if ( (a5 & 1) != 0 )
  {
    return of_icc_get(a1, a4);
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_icc_get_path",
    1089,
    "Must use path names to get icc path handle");
  return 0;
}
