__int64 __fastcall adreno_gen7_receive_err_req(__int64 a1, __int64 a2)
{
  __int64 v2; // d15
  __int64 v4; // x19
  __int64 (*v5)(void); // x8
  __int64 v6; // x20
  __int64 result; // x0
  int v8; // w3
  __int64 v9; // x0
  __int64 v10; // x1

  v4 = gen7_gmu_to_adreno(a1);
  v5 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v4 + 14264) + 40LL) + 152LL);
  if ( *((_DWORD *)v5 - 1) != -944375624 )
    __break(0x8228u);
  v6 = v5();
  result = dev_err(
             *(_QWORD *)(v4 + 1544) + 16LL,
             "HFI Error Received: %d %d %.16s\n",
             HIWORD(*(_DWORD *)(a2 + 4)),
             (unsigned __int16)*(_DWORD *)(a2 + 4),
             (const char *)(a2 + 8));
  v8 = *(_DWORD *)(v4 + 1536);
  if ( (v8 & 0x80) != 0 )
  {
    v9 = dev_err(
           *(_QWORD *)(v4 + 1544) + 16LL,
           "GMU always on ticks: %llx gf_policy: 0x%x gf_trigger: 0x%lx\n",
           v6,
           v8,
           128);
    __break(0x800u);
    *(_QWORD *)(v10 + 26080) = v2;
    return adreno_gen7_receive_debug_req(v9);
  }
  return result;
}
