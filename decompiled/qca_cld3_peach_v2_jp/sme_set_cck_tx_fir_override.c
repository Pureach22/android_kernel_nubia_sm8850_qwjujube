__int64 __fastcall sme_set_cck_tx_fir_override(__int64 a1, unsigned int a2)
{
  return wma_cli_set_command(a2, 151, *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1052LL), 2);
}
