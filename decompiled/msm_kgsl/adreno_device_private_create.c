__int64 adreno_device_private_create()
{
  __int64 result; // x0

  result = _kmalloc_cache_noprof(idr_find, 3520, 32);
  if ( result )
  {
    *(_QWORD *)(result + 16) = result + 16;
    *(_QWORD *)(result + 24) = result + 16;
  }
  return result;
}
