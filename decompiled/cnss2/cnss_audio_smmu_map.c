__int64 __fastcall cnss_audio_smmu_map(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v12; // x10
  __int64 v13; // x5

  v7 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v7 )
    return 4294967277LL;
  v8 = v7;
  v9 = *(_QWORD *)(v7 + 7544);
  if ( !v9 )
    return 4294967274LL;
  if ( (*(_BYTE *)(v8 + 7552) & 1) != 0 )
    return 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (unsigned __int64)(a3 & 0xFFF) + a4 <= 0x1000 )
    v12 = a4;
  else
    v12 = a4 + 4096;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || *(_DWORD *)(StatusReg + 16)
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 1412) )
  {
    v13 = 2080;
  }
  else
  {
    v13 = 3264;
  }
  return iommu_map(v9, a3 & 0xFFFFFFFFFFFFF000LL, a2 - (a3 & 0xFFF), (v12 + 4095) & 0xFFFFFFFFFFFFF000LL, 7, v13);
}
