__int64 __fastcall wlan_delayed_peer_obj_free_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 )
  {
    *(_DWORD *)(a1 + 1256) = 0;
    *(_QWORD *)(a1 + 1328) = wlan_objmgr_peer_obj_free_work;
    *(_QWORD *)(a1 + 1296) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 1264) = 0;
    *(_QWORD *)(a1 + 1336) = a1;
    *(_QWORD *)(a1 + 1304) = a1 + 1304;
    *(_QWORD *)(a1 + 1312) = a1 + 1304;
    *(_QWORD *)(a1 + 1320) = _qdf_defer_func;
    *(_DWORD *)(a1 + 1344) = 0;
    *(_QWORD *)(a1 + 1272) = a1 + 1272;
    *(_QWORD *)(a1 + 1280) = a1 + 1272;
    *(_QWORD *)(a1 + 1288) = 0x4000000000LL;
    qdf_trace_msg(
      0x57u,
      8u,
      "%s: Delayed peer obj free init successfully",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_delayed_peer_obj_free_init");
    return 0;
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_delayed_peer_obj_free_init");
    return 16;
  }
}
