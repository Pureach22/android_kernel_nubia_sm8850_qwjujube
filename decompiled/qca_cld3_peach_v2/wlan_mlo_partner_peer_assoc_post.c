__int64 __fastcall wlan_mlo_partner_peer_assoc_post(__int64 result)
{
  __int64 v1; // x24
  __int64 v2; // x22
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  __int64 v12; // x19
  __int64 v13; // x20
  __int64 v14; // x23
  __int64 v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 784);
  if ( v1 )
  {
    v2 = result;
    qdf_mutex_acquire(v1 + 120);
    if ( *(_DWORD *)(v1 + 200) )
    {
      result = qdf_mutex_release(v1 + 120);
    }
    else
    {
      v11 = *(_QWORD *)(v1 + 16);
      v12 = *(_QWORD *)(v1 + 192);
      v13 = 0;
      *(_DWORD *)(v1 + 200) = 1;
      if ( v11 && v11 != v2 )
      {
        if ( (*(_BYTE *)(v11 + 64) & 0x40) != 0 )
        {
          v13 = 0;
        }
        else if ( (unsigned int)wlan_objmgr_peer_try_get_ref(v11, 0x5Au, v3, v4, v5, v6, v7, v8, v9, v10) )
        {
          v13 = 0;
        }
        else
        {
          v13 = v11;
        }
      }
      v14 = *(_QWORD *)(v1 + 56);
      v15 = 0;
      if ( v14 && v14 != v2 )
      {
        if ( (*(_BYTE *)(v14 + 64) & 0x40) != 0 )
        {
          v15 = 0;
        }
        else if ( (unsigned int)wlan_objmgr_peer_try_get_ref(
                                  *(_QWORD *)(v1 + 56),
                                  0x5Au,
                                  v3,
                                  v4,
                                  v5,
                                  v6,
                                  v7,
                                  v8,
                                  v9,
                                  v10) )
        {
          v15 = 0;
        }
        else
        {
          v15 = v14;
        }
      }
      result = qdf_mutex_release(v1 + 120);
      if ( v13 )
      {
        v32[0] = v13;
        result = mlo_msgq_post(1, v12, v32);
        if ( (_DWORD)result )
          result = wlan_objmgr_peer_release_ref(v13, 0x5Au, v16, v17, v18, v19, v20, v21, v22, v23);
      }
      if ( v15 )
      {
        v32[0] = v15;
        result = mlo_msgq_post(1, v12, v32);
        if ( (_DWORD)result )
          result = wlan_objmgr_peer_release_ref(v15, 0x5Au, v24, v25, v26, v27, v28, v29, v30, v31);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
