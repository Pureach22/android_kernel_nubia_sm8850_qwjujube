__int64 __fastcall policy_mgr_get_valid_chan_weights(__int64 a1, _DWORD *a2, unsigned int a3, __int64 a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  bool v26; // w26
  unsigned __int64 v27; // x24
  _DWORD *v28; // x27
  __int64 result; // x0
  __int64 v30; // x8
  __int64 v31; // x10
  unsigned __int64 i; // x9
  __int64 v33; // x13
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int8 v42[4]; // [xsp+4h] [xbp-CCh] BYREF
  _QWORD v43[22]; // [xsp+8h] [xbp-C8h] BYREF
  int v44; // [xsp+B8h] [xbp-18h]
  __int64 v45; // [xsp+C0h] [xbp-10h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  memset(v43, 0, sizeof(v43));
  v42[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_get_valid_chan_weights");
    result = 16;
    goto LABEL_28;
  }
  v17 = context;
  qdf_mem_set(a2 + 206, 0x66u, 0);
  qdf_mutex_acquire(v17 + 56);
  if ( (a3 & 0xFFFFFFFE) == 2 )
  {
    v26 = (unsigned int)policy_mgr_get_beaconing_mode_count(a1, nullptr)
       || (unsigned int)policy_mgr_mode_specific_connection_count(a1, 2, nullptr);
LABEL_6:
    if ( a2[205] )
    {
      v27 = 0;
      v28 = a2 + 103;
      do
      {
        if ( v27 == 102 )
LABEL_39:
          __break(0x5512u);
        if ( !(v26 | ((policy_mgr_is_concurrency_allowed(a1, a3, v28[v27], 3, 0, 0) & 1) == 0)) )
          *((_BYTE *)v28 + v27 + 412) = 1;
        ++v27;
      }
      while ( v27 < (unsigned int)a2[205] );
    }
    if ( (a3 & 0xFFFFFFFE) != 2 )
      policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v43, v42[0], v18, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_16;
  }
  if ( !a3 && (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) )
  {
    if ( (((__int64 (__fastcall *)(__int64))policy_mgr_concurrent_sta_on_different_mac)(a1) & 1) != 0
      && (wlan_cm_same_band_sta_allowed(a1) & 1) == 0
      && a2[102] )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: sta follow pcl strictly",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "policy_mgr_get_valid_chan_weights");
      v26 = 1;
    }
    else
    {
      v26 = 0;
    }
    if ( a4 )
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
        a1,
        *(unsigned __int8 *)(a4 + 104),
        v43,
        v42);
    else
      ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info)(
        a1,
        0,
        1,
        v43,
        v42);
    goto LABEL_6;
  }
LABEL_16:
  qdf_mutex_release(v17 + 56);
  v30 = (unsigned int)a2[205];
  if ( (_DWORD)v30 )
  {
    v31 = (unsigned int)a2[102];
    for ( i = 0; i != v30; ++i )
    {
      if ( (_DWORD)v31 )
      {
        if ( i > 0x65 )
          goto LABEL_39;
        v33 = 0;
        while ( 1 )
        {
          if ( v33 == 102 )
            goto LABEL_39;
          if ( a2[i + 103] == a2[v33] )
            break;
          if ( v31 == ++v33 )
            goto LABEL_19;
        }
        *((_BYTE *)a2 + i + 824) = *((_BYTE *)a2 + v33 + 926);
      }
LABEL_19:
      ;
    }
  }
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
