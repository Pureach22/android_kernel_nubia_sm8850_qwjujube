__int64 __fastcall hdd_config_propagation_delay(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  int v3; // w8

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( *(unsigned __int8 *)(a2 + 4) >= 0x3Fu )
    v3 = 63;
  else
    v3 = *(unsigned __int8 *)(a2 + 4);
  return wma_cli_set_command(v2, 126, v3 | 0x40u, 2);
}
