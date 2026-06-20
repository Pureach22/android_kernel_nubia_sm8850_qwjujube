__int64 __fastcall dp_rx_update_stats(__int64 result, __int64 a2)
{
  __int64 v2; // x9

  if ( result )
  {
    v2 = *(_QWORD *)(result + 13648);
    ++*(_QWORD *)(result + 13640);
    *(_QWORD *)(result + 13648) = v2 + *(unsigned __int16 *)(a2 + 60);
  }
  return result;
}
