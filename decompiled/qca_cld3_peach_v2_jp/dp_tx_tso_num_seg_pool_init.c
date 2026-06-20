__int64 __fastcall dp_tx_tso_num_seg_pool_init(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 v5; // x22
  unsigned int v6; // w19
  __int64 v7; // x23
  __int64 v8; // x24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 v18; // x9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( !a2 )
    return 0;
  v5 = 0;
  v6 = 0;
  v7 = 72LL * a2;
  v8 = a1 + 5296;
  while ( 1 )
  {
    if ( v5 == 504 )
    {
      __break(0x5512u);
      JUMPOUT(0x59DCDB8);
    }
    if ( (unsigned int)qdf_mem_multi_page_link(*(_QWORD *)(a1 + 24), (unsigned __int16 *)(v8 + v5), 0x10u, a3, 1) )
      break;
    v17 = a1 + v5;
    v5 += 72;
    ++v6;
    v18 = **(_QWORD **)(v17 + 5312);
    *(_WORD *)(v17 + 5282) = a3;
    *(_WORD *)(v17 + 5280) = a3;
    *(_DWORD *)(v17 + 5336) = 0;
    *(_QWORD *)(v17 + 5288) = v18;
    *(_QWORD *)(v17 + 5344) = 0;
    if ( v7 == v5 )
      return 0;
  }
  qdf_trace_msg(0x45u, 2u, "invalid tso desc allocation - overflow num link", v9, v10, v11, v12, v13, v14, v15, v16);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: failed to initialise TSO num seg pool %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "dp_tx_tso_num_seg_pool_init",
    v6);
  return 5;
}
