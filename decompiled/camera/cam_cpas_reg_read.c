__int64 __fastcall cam_cpas_reg_read(int a1, int a2, int a3, char a4, _DWORD *a5)
{
  __int64 v5; // x9
  _DWORD *v6; // x8
  __int64 result; // x0
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v11; // x0
  unsigned int v13; // w19
  _DWORD v14[3]; // [xsp+4h] [xbp-1Ch] BYREF
  int v15; // [xsp+10h] [xbp-10h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_reg_read",
      615,
      "cpas intf not initialized");
    result = 4294967277LL;
    goto LABEL_12;
  }
  if ( !a5 )
  {
    v9 = "Invalid arg value";
    v10 = 620;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_reg_read",
      v10,
      v9);
    goto LABEL_11;
  }
  v5 = *(_QWORD *)(g_cpas_intf + 480);
  v6 = *(_DWORD **)(v5 + 88);
  if ( !v6 )
  {
    v9 = "Invalid process_cmd ops";
    v10 = 652;
    goto LABEL_10;
  }
  v16 = 0;
  if ( a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_reg_read",
      631,
      "Invalid reg base: %d for read ops client: %u",
      a2,
      a1);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v11 = *(_QWORD *)(v5 + 112);
  v14[2] = a3;
  v15 = 0;
  v14[0] = a1;
  v14[1] = 0;
  LOBYTE(v16) = a4 & 1;
  if ( *(v6 - 1) != -1055839300 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *, __int64))v6)(v11, 4, v14, 20);
  if ( (_DWORD)result )
  {
    v13 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_reg_read",
      646,
      "Failed in process_cmd, rc=%d",
      result);
    result = v13;
  }
  else
  {
    *a5 = v15;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
