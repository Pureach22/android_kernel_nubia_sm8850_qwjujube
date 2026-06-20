__int64 __fastcall cam_cpas_update_axi_vote(unsigned int a1, __int64 a2)
{
  __int64 v2; // x9
  _DWORD *v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w19
  const char *v7; // x5
  __int64 v8; // x4
  _QWORD v9[3]; // [xsp+8h] [xbp-18h] BYREF

  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_update_axi_vote",
      728,
      "cpas intf not initialized");
    result = 4294967277LL;
    goto LABEL_13;
  }
  if ( !a2 )
  {
    v7 = "NULL axi vote";
    v8 = 733;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_update_axi_vote",
      v8,
      v7);
    result = 4294967274LL;
    goto LABEL_13;
  }
  v2 = *(_QWORD *)(g_cpas_intf + 480);
  v3 = *(_DWORD **)(v2 + 88);
  if ( !v3 )
  {
    v7 = "Invalid process_cmd ops";
    v8 = 750;
    goto LABEL_12;
  }
  v9[1] = a2;
  v9[0] = a1;
  v4 = *(_QWORD *)(v2 + 112);
  if ( *(v3 - 1) != -1055839300 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v3)(v4, 6, v9, 16);
  if ( (_DWORD)result )
  {
    v6 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_update_axi_vote",
      748,
      "Failed in process_cmd, rc=%d",
      result);
    result = v6;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
