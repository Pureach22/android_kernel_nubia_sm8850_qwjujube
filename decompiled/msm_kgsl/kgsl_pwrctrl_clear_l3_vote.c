__int64 __fastcall kgsl_pwrctrl_clear_l3_vote(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // [xsp+8h] [xbp-18h] BYREF
  int v4; // [xsp+10h] [xbp-10h]
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(result + 13100);
  v3 = 0;
  if ( v1 )
  {
    v2 = result;
    v4 = 2;
    result = qcom_dcvs_update_votes("kgsl-l3", &v3, 1, 0);
    if ( (_DWORD)result )
      result = dev_err(*(_QWORD *)v2, "Could not clear l3_vote: %d\n", result);
    else
      *(_DWORD *)(v2 + 13104) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
