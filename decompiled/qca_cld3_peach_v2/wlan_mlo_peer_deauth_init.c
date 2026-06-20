__int64 __fastcall wlan_mlo_peer_deauth_init(__int64 result, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x24
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  __int64 v15; // x19
  __int64 v16; // x23
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char v26; // w8
  int v27; // w0
  __int64 v28; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_31;
  v3 = result;
  qdf_mutex_acquire(result + 120);
  if ( *(_DWORD *)(v3 + 200) == 2 )
  {
    result = qdf_mutex_release(v3 + 120);
    goto LABEL_31;
  }
  v14 = *(_QWORD *)(v3 + 16);
  v15 = *(_QWORD *)(v3 + 192);
  if ( v14 )
  {
    if ( (unsigned int)wlan_objmgr_peer_try_get_ref(*(_QWORD *)(v3 + 16), 0x5Au, v6, v7, v8, v9, v10, v11, v12, v13) )
      v16 = 0;
    else
      v16 = v14;
    v17 = *(_QWORD *)(v3 + 56);
    if ( !v17 )
      goto LABEL_11;
  }
  else
  {
    v16 = 0;
    v17 = *(_QWORD *)(v3 + 56);
    if ( !v17 )
      goto LABEL_11;
  }
  if ( (unsigned int)wlan_objmgr_peer_try_get_ref(v17, 0x5Au, v6, v7, v8, v9, v10, v11, v12, v13) )
    v17 = 0;
LABEL_11:
  *(_DWORD *)(v3 + 200) = 2;
  result = qdf_mutex_release(v3 + 120);
  if ( !v16 )
    goto LABEL_22;
  if ( v16 == a2 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v16 + 96) + 16LL) != 1
      || (v28 = v16, result = mlo_msgq_post(3, v15, &v28), (_DWORD)result) )
    {
      result = wlan_objmgr_peer_release_ref(v16, 0x5Au, v18, v19, v20, v21, v22, v23, v24, v25);
    }
LABEL_22:
    v26 = 0;
    if ( !v17 )
      goto LABEL_31;
LABEL_23:
    if ( v17 == a2 )
      v26 = 1;
    if ( (v26 & 1) != 0 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v17 + 96) + 16LL) != 1 )
        goto LABEL_30;
      v27 = 3;
      v28 = v17;
    }
    else
    {
      v28 = v17;
      v27 = 4;
      v29 = a3;
    }
    result = mlo_msgq_post(v27, v15, &v28);
    if ( !(_DWORD)result )
      goto LABEL_31;
LABEL_30:
    result = wlan_objmgr_peer_release_ref(v17, 0x5Au, v18, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_31;
  }
  v28 = v16;
  v29 = a3;
  result = mlo_msgq_post(4, v15, &v28);
  if ( (_DWORD)result )
    result = wlan_objmgr_peer_release_ref(v16, 0x5Au, v18, v19, v20, v21, v22, v23, v24, v25);
  v26 = 1;
  if ( v17 )
    goto LABEL_23;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
