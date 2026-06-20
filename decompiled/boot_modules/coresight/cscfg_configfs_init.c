__int64 __fastcall cscfg_configfs_init(_QWORD *a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  __int64 *v5; // x20
  __int64 *v6; // x1
  __int64 *v7; // x1

  if ( !a1 )
    return 4294967274LL;
  v2 = cscfg_device(a1);
  v3 = (_QWORD *)devm_kmalloc(v2, 40, 3520);
  if ( !v3 )
    return 4294967284LL;
  *v3 = &_this_module;
  v4 = v3;
  config_item_set_name(a1 + 123, "cs-syscfg");
  a1[131] = v4;
  config_group_init(a1 + 123);
  _mutex_init(a1 + 140, "&subsys->su_mutex", &cscfg_configfs_init___key);
  config_group_init(&cscfg_configs_grp);
  v5 = a1 + 136;
  v6 = (__int64 *)a1[137];
  if ( a1 + 136 == &qword_990 || v6 == &qword_990 || (__int64 *)*v6 != v5 )
  {
    _list_add_valid_or_report(&qword_990, v6);
  }
  else
  {
    a1[137] = &qword_990;
    qword_990 = (__int64)(a1 + 136);
    qword_998 = (__int64)v6;
    *v6 = (__int64)&qword_990;
  }
  config_group_init(&cscfg_features_grp);
  v7 = (__int64 *)a1[137];
  if ( v5 == &qword_A18 || v7 == &qword_A18 || (__int64 *)*v7 != v5 )
  {
    _list_add_valid_or_report(&qword_A18, v7);
  }
  else
  {
    a1[137] = &qword_A18;
    qword_A18 = (__int64)(a1 + 136);
    qword_A20 = (__int64)v7;
    *v7 = (__int64)&qword_A18;
  }
  return configfs_register_subsystem(a1 + 123);
}
