__int64 __fastcall gf_disable_irq(__int64 a1)
{
  unsigned int v1; // w8

  if ( !*(_DWORD *)(a1 + 76) )
    return printk(&unk_8DA2);
  v1 = *(_DWORD *)(a1 + 72);
  *(_DWORD *)(a1 + 76) = 0;
  return disable_irq(v1);
}
