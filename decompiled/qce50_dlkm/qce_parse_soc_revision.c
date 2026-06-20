__int64 __fastcall qce_parse_soc_revision(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x20
  __int64 result; // x0

  if ( arm64_use_ng_mappings )
    v2 = 0x68000000000F13LL;
  else
    v2 = 0x68000000000713LL;
  v3 = ioremap_prot(33325056, 4, v2);
  if ( v3 )
  {
    v5 = v3;
    *(_BYTE *)(a1 + 70304) = (unsigned int)readl() == -1608843008;
    return iounmap(v5);
  }
  else
  {
    result = printk(&unk_1553E, "qce_parse_soc_revision", v4);
    *(_BYTE *)(a1 + 70304) = 0;
  }
  return result;
}
