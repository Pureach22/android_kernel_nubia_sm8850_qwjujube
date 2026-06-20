__int64 __fastcall wlan_ipa_uc_stat(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x0
  __int64 v43; // x8
  void (*v44)(void); // x8
  __int64 result; // x0
  __int64 v46; // [xsp+0h] [xbp-130h]
  __int64 v47; // [xsp+0h] [xbp-130h]
  __int64 v48; // [xsp+8h] [xbp-128h]
  __int64 v49; // [xsp+8h] [xbp-128h]
  __int64 v50; // [xsp+10h] [xbp-120h]
  __int64 v51; // [xsp+10h] [xbp-120h]
  __int64 v52; // [xsp+18h] [xbp-118h]
  __int64 v53; // [xsp+18h] [xbp-118h]
  __int64 v54; // [xsp+20h] [xbp-110h]
  __int64 v55; // [xsp+20h] [xbp-110h]
  __int64 v56; // [xsp+28h] [xbp-108h]
  __int64 v57; // [xsp+28h] [xbp-108h]
  __int64 v58; // [xsp+30h] [xbp-100h]
  __int64 v59; // [xsp+30h] [xbp-100h]
  __int64 v60; // [xsp+38h] [xbp-F8h]
  __int64 v61; // [xsp+38h] [xbp-F8h]
  __int64 v62; // [xsp+40h] [xbp-F0h]
  __int64 v63; // [xsp+40h] [xbp-F0h]
  __int64 v64; // [xsp+48h] [xbp-E8h]
  __int64 v65; // [xsp+48h] [xbp-E8h]
  __int64 v66; // [xsp+50h] [xbp-E0h]
  __int64 v67; // [xsp+80h] [xbp-B0h] BYREF
  __int64 v68; // [xsp+88h] [xbp-A8h]
  __int64 v69; // [xsp+90h] [xbp-A0h]
  __int64 v70; // [xsp+98h] [xbp-98h]
  __int64 v71; // [xsp+A0h] [xbp-90h]
  __int64 v72; // [xsp+A8h] [xbp-88h]
  __int64 v73; // [xsp+B0h] [xbp-80h]
  __int64 v74; // [xsp+B8h] [xbp-78h]
  __int64 v75; // [xsp+C0h] [xbp-70h]
  __int64 v76; // [xsp+C8h] [xbp-68h]
  __int64 v77; // [xsp+D0h] [xbp-60h]
  __int64 v78; // [xsp+D8h] [xbp-58h]
  __int64 v79; // [xsp+E0h] [xbp-50h]
  __int64 v80; // [xsp+E8h] [xbp-48h]
  __int64 v81; // [xsp+F0h] [xbp-40h]
  __int64 v82; // [xsp+F8h] [xbp-38h]
  __int64 v83; // [xsp+100h] [xbp-30h]
  __int64 v84; // [xsp+108h] [xbp-28h]
  __int64 v85; // [xsp+110h] [xbp-20h]
  __int64 v86; // [xsp+118h] [xbp-18h]
  int v87; // [xsp+120h] [xbp-10h]
  __int64 v88; // [xsp+128h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \n"
    "==== IPA IPA TX/RX STATS ====\n"
    "NUM RM GRANT: %llu\n"
    "NUM RM RELEASE: %llu\n"
    "NUM RM GRANT IMM: %llu\n"
    "NUM CONS PERF REQ: %llu\n"
    "NUM PROD PERF REQ: %llu\n"
    "NUM RX DROP: %llu\n"
    "NUM EXCP PKT: %llu\n"
    "NUM TX FWD OK: %llu\n"
    "NUM TX FWD ERR: %llu\n"
    "NUM TX DESC Q CNT: %llu\n"
    "NUM TX DESC ERROR: %llu\n"
    "NUM TX COMP CNT: %llu\n"
    "NUM TX QUEUED: %llu\n"
    "NUM TX DEQUEUED: %llu\n"
    "NUM MAX PM QUEUE: %llu\n"
    "TX REF CNT: %d\n"
    "SUSPENDED: %d\n"
    "PEND DESC HEAD: %pK\n"
    "TX DESC LIST: %pK\n",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_print_txrx_stats",
    *(_QWORD *)(a1 + 3568),
    *(_QWORD *)(a1 + 3576),
    *(_QWORD *)(a1 + 3584),
    *(_QWORD *)(a1 + 3592),
    *(_QWORD *)(a1 + 3600),
    *(_QWORD *)(a1 + 3608),
    *(_QWORD *)(a1 + 3664),
    *(_QWORD *)(a1 + 3680),
    *(_QWORD *)(a1 + 3688),
    *(_QWORD *)(a1 + 3616),
    *(_QWORD *)(a1 + 3624),
    *(_QWORD *)(a1 + 3632),
    *(_QWORD *)(a1 + 3640),
    *(_QWORD *)(a1 + 3648),
    *(_QWORD *)(a1 + 3656),
    *(_DWORD *)(a1 + 3284),
    *(unsigned __int8 *)(a1 + 3376),
    a1 + 3448,
    a1 + 3472);
  if ( *(_BYTE *)(a1 + 1116) != 5 )
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: IFACE[%d]: TX:%llu, TX DROP:%llu, TX ERR:%llu, TX CAC DROP:%llu, RX IPA EXCEP:%llu",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_ipa_print_txrx_stats",
      0,
      *(_QWORD *)(a1 + 1144),
      *(_QWORD *)(a1 + 1152),
      *(_QWORD *)(a1 + 1160),
      *(_QWORD *)(a1 + 1168),
      *(_QWORD *)(a1 + 1176));
  if ( *(_BYTE *)(a1 + 1244) != 5 )
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: IFACE[%d]: TX:%llu, TX DROP:%llu, TX ERR:%llu, TX CAC DROP:%llu, RX IPA EXCEP:%llu",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_ipa_print_txrx_stats",
      1,
      *(_QWORD *)(a1 + 1272),
      *(_QWORD *)(a1 + 1280),
      *(_QWORD *)(a1 + 1288),
      *(_QWORD *)(a1 + 1296),
      *(_QWORD *)(a1 + 1304));
  if ( *(_BYTE *)(a1 + 1372) != 5 )
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: IFACE[%d]: TX:%llu, TX DROP:%llu, TX ERR:%llu, TX CAC DROP:%llu, RX IPA EXCEP:%llu",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_ipa_print_txrx_stats",
      2,
      *(_QWORD *)(a1 + 1400),
      *(_QWORD *)(a1 + 1408),
      *(_QWORD *)(a1 + 1416),
      *(_QWORD *)(a1 + 1424),
      *(_QWORD *)(a1 + 1432));
  v87 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  ipa_get_wdi_stats(&v67);
  LODWORD(v66) = HIDWORD(v86);
  LODWORD(v64) = HIDWORD(v85);
  LODWORD(v62) = v85;
  LODWORD(v60) = HIDWORD(v84);
  LODWORD(v58) = HIDWORD(v83);
  LODWORD(v56) = v83;
  LODWORD(v54) = HIDWORD(v82);
  LODWORD(v52) = v82;
  LODWORD(v50) = v81;
  LODWORD(v48) = HIDWORD(v80);
  LODWORD(v46) = v80;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \n"
    "==== IPA WDI TX STATS ====\n"
    "NUM PROCD : %d\n"
    "CE DBELL : 0x%x\n"
    "NUM DBELL FIRED : %d\n"
    "COMP RNG FULL : %d\n"
    "COMP RNG EMPT : %d\n"
    "COMP RNG USE HGH : %d\n"
    "COMP RNG USE LOW : %d\n"
    "BAM FIFO FULL : %d\n"
    "BAM FIFO EMPT : %d\n"
    "BAM FIFO USE HGH : %d\n"
    "BAM FIFO USE LOW : %d\n"
    "NUM DBELL : %d\n"
    "NUM UNEXP DBELL : %d\n"
    "NUM BAM INT HDL : 0x%x\n"
    "NUM QMB INT HDL : 0x%x\n",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_ipa_print_ipa_wdi_stats",
    (unsigned int)v78,
    HIDWORD(v78),
    (unsigned int)v79,
    HIDWORD(v79),
    v46,
    v48,
    v50,
    v52,
    v54,
    v56,
    v58,
    v60,
    v62,
    v64,
    v66);
  LODWORD(v65) = HIDWORD(v73);
  LODWORD(v63) = HIDWORD(v74);
  LODWORD(v61) = v74;
  LODWORD(v59) = HIDWORD(v72);
  LODWORD(v57) = v72;
  LODWORD(v55) = HIDWORD(v71);
  LODWORD(v53) = v71;
  LODWORD(v51) = v70;
  LODWORD(v49) = HIDWORD(v69);
  LODWORD(v47) = v69;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \n"
    "==== IPA WDI RX STATS ====\n"
    "MAX OST PKT : %d\n"
    "NUM PKT PRCSD : %d\n"
    "RNG RP : 0x%x\n"
    "IND RNG FULL : %d\n"
    "IND RNG EMPT : %d\n"
    "IND RNG USE HGH : %d\n"
    "IND RNG USE LOW : %d\n"
    "BAM FIFO FULL : %d\n"
    "BAM FIFO EMPT : %d\n"
    "BAM FIFO USE HGH : %d\n"
    "BAM FIFO USE LOW : %d\n"
    "NUM DB : %d\n"
    "NUM UNEXP DB : %d\n"
    "NUM BAM INT HNDL : 0x%x\n",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_ipa_print_ipa_wdi_stats",
    (unsigned int)v67,
    HIDWORD(v67),
    (unsigned int)v68,
    HIDWORD(v68),
    v47,
    v49,
    v51,
    v53,
    v55,
    v57,
    v59,
    v61,
    v63,
    v65);
  qdf_mutex_acquire(a1 + 7224);
  if ( wlan_ipa_is_fw_wdi_activated(a1) && (*(_BYTE *)(a1 + 3720) & 1) == 0 )
  {
    v42 = *(_QWORD *)(a1 + 1456);
    *(_DWORD *)(a1 + 4120) = 1;
    if ( v42 && *(_QWORD *)v42 && (v43 = *(_QWORD *)(*(_QWORD *)v42 + 152LL)) != 0 )
    {
      v44 = *(void (**)(void))(v43 + 56);
      if ( v44 )
      {
        if ( *((_DWORD *)v44 - 1) != 261447488 )
          __break(0x8228u);
        v44();
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v34, v35, v36, v37, v38, v39, v40, v41, "cdp_ipa_get_stat");
    }
  }
  result = qdf_mutex_release(a1 + 7224);
  _ReadStatusReg(SP_EL0);
  return result;
}
