__int64 __fastcall wma_shutdown_notifier_cb(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  __int64 v12; // [xsp+8h] [xbp-38h] BYREF
  __int64 *v13; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v14)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v15)(); // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[3];
  v16 = 0;
  v17 = 0;
  v14 = nullptr;
  v15 = nullptr;
  v12 = 0;
  v13 = nullptr;
  ucfg_pmo_psoc_wakeup_host_event_received(v2);
  wmi_stop(*a1, v3, v4, v5, v6, v7, v8, v9, v10);
  v13 = a1;
  v14 = wma_cleanup_vdev_resp_and_hold_req;
  v15 = wma_cleanup_vdev_resp_and_hold_req_flush_cb;
  result = scheduler_post_message_debug(
             0x36u,
             0x36u,
             73,
             (unsigned __int16 *)&v12,
             0x8FEu,
             (__int64)"wma_shutdown_notifier_cb");
  _ReadStatusReg(SP_EL0);
  return result;
}
