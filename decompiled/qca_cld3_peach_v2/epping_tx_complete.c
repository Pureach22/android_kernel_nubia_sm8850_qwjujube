__int64 __fastcall epping_tx_complete(__int64 result, __int64 a2)
{
  __int64 *v2; // x26
  __int64 v4; // x19
  __int64 v5; // x25
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w23
  unsigned int v16; // w24
  __int64 v17; // x20
  __int64 v18; // x21
  int v19; // w27
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  bool v28; // w22
  __int64 v29; // x6
  int v30; // w8
  __int64 v31; // x8

  if ( a2 )
  {
    v2 = *(__int64 **)(result + 48);
    v4 = result;
    v5 = v2[2];
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v2 + 4);
    }
    else
    {
      raw_spin_lock_bh(v2 + 4);
      v2[5] |= 1uLL;
    }
    v15 = *(_DWORD *)(a2 + 48);
    v16 = *(_DWORD *)(a2 + 52);
    v17 = *(_QWORD *)(a2 + 96);
    v18 = *(_QWORD *)(a2 + 16);
    if ( v17 )
    {
      if ( *(_QWORD *)(a2 + 32) != *(_QWORD *)(v17 + 224) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: htc_pkt buffer not equal to skb->data",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "epping_tx_complete");
      *(_QWORD *)v17 = 0;
      if ( !v16 )
      {
        v29 = *(unsigned int *)(a2 + 44);
        if ( (*(_BYTE *)(v17 + 68) & 4) != 0 )
          v30 = *(unsigned __int16 *)(v17 + 66);
        else
          v30 = 0;
        if ( *(_DWORD *)(v17 + 112) + v30 != (_DWORD)v29 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: htc_pkt length not equal to skb->len",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "epping_tx_complete");
          v29 = *(unsigned int *)(a2 + 44);
        }
        qdf_trace_msg(
          0x33u,
          4u,
          "%s skb=%pK data=%pK len=0x%x eid=%d ",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "epping_tx_complete",
          v17,
          *(_QWORD *)(a2 + 32),
          v29,
          v15);
        v19 = 1;
        goto LABEL_21;
      }
      v19 = 1;
    }
    else
    {
      qdf_trace_msg(0x33u, 2u, "%s: NULL skb from hc packet", v7, v8, v9, v10, v11, v12, v13, v14, "epping_tx_complete");
      v19 = 0;
    }
    qdf_trace_msg(
      0x33u,
      4u,
      "%s skb=%pK data=%pK len=0x%x eid=%d ",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "epping_tx_complete",
      v17,
      *(_QWORD *)(a2 + 32),
      *(unsigned int *)(a2 + 44),
      v15);
    if ( v16 )
    {
      if ( v16 != 1 )
      {
        v28 = v16 == 9;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s() -TX ERROR, status: 0x%x",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "epping_tx_complete",
          v16);
        goto LABEL_23;
      }
LABEL_22:
      v28 = 0;
LABEL_23:
      epping_free_cookie(*v2, v18);
      v31 = v2[5];
      if ( (v31 & 1) != 0 )
      {
        v2[5] = v31 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v2 + 4);
        if ( v19 )
        {
LABEL_25:
          if ( v17 )
          {
            *(_QWORD *)v17 = 0;
            result = _qdf_nbuf_free(v17);
            ++*(_DWORD *)(v4 + 116);
          }
        }
      }
      else
      {
        result = raw_spin_unlock(v2 + 4);
        if ( v19 )
          goto LABEL_25;
      }
      if ( !v28 )
        return netif_tx_wake_queue(*(_QWORD *)(v5 + 24));
      return result;
    }
LABEL_21:
    qdf_trace_msg(0x33u, 4u, "%s: OK\n", v20, v21, v22, v23, v24, v25, v26, v27, "epping_tx_complete");
    goto LABEL_22;
  }
  return result;
}
