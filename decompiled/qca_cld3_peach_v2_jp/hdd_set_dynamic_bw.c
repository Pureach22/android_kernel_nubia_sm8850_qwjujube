__int64 __fastcall hdd_set_dynamic_bw(__int64 a1, __int64 a2)
{
  return wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 10, *(unsigned __int8 *)(a2 + 4), 2);
}
