__int64 memshare_init_worker()
{
  __int64 result; // x0

  result = _kmalloc_cache_noprof(mutex_unlock, 3520, 304);
  mem_share_svc_handle = result;
  if ( result )
  {
    if ( (qmi_handle_init(result, 32, &server_ops, &qmi_memshare_handlers) & 0x80000000) != 0 )
    {
      dev_err(*(_QWORD *)memsh_drv, "memshare: Creating mem_share_svc qmi handle failed\n");
LABEL_8:
      result = kfree(mem_share_svc_handle);
      mem_share_svc_handle = 0;
      return result;
    }
    result = qmi_add_server(mem_share_svc_handle, 52, 1, 1);
    if ( (result & 0x80000000) != 0 )
    {
      dev_err(*(_QWORD *)memsh_drv, "memshare: Registering mem share svc failed %d\n", result);
      result = mem_share_svc_handle;
      if ( mem_share_svc_handle )
      {
        qmi_handle_release();
        goto LABEL_8;
      }
    }
  }
  return result;
}
