__int64 __fastcall tz_log_remove(__int64 a1)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a1 + 168) )
    remove_proc_subtree("tzdbg", 0);
  dma_free_attrs(a1 + 16, (unsigned int)display_buf_size, qword_130, disp_buf_paddr, 0);
  qtee_shmbridge_deregister(qword_ABF0);
  dma_free_attrs(a1 + 16, qword_ABE8, qword_ABE0, enc_tzlog_info, 0);
  qtee_shmbridge_deregister(qword_ABD0);
  dma_free_attrs(a1 + 16, qword_ABC8, qword_ABC0, enc_qseelog_info, 0);
  if ( (byte_330 & 1) == 0 )
    qtee_shmbridge_deregister(qseelog_shmbridge_handle);
  result = dma_free_attrs(a1 + 16, (unsigned int)qseelog_buf_size, g_qsee_log, coh_pmem, 0);
  if ( (byte_330 & 1) == 0 )
    return kfree(qword_110);
  return result;
}
