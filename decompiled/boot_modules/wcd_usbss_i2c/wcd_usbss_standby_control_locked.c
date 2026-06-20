__int64 __fastcall wcd_usbss_standby_control_locked(__int64 result)
{
  __int64 v1; // x8

  if ( *(_BYTE *)(wcd_usbss_ctxt_ + 401) != (result & 1) )
  {
    v1 = *(_QWORD *)wcd_usbss_ctxt_;
    if ( (result & 1) != 0 )
    {
      result = regmap_update_bits_base(v1, 1049, 16, 16, 0, 0, 0);
      if ( (result & 0x80000000) != 0 )
        return dev_err(
                 *(_QWORD *)(wcd_usbss_ctxt_ + 8),
                 "%s: enter standby failed\n",
                 "wcd_usbss_standby_control_locked");
      else
        *(_BYTE *)(wcd_usbss_ctxt_ + 401) = 1;
    }
    else if ( (regmap_update_bits_base(v1, 1049, 16, 0, 0, 0, 0) & 0x80000000) != 0 )
    {
      return dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: exit standby failed\n", "wcd_usbss_standby_control_locked");
    }
    else
    {
      result = usleep_range_state(10000, 10100, 2);
      *(_BYTE *)(wcd_usbss_ctxt_ + 401) = 0;
    }
  }
  return result;
}
