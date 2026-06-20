__int64 __fastcall cam_icp_update_clk_util(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  char v6; // w9
  int v7; // w11
  int v8; // w21
  __int64 v9; // x9
  __int64 (__fastcall *v10)(__int64, __int64, int *, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x8
  _DWORD *v13; // x9
  __int64 v14; // x0
  int v15; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a3 + 16);
  v6 = *(_BYTE *)(a2 + 44231);
  v15 = result;
  v16[0] = 0xFFFFFFFFLL;
  v7 = *(_DWORD *)(v5 + 580);
  BYTE4(v16[0]) = v6;
  if ( !v7 )
  {
LABEL_7:
    if ( *(_DWORD *)(v5 + 8) == 3 )
      goto LABEL_17;
    if ( (debug_mdl & 0x2000000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000000,
        4,
        "cam_icp_update_clk_util",
        1612,
        "%s: Update ICP clk to level [%d]",
        (const char *)(a3 + 29824),
        LODWORD(v16[0]));
      v12 = *(_QWORD *)(a2 + 80);
      if ( v12 )
        goto LABEL_11;
    }
    else
    {
      v12 = *(_QWORD *)(a2 + 80);
      if ( v12 )
      {
LABEL_11:
        v13 = *(_DWORD **)(v12 + 88);
        v14 = *(_QWORD *)(v12 + 112);
        if ( *(v13 - 1) != -1055839300 )
          __break(0x8229u);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v13)(v14, 12, v16, 4);
        goto LABEL_17;
      }
    }
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_update_clk_util",
               1615,
               "Device interface is NULL");
    goto LABEL_17;
  }
  v8 = 0;
  while ( 1 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(v5 + 16) + 8LL * v8);
    if ( !v9 )
      break;
    v10 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v9 + 88);
    v11 = *(_QWORD *)(v9 + 112);
    if ( *((_DWORD *)v10 - 1) != -1055839300 )
      __break(0x8228u);
    result = v10(v11, 6, &v15, 12);
    v5 = *(_QWORD *)(a3 + 16);
    if ( (unsigned int)++v8 >= *(_DWORD *)(v5 + 580) )
      goto LABEL_7;
  }
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_update_clk_util",
             1601,
             "Device intf for %s[%u] is NULL",
             *(const char **)v5,
             v8);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
