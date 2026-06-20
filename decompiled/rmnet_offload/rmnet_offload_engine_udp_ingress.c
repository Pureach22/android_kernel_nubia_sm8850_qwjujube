__int64 __fastcall rmnet_offload_engine_udp_ingress(__int64 a1, unsigned __int16 *a2, char a3, __int64 **a4)
{
  int v7; // w8
  __int64 v8; // x0

  if ( (a3 & 1) == 0 )
  {
    if ( *(_BYTE *)(a1 + 98) )
    {
      v7 = *(unsigned __int16 *)(*(_QWORD *)a2 + 70LL);
      if ( !*(_WORD *)(*(_QWORD *)a2 + 70LL) )
        v7 = a2[32];
      if ( v7 == *(unsigned __int16 *)(a1 + 96) )
      {
        if ( *(unsigned __int16 *)(a1 + 88) + (unsigned __int64)a2[32] < rmnet_offload_knob_get(1u) )
        {
          *((_BYTE *)a2 + 66) = 0;
          goto LABEL_12;
        }
        v8 = 20;
      }
      else
      {
        v8 = 19;
      }
      rmnet_offload_stats_update(v8);
      rmnet_offload_engine_flush_flow(a1, a4);
    }
LABEL_12:
    rmnet_offload_engine_add_flow_pkt(a1, (__int64)a2);
    return 1;
  }
  rmnet_offload_stats_update(18);
  rmnet_offload_engine_flush_flow(a1, a4);
  rmnet_offload_flush_current_pkt((__int64)a2, (__int64)a4);
  return 1;
}
