__int64 sub_239FA0()
{
  char v0; // w24

  if ( (v0 & 1) == 0 )
    JUMPOUT(0x235C5C);
  return wmi_print_mgmt_cmd_tx_cmp_log();
}
