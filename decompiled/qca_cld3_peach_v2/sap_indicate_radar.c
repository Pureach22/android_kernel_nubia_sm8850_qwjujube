__int64 __fastcall sap_indicate_radar(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  _QWORD *v11; // x20
  __int64 sap_ch_sw_info; // x0
  __int64 result; // x0
  const char *v14; // x2
  __int64 v15; // x0
  unsigned int freq_before_pre_cac; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  if ( !a1 )
  {
    v14 = "%s: null sap_ctx";
LABEL_11:
    qdf_trace_msg(0x39u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "sap_indicate_radar");
    return 0;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v14 = "%s: Invalid MAC context";
    goto LABEL_11;
  }
  v11 = context;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !sap_ch_sw_info )
  {
    v14 = "%s: Invalid channel info";
    goto LABEL_11;
  }
  if ( a1[182] == 2 )
    *(_BYTE *)(sap_ch_sw_info + 8) = 1;
  if ( *(_BYTE *)(v11[1] + 3369LL) == 1 )
  {
    *(_DWORD *)(sap_ch_sw_info + 16) = a1[375];
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: DFS channel switch disabled, CSA to same ch %d wd %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sap_indicate_radar",
      *a1);
    return *a1;
  }
  else
  {
    v15 = *((_QWORD *)a1 + 2);
    *((_BYTE *)a1 + 13) = 1;
    freq_before_pre_cac = wlan_pre_cac_get_freq_before_pre_cac(v15);
    if ( freq_before_pre_cac )
    {
      v25 = freq_before_pre_cac;
      qdf_trace_msg(
        0x39u,
        4u,
        "%s: sapdfs: set chan freq before pre cac %d as target chan",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "sap_indicate_radar",
        freq_before_pre_cac);
      return v25;
    }
    else if ( *((_BYTE *)a1 + 1628) != 1
           || (result = sap_signal_hdd_event((__int64)a1, 0, 0x17u, nullptr, v17, v18, v19, v20, v21, v22, v23, v24),
               (_DWORD)result) )
    {
      v26 = sap_random_channel_sel(a1);
      if ( !v26 )
        sap_signal_hdd_event((__int64)a1, 0, 0x12u, nullptr, v27, v28, v29, v30, v31, v32, v33, v34);
      qdf_trace_msg(
        0x39u,
        3u,
        "%s: sapdfs: New selected target freq is [%d]",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_indicate_radar",
        v26);
      return v26;
    }
  }
  return result;
}
