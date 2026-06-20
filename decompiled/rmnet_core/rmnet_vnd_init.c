__int64 __fastcall rmnet_vnd_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  unsigned int v5; // w19

  v2 = pcpu_alloc_noprof(40, 8, 0, 3264);
  *(_QWORD *)(a1 + 2704) = v2;
  if ( !v2 )
    return 4294967284LL;
  result = gro_cells_init(a1 + 2712, a1);
  if ( (_DWORD)result )
  {
    v4 = *(_QWORD *)(a1 + 2704);
    v5 = result;
    free_percpu(v4);
    return v5;
  }
  return result;
}
