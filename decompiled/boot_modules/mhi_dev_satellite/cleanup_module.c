__int64 cleanup_module()
{
  __int64 v0; // x0
  unsigned int v1; // w22
  __int64 *v2; // x21
  __int64 v3; // t1
  __int64 result; // x0

  unregister_rpmsg_driver(&mhi_sat_rpmsg_driver);
  v0 = mhi_sat_driver_1;
  if ( mhi_sat_driver_2 == 1 )
  {
    v1 = 0;
    v2 = (__int64 *)(mhi_sat_driver_1 + 88);
    do
    {
      v3 = *v2;
      v2 += 12;
      ipc_log_context_destroy(v3);
      if ( mhi_sat_driver_2 != 1 )
        break;
    }
    while ( v1++ < 2 );
    v0 = mhi_sat_driver_1;
  }
  result = kfree(v0);
  mhi_sat_driver_1 = 0;
  return result;
}
