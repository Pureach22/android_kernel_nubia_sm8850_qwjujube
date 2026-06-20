__int64 __fastcall clk_rcg2_disable(__int64 result)
{
  char v1; // w8
  __int64 v2; // x19

  v1 = *(_BYTE *)(result - 16);
  v2 = result;
  *(_BYTE *)(result + 155) = 0;
  if ( (v1 & 1) != 0 )
  {
    clk_rcg2_set_force_enable(result);
    if ( (unsigned int)clk_rcg2_configure(v2 - 48, &cxo_f) )
    {
      clk_hw_get_name(v2);
      printk(&unk_289B5);
    }
  }
  else if ( (*(_BYTE *)(result + 152) & 1) == 0 )
  {
    return result;
  }
  return regmap_update_bits_base(*(_QWORD *)(v2 + 24), *(unsigned int *)(v2 - 48), 2, 0, 0, 0, 0);
}
