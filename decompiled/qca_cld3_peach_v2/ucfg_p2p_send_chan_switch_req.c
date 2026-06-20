__int64 __fastcall ucfg_p2p_send_chan_switch_req(
        __int64 a1,
        char a2,
        char a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  __int64 v25; // x0
  __int64 v26; // x19
  __int64 result; // x0
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // [xsp+8h] [xbp-38h] BYREF
  __int64 v38; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v39)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v40; // [xsp+20h] [xbp-20h]
  __int64 v41; // [xsp+28h] [xbp-18h]
  __int64 v42; // [xsp+30h] [xbp-10h]
  __int64 v43; // [xsp+38h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = 0;
  v39 = nullptr;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  if ( a2 == -1 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: Invalid VDEV", a5, a6, a7, a8, a9, a10, a11, a12, "ucfg_p2p_send_chan_switch_req");
    result = 4;
  }
  else
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v24 = comp_private_obj;
      v25 = _qdf_mem_malloc(0x10u, "ucfg_p2p_send_chan_switch_req", 594);
      if ( v25 )
      {
        *(_QWORD *)v25 = v24;
        LOWORD(v37) = 7;
        *(_BYTE *)(v25 + 8) = a2;
        *(_BYTE *)(v25 + 9) = a3;
        *(_BYTE *)(v25 + 10) = a4;
        v26 = v25;
        v38 = v25;
        v39 = p2p_process_cmd;
        result = scheduler_post_message_debug(
                   0x33u,
                   0x4Eu,
                   72,
                   (unsigned __int16 *)&v37,
                   0x25Fu,
                   (__int64)"ucfg_p2p_send_chan_switch_req");
        if ( (_DWORD)result )
        {
          v28 = result;
          _qdf_mem_free(v26);
          qdf_trace_msg(0x4Eu, 8u, "p2p chan switch post msg fail %d", v29, v30, v31, v32, v33, v34, v35, v36, v28);
          result = v28;
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
        "%s: p2p soc context is NULL",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "ucfg_p2p_send_chan_switch_req");
      result = 16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
