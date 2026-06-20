__int64 wcd_usbss_pm_suspend()
{
  __int64 v0; // x0

  if ( wcd_usbss_ctxt_ )
  {
    mutex_lock(wcd_usbss_ctxt_ + 408);
    v0 = wcd_usbss_ctxt_ + 408;
    *(_BYTE *)(wcd_usbss_ctxt_ + 528) = 1;
    mutex_unlock(v0);
  }
  return 0;
}
