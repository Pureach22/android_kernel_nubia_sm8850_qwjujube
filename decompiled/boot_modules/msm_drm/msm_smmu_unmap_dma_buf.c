size_t __fastcall msm_smmu_unmap_dma_buf(size_t result, unsigned int *a2, unsigned int a3, int a4)
{
  __int64 v4; // x22

  if ( !a2 )
    return _drm_err("sg table is invalid\n");
  v4 = *(_QWORD *)(result + 40);
  if ( !v4 )
    return _drm_err("sg table is invalid\n");
  if ( *(_QWORD *)a2 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "%pad/0x%x/0x%x\n",
      (const void *)(*(_QWORD *)a2 + 16LL),
      *(_DWORD *)(*(_QWORD *)a2 + 24LL),
      a3);
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "msm_smmu_unmap_dma_buf",
               319,
               -1,
               *(_QWORD *)(*(_QWORD *)a2 + 16LL),
               *(_DWORD *)(*(_QWORD *)a2 + 24LL),
               a3,
               *(unsigned __int8 *)(v4 + 41),
               a4);
  }
  if ( (a4 & 0x40000000) == 0 )
    return dma_unmap_sg_attrs(*(_QWORD *)v4, *(_QWORD *)a2, a2[2], a3, 0);
  return result;
}
