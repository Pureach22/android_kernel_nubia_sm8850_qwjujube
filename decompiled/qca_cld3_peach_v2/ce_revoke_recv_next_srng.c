__int64 __fastcall ce_revoke_recv_next_srng(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x10

  v3 = *(_QWORD *)(a1 + 144);
  if ( !v3 )
    return 16;
  v4 = *(unsigned int *)(v3 + 8);
  if ( a2 )
    *a2 = *(_QWORD *)(a1 + 96);
  if ( a3 )
    *a3 = *(_QWORD *)(*(_QWORD *)(v3 + 88) + 8 * v4);
  v5 = *(_QWORD *)(v3 + 88);
  if ( !*(_QWORD *)(v5 + 8 * v4) )
    return 16;
  *(_QWORD *)(v5 + 8 * v4) = 0;
  *(_DWORD *)(v3 + 8) = *(_DWORD *)(v3 + 4) & (v4 + 1);
  return 0;
}
