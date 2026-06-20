__int64 __fastcall ucfg_dlm_wifi_off(
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
  __int64 pdev_obj; // x20
  __int64 psoc_obj; // x0
  __int64 v12; // x21
  const char *v13; // x2

  if ( a1 )
  {
    pdev_obj = dlm_get_pdev_obj(a1);
    psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
    if ( pdev_obj && psoc_obj )
    {
      v12 = psoc_obj;
      if ( !(unsigned int)qdf_mutex_acquire(pdev_obj) )
      {
        dlm_flush_reject_ap_list(pdev_obj);
        dlm_send_reject_ap_list_to_fw(a1, pdev_obj + 64, v12 + 8);
        return qdf_mutex_release(pdev_obj);
      }
      v13 = "%s: failed to acquire reject_ap_list_lock";
    }
    else
    {
      v13 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
    }
  }
  else
  {
    v13 = "%s: pdev is NULL";
  }
  return qdf_trace_msg(0x6Du, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_dlm_wifi_off");
}
