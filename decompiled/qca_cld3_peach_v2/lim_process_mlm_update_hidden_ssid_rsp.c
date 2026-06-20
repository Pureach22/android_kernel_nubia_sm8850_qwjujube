__int64 __fastcall lim_process_mlm_update_hidden_ssid_rsp(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 session_by_vdev_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 result; // x0
  __int64 v24; // x4
  const char *v25; // x2
  _QWORD v26[7]; // [xsp+8h] [xbp-38h] BYREF

  v10 = (unsigned __int8)a2;
  v26[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v26, 0, 48);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: hidden ssid resp for vdev_id:%d ",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_mlm_update_hidden_ssid_rsp",
    (unsigned __int8)a2);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
  {
    v25 = "%s: vdev_id:%d Session Doesn't exist";
    v24 = v10;
    goto LABEL_5;
  }
  v22 = session_by_vdev_id;
  sch_set_fixed_beacon_fields(a1, session_by_vdev_id);
  lim_send_beacon(a1, v22);
  LOWORD(v26[0]) = 5271;
  HIDWORD(v26[0]) = v10;
  result = scheduler_post_message_debug(
             0x35u,
             0x34u,
             52,
             (unsigned __int16 *)v26,
             0xA0Fu,
             (__int64)"lim_process_mlm_update_hidden_ssid_rsp");
  if ( (_DWORD)result )
  {
    v24 = (unsigned int)result;
    v25 = "%s: Failed to post message %u";
LABEL_5:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v25,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "lim_process_mlm_update_hidden_ssid_rsp",
               v24);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
