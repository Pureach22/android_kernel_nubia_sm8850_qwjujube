__int64 __fastcall wcd939x_hph_compander_put(__int64 a1, __int64 a2)
{
  unsigned int v4; // w3
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v8; // x10

  v4 = *(_DWORD *)(a2 + 72);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL);
  if ( v4 >= 2 )
  {
    dev_err(v6, "%s: Invalid comp value = %d\n", "wcd939x_hph_compander_put", v4);
    return 4294967274LL;
  }
  else
  {
    v7 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
    if ( (unsigned int)v7 > 1 )
    {
      __break(0x5512u);
      __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
      return wcd939x_hph_xtalk_get(v6);
    }
    else
    {
      v8 = *(_QWORD *)(v6 + 152);
      *(_DWORD *)(v8 + 4 * v7 + 264) = v4;
      return 0;
    }
  }
}
