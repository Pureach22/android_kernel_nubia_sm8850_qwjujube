__int64 __fastcall wma_allow_suspend_after_obss_color_change(
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
  __int64 result; // x0
  __int64 v10; // x19

  result = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v10 = result;
    qdf_runtime_pm_allow_suspend((__int64 *)(result + 24800));
    return qdf_wake_lock_release(v10 + 24600, 0);
  }
  return result;
}
