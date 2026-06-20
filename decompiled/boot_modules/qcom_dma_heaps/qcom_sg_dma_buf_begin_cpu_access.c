__int64 __fastcall qcom_sg_dma_buf_begin_cpu_access(__int64 a1)
{
  __int64 v1; // x20
  __int64 *i; // x22

  v1 = *(_QWORD *)(a1 + 112);
  if ( (*(_BYTE *)(v1 + 112) & 1) == 0 )
  {
    mutex_lock(v1 + 24);
    if ( (mem_buf_vmperm_can_cmo(*(_QWORD *)(v1 + 120)) & 1) != 0 )
    {
      for ( i = *(__int64 **)(v1 + 8); i != (__int64 *)(v1 + 8); i = (__int64 *)*i )
      {
        if ( *((_BYTE *)i + 16) == 1 && (*(_BYTE *)(*(i - 2) + 844) & 0x40) == 0 )
          _dma_sync_sg_for_cpu();
      }
    }
    mutex_unlock(v1 + 24);
  }
  return 0;
}
