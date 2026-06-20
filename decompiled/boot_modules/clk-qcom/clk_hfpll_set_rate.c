__int64 __fastcall clk_hfpll_set_rate(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v5; // x21
  __int64 v6; // x25
  __int64 v7; // x22
  __int64 v8; // x20
  char is_enabled; // w23
  __int64 v10; // x1
  unsigned int v11; // w8
  __int64 v12; // x2
  __int64 v13; // x1
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v5 = a2 / a3;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 16);
  v7 = *(_QWORD *)(a1 + 24);
  v15 = 0;
  v8 = raw_spin_lock_irqsave(a1 + 144);
  is_enabled = _clk_is_enabled(*(_QWORD *)(a1 + 8));
  if ( (is_enabled & 1) != 0 )
    regmap_update_bits_base(*(_QWORD *)(a1 + 24), **(unsigned int **)(a1 - 16), 7, 0, 0, 0, 0);
  v10 = *(unsigned int *)(v6 + 16);
  if ( (_DWORD)v10 && *(_DWORD *)(v6 + 52) )
  {
    regmap_read(v7, v10, &v15);
    v11 = *(_DWORD *)(v6 + 52);
    if ( *(_QWORD *)(v6 + 56) >= a2 )
      v12 = v15 & ~v11;
    else
      v12 = v15 | v11;
    v13 = *(unsigned int *)(v6 + 16);
    v15 = v12;
    regmap_write(v7, v13, v12);
  }
  regmap_write(v7, *(unsigned int *)(v6 + 4), (unsigned int)v5);
  if ( (is_enabled & 1) != 0 )
    _clk_hfpll_enable(a1);
  raw_spin_unlock_irqrestore(a1 + 144, v8);
  _ReadStatusReg(SP_EL0);
  return 0;
}
