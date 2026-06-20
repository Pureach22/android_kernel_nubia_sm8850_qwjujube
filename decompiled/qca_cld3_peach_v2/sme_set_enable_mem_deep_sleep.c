__int64 __fastcall sme_set_enable_mem_deep_sleep(__int64 a1, unsigned int a2)
{
  return wma_cli_set_command(a2, 52, *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1051LL), 2);
}
