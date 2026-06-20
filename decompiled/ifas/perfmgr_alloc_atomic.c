void *__fastcall perfmgr_alloc_atomic(int i32Size)
{
  __int64 v1; // x1

  if ( (unsigned int)i32Size > 0x1000 )
    v1 = 3264;
  else
    v1 = 2080;
  return _kmalloc_noprof(i32Size, v1);
}
