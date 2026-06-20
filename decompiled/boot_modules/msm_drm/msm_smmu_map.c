__int64 __fastcall msm_smmu_map(__int64 a1, __int64 a2, unsigned int *a3, int a4, __int64 a5)
{
  __int64 v7; // x2
  int v8; // w20
  __int64 v9; // x21
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a3 && (v7 = *(_QWORD *)a3) != 0 )
  {
    v8 = a5;
    v9 = iommu_map_sg(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL), a2, v7, a3[3], a5, 2080);
    if ( (v9 & 0x80000000) != 0 )
      __break(0x800u);
    _drm_dev_dbg(
      0,
      0,
      0,
      "%pad/0x%x/0x%x/\n",
      (const void *)(*(_QWORD *)a3 + 16LL),
      *(_DWORD *)(*(_QWORD *)a3 + 24LL),
      v8);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "msm_smmu_map",
      230,
      -1,
      *(_QWORD *)(*(_QWORD *)a3 + 16LL),
      *(_DWORD *)(*(_QWORD *)a3 + 24LL),
      v8,
      -1059143953,
      vars0);
  }
  else
  {
    v9 = 0;
  }
  if ( v9 == a4 )
    return 0;
  else
    return 4294967274LL;
}
