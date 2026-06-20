__int64 __fastcall cm_handle_scan_ch_list_data(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a1;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 5280;
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)&v10,
             0x168u,
             (__int64)"cm_handle_scan_ch_list_data");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to post msg to SME",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "cm_handle_scan_ch_list_data");
    _qdf_mem_free(v11);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
