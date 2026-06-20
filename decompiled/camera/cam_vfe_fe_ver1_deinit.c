__int64 __fastcall cam_vfe_fe_ver1_deinit(_QWORD *a1)
{
  _QWORD *v2; // x0

  v2 = (_QWORD *)a1[3];
  a1[3] = 0;
  a1[11] = 0;
  a1[12] = 0;
  a1[13] = 0;
  a1[14] = 0;
  a1[15] = 0;
  if ( v2 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v2, 0);
    else
      kvfree(v2);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_ver1_deinit",
      618,
      "Error! fe_priv is NULL");
    return 4294967277LL;
  }
}
