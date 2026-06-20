__int64 __fastcall kgsl_pwrctrl_disable(_QWORD *a1)
{
  int v2; // w8
  int updated; // w0
  void (__fastcall *v4)(_QWORD); // x8
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  int v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a1 + 3275);
  v6 = 0;
  if ( v2 )
  {
    v7 = 2;
    updated = qcom_dcvs_update_votes("kgsl-l3", &v6, 1, 0);
    if ( updated )
      dev_err(*a1, "Could not clear l3_vote: %d\n", updated);
    else
      *((_DWORD *)a1 + 3276) = 0;
  }
  v4 = *(void (__fastcall **)(_QWORD))(a1[1094] + 216LL);
  if ( *((_DWORD *)v4 - 1) != 1058568764 )
    __break(0x8228u);
  v4(a1);
  kgsl_pwrctrl_axi((__int64)a1, 0);
  kgsl_pwrctrl_clk((__int64)a1, 0, 0x80u);
  result = kgsl_pwrctrl_pwrrail(a1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
