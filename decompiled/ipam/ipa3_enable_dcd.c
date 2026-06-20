__int64 ipa3_enable_dcd()
{
  __int64 result; // x0
  int v1; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v2; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = 256;
  result = ((__int64 (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(94, 0, &v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
