__int64 __fastcall qvadj_set_next_voltage_overrides(unsigned __int8 a1, __int64 a2)
{
  int v2; // w19
  unsigned int v3; // w19

  if ( ((unsigned __int8)a2 | (unsigned int)a1) >= 8 )
  {
    printk(&unk_6627, a2);
    return (unsigned int)-22;
  }
  else
  {
    v2 = a1 | (16 * (unsigned __int8)a2);
    mutex_lock(pd);
    v3 = regmap_write(*(_QWORD *)(pd + 48), 29009, v2 | 0x88u);
    if ( (v3 & 0x80000000) != 0 )
      printk(&unk_65FE, v3);
    mutex_unlock(pd);
  }
  return v3;
}
