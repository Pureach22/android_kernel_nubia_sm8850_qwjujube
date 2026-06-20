__int64 __fastcall csr_set_global_cfgs(__int64 a1)
{
  __int64 v1; // x20
  _DWORD *v3; // x21
  unsigned int frag_thresh; // w0
  __int64 v5; // x20
  unsigned int rts_thresh; // w0
  unsigned int v7; // w1
  unsigned int v8; // w1
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 21552);
  v3 = (_DWORD *)(a1 + 0x4000);
  frag_thresh = csr_get_frag_thresh();
  wlan_mlme_set_frag_threshold(v1, frag_thresh);
  v5 = *(_QWORD *)(a1 + 21552);
  rts_thresh = csr_get_rts_thresh(a1);
  wlan_mlme_set_rts_threshold(v5, rts_thresh);
  v7 = v3[185];
  if ( v7 <= 0xA )
    ucfg_mlme_set_channel_bonding_5ghz(*(_QWORD *)(a1 + 21552), v7);
  v8 = v3[184];
  if ( v8 <= 0xA )
    ucfg_mlme_set_channel_bonding_24ghz(*(_QWORD *)(a1 + 21552), v8);
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + 3508LL) = 40;
  result = csr_translate_to_wni_cfg_dot11_mode(a1, (unsigned int)v3[187]);
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL) = result;
  return result;
}
