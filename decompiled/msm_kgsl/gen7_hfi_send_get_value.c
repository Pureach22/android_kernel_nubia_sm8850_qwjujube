__int64 __fastcall gen7_hfi_send_get_value(__int64 a1, int a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w21
  int v9[3]; // [xsp+Ch] [xbp-94h] BYREF
  _QWORD v10[17]; // [xsp+18h] [xbp-88h] BYREF

  v10[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[1] = a2;
  v9[2] = a3;
  memset(v10, 0, 128);
  v9[0] = 12;
  result = gen7_hfi_send_generic_req_v5(a1, v9, (int *)v10, 0xCu);
  if ( (result & 0x80000000) != 0 )
  {
    v7 = *(_QWORD *)(a1 + 1544);
    v8 = result;
    dev_err(v7 + 16, "Unable to get HFI Value type: %d, subtype: %d, error = %d\n", a2, a3, result);
    result = v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
