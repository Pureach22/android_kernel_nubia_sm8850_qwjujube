__int64 wcd_usbss_get_sbu_switch_orientation()
{
  __int64 result; // x0
  int v1; // w0
  int v2; // w8
  unsigned int v3; // w19
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wcd_usbss_ctxt_;
  v4 = 0;
  if ( wcd_usbss_ctxt_ )
  {
    if ( *(_QWORD *)wcd_usbss_ctxt_ )
    {
      v1 = acquire_runtime_env();
      if ( v1 < 0 )
      {
        v3 = v1;
        dev_err(
          *(_QWORD *)(wcd_usbss_ctxt_ + 8),
          "%s: acquire_runtime_env failed: %i\n",
          "wcd_usbss_get_sbu_switch_orientation",
          v1);
        result = v3;
      }
      else
      {
        regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 1028, &v4);
        release_runtime_env(wcd_usbss_ctxt_);
        v2 = v4 & 3;
        if ( v2 == 1 )
          result = 1;
        else
          result = 2 * (unsigned int)(v2 == 2);
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
