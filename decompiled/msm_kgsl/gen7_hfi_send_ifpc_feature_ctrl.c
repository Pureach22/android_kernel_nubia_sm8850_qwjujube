__int64 __fastcall gen7_hfi_send_ifpc_feature_ctrl(__int64 a1)
{
  int v2; // w8
  __int64 result; // x0
  __int64 v4; // x20
  unsigned int v5; // w19
  const char *v6; // x0
  __int64 v7; // [xsp+8h] [xbp-98h] BYREF
  int v8; // [xsp+10h] [xbp-90h]
  int v9; // [xsp+14h] [xbp-8Ch]
  _QWORD v10[17]; // [xsp+18h] [xbp-88h] BYREF

  v10[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(to_gen7_gmu(a1) + 1008) == 3 )
  {
    v2 = *(_DWORD *)(a1 + 24036);
    v8 = 1;
    v9 = v2;
    memset(v10, 0, 128);
    v7 = 0x90000000BLL;
    result = gen7_hfi_send_generic_req_v5(a1, (int *)&v7, (int *)v10, 0x10u);
    if ( (result & 0x80000000) != 0 )
    {
      v4 = *(_QWORD *)(a1 + 1544);
      v5 = result;
      v6 = hfi_feature_to_string(9);
      dev_err(v4 + 16, "Unable to %s feature %s (%d)\n", "enable", v6, 9);
      result = v5;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
