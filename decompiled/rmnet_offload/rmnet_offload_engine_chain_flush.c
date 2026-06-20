__int64 rmnet_offload_engine_chain_flush()
{
  __int64 v0; // x0
  __int64 v1; // x21
  int v2; // w20
  __int64 i; // x19
  __int64 result; // x0
  __int64 *v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = (__int64 *)v5;
  v5[1] = (__int64 *)v5;
  v0 = rmnet_offload_lock();
  v1 = 0;
  v2 = 0;
  do
  {
    for ( i = rmnet_offload_flow_table[v1]; i; i = *(_QWORD *)i )
    {
      if ( *(_BYTE *)(i + 98) )
      {
        ++v2;
        v0 = rmnet_offload_engine_flush_flow(i, v5);
      }
    }
    ++v1;
  }
  while ( v1 != 32 );
  if ( v2 )
    v0 = rmnet_offload_stats_update(9);
  rmnet_offload_unlock(v0);
  result = rmnet_offload_deliver_descs(v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
