__int64 __fastcall mux_div_get_parent(__int64 a1)
{
  __int64 v2; // x21
  int num_parents; // w0
  int v4; // w22
  __int64 v5; // x21
  int v7; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v2 = a1 - 40;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  clk_hw_get_name(a1);
  v7 = 0;
  mux_div_get_src_div(v2, &v7, v8);
  num_parents = clk_hw_get_num_parents(a1);
  v4 = v7;
  if ( num_parents )
  {
    v5 = 0;
    while ( v4 != *(_DWORD *)(*(_QWORD *)(a1 - 8) + 4 * v5) )
    {
      if ( ++v5 >= (unsigned __int64)(unsigned int)clk_hw_get_num_parents(a1) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    printk(&unk_29519);
    LODWORD(v5) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
