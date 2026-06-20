__int64 __fastcall cam_cpas_register_client(__int64 a1)
{
  __int64 v1; // x9
  _DWORD *v2; // x8
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w19

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v1 = *(_QWORD *)(g_cpas_intf + 480);
    v2 = *(_DWORD **)(v1 + 88);
    if ( v2 )
    {
      v4 = *(_QWORD *)(v1 + 112);
      if ( *(v2 - 1) != -1055839300 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v2)(v4, 0, a1, 168);
      if ( (_DWORD)result )
      {
        v6 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_register_client",
          998,
          "Failed in process_cmd, rc=%d",
          result);
        return v6;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_register_client",
        1000,
        "Invalid process_cmd ops");
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_register_client",
      988,
      "cpas intf not initialized");
    return 4294967277LL;
  }
  return result;
}
