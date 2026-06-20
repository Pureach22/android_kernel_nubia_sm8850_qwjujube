__int64 sub_21A820()
{
  char v0; // w24

  if ( (v0 & 1) == 0 )
    JUMPOUT(0x2164DC);
  return wmi_print_mgmt_cmd_tx_cmp_log();
}
