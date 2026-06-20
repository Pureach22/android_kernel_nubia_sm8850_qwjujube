unsigned __int64 __fastcall qtee_shmbridge_free_shm(unsigned __int64 result)
{
  __int64 v1; // x1

  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    v1 = *(_QWORD *)(result + 8);
    if ( v1 )
      return gen_pool_free_owner(qword_13980, v1, *(_QWORD *)(result + 16), 0);
  }
  return result;
}
