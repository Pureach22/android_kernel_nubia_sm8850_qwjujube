__int64 __fastcall ost_t_output_open(int *a1, __int64 a2)
{
  _DWORD *v4; // x0
  int v5; // w9
  unsigned int v6; // w8

  v4 = (_DWORD *)_kmalloc_cache_noprof(to_pdrv_policy_node, 2336, 4);
  if ( v4 )
  {
    v5 = *a1;
    v6 = 0;
    *(_QWORD *)(a2 + 16) = v4;
    *v4 = v5;
  }
  else
  {
    return (unsigned int)-12;
  }
  return v6;
}
