__int64 __fastcall ieee80211_stop_device(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  v3 = ieee80211_handle_queued_frames(a1);
  local_bh_enable_4(v3);
  wiphy_work_cancel(*(_QWORD *)(a1 + 72), a1 + 1408);
  _flush_workqueue(*(_QWORD *)(a1 + 472));
  wiphy_work_flush(*(_QWORD *)(a1 + 72), 0);
  return drv_stop(a1);
}
