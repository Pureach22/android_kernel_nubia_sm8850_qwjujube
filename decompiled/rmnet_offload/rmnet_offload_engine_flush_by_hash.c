__int64 __fastcall rmnet_offload_engine_flush_by_hash(__int64 result, __int64 **a2)
{
  __int64 v2; // x20
  int v3; // w19

  v2 = rmnet_offload_flow_table[(unsigned int)(1640531527 * result) >> 27];
  if ( v2 )
  {
    v3 = result;
    do
    {
      if ( *(_DWORD *)(v2 + 84) == v3 )
      {
        if ( *(_BYTE *)(v2 + 98) )
          result = rmnet_offload_engine_flush_flow(v2, a2);
      }
      v2 = *(_QWORD *)v2;
    }
    while ( v2 );
  }
  return result;
}
