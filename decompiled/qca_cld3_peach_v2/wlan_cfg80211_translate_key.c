__int64 __fastcall wlan_cfg80211_translate_key(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  int v12; // w8
  int v13; // w0
  int v14; // w0
  int v15; // w1

  qdf_mem_set(a6, 0x1B0u, 0);
  v12 = *(_DWORD *)(a5 + 16);
  *(_WORD *)(a6 + 4) = a2;
  *(_BYTE *)a6 = v12;
  qdf_trace_msg(
    72,
    8,
    "%s: key_type %d, opmode %d, key_len %d, seq_len %d",
    "wlan_cfg80211_translate_key",
    a3,
    *(_DWORD *)(a1 + 16),
    *(_DWORD *)(a5 + 16),
    *(_DWORD *)(a5 + 20));
  qdf_mem_copy(a6 + 384, *(_QWORD *)a5, *(unsigned int *)(a5 + 16));
  qdf_mem_copy(a6 + 104, *(_QWORD *)(a5 + 8), *(unsigned int *)(a5 + 20));
  *(_DWORD *)(a6 + 12) = a3;
  v13 = osif_nl_to_crypto_cipher_type(*(unsigned int *)(a5 + 28));
  *(_DWORD *)(a6 + 8) = v13;
  if ( v13 && v13 != 15 )
  {
    if ( a4 || v13 != 16 )
      goto LABEL_4;
    return qdf_trace_msg(72, 8, "%s: No Mac Address to copy", "wlan_cfg80211_translate_key");
  }
  if ( !a4 )
    return qdf_trace_msg(72, 8, "%s: No Mac Address to copy", "wlan_cfg80211_translate_key");
LABEL_4:
  if ( a3 && (*(_DWORD *)(a1 + 16) | 2) != 2 )
  {
    v14 = a6 + 16;
    v15 = a1 + 74;
  }
  else
  {
    v14 = a6 + 16;
    v15 = a4;
  }
  qdf_mem_copy(v14, v15, 6u);
  return qdf_trace_msg(
           72,
           8,
           "%s: mac %02x:%02x:%02x:**:**:%02x",
           "wlan_cfg80211_translate_key",
           *(unsigned __int8 *)(a6 + 16),
           *(unsigned __int8 *)(a6 + 17),
           *(unsigned __int8 *)(a6 + 18),
           *(unsigned __int8 *)(a6 + 21));
}
