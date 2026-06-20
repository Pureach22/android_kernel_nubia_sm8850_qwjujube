__int64 __fastcall wma_print_wow_stats(__int64 result, __int64 a2)
{
  unsigned int v3; // w8
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double vdev_wake_lock_stats; // d0
  unsigned int *v15; // x8
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
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // [xsp+0h] [xbp-A0h]
  __int64 v56; // [xsp+0h] [xbp-A0h]
  __int64 v57; // [xsp+0h] [xbp-A0h]
  int v58; // [xsp+8h] [xbp-98h]
  __int64 v59; // [xsp+8h] [xbp-98h]
  __int64 v60; // [xsp+8h] [xbp-98h]
  int v61; // [xsp+10h] [xbp-90h]
  __int64 v62; // [xsp+10h] [xbp-90h]
  __int64 v63; // [xsp+10h] [xbp-90h]
  int v64; // [xsp+18h] [xbp-88h]
  __int64 v65; // [xsp+18h] [xbp-88h]
  int v66; // [xsp+20h] [xbp-80h]
  __int64 v67; // [xsp+28h] [xbp-78h] BYREF
  __int64 v68; // [xsp+30h] [xbp-70h]
  __int64 v69; // [xsp+38h] [xbp-68h]
  __int64 v70; // [xsp+40h] [xbp-60h]
  __int64 v71; // [xsp+48h] [xbp-58h]
  __int64 v72; // [xsp+50h] [xbp-50h]
  __int64 v73; // [xsp+58h] [xbp-48h]
  __int64 v74; // [xsp+60h] [xbp-40h]
  __int64 v75; // [xsp+68h] [xbp-38h]
  __int64 v76; // [xsp+70h] [xbp-30h]
  __int64 v77; // [xsp+78h] [xbp-28h]
  __int64 v78; // [xsp+80h] [xbp-20h]
  __int64 v79; // [xsp+88h] [xbp-18h]
  __int64 v80; // [xsp+90h] [xbp-10h]
  __int64 v81; // [xsp+98h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 12);
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
  if ( v3 <= 0x2F && ((1LL << v3) & 0xC2FE6005821DLL) != 0 || v3 == 68 || v3 == 64 )
  {
    v4 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           *(_QWORD *)(result + 24),
           *(unsigned int *)(a2 + 4),
           8);
    if ( v4 )
    {
      v13 = v4;
      vdev_wake_lock_stats = ucfg_mc_cp_stats_get_vdev_wake_lock_stats(v4, &v67);
      wlan_objmgr_vdev_release_ref(v13, 8u, v15, vdev_wake_lock_stats, v16, v17, v18, v19, v20, v21, v22);
      qdf_trace_msg(0x36u, 4u, "WLAN wake reason counters:", v23, v24, v25, v26, v27, v28, v29, v30);
      v61 = HIDWORD(v70);
      v66 = HIDWORD(v71);
      v64 = v71;
      v58 = v70;
      v55 = HIDWORD(v69);
      qdf_trace_msg(
        0x36u,
        4u,
        "uc:%d bc:%d v4_mc:%d v6_mc:%d ra:%d ns:%d na:%d mlq:%dicmp:%d icmpv6:%d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        (unsigned int)v67,
        HIDWORD(v67),
        (unsigned int)v68,
        HIDWORD(v68),
        (unsigned int)v69,
        v55,
        v58,
        v61,
        v64,
        v66);
      LODWORD(v56) = HIDWORD(v79);
      LODWORD(v62) = HIDWORD(v80);
      LODWORD(v59) = v80;
      qdf_trace_msg(
        0x36u,
        4u,
        "assoc:%d disassoc:%d assoc_resp:%d reassoc:%d reassoc_resp:%d auth:%d deauth:%d action:%d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        (unsigned int)v77,
        HIDWORD(v77),
        (unsigned int)v78,
        HIDWORD(v78),
        (unsigned int)v79,
        v56,
        v59,
        v62);
      LODWORD(v57) = HIDWORD(v74);
      LODWORD(v65) = HIDWORD(v75);
      LODWORD(v63) = HIDWORD(v76);
      LODWORD(v60) = v75;
      result = qdf_trace_msg(
                 0x36u,
                 4u,
                 "pno_match:%d pno_complete:%d gscan:%d low_rssi:%d rssi_breach:%d oem:%d ucdrop:%d scan_11d:%d fatal_event:%d",
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 v52,
                 v53,
                 v54,
                 (unsigned int)v74,
                 HIDWORD(v73),
                 (unsigned int)v73,
                 HIDWORD(v72),
                 (unsigned int)v72,
                 v57,
                 v60,
                 v63,
                 v65);
    }
    else
    {
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: vdev_id: %d, failed to get vdev from psoc",
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "wma_print_wow_stats",
                 *(unsigned int *)(a2 + 4));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
