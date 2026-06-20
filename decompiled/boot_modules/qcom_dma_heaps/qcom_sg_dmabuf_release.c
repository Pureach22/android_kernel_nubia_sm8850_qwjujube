unsigned int *__fastcall qcom_sg_dmabuf_release(__int64 a1)
{
  __int64 v1; // x19
  unsigned int *result; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8
  int v9; // w8

  v1 = *(_QWORD *)(a1 + 112);
  mem_buf_vmperm_try_reclaim(*(_QWORD *)(v1 + 120), 0);
  msm_dma_buf_freed(v1);
  result = (unsigned int *)(v1 + 168);
  __asm { PRFM            #0x11, [X0] }
  do
    v9 = __ldxr(result);
  while ( __stlxr(v9 - 1, result) );
  if ( v9 == 1 )
  {
    __dmb(9u);
    result = (unsigned int *)mem_buf_vmperm_free(*(_QWORD *)(v1 + 120));
    v3 = *(__int64 (__fastcall **)(_QWORD))(v1 + 160);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != 1054465814 )
        __break(0x8228u);
      return (unsigned int *)v3(v1);
    }
  }
  else if ( v9 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate();
  }
  return result;
}
