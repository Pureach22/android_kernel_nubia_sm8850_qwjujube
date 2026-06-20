__int64 __fastcall cam_cpas_reg_write(int a1, unsigned int a2, int a3, char a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  _DWORD *v7; // x8
  __int64 result; // x0
  __int64 v10; // x0
  unsigned int v11; // w19
  _DWORD v12[4]; // [xsp+4h] [xbp-1Ch] BYREF
  int v13; // [xsp+14h] [xbp-Ch]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v6 = *(_QWORD *)(g_cpas_intf + 480);
    v7 = *(_DWORD **)(v6 + 88);
    if ( !v7 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_reg_write",
        601,
        "Invalid process_cmd ops");
      goto LABEL_8;
    }
    v13 = 0;
    if ( a2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_reg_write",
        584,
        "Invalid reg base: %d for write ops client: %u",
        a2,
        a1);
LABEL_8:
      result = 4294967274LL;
      goto LABEL_9;
    }
    v10 = *(_QWORD *)(v6 + 112);
    v12[2] = a3;
    v12[3] = a5;
    v12[0] = a1;
    v12[1] = 0;
    LOBYTE(v13) = a4 & 1;
    if ( *(v7 - 1) != -1055839300 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *, __int64, __int64, __int64, _QWORD))v7)(
               v10,
               3,
               v12,
               20,
               a5,
               a6,
               a2);
    if ( (_DWORD)result )
    {
      v11 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_reg_write",
        599,
        "Failed in process_cmd, rc=%d",
        result);
      result = v11;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_reg_write",
      573,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
