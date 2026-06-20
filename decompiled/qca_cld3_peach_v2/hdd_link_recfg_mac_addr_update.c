__int64 __fastcall hdd_link_recfg_mac_addr_update(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x21
  __int64 link_info_by_link_addr; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  __int64 v25; // x4
  _QWORD *v26; // x24
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _QWORD *v36; // x21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  int v48; // w8
  int v49; // w9
  int v50; // w10
  int v51; // w11
  int v52; // w12
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w2
  __int64 v66; // x4
  __int64 v67; // x5
  __int64 v68; // x6
  __int64 v69; // x7
  __int64 result; // x0
  __int64 v71; // x9
  __int64 v72; // x8
  int v73; // w12
  __int16 v74; // w10
  int v75; // w11
  char v76; // w10
  __int16 v77; // w10
  int v78; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v79; // [xsp+30h] [xbp-20h]
  __int128 v80; // [xsp+38h] [xbp-18h]
  __int64 v81; // [xsp+48h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_link_recfg_mac_addr_update", a4, a5, a6, a7, a8, a9, a10, a11);
  link_info_by_link_addr = hdd_get_link_info_by_link_addr((__int64)context, (__int64)a2);
  if ( !link_info_by_link_addr )
  {
    if ( a2 )
    {
      v53 = *a2;
      v54 = a2[1];
      v55 = a2[2];
      v56 = a2[5];
    }
    else
    {
      v55 = 0;
      v53 = 0;
      v54 = 0;
      v56 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: no hdd link with mac %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_link_recfg_mac_addr_update",
      v53,
      v54,
      v55,
      v56);
    v65 = 6512;
    goto LABEL_19;
  }
  v24 = *(unsigned __int8 *)(a1 + 168);
  v25 = *(unsigned __int8 *)(link_info_by_link_addr + 8);
  if ( (_DWORD)v25 != v24 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev id mismatch %d %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_link_recfg_mac_addr_update",
      v25,
      *(unsigned __int8 *)(a1 + 168));
    v65 = 6519;
LABEL_19:
    _cds_trigger_recovery(44, (__int64)"hdd_link_recfg_mac_addr_update", v65, v57, v58, v59, v60, v61, v62, v63, v64);
    result = 4;
    goto LABEL_20;
  }
  v26 = (_QWORD *)link_info_by_link_addr;
  v27 = hdd_get_link_info_by_link_addr((__int64)context, (__int64)a3);
  if ( !v27 )
  {
    if ( a3 )
    {
      v66 = *a3;
      v67 = a3[1];
      v68 = a3[2];
      v69 = a3[5];
    }
    else
    {
      v68 = 0;
      v66 = 0;
      v67 = 0;
      v69 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: no hdd link with mac %02x:%02x:%02x:**:**:%02x",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_link_recfg_mac_addr_update",
      v66,
      v67,
      v68,
      v69);
    v65 = 6527;
    goto LABEL_19;
  }
  if ( v26 == *(_QWORD **)(*v26 + 52832LL) || v27 == *(_QWORD *)(*(_QWORD *)v27 + 52832LL) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: deflink switched",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_link_recfg_mac_addr_update");
    v65 = 6534;
    goto LABEL_19;
  }
  v36 = (_QWORD *)v27;
  ucfg_dp_update_link_mac_addr(a1, a3, 1);
  if ( !a2 )
  {
    v47 = 0;
    v45 = 0;
    v46 = 0;
    v48 = 0;
    if ( a3 )
      goto LABEL_8;
LABEL_22:
    v51 = 0;
    v49 = 0;
    v50 = 0;
    v52 = 0;
    goto LABEL_23;
  }
  v45 = *a2;
  v46 = a2[1];
  v47 = a2[2];
  v48 = a2[5];
  if ( !a3 )
    goto LABEL_22;
LABEL_8:
  v49 = *a3;
  v50 = a3[1];
  v51 = a3[2];
  v52 = a3[5];
LABEL_23:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev id %d change self mac %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "hdd_link_recfg_mac_addr_update",
    v24,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52);
  hdd_adapter_update_links_on_link_switch(v26, v36);
  v71 = *v26;
  v80 = 0u;
  v79 = 0;
  v72 = v71 + 52800;
  if ( (*(_BYTE *)(v71 + 52800) & 1) != 0 )
  {
    if ( v71 )
    {
      v73 = *(_DWORD *)(v71 + 52912);
      v74 = *(_WORD *)(v71 + 52916);
      LOBYTE(v79) = *(_BYTE *)(v71 + 52848);
      *(_DWORD *)((char *)&v79 + 1) = v73;
      *(_WORD *)((char *)&v79 + 5) = v74;
      if ( v71 == -58928 )
      {
        LODWORD(v71) = 1;
      }
      else
      {
        HIBYTE(v79) = *(_BYTE *)(v71 + 58936);
        v75 = *(_DWORD *)(v71 + 59000);
        WORD2(v80) = *(_WORD *)(v71 + 59004);
        LODWORD(v80) = v75;
        if ( v71 == -65016 )
        {
          LODWORD(v71) = 2;
        }
        else
        {
          v76 = *(_BYTE *)(v71 + 65024);
          v71 += 65088;
          BYTE6(v80) = v76;
          v77 = *(_WORD *)(v71 + 4);
          *(_DWORD *)((char *)&v80 + 7) = *(_DWORD *)v71;
          LODWORD(v71) = 3;
          *(_WORD *)((char *)&v80 + 11) = v77;
        }
      }
    }
    v78 = v71;
    mlo_mgr_update_link_info_mac_addr(*(_QWORD *)(*(_QWORD *)(v72 + 32) + 32LL), &v78);
  }
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
