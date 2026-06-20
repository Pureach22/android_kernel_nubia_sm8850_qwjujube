__int64 __fastcall crm_cache_vcd_votes(__int64 a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v4; // w23
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x24

  v4 = a3[2];
  v6 = *a3;
  v5 = a3[1];
  v7 = a1 + 40LL * a2;
  raw_spin_lock(a1 + 172);
  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 48) + 8 * v5) + 4 * v6) = v4;
  *(_BYTE *)(v7 + 72) = 1;
  raw_spin_unlock(a1 + 172);
  return ipc_log_string(
           *(_QWORD *)(a1 + 184),
           "Cache: type: %u resource_idx:%u pwr_state: %u data: %#x",
           a2,
           v5,
           v6,
           v4);
}
