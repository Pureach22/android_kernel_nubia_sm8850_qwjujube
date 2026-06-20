__int64 __fastcall hdd_ipa_update_rx_mcbc_stats(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  unsigned __int8 *v6; // x8
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = hdd_get_sta_info_by_mac(a1 + 38848, *(_QWORD *)(a2 + 224) + 6LL, 30, 3);
  v7[0] = result;
  if ( result )
  {
    v5 = result;
    if ( _qdf_nbuf_data_is_ipv4_mcast_pkt(*(_QWORD *)(a2 + 224)) )
      ++*(_DWORD *)(v5 + 232);
    v6 = *(unsigned __int8 **)(a2 + 224);
    if ( *v6 == 255 && v6[1] == 255 && v6[2] == 255 && v6[3] == 255 && v6[4] == 255 && v6[5] == 255 )
      ++*(_DWORD *)(v5 + 232);
    result = hdd_put_sta_info_ref(a1 + 38848, v7, 1, 30);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
