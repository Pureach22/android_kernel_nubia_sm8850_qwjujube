__int64 __fastcall cm_flush_pending_request(__int64 a1, int a2, char a3)
{
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned __int8 v9; // w22
  _QWORD *i; // x1
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x26
  int v20; // w5
  __int64 v21; // x0
  __int64 v22; // x27
  int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w1
  __int64 v33; // x9
  __int64 v34; // x0
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x0
  int v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  _QWORD *v48; // [xsp+0h] [xbp-40h] BYREF
  _QWORD *v49; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v50[6]; // [xsp+10h] [xbp-30h] BYREF

  v50[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)a1;
  v48 = nullptr;
  v49 = nullptr;
  v7 = *(_QWORD *)(v6 + 152);
  if ( v7 )
    v8 = *(_QWORD *)(v7 + 80);
  else
    v8 = 0;
  v9 = cm_roam_offload_enabled(v8);
  qdf_mutex_acquire(a1 + 120);
  qdf_list_peek_front((_QWORD *)(a1 + 96), &v49);
  for ( i = v49; i; v49 = i )
  {
    qdf_list_peek_next((_QWORD *)(a1 + 96), i, &v48);
    v19 = (__int64)v49;
    v20 = *((_DWORD *)v49 + 4);
    if ( (v20 & 0xF000000) == a2
      && (((a2 == 251658240) & v9) != 0 || v20 != *(_DWORD *)(a1 + 88))
      && ((a3 & 1) == 0 || *((_BYTE *)v49 + 20) == 1) )
    {
      switch ( a2 )
      {
        case 251658240:
          cm_free_roam_req_mem(v49 + 3);
          break;
        case 218103808:
          memset(v50, 0, 40);
          qdf_mem_set(v50, 0x28u, 0);
          v35 = *(_QWORD *)(v19 + 28);
          v36 = *(_QWORD *)(v19 + 36);
          v37 = *(_QWORD *)a1;
          LODWORD(v50[0]) = *(_DWORD *)(v19 + 16);
          v38 = *(_DWORD *)(v19 + 44);
          *(_QWORD *)((char *)v50 + 4) = v35;
          *(_QWORD *)((char *)&v50[1] + 4) = v36;
          HIDWORD(v50[2]) = v38;
          mlme_cm_osif_disconnect_complete(v37, v50);
          if ( (v50[0] & 0x10000000) != 0 )
            cm_reset_active_cm_id(*(_QWORD *)a1, v50[0], v39, v40, v41, v42, v43, v44, v45, v46);
          --*(_BYTE *)(a1 + 184);
          break;
        case 201326592:
          v21 = _qdf_mem_malloc(0xA0u, "cm_handle_connect_flush", 622);
          if ( v21 )
          {
            *(_DWORD *)(v21 + 52) = 16;
            v22 = v21;
            *(_DWORD *)(v21 + 4) = *(_DWORD *)(v19 + 16);
            *(_BYTE *)v21 = *(_BYTE *)(*(_QWORD *)a1 + 104LL);
            if ( *(_BYTE *)(v19 + 20) )
              v23 = 14;
            else
              v23 = 2;
            *(_DWORD *)(v21 + 56) = v23;
            cm_fill_connect_resp_from_req();
            cm_notify_connect_complete((__int64 *)a1, v22, 0);
            v32 = *(_DWORD *)(v22 + 4);
            if ( (v32 & 0x10000000) != 0 )
              cm_reset_active_cm_id(*(_QWORD *)a1, v32, v24, v25, v26, v27, v28, v29, v30, v31);
            _qdf_mem_free(v22);
          }
          --*(_BYTE *)(a1 + 185);
          cm_free_connect_req_mem(v19 + 24);
          v33 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
          if ( v33 )
            v34 = *(_QWORD *)(v33 + 80);
          else
            v34 = 0;
          wlan_ll_sap_switch_bearer_on_sta_connect_complete(v34, *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL));
          break;
        default:
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x: Invalid prefix %x",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "cm_flush_pending_request",
            *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL));
          break;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: ",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "cm_flush_pending_request",
        *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
        *(unsigned int *)(v19 + 16),
        v48);
      cm_remove_cmd_from_serialization((__int64 *)a1, *(_DWORD *)(v19 + 16));
      qdf_list_remove_node(a1 + 96, (_QWORD *)v19);
      _qdf_mem_free(v19);
    }
    i = v48;
    v48 = nullptr;
  }
  result = qdf_mutex_release(a1 + 120);
  _ReadStatusReg(SP_EL0);
  return result;
}
