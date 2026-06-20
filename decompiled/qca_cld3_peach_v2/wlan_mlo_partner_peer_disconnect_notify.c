__int64 __fastcall wlan_mlo_partner_peer_disconnect_notify(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x21
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v13; // x19
  int ref; // w0
  __int64 v15; // x8
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 784);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 96);
    if ( v2 )
    {
      if ( (*(_BYTE *)(v2 + 67) & 2) == 0 )
      {
        v3 = result;
        qdf_mutex_acquire(v1 + 120);
        if ( *(_DWORD *)(v1 + 200) == 2 || (*(_DWORD *)(v1 + 200) = 2, !*(_DWORD *)(v2 + 16)) )
        {
          result = qdf_mutex_release(v1 + 120);
        }
        else
        {
          v12 = *(_QWORD *)(v1 + 16);
          v13 = *(_QWORD *)(v1 + 192);
          if ( v12 )
          {
            if ( v12 == v3 )
            {
              v15 = v3;
              v12 = 0;
            }
            else
            {
              ref = wlan_objmgr_peer_try_get_ref(*(_QWORD *)(v1 + 16), 0x5Au, v4, v5, v6, v7, v8, v9, v10, v11);
              v15 = v3;
              if ( ref )
                v12 = 0;
            }
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: link peer is null",
              v4,
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              "wlan_mlo_partner_peer_disconnect_notify");
            v15 = v3;
          }
          v16 = *(_QWORD *)(v1 + 56);
          if ( v16 )
          {
            if ( v16 == v15 )
            {
              v16 = 0;
            }
            else if ( (unsigned int)wlan_objmgr_peer_try_get_ref(
                                      *(_QWORD *)(v1 + 56),
                                      0x5Au,
                                      v4,
                                      v5,
                                      v6,
                                      v7,
                                      v8,
                                      v9,
                                      v10,
                                      v11) )
            {
              v16 = 0;
            }
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: link peer is null",
              v4,
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              "wlan_mlo_partner_peer_disconnect_notify");
          }
          result = qdf_mutex_release(v1 + 120);
          if ( v12 )
          {
            if ( *(_DWORD *)(*(_QWORD *)(v12 + 96) + 16LL) != 1
              || (v25[0] = v12, result = mlo_msgq_post(3, v13, v25), (_DWORD)result) )
            {
              result = wlan_objmgr_peer_release_ref(v12, 0x5Au, v17, v18, v19, v20, v21, v22, v23, v24);
            }
          }
          if ( v16 )
          {
            if ( *(_DWORD *)(*(_QWORD *)(v16 + 96) + 16LL) != 1
              || (v25[0] = v16, result = mlo_msgq_post(3, v13, v25), (_DWORD)result) )
            {
              result = wlan_objmgr_peer_release_ref(v16, 0x5Au, v17, v18, v19, v20, v21, v22, v23, v24);
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
