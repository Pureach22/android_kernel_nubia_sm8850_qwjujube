__int64 __fastcall wlan_mlo_partner_peer_create_failed_notify(__int64 result)
{
  __int64 v1; // x20
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x21
  __int64 v11; // x19
  __int64 v12; // x22
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_18;
  v1 = result;
  qdf_mutex_acquire(result + 120);
  if ( *(_DWORD *)(v1 + 200) == 2 )
  {
    result = qdf_mutex_release(v1 + 120);
    goto LABEL_18;
  }
  v10 = *(_QWORD *)(v1 + 16);
  v11 = *(_QWORD *)(v1 + 192);
  *(_DWORD *)(v1 + 200) = 2;
  if ( v10 )
  {
    if ( (unsigned int)wlan_objmgr_peer_try_get_ref(v10, 0x5Au, v2, v3, v4, v5, v6, v7, v8, v9) )
      v12 = 0;
    else
      v12 = v10;
    v13 = *(_QWORD *)(v1 + 56);
    if ( v13 )
    {
LABEL_9:
      if ( (unsigned int)wlan_objmgr_peer_try_get_ref(v13, 0x5Au, v2, v3, v4, v5, v6, v7, v8, v9) )
        v13 = 0;
    }
  }
  else
  {
    v12 = 0;
    v13 = *(_QWORD *)(v1 + 56);
    if ( v13 )
      goto LABEL_9;
  }
  result = qdf_mutex_release(v1 + 120);
  if ( v12 )
  {
    v22[0] = v12;
    result = mlo_msgq_post(2, v11, v22);
    if ( (_DWORD)result )
      result = wlan_objmgr_peer_release_ref(v12, 0x5Au, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  if ( v13 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v13 + 96) + 16LL) != 1
      || (v22[0] = v13, result = mlo_msgq_post(3, v11, v22), (_DWORD)result) )
    {
      result = wlan_objmgr_peer_release_ref(v13, 0x5Au, v14, v15, v16, v17, v18, v19, v20, v21);
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
