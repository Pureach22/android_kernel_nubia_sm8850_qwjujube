__int64 __fastcall sde_wb_drm_deinit(__int64 a1)
{
  if ( a1 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    return 0;
  }
  else
  {
    printk(&unk_223EAA, "sde_wb_drm_deinit");
    return 4294967274LL;
  }
}
