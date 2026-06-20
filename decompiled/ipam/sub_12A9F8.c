// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_12A9F8(__int64 a1, const char *a2)
{
  int v2; // w13

  if ( (v2 & 0x1000000) == 0 )
    return ipa_is_modem_pipe(a1);
  ipc_log_string(a1, a2, "__ipa_stop_gsi_channel", 12556);
  return 4294967274LL;
}
