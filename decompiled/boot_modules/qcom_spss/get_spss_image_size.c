__int64 __fastcall get_spss_image_size(int a1)
{
  __int64 v1; // x0
  __int64 v2; // x2
  __int64 v3; // x0
  __int64 v4; // x19
  int v5; // w20
  unsigned int v6; // w1

  v1 = (unsigned int)(a1 + 4104);
  if ( arm64_use_ng_mappings )
    v2 = 0x68000000000F13LL;
  else
    v2 = 0x68000000000713LL;
  v3 = ioremap_prot(v1, 4, v2);
  if ( v3 )
  {
    v4 = v3;
    v5 = readl_relaxed();
    iounmap(v4);
    v6 = 4 * v5;
    if ( (v5 & 0x3FF) != 0 )
    {
      printk(&unk_811F);
      return (unsigned int)-14;
    }
  }
  else
  {
    printk(&unk_7CCE);
    return (unsigned int)-22;
  }
  return v6;
}
