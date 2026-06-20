__int64 __fastcall hdd_config_ctrl_retry(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x2

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( *(unsigned __int8 *)(a2 + 4) >= 0x1Fu )
    v3 = 31;
  else
    v3 = *(unsigned __int8 *)(a2 + 4);
  return wma_cli_set_command(v2, 125, v3, 2);
}
