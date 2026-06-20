__int64 sub_239FC4()
{
  char v0; // w24

  if ( (v0 & 1) == 0 )
    JUMPOUT(0x235C80);
  return wmi_print_event_log();
}
