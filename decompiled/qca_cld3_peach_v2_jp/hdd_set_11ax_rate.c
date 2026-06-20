__int64 __fastcall hdd_set_11ax_rate(
        __int64 a1,
        int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x20
  __int64 v14; // x4
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w23
  unsigned int v32; // w20
  unsigned int v33; // w22
  unsigned int v34; // w21

  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL);
  if ( a3 )
  {
    v14 = *(unsigned int *)(a3 + 40);
    if ( (_DWORD)v14 != 2048 && (_DWORD)v14 != 4096 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid hw mode, SAP hw_mode= 0x%x, ch_freq = %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "hdd_set_11ax_rate",
        v14,
        *(unsigned int *)(a3 + 440));
      return 4294967291LL;
    }
  }
  else if ( (sme_is_feature_supported_by_fw(13) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Target does not support 11ax",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_set_11ax_rate");
    return 4294967291LL;
  }
  if ( a2 == 0xFFFF )
  {
    sme_set_auto_rate_he_ltf(v13, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 0);
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 0xFFFF;
  }
  else
  {
    v32 = (unsigned __int8)a2 >> 5;
    v33 = a2 & 0x1F;
    v31 = 4;
    v34 = wlan_mlme_assemble_rate_code(4u, (unsigned __int8)a2 >> 5, a2 & 0x1F);
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: SET_11AX_RATE val %d rix %d preamble %x nss %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "hdd_set_11ax_rate",
    v34,
    v33,
    v31,
    v32);
  return wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 27, v34, 1);
}
