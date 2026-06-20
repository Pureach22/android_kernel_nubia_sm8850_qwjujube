__int64 __fastcall createRingBuffer(int a1)
{
  __int64 v2; // x20

  if ( a1 > 1 )
  {
    v2 = _kmalloc_cache_noprof(_tracepoint_android_rvh_update_cpu_capacity, 3264, 128);
    *(_DWORD *)(v2 + 24) = a1;
    *(_WORD *)v2 = 0;
    *(_QWORD *)(v2 + 8) = _kmalloc_noprof(88LL * (unsigned int)a1, 3264);
    *(_QWORD *)(v2 + 40) = addItem;
    *(_QWORD *)(v2 + 48) = dump;
    *(_QWORD *)(v2 + 56) = dumpToBuf;
    *(_QWORD *)(v2 + 64) = &clear;
    *(_QWORD *)(v2 + 104) = isFull;
    *(_QWORD *)(v2 + 112) = debug;
    *(_QWORD *)(v2 + 72) = getCnt;
    *(_QWORD *)(v2 + 80) = getSize;
    *(_QWORD *)(v2 + 88) = setSize;
    *(_QWORD *)(v2 + 96) = isEmpty;
    *(_QWORD *)(v2 + 16) = _kmalloc_noprof(4LL * (unsigned int)a1, 3264);
    *(_QWORD *)(v2 + 120) = getMostFrequent;
    if ( v2 )
    {
      memset(*(void **)(v2 + 8), 0, 88LL * *(int *)(v2 + 24));
      memset(*(void **)(v2 + 16), 0, 4LL * *(int *)(v2 + 24));
      *(_QWORD *)(v2 + 28) = 0;
    }
    else
    {
      printk(&unk_61D9B);
    }
    printk(&unk_640A0);
  }
  else
  {
    printk(&unk_60EF1);
    return 0;
  }
  return v2;
}
