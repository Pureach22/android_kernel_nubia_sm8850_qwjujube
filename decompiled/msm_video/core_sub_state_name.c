const char *__fastcall core_sub_state_name(int a1)
{
  if ( a1 > 15 )
  {
    if ( a1 <= 63 )
    {
      if ( a1 == 16 )
        return "PAGE_FAULT ";
      if ( a1 == 32 )
        return "CPU_WATCHDOG ";
    }
    else
    {
      switch ( a1 )
      {
        case 64:
          return "VIDEO_UNRESPONSIVE ";
        case 128:
          return "RPROC_ENABLE ";
        case 256:
          return "MAX ";
      }
    }
  }
  else if ( a1 <= 1 )
  {
    if ( !a1 )
      return "NONE ";
    if ( a1 == 1 )
      return "POWER_ENABLE ";
  }
  else
  {
    switch ( a1 )
    {
      case 2:
        return "GDSC_HANDOFF ";
      case 4:
        return "PM_SUSPEND ";
      case 8:
        return "FW_PWR_CTRL ";
    }
  }
  return "UNKNOWN ";
}
