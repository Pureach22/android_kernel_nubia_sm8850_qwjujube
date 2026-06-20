__int64 __fastcall dp_rx_buffer_pool_nbuf_map(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x1

  v4 = *(_QWORD *)(a3 + 8);
  if ( *(_QWORD *)(v4 + 40) )
    return 0;
  else
    return qdf_nbuf_map_nbytes_single_0(*(_QWORD *)(a1 + 24), v4, *(unsigned __int16 *)(a2 + 74));
}
