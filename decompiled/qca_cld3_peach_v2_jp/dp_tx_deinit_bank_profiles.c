__int64 __fastcall dp_tx_deinit_bank_profiles(__int64 a1)
{
  _qdf_mem_free(*(_QWORD *)(a1 + 22544));
  return qdf_mutex_destroy(a1 + 22480);
}
