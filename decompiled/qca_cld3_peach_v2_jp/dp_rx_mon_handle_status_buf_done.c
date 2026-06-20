__int64 __fastcall dp_rx_mon_handle_status_buf_done(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  int v12; // w8
  int v13; // w9
  unsigned int v14; // w10
  int v15; // w11
  unsigned int v16; // w8
  __int64 v17; // x8
  unsigned int v18; // w20
  __int64 v19; // x22
  void (__fastcall *v20)(__int64, __int64 *); // x9
  __int64 v21; // x19
  __int64 v22; // x8
  __int64 *v23; // x9
  __int64 v24; // x20
  __int64 v25; // x19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  __int64 v35; // x22
  __int64 v36; // x0
  __int64 v37; // [xsp+8h] [xbp-18h] BYREF
  __int64 v38; // [xsp+10h] [xbp-10h]
  __int64 v39; // [xsp+18h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 8);
  v37 = 0;
  v38 = 0;
  if ( a3 >= 3u )
    __break(0x5512u);
  v12 = *(_DWORD *)(a2 + 120);
  v13 = *(_DWORD *)(a2 + 44);
  v14 = *(_DWORD *)(a2 + 36);
  v15 = *(_DWORD *)(a2 + 136);
  if ( (v13 + v12) % v14 == v15
    || (v16 = (v12 + 2 * v13) % v14, v16 == v15)
    || (v17 = *(_QWORD *)(a2 + 16) + 4LL * v16) == 0 )
  {
    qdf_trace_msg(
      0x84u,
      8u,
      "%s: %pK: Monitor status ring entry is NULL for SRNG: %pK",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_rx_mon_handle_status_buf_done",
      v11,
      a2);
    result = 0;
  }
  else
  {
    v18 = a3;
    v19 = v11;
    v20 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(v11 + 1128) + 74392LL) + 1456LL);
    v21 = *(_QWORD *)(a1 + 95560);
    if ( *((_DWORD *)v20 - 1) != -621572614 )
      __break(0x8229u);
    v20(v17, &v37);
    if ( (v38 & 0xE0000) != 0
      || (v22 = v19,
          (v23 = (__int64 *)(*(_QWORD *)(*(_QWORD *)(v19
                                                   + 120 * (((unsigned __int64)(unsigned int)v38 >> 16) & 1)
                                                   + 11912)
                                       + 8LL * BYTE1(v38))
                           + (unsigned __int8)v38
                           * (unsigned int)*(unsigned __int16 *)(v19
                                                               + 120 * (((unsigned __int64)(unsigned int)v38 >> 16) & 1)
                                                               + 11892))) == nullptr) )
    {
      v36 = printk(
              &unk_9BB309,
              "rx_desc",
              "dp_rx_mon_handle_status_buf_done",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/1.0/dp_rx_mon_status_1.0.c");
      dump_stack(v36);
      v22 = v19;
      v23 = nullptr;
    }
    v24 = v21 + 18528LL * v18;
    v25 = *v23;
    _qdf_nbuf_sync_for_cpu(*(_QWORD *)(v22 + 24), *v23);
    if ( (**(_DWORD **)(v25 + 224) & 0x3FE) == 0x24C )
    {
      ++*(_DWORD *)(v24 + 2972);
    }
    else
    {
      v35 = jiffies;
      if ( dp_rx_mon_handle_status_buf_done___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Monitor status ring: DMA is not done for nbuf: %pK",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "dp_rx_mon_handle_status_buf_done",
          v25);
        dp_rx_mon_handle_status_buf_done___last_ticks = v35;
      }
      ++*(_DWORD *)(v24 + 2968);
    }
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
