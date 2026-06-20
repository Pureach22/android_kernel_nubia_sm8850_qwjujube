__int64 __fastcall thermal_qmi_net_reset(__int64 result)
{
  __int64 *v1; // x19
  __int64 v2; // x20

  v1 = *(__int64 **)(result + 360);
  v2 = result + 360;
  while ( v1 != (__int64 *)v2 )
  {
    if ( *((_BYTE *)v1 - 8) == 1 )
      result = qmi_tmd_send_state_request((__int64)(v1 - 10), *((_DWORD *)v1 + 6));
    v1 = (__int64 *)*v1;
  }
  return result;
}
