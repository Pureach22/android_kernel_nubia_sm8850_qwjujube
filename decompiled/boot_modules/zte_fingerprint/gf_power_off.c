__int64 __fastcall gf_power_off(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w19

  if ( a1 && *(_QWORD *)(a1 + 144) < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_91D3);
    if ( (unsigned int)regulator_is_enabled(*(_QWORD *)(a1 + 144)) )
    {
      result = regulator_disable(*(_QWORD *)(a1 + 144));
      if ( (_DWORD)result )
      {
        v3 = result;
        printk(&unk_8670);
        return v3;
      }
    }
    else
    {
      printk(&unk_8870);
      return 0;
    }
  }
  else
  {
    printk(&unk_8CAD);
    return 4294967277LL;
  }
  return result;
}
