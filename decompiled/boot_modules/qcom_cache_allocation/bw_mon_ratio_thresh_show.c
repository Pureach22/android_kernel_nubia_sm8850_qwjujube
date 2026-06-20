__int64 __fastcall bw_mon_ratio_thresh_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  int v7; // w25
  int v8; // w25

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(int *)(v3 + 56) < 1 )
  {
    v7 = 0;
  }
  else
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = scnprintf(a3 + v7, 4096LL - v7, "%llu ", *(_QWORD *)(*(_QWORD *)(v3 + 16) + v5 + 24)) + v7;
      ++v6;
      v7 = scnprintf(a3 + v8, 4096LL - v8, "%llu ", *(_QWORD *)(*(_QWORD *)(v3 + 16) + v5 + 32)) + v8;
      v5 += 40;
    }
    while ( v6 < *(int *)(v3 + 56) );
  }
  return (int)(scnprintf(a3 + v7, 4096LL - v7, "\n") + v7);
}
