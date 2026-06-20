__int64 __fastcall gen8_hfi_send_minbw_feature_ctrl(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w8
  __int64 result; // x0
  __int64 v6; // x20
  unsigned int v7; // w19
  const char *v8; // x0
  __int64 v9; // [xsp+8h] [xbp-98h] BYREF
  int v10; // [xsp+10h] [xbp-90h]
  int v11; // [xsp+14h] [xbp-8Ch]
  _QWORD v12[17]; // [xsp+18h] [xbp-88h] BYREF

  v2 = a1 + 20442;
  v12[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = to_gen8_gmu(a1);
  if ( *(_BYTE *)v2 == 1 && *(_DWORD *)(v3 + 1008) )
  {
    v4 = *(_DWORD *)(v2 + 3554);
    v10 = 1;
    v11 = v4;
    memset(v12, 0, 128);
    v9 = 0x140000000BLL;
    result = gen8_hfi_send_generic_req_v5(a1, (int *)&v9, (int *)v12, 0x10u);
    if ( (result & 0x80000000) != 0 )
    {
      v6 = *(_QWORD *)(a1 + 1544);
      v7 = result;
      v8 = hfi_feature_to_string(20);
      dev_err(v6 + 16, "Unable to %s feature %s (%d)\n", "enable", v8, 20);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
