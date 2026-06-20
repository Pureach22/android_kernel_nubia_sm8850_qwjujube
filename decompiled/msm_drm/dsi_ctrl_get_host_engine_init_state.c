__int64 __fastcall dsi_ctrl_get_host_engine_init_state(__int64 a1, _BYTE *a2)
{
  const char *v5; // x3

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 32);
    *a2 = *(_BYTE *)(a1 + 1628);
    mutex_unlock(a1 + 32);
    return 0;
  }
  else
  {
    if ( a1 )
      v5 = *(const char **)(a1 + 16);
    else
      v5 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid Params\n", v5);
    return 4294967274LL;
  }
}
