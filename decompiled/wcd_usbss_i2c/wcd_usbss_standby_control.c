__int64 __fastcall wcd_usbss_standby_control(__int64 result)
{
  char v1; // w19
  int v2; // w0

  if ( *(_BYTE *)(wcd_usbss_ctxt_ + 400) == 1 )
  {
    v1 = result;
    mutex_lock(wcd_usbss_ctxt_ + 408);
    v2 = acquire_runtime_env(wcd_usbss_ctxt_);
    if ( v2 < 0 )
    {
      dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: acquire_runtime_env failed: %i\n", "wcd_usbss_standby_control", v2);
    }
    else
    {
      wcd_usbss_standby_control_locked(v1 & 1);
      release_runtime_env(wcd_usbss_ctxt_);
    }
    return mutex_unlock(wcd_usbss_ctxt_ + 408);
  }
  return result;
}
