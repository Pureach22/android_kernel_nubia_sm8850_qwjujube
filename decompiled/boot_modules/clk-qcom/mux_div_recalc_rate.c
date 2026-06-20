unsigned __int64 __fastcall mux_div_recalc_rate(__int64 a1)
{
  __int64 v2; // x22
  int num_parents; // w21
  __int64 v4; // x1
  unsigned __int64 result; // x0
  __int64 parent_by_index; // x0
  unsigned __int64 rate; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 - 40;
  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  num_parents = clk_hw_get_num_parents(a1);
  clk_hw_get_name(a1);
  mux_div_get_src_div(v2, v8, (char *)v8 + 4);
  if ( num_parents < 1 )
  {
LABEL_5:
    printk(&unk_28EF1);
    result = 0;
  }
  else
  {
    v4 = 0;
    while ( LODWORD(v8[0]) != *(_DWORD *)(*(_QWORD *)(a1 - 8) + 4 * v4) )
    {
      if ( num_parents == ++v4 )
        goto LABEL_5;
    }
    parent_by_index = clk_hw_get_parent_by_index(a1, v4);
    rate = clk_hw_get_rate(parent_by_index);
    result = 2 * (rate % (unsigned int)(HIDWORD(v8[0]) + 1)) / (unsigned int)(HIDWORD(v8[0]) + 1)
           + 2 * (rate / (unsigned int)(HIDWORD(v8[0]) + 1));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
