__int64 __fastcall wlan_cfg80211_translate_ml_sta_key(unsigned __int8 a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v10; // w8
  int v11; // w0

  qdf_mem_set(a5, 0x1B0u, 0);
  v10 = *(_DWORD *)(a4 + 16);
  *(_WORD *)(a5 + 4) = a1;
  *(_BYTE *)a5 = v10;
  qdf_trace_msg(
    72,
    8,
    "%s: key_type %d, key_len %d, seq_len %d",
    "wlan_cfg80211_translate_ml_sta_key",
    a2,
    *(_DWORD *)(a4 + 16),
    *(_DWORD *)(a4 + 20));
  qdf_mem_copy(a5 + 384, *(_QWORD *)a4, *(unsigned int *)(a4 + 16));
  qdf_mem_copy(a5 + 104, *(_QWORD *)(a4 + 8), *(unsigned int *)(a4 + 20));
  *(_DWORD *)(a5 + 12) = a2;
  v11 = osif_nl_to_crypto_cipher_type(*(unsigned int *)(a4 + 28));
  *(_DWORD *)(a5 + 8) = v11;
  if ( v11 && v11 != 15 )
  {
    if ( a3 || v11 != 16 )
      goto LABEL_4;
  }
  else if ( a3 )
  {
LABEL_4:
    qdf_mem_copy(a5 + 16, a3, 6u);
    return qdf_trace_msg(
             72,
             8,
             "%s: crypto key mac %02x:%02x:%02x:**:**:%02x",
             "wlan_cfg80211_translate_ml_sta_key",
             *(unsigned __int8 *)(a5 + 16),
             *(unsigned __int8 *)(a5 + 17),
             *(unsigned __int8 *)(a5 + 18),
             *(unsigned __int8 *)(a5 + 21));
  }
  return qdf_trace_msg(72, 8, "%s: No Mac Address to copy", "wlan_cfg80211_translate_ml_sta_key");
}
