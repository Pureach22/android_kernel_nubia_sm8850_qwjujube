unsigned __int64 __fastcall gf_cleanup(__int64 a1)
{
  unsigned __int64 result; // x0
  void *v3; // x0

  printk(&unk_9885);
  if ( (*(_DWORD *)(a1 + 60) & 0x80000000) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 64) & 0x80000000) != 0 )
      goto LABEL_3;
  }
  else
  {
    gpio_free();
    printk(&unk_8B3B);
    if ( (*(_DWORD *)(a1 + 64) & 0x80000000) != 0 )
      goto LABEL_3;
  }
  gpio_free();
  printk(&unk_9204);
LABEL_3:
  result = *(_QWORD *)(a1 + 144);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (unsigned int)regulator_is_enabled() )
    {
      regulator_disable(*(_QWORD *)(a1 + 144));
      v3 = &unk_9899;
    }
    else
    {
      v3 = &unk_97E1;
    }
    return printk(v3);
  }
  return result;
}
