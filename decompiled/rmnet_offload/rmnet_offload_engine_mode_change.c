__int64 __fastcall rmnet_offload_engine_mode_change(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned int v3; // w20
  __int64 *k; // x19
  __int64 v5; // x21
  __int64 *j; // x19
  __int64 v7; // x21
  __int64 *i; // x19
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = v10;
  v10[1] = v10;
  if ( a1 != 3 && a2 )
  {
    switch ( a2 )
    {
      case 1LL:
        v7 = 0;
        v3 = 0;
        do
        {
          for ( i = (__int64 *)rmnet_offload_flow_table[v7]; i; i = (__int64 *)*i )
          {
            if ( *((_BYTE *)i + 98) && *((_BYTE *)i + 81) == 17 )
            {
              ++v3;
              rmnet_offload_engine_flush_flow(i, v10);
            }
          }
          ++v7;
        }
        while ( v7 != 32 );
        break;
      case 2LL:
        v5 = 0;
        v3 = 0;
        do
        {
          for ( j = (__int64 *)rmnet_offload_flow_table[v5]; j; j = (__int64 *)*j )
          {
            if ( *((_BYTE *)j + 98) && *((_BYTE *)j + 81) == 6 )
            {
              ++v3;
              rmnet_offload_engine_flush_flow(j, v10);
            }
          }
          ++v5;
        }
        while ( v5 != 32 );
        break;
      case 3LL:
        v2 = 0;
        v3 = 0;
        do
        {
          for ( k = (__int64 *)rmnet_offload_flow_table[v2]; k; k = (__int64 *)*k )
          {
            if ( *((_BYTE *)k + 98) )
            {
              ++v3;
              rmnet_offload_engine_flush_flow(k, v10);
            }
          }
          ++v2;
        }
        while ( v2 != 32 );
        break;
      default:
        v3 = 0;
        break;
    }
    _rmnet_offload_stats_update(11, v3);
    rmnet_offload_deliver_descs(v10);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
