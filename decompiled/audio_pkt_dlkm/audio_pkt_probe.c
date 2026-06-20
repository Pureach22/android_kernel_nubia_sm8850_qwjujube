__int64 __fastcall audio_pkt_probe(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 result; // x0

  if ( ap_priv )
  {
    mutex_lock(ap_priv + 24);
    v2 = ap_priv;
    v3 = ap_priv + 24;
    *(_QWORD *)ap_priv = a1;
    *(_DWORD *)(v2 + 72) = 1;
    mutex_unlock(v3);
    result = 0;
    *(_QWORD *)(a1 + 152) = ap_priv;
  }
  else
  {
    dev_err(a1, "%s: Driver[%s] Probe Failed\n", "audio_pkt_probe", (const char *)(a1 + 920));
    return 4294967274LL;
  }
  return result;
}
