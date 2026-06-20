void __fastcall wlan_hdd_get_station_remote(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v14; // x22
  bool v15; // zf
  bool v16; // zf
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x21
  __int64 mlpeer; // x0
  __int64 v29; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int64 v39; // x25
  char v40; // w9
  int v41; // w12
  int v42; // w13
  int v43; // w14
  int v44; // w15
  __int64 v45; // x9
  int v46; // w10
  int v47; // w12
  unsigned __int8 *v48; // x23
  char v49; // w22
  __int64 *sta_info_by_mac; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double link_peer_stats_sap; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int16 v67; // w9
  __int16 v68; // w8
  __int16 v69; // w10
  __int64 v70; // x4
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  const char *v82; // x2
  __int64 *v83; // [xsp+8h] [xbp-68h] BYREF
  __int64 v84; // [xsp+10h] [xbp-60h] BYREF
  _QWORD v85[4]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v86; // [xsp+38h] [xbp-38h]
  __int64 v87; // [xsp+40h] [xbp-30h]
  __int64 v88; // [xsp+48h] [xbp-28h]
  __int64 v89; // [xsp+50h] [xbp-20h]
  __int64 v90; // [xsp+58h] [xbp-18h]
  __int64 v91; // [xsp+60h] [xbp-10h]
  __int64 v92; // [xsp+68h] [xbp-8h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2 + 38;
  v15 = *(_DWORD *)(a2 + 38) == *(_DWORD *)a3 && *(unsigned __int16 *)(a2 + 42) == *(unsigned __int16 *)(a3 + 4);
  if ( !v15
    || (*(_DWORD *)(a2 + 32) == *(_DWORD *)a3
      ? (v16 = *(unsigned __int16 *)(a2 + 36) == *(unsigned __int16 *)(a3 + 4))
      : (v16 = 0),
        v16) )
  {
    wlan_hdd_get_link_peer_stats_sap(a1 + 2688, a2, a4);
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Get stats with mld level %02x:%02x:%02x:**:**:%02x",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wlan_hdd_get_station_remote",
    *(unsigned __int8 *)(a2 + 38),
    *(unsigned __int8 *)(a2 + 39),
    *(unsigned __int8 *)(a2 + 40),
    *(unsigned __int8 *)(a2 + 43));
  v90 = 0;
  v91 = 0;
  v25 = *(_QWORD *)(a1 + 55520);
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v26 = *(_QWORD *)(v25 + 32);
  memset(v85, 0, sizeof(v85));
  v83 = nullptr;
  v84 = 0;
  v27 = *(_QWORD *)(v26 + 1360);
  if ( !v27 )
  {
    v82 = "%s: no ap mlo dev ctxt";
LABEL_27:
    qdf_trace_msg(0x33u, 2u, v82, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_get_mld_peer_stats");
    goto LABEL_6;
  }
  mlpeer = mlo_get_mlpeer(*(_QWORD *)(v26 + 1360), v14);
  if ( !mlpeer )
  {
    v82 = "%s: Not a valid mld peer";
    goto LABEL_27;
  }
  v29 = mlpeer;
  LOBYTE(v84) = 0x80;
  qdf_mutex_acquire(v27 + 1584);
  v38 = 0;
  v39 = v29 + 16;
  v40 = 1;
  do
  {
    v48 = (unsigned __int8 *)(v39 + 40 * v38);
    v49 = v40;
    if ( v48 )
    {
      sta_info_by_mac = hdd_get_sta_info_by_mac(
                          (__int64 **)(a1 + 41536),
                          v48 + 8,
                          0xBu,
                          1u,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          v35,
                          v36,
                          v37);
      v83 = sta_info_by_mac;
      if ( sta_info_by_mac )
      {
        link_peer_stats_sap = wlan_hdd_get_link_peer_stats_sap(a1 + 2688, sta_info_by_mac, a4);
        hdd_put_sta_info_ref(
          a1 + 41536,
          (__int64 *)&v83,
          1,
          0xBu,
          link_peer_stats_sap,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66);
        if ( *((char *)a4 + 45) > (char)v84 )
        {
          v67 = *((_WORD *)a4 + 23);
          LOBYTE(v84) = *((_BYTE *)a4 + 45);
          v68 = *((_WORD *)a4 + 26);
          v69 = *((_WORD *)a4 + 27);
          *(_WORD *)((char *)&v84 + 1) = v67;
          *(_WORD *)((char *)&v84 + 3) = v68;
          *(_WORD *)((char *)&v84 + 5) = v69;
          qdf_mem_copy(v85, a4 + 7, 0xEu);
          qdf_mem_copy((char *)&v85[1] + 6, (char *)a4 + 70, 0xEu);
          v91 = *a4;
        }
        v41 = *((_DWORD *)a4 + 21);
        v42 = *((_DWORD *)a4 + 22);
        v43 = *((_DWORD *)a4 + 23);
        v44 = *((_DWORD *)a4 + 24);
        v45 = v87 + a4[4];
        v86 += a4[3];
        v87 = v45;
        LODWORD(v88) = v88 + v41;
        HIDWORD(v88) += v42;
        v46 = *((_DWORD *)a4 + 53);
        v47 = *((_DWORD *)a4 + 54);
        LODWORD(v89) = v89 + v43;
        HIDWORD(v89) += v44;
        LODWORD(v90) = v90 + v46;
        HIDWORD(v90) += v47;
      }
      else
      {
        if ( v48 == (unsigned __int8 *)-8LL )
        {
          v72 = 0;
          v70 = 0;
          v71 = 0;
          v73 = 0;
        }
        else
        {
          v70 = v48[8];
          v71 = v48[9];
          v72 = v48[10];
          v73 = v48[13];
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Peer %02x:%02x:%02x:**:**:%02x not found",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlan_hdd_get_mld_peer_stats",
          v70,
          v71,
          v72,
          v73);
      }
    }
    v40 = 0;
    v38 = 1;
  }
  while ( (v49 & 1) != 0 );
  qdf_mutex_release(v27 + 1584);
  wlan_hdd_copy_hdd_stats_to_sinfo(a4, &v84);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Sending aggregated mld peer stats",
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    "wlan_hdd_get_mld_peer_stats");
LABEL_6:
  _ReadStatusReg(SP_EL0);
}
