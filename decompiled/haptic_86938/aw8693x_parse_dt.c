__int64 __fastcall aw8693x_parse_dt(__int64 a1, __int64 a2, __int64 a3)
{
  char v5; // w9
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 result; // x0
  __int16 v9; // [xsp+Ch] [xbp-24h] BYREF
  char v10; // [xsp+Eh] [xbp-22h]
  __int64 v11; // [xsp+10h] [xbp-20h] BYREF
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v9 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_gain_bypass", a2 + 1217, 1, 0) & 0x80000000) != 0 )
    printk(&unk_164F4, "haptic_hv", 1710, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_uvlo_vol_default", a2 + 1218, 1, 0) & 0x80000000) != 0 )
    printk(&unk_154A8, "haptic_hv", 1714, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u32_array(a3, "f0_pre", a2 + 1128, 1, 0) & 0x80000000) != 0 )
    printk(&unk_14253, "haptic_hv", 1718, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_f0_cali_percent", a2 + 1122, 1, 0) & 0x80000000) != 0 )
    printk(&unk_1535E, "haptic_hv", 1722, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_smart_loop", a2 + 1219, 1, 0) & 0x80000000) != 0 )
    printk(&unk_1437F, "haptic_hv", 1726, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_drv1_lvl", a2 + 1178, 1, 0) & 0x80000000) != 0 )
    printk(&unk_13F99, "haptic_hv", 1730, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u32_array(a3, "aw8693x_cont_lra_vrms", a2 + 1220, 1, 0) & 0x80000000) != 0 )
    printk(&unk_15CA2, "haptic_hv", 1734, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_drv1_time", a2 + 1184, 1, 0) & 0x80000000) != 0 )
    printk(&unk_15CD3, "haptic_hv", 1738, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_drv2_time", a2 + 1185, 1, 0) & 0x80000000) != 0 )
    printk(&unk_160A1, "haptic_hv", 1742, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_brk_time", a2 + 1181, 1, 0) & 0x80000000) != 0 )
    printk(&unk_14529, "haptic_hv", 1746, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_track_margin", a2 + 1187, 1, 0) & 0x80000000) != 0 )
    printk(&unk_14764, "haptic_hv", 1751, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_cont_brk_gain", a2 + 1183, 1, 0) & 0x80000000) != 0 )
    printk(&unk_16371, "haptic_hv", 1755, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_d2s_gain", a2 + 1173, 1, 0) & 0x80000000) != 0 )
    printk(&unk_16ACE, "haptic_hv", 1759, "aw8693x_parse_dt");
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_duration_time", &v9, 3, 0) & 0x80000000) != 0 )
  {
    printk(&unk_15913, "haptic_hv", 1764, "aw8693x_parse_dt");
  }
  else
  {
    v5 = v10;
    *(_WORD *)(a2 + 1124) = v9;
    *(_BYTE *)(a2 + 1126) = v5;
  }
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_trig_config", &v11, 24, 0) & 0x80000000) != 0 )
  {
    printk(&unk_15DC8, "haptic_hv", 1771, "aw8693x_parse_dt");
  }
  else
  {
    v6 = v12;
    v7 = v13;
    *(_QWORD *)(a2 + 1189) = v11;
    *(_QWORD *)(a2 + 1197) = v6;
    *(_QWORD *)(a2 + 1205) = v7;
  }
  if ( (of_property_read_variable_u8_array(a3, "aw8693x_bst_vol_default", a2 + 1123, 1, 0) & 0x80000000) != 0 )
    printk(&unk_15391, "haptic_hv", 1778, "aw8693x_parse_dt");
  *(_BYTE *)(a2 + 1216) = of_find_property(a3, "aw8693x_is_enabled_track_en", 0) != 0;
  printk(&unk_1653B, "haptic_hv", 1782, "aw8693x_parse_dt");
  *(_BYTE *)(a2 + 1213) = of_find_property(a3, "aw8693x_is_enabled_auto_bst", 0) != 0;
  printk(&unk_14A2F, "haptic_hv", 1786, "aw8693x_parse_dt");
  *(_BYTE *)(a2 + 1215) = of_find_property(a3, "aw8693x_is_enabled_one_wire", 0) != 0;
  result = printk(&unk_14950, "haptic_hv", 1790, "aw8693x_parse_dt");
  _ReadStatusReg(SP_EL0);
  return result;
}
