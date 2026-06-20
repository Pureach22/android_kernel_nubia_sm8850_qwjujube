__int64 __fastcall policy_mgr_get_pcl_ch_list_for_ll_sap(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        _BYTE *a5)
{
  __int64 context; // x0
  __int64 v11; // x21
  __int64 v12; // x7
  unsigned int v13; // w23
  char connection_info; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w2
  __int64 v25; // [xsp+0h] [xbp-30h] BYREF
  __int64 v26; // [xsp+8h] [xbp-28h]
  __int64 v27; // [xsp+10h] [xbp-20h]
  __int64 v28; // [xsp+18h] [xbp-18h]
  __int64 v29; // [xsp+20h] [xbp-10h] BYREF
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v29) = 0;
  LODWORD(v29) = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    ((void (__fastcall *)(__int64, _QWORD, __int64 *, char *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
      a1,
      (unsigned __int8)a3,
      &v25,
      (char *)&v29 + 4);
    v13 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))policy_mgr_get_pcl)(
            a1,
            6,
            a2,
            a2 + 512,
            a2 + 408,
            102,
            a3,
            v12,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30);
    connection_info = policy_mgr_get_connection_info(a1, a4);
    v23 = BYTE4(v29);
    *a5 = connection_info;
    if ( v23 )
      policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)&v25, v23, v15, v16, v17, v18, v19, v20, v21, v22);
    qdf_mutex_release(v11 + 56);
  }
  else
  {
    v13 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
