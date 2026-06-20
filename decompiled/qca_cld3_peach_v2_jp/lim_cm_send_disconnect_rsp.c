__int64 __fastcall lim_cm_send_disconnect_rsp(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v16)(__int64); // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = nullptr;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  result = _qdf_mem_malloc(0x10u, "lim_cm_send_disconnect_rsp", 840);
  if ( result )
  {
    *(_BYTE *)result = a2;
    v5 = result;
    *(_QWORD *)(result + 8) = *(_QWORD *)(a1 + 21552);
    v15 = result;
    v16 = cm_handle_disconnect_resp;
    result = scheduler_post_message_debug(
               0x35u,
               0x48u,
               72,
               (unsigned __int16 *)&v14,
               0x353u,
               (__int64)"lim_cm_send_disconnect_rsp");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to post disconnect rsp to sme vdev_id %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "lim_cm_send_disconnect_rsp",
        a2);
      result = _qdf_mem_free(v5);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
