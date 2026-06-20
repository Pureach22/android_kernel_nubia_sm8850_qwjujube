__int64 __fastcall adreno_hwsched_snapshot_rb(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  __int64 v9; // x8

  if ( *(_QWORD *)(a4 + 40) + 44LL <= a3 )
  {
    *(_DWORD *)a2 = 0;
    v7 = *(_QWORD *)(a4 + 40);
    *(_DWORD *)(a2 + 16) = 0;
    *(_DWORD *)(a2 + 4) = v7 >> 2;
    *(_DWORD *)(a2 + 8) = *(_QWORD *)(a4 + 40) >> 2;
    v8 = *(_QWORD *)(a4 + 40);
    *(_QWORD *)(a2 + 24) = 0;
    *(_DWORD *)(a2 + 20) = v8 >> 2;
    v9 = *(_QWORD *)(a4 + 24);
    *(_DWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 32) = v9;
    memcpy((void *)(a2 + 44), *(const void **)(a4 + 8), *(_QWORD *)(a4 + 40));
    return *(_QWORD *)(a4 + 40) + 44LL;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&adreno_hwsched_snapshot_rb__rs, "adreno_hwsched_snapshot_rb") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "RB");
    return 0;
  }
}
