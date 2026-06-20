__int64 __fastcall dp_rx_flush_packet_cbk(__int64 a1, unsigned int a2)
{
  _QWORD *v2; // x21
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x20
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x0
  unsigned int v24; // w9
  unsigned int v27; // w10

  v2 = *(_QWORD **)(a1 + 32);
  context = _cds_get_context(71, "dp_rx_flush_packet_cbk");
  if ( !context )
    return 16;
  v13 = *v2;
  if ( !*v2 )
    return 16;
  v14 = context;
  _X8 = (unsigned int *)(v2 + 447);
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stxr(v24 + 1, _X8) );
  if ( *(_BYTE *)(v13 + 218) == 1 )
    dp_rx_fisa_flush_by_vdev_id(context, a2);
  if ( *(_BYTE *)(v13 + 371) == 1 )
  {
    if ( *(_QWORD *)v14 )
    {
      v15 = *(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)v14 + 624LL);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != -1355198606 )
          __break(0x8228u);
        v16 = v15(v14);
        if ( v16 )
          dp_rx_tm_flush_by_vdev_id(v16 + 16, a2);
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_soc_get_dp_txrx_handle");
    }
  }
  _X8 = (unsigned int *)(v2 + 447);
  __asm { PRFM            #0x11, [X8] }
  do
    v27 = __ldxr(_X8);
  while ( __stxr(v27 - 1, _X8) );
  return 0;
}
