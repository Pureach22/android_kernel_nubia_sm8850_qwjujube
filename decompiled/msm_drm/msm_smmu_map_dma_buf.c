__int64 __fastcall msm_smmu_map_dma_buf(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x22

  if ( !a2 || (v4 = *(_QWORD *)(a1 + 40)) == 0 )
  {
    _drm_err("sg table is invalid\n");
    return 4294967284LL;
  }
  if ( (a4 & 0x40000000) == 0
    && !(unsigned int)dma_map_sg_attrs(*(_QWORD *)v4, *(_QWORD *)a2, *(unsigned int *)(a2 + 8), a3, 0) )
  {
    _drm_err("dma map sg failed\n");
    return 4294967284LL;
  }
  if ( *(_QWORD *)a2 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "%pad/0x%x/0x%x/0x%lx\n",
      (const void *)(*(_QWORD *)a2 + 16LL),
      *(_DWORD *)(*(_QWORD *)a2 + 24LL),
      a3,
      0);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "msm_smmu_map_dma_buf",
      296,
      -1,
      *(_QWORD *)(*(_QWORD *)a2 + 16LL),
      *(_DWORD *)(*(_QWORD *)a2 + 24LL),
      a3,
      0,
      *(_BYTE *)(v4 + 41));
  }
  return 0;
}
