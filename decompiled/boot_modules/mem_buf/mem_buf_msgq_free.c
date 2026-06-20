__int64 mem_buf_msgq_free()
{
  __int64 v0; // x21
  __int64 result; // x0

  if ( (mem_buf_capability & 3) != 0 )
  {
    mutex_lock(&mem_buf_list_lock);
    if ( mem_buf_list != (_UNKNOWN *)&mem_buf_list )
      dev_err(mem_buf_dev, "Removing mem-buf driver while there are membufs\n");
    mutex_unlock(&mem_buf_list_lock);
    mutex_lock(&mem_buf_xfer_mem_list_lock);
    if ( mem_buf_xfer_mem_list != (_UNKNOWN *)&mem_buf_xfer_mem_list )
      dev_err(mem_buf_dev, "Removing mem-buf driver while memory is still lent\n");
    mutex_unlock(&mem_buf_xfer_mem_list_lock);
    if ( num_msgqs >= 1 )
    {
      v0 = 0;
      do
        mem_buf_msgq_unregister(*(_QWORD *)(msgqs + 8 * v0++));
      while ( v0 < num_msgqs );
    }
    kfree(msgqs);
    num_msgqs = 0;
    msgqs = 0;
    result = destroy_workqueue(mem_buf_wq);
    mem_buf_wq = 0;
  }
  return result;
}
