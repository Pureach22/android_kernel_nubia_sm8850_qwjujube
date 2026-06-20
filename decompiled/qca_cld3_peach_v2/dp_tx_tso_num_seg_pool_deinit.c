__int64 __fastcall dp_tx_tso_num_seg_pool_deinit(__int64 result, unsigned __int8 a2)
{
  int v2; // w21
  __int64 v3; // x19
  int v4; // w20

  v2 = a2;
  if ( a2 )
  {
    v3 = result;
    v4 = 0;
    do
      result = dp_tx_tso_num_seg_pool_deinit_by_id(v3, v4++);
    while ( v2 != v4 );
  }
  return result;
}
