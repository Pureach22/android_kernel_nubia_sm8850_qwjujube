__int64 __fastcall glink_subdev_start(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 subsys; // x0
  unsigned __int64 v4; // x20
  unsigned __int64 v6; // x8

  v2 = qcom_glink_smem_register(a1[7], a1[8]);
  a1[9] = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1[7], "Failed to register glink smem\n");
    v6 = a1[9];
    if ( v6 <= 0xFFFFFFFFFFFFF000LL )
      return 0;
    else
      return (unsigned int)v6;
  }
  else
  {
    a1[10] = glink_early_ssr_notifier_event;
    subsys = qcom_ssr_get_subsys(a1[6]);
    v4 = subsys;
    if ( subsys <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = subsys + 528;
      srcu_notifier_chain_register(subsys + 528, a1 + 10);
    }
    a1[13] = v4;
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(a1[7], "Failed to register for SSR notifier\n");
      a1[13] = 0;
    }
    return qcom_glink_smem_start(a1[9]);
  }
}
