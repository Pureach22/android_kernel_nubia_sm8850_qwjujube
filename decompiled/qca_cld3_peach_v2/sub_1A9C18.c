__int64 __fastcall sub_1A9C18(__int64 a1, __int64 a2, __int64 a3)
{
  _ReadStatusReg(CNTVCTSS_EL0);
  return target_if_vdev_mgr_rsp_timer_stop(a1, a2, a3);
}
