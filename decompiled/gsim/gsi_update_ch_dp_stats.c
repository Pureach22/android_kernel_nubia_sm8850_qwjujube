__int64 __fastcall gsi_update_ch_dp_stats(__int64 a1, unsigned __int16 a2)
{
  unsigned int v3; // w20
  __int64 result; // x0
  unsigned __int64 v5; // x9
  __int64 v6; // x9

  v3 = a2;
  result = jiffies_to_msecs(jiffies);
  if ( !v3 )
  {
    v5 = (unsigned int)result - *(_QWORD *)(a1 + 432);
    if ( *(_QWORD *)(a1 + 424) < v5 )
      *(_QWORD *)(a1 + 424) = v5;
  }
  if ( *(unsigned __int16 *)(a1 + 32) / 3 >= v3 )
  {
    v6 = 400;
  }
  else
  {
    v6 = 408;
    if ( (1431655766 * (unsigned __int64)(2 * (unsigned int)*(unsigned __int16 *)(a1 + 32))) >> 32 < v3 )
      v6 = 416;
  }
  ++*(_QWORD *)(a1 + v6);
  *(_QWORD *)(a1 + 432) = (unsigned int)result;
  return result;
}
