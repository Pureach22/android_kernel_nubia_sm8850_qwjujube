__int64 __fastcall qcom_add_ssr_subdev(__int64 a1, _QWORD *a2, const char *a3)
{
  unsigned __int64 subsys; // x0
  unsigned __int64 v6; // x21

  subsys = qcom_ssr_get_subsys(a3);
  if ( subsys >= 0xFFFFFFFFFFFFF001LL )
    return dev_err(a1 + 56, "Failed to add ssr subdevice\n");
  v6 = subsys;
  init_timer_key(a2 + 7, &ssr_notif_timeout_handler, 0, 0, 0);
  a2[2] = ssr_notify_prepare;
  a2[3] = ssr_notify_start;
  a2[12] = v6;
  a2[4] = ssr_notify_stop;
  a2[5] = ssr_notify_unprepare;
  return rproc_add_subdev(a1, a2);
}
