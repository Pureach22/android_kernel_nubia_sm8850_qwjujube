__int64 __fastcall dp_softap_inspect_tx_eap_pkt(__int64 result, __int64 a2, char a3)
{
  int v3; // w8
  __int64 v4; // x21
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x2
  __int64 **v17; // x20
  unsigned __int8 *v18; // x21
  _QWORD *peer_by_mac; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x19
  __int64 peer_priv_obj; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  __int64 v47; // x1
  unsigned __int64 v54; // x10
  unsigned __int64 v57; // x9

  if ( (*(_BYTE *)(a2 + 71) & 0x78) == 8 )
  {
    v3 = (*(_BYTE *)(a2 + 68) & 4) != 0 ? *(unsigned __int16 *)(a2 + 66) : 0;
    if ( (unsigned int)(*(_DWORD *)(a2 + 112) + v3) >= 0x13 )
    {
      v4 = *(_QWORD *)(result + 32);
      v7 = result;
      if ( (cds_get_driver_state() & 8) != 0
        || (cds_get_driver_state() & 0x10) != 0
        || (result = cds_get_driver_state(), (result & 6) != 0) )
      {
        v16 = "%s: Recovery/(Un)load in Progress. Ignore!!!";
        return qdf_trace_msg(0x45u, 8u, v16, v8, v9, v10, v11, v12, v13, v14, v15, "dp_softap_inspect_tx_eap_pkt");
      }
      if ( *(_DWORD *)(v4 + 28) == 3 )
      {
        if ( *(_DWORD *)(v7 + 84) != 1 )
        {
          v16 = "%s: BSS intf state is not START";
          return qdf_trace_msg(0x45u, 8u, v16, v8, v9, v10, v11, v12, v13, v14, v15, "dp_softap_inspect_tx_eap_pkt");
        }
        v17 = (__int64 **)v4;
        v18 = *(unsigned __int8 **)(a2 + 224);
        if ( !v18[15] && v18[18] == 4 )
        {
          peer_by_mac = wlan_objmgr_get_peer_by_mac(**v17, *(_BYTE **)(a2 + 224), 0x61u);
          if ( peer_by_mac )
          {
            v28 = (__int64)peer_by_mac;
            peer_priv_obj = dp_get_peer_priv_obj((__int64)peer_by_mac);
            if ( peer_priv_obj )
            {
              v38 = peer_priv_obj;
              if ( (a3 & 1) != 0 )
              {
                if ( v18 )
                {
                  v39 = *v18;
                  v40 = v18[1];
                  v41 = v18[2];
                  v42 = v18[5];
                }
                else
                {
                  v41 = 0;
                  v39 = 0;
                  v40 = 0;
                  v42 = 0;
                }
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: eap_failure frm tx done%02x:%02x:%02x:**:**:%02x",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "dp_softap_inspect_tx_eap_pkt",
                  v39,
                  v40,
                  v41,
                  v42);
                _X8 = (unsigned __int64 *)(v38 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v54 = __ldxr(_X8);
                while ( __stxr(v54 & 0xFFFFFFFFFFFFFFFELL, _X8) );
                qdf_event_set((__int64)(v17 + 452), v47);
              }
              else
              {
                if ( v18 )
                {
                  v43 = *v18;
                  v44 = v18[1];
                  v45 = v18[2];
                  v46 = v18[5];
                }
                else
                {
                  v45 = 0;
                  v43 = 0;
                  v44 = 0;
                  v46 = 0;
                }
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: eap_failure frm tx pending%02x:%02x:%02x:**:**:%02x",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "dp_softap_inspect_tx_eap_pkt",
                  v43,
                  v44,
                  v45,
                  v46);
                qdf_event_reset((__int64)(v17 + 452));
                _X8 = (unsigned __int64 *)(v38 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v57 = __ldxr(_X8);
                while ( __stxr(v57 | 1, _X8) );
                *(_BYTE *)(a2 + 61) |= 1u;
              }
            }
            return wlan_objmgr_peer_release_ref(v28, 0x61u, v30, v31, v32, v33, v34, v35, v36, v37);
          }
          else
          {
            return qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: Peer object not found",
                     v20,
                     v21,
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     "dp_softap_inspect_tx_eap_pkt");
          }
        }
      }
    }
  }
  return result;
}
