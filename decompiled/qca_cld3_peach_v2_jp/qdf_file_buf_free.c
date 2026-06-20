__int64 __fastcall qdf_file_buf_free(__int64 result)
{
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
