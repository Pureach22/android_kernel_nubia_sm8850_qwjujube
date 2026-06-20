__int64 __fastcall populate_dot11f_ds_params(__int64 a1, _BYTE *a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( wlan_reg_is_24ghz_ch_freq(a3) )
  {
    a2[1] = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), a3, v6, v7, v8, v9, v10, v11, v12, v13);
    *a2 = 1;
  }
  return 0;
}
