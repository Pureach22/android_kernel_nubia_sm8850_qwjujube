__int64 __fastcall qtee_shmbridge_allocate_shm(unsigned __int64 a1, __int64 *a2, __int64 a3)
{
  size_t v4; // x20
  void *v5; // x0
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 result; // x0

  if ( a2 && (unsigned __int64)a2 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( qword_13968 < a1 )
    {
      printk(&unk_122AD, 407, a1);
      return 4294967274LL;
    }
    else if ( qword_13980 )
    {
      v4 = (a1 + (1 << dword_13978) - 1) / (1 << dword_13978) * (1 << dword_13978);
      v5 = (void *)gen_pool_alloc_algo_owner(
                     qword_13980,
                     v4,
                     *(_QWORD *)(qword_13980 + 32),
                     *(_QWORD *)(qword_13980 + 40),
                     0);
      if ( v5 )
      {
        v6 = (__int64)v5;
        memset(v5, 0, v4);
        a2[1] = v6;
        v7 = gen_pool_virt_to_phys(qword_13980, v6);
        result = 0;
        a2[2] = v4;
        *a2 = v7;
      }
      else
      {
        printk(&unk_122F2, 422, v4);
        return 4294967284LL;
      }
    }
    else
    {
      printk(&unk_12BA8, 413, a1);
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_11F3F, 400, a3);
    return 4294967274LL;
  }
  return result;
}
