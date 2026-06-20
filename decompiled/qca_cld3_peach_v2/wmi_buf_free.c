__int64 wmi_buf_free()
{
  __int64 result; // x0

  result = wbuff_buff_put();
  if ( result )
    return _qdf_nbuf_free(result);
  return result;
}
