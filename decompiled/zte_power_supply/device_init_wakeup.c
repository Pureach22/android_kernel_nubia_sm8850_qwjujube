__int64 __fastcall device_init_wakeup(__int64 a1, char a2)
{
  if ( (a2 & 1) != 0 )
  {
    device_set_wakeup_capable(a1, 1);
    return device_wakeup_enable(a1);
  }
  else
  {
    device_wakeup_disable(a1);
    device_set_wakeup_capable(a1, 0);
    return 0;
  }
}
