__int64 __fastcall sde_core_irq_idx_lookup(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 (__fastcall *v7)(__int64, __int64); // x9

  if ( !a1 )
    return 4294967274LL;
  v5 = *(_QWORD *)(a1 + 1896);
  if ( !v5 )
    return 4294967274LL;
  v6 = *(unsigned int *)(v5 + 28);
  if ( (unsigned int)v6 >= 3 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V23.4S, V10.4S, V29.S[2] }
    return sde_core_irq_enable(v5, a2, a3);
  }
  else
  {
    v7 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 8 * v6 + 32);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != 1955451567 )
        __break(0x8229u);
      return v7(v5, a2);
    }
    else if ( (_DWORD)v6 == 1 )
    {
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
}
