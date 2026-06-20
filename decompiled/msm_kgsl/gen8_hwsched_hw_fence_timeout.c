__int64 __fastcall gen8_hwsched_hw_fence_timeout(__int64 a1)
{
  __int64 v2; // x24
  __int64 v3; // x21
  unsigned int v4; // w22
  unsigned int v5; // w26
  __int64 v6; // x25
  int v7; // w20
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w4

  v2 = *(_QWORD *)(a1 - 23240);
  v3 = a1 - 1632;
  gen8_hwsched_process_msgq(a1 - 24784);
  raw_spin_lock(v3);
  v4 = *(_DWORD *)(a1 - 1628);
  if ( (*(_QWORD *)(a1 - 1584) & 1) != 0 )
    v5 = (v4 > 0xA) & ((unsigned int)*(_QWORD *)(a1 - 1584) >> 1);
  else
    v5 = 0;
  v6 = *(_QWORD *)(a1 - 1600);
  v7 = *(_DWORD *)(a1 - 1592);
  result = raw_spin_unlock(v3);
  if ( v5 )
  {
    dev_err(v2 + 16, "Hardware fence unack(%d) timeout\n", v4);
    if ( v6 )
    {
      v9 = *(_QWORD *)(v6 + 24);
      v10 = *(_QWORD *)(v9 + 8);
      if ( v10 )
        v11 = *(_DWORD *)(v10 + 112);
      else
        v11 = 0;
      dev_err(
        v2 + 16,
        "Hardware fence got deferred for ctx:%d ts:%d pid:%d proc:%s\n",
        *(_DWORD *)(v6 + 4),
        v7,
        v11,
        (const char *)(v9 + 16));
    }
    return gen8_hwsched_fault(a1 - 24784, 32);
  }
  return result;
}
