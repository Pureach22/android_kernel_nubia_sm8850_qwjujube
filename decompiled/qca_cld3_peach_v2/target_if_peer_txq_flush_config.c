__int64 __fastcall target_if_peer_txq_flush_config(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        unsigned __int8 a4,
        int a5,
        unsigned int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  int v14; // w19
  const char *v15; // x2
  __int64 result; // x0
  _QWORD *peer_by_mac; // x0
  __int64 v23; // x9
  __int64 v24; // x19
  __int64 v25; // x20
  unsigned int v26; // w0
  unsigned int v27; // w9
  bool v28; // zf
  __int64 v29; // x3
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x9
  __int64 v40; // x20
  unsigned int v41; // w9
  unsigned int v42; // w20
  const char *v43; // x3
  _BYTE v44[12]; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v45; // [xsp+14h] [xbp-Ch]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v15 = "%s: Invalid params";
    goto LABEL_9;
  }
  v14 = a4;
  if ( !(a4 | a5) )
  {
    v15 = "%s: no ac/tid mask setting";
    goto LABEL_9;
  }
  if ( !a5 || a6 != 3 )
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a3, 0x61u);
    if ( !peer_by_mac )
    {
      v15 = "%s: Peer not found in the list";
      goto LABEL_9;
    }
    if ( !a5 )
    {
      if ( !v14 )
      {
        result = 0;
        goto LABEL_10;
      }
      v27 = (v14 << 31 >> 31) & 9;
      if ( (v14 & 2) != 0 )
        v27 |= 6u;
      if ( (v14 & 4) != 0 )
        v27 |= 0x30u;
      v28 = (v14 & 8) == 0;
      v24 = (__int64)peer_by_mac;
      if ( v28 )
        v29 = v27;
      else
        v29 = v27 | 0xC0;
      v30 = send_peer_txq_flush_tids(a1, a3, a2, v29);
      goto LABEL_42;
    }
    if ( a6 == 1 )
    {
      v23 = *(_QWORD *)(a1 + 2800);
      v24 = (__int64)peer_by_mac;
      *(_QWORD *)&v44[4] = 0;
      if ( v23 )
      {
        v25 = *(_QWORD *)(v23 + 16);
        if ( v25 )
        {
          v44[4] = a2;
          *(_DWORD *)v44 = a5;
          qdf_mem_copy(&v44[5], a3, 6u);
          v26 = wmi_unified_peer_flush_tids_send(v25);
LABEL_41:
          v30 = qdf_status_to_os_return(v26);
LABEL_42:
          v42 = v30;
          goto LABEL_43;
        }
      }
      v43 = "send_peer_txq_flush_tids";
    }
    else
    {
      v39 = *(_QWORD *)(a1 + 2800);
      *(_QWORD *)v44 = 0;
      if ( v39 )
      {
        v40 = *(_QWORD *)(v39 + 16);
        if ( v40 )
        {
          if ( a6 == 2 )
            v41 = 1;
          else
            v41 = 2;
          v24 = (__int64)peer_by_mac;
          if ( !a6 )
            v41 = 0;
          if ( v41 < 2 )
          {
            *(_DWORD *)&v44[8] = a5;
            v45 = v41;
            qdf_mem_copy(&v44[1], a3, 6u);
            v26 = wmi_unified_peer_txq_flush_config_send(v40);
            goto LABEL_41;
          }
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: Invalid flush policy : %d",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "send_peer_txq_flush_conf",
            a6);
          v42 = -22;
LABEL_43:
          wlan_objmgr_peer_release_ref(v24, 0x61u, v31, v32, v33, v34, v35, v36, v37, v38);
          result = v42;
          goto LABEL_10;
        }
      }
      v24 = (__int64)peer_by_mac;
      v43 = "send_peer_txq_flush_conf";
    }
    qdf_trace_msg(0x49u, 2u, "%s: Invalid wmi handle", a7, a8, a9, a10, a11, a12, a13, a14, v43);
    v42 = -22;
    goto LABEL_43;
  }
  v15 = "%s: Invalid flush policy";
LABEL_9:
  qdf_trace_msg(0x49u, 2u, v15, a7, a8, a9, a10, a11, a12, a13, a14, "target_if_peer_txq_flush_config");
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
