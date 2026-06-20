__int64 __fastcall dsi_display_update_pps(const void *a1, __int64 a2)
{
  if ( a1 && a2 )
  {
    mutex_lock(a2 + 72);
    memcpy((void *)(*(_QWORD *)(a2 + 264) + 2049LL), a1, 0x87u);
    mutex_unlock(a2 + 72);
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid parameter\n");
    return 4294967274LL;
  }
}
