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
  __int64 v53; // x25
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  _DWORD *v63; // x8
  __int64 v64; // x1
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x8
  __int64 v75; // x9
  __int64 v76; // x10
  __int64 v77; // x20
  unsigned int v78; // w22
  __int64 v79; // x21
  __int64 v80; // x23
  __int64 v81; // x0
  __int64 v82; // x23
  __int64 v83; // x22
  __int64 v84; // x23
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  _WORD *v93; // x23
  __int64 v94; // x22
  __int64 v95; // x24
  _WORD *v96; // x22
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x22
  __int64 v106; // x24
  _WORD *v107; // x24
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v119; // x22
  int v120; // [xsp+Ch] [xbp-14h]
  _QWORD v121[2]; // [xsp+10h] [xbp-10h] BYREF

  v121[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_get_txrx_nss", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = _qdf_mem_malloc(0x10u, "hdd_get_txrx_nss", 1352);
  if ( !v13 )
  {
    v77 = jiffies;
    v78 = 2;
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
      hdd_get_txrx_nss___last_ticks = v77;
    }
    goto LABEL_68;
  }
  v22 = (__int64 *)v13;
  v23 = _qdf_mem_malloc(0x10u, "hdd_get_txrx_nss", 1358);
  if ( !v23 )
  {
    v79 = jiffies;
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
      hdd_get_txrx_nss___last_ticks_11 = v79;
    }
    _qdf_mem_free((__int64)v22);
    v78 = 2;
    goto LABEL_68;
  }
  v32 = (__int64 *)v23;
  v33 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1367);
  *v22 = v33;
  if ( !v33 )
    goto LABEL_39;
  v42 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1374);
  *v32 = v42;
  if ( !v42 )
    goto LABEL_43;
  v51 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1367);
  v22[1] = v51;
  if ( !v51 )
  {
LABEL_39:
    v80 = jiffies;
    if ( hdd_get_txrx_nss___last_ticks_13 - jiffies + 125 < 0 )
    {
      v78 = 2;
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
      hdd_get_txrx_nss___last_ticks_13 = v80;
      v81 = *v22;
      if ( !*v22 )
        goto LABEL_67;
      goto LABEL_62;
    }
    goto LABEL_44;
  }
  v52 = _qdf_mem_malloc(0xCu, "hdd_get_txrx_nss", 1374);
  v32[1] = v52;
  if ( !v52 )
  {
LABEL_43:
    v82 = jiffies;
    if ( hdd_get_txrx_nss___last_ticks_15 - jiffies + 125 < 0 )
    {
      v78 = 2;
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
      hdd_get_txrx_nss___last_ticks_15 = v82;
      v81 = *v22;
      if ( !*v22 )
        goto LABEL_67;
      goto LABEL_62;
    }
LABEL_44:
    v78 = 2;
    v81 = *v22;
    if ( !*v22 )
      goto LABEL_67;
    goto LABEL_62;
  }
  v120 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 104LL) + 18LL);
  if ( (v120 & 1) != 0 )
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
    if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v53 = a1 + 52840, a1 != -52840)
      || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v53 = a1 + 58928, a1 != -58928)
      || (*(_QWORD *)(a1 + 1640) & 4) != 0 && (v53 = a1 + 65016, a1 != -65016) )
    {
      while ( 1 )
      {
        if ( hdd_cm_is_vdev_associated((_DWORD *)v53) )
        {
          if ( context && *context && (v62 = *(_QWORD *)(*context + 8LL)) != 0 )
          {
            v63 = *(_DWORD **)(v62 + 224);
            if ( v63 )
            {
              v64 = *(unsigned __int8 *)(v53 + 8);
              if ( *(v63 - 1) != 893907105 )
                __break(0x8228u);
              v65 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64 *))v63)(context, v64, v22);
              if ( v65 )
              {
                v119 = jiffies;
                if ( hdd_get_txrx_nss___last_ticks_18 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Get stats failed, vdev_id: %d status: %d",
                    v66,
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    "hdd_get_txrx_nss",
                    *(unsigned __int8 *)(v53 + 8),
                    v65);
                  hdd_get_txrx_nss___last_ticks_18 = v119;
                }
LABEL_59:
                v78 = 16;
                v81 = *v22;
                if ( !*v22 )
                  goto LABEL_67;
LABEL_62:
                _qdf_mem_free(v81);
                if ( *v32 )
                  _qdf_mem_free(*v32);
                v116 = v22[1];
                if ( v116 )
                {
                  _qdf_mem_free(v116);
                  v117 = v32[1];
                  if ( v117 )
                    _qdf_mem_free(v117);
                }
                goto LABEL_67;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              8u,
              "%s: Invalid Instance:",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "cdp_get_txrx_nss");
          }
          *(_DWORD *)*v32 += *(_DWORD *)*v22;
          *(_DWORD *)(*v32 + 4) += *(_DWORD *)(*v22 + 4);
          *(_DWORD *)v32[1] += *(_DWORD *)v22[1];
          *(_DWORD *)(v32[1] + 4) += *(_DWORD *)(v22[1] + 4);
        }
        if ( (unsigned __int8)(73 * ((unsigned int)(v53 - *(_DWORD *)v53 - 52840) >> 3) + 1) <= 2u )
        {
          v74 = (unsigned __int8)(73 * ((unsigned int)(v53 - *(_DWORD *)v53 - 52840) >> 3) + 1);
          v53 = 0;
          v75 = a1 + 52840 + 6088LL * (unsigned int)v74;
          do
          {
            if ( v53 )
              break;
            v76 = *(_QWORD *)(a1 + 1640) >> v74++;
            v53 = (v76 << 63 >> 63) & v75;
            v75 += 6088;
          }
          while ( v74 != 3 );
          if ( v53 )
            continue;
        }
        break;
      }
    }
  }
  v83 = *(_QWORD *)(a2 + 216);
  v84 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32823, 0, 0) & 0x80000000) != 0 )
    goto LABEL_58;
  v93 = (_WORD *)(v83 + v84);
  if ( !v93 )
    goto LABEL_58;
  v94 = *(_QWORD *)(a2 + 216);
  v95 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32769, 0, 0) & 0x80000000) != 0 )
    goto LABEL_58;
  v96 = (_WORD *)(v94 + v95);
  if ( !v96 )
    goto LABEL_58;
  LOBYTE(v121[0]) = 1;
  nla_put(a2, 1, 1, v121);
  v121[0] = *(int *)*v32;
  nla_put_64bit(a2, 2, 8, v121, 229);
  v121[0] = *(int *)(*v32 + 4);
  nla_put_64bit(a2, 3, 8, v121, 229);
  if ( v120 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: nss val %d tx_pkt %llu rx_pkt %llu",
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      "hdd_get_txrx_nss",
      1,
      *(int *)*v32,
      *(int *)(*v32 + 4));
  *v96 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v96;
  v105 = *(_QWORD *)(a2 + 216);
  v106 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32770, 0, 0) & 0x80000000) != 0 || (v107 = (_WORD *)(v105 + v106)) == nullptr )
  {
LABEL_58:
    qdf_trace_msg(0x33u, 2u, "%s: nla_nest_start failed", v85, v86, v87, v88, v89, v90, v91, v92, "hdd_get_txrx_nss");
    sk_skb_reason_drop(0, a2, 2);
    goto LABEL_59;
  }
  LOBYTE(v121[0]) = 2;
  nla_put(a2, 1, 1, v121);
  v121[0] = *(int *)v32[1];
  nla_put_64bit(a2, 2, 8, v121, 229);
  v121[0] = *(int *)(v32[1] + 4);
  nla_put_64bit(a2, 3, 8, v121, 229);
  if ( v120 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: nss val %d tx_pkt %llu rx_pkt %llu",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      "hdd_get_txrx_nss",
      2,
      *(int *)v32[1],
      *(int *)(v32[1] + 4));
  v78 = 0;
  *v107 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v107;
  *v93 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v93;
  v81 = *v22;
  if ( *v22 )
    goto LABEL_62;
LABEL_67:
  _qdf_mem_free((__int64)v22);
  _qdf_mem_free((__int64)v32);
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return v78;
}
