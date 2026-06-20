__int64 __fastcall wlan_dp_sawfish_update_metadata(__int64 *a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x20
  unsigned int v6; // w8
  __int64 result; // x0
  unsigned int peer_id; // w0
  unsigned __int16 v9; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v10[5]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+30h] [xbp-10h]
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[467];
  v11 = 0;
  memset(v10, 0, sizeof(v10));
  if ( !v2 )
  {
    result = 11;
    goto LABEL_9;
  }
  if ( (dp_rtpm_tput_policy_get_vote(*a1) & 2) != 0 )
  {
    result = 10;
    goto LABEL_9;
  }
  v5 = *(_QWORD *)(a2 + 24);
  if ( (_qdf_nbuf_sock_is_valid_fullsock(a2) & 1) == 0 )
    goto LABEL_16;
  v6 = *(unsigned __int8 *)(v5 + 646);
  v9 = v6 >> 2;
  if ( v6 < 4 )
  {
    if ( !_qdf_nbuf_data_is_ipv6_pkt(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_dns_query(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_dns_response(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224))
      && *(_WORD *)(a2 + 180) == 8
      && (*(_WORD *)(*(_QWORD *)(a2 + 224) + 20LL) & 0xFF1F) == 0 )
    {
      dp_fim_parse_skb_flow_info(a2, (int)v10);
      if ( (_DWORD)v11 )
      {
        if ( (v11 & 0x80) == 0 )
        {
          peer_id = cdp_get_peer_id(*(_QWORD *)(*a1 + 240), *(_QWORD *)(a2 + 224));
          wlan_dp_spm_get_flow_id_origin(a1, &v9, v10, v5, peer_id);
          if ( v9 > 0x3Fu )
          {
            result = 4;
            goto LABEL_9;
          }
          *(_BYTE *)(v5 + 646) = *(_BYTE *)(v5 + 646) & 3 | (4 * v9);
          goto LABEL_5;
        }
      }
    }
LABEL_16:
    result = 4;
    *(_DWORD *)(a2 + 168) = 251658240;
    goto LABEL_9;
  }
LABEL_5:
  result = (unsigned __int16)wlan_dp_spm_svc_get_metadata(a1, a2);
  if ( (_DWORD)result == 17 )
    *(_BYTE *)(v5 + 646) &= 3u;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
