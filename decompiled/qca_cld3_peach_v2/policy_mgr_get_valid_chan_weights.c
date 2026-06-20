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
  __int64 v17; // x24
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  bool v26; // w27
  unsigned __int64 v27; // x28
  _DWORD *v28; // x26
  unsigned int v29; // w25
  unsigned int conc_ext_flags; // w0
  __int64 result; // x0
  __int64 v32; // x8
  __int64 v33; // x10
  unsigned __int64 i; // x9
  __int64 v35; // x13
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // [xsp+4h] [xbp-DCh]
  __int64 v45; // [xsp+8h] [xbp-D8h]
  unsigned __int8 v46[4]; // [xsp+14h] [xbp-CCh] BYREF
  _QWORD v47[22]; // [xsp+18h] [xbp-C8h] BYREF
  int v48; // [xsp+C8h] [xbp-18h]
  __int64 v49; // [xsp+D0h] [xbp-10h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  memset(v47, 0, sizeof(v47));
  v46[0] = 0;
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
    v44 = 2;
    v45 = v17;
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
        v29 = v28[v27];
        conc_ext_flags = policy_mgr_get_conc_ext_flags(a4, 0, v18, v19, v20, v21, v22, v23, v24, v25);
        if ( !(v26 | ((policy_mgr_is_concurrency_allowed(a1, a3, v29, 3, conc_ext_flags, 0) & 1) == 0)) )
          *((_BYTE *)v28 + v27 + 412) = 1;
        ++v27;
      }
      while ( v27 < (unsigned int)a2[205] );
    }
    v17 = v45;
    if ( v44 != 2 )
      policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v47, v46[0], v18, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_16;
  }
  if ( !a3 && (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) )
  {
    if ( (policy_mgr_concurrent_sta_on_different_mac(a1) & 1) != 0
      && (wlan_cm_same_band_sta_allowed(a1) & 1) == 0
      && a2[102] )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: sta follow pcl strictly",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "policy_mgr_get_valid_chan_weights");
      v26 = 1;
    }
    else
    {
      v26 = 0;
    }
    v44 = a3 & 0xFFFFFFFE;
    v45 = v17;
    if ( a4 )
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
        a1,
        *(unsigned __int8 *)(a4 + 168),
        v47,
        v46);
    else
      ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info)(
        a1,
        0,
        1,
        v47,
        v46);
    goto LABEL_6;
  }
LABEL_16:
  qdf_mutex_release(v17 + 56);
  v32 = (unsigned int)a2[205];
  if ( (_DWORD)v32 )
  {
    v33 = (unsigned int)a2[102];
    for ( i = 0; i != v32; ++i )
    {
      if ( (_DWORD)v33 )
      {
        if ( i > 0x65 )
          goto LABEL_39;
        v35 = 0;
        while ( 1 )
        {
          if ( v35 == 102 )
            goto LABEL_39;
          if ( a2[i + 103] == a2[v35] )
            break;
          if ( v33 == ++v35 )
            goto LABEL_19;
        }
        *((_BYTE *)a2 + i + 824) = *((_BYTE *)a2 + v35 + 926);
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
