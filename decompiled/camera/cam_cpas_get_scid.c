__int64 __fastcall cam_cpas_get_scid(int a1)
{
  __int64 v1; // x9
  __int64 (__fastcall *v2)(__int64, __int64, int *, __int64); // x8
  __int64 v3; // x0
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1;
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v1 = *(_QWORD *)(g_cpas_intf + 480);
    v2 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v1 + 88);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v1 + 112);
      if ( *((_DWORD *)v2 - 1) != -1055839300 )
        __break(0x8228u);
      result = v2(v3, 11, &v5, 4);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_get_scid",
        1024,
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
      "cam_cpas_get_scid",
      1014,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
