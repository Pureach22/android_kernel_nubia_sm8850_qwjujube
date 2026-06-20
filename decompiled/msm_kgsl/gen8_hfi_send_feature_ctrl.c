__int64 __fastcall gen8_hfi_send_feature_ctrl(__int64 a1, int a2, int a3, int a4)
{
  __int64 result; // x0
  __int64 v8; // x22
  unsigned int v9; // w21
  const char *v10; // x20
  const char *v11; // x0
  int v12[4]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v13[17]; // [xsp+18h] [xbp-88h] BYREF

  v13[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[2] = a3;
  v12[3] = a4;
  v12[0] = 11;
  v12[1] = a2;
  memset(v13, 0, 128);
  result = gen8_hfi_send_generic_req_v5(a1, v12, (int *)v13, 0x10u);
  if ( (result & 0x80000000) != 0 )
  {
    v8 = *(_QWORD *)(a1 + 1544);
    v9 = result;
    if ( a3 )
      v10 = "enable";
    else
      v10 = "disable";
    v11 = hfi_feature_to_string(a2);
    dev_err(v8 + 16, "Unable to %s feature %s (%d)\n", v10, v11, a2);
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
