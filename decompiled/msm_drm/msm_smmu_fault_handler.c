__int64 __fastcall msm_smmu_fault_handler(
        int a1,
        int a2,
        __int64 a3,
        int a4,
        const char ***a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  const char *v11; // x1
  char v13; // [xsp+0h] [xbp+0h]

  if ( a5 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "msm_smmu_fault_handler", 479, -1, a3, a4, -1059143953, a8, v13);
    _drm_err("trigger dump, iova=0x%08lx, flags=0x%x\n", a3, a4);
    if ( *a5 )
      v11 = **a5;
    else
      v11 = (const char *)&unk_229BD3;
    _drm_err("SMMU device:%s", v11);
  }
  else
  {
    _drm_err("Error: token is NULL\n");
  }
  return 4294967274LL;
}
