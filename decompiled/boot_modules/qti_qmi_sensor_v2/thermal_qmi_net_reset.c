__int64 __fastcall thermal_qmi_net_reset(__int64 result)
{
  _QWORD *v1; // x23
  _QWORD *i; // x24

  v1 = *(_QWORD **)(result + 360);
  for ( i = (_QWORD *)(result + 360); v1 != i; v1 = (_QWORD *)*v1 )
  {
    if ( *((_BYTE *)v1 - 8) == 1 )
    {
      qmi_ts_request((__int64)(v1 - 7), 1);
      result = qmi_ts_request((__int64)(v1 - 7), 0);
      if ( (_DWORD)result )
        result = printk(&unk_821A, "qti_qmi_sensor_v2", "thermal_qmi_net_reset");
    }
  }
  return result;
}
