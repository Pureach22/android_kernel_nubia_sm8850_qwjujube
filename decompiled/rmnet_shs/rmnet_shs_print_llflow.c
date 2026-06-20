__int64 __fastcall rmnet_shs_print_llflow(_BYTE *a1)
{
  __int64 result; // x0
  int v3; // w8

  printk(&unk_15976);
  printk(&unk_154AE);
  printk(&unk_1576A);
  printk(&unk_15869);
  printk(&unk_157A7);
  printk(&unk_15887);
  printk(&unk_15642);
  printk(&unk_1582F);
  printk(&unk_159F2);
  result = printk(&unk_1558C);
  v3 = (unsigned __int8)a1[76];
  if ( v3 == 4 )
  {
    if ( !a1[73] || !a1[72] )
      return result;
    printk(&unk_15717);
    result = printk(&unk_155A4);
    v3 = (unsigned __int8)a1[76];
  }
  if ( v3 == 6 && a1[73] )
  {
    if ( a1[72] )
    {
      printk(&unk_15C14);
      return printk(&unk_15A99);
    }
  }
  return result;
}
