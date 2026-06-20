__int64 __fastcall hdd_get_txrx_nss(
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
  _QWORD *context; // x23
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x19
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 *v32; // x20
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x24
  __int64 v54; // x20
  unsigned int v55; // w22
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  _DWORD *v65; // x8
  __int64 v66; // x1
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x22
  __int64 v77; // x23
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  _WORD *v86; // x23
  __int64 v87; // x22
  __int64 v88; // x24
  _WORD *v89; // x22
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x22
  __int64 v99; // x24
  _WORD *v100; // x24
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x0
  __int64 v110; // x21
  __int64 v111; // x23
  __int64 v112; // x23
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v116; // x22
  int v117; // [xsp+Ch] [xbp-14h]
  _QWORD v118[2]; // [xsp+10h] [xbp-10h] BYREF

  v118[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_get_txrx_nss", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = _qdf_mem_malloc(0x10u, "hdd_get_txrx_nss", 1352);
  if ( !v13 )
  {
    v54 = jiffies;
    v55 = 2;
    if ( hdd_get_txrx_nss___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to allocate nss_stats",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_get_txrx_nss");
      hdd_get_txrx_nss___last_ticks = v54;
    }
    goto LABEL_60;
  }
  v22 = (__int64 *)v13;
  v23 = _qdf_mem_malloc(0x10u, "hdd_get_txrx_nss", 1358);
  if ( !v23 )
  {
    v110 = jiffies;
    if ( hdd_get_txrx_nss___last_ticks_11 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to allocate aggr_nss_stats",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_get_txrx_nss");
      hdd_get_txrx_nss___last_ticks_11 = v110;
    }
    _qdf_mem_free((__int64)v22);
    v55 = 2;
    goto LABEL_60;
  }
  v32 = (__int64 *)v23;
  v33 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1367);
  *v22 = v33;
  if ( !v33 )
    goto LABEL_43;
  v42 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1374);
  *v32 = v42;
  if ( !v42 )
    goto LABEL_47;
  v51 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1367);
  v22[1] = v51;
  if ( !v51 )
  {
LABEL_43:
    v111 = jiffies;
    if ( hdd_get_txrx_nss___last_ticks_13 - jiffies + 125 < 0 )
    {
      v55 = 2;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to allocate nss_stats column",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "hdd_get_txrx_nss");
      hdd_get_txrx_nss___last_ticks_13 = v111;
      v109 = *v22;
      if ( !*v22 )
        goto LABEL_59;
      goto LABEL_54;
    }
    goto LABEL_48;
  }
  v52 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1374);
  v32[1] = v52;
  if ( !v52 )
  {
LABEL_47:
    v112 = jiffies;
    if ( hdd_get_txrx_nss___last_ticks_15 - jiffies + 125 < 0 )
    {
      v55 = 2;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to allocate aggr_nss_stats column",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "hdd_get_txrx_nss");
      hdd_get_txrx_nss___last_ticks_15 = v112;
      v109 = *v22;
      if ( !*v22 )
        goto LABEL_59;
      goto LABEL_54;
    }
LABEL_48:
    v55 = 2;
    v109 = *v22;
    if ( !*v22 )
      goto LABEL_59;
    goto LABEL_54;
  }
  v117 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 104LL) + 18LL);
  if ( (v117 & 1) != 0 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Received Tx Rx NSS request",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "hdd_get_txrx_nss");
  if ( a1 )
  {
    if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
    {
      v53 = a1 + 52832;
      if ( a1 != -52832 )
      {
        while ( 1 )
        {
          if ( hdd_cm_is_vdev_associated((_DWORD *)v53) )
          {
            if ( context && *context && (v64 = *(_QWORD *)(*context + 8LL)) != 0 )
            {
              v65 = *(_DWORD **)(v64 + 224);
              if ( v65 )
              {
                v66 = *(unsigned __int8 *)(v53 + 8);
                if ( *(v65 - 1) != 893907105 )
                  __break(0x8228u);
                v67 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64 *))v65)(context, v66, v22);
                if ( v67 )
                {
                  v116 = jiffies;
                  if ( hdd_get_txrx_nss___last_ticks_18 - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Get stats failed, vdev_id: %d status: %d",
                      v68,
                      v69,
                      v70,
                      v71,
                      v72,
                      v73,
                      v74,
                      v75,
                      "hdd_get_txrx_nss",
                      *(unsigned __int8 *)(v53 + 8),
                      v67);
                    hdd_get_txrx_nss___last_ticks_18 = v116;
                  }
LABEL_51:
                  v55 = 16;
                  v109 = *v22;
                  if ( !*v22 )
                    goto LABEL_59;
LABEL_54:
                  _qdf_mem_free(v109);
                  if ( *v32 )
                    _qdf_mem_free(*v32);
                  v113 = v22[1];
                  if ( v113 )
                  {
                    _qdf_mem_free(v113);
                    v114 = v32[1];
                    if ( v114 )
                      _qdf_mem_free(v114);
                  }
                  goto LABEL_59;
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x89u,
                8u,
                "%s: Invalid Instance:",
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                "cdp_get_txrx_nss");
            }
            *(_DWORD *)*v32 += *(_DWORD *)*v22;
            *(_DWORD *)(*v32 + 4) += *(_DWORD *)(*v22 + 4);
            *(_DWORD *)v32[1] += *(_DWORD *)v22[1];
            *(_DWORD *)(v32[1] + 4) += *(_DWORD *)(v22[1] + 4);
          }
          if ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v53 - *(_DWORD *)v53 - 52832) >> 4)) )
          {
            v53 = a1 + 52832;
            if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
              continue;
          }
          break;
        }
      }
    }
  }
  v76 = *(_QWORD *)(a2 + 216);
  v77 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32823, 0, 0) & 0x80000000) != 0 )
    goto LABEL_50;
  v86 = (_WORD *)(v76 + v77);
  if ( !v86 )
    goto LABEL_50;
  v87 = *(_QWORD *)(a2 + 216);
  v88 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32769, 0, 0) & 0x80000000) != 0 )
    goto LABEL_50;
  v89 = (_WORD *)(v87 + v88);
  if ( !v89 )
    goto LABEL_50;
  LOBYTE(v118[0]) = 1;
  nla_put(a2, 1, 1, v118);
  v118[0] = *(int *)*v32;
  nla_put_64bit(a2, 2, 8, v118, 229);
  v118[0] = *(int *)(*v32 + 4);
  nla_put_64bit(a2, 3, 8, v118, 229);
  if ( v117 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: nss val %d tx_pkt %llu rx_pkt %llu",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "hdd_get_txrx_nss",
      1,
      *(int *)*v32,
      *(int *)(*v32 + 4));
  *v89 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v89;
  v98 = *(_QWORD *)(a2 + 216);
  v99 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32770, 0, 0) & 0x80000000) != 0 || (v100 = (_WORD *)(v98 + v99)) == nullptr )
  {
LABEL_50:
    qdf_trace_msg(0x33u, 2u, "%s: nla_nest_start failed", v78, v79, v80, v81, v82, v83, v84, v85, "hdd_get_txrx_nss");
    sk_skb_reason_drop(0, a2, 2);
    goto LABEL_51;
  }
  LOBYTE(v118[0]) = 2;
  nla_put(a2, 1, 1, v118);
  v118[0] = *(int *)v32[1];
  nla_put_64bit(a2, 2, 8, v118, 229);
  v118[0] = *(int *)(v32[1] + 4);
  nla_put_64bit(a2, 3, 8, v118, 229);
  if ( v117 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: nss val %d tx_pkt %llu rx_pkt %llu",
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      "hdd_get_txrx_nss",
      2,
      *(int *)v32[1],
      *(int *)(v32[1] + 4));
  v55 = 0;
  *v100 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v100;
  *v86 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v86;
  v109 = *v22;
  if ( *v22 )
    goto LABEL_54;
LABEL_59:
  _qdf_mem_free((__int64)v22);
  _qdf_mem_free((__int64)v32);
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v55;
}
