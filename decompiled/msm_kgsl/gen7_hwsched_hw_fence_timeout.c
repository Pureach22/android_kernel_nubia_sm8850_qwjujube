__int64 __fastcall gen7_hwsched_hw_fence_timeout(__int64 a1)
{
  __int64 v2; // x22
  unsigned int v3; // w21
  unsigned int v4; // w25
  __int64 v5; // x24
  int v6; // w20
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x10
  int v10; // w4

  v2 = a1 - 1576;
  gen7_hwsched_process_msgq(a1 - 24728);
  raw_spin_lock(v2);
  v3 = *(_DWORD *)(a1 - 1572);
  if ( (*(_QWORD *)(a1 - 1528) & 1) != 0 )
    v4 = (v3 > 0xA) & ((unsigned int)*(_QWORD *)(a1 - 1528) >> 1);
  else
    v4 = 0;
  v5 = *(_QWORD *)(a1 - 1544);
  v6 = *(_DWORD *)(a1 - 1536);
  result = raw_spin_unlock(v2);
  if ( v4 )
  {
    dev_err(*(_QWORD *)(a1 - 23184) + 16LL, "Hardware fence unack(%d) timeout\n", v3);
    if ( v5 )
    {
      v8 = *(_QWORD *)(v5 + 24);
      v9 = *(_QWORD *)(v8 + 8);
      if ( v9 )
        v10 = *(_DWORD *)(v9 + 112);
      else
        v10 = 0;
      dev_err(
        *(_QWORD *)(a1 - 23184) + 16LL,
        "Hardware fence got deferred for ctx:%d ts:%d pid:%d proc:%s\n",
        *(_DWORD *)(v5 + 4),
        v6,
        v10,
        (const char *)(v8 + 16));
    }
    return gen7_hwsched_fault(a1 - 24728, 32);
  }
  return result;
}
