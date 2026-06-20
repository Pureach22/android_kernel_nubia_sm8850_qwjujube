__int64 __fastcall pmic_arb_offset_v5(__int64 *a1, unsigned __int8 a2, unsigned __int16 a3, int a4)
{
  __int64 v5; // x10
  int v6; // w9

  if ( (*(_WORD *)(a1[17] + 2LL * ((a2 << 8) | (unsigned int)HIBYTE(a3))) & 0x8000) == 0 )
    return 4294967277LL;
  v5 = *a1;
  v6 = *(_WORD *)(a1[17] + 2LL * ((a2 << 8) | (unsigned int)HIBYTE(a3))) & 0x7FFF;
  if ( a4 )
  {
    if ( a4 == 1 )
      return (*(unsigned __int8 *)(v5 + 49) << 16) + (v6 << 7);
    else
      return 0;
  }
  else if ( *(unsigned __int8 *)(a1[19]
                               + 4LL * (*(_WORD *)(a1[17] + 2LL * ((a2 << 8) | (unsigned int)HIBYTE(a3))) & 0x7FFF)
                               + 2) == *(unsigned __int8 *)(v5 + 49) )
  {
    return (unsigned int)(v6 << 16);
  }
  else
  {
    dev_err(a1[5], "disallowed SPMI write to sid=%u, addr=0x%04X\n", a2, a3);
    return 0xFFFFFFFFLL;
  }
}
