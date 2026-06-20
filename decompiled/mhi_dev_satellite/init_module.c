__int64 init_module()
{
  _QWORD *v0; // x0
  _QWORD *v1; // x23
  unsigned int v2; // w19
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // [xsp+8h] [xbp-28h] BYREF
  __int64 v6; // [xsp+10h] [xbp-20h]
  __int64 v7; // [xsp+18h] [xbp-18h]
  __int64 v8; // [xsp+20h] [xbp-10h]
  __int64 v9; // [xsp+28h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = (_QWORD *)_kmalloc_cache_noprof(kfree, 3520, 288);
  if ( !v0 )
  {
    result = 4294967284LL;
    goto LABEL_7;
  }
  mhi_sat_driver_2 = 1;
  mhi_sat_driver_1 = (__int64)v0;
  v1 = v0;
  *v0 = "adsp";
  v7 = 0;
  v8 = 0;
  v5 = 0;
  v6 = 0;
  _mutex_init(v0 + 4, "&subsys->cntrl_mutex", &mhi_sat_init___key);
  *((_DWORD *)v1 + 20) = 0;
  v1[2] = v1 + 2;
  v1[3] = v1 + 2;
  scnprintf(&v5, 32, "mhi_sat_%s", (const char *)*v1);
  v1[11] = ipc_log_context_create(10, &v5, 0);
  v1[12] = "cdsp";
  v7 = 0;
  v8 = 0;
  v5 = 0;
  v6 = 0;
  _mutex_init(v1 + 16, "&subsys->cntrl_mutex", &mhi_sat_init___key);
  *((_DWORD *)v1 + 44) = 0;
  v1[14] = v1 + 14;
  v1[15] = v1 + 14;
  scnprintf(&v5, 32, "mhi_sat_%s", (const char *)v1[12]);
  v1[23] = ipc_log_context_create(10, &v5, 0);
  v1[24] = "slpi";
  v7 = 0;
  v8 = 0;
  v5 = 0;
  v6 = 0;
  _mutex_init(v1 + 28, "&subsys->cntrl_mutex", &mhi_sat_init___key);
  *((_DWORD *)v1 + 68) = 0;
  v1[26] = v1 + 26;
  v1[27] = v1 + 26;
  scnprintf(&v5, 32, "mhi_sat_%s", (const char *)v1[24]);
  v1[35] = ipc_log_context_create(10, &v5, 0);
  v2 = _register_rpmsg_driver(&mhi_sat_rpmsg_driver, &_this_module);
  if ( v2 )
    goto LABEL_5;
  result = _mhi_driver_register(&mhi_sat_dev_driver, &_this_module);
  if ( (_DWORD)result )
  {
    v2 = result;
    unregister_rpmsg_driver(&mhi_sat_rpmsg_driver);
LABEL_5:
    v4 = mhi_sat_driver_1;
    ipc_log_context_destroy(*(_QWORD *)(mhi_sat_driver_1 + 88));
    ipc_log_context_destroy(*(_QWORD *)(v4 + 184));
    ipc_log_context_destroy(*(_QWORD *)(v4 + 280));
    kfree(mhi_sat_driver_1);
    result = v2;
    mhi_sat_driver_1 = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
