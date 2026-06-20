__int64 __fastcall qcom_sg_dma_buf_begin_cpu_access_partial(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  __int64 v4; // x22
  __int64 *v9; // x24
  unsigned int v10; // w0
  unsigned int v11; // w19

  v4 = *(_QWORD *)(a1 + 112);
  if ( (*(_BYTE *)(v4 + 112) & 1) != 0 )
    return 0;
  mutex_lock(v4 + 24);
  if ( (mem_buf_vmperm_can_cmo(*(_QWORD *)(v4 + 120)) & 1) == 0
    || (v9 = *(__int64 **)(v4 + 8), v9 == (__int64 *)(v4 + 8)) )
  {
    v10 = 0;
  }
  else
  {
    v10 = 0;
    do
    {
      if ( *((_BYTE *)v9 + 16) == 1 )
        v10 = sgl_sync_range(*(v9 - 2), *(_QWORD *)*(v9 - 1), *(unsigned int *)(*(v9 - 1) + 12), a3, a4, a2, 1);
      v9 = (__int64 *)*v9;
    }
    while ( v9 != (__int64 *)(v4 + 8) );
  }
  v11 = v10;
  mutex_unlock(v4 + 24);
  return v11;
}
