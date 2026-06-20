__int64 __fastcall gen8_hfi_send_bcl_feature_ctrl(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0
  __int64 v4; // x20
  unsigned int v5; // w19
  const char *v6; // x0
  __int64 v7; // [xsp+8h] [xbp-98h] BYREF
  int v8; // [xsp+10h] [xbp-90h]
  int v9; // [xsp+14h] [xbp-8Ch]
  _QWORD v10[17]; // [xsp+18h] [xbp-88h] BYREF

  v10[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 20437) == 1 )
  {
    v1 = *(_DWORD *)(a1 + 23992);
    v8 = 1;
    v9 = v1;
    memset(v10, 0, 128);
    v7 = 0xB0000000BLL;
    result = gen8_hfi_send_generic_req_v5(a1, (int *)&v7, (int *)v10, 0x10u);
    if ( (result & 0x80000000) != 0 )
    {
      v4 = *(_QWORD *)(a1 + 1544);
      v5 = result;
      v6 = hfi_feature_to_string(11);
      dev_err(v4 + 16, "Unable to %s feature %s (%d)\n", "enable", v6, 11);
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
