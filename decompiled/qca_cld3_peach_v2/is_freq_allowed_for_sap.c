__int64 __fastcall is_freq_allowed_for_sap(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  __int64 v15; // x25
  unsigned int v16; // w20
  unsigned int chan_enum_for_freq; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char is_prev_n_freqs_free; // w0
  __int64 v27; // x24
  unsigned int v28; // w0
  const char *v29; // x2
  unsigned int v30; // w1
  unsigned __int16 bw_value; // w0
  unsigned __int16 *bonded_chan_entry; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int16 *v41; // x23
  __int64 v42; // x0
  __int64 v43; // x1
  __int64 v44; // x2
  __int64 v46; // [xsp+0h] [xbp-10h] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a2 + 1544);
  v15 = *(_QWORD *)(a2 + 16);
  WORD2(v46) = 0;
  LOWORD(v46) = 0;
  v16 = *(unsigned __int16 *)(v14 + 42);
  chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(a3, a4, a5, a6, a7, a8, a9, a10, a11);
  is_prev_n_freqs_free = 0;
  if ( chan_enum_for_freq <= 0x65 )
  {
    v27 = *(_QWORD *)(a1 + 80);
    if ( !v27 )
    {
      v29 = "%s: invalid psoc";
LABEL_10:
      v30 = 2;
LABEL_21:
      qdf_trace_msg(0x39u, v30, v29, v18, v19, v20, v21, v22, v23, v24, v25, "is_freq_allowed_for_sap", v46, v47);
LABEL_22:
      is_prev_n_freqs_free = 0;
      goto LABEL_23;
    }
    if ( !(unsigned int)wlan_mlme_get_ap_policy(v15, v18, v19, v20, v21, v22, v23, v24, v25)
      && (*(_BYTE *)(*(_QWORD *)(a2 + 1544) + 610LL) & 1) == 0 )
    {
      v29 = "%s: low latency sap is not present";
      goto LABEL_20;
    }
    v28 = wlan_reg_min_24ghz_chan_freq();
    if ( (policy_mgr_2_freq_always_on_same_mac(v27, v28, a3) & 1) != 0 )
    {
      v29 = "%s: frequency can be shared by 2G MAC";
LABEL_20:
      v30 = 8;
      goto LABEL_21;
    }
    if ( (unsigned int)wlan_reg_get_min_max_bw_for_chan_index(
                         a1,
                         chan_enum_for_freq,
                         (_WORD *)&v46 + 2,
                         &v46,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25) )
    {
      v29 = "%s: get bw for curr channel failed";
      goto LABEL_10;
    }
    bw_value = wlan_reg_get_bw_value(v16);
    if ( WORD2(v46) > (unsigned int)bw_value || (unsigned __int16)v46 < (unsigned int)bw_value )
    {
      v29 = "%s: frequency doesn't support configured bw";
      goto LABEL_20;
    }
    bonded_chan_entry = wlan_reg_get_bonded_chan_entry(a3, v16, 0, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( !bonded_chan_entry )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Invalid freq range for freq: %d and ch_width: %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "is_freq_allowed_for_sap",
        a3,
        v16);
      goto LABEL_22;
    }
    v41 = bonded_chan_entry;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: freq range for bw %d is %d-%d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "is_freq_allowed_for_sap",
      v16,
      *bonded_chan_entry,
      bonded_chan_entry[1]);
    is_prev_n_freqs_free = 0;
    if ( (int)v16 > 2 )
    {
      if ( v16 == 3 )
      {
        v42 = a2 + 1779;
        v43 = chan_enum_for_freq;
        v44 = 8;
      }
      else
      {
        if ( v16 != 7 )
          goto LABEL_23;
        v42 = a2 + 1779;
        v43 = chan_enum_for_freq;
        v44 = 16;
      }
LABEL_30:
      is_prev_n_freqs_free = sap_is_prev_n_freqs_free(v42, v43, v44, v41);
      goto LABEL_23;
    }
    if ( v16 == 1 )
    {
      v42 = a2 + 1779;
      v43 = chan_enum_for_freq;
      v44 = 2;
      goto LABEL_30;
    }
    if ( v16 == 2 )
    {
      v42 = a2 + 1779;
      v43 = chan_enum_for_freq;
      v44 = 4;
      goto LABEL_30;
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return is_prev_n_freqs_free & 1;
}
