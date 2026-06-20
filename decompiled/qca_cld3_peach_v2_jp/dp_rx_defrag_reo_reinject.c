__int64 __fastcall dp_rx_defrag_reo_reinject(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x22
  unsigned int v7; // w19
  __int64 v10; // x23
  _QWORD *v11; // x24
  __int64 v12; // x8
  __int64 v13; // x1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( (unsigned int)a2 >= 0x11 )
  {
    __break(0x5512u);
    return dp_rx_frag_handle(a1, a2, a3, a4, a5, a6);
  }
  else
  {
    v6 = *(_QWORD *)a1;
    v7 = a2;
    v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 8LL);
    v11 = *(_QWORD **)(a1 + 120LL * (unsigned int)a2 + 224);
    *(_WORD *)(a3 + 86) = *(_WORD *)(a3 + 86) & 0xF000 | *(unsigned __int8 *)(*(_QWORD *)a1 + 59LL) | ((a2 & 0xF) << 8);
    v12 = *(_QWORD *)(a3 + 40);
    v13 = *(unsigned __int16 *)(v10 + 1138);
    if ( v12 )
      *(_QWORD *)(a3 + 40) = v12 + v13;
    skb_pull(a3, v13);
    *(_BYTE *)(a3 + 75) = 1;
    *(_QWORD *)a3 = 0;
    dp_rx_deliver_to_stack(v10, v6, a1, a3, a3);
    *v11 = 0;
    v11[1] = 0;
    return dp_rx_return_head_frag_desc(a1, v7, v14, v15, v16, v17, v18, v19, v20, v21);
  }
}
