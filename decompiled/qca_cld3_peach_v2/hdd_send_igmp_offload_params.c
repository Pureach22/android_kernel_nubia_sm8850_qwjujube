__int64 __fastcall hdd_send_igmp_offload_params(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v15; // x0
  __int64 v16; // x19
  unsigned __int64 v17; // x8
  int v18; // w13
  const char *v19; // x2
  unsigned int v20; // w1
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 968LL);
  if ( !v11 )
  {
LABEL_13:
    v19 = "%s: in_dev is NULL";
    v20 = 2;
LABEL_18:
    qdf_trace_msg(0x33u, v20, v19, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_send_igmp_offload_params");
    return 16;
  }
  v12 = *(_QWORD *)(v11 + 24);
  if ( !v12 )
  {
    v19 = "%s: ip list empty";
    v20 = 8;
    goto LABEL_18;
  }
  v15 = _qdf_mem_malloc(0x38u, "hdd_send_igmp_offload_params", 226);
  if ( !v15 )
    return 16;
  v16 = v15;
  v17 = 0;
  do
  {
    v18 = *(_DWORD *)(v12 + 8);
    if ( !v18 || (a3 & 1) == 0 || (int)v17 > 9 )
      break;
    if ( v18 != 16777440 )
    {
      if ( v17 >= 0xA )
      {
        __break(0x5512u);
        goto LABEL_13;
      }
      *(_DWORD *)(v15 + 16 + 4 * v17++) = v18;
    }
    v12 = *(_QWORD *)(v12 + 48);
  }
  while ( v12 );
  *(_BYTE *)(v15 + 4) = a3 & 1;
  *(_DWORD *)(v15 + 12) = v17;
  v21 = ucfg_pmo_enable_igmp_offload(a2, v15);
  if ( v21 )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to configure igmp offload",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hdd_send_igmp_offload_params");
  _qdf_mem_free(v16);
  return v21;
}
