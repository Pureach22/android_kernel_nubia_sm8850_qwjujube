__int64 __fastcall qcom_ssr_get_subsys(const char *a1)
{
  _UNKNOWN **v2; // x22
  __int64 v3; // x19
  _QWORD *v4; // x1

  mutex_lock(&qcom_ssr_subsys_lock);
  v2 = &qcom_ssr_subsystem_list;
  while ( 1 )
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &qcom_ssr_subsystem_list )
      break;
    v3 = (__int64)(v2 - 131);
    if ( !strcmp((const char *)*(v2 - 131), a1) )
      goto LABEL_11;
  }
  v3 = _kmalloc_cache_noprof(auxiliary_device_init, 3520, 1064);
  if ( v3 )
  {
    *(_QWORD *)v3 = kstrdup_const(a1, 3264);
    srcu_init_notifier_head(v3 + 8);
    srcu_init_notifier_head(v3 + 528);
    v4 = off_290;
    if ( off_290 == (_UNKNOWN *)(v3 + 1048) || *(_UNKNOWN ***)off_290 != &qcom_ssr_subsystem_list )
    {
      _list_add_valid_or_report();
    }
    else
    {
      off_290 = (_UNKNOWN *)(v3 + 1048);
      *(_QWORD *)(v3 + 1048) = &qcom_ssr_subsystem_list;
      *(_QWORD *)(v3 + 1056) = v4;
      *v4 = v3 + 1048;
    }
  }
  else
  {
    v3 = -12;
  }
LABEL_11:
  mutex_unlock(&qcom_ssr_subsys_lock);
  return v3;
}
