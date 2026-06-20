_QWORD *__fastcall qtee_shmbridge_flush_shm_buf(_QWORD *result)
{
  if ( result )
  {
    if ( (*(_BYTE *)(qword_13988 + 844) & 0x40) == 0 )
      return (_QWORD *)_dma_sync_single_for_device(qword_13988, *result, result[2], 1);
  }
  return result;
}
