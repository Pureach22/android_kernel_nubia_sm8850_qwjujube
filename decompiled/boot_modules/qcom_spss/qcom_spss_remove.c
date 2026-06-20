__int64 __fastcall qcom_spss_remove(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD **)(a1 + 168);
  rproc_del(v1[1]);
  if ( v1[27] )
  {
    rproc_remove_subdev(v1[1], v1 + 19);
    kfree_const(v1[25]);
  }
  qcom_remove_ssr_subdev(v1[1], v1 + 33);
  qcom_remove_sysmon_subdev(v1[46]);
  v2 = *v1;
  device_wakeup_disable(*v1);
  device_set_wakeup_capable(v2, 0);
  return rproc_free(v1[1]);
}
