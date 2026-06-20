__int64 __fastcall wcd_usbss_switch_update_defaults(_QWORD *a1)
{
  _QWORD *v2; // x8
  __int64 result; // x0

  regmap_update_bits_base(*a1, 1027, 7, 0, 0, 0, 0);
  regmap_update_bits_base(*a1, 1029, 1, 0, 0, 0, 0);
  regmap_update_bits_base(*a1, 1028, 3, 0, 0, 0, 0);
  regmap_update_bits_base(*a1, 37, 8, 8, 0, 0, 0);
  regmap_update_bits_base(*a1, 41, 8, 8, 0, 0, 0);
  regmap_update_bits_base(*a1, 1075, 1, 1, 0, 0, 1);
  regmap_update_bits_base(*a1, 1028, 60, 20, 0, 0, 0);
  regmap_update_bits_base(*a1, 1049, 7, 5, 0, 0, 0);
  regmap_write(*a1, 1, 0);
  v2 = (_QWORD *)wcd_usbss_ctxt_;
  if ( *(_DWORD *)(wcd_usbss_ctxt_ + 504) == 1 )
  {
    regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 2, 64, 0, 0, 0, 0);
    v2 = (_QWORD *)wcd_usbss_ctxt_;
  }
  regmap_write(*v2, 67, 0);
  regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 61, 0);
  regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 4, 16);
  regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 80, 0);
  regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 145, 0);
  result = regmap_write(*(_QWORD *)wcd_usbss_ctxt_, 146, 0);
  audio_fsm_mode = 0;
  return result;
}
