__int64 __fastcall qmi_sensor_read(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x19
  _DWORD *v3; // x20

  v2 = *(_QWORD *)(a1 + 1048);
  if ( *(_BYTE *)(v2 + 48) == 1 && !in_suspend )
  {
    v3 = a2;
    qmi_ts_request(v2, 1);
    a2 = v3;
  }
  *a2 = *(_DWORD *)(v2 + 80);
  return 0;
}
