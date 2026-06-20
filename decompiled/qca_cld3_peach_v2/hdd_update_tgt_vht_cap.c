__int64 __fastcall hdd_update_tgt_vht_cap(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  unsigned int v48; // w22
  __int64 result; // x0
  int v50; // w8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  int v68; // w8
  int v69; // w9
  int v70; // w8
  int v71; // w8
  _BYTE v72[4]; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v73; // [xsp+8h] [xbp-38h] BYREF
  __int64 v74; // [xsp+10h] [xbp-30h]
  __int64 v75; // [xsp+18h] [xbp-28h]
  __int64 v76; // [xsp+20h] [xbp-20h]
  __int64 v77; // [xsp+28h] [xbp-18h]
  __int64 v78; // [xsp+30h] [xbp-10h]
  __int64 v79; // [xsp+38h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 24);
  v72[0] = 0;
  v11 = *(_QWORD *)(v10 + 336);
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  if ( v11 )
  {
    if ( (unsigned int)mlme_update_vht_cap(*(_QWORD *)a1, (unsigned int *)a2, *(_DWORD *)(a1 + 1248)) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not update vht capabilities",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_update_tgt_vht_cap");
    if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*(_QWORD *)a1, v72) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to get vht_enable2x2",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_update_tgt_vht_cap");
    v30 = vht_supported_datarate_bw80_gi400ns[v72[0] != 0];
    if ( (unsigned int)wlan_mlme_cfg_set_vht_rx_supp_data_rate(*(_QWORD *)a1, v30) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set rx_supp_data_rate",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "hdd_update_tgt_vht_cap");
    if ( (unsigned int)wlan_mlme_cfg_set_vht_tx_supp_data_rate(*(_QWORD *)a1, v30) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set tx_supp_data_rate",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "hdd_update_tgt_vht_cap");
    if ( (*(_BYTE *)(a2 + 12) & 0x20) != 0 )
      v30 = vht_supported_datarate_bw80_gi800ns[v72[0] != 0];
    if ( (unsigned int)(*(_DWORD *)a2 - 1) <= 1 )
      *(_DWORD *)(v11 + 56) |= *(_DWORD *)a2;
    v47 = *(_DWORD *)(a2 + 4);
    if ( (v47 & 0x10) != 0 )
    {
      v48 = 2;
      v50 = 8;
    }
    else
    {
      if ( (v47 & 8) == 0 )
      {
        v48 = 0;
        goto LABEL_21;
      }
      v48 = 1;
      v50 = 4;
    }
    *(_DWORD *)(v11 + 56) |= v50;
LABEL_21:
    if ( (unsigned int)wlan_mlme_cfg_set_vht_chan_width(*(_QWORD *)a1, v48) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not set the channel width",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "hdd_update_tgt_vht_cap");
      if ( (*(_BYTE *)(a2 + 8) & 0x10) == 0 )
        goto LABEL_23;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: supported channel width %d",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "hdd_update_tgt_vht_cap",
        v48);
      if ( (*(_BYTE *)(a2 + 8) & 0x10) == 0 )
      {
LABEL_23:
        result = wma_get_caps_for_phyidx_hwmode(&v73, 0, 2);
        if ( (_DWORD)result || (v74 & 0x1000000000LL) == 0 )
        {
LABEL_29:
          if ( (*(_BYTE *)(a2 + 12) & 0x20) != 0 )
          {
            *(_DWORD *)(v11 + 56) |= 0x20u;
            if ( (*(_BYTE *)(a2 + 16) & 0x40) == 0 )
            {
LABEL_31:
              v68 = v72[0];
              if ( !v72[0] )
                goto LABEL_37;
              goto LABEL_35;
            }
          }
          else if ( (*(_BYTE *)(a2 + 16) & 0x40) == 0 )
          {
            goto LABEL_31;
          }
          *(_DWORD *)(v11 + 56) |= 0x40u;
          v68 = v72[0];
          if ( !v72[0] )
            goto LABEL_37;
LABEL_35:
          if ( (*(_BYTE *)(a2 + 20) & 0x80) != 0 )
            *(_DWORD *)(v11 + 56) |= 0x80u;
LABEL_37:
          v69 = *(_DWORD *)(a2 + 24);
          if ( (v69 & 0x100) != 0 )
          {
            *(_DWORD *)(v11 + 56) |= 0x100u;
            v69 = *(_DWORD *)(a2 + 24);
          }
          if ( v68 && (v69 & 0x200) != 0 )
          {
            *(_DWORD *)(v11 + 56) |= 0x200u;
            v69 = *(_DWORD *)(a2 + 24);
          }
          v70 = *(_DWORD *)(v11 + 56);
          if ( (v69 & 0x300) != 0 )
          {
            v70 |= 0x300u;
            *(_DWORD *)(v11 + 56) = v70;
          }
          v71 = v70 | (*(_DWORD *)(a2 + 44) << 23);
          *(_DWORD *)(v11 + 56) = v71;
          if ( (*(_BYTE *)(a2 + 29) & 8) != 0 )
          {
            v71 |= 0x800u;
            *(_DWORD *)(v11 + 56) = v71;
            if ( (*(_BYTE *)(a2 + 33) & 0x10) == 0 )
            {
LABEL_46:
              if ( (*(_BYTE *)(a2 + 38) & 8) == 0 )
                goto LABEL_47;
              goto LABEL_54;
            }
          }
          else if ( (*(_BYTE *)(a2 + 33) & 0x10) == 0 )
          {
            goto LABEL_46;
          }
          v71 |= 0x1000u;
          *(_DWORD *)(v11 + 56) = v71;
          if ( (*(_BYTE *)(a2 + 38) & 8) == 0 )
          {
LABEL_47:
            if ( (*(_BYTE *)(a2 + 42) & 0x10) == 0 )
              goto LABEL_48;
            goto LABEL_55;
          }
LABEL_54:
          v71 |= 0x80000u;
          *(_DWORD *)(v11 + 56) = v71;
          if ( (*(_BYTE *)(a2 + 42) & 0x10) == 0 )
          {
LABEL_48:
            if ( (*(_BYTE *)(a2 + 50) & 0x20) == 0 )
            {
LABEL_50:
              *(_WORD *)(v11 + 62) = v30;
              *(_WORD *)(v11 + 66) = v30;
              goto LABEL_51;
            }
LABEL_49:
            *(_DWORD *)(v11 + 56) = v71 | 0x200000;
            goto LABEL_50;
          }
LABEL_55:
          v71 |= 0x100000u;
          *(_DWORD *)(v11 + 56) = v71;
          if ( (*(_BYTE *)(a2 + 50) & 0x20) == 0 )
            goto LABEL_50;
          goto LABEL_49;
        }
        v67 = "%s: VHT RX LDPC capability is set";
LABEL_28:
        *(_DWORD *)(v11 + 56) |= 0x10u;
        result = qdf_trace_msg(0x33u, 8u, v67, v59, v60, v61, v62, v63, v64, v65, v66, "hdd_update_tgt_vht_cap");
        goto LABEL_29;
      }
    }
    v67 = "%s: VHT RxLDPC capability is set";
    goto LABEL_28;
  }
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: 5GHz band disabled, skipping capability population",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_update_tgt_vht_cap");
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
