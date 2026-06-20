__int64 __fastcall cam_cpas_select_qos_settings(int a1)
{
  __int64 v1; // x9
  __int64 (__fastcall *v2)(__int64, __int64, int *, __int64); // x8
  __int64 v3; // x0
  __int64 result; // x0
  unsigned int v5; // w19
  const char *v6; // x5
  __int64 v7; // x4
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1;
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
  {
    v6 = "cpas intf not initialized";
    v7 = 881;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_select_qos_settings",
      v7,
      v6);
    result = 4294967243LL;
    goto LABEL_10;
  }
  v1 = *(_QWORD *)(g_cpas_intf + 480);
  v2 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v1 + 88);
  if ( !v2 )
  {
    v6 = "Invalid process_cmd ops";
    v7 = 893;
    goto LABEL_9;
  }
  v3 = *(_QWORD *)(v1 + 112);
  if ( *((_DWORD *)v2 - 1) != -1055839300 )
    __break(0x8228u);
  result = v2(v3, 9, &v8, 4);
  if ( (_DWORD)result )
  {
    v5 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_select_qos_settings",
      891,
      "Failed in process_cmd, rc=%d",
      result);
    result = v5;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
