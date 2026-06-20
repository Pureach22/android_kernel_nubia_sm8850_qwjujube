__int64 __fastcall sde_irq_preinstall(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 136);
  if ( !v1 || !*(_QWORD *)(v1 + 8) )
    return printk(&unk_216038, "sde_irq_preinstall");
  sde_core_irq_preinstall();
  result = platform_get_irq(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL) - 16LL, 0);
  *(_DWORD *)(a1 + 1952) = result;
  if ( (result & 0x80000000) != 0 )
    return printk(&unk_27D8CF, "sde_irq_preinstall");
  if ( (*(_BYTE *)(a1 + 1956) & 1) == 0 )
    return irq_modify_status((unsigned int)result, 0, 4096);
  return result;
}
