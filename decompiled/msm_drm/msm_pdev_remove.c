__int64 __fastcall msm_pdev_remove(__int64 a1)
{
  component_master_del(a1 + 16, msm_drm_ops);
  return of_platform_depopulate(a1 + 16);
}
