__int64 qmi_ts_svc_arrive()
{
  __int64 result; // x0
  __int64 v1; // x20
  int v2; // [xsp+24h] [xbp-Ch]
  __int64 v3; // [xsp+28h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  result = _kmalloc_cache_noprof(qmi_response_type_v01_ei, 3520, 3180);
  v1 = result;
  if ( result )
  {
    if ( (((__int64 (*)(void))qmi_ts_send_request)() & 0x80000000) != 0 )
      printk(&unk_8250, "qti_qmi_sensor_v2", "verify_sensor_and_register");
    result = kfree(v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
