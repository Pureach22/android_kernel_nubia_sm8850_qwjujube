void __fastcall spi_setup_word_len(__int64 a1, char a2, signed int a3)
{
  _BOOL4 v5; // w23
  int v6; // w0
  int v7; // w8
  unsigned int v8; // w20
  unsigned int v9; // w21

  v5 = (a2 & 8) == 0;
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 184) + 616LL));
  v7 = *(_DWORD *)(a1 + 216);
  v8 = v6 & 0xFFFFFC00 | (a3 + 1020) & 0x3FF;
  if ( v7 % a3 )
    v9 = 1;
  else
    v9 = v7 / a3;
  geni_se_config_packing(a1, (unsigned int)a3, v9, v5, 1, 1);
  writel_relaxed(v8, (unsigned int *)(*(_QWORD *)(a1 + 184) + 616LL));
  ipc_log_string(*(_QWORD *)(a1 + 472), "%s: %u bpw %d pack_words %d\n", "spi_setup_word_len", v8, a3, v9);
  if ( *(_QWORD *)(a1 + 200) )
    spi_trace_log();
}
