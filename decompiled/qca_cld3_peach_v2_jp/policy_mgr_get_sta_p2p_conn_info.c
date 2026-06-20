__int64 __fastcall policy_mgr_get_sta_p2p_conn_info(__int64 *a1, __int64 a2)
{
  __int64 v4; // x19
  int v5; // w22
  unsigned int v6; // w23
  __int64 v7; // x11
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x11
  __int64 v14; // x8
  __int64 v15; // x12
  __int64 v16; // x9
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x8
  __int64 v23; // x12
  __int64 v24; // x9
  __int64 v25; // x11

  v4 = (__int64)(a1 + 7);
  v5 = policy_mgr_mode_specific_connection_count(*a1, 1, nullptr);
  qdf_mutex_acquire(v4);
  if ( BYTE4(qword_81C458) == 1 )
  {
    if ( !v5 && (pm_conc_connection_list & 0xFFFFFFFE) == 4 && (wlan_nan_is_sta_p2p_ndp_supported(*a1) & 1) != 0 )
    {
      v6 = 0;
      if ( (qword_81C47C & 0x100000000LL) == 0 )
        goto LABEL_14;
      goto LABEL_11;
    }
    v6 = 1;
    *(_QWORD *)a2 = pm_conc_connection_list;
    v7 = qword_81C448;
    v8 = *(_QWORD *)&dword_81C450;
    v9 = qword_81C458;
    *(_DWORD *)(a2 + 32) = dword_81C460;
    *(_QWORD *)(a2 + 8) = v7;
    *(_QWORD *)(a2 + 16) = v8;
    *(_QWORD *)(a2 + 24) = v9;
  }
  else
  {
    v6 = 0;
  }
  if ( (qword_81C47C & 0x100000000LL) == 0 )
    goto LABEL_14;
  if ( v5 )
    goto LABEL_13;
LABEL_11:
  if ( (qword_81C464 & 0xFFFFFFFE) != 4 || (wlan_nan_is_sta_p2p_ndp_supported(*a1) & 1) == 0 )
  {
LABEL_13:
    v10 = a2 + 36LL * v6++;
    *(_QWORD *)v10 = qword_81C464;
    v11 = qword_81C46C;
    v12 = *(_QWORD *)&dword_81C474;
    v13 = qword_81C47C;
    *(_DWORD *)(v10 + 32) = dword_81C484;
    *(_QWORD *)(v10 + 8) = v11;
    *(_QWORD *)(v10 + 16) = v12;
    *(_QWORD *)(v10 + 24) = v13;
  }
LABEL_14:
  if ( BYTE4(qword_81C4A0) == 1 )
  {
    if ( !v5 && (qword_81C488 & 0xFFFFFFFE) == 4 && (wlan_nan_is_sta_p2p_ndp_supported(*a1) & 1) != 0 )
    {
      if ( (qword_81C4C4 & 0x100000000LL) == 0 )
        goto LABEL_26;
      goto LABEL_23;
    }
    v14 = a2 + 36LL * v6++;
    *(_QWORD *)v14 = qword_81C488;
    v15 = qword_81C490;
    v16 = *(_QWORD *)&dword_81C498;
    v17 = qword_81C4A0;
    *(_DWORD *)(v14 + 32) = dword_81C4A8;
    *(_QWORD *)(v14 + 8) = v15;
    *(_QWORD *)(v14 + 16) = v16;
    *(_QWORD *)(v14 + 24) = v17;
  }
  if ( (qword_81C4C4 & 0x100000000LL) == 0 )
    goto LABEL_26;
  if ( v5 )
  {
LABEL_25:
    v18 = a2 + 36LL * v6++;
    *(_QWORD *)v18 = qword_81C4AC;
    v19 = qword_81C4B4;
    v20 = *(_QWORD *)&dword_81C4BC;
    v21 = qword_81C4C4;
    *(_DWORD *)(v18 + 32) = dword_81C4CC;
    *(_QWORD *)(v18 + 8) = v19;
    *(_QWORD *)(v18 + 16) = v20;
    *(_QWORD *)(v18 + 24) = v21;
    goto LABEL_26;
  }
LABEL_23:
  if ( (qword_81C4AC & 0xFFFFFFFE) != 4 || (wlan_nan_is_sta_p2p_ndp_supported(*a1) & 1) == 0 )
    goto LABEL_25;
LABEL_26:
  if ( BYTE4(qword_81C4E8) == 1
    && (v5 || (qword_81C4D0 & 0xFFFFFFFE) != 4 || (wlan_nan_is_sta_p2p_ndp_supported(*a1) & 1) == 0) )
  {
    v22 = a2 + 36LL * v6++;
    *(_QWORD *)v22 = qword_81C4D0;
    v23 = qword_81C4D8;
    v24 = *(_QWORD *)&dword_81C4E0;
    v25 = qword_81C4E8;
    *(_DWORD *)(v22 + 32) = dword_81C4F0;
    *(_QWORD *)(v22 + 8) = v23;
    *(_QWORD *)(v22 + 16) = v24;
    *(_QWORD *)(v22 + 24) = v25;
  }
  qdf_mutex_release(v4);
  return v6;
}
