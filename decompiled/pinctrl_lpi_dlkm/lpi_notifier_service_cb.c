__int64 __fastcall lpi_notifier_service_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( a2 == 1 )
  {
    if ( initial_boot == 1 )
      initial_boot = 0;
    lpi_dev_up = 1;
    snd_event_notify(lpi_dev, 1);
    return 1;
  }
  if ( a2 )
    return 1;
  result = 1;
  if ( initial_boot == 1 )
    initial_boot = 0;
  else
    lpi_dev_up = 0;
  return result;
}
