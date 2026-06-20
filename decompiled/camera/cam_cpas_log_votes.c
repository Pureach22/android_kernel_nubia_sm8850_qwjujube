__int64 __fastcall cam_cpas_log_votes(char a1)
{
  __int64 v1; // x9
  _DWORD *v2; // x8
  __int64 v3; // x0
  __int64 result; // x0
  const char *v5; // x5
  __int64 v6; // x4
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = a1;
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
  {
    v5 = "cpas intf not initialized";
    v6 = 858;
LABEL_9:
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               4,
               1,
               "cam_cpas_log_votes",
               v6,
               v5);
    goto LABEL_10;
  }
  v1 = *(_QWORD *)(g_cpas_intf + 480);
  v2 = *(_DWORD **)(v1 + 88);
  if ( !v2 )
  {
    v5 = "Invalid process_cmd ops";
    v6 = 870;
    goto LABEL_9;
  }
  v3 = *(_QWORD *)(v1 + 112);
  if ( *(v2 - 1) != -1055839300 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64))v2)(v3, 8, v7, 1);
  if ( (_DWORD)result )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               4,
               1,
               "cam_cpas_log_votes",
               868,
               "Failed in process_cmd, rc=%d",
               result);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
