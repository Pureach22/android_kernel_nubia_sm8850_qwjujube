__int64 __fastcall mux_div_get_src_div(unsigned int *a1, unsigned int *a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  clk_hw_get_name(a1 + 10);
  regmap_read(*((_QWORD *)a1 + 8), *a1, &v8);
  if ( (v8 & 0x10) != 0 )
  {
    result = printk(&unk_28F0D);
  }
  else
  {
    result = regmap_read(*((_QWORD *)a1 + 8), *a1 + 4, &v8);
    v7 = v8;
    *a2 = (v8 >> a1[4]) & ~(unsigned int)(-1LL << a1[3]);
    *a3 = (v7 >> a1[2]) & ~(unsigned int)(-1LL << a1[1]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
