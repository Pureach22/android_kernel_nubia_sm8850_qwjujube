__int64 sub_23A254()
{
  char v0; // w24

  if ( (v0 & 1) == 0 )
    JUMPOUT(0x235F10);
  return wmi_print_mgmt_event_log();
}
