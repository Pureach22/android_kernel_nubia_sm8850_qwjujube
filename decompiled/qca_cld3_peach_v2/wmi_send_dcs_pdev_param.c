__int64 __fastcall wmi_send_dcs_pdev_param(__int64 a1, __int64 a2, char a3, int a4)
{
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v8 = 0;
  qdf_mem_set(&v8, 0xCu, 0);
  LOBYTE(v9) = a3;
  LODWORD(v8) = 36;
  HIDWORD(v8) = a4;
  result = wmi_unified_pdev_param_send(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
