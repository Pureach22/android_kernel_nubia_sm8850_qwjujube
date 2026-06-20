__int64 __fastcall tgt_interop_issues_ap_info_callback(__int64 a1, const void *a2)
{
  void *v3; // x0
  __int64 v4; // x20
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v17)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v18)(); // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = nullptr;
  v18 = nullptr;
  v15 = 0;
  v16 = 0;
  v3 = (void *)_qdf_mem_malloc(0x20u, "tgt_interop_issues_ap_info_callback", 74);
  if ( v3 )
  {
    v4 = (__int64)v3;
    qdf_mem_copy(v3, a2, 0x20u);
    v16 = v4;
    v17 = wlan_interop_issues_ap_info_cbk;
    v18 = wlan_interop_issues_ap_flush_cbk;
    result = scheduler_post_message_debug(
               0x6Cu,
               0x6Cu,
               73,
               (unsigned __int16 *)&v15,
               0x56u,
               (__int64)"tgt_interop_issues_ap_info_callback");
    if ( (_DWORD)result )
    {
      v14 = result;
      qdf_trace_msg(
        0x6Cu,
        2u,
        "%s: scheduler msg posting failed",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "tgt_interop_issues_ap_info_callback");
      _qdf_mem_free(v16);
      result = v14;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
