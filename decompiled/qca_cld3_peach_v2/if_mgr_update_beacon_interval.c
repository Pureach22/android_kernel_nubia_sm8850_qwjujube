__int64 __fastcall if_mgr_update_beacon_interval(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v5; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w22
  _DWORD *v16; // x0
  __int64 v17; // x21
  void *v18; // x0
  __int64 v19; // x8
  unsigned __int8 *v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int16 v41; // w8
  unsigned int v42; // w20
  _BYTE v43[4]; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-38h] BYREF
  __int64 v45; // [xsp+10h] [xbp-30h]
  __int64 v46; // [xsp+18h] [xbp-28h]
  __int64 v47; // [xsp+20h] [xbp-20h]
  __int64 v48; // [xsp+28h] [xbp-18h]
  __int64 v49; // [xsp+30h] [xbp-10h]
  __int64 v50; // [xsp+38h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *(_QWORD *)(a1 + 80);
  if ( result )
  {
    v5 = *(unsigned __int8 *)(a2 + 168);
    v43[0] = 0;
    policy_mgr_get_allow_mcc_go_diff_bi(result, v43);
    result = wlan_objmgr_vdev_try_get_bsspeer(a2, 0x4Eu);
    if ( result )
    {
      v15 = *(_DWORD *)(result + 68);
      result = wlan_objmgr_peer_release_ref(result, 0x4Eu, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( v15 != 3 )
      {
        if ( v43[0] == 4 && (*(_BYTE *)(a3 + 21) & 1) != 0 )
        {
          v48 = 0;
          v49 = 0;
          v46 = 0;
          v47 = 0;
          v44 = 0;
          v45 = 0;
          *(_BYTE *)(a3 + 21) = 0;
          v16 = (_DWORD *)_qdf_mem_malloc(0xEu, "if_mgr_send_chng_mcc_beacon_interval", 347);
          if ( v16 )
          {
            v17 = (__int64)v16;
            *v16 = 922664;
            v18 = (char *)v16 + 6;
            v19 = *(_QWORD *)(a2 + 216);
            if ( v19 )
              v20 = (unsigned __int8 *)(v19 + 32);
            else
              v20 = nullptr;
            qdf_mem_copy(v18, v20, 6u);
            if ( v20 )
            {
              v29 = *v20;
              v30 = v20[1];
              v31 = v20[2];
              v32 = v20[5];
            }
            else
            {
              v31 = 0;
              v29 = 0;
              v30 = 0;
              v32 = 0;
            }
            qdf_trace_msg(
              0x78u,
              8u,
              "%s: %02x:%02x:%02x:**:**:%02x",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "if_mgr_send_chng_mcc_beacon_interval",
              v29,
              v30,
              v31,
              v32);
            *(_BYTE *)(v17 + 12) = *(_BYTE *)(a2 + 168);
            qdf_trace_msg(
              0x78u,
              8u,
              "%s: session %d BeaconInterval %d",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "if_mgr_send_chng_mcc_beacon_interval");
            v41 = *(_WORD *)(a3 + 12);
            LOWORD(v44) = 5160;
            *(_WORD *)(v17 + 4) = v41;
            HIDWORD(v44) = 0;
            v45 = v17;
            result = scheduler_post_message_debug(
                       0x35u,
                       0x35u,
                       53,
                       (unsigned __int16 *)&v44,
                       0x170u,
                       (__int64)"if_mgr_send_chng_mcc_beacon_interval");
            if ( (_DWORD)result )
            {
              v42 = result;
              _qdf_mem_free(v17);
              result = v42;
            }
          }
          else
          {
            result = 2;
          }
          goto LABEL_18;
        }
        if ( (*(_BYTE *)(a3 + 21) & 1) != 0 )
        {
          result = wlan_sap_disconnect_all_p2p_client(v5);
LABEL_18:
          *(_DWORD *)(a3 + 16) = result;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
