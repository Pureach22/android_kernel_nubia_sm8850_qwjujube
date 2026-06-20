__int64 wcd_usbss_pm_resume()
{
  __int64 v0; // x8
  int v1; // w0

  if ( wcd_usbss_ctxt_ )
  {
    mutex_lock(wcd_usbss_ctxt_ + 408);
    v0 = wcd_usbss_ctxt_;
    if ( *(_BYTE *)(wcd_usbss_ctxt_ + 529) == 1 )
    {
      v1 = wcd_usbss_sdam_handle_events_locked(*(_DWORD *)(wcd_usbss_ctxt_ + 532));
      v0 = wcd_usbss_ctxt_;
      *(_BYTE *)(wcd_usbss_ctxt_ + 529) = 0;
      if ( !v1 )
        *(_DWORD *)(v0 + 508) = *(_DWORD *)(v0 + 532);
    }
    *(_BYTE *)(v0 + 528) = 0;
    mutex_unlock(v0 + 408);
  }
  return 0;
}
