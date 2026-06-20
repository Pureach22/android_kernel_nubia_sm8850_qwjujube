__int64 __fastcall wlan_dp_lapb_handle_app_ind(__int64 a1)
{
  unsigned __int64 v1; // x19
  __int64 context; // x0
  __int64 v4; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x8
  int v8; // w19
  unsigned __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  char v13; // w21
  bool is_ipv4_pkt; // w8
  __int64 v15; // x0
  char ipv4_tos; // w0
  char v17; // w19
  bool v18; // w8
  __int64 v19; // x0

  v1 = *(unsigned int *)(a1 + 168);
  if ( (v1 & 0xF000000) == 0xB000000 )
  {
    context = dp_get_context();
    if ( context )
      v4 = *(_QWORD *)(context + 1552);
    else
      v4 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)(StatusReg + 16) += 512;
    if ( (v1 & 0xE00000) != 0 )
      goto LABEL_9;
    if ( !v4 )
      goto LABEL_9;
    v6 = *(_QWORD *)(v4 + 8 * ((v1 >> 16) & 0x1F));
    if ( !v6 || (*(_BYTE *)(v6 + 28) & 4) == 0 )
      goto LABEL_9;
    v8 = *(unsigned __int8 *)(v6 + 25);
    local_bh_enable_6();
    v9 = *(unsigned int *)(a1 + 168);
    v10 = dp_get_context();
    v11 = v10 ? *(_QWORD *)(v10 + 1552) : 0LL;
    *(_DWORD *)(StatusReg + 16) += 512;
    if ( (v9 & 0xE00000) == 0
      && v11
      && (v12 = *(_QWORD *)(v11 + 8 * ((v9 >> 16) & 0x1F))) != 0
      && (*(_BYTE *)(v12 + 28) & 2) != 0 )
    {
      v13 = *(_BYTE *)(v12 + 24);
      local_bh_enable_6();
      is_ipv4_pkt = _qdf_nbuf_data_is_ipv4_pkt(*(_QWORD *)(a1 + 224));
      v15 = *(_QWORD *)(a1 + 224);
      if ( is_ipv4_pkt )
      {
        ipv4_tos = _qdf_nbuf_data_get_ipv4_tos(v15);
      }
      else
      {
        if ( !_qdf_nbuf_data_is_ipv6_pkt(v15) )
          return 0;
        ipv4_tos = _qdf_nbuf_data_get_ipv6_tc(*(_QWORD *)(a1 + 224));
      }
      if ( v8 == (unsigned __int8)(ipv4_tos & 0xFC) >> 2 )
      {
        v17 = ipv4_tos & 3 | (4 * v13);
        v18 = _qdf_nbuf_data_is_ipv4_pkt(*(_QWORD *)(a1 + 224));
        v19 = *(_QWORD *)(a1 + 224);
        if ( v18 )
        {
          _qdf_nbuf_data_set_ipv4_tos(v19, v17);
          ip_send_check(*(_QWORD *)(a1 + 224) + 14LL);
          if ( _qdf_nbuf_is_ipv4_last_fragment(a1) )
            *(_DWORD *)(a1 + 168) |= 0x10000000u;
        }
        else if ( _qdf_nbuf_data_is_ipv6_pkt(v19) )
        {
          _qdf_nbuf_data_set_ipv6_tc(*(_QWORD *)(a1 + 224), v17);
        }
      }
    }
    else
    {
LABEL_9:
      local_bh_enable_6();
    }
  }
  return 0;
}
