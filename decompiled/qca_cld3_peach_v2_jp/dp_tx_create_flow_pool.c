__int64 __fastcall dp_tx_create_flow_pool(
        __int64 a1,
        unsigned int a2,
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
  unsigned int v11; // w20
  const char *v12; // x2
  __int64 v16; // x24
  __int64 v17; // x19
  unsigned __int64 StatusReg; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  char v28; // w9
  __int64 v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  unsigned int tx_flow_stop_queue_th; // w20
  int tx_flow_start_queue_offset; // w0

  v11 = (unsigned __int8)a2;
  if ( (unsigned __int8)a2 >= 6u )
  {
    v12 = "%s: invalid flow_pool_id %d";
LABEL_20:
    qdf_trace_msg(0x45u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_create_flow_pool", v11);
    return 0;
  }
  v16 = a1 + 296LL * (unsigned __int8)a2;
  v17 = v16 + 2256;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v16 + 2512);
  }
  else
  {
    raw_spin_lock_bh(v16 + 2512);
    *(_QWORD *)(v16 + 2520) |= 1uLL;
  }
  if ( *(_DWORD *)(v16 + 2320) == 6 && !*(_BYTE *)(v16 + 2528) )
  {
    if ( (unsigned int)dp_tx_desc_pool_alloc(a1, a2, a3, 0, v19, v20, v21, v22, v23, v24, v25, v26) )
    {
      v27 = *(_QWORD *)(v16 + 2520);
      if ( (v27 & 1) != 0 )
      {
        *(_QWORD *)(v16 + 2520) = v27 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 2512);
      }
      else
      {
        raw_spin_unlock(v16 + 2512);
      }
      v12 = "%s: dp_tx_desc_pool_alloc failed flow_pool_id: %d";
    }
    else
    {
      if ( !(unsigned int)dp_tx_desc_pool_init(a1, a2, a3, 0) )
      {
        tx_flow_stop_queue_th = wlan_cfg_get_tx_flow_stop_queue_th(*(_QWORD *)(a1 + 40));
        tx_flow_start_queue_offset = wlan_cfg_get_tx_flow_start_queue_offset(*(_QWORD *)(a1 + 40));
        *(_BYTE *)(v16 + 2314) = a2;
        *(_WORD *)(v16 + 2312) = a3;
        *(_WORD *)(v16 + 2316) = a3;
        *(_DWORD *)(v16 + 2320) = 0;
        dp_tx_initialize_threshold(
          v16 + 2256,
          tx_flow_start_queue_offset + tx_flow_stop_queue_th,
          tx_flow_stop_queue_th,
          a3);
        ++*(_BYTE *)(v16 + 2528);
        qdf_spin_unlock_bh_23(v16 + 2512);
        return v17;
      }
      dp_tx_desc_pool_free(a1, a2, v38, v39, v40, v41, v42, v43, v44, v45);
      v46 = *(_QWORD *)(v16 + 2520);
      if ( (v46 & 1) != 0 )
      {
        *(_QWORD *)(v16 + 2520) = v46 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 2512);
      }
      else
      {
        raw_spin_unlock(v16 + 2512);
      }
      v12 = "%s: dp_tx_desc_pool_init failed flow_pool_id: %d";
    }
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: flow pool already allocated, attached %d times",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "dp_tx_flow_pool_reattach",
    *(unsigned __int8 *)(v16 + 2528));
  v28 = *(_BYTE *)(v16 + 2528);
  v29 = *(_QWORD *)(v16 + 2520);
  *(_DWORD *)(v16 + 2320) = 7;
  *(_BYTE *)(v16 + 2528) = v28 + 1;
  if ( (v29 & 1) != 0 )
  {
    *(_QWORD *)(v16 + 2520) = v29 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v16 + 2512);
  }
  else
  {
    raw_spin_unlock(v16 + 2512);
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: cannot alloc desc, status=%d, create_cnt=%d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "dp_tx_create_flow_pool",
    *(unsigned int *)(v16 + 2320),
    *(unsigned __int8 *)(v16 + 2528));
  return v17;
}
