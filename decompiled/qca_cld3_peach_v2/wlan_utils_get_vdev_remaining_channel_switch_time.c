__int64 __fastcall wlan_utils_get_vdev_remaining_channel_switch_time(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  int v3; // w19
  int system_time; // w0

  result = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( result )
  {
    v2 = *(_QWORD *)(result + 264);
    if ( v2 )
    {
      v3 = v2 + *(_DWORD *)(result + 256);
      system_time = qdf_mc_timer_get_system_time();
      return (v3 - system_time) & (unsigned int)~((v3 - system_time) >> 31);
    }
    else
    {
      return 0;
    }
  }
  return result;
}
