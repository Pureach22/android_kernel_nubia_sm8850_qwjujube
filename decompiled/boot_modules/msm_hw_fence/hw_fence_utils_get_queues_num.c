__int64 __fastcall hw_fence_utils_get_queues_num(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v3; // x8

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 60) > a2 )
    {
      v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 16LL * (int)a2);
      if ( v3 )
        return *(unsigned int *)(v3 + 20);
    }
  }
  printk(&unk_219A6, "hw_fence_utils_get_queues_num", 1926, v2, a2);
  return 0;
}
