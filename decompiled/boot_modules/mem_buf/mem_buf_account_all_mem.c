__int64 mem_buf_account_all_mem()
{
  _UNKNOWN **v0; // x9
  __int64 v1; // x19
  __int64 v2; // x10

  mutex_lock(&mem_buf_xfer_mem_list_lock);
  v0 = (_UNKNOWN **)mem_buf_xfer_mem_list;
  if ( mem_buf_xfer_mem_list == (_UNKNOWN *)&mem_buf_xfer_mem_list )
  {
    v1 = 0;
  }
  else
  {
    v1 = 0;
    do
    {
      v2 = (__int64)*(v0 - 6);
      v0 = (_UNKNOWN **)*v0;
      v1 += v2;
    }
    while ( v0 != &mem_buf_xfer_mem_list );
  }
  mutex_unlock(&mem_buf_xfer_mem_list_lock);
  return v1;
}
