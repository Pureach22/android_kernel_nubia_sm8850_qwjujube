__int64 __fastcall rtc6226_power_up(__int64 a1)
{
  unsigned int all_registers; // w0
  int v3; // w0
  unsigned int v4; // w20

  mutex_lock(a1 + 1872);
  all_registers = rtc6226_start(a1);
  if ( (all_registers & 0x80000000) == 0 )
  {
    *(_WORD *)(a1 + 1766) = 16396;
    all_registers = rtc6226_set_register(a1, 2);
    if ( (all_registers & 0x80000000) == 0 )
    {
      *(_WORD *)(a1 + 1770) |= 0xC000u;
      all_registers = rtc6226_set_register(a1, 4);
      if ( (all_registers & 0x80000000) == 0 )
      {
        *(_WORD *)(a1 + 1776) |= 4u;
        all_registers = rtc6226_set_register(a1, 7);
        if ( (all_registers & 0x80000000) == 0 )
        {
          *(_WORD *)(a1 + 1818) = 9344;
          all_registers = rtc6226_set_register(a1, 28);
          if ( (all_registers & 0x80000000) == 0 )
          {
            *(_WORD *)(a1 + 1772) = *(_WORD *)(a1 + 1772) & 0xF0FF | 0x200;
            v3 = rtc6226_set_register(a1, 5);
            *(_BYTE *)(a1 + 1761) = 8;
            if ( v3 < 0 )
              printk(&unk_D9F1, "rtc6226_power_up");
            *(_WORD *)(a1 + 1774) = 0x8000;
            all_registers = rtc6226_set_register(a1, 6);
            if ( (all_registers & 0x80000000) == 0 )
            {
              msleep(30);
              all_registers = rtc6226_get_all_registers(a1);
            }
          }
        }
      }
    }
  }
  v4 = all_registers;
  mutex_unlock(a1 + 1872);
  return v4;
}
