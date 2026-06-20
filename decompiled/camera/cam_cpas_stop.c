__int64 __fastcall cam_cpas_stop(int a1)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(__int64, int *, __int64); // x9
  __int64 v3; // x8
  __int64 result; // x0
  unsigned int v5; // w19
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v1 = *(_QWORD *)(g_cpas_intf + 480);
    v2 = *(__int64 (__fastcall **)(__int64, int *, __int64))(v1 + 64);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v1 + 112);
      v6 = a1;
      if ( *((_DWORD *)v2 - 1) != 1989616049 )
        __break(0x8229u);
      result = v2(v3, &v6, 4);
      if ( (_DWORD)result )
      {
        v5 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_stop",
          807,
          "Failed in stop, rc=%d",
          result);
        result = v5;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_stop",
        809,
        "Invalid stop ops");
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_stop",
      794,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
