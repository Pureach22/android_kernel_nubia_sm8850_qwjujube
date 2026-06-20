__int64 __fastcall target_if_cp_stats_send_peer_stats_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  int v12; // w9
  __int64 result; // x0
  _DWORD v14[2]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v15; // [xsp+Ch] [xbp-14h] BYREF
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15 = 0;
  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    v12 = *(_DWORD *)(a2 + 16);
    v14[0] = 1;
    v14[1] = v12;
    qdf_mem_copy(&v15, (const void *)(a2 + 24), 6u);
    v16 = 0;
    result = wmi_unified_peer_stats_request_send(v11, v14);
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: wmi_handle is null.",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_cp_stats_send_peer_stats_req");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
