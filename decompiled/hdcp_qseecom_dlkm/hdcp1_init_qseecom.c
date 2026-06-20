__int64 hdcp1_init_qseecom()
{
  __int64 result; // x0

  result = _kmalloc_cache_noprof(kfree_sensitive, 3520, 48);
  if ( result )
    *(_QWORD *)(result + 32) = "hdcp1";
  return result;
}
