__int64 __fastcall dp_rx_process_invalid_peer(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x9
  __int64 v5; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8
  unsigned __int16 *v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int16 *v18; // x21
  int v19; // w9
  __int64 v20; // x22
  __int64 v21; // x22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v32; // x24
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x22
  __int64 v43; // x22
  _QWORD *v44; // x0
  _QWORD *v45; // x21
  __int64 v46; // x8
  __int64 v48; // x8
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x22
  int v67; // w25
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  void (__fastcall *v76)(__int64, unsigned __int16 *); // x8
  __int64 v77; // x0

  v3 = *(_QWORD *)(a1 + 1128);
  v5 = *(_QWORD *)(a2 + 224);
  v8 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 74392) + 1336LL);
  if ( *((_DWORD *)v8 - 1) != -640867646 )
    __break(0x8228u);
  v9 = (unsigned __int16 *)v8(v5);
  if ( (*(_BYTE *)v9 & 0xC) == 8 )
  {
    v18 = v9;
    if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
      v19 = *(unsigned __int16 *)(a2 + 66);
    else
      v19 = 0;
    if ( (unsigned int)(*(_DWORD *)(a2 + 112) + v19) <= 0x17 )
    {
      v21 = jiffies;
      if ( dp_rx_process_invalid_peer___last_ticks_16 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x7Eu,
          5u,
          "%s: %pK: Invalid nbuf length: %u",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "dp_rx_process_invalid_peer",
          a1);
        dp_rx_process_invalid_peer___last_ticks_16 = v21;
      }
      goto LABEL_27;
    }
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), a3)
      || (v30 = *(_QWORD *)(a1 + 72)) == 0 )
    {
      v43 = jiffies;
      if ( dp_rx_process_invalid_peer___last_ticks_18 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x7Eu,
          5u,
          "%s: %pK: PDEV not found",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "dp_rx_process_invalid_peer",
          a1);
        dp_rx_process_invalid_peer___last_ticks_18 = v43;
      }
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v30 + 312);
        v32 = *(_QWORD *)(v30 + 296);
        if ( v32 )
          goto LABEL_19;
        goto LABEL_21;
      }
      raw_spin_lock_bh(v30 + 312);
      *(_QWORD *)(v30 + 320) |= 1uLL;
      v32 = *(_QWORD *)(v30 + 296);
      if ( !v32 )
      {
LABEL_21:
        v33 = *(_QWORD *)(v30 + 320);
        if ( (v33 & 1) != 0 )
        {
          *(_QWORD *)(v30 + 320) = v33 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v30 + 312);
        }
        else
        {
          raw_spin_unlock(v30 + 312);
        }
        v42 = jiffies;
        if ( dp_rx_process_invalid_peer___last_ticks_20 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x7Eu,
            5u,
            "%s: %pK: VDEV not found",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "dp_rx_process_invalid_peer",
            a1);
          dp_rx_process_invalid_peer___last_ticks_20 = v42;
        }
        goto LABEL_27;
      }
LABEL_19:
      while ( (unsigned int)qdf_mem_cmp(v18 + 2, (const void *)(v32 + 96), 6u) )
      {
        v32 = *(_QWORD *)(v32 + 104);
        if ( !v32 )
          goto LABEL_21;
      }
      v48 = *(_QWORD *)(v30 + 320);
      if ( (v48 & 1) != 0 )
      {
        *(_QWORD *)(v30 + 320) = v48 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v30 + 312);
      }
      else
      {
        raw_spin_unlock(v30 + 312);
      }
      if ( *(_DWORD *)(v32 + 32) == 1 )
      {
        v49 = dp_peer_find_hash_find(a1, v18 + 5, 0, *(_BYTE *)(v32 + 59), 4u);
        if ( v49 )
        {
          dp_peer_unref_delete(v49, 4u, v50, v51, v52, v53, v54, v55, v56, v57);
          if ( a1 )
            ++*(_DWORD *)(a1 + 14152);
          v66 = jiffies;
          if ( dp_rx_process_invalid_peer___last_ticks_22 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: invalid peer frame with correct SA/RA is freed",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "dp_rx_process_invalid_peer");
            dp_rx_process_invalid_peer___last_ticks_22 = v66;
          }
          goto LABEL_27;
        }
        v67 = v18[5] & 1;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: TA %02x:%02x:%02x:**:**:%02x bmcast %d",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "dp_rx_process_invalid_peer",
          v67);
        if ( v67 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: skip rx invalid peer report to umac for b/mcast case",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "dp_rx_process_invalid_peer");
          goto LABEL_27;
        }
      }
      v76 = *(void (__fastcall **)(__int64, unsigned __int16 *))(*(_QWORD *)(a1 + 8) + 88LL);
      if ( v76 )
      {
        v77 = *(unsigned __int8 *)(v32 + 59);
        if ( *((_DWORD *)v76 - 1) != -80696377 )
          __break(0x8228u);
        v76(v77, v18);
      }
    }
  }
  else
  {
    v20 = jiffies;
    if ( dp_rx_process_invalid_peer___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: only for data frames",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "dp_rx_process_invalid_peer");
      dp_rx_process_invalid_peer___last_ticks = v20;
    }
  }
LABEL_27:
  if ( a2 )
  {
    v44 = (_QWORD *)a2;
    do
    {
      v45 = (_QWORD *)*v44;
      _qdf_nbuf_free((__int64)v44);
      v44 = v45;
    }
    while ( v45 );
  }
  if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), a3) )
  {
    v46 = *(_QWORD *)(a1 + 72);
    if ( v46 )
    {
      *(_QWORD *)(v46 + 368) = 0;
      *(_QWORD *)(v46 + 376) = 0;
    }
  }
  return 0;
}
