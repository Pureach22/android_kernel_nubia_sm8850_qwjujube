__int64 __fastcall sde_vm_populate_irq(_QWORD **a1)
{
  unsigned int v2; // w21
  _QWORD *v3; // x8
  __int64 v4; // x20
  __int64 v5; // x0
  _QWORD *v6; // x8
  unsigned int v7; // w9
  _DWORD *v8; // x10

  v2 = -1;
  v3 = a1;
  do
  {
    v3 = (_QWORD *)*v3;
    ++v2;
  }
  while ( v3 != a1 );
  v4 = _kmalloc_cache_noprof(kthread_create_on_node, 3520, 16);
  if ( !v4 )
    return 12;
  v5 = _kmalloc_noprof(8LL * v2, 3520);
  *(_QWORD *)(v4 + 8) = v5;
  if ( !v5 )
  {
    kfree(v4);
    return 12;
  }
  v6 = *a1;
  if ( *a1 != a1 )
  {
    v7 = 0;
    do
    {
      v8 = (_DWORD *)(*(_QWORD *)(v4 + 8) + 8LL * v7++);
      v8[1] = *((_DWORD *)v6 - 1);
      *v8 = *((_DWORD *)v6 - 2);
      v6 = (_QWORD *)*v6;
    }
    while ( v6 != a1 );
  }
  *(_DWORD *)v4 = v2;
  msm_dss_clean_io_irq(a1);
  return v4;
}
