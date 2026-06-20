__int64 __fastcall cam_cpas_start(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  _DWORD *v4; // x8
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w19
  const char *v8; // x5
  __int64 v9; // x4
  _QWORD v10[4]; // [xsp+0h] [xbp-20h] BYREF

  v10[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_start",
      823,
      "cpas intf not initialized");
    result = 4294967277LL;
    goto LABEL_13;
  }
  if ( !a3 )
  {
    v8 = "NULL axi vote";
    v9 = 828;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_start",
      v9,
      v8);
    result = 4294967274LL;
    goto LABEL_13;
  }
  v3 = *(_QWORD *)(g_cpas_intf + 480);
  v4 = *(_DWORD **)(v3 + 56);
  if ( !v4 )
  {
    v8 = "Invalid start ops";
    v9 = 845;
    goto LABEL_12;
  }
  v10[1] = a2;
  v10[0] = a1;
  v5 = *(_QWORD *)(v3 + 112);
  v10[2] = a3;
  if ( *(v4 - 1) != 1989616049 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64))v4)(v5, v10, 24);
  if ( (_DWORD)result )
  {
    v7 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_start",
      843,
      "Failed in start, rc=%d",
      result);
    result = v7;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
