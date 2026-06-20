__int64 __fastcall dp_sim_update_port_edid(__int64 a1, unsigned int a2, const void *a3, unsigned int a4)
{
  __int64 v9; // x23
  unsigned int v10; // w8
  size_t v11; // x21
  unsigned int v12; // w20
  __int64 v13; // x0

  if ( !a1 )
    return 4294967274LL;
  if ( (*(_DWORD *)(a1 + 16) & 0x80000000) == 0 )
    return 4294967274LL;
  mutex_lock(a1 + 80);
  if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(a1 + 2252) <= a2 )
  {
    v12 = -22;
  }
  else
  {
    v9 = *(_QWORD *)(a1 + 2240) + 48LL * a2;
    v10 = a4;
    if ( *(_DWORD *)(v9 + 40) == a4 )
    {
      v11 = a4;
    }
    else
    {
      if ( *(_QWORD *)(v9 + 32) )
      {
        devm_kfree(*(_QWORD *)(a1 - 8));
        v10 = a4;
      }
      v11 = v10;
      v13 = devm_kmalloc(*(_QWORD *)(a1 - 8), v10, 3520);
      *(_QWORD *)(v9 + 32) = v13;
      if ( !v13 )
        return 4294967284LL;
      *(_DWORD *)(v9 + 40) = a4;
    }
    memcpy(*(void **)(v9 + 32), a3, v11);
    v12 = dp_mst_sim_update(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 2252), *(_QWORD *)(a1 + 2240));
  }
  mutex_unlock(a1 + 80);
  return v12;
}
