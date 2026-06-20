__int64 __fastcall dp_get_total_per(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x9

  if ( a2 )
    return 0;
  v2 = *(_QWORD *)(a1 + 72);
  if ( v2
    && (dp_aggregate_pdev_stats(*(_QWORD **)(a1 + 72)),
        v3 = *(unsigned int *)(v2 + 3108),
        (v4 = *(_QWORD *)(v2 + 3072) + v3) != 0) )
  {
    return 100 * (int)v3 / (unsigned int)v4;
  }
  else
  {
    return 0;
  }
}
