__int64 __fastcall wma_create_objmgr_peer(__int64 a1, __int64 a2, unsigned __int8 *a3, int a4)
{
  unsigned __int8 v7; // w22
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  _QWORD *peer_by_mac; // x0
  int v19; // w21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x20
  _DWORD *v38; // x25
  unsigned int v39; // w1
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  __int64 v49; // x4

  v7 = a2;
  _ReadStatusReg(SP_EL0);
  v8 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 24),
         a2,
         8);
  if ( v8 )
  {
    v17 = v8;
    if ( a3 )
    {
      if ( *(_DWORD *)a3 | *((unsigned __int16 *)a3 + 2) )
      {
        peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), a3, 8u);
        if ( peer_by_mac )
        {
          v19 = *(unsigned __int8 *)(peer_by_mac[11] + 104LL);
          wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v9, v10, v11, v12, v13, v14, v15, v16);
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Peer %02x:%02x:%02x:**:**:%02x already exists on vdev %d, current vdev %d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "wma_create_objmgr_peer",
            *a3,
            a3[1],
            a3[2],
            a3[5],
            v19,
            v7);
          v37 = 0;
LABEL_26:
          wlan_objmgr_vdev_release_ref(v17, 8u, v28, v29, v30, v31, v32, v33, v34, v35, v36);
          goto LABEL_27;
        }
      }
    }
    v38 = *(_DWORD **)(*(_QWORD *)(a1 + 520) + 488LL * v7);
    if ( !v38 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Couldn't find vdev for VDEV_%d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "wma_get_obj_mgr_peer_type",
        v7);
LABEL_14:
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid obj peer type. Unable to create peer %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wma_create_objmgr_peer",
        0);
      v37 = 0;
      goto LABEL_26;
    }
    if ( a4 == 2 )
    {
      v39 = 6;
    }
    else
    {
      if ( a4 == 6 )
      {
        if ( v38[4] == 16 )
          v39 = 14;
        else
          v39 = 12;
        goto LABEL_25;
      }
      if ( (unsigned int)qdf_mem_cmp((char *)v38 + 74, a3, 6u) && (unsigned int)qdf_mem_cmp(v38 + 20, a3, 6u) )
      {
        v48 = *(_QWORD *)(a1 + 520) + 488LL * v7;
        v49 = *(unsigned int *)(v48 + 164);
        if ( (int)v49 > 2 )
        {
          if ( (_DWORD)v49 == 3 )
          {
            v39 = 9;
          }
          else
          {
            if ( (_DWORD)v49 != 7 )
            {
LABEL_31:
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Couldn't find peertype for type %d and sub type %d",
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                "wma_get_obj_mgr_peer_type",
                v49,
                *(unsigned int *)(v48 + 168));
              goto LABEL_14;
            }
            v39 = 10;
          }
        }
        else
        {
          if ( (_DWORD)v49 != 1 )
          {
            if ( (_DWORD)v49 == 2 )
            {
              if ( *(_DWORD *)(v48 + 168) == 2 )
                v39 = 3;
              else
                v39 = 2;
              goto LABEL_25;
            }
            goto LABEL_31;
          }
          v39 = 4;
        }
      }
      else
      {
        v39 = 1;
      }
    }
LABEL_25:
    v37 = wlan_objmgr_peer_obj_create(v17, v39, a3, v9, v10, v11, v12, v13, v14, v15, v16);
    goto LABEL_26;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid obj vdev. Unable to create peer",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wma_create_objmgr_peer");
  v37 = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v37;
}
