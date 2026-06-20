__int64 __fastcall hdd_disable_and_flush_mc_addr_list(__int64 a1, unsigned int a2)
{
  _QWORD *v2; // x20
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v2 = *(_QWORD **)(a1 + 24);
  v4 = ucfg_pmo_disable_mc_addr_filtering_in_fwr(*v2, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), a2);
  if ( v4 )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: failed to disable mc list; status:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_disable_and_flush_mc_addr_list",
      v4);
  result = ucfg_pmo_flush_mc_addr_list(*v2, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL));
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: failed to flush mc list; status:%d",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "hdd_disable_and_flush_mc_addr_list",
             (unsigned int)result);
  return result;
}
