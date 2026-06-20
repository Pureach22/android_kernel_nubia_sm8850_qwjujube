__int64 __fastcall gen8_hfi_send_ifpc_feature_ctrl(__int64 a1)
{
  int v2; // w8
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // x20
  unsigned int v6; // w19
  const char *v7; // x0
  __int64 v8; // [xsp+8h] [xbp-98h] BYREF
  int v9; // [xsp+10h] [xbp-90h]
  int v10; // [xsp+14h] [xbp-8Ch]
  _QWORD v11[17]; // [xsp+18h] [xbp-88h] BYREF

  v11[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(to_gen8_gmu(a1) + 1008);
  if ( v2 == 6 || v2 == 3 )
  {
    v3 = *(_DWORD *)(a1 + 24036);
    v9 = 1;
    v10 = v3;
    memset(v11, 0, 128);
    v8 = 0x90000000BLL;
    result = gen8_hfi_send_generic_req_v5(a1, (int *)&v8, (int *)v11, 0x10u);
    if ( (result & 0x80000000) != 0 )
    {
      v5 = *(_QWORD *)(a1 + 1544);
      v6 = result;
      v7 = hfi_feature_to_string(9);
      dev_err(v5 + 16, "Unable to %s feature %s (%d)\n", "enable", v7, 9);
      result = v6;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
