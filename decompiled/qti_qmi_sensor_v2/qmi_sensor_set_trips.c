__int64 __fastcall qmi_sensor_set_trips(__int64 a1, int a2, int a3)
{
  __int64 v3; // x19
  int v4; // w8
  __int64 result; // x0
  unsigned int v6; // w19

  v3 = *(_QWORD *)(a1 + 1048);
  if ( *(_DWORD *)(v3 + 84) == a3 && *(_DWORD *)(v3 + 88) == a2 )
    return 0;
  v4 = *(unsigned __int8 *)(v3 + 48);
  *(_DWORD *)(v3 + 84) = a3;
  *(_DWORD *)(v3 + 88) = a2;
  if ( v4 != 1 )
    return 0;
  result = qmi_ts_request(v3, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v6 = result;
    printk(&unk_8460, "qti_qmi_sensor_v2", "qmi_sensor_set_trips");
    return v6;
  }
  return result;
}
