__int64 __fastcall rmnet_offload_engine_flush_all_flows(__int64 a1)
{
  __int64 v2; // x22
  unsigned int v3; // w20
  __int64 *i; // x21

  v2 = 0;
  v3 = 0;
  do
  {
    for ( i = (__int64 *)rmnet_offload_flow_table[v2]; i; i = (__int64 *)*i )
    {
      if ( *((_BYTE *)i + 98) )
      {
        ++v3;
        rmnet_offload_engine_flush_flow(i, a1);
      }
    }
    ++v2;
  }
  while ( v2 != 32 );
  return v3;
}
