__int64 __fastcall ucfg_set_tdls_secoffchanneloffset(__int64 a1, int a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  unsigned int ref; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+8h] [xbp-38h] BYREF
  __int64 v43; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v44)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v45)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+28h] [xbp-18h]
  __int64 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = nullptr;
  v45 = nullptr;
  v42 = 0;
  v43 = 0;
  v4 = _qdf_mem_malloc(0x18u, "ucfg_set_tdls_secoffchanneloffset", 1217);
  if ( v4 )
  {
    v13 = v4;
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0x11u, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( ref )
    {
      v23 = ref;
      qdf_trace_msg(
        0,
        2u,
        "%s: can't get vdev",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "ucfg_set_tdls_secoffchanneloffset");
LABEL_7:
      _qdf_mem_free(v13);
      result = v23;
      goto LABEL_8;
    }
    *(_DWORD *)(v13 + 8) = a2;
    *(_QWORD *)(v13 + 16) = wlan_tdls_offchan_parms_callback;
    *(_QWORD *)v13 = a1;
    v43 = v13;
    v44 = tdls_process_cmd;
    LOWORD(v42) = 23;
    v45 = ucfg_tdls_post_msg_flush_cb;
    result = scheduler_post_message_debug(
               0x33u,
               0,
               72,
               (unsigned __int16 *)&v42,
               0x4D3u,
               (__int64)"ucfg_set_tdls_secoffchanneloffset");
    if ( (_DWORD)result )
    {
      v23 = result;
      qdf_trace_msg(
        0,
        2u,
        "%s: post set secoffchan offset msg fail",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "ucfg_set_tdls_secoffchanneloffset");
      wlan_objmgr_vdev_release_ref(a1, 0x11u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
      goto LABEL_7;
    }
  }
  else
  {
    result = 2;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
