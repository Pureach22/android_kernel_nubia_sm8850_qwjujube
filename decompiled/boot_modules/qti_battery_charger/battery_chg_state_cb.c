__int64 __fastcall battery_chg_state_cb(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  down_write(a1 + 192);
  if ( (*(_BYTE *)(a1 + 1144) & 1) != 0 )
  {
    *(_DWORD *)(a1 + 556) = a2;
    result = up_write(a1 + 192);
    if ( a2 )
    {
      if ( a2 == 1 )
        return queue_work_on(32, system_wq, a1 + 560);
    }
    else
    {
      *(_BYTE *)(a1 + 1164) = 0;
    }
  }
  else
  {
    printk(&unk_11A9C, "battery_chg_state_cb", a2);
    return up_write(a1 + 192);
  }
  return result;
}
