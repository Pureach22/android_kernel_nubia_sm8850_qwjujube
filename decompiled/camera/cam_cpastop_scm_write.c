__int64 __fastcall cam_cpastop_scm_write(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 16);
  v5 = 0;
  qcom_scm_io_readl(v2, &v5);
  v3 = *(unsigned int *)(a1 + 16);
  v5 |= *(_DWORD *)(a1 + 28);
  result = qcom_scm_io_writel(v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
