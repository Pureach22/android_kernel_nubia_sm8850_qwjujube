__int64 __fastcall pe_handle_probe_req_frames(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  __int64 v11; // x20
  unsigned int v12; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-38h] BYREF
  __int64 v14; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v15)(double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = nullptr;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, unsigned int *))scheduler_get_queue_size)(21, &v12)
    || v12 >= 0x97 )
  {
    v11 = jiffies;
    if ( pe_handle_probe_req_frames___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Dropping probe req frame, queue size %d",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "pe_handle_probe_req_frames",
        v12);
      pe_handle_probe_req_frames___last_ticks = v11;
    }
    result = 16;
  }
  else
  {
    LOWORD(v13) = 5044;
    HIDWORD(v13) = 0;
    v14 = a1;
    v15 = pe_mc_process_handler;
    result = scheduler_post_message_debug(
               0x35u,
               0x35u,
               21,
               (unsigned __int16 *)&v13,
               0x587u,
               (__int64)"pe_handle_probe_req_frames");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
