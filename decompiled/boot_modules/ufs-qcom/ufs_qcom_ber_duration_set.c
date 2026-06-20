__int64 __fastcall ufs_qcom_ber_duration_set(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  if ( (unsigned int)kstrtoll(a1, 0, v5) )
    result = 4294967274LL;
  else
    result = param_set_int(a1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
