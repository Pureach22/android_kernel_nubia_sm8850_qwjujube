__int64 __fastcall ufs_qcom_ber_threshold_set(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 result; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v4 = kstrtouint(a1, 0, &v6);
  result = 4294967274LL;
  if ( !v4 && v6 <= 0x1F )
  {
    override_ber_threshold = v6 != 0;
    result = param_set_int(a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
