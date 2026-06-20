__int64 __fastcall pmic_arb_wr_addr_map_v5(_QWORD *a1, unsigned __int8 a2, unsigned __int16 a3, __int64 *a4)
{
  __int64 v5; // x9
  __int64 v6; // x8

  if ( (*(_WORD *)(a1[17] + 2LL * ((a2 << 8) | (unsigned int)HIBYTE(a3))) & 0x8000) == 0 )
    return 4294967277LL;
  v5 = *(_WORD *)(a1[17] + 2LL * ((a2 << 8) | (unsigned int)HIBYTE(a3))) & 0x7FFF;
  if ( *(unsigned __int8 *)(a1[19] + 4 * v5 + 2) == *(unsigned __int8 *)(*a1 + 49LL) )
  {
    v6 = *(_QWORD *)(*a1 + 16LL) + (v5 << 16);
    *a4 = v6;
    a4[1] = v6 + 0xFFFF;
    return 0;
  }
  else
  {
    dev_err(a1[5], "disallowed SPMI write to sid=%u, addr=0x%04X\n", a2, a3);
    return 0xFFFFFFFFLL;
  }
}
