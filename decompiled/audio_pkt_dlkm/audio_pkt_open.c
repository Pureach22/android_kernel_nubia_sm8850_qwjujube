__int64 __fastcall audio_pkt_open(__int64 a1, __int64 a2)
{
  if ( (audio_pkt_debug_mask & 1) != 0 )
    ipc_log_string(
      0,
      "[%s]: %s: for %s \n",
      "audio_pkt_open",
      "audio_pkt_open",
      (const char *)(*(_QWORD *)(ap_priv + 16) + 268LL));
  *(_QWORD *)(a2 + 32) = ap_priv;
  return 0;
}
