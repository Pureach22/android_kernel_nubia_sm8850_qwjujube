__int64 __fastcall wlan_tdls_teardown_links(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x20
  unsigned int v12; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v31; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v32)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v33)(); // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = nullptr;
  v33 = nullptr;
  v30 = 0;
  v31 = nullptr;
  v2 = _qdf_mem_malloc(8u, "wlan_tdls_teardown_links", 68);
  if ( v2 )
  {
    v11 = (_QWORD *)v2;
    wlan_objmgr_psoc_get_ref(a1, 0x10u, v3, v4, v5, v6, v7, v8, v9, v10);
    *v11 = a1;
    v31 = v11;
    v32 = tdls_process_cmd;
    v33 = tdls_teardown_flush_cb;
    LOWORD(v30) = 17;
    v12 = scheduler_post_message_debug(
            0x33u,
            0,
            72,
            (unsigned __int16 *)&v30,
            0x51u,
            (__int64)"wlan_tdls_teardown_links");
    if ( v12 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: post msg fail, %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_tdls_teardown_links",
        v12);
      wlan_objmgr_psoc_release_ref(a1, 0x10u, v21, v22, v23, v24, v25, v26, v27, v28);
      _qdf_mem_free((__int64)v11);
    }
  }
  else
  {
    v12 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
