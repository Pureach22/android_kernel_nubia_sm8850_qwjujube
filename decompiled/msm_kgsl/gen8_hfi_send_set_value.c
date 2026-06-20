__int64 __fastcall gen8_hfi_send_set_value(__int64 a1, int a2, int a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x8
  unsigned int v10; // w22
  int v11[4]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v12[17]; // [xsp+18h] [xbp-88h] BYREF

  v12[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[2] = a3;
  v11[3] = a4;
  v11[0] = 13;
  v11[1] = a2;
  memset(v12, 0, 128);
  result = gen8_hfi_send_generic_req_v5(a1, v11, (int *)v12, 0x10u);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = *(_QWORD *)(a1 + 1544);
    v10 = result;
    dev_err(v9 + 16, "Unable to set HFI Value %d, %d to %d, error = %d\n", a2, a3, a4, result);
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
