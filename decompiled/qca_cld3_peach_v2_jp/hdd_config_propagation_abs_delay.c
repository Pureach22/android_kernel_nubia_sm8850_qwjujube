__int64 __fastcall hdd_config_propagation_abs_delay(__int64 a1, __int64 a2)
{
  return wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 126, *(unsigned int *)(a2 + 4), 2);
}
