__int64 __fastcall dp_deinit_tx_pair_by_index(__int64 a1, unsigned int a2)
{
  unsigned __int8 *v4; // x8
  unsigned int v5; // w21
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x1
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x24
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x4
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x21
  __int64 v45; // x4
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  v4 = (unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 776LL) + 4LL * a2);
  v5 = *v4;
  v6 = v4[1];
  dp_ssr_dump_srng_unregister("tcl_data_ring", a2);
  v7 = dp_ssr_dump_srng_unregister("tx_comp_ring", a2);
  if ( a2 >= 5 )
  {
    __break(0x5512u);
    return dp_init_tx_ring_pair_by_index(v7, v8);
  }
  else
  {
    v17 = a1 + 80LL * a2;
    wlan_minidump_remove(
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      *(_QWORD *)(v17 + 6808),
      *(unsigned int *)(v17 + 6840),
      *(_QWORD *)(a1 + 16));
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: index %u tcl %u wbm %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dp_deinit_tx_pair_by_index",
      a2,
      v5,
      v6);
    result = dp_srng_deinit(a1, (__int64 *)(v17 + 6800), 5u, v5, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( v6 != 15 )
    {
      v44 = a1 + 80LL * a2;
      wlan_minidump_remove(
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        *(_QWORD *)(v44 + 7376),
        *(unsigned int *)(v44 + 7408),
        *(_QWORD *)(a1 + 16));
      return dp_srng_deinit(a1, (__int64 *)(v44 + 7368), 0xDu, v6, v45, v46, v47, v48, v49, v50, v51, v52, v53);
    }
  }
  return result;
}
