__int64 __fastcall dsi_display_get_mode_count(__int64 a1, _DWORD *a2)
{
  int v5; // w3

  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 264) )
    {
      mutex_lock(a1 + 72);
      *a2 = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 1436LL);
      mutex_unlock(a1 + 72);
      return 0;
    }
    v5 = 1;
  }
  else
  {
    v5 = 0;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display:%d panel:%d\n", v5, 0);
  return 4294967274LL;
}
