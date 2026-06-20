__int64 __fastcall dp_softap_inspect_dhcp_packet(__int64 a1, __int64 a2, int a3)
{
  __int64 v6; // x19
  __int64 context; // x0
  __int64 v8; // x26
  _BYTE *v9; // x20
  int dhcp_subtype; // w25
  _QWORD *peer_by_mac; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w0
  int v40; // w8
  __int64 result; // x0
  __int64 v42; // x8
  _DWORD *v43; // x8
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w8
  const char *v65; // x2
  unsigned int v66; // w1
  unsigned int v67; // w21
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // [xsp+8h] [xbp-18h] BYREF
  int v77; // [xsp+10h] [xbp-10h]
  __int64 v78; // [xsp+18h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 32);
  v77 = 0;
  v76 = 0;
  context = _cds_get_context(71, "dp_softap_inspect_dhcp_packet");
  if ( (*(_DWORD *)(v6 + 28) | 2) != 3 )
    goto LABEL_13;
  if ( a3 == 1 )
  {
    v8 = context;
    if ( _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224)) )
      goto LABEL_5;
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
  if ( a3 )
    goto LABEL_13;
  v8 = context;
  if ( (*(_BYTE *)(a2 + 71) & 0x78) != 0x20 )
    goto LABEL_13;
LABEL_5:
  v9 = *(_BYTE **)(a2 + 224);
  dhcp_subtype = _qdf_nbuf_data_get_dhcp_subtype(v9);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(**(_QWORD **)v6, v9 + 70, 0x61u);
  if ( !peer_by_mac )
  {
    if ( v8 && *(_QWORD *)v8 && (v42 = *(_QWORD *)(*(_QWORD *)v8 + 72LL)) != 0 )
    {
      v43 = *(_DWORD **)(v42 + 184);
      if ( v43 )
      {
        if ( *(v43 - 1) != 1021873010 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _BYTE *, _QWORD, __int64 *))v43)(v8, v9 + 70, 0, &v76);
        if ( HIDWORD(v76) )
        {
          if ( (unsigned __int8)v77 == 1 )
          {
            if ( v9 == (_BYTE *)-70LL )
            {
              v46 = 0;
              v44 = 0;
              v45 = 0;
              v47 = 0;
            }
            else
            {
              v44 = (unsigned __int8)v9[70];
              v45 = (unsigned __int8)v9[71];
              v46 = (unsigned __int8)v9[72];
              v47 = (unsigned __int8)v9[75];
            }
            v65 = "%s: mld peer %02x:%02x:%02x:**:**:%02x no dhcp inspect";
            v66 = 8;
LABEL_35:
            qdf_trace_msg(
              0x45u,
              v66,
              v65,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "dp_softap_inspect_dhcp_packet",
              v44,
              v45,
              v46,
              v47);
            result = 4;
            goto LABEL_14;
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "cdp_peer_get_info_by_peer_addr");
    }
    if ( v9 == (_BYTE *)-70LL )
    {
      v46 = 0;
      v44 = 0;
      v45 = 0;
      v47 = 0;
    }
    else
    {
      v44 = (unsigned __int8)v9[70];
      v45 = (unsigned __int8)v9[71];
      v46 = (unsigned __int8)v9[72];
      v47 = (unsigned __int8)v9[75];
    }
    v65 = "%s: Peer %02x:%02x:%02x:**:**:%02x object not found";
    v66 = 2;
    goto LABEL_35;
  }
  v20 = (__int64)peer_by_mac;
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Eu);
  if ( comp_private_obj )
  {
    v30 = comp_private_obj;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: ENTER: type=%d, phase=%d, nego_status=%d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dp_softap_inspect_dhcp_packet",
      (unsigned int)dhcp_subtype,
      *(unsigned int *)(comp_private_obj + 16),
      *(unsigned int *)(comp_private_obj + 20));
    v39 = 0;
    if ( dhcp_subtype <= 7 )
    {
      switch ( dhcp_subtype )
      {
        case 5:
          if ( a3 == 1 )
          {
            if ( *(_DWORD *)(v30 + 20) )
            {
              *(_DWORD *)(v30 + 16) = 1;
            }
            else
            {
              v39 = dp_post_dhcp_ind(a1, (unsigned __int8 *)v30, 1, v31, v32, v33, v34, v35, v36, v37, v38);
              *(_DWORD *)(v30 + 16) = 1;
              if ( v39 )
                goto LABEL_52;
            }
            v39 = 0;
            *(_DWORD *)(v30 + 20) = 1;
LABEL_52:
            v67 = v39;
            wlan_objmgr_peer_release_ref(v20, 0x61u, v31, v32, v33, v34, v35, v36, v37, v38);
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: EXIT: phase=%d, nego_status=%d",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "dp_softap_inspect_dhcp_packet",
              *(unsigned int *)(v30 + 16),
              *(unsigned int *)(v30 + 20));
            result = v67;
            goto LABEL_14;
          }
          break;
        case 6:
          if ( a3 == 1 )
          {
            if ( *(_DWORD *)(v30 + 20)
              || (v39 = dp_post_dhcp_ind(a1, (unsigned __int8 *)v30, 1, v31, v32, v33, v34, v35, v36, v37, v38)) == 0 )
            {
              v39 = 0;
              *(_DWORD *)(v30 + 20) = 1;
            }
            goto LABEL_50;
          }
          break;
        case 7:
          v40 = 2;
          v39 = 0;
LABEL_51:
          *(_DWORD *)(v30 + 16) = v40;
          goto LABEL_52;
        default:
          goto LABEL_52;
      }
      v39 = 0;
      goto LABEL_52;
    }
    if ( (unsigned int)(dhcp_subtype - 8) < 2 )
    {
      v64 = *(_DWORD *)(v30 + 20);
      *(_DWORD *)(v30 + 16) = 0;
      if ( v64 == 1 )
      {
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: Setting NOTIFY_COMP Flag",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "dp_softap_inspect_dhcp_packet");
        *(_BYTE *)(a2 + 61) |= 1u;
      }
      v39 = 0;
      *(_DWORD *)(v30 + 20) = 0;
      goto LABEL_52;
    }
    if ( dhcp_subtype != 12 )
      goto LABEL_52;
    v39 = 0;
    if ( a3 != 1 )
      goto LABEL_52;
LABEL_50:
    v40 = 3;
    goto LABEL_51;
  }
  qdf_trace_msg(0x45u, 2u, "%s: peer is null", v22, v23, v24, v25, v26, v27, v28, v29, "dp_get_peer_priv_obj");
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Peer priv ctx not found",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "dp_softap_inspect_dhcp_packet");
  wlan_objmgr_peer_release_ref(v20, 0x61u, v56, v57, v58, v59, v60, v61, v62, v63);
  result = 4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
