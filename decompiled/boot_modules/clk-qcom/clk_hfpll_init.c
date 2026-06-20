__int64 __fastcall clk_hfpll_init(__int64 a1)
{
  unsigned int *v2; // x21
  __int64 v3; // x20
  __int64 v4; // x1
  const char *name; // x0
  __int64 v6; // x20
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int **)(a1 - 16);
  v8[0] = 0;
  v3 = *(_QWORD *)(a1 + 24);
  regmap_read(v3, *v2, (char *)v8 + 4);
  if ( HIDWORD(v8[0]) != 7 )
    goto LABEL_5;
  v4 = v2[7];
  if ( (_DWORD)v4 )
  {
    regmap_read(v3, v4, v8);
    if ( (((unsigned __int64)LODWORD(v8[0]) >> *((_BYTE *)v2 + 32)) & 1) == 0 )
    {
      name = (const char *)_clk_get_name(*(_QWORD *)(a1 + 8));
      _warn_printk("HFPLL %s is ON, but not locked!\n", name);
      __break(0x800u);
      v6 = raw_spin_lock_irqsave(a1 + 144);
      regmap_update_bits_base(*(_QWORD *)(a1 + 24), **(unsigned int **)(a1 - 16), 7, 0, 0, 0, 0);
      raw_spin_unlock_irqrestore(a1 + 144, v6);
LABEL_5:
      _clk_hfpll_init_once(a1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
