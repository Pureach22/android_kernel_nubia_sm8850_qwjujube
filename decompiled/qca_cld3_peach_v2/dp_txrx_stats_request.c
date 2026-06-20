__int64 __fastcall dp_txrx_stats_request(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x20
  unsigned __int64 v16; // x8
  unsigned int v17; // w9
  unsigned int v24; // w11
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  __int64 v34; // x8
  unsigned int v35; // w21
  unsigned int v36; // w5
  unsigned int *v37; // x8
  unsigned int v38; // w22
  int v39; // w23
  __int64 v40; // x0
  __int64 v41; // x23
  unsigned int v42; // w24
  const char *v43; // x2
  const char *v44; // x2
  unsigned int v45; // w1
  unsigned __int8 *v46; // x10
  int v47; // w11
  unsigned int v48; // w13
  int v49; // w11
  int v50; // w11
  int v51; // w11
  int v52; // w11
  unsigned int v53; // w0
  __int64 v54; // x4
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2
  unsigned int v64; // w1
  unsigned int v67; // w9
  __int64 v68; // x8

  if ( a2 > 5u )
    goto LABEL_22;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18984);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18984);
    *(_QWORD *)(a1 + 18992) |= 1uLL;
  }
  v15 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
  if ( !v15 )
  {
LABEL_20:
    v34 = *(_QWORD *)(a1 + 18992);
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
LABEL_22:
    qdf_trace_msg(
      0x89u,
      2u,
      "%s: %pK: Invalid vdev/req instance",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_txrx_stats_request",
      a1);
    return 4;
  }
  v16 = v15 + 40960;
  v17 = *(_DWORD *)(v15 + 43384);
  do
  {
    if ( !v17 )
      goto LABEL_20;
    _X13 = (unsigned int *)(v15 + 43384);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v24 = __ldxr(_X13);
      if ( v24 != v17 )
        break;
      if ( !__stlxr(v17 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v24 == v17;
    v17 = v24;
  }
  while ( !_ZF );
  while ( 1 )
  {
    _X8 = (unsigned int *)(v16 + 2456);
    __asm { PRFM            #0x11, [X8] }
    do
      v67 = __ldxr(_X8);
    while ( __stxr(v67 + 1, _X8) );
    v68 = *(_QWORD *)(a1 + 18992);
    if ( (v68 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v68 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
      if ( !a3 )
      {
LABEL_62:
        v44 = "%s: %pK: Invalid vdev/req instance";
        v45 = 2;
        goto LABEL_63;
      }
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
      if ( !a3 )
        goto LABEL_62;
    }
    if ( *((unsigned __int8 *)a3 + 24) >= 2u )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Invalid mac_id: %u request",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_txrx_stats_request");
      goto LABEL_64;
    }
    v33 = (unsigned int *)*a3;
    if ( (unsigned int)v33 > 0x108 )
      goto LABEL_64;
    if ( (unsigned int)v33 <= 0x100 )
      v36 = *a3;
    else
      v36 = (_DWORD)v33 - 237;
    if ( v36 >= 0x2B )
    {
      qdf_trace_msg(
        0x89u,
        2u,
        "%s: %pK : Invalid stats option: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_txrx_stats_request",
        a1);
      goto LABEL_64;
    }
    *a3 = v36;
    v16 = (8LL * v36) | 4;
    if ( v16 <= 0x158 )
      break;
    __break(1u);
  }
  v37 = (unsigned int *)((char *)&dp_stats_mapping_table + 8 * v36);
  v38 = *v37;
  v39 = v37[1];
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: stats: %u fw_stats_type: %d host_stats: %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "dp_txrx_stats_request",
    v36,
    *v37,
    (unsigned int)v39);
  if ( v38 == -1 )
  {
    if ( v39 != -1 && v39 <= 20 )
    {
      ((void (__fastcall *)(__int64, unsigned int *, __int64))dp_print_host_stats)(v15, a3, a1);
      v35 = 0;
      goto LABEL_65;
    }
    v44 = "%s: %pK: Wrong Input for TxRx Stats";
    v45 = 5;
LABEL_63:
    qdf_trace_msg(0x89u, v45, v44, v25, v26, v27, v28, v29, v30, v31, v32, "dp_txrx_stats_request", a1);
LABEL_64:
    v35 = 4;
    goto LABEL_65;
  }
  *a3 = v38;
  v40 = *(_QWORD *)(v15 + 24);
  if ( !v40 )
  {
    v43 = "PDEV not found";
LABEL_43:
    qdf_trace_msg(0x45u, 0, v43, v25, v26, v27, v28, v29, v30, v31, v32);
    v35 = 16;
    goto LABEL_65;
  }
  v41 = *(_QWORD *)(v40 + 8);
  if ( !v41 )
  {
    v43 = "soc not found";
    goto LABEL_43;
  }
  v42 = a3[5];
  if ( !v38 )
  {
    *(_QWORD *)(a3 + 1) = 0xFFFFFFFF00000001LL;
    *(_QWORD *)(a3 + 3) = -1;
    goto LABEL_47;
  }
  if ( v38 == 11 )
  {
    v46 = *((unsigned __int8 **)a3 + 4);
    if ( v46 )
    {
      v47 = a3[2] | 0x7FFFFFFF;
      a3[1] |= 1u;
      a3[2] = v47;
      v48 = a3[4];
      v49 = a3[3] | *v46;
      a3[3] = v49;
      v50 = v49 | (v46[1] << 8);
      a3[3] = v50;
      v51 = v50 | (v46[2] << 16);
      a3[3] = v51;
      a3[3] = v51 | (v46[3] << 24);
      v52 = v48 | v46[4];
      a3[4] = v52;
      a3[4] = v52 | (v46[5] << 8);
      goto LABEL_47;
    }
    qdf_trace_msg(0x45u, 2u, "%s: peer_addr is not set", v25, v26, v27, v28, v29, v30, v31, v32, "dp_fw_stats_process");
    v35 = 16;
  }
  else
  {
    if ( v38 == 17 )
      a3[1] = (2 * *(unsigned __int8 *)(v15 + 59)) | 1;
LABEL_47:
    ((void (__fastcall *)(__int64))dp_h2t_ext_stats_msg_send)(v40);
    v35 = 0;
    if ( v42 == 32 )
    {
      v53 = qdf_wait_single_event(*(_QWORD *)(v41 + 17584) + 96LL, 0xBB8u);
      if ( v53 == 15 )
      {
        v63 = "%s: sysfs_txrx_fw_request_done event expired";
        v64 = 3;
LABEL_52:
        qdf_trace_msg(0x89u, v64, v63, v55, v56, v57, v58, v59, v60, v61, v62, "dp_sysfs_event_trigger", v54);
        v35 = 0;
      }
      else
      {
        v54 = v53;
        if ( !v53 )
        {
          v63 = "%s: sysfs_txrx_fw_request_done event completed";
          v64 = 5;
          goto LABEL_52;
        }
        qdf_trace_msg(
          0x89u,
          3u,
          "%s: sysfs_txrx_fw_request_done event error code %d",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "dp_sysfs_event_trigger",
          v53);
        v35 = 0;
      }
    }
  }
LABEL_65:
  dp_vdev_unref_delete(a1, v15, 7u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
  return v35;
}
