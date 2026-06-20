__int64 __fastcall drv_cmd_set_band(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  unsigned int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  unsigned int v15; // w0
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v5 = kstrtou8(a3 + a4 + 1, 10, v17);
  if ( v5 )
  {
    v14 = v5;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: error %d parsing userspace band parameter",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_band",
      v5);
  }
  else
  {
    v15 = hdd_reg_legacy_setband_to_reg_wifi_band_bitmap(v17[0]);
    v14 = hdd_reg_set_band(*(_QWORD *)(*(_QWORD *)a1 + 32LL), v15);
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
