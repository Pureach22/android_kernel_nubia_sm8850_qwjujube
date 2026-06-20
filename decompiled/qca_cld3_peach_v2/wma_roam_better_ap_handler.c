__int64 __fastcall wma_roam_better_ap_handler(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v16)(); // [xsp+18h] [xbp-28h]
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
  result = _qdf_mem_malloc(0x10u, "wma_roam_better_ap_handler", 2653);
  if ( result )
  {
    v13 = *(_QWORD *)(a1 + 32);
    *(_BYTE *)result = a2;
    *(_QWORD *)(result + 8) = v13;
    v15 = result;
    v16 = wlan_cm_host_roam_start;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Posting ROam start ind to connection manager, vdev %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wma_roam_better_ap_handler",
      a2);
    result = scheduler_post_message_debug(
               0x36u,
               0x48u,
               21,
               (unsigned __int16 *)&v14,
               0xA69u,
               (__int64)"wma_roam_better_ap_handler");
    if ( (_DWORD)result )
      result = _qdf_mem_free(v15);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
