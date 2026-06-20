_QWORD *__fastcall dp_txrx_clear_tso_stats(_QWORD *result)
{
  unsigned int v1; // w8
  __int64 v2; // x20
  _QWORD *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2

  v1 = *((unsigned __int8 *)result + 1120);
  if ( *((_BYTE *)result + 1120) )
  {
    v2 = result[9];
    v3 = result;
    if ( v2 )
    {
      result = qdf_mem_set((void *)(v2 + 92216), 0x7C8u, 0);
      *(_DWORD *)(v2 + 96336) = 0;
      v1 = *((unsigned __int8 *)v3 + 1120);
    }
    if ( v1 > 1 )
    {
      __break(0x5512u);
      v4 = MEMORY[0x2B6CDEC]();
      return (_QWORD *)dp_txrx_get_peer_per_pkt_stats_param(v4, v5, v6);
    }
  }
  return result;
}
