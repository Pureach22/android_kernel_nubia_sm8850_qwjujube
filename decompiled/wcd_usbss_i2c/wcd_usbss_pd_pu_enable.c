__int64 wcd_usbss_pd_pu_enable()
{
  __int64 result; // x0

  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 32, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 44, 32, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 31, 1, 1, 0, 0, 0);
  result = regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 34, 1, 1, 0, 0, 0);
  if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 536) & 1) == 0 )
  {
    regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 37, 1, 1, 0, 0, 0);
    return regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 41, 1, 1, 0, 0, 0);
  }
  return result;
}
