__int64 __fastcall dp_init_tx_ring_pair_by_index(
        __int64 *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w21
  const char *v11; // x2
  unsigned int v13; // w24
  unsigned __int8 *v14; // x8
  __int64 v15; // x20
  int v16; // w22
  __int64 v17; // x23
  __int64 v19; // x24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x9
  __int64 v29; // x2

  v10 = a2;
  if ( a2 >= 5u )
  {
    v11 = "%s: unexpected index!";
LABEL_5:
    qdf_trace_msg(0x45u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "dp_init_tx_ring_pair_by_index");
    return 16;
  }
  v13 = a2;
  v14 = (unsigned __int8 *)(*(_QWORD *)(a1[5] + 776) + 4LL * a2);
  v15 = *v14;
  v16 = v14[1];
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: index %u tcl %u wbm %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_init_tx_ring_pair_by_index",
    a2,
    v15,
    v14[1]);
  v17 = (__int64)&a1[10 * v13 + 850];
  if ( (unsigned int)dp_srng_init((__int64)a1) )
  {
    v11 = "%s: dp_srng_init failed for tcl_data_ring";
    goto LABEL_5;
  }
  wlan_minidump_log(a3, a4, a5, a6, a7, a8, a9, a10, a1[10 * v13 + 851], LODWORD(a1[10 * v13 + 855]), a1[2]);
  if ( v16 != 15 )
  {
    v19 = (__int64)&a1[10 * v13 + 921];
    if ( (unsigned int)dp_srng_init((__int64)a1) )
    {
      v11 = "%s: dp_srng_init failed for tx_comp_ring";
      goto LABEL_5;
    }
    dp_ssr_dump_srng_register("tcl_data_ring", v17, v10);
    dp_ssr_dump_srng_register("tx_comp_ring", v19, v10);
    wlan_minidump_log(v20, v21, v22, v23, v24, v25, v26, v27, *(_QWORD *)(v19 + 8), *(unsigned int *)(v19 + 40), a1[2]);
  }
  v28 = (_DWORD *)a1[178];
  v29 = *(unsigned __int8 *)(*(_QWORD *)(a1[5] + 776) + 4 * v15 + 2);
  if ( *(v28 - 1) != -1169284475 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64 *, _QWORD, __int64))v28)(a1, (unsigned int)v15, v29);
  return 0;
}
