__int64 __fastcall clk_branch2_set_flags(__int64 a1, unsigned __int64 a2)
{
  unsigned int updated; // w0
  unsigned int v3; // w19

  if ( a2 > 5 )
    return 4294967274LL;
  updated = regmap_update_bits_base(
              *(_QWORD *)(a1 + 24),
              *(unsigned int *)(a1 - 12),
              dword_25878[a2],
              *((unsigned int *)&off_25860 + a2),
              0,
              0,
              0);
  __dsb(0xFu);
  v3 = updated;
  _const_udelay(4295);
  return v3;
}
