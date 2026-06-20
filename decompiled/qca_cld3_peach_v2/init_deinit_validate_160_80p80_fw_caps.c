__int64 __fastcall init_deinit_validate_160_80p80_fw_caps(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v10; // w8
  __int64 hal_reg_cap; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( a10 )
  {
    v10 = *(_DWORD *)(a10 + 496);
    if ( v10 <= 0x27 && ((1LL << v10) & 0x9041300000LL) != 0 )
      return 0;
    hal_reg_cap = ucfg_reg_get_hal_reg_cap();
    if ( hal_reg_cap )
    {
      if ( (*(_DWORD *)(a10 + 696) & 0x4C) != 0x40 )
        return 0;
      v22 = *(_DWORD *)(hal_reg_cap + 24);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Invalid 160/80+80 MHz config specified by FW. Take care of it first",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "init_deinit_validate_160_80p80_fw_caps");
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wireless_mode_160mhz: %d, wireless_mode_80p80mhz: %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "init_deinit_validate_160_80p80_fw_caps",
        (v22 >> 21) & 1,
        (v22 >> 22) & 1);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: vhtcap_160mhz: %d, vhtcap_80p80_160mhz: %d,vhtcap_160mhz_sgi: %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "init_deinit_validate_160_80p80_fw_caps",
        0,
        0,
        1);
      return 1;
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: reg cap is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "init_deinit_validate_160_80p80_fw_caps");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: target_psoc_info is null in validate 160n80p80 cap check",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "init_deinit_validate_160_80p80_fw_caps");
    return 4;
  }
}
