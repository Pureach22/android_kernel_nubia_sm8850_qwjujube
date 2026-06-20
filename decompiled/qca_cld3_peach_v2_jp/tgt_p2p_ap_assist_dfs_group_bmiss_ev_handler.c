__int64 __fastcall tgt_p2p_ap_assist_dfs_group_bmiss_ev_handler(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v27)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v28)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = nullptr;
  v28 = nullptr;
  v25 = 0;
  v26 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    v13 = _qdf_mem_malloc(0x10u, "tgt_p2p_ap_assist_dfs_group_bmiss_ev_handler", 533);
    if ( v13 )
    {
      *(_QWORD *)v13 = v12;
      LOWORD(v25) = 6;
      *(_BYTE *)(v13 + 8) = a2;
      v14 = v13;
      v26 = v13;
      v27 = p2p_process_evt;
      v28 = p2p_event_flush_callback;
      result = scheduler_post_message_debug(
                 0x4Eu,
                 0x4Eu,
                 73,
                 (unsigned __int16 *)&v25,
                 0x222u,
                 (__int64)"tgt_p2p_ap_assist_dfs_group_bmiss_ev_handler");
      if ( (_DWORD)result )
      {
        v24 = result;
        qdf_trace_msg(
          0x4Eu,
          8u,
          "p2p failed to post msg (%d), status (%d)",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          6,
          (unsigned int)result);
        _qdf_mem_free(v14);
        result = v24;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: p2p soc object is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "tgt_p2p_ap_assist_dfs_group_bmiss_ev_handler");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
