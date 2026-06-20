__int64 __fastcall wcd939x_hph_compander_get(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x9

  v4 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  if ( (unsigned int)v4 >= 2 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return wcd939x_hph_compander_put();
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 128);
    *(_QWORD *)(a2 + 72) = *(int *)(*(_QWORD *)(*(_QWORD *)(v5 + 24) + 152LL) + 4 * v4 + 264);
    return 0;
  }
}
