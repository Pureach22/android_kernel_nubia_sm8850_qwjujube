__int64 __fastcall rmnet_mem_get_pool_size(unsigned int a1)
{
  __int64 result; // x0

  if ( a1 < 4 )
  {
    result = *((unsigned int *)&static_pool_size + a1);
    if ( !(_DWORD)result )
      return *((unsigned int *)&target_pool_size + a1);
  }
  else
  {
    ++qword_8BE8;
    return 0;
  }
  return result;
}
