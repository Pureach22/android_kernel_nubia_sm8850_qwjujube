__int64 __fastcall dp_tx_compute_hw_delay_us(
        __int64 a1,
        int a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8
  int v15; // w7
  unsigned int v16; // w9
  unsigned int v17; // w10
  unsigned int v18; // w8
  __int64 v19; // x4
  int v20; // w8
  __int64 v21; // x20
  __int64 v22; // x20
  _DWORD *v23; // x19
  int v24; // [xsp+18h] [xbp-58h]

  if ( !a3 )
    return 4;
  v13 = *(_QWORD *)(a1 + 16);
  if ( (v13 & 0x100000000LL) == 0 )
    return 4;
  v15 = *(_DWORD *)(a1 + 24);
  v16 = (unsigned int)v13 >> 13;
  v17 = (v15 - a2) & 0xE0000000 | ((unsigned int)v13 >> 13 << 10);
  v18 = v17 - 0x20000000;
  if ( v17 <= v15 - a2 )
    v18 = v17;
  v19 = v15 - a2 - v18;
  if ( (int)(v15 - a2 - v18) < 0 )
  {
    v22 = jiffies;
    if ( dp_tx_compute_hw_delay_us___last_ticks - jiffies + 125 < 0 )
    {
      v24 = *(_DWORD *)(a1 + 24);
      v23 = a3;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: delay = 0x%x (-ve)\n"
        "release_src = %d\n"
        "ppdu_id = 0x%x\n"
        "peer_id = 0x%x\n"
        "tid = 0x%x\n"
        "release_reason = %d\n"
        "tsf = %u (0x%x)\n"
        "buffer_timestamp = %u (0x%x)\n"
        "delta_tsf = %u (0x%x)\n",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "dp_tx_compute_hw_delay_us",
        v19,
        *(_DWORD *)(a1 + 8) & 7,
        *(_DWORD *)(a1 + 12) & 0xFFFFFF,
        (unsigned __int16)*(_DWORD *)(a1 + 28),
        (unsigned __int8)BYTE2(*(_DWORD *)(a1 + 28)),
        (*(_DWORD *)(a1 + 8) >> 13) & 0xF,
        v24,
        v24,
        v16,
        v16,
        a2,
        a2,
        v11,
        v12);
      a3 = v23;
      v20 = 0;
      dp_tx_compute_hw_delay_us___last_ticks = v22;
    }
    else
    {
      v20 = 0;
    }
    goto LABEL_14;
  }
  v20 = v19 & 0x1FFFFFFF;
  if ( ((unsigned int)v19 & 0x1FFFFFFF) < 0x1000001 )
  {
LABEL_14:
    *a3 = v20;
    return 0;
  }
  v21 = jiffies;
  if ( dp_tx_compute_hw_delay_us___last_ticks_34 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: ----------------------\n"
      "Tx completion status:\n"
      "----------------------\n"
      "release_src = %d\n"
      "ppdu_id = 0x%x\n"
      "release_reason = %d\n"
      "tsf = %u (0x%x)\n"
      "buffer_timestamp = %u (0x%x)\n"
      "delta_tsf = %u (0x%x)\n",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_tx_compute_hw_delay_us",
      *(_DWORD *)(a1 + 8) & 7,
      *(_DWORD *)(a1 + 12) & 0xFFFFFF,
      (*(_DWORD *)(a1 + 8) >> 13) & 0xF,
      *(_DWORD *)(a1 + 24),
      v16,
      v16,
      a2,
      a2);
    dp_tx_compute_hw_delay_us___last_ticks_34 = v21;
  }
  return 16;
}
