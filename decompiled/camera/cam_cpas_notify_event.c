__int64 __fastcall cam_cpas_notify_event(__int64 a1, int a2)
{
  __int64 v2; // x9
  __int64 (__fastcall *v3)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w19
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
  {
    v7 = "cpas intf not initialized";
    v8 = 932;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_notify_event",
      v8,
      v7);
    result = 4294967243LL;
    goto LABEL_10;
  }
  v2 = *(_QWORD *)(g_cpas_intf + 480);
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v2 + 88);
  if ( !v3 )
  {
    v7 = "Invalid process_cmd ops";
    v8 = 949;
    goto LABEL_9;
  }
  v9 = a1;
  v10 = 0;
  v4 = *(_QWORD *)(v2 + 112);
  LODWORD(v10) = a2;
  if ( *((_DWORD *)v3 - 1) != -1055839300 )
    __break(0x8228u);
  result = v3(v4, 10, &v9, 16);
  if ( (_DWORD)result )
  {
    v6 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_notify_event",
      947,
      "Failed in process_cmd, rc=%d",
      result);
    result = v6;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
