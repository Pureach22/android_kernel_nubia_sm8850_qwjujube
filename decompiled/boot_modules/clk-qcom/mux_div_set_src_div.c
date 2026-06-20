__int64 __fastcall mux_div_set_src_div(unsigned int *a1, int a2, int a3)
{
  unsigned int v6; // w8
  unsigned int v7; // w11
  int v8; // w14
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x3
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  __int64 result; // x0
  int v15; // w21
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  clk_hw_get_name(a1 + 10);
  v6 = a1[4];
  v7 = a1[2];
  v8 = a2 << v6;
  v9 = *((_QWORD *)a1 + 8);
  v10 = *a1 + 4;
  v11 = (a2 << v6) | (unsigned int)(a3 << v7);
  v12 = (unsigned __int64)(unsigned int)~(-1 << a1[1]) << v7;
  v13 = (unsigned __int64)(unsigned int)~(-1 << a1[3]) << v6;
  v16 = v8 | (a3 << v7);
  result = regmap_update_bits_base(v9, v10, (unsigned int)v13 | (unsigned int)v12, v11, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    result = regmap_update_bits_base(*((_QWORD *)a1 + 8), *a1, 1, 1, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      v15 = 501;
      while ( 1 )
      {
        result = regmap_read(*((_QWORD *)a1 + 8), *a1, &v16);
        if ( (_DWORD)result )
          break;
        if ( (v16 & 1) == 0 )
        {
          result = 0;
          break;
        }
        _const_udelay(4295);
        if ( (unsigned int)--v15 <= 1 )
        {
          printk(&unk_294EE);
          result = 4294967280LL;
          break;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
