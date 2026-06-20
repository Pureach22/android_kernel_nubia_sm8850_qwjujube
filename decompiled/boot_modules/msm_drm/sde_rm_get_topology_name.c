__int64 __fastcall sde_rm_get_topology_name(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x12

  v3 = *(_QWORD *)(a1 + 328);
  v4 = 0;
  v5 = v3 + 12;
  do
  {
    if ( *(_QWORD *)(v5 + v4 - 8) == a2 && __PAIR64__(*(_DWORD *)(v5 + v4 + 12), *(_DWORD *)(v5 + v4)) == a3 )
      return *(unsigned int *)(v3 + v4);
    v4 += 28;
  }
  while ( v4 != 476 );
  return 0;
}
