__int64 __fastcall dp_rxdma_ring_sel_cfg_be(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned __int16 v3; // w20
  __int64 (*v4)(void); // x8
  char v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x10
  unsigned int (*v16)(void); // x8
  __int64 v17; // x8
  int v18; // w22
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 (*v21)(void); // x8
  unsigned __int16 v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 (*v33)(void); // x8
  unsigned __int16 v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  __int64 v53; // x8
  __int64 (__fastcall *v54)(_QWORD); // x8
  int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  __int64 v65; // x8
  __int64 (*v66)(void); // x8
  int v67; // w0
  _BYTE *v68; // x23
  unsigned int v69; // w21
  _BYTE *v70; // x22
  int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w8
  __int64 v81; // x2
  unsigned __int64 v82; // x8
  __int64 v83; // x2
  __int64 v85; // [xsp+50h] [xbp-60h] BYREF
  __int64 v86; // [xsp+58h] [xbp-58h]
  __int64 v87; // [xsp+60h] [xbp-50h]
  __int64 v88; // [xsp+68h] [xbp-48h]
  __int64 v89; // [xsp+70h] [xbp-40h]
  __int64 v90; // [xsp+78h] [xbp-38h]
  __int64 v91; // [xsp+80h] [xbp-30h]
  __int64 v92; // [xsp+88h] [xbp-28h]
  __int64 v93; // [xsp+90h] [xbp-20h]
  __int64 v94; // [xsp+98h] [xbp-18h]
  __int64 v95; // [xsp+A0h] [xbp-10h]
  __int64 v96; // [xsp+A8h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[5];
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v87 = 0;
  v3 = wlan_cfg_rx_buffer_size(v2);
  v4 = *(__int64 (**)(void))(*(_QWORD *)(a1[141] + 74392LL) + 1896LL);
  if ( *((_DWORD *)v4 - 1) != 799902358 )
    __break(0x8228u);
  v5 = v4();
  v14 = 0x800100000100LL;
  v15 = a1[1];
  if ( (v5 & 1) != 0 )
    v14 = 0xC00100000100LL;
  LOWORD(v87) = 0;
  WORD1(v91) = 0;
  v85 = 2113549;
  v86 = v14;
  v16 = *(unsigned int (**)(void))(v15 + 200);
  LODWORD(v92) = 0;
  if ( !v16 )
    goto LABEL_10;
  if ( *((_DWORD *)v16 - 1) != 1696218653 )
    __break(0x8228u);
  if ( v16() == 4 )
    v17 = 1136;
  else
LABEL_10:
    v17 = 1138;
  v18 = *(unsigned __int16 *)((char *)a1 + v17);
  v19 = a1[141];
  LOWORD(v91) = 0;
  HIWORD(v90) = v18;
  if ( v19 && (v20 = *(_QWORD *)(v19 + 74392)) != 0 )
  {
    v21 = *(__int64 (**)(void))(v20 + 984);
    if ( *((_DWORD *)v21 - 1) != -605791253 )
      __break(0x8228u);
    v22 = v21();
  }
  else
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: hal handle is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hal_rx_mpdu_start_offset_get");
    v22 = 0;
  }
  v31 = a1[141];
  WORD2(v91) = v22;
  if ( v31 && (v32 = *(_QWORD *)(v31 + 74392)) != 0 )
  {
    v33 = *(__int64 (**)(void))(v32 + 960);
    if ( *((_DWORD *)v33 - 1) != -605791253 )
      __break(0x8228u);
    v34 = v33();
  }
  else
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: hal handle is NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hal_rx_msdu_end_offset_get");
    v34 = 0;
  }
  HIWORD(v91) = v34;
  v43 = qdf_trace_msg(
          0x45u,
          5u,
          "%s: TLV subscription\n"
          "msdu_start %d, mpdu_end %d, attention %d mpdu_start %d, msdu_end %d, pkt_hdr %d, pkt %d\n"
          "TLV offsets\n"
          "msdu_start %d, mpdu_end %d, attention %d mpdu_start %d, msdu_end %d, pkt_hdr %d, pkt %d\n",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "dp_rxdma_ring_sel_cfg_be",
          0,
          0,
          0,
          1,
          1,
          0,
          1,
          0,
          0,
          0,
          v22,
          v34,
          0,
          v18,
          v85,
          v86,
          v87);
  v52 = a1[141];
  if ( v52 && (v53 = *(_QWORD *)(v52 + 74392)) != 0 )
  {
    v54 = *(__int64 (__fastcall **)(_QWORD))(v53 + 1008);
    if ( *((_DWORD *)v54 - 1) != -605791253 )
      __break(0x8228u);
    v55 = v54(v43);
  }
  else
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: hal handle is NULL",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "hal_rx_msdu_end_wmask_get");
    v55 = 0;
  }
  v64 = a1[141];
  HIDWORD(v93) = v55;
  if ( v64 && (v65 = *(_QWORD *)(v64 + 74392)) != 0 )
  {
    v66 = *(__int64 (**)(void))(v65 + 1016);
    if ( *((_DWORD *)v66 - 1) != -605791253 )
      __break(0x8228u);
    v67 = v66();
  }
  else
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: hal handle is NULL",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "hal_rx_mpdu_start_wmask_get");
    v67 = 0;
  }
  v68 = (_BYTE *)a1[9];
  HIDWORD(v92) = v67;
  if ( v68 )
  {
    v70 = v68 + 112;
    v69 = (unsigned __int8)*v68;
    v71 = wlan_cfg_per_pdev_lmac_ring(a1[5]);
    v80 = v69;
    if ( v71 )
    {
      if ( v69 )
        goto LABEL_48;
      v80 = *(unsigned __int8 *)(a1[9] + 1LL);
    }
    if ( v80 < 3 )
    {
      v81 = *(_QWORD *)&v70[80 * v80];
      if ( v81 )
        htt_h2t_rx_ring_cfg(a1[6], v69, v81, 14, v3, &v85);
      if ( *v68 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Both mac_id and pdev_id cannot be non zero",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "dp_get_mac_id_for_pdev");
        v69 = 0;
        LOBYTE(v68) = *v68 == 0;
      }
      else
      {
        LOBYTE(v68) = 1;
        v69 = 1;
      }
      if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) )
        goto LABEL_49;
      if ( ((unsigned __int8)v68 & 1) != 0 )
      {
        v82 = *(unsigned __int8 *)(a1[9] + 1LL);
        if ( v82 < 3 )
        {
LABEL_52:
          v83 = *(_QWORD *)&v70[80 * (unsigned int)v82];
          if ( v83 )
            htt_h2t_rx_ring_cfg(a1[6], v69, v83, 14, v3, &v85);
          goto LABEL_54;
        }
      }
    }
LABEL_48:
    __break(0x5512u);
LABEL_49:
    if ( ((unsigned __int8)v68 & 1) != 0 )
    {
      LODWORD(v82) = 1;
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Both mac_id and pdev_id cannot be non zero",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "dp_get_lmac_id_for_pdev_id");
      LODWORD(v82) = 0;
    }
    goto LABEL_52;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return 0;
}
