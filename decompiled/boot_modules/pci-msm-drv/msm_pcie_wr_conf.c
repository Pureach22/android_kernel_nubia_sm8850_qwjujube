__int64 __fastcall msm_pcie_wr_conf(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, int a5)
{
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a5;
  result = msm_pcie_oper_conf(a1, a2, 1, a3, a4, &v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
