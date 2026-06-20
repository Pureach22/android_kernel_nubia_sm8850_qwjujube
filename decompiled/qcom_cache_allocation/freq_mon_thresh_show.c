__int64 __fastcall freq_mon_thresh_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v5; // x23
  __int64 v6; // x24
  int v7; // w22
  int v8; // w22
  int v9; // w22
  __int64 v10; // x23
  __int64 v11; // x24
  int v12; // w22

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
      v8 = scnprintf(a3 + v7, 4096LL - v7, "%d ", *(_DWORD *)(*(_QWORD *)(v3 + 16) + v5 + 4)) + v7;
      ++v6;
      v7 = scnprintf(a3 + v8, 4096LL - v8, "%d ", *(_DWORD *)(*(_QWORD *)(v3 + 16) + v5 + 8)) + v8;
      v5 += 40;
    }
    while ( v6 < *(int *)(v3 + 56) );
  }
  v9 = scnprintf(a3 + v7, 4096LL - v7, "%d\n", *(_DWORD *)(*(_QWORD *)(v3 + 16) + 20LL)) + v7;
  if ( *(int *)(v3 + 56) >= 1 )
  {
    v10 = 0;
    v11 = 0;
    do
    {
      v12 = scnprintf(a3 + v9, 4096LL - v9, "%d ", *(_DWORD *)(*(_QWORD *)(v3 + 16) + v10 + 12)) + v9;
      ++v11;
      v9 = scnprintf(a3 + v12, 4096LL - v12, "%d ", *(_DWORD *)(*(_QWORD *)(v3 + 16) + v10 + 16)) + v12;
      v10 += 40;
    }
    while ( v11 < *(int *)(v3 + 56) );
  }
  return (int)(scnprintf(a3 + v9, 4096LL - v9, "%d\n", *(_DWORD *)(*(_QWORD *)(v3 + 16) + 60LL)) + v9);
}
