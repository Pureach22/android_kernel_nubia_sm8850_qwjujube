__int64 __fastcall ifpc_hyst_store(__int64 a1, unsigned __int16 a2)
{
  int v4; // w2

  if ( !(unsigned int)gmu_core_dev_ifpc_isenabled(a1) )
    return 4294967274LL;
  if ( (unsigned int)a2 <= *(_DWORD *)(a1 + 24040) )
    v4 = *(_DWORD *)(a1 + 24040);
  else
    v4 = a2;
  if ( v4 == *(_DWORD *)(a1 + 24036) )
    return 0;
  else
    return adreno_power_cycle_u32(a1, (_DWORD *)(a1 + 24036), v4);
}
