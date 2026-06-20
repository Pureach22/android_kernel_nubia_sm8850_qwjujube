__int64 __fastcall sde_power_mmrm_callback(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 result; // x0
  unsigned int v9; // w20

  if ( *(_DWORD *)a1 != 1 )
    return 0xFFFFFFFFLL;
  result = sde_power_mmrm_set_clk_limit(
             *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL),
             **(_QWORD **)(a1 + 24),
             *(_QWORD *)(a1 + 16),
             a4,
             a5,
             a6,
             a7,
             a8);
  if ( (_DWORD)result )
  {
    v9 = result;
    printk(&unk_23CC7C, "sde_power_mmrm_callback");
    return v9;
  }
  return result;
}
