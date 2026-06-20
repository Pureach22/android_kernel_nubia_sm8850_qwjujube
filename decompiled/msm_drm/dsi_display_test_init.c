__int64 __fastcall dsi_display_test_init(__int64 a1)
{
  _QWORD *v2; // x0

  if ( (dsi_display_test_init_done & 1) != 0 )
    return 0;
  dsi_display_test_init_done = 1;
  if ( a1 )
  {
    v2 = (_QWORD *)_kmalloc_cache_noprof(_drm_debug, 3520, 40);
    if ( v2 )
    {
      v2[1] = 0xFFFFFFFE00000LL;
      *v2 = a1;
      v2[2] = v2 + 2;
      v2[3] = v2 + 2;
      v2[4] = dsi_display_test_work;
      dsi_display_test_work(v2 + 1);
      return 0;
    }
    return 4294967284LL;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
}
