__int64 __fastcall commit_epss_l3_percpu(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x8
  __int64 v5; // x9
  __int64 v6; // x0

  v2 = *(_QWORD *)(a1 + 16);
  v5 = *(unsigned int *)(v2 + 120);
  if ( (_DWORD)v5 )
  {
    v6 = 0;
    while ( *a2 > *(_DWORD *)(*(_QWORD *)(v2 + 112) + 4 * v6) )
    {
      if ( v5 == ++v6 )
      {
        v6 = (unsigned int)v5;
        break;
      }
    }
  }
  else
  {
    v6 = 0;
  }
  if ( *(_DWORD *)(v2 + 104) == 2 )
    writel_relaxed(
      v6,
      **(_QWORD **)(a1 + 120)
    + *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 120) + 16LL) + 4LL * *(int *)(_ReadStatusReg(SP_EL0) + 40)));
  *(_DWORD *)(a1 + 24) = *a2;
  return 0;
}
