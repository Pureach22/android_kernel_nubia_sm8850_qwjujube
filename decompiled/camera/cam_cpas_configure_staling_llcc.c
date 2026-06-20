__int64 __fastcall cam_cpas_configure_staling_llcc(int a1, int a2, int a3, int a4)
{
  __int64 v4; // x9
  _DWORD *v5; // x8
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w19
  _DWORD v9[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v4 = *(_QWORD *)(g_cpas_intf + 480);
    v9[2] = a2;
    v9[3] = a3;
    v9[0] = a1;
    v9[1] = a4;
    v5 = *(_DWORD **)(v4 + 88);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v4 + 112);
      if ( *(v5 - 1) != -1055839300 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *, __int64))v5)(v6, 14, v9, 16);
      if ( (_DWORD)result )
      {
        v8 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_configure_staling_llcc",
          1166,
          "Failed in process_cmd, rc=%d",
          result);
        result = v8;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_configure_staling_llcc",
        1168,
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
      "cam_cpas_configure_staling_llcc",
      1148,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
