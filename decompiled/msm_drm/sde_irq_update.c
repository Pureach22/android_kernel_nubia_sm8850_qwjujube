__int64 __fastcall sde_irq_update(__int64 a1, char a2)
{
  __int64 v3; // x0

  if ( !a1 )
    return printk(&unk_231B80, "sde_irq_update");
  v3 = *(unsigned int *)(a1 + 1952);
  *(_BYTE *)(a1 + 1956) = a2 & 1;
  if ( (a2 & 1) != 0 )
    return enable_irq(v3);
  else
    return disable_irq(v3);
}
