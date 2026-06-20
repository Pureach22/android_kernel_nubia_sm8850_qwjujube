__int64 __fastcall dp_process_ul_delay(__int64 a1, unsigned __int8 a2)
{
  __int64 ref_by_id_1; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x21
  unsigned int *v15; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v17; // x8
  __int64 v18; // x20
  __int64 result; // x0
  unsigned int v20; // w9
  unsigned int v21; // w10
  unsigned int v22; // w11
  int v23; // w11
  unsigned int v24; // w11
  unsigned int v25; // w12
  int v26; // w12
  unsigned int v27; // w12
  int v28; // w9
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // [xsp+0h] [xbp-10h] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 7u);
  if ( ref_by_id_1 )
  {
    v13 = ref_by_id_1;
    v14 = ref_by_id_1 + 42728;
    v15 = (unsigned int *)*(unsigned int *)(ref_by_id_1 + 42728);
    if ( (_DWORD)v15 )
    {
      if ( *(_DWORD *)(ref_by_id_1 + 42744) )
        dp_accumulate_hist_stats(ref_by_id_1 + 4776, ref_by_id_1 + 4904);
      if ( *(_DWORD *)(v14 + 24) )
      {
        dp_accumulate_hist_stats(v13 + 4776, v13 + 5032);
        v38 = 0;
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v17 = 10 * StatusReg >= StatusReg ? 10 * StatusReg / 0xC0 : 10 * (StatusReg / 0xC0);
        if ( v17 - *(_QWORD *)(v14 + 32) >= 1000 * (unsigned __int64)*(unsigned __int16 *)(v14 + 28) )
        {
          v20 = *(_DWORD *)(v14 + 4);
          v21 = *(_DWORD *)(v14 + 8);
          v22 = *(_DWORD *)(v14 + 2688);
          if ( v21 < v22 )
            v23 = ~v22;
          else
            v23 = -v22;
          v24 = v23 + v21;
          if ( v24 )
          {
            v25 = *(_DWORD *)(v14 + 2684);
            *(_DWORD *)(v14 + 2684) = v20;
            *(_DWORD *)(v14 + 2688) = v21;
            HIWORD(v38) = v24;
            if ( v20 < v25 )
              v26 = ~v25;
            else
              v26 = -v25;
            v27 = (v26 + v20) / v24;
            LOBYTE(v38) = *(_BYTE *)(v13 + 59);
            v28 = *(_DWORD *)(v13 + 5152);
            WORD1(v38) = v27;
            *(_QWORD *)(v14 + 32) = v17;
            WORD2(v38) = v28;
            qdf_mem_set((void *)(v13 + 5032), 0x80u, 0);
            v29 = dp_h2t_tx_mlo_latency_stats_msg_send(
                    *(_QWORD *)(*(_QWORD *)(v13 + 24) + 8LL),
                    (unsigned __int16 *)&v38);
            if ( v29 )
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: Failed to send stats, Status: %d",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "dp_tx_report_tx_delay_to_fw",
                v29,
                v38,
                v39);
          }
          else
          {
            *(_DWORD *)(v14 + 2684) = v20;
            *(_DWORD *)(v14 + 2688) = v21;
          }
        }
      }
      qdf_mem_set((void *)(v13 + 4776), 0x80u, 0);
    }
    dp_vdev_unref_delete(a1, v13, 7u, v15, v5, v6, v7, v8, v9, v10, v11, v12);
    result = 0;
  }
  else
  {
    v18 = jiffies;
    if ( dp_process_ul_delay___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: vdev %d does not exist",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "dp_process_ul_delay",
        a2);
      dp_process_ul_delay___last_ticks = v18;
    }
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
