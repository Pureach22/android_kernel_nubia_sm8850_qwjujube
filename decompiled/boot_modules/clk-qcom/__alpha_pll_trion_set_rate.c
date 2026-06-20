__int64 __fastcall _alpha_pll_trion_set_rate(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned int a4, int a5)
{
  unsigned __int64 v8; // x9
  char v9; // w10
  unsigned __int64 v10; // x22
  unsigned __int64 v11; // x23
  __int64 result; // x0
  const char **v13; // x8
  const char *name; // x1
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v8 = a2 % (unsigned int)a3;
  if ( v8 )
  {
    v9 = 16;
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL) - *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL) == 4 )
      v9 = 32;
    v10 = (v8 << v9) / (unsigned int)a3;
    v11 = 1000
        * (((((unsigned __int64)(unsigned int)v10 * a3) >> v9) + (unsigned int)(a2 / (unsigned int)a3) * a3 + 999)
         / 0x3E8);
  }
  else
  {
    LODWORD(v10) = 0;
    v11 = a2;
  }
  if ( v11 < a2 || a2 + 500 < v11 )
  {
    clk_hw_get_name(a1);
    printk(&unk_28661);
    result = 4294967274LL;
    goto LABEL_13;
  }
  regmap_update_bits_base(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
    0xFFFF,
    a2 / (unsigned int)a3,
    0,
    0,
    0);
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
    (unsigned int)v10);
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v15);
  if ( (v15 & 4) == 0 )
  {
LABEL_9:
    if ( (clk_hw_is_enabled(a1) & 1) == 0
      || (result = wait_for_pll((unsigned int *)(a1 - 48), 0x80000000, 0, "enable"), !(_DWORD)result) )
    {
      _const_udelay(429500);
      result = 0;
    }
    goto LABEL_13;
  }
  result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), a4, a4, 0, 0, 0);
  if ( (_DWORD)result )
    goto LABEL_13;
  _const_udelay(4295);
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v15);
  if ( (v15 & a5) != 0 )
  {
    result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), a4, 0, 0, 0, 0);
    if ( (_DWORD)result )
      goto LABEL_13;
    goto LABEL_9;
  }
  clk_debug_print_hw(a1, 0);
  v13 = *(const char ***)(a1 + 16);
  if ( v13 )
    name = *v13;
  else
    name = (const char *)clk_hw_get_name(a1);
  _warn_printk("%s: Lucid PLL latch failed. Output may be unstable!\n", name);
  __break(0x800u);
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
