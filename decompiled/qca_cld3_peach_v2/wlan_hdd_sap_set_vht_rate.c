__int64 __fastcall wlan_hdd_sap_set_vht_rate(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w4
  unsigned int v13; // w22
  unsigned int v14; // w19
  unsigned int v15; // w20
  unsigned int v16; // w21

  v10 = *(_DWORD *)(*(_QWORD *)(a1 + 52832) + 320LL);
  if ( v10 < 0x100 || v10 == 0x4000 || v10 == 4096 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: SET_VHT_RATE: SapHw_mode= 0x%x, ch_freq: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_sap_set_vht_rate");
    return 4294967291LL;
  }
  else
  {
    if ( a2 == 255 )
    {
      v13 = 0;
      v14 = 0;
      v15 = 0;
      v16 = 255;
    }
    else
    {
      v14 = (a2 >> 4) & 3;
      v15 = a2 & 0xF;
      v13 = 3;
      v16 = hdd_assemble_rate_code(3u, (a2 >> 4) & 3, a2 & 0xF);
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: SET_VHT_RATE val %d rix %d preamble %x nss %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_sap_set_vht_rate",
      v16,
      v15,
      v13,
      v14);
    return wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 27, v16, 1);
  }
}
