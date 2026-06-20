__int64 tgt_if_regulatory_modify_freq_range()
{
  unsigned int *hal_reg_cap; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x8
  __int64 v10; // x5
  __int64 v11; // x6

  hal_reg_cap = (unsigned int *)ucfg_reg_get_hal_reg_cap();
  if ( hal_reg_cap )
  {
    v9 = *((_QWORD *)hal_reg_cap + 3);
    if ( (v9 & 1) == 0 )
      *((_QWORD *)hal_reg_cap + 5) = 0;
    if ( (v9 & 0xC) != 0 )
    {
      v10 = hal_reg_cap[8];
      v11 = hal_reg_cap[9];
    }
    else
    {
      v11 = 0;
      v10 = 0;
      *((_QWORD *)hal_reg_cap + 4) = 0;
    }
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: phy_id = %d - low_2ghz_chan = %d high_2ghz_chan = %d low_5ghz_chan = %d high_5ghz_chan = %d",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "tgt_if_regulatory_modify_freq_range",
      *hal_reg_cap,
      v10,
      v11,
      hal_reg_cap[10],
      hal_reg_cap[11]);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: reg cap is NULL",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "tgt_if_regulatory_modify_freq_range");
    return 16;
  }
}
