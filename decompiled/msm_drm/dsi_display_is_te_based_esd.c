bool __fastcall dsi_display_is_te_based_esd(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 264);
  if ( v1 )
    return *(_DWORD *)(v1 + 1724) == 2 && (*(_DWORD *)(a1 + 120) & 0x80000000) == 0;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid panel data\n");
  return 0;
}
