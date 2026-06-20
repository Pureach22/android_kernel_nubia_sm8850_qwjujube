__int64 __fastcall tdls_peers_deleted_notification(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 result; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v36)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v37)(); // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = nullptr;
  v37 = nullptr;
  v34 = 0;
  v35 = 0;
  v4 = _qdf_mem_malloc(0x10u, "tdls_peers_deleted_notification", 1927);
  if ( v4 )
  {
    v5 = v4;
    v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 17);
    if ( v6 )
    {
      *(_BYTE *)(v5 + 12) = a2;
      v15 = v6;
      *(_DWORD *)(v5 + 8) = 0x10000;
      *(_QWORD *)v5 = v6;
      v35 = v5;
      v36 = tdls_process_cmd;
      v37 = tdls_post_msg_flush_cb;
      LOWORD(v34) = 13;
      result = scheduler_post_message_debug(
                 0,
                 0,
                 72,
                 (unsigned __int16 *)&v34,
                 0x7A4u,
                 (__int64)"tdls_peers_deleted_notification");
      if ( (_DWORD)result )
      {
        wlan_objmgr_vdev_release_ref(v15, 0x11u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
        _qdf_mem_free(v5);
        qdf_trace_msg(
          0,
          1u,
          "%s: message post failed ",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "tdls_peers_deleted_notification");
        result = 16;
      }
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: vdev not exist for the vdev id %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "tdls_peers_deleted_notification",
        (unsigned __int8)a2);
      _qdf_mem_free(v5);
      result = 4;
    }
  }
  else
  {
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
