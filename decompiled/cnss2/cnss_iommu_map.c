__int64 __fastcall cnss_iommu_map(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x5

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || *(_DWORD *)(StatusReg + 16)
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 1412) )
  {
    v6 = 2080;
  }
  else
  {
    v6 = 3264;
  }
  return iommu_map(a1, a2, a3, a4, a5, v6);
}
