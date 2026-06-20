__int64 cam_cpas_dump_camnoc_buff_fill_info()
{
  __int64 v0; // x9
  __int64 (__fastcall *v1)(__int64, __int64, int *, __int64); // x8
  __int64 v2; // x0
  __int64 result; // x0
  unsigned int v4; // w19
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v0 = *(_QWORD *)(g_cpas_intf + 480);
    v1 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v0 + 88);
    if ( v1 )
    {
      v2 = *(_QWORD *)(v0 + 112);
      if ( *((_DWORD *)v1 - 1) != -1055839300 )
        __break(0x8228u);
      result = v1(v2, 16, &v5, 4);
      if ( (_DWORD)result )
      {
        v4 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_dump_camnoc_buff_fill_info",
          337,
          "Failed in process_cmd, rc=%d",
          result);
        result = v4;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_dump_camnoc_buff_fill_info",
        339,
        "Invalid process_cmd ops");
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dump_camnoc_buff_fill_info",
      327,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
