__int64 __fastcall gf_power_on(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w19

  if ( a1 && *(_QWORD *)(a1 + 144) < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_9762);
    if ( (unsigned int)regulator_is_enabled(*(_QWORD *)(a1 + 144)) )
    {
      printk(&unk_8558);
      return 0;
    }
    else
    {
      result = regulator_enable(*(_QWORD *)(a1 + 144));
      if ( (_DWORD)result )
      {
        v3 = result;
        printk(&unk_8833);
        return v3;
      }
    }
  }
  else
  {
    printk(&unk_8CAD);
    return 4294967277LL;
  }
  return result;
}
