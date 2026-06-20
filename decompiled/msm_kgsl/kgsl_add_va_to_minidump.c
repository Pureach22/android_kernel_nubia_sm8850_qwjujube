__int64 __fastcall kgsl_add_va_to_minidump(__int64 a1, const char *a2, __int64 a3, int a4)
{
  __int64 result; // x0
  unsigned int v9; // w21
  __int64 v10; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v11[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+28h] [xbp-18h]
  __int64 v13; // [xsp+30h] [xbp-10h]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  memset(v11, 0, sizeof(v11));
  v10 = 0;
  scnprintf(v11, 32, a2);
  v10 = a3;
  LODWORD(v12) = a4;
  result = qcom_va_md_add_region(&v10);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = result;
    dev_err(a1, "Failed to register %s with va_minidump: %d\n", a2, result);
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
