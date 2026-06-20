__int64 __fastcall dsi_display_get_dst_format(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  if ( a2 )
  {
    v2 = a2[33];
    if ( v2 )
      return *(unsigned int *)(v2 + 1224);
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params(s) dsi_display %pK, panel %pK\n", a2, nullptr);
  return 8;
}
