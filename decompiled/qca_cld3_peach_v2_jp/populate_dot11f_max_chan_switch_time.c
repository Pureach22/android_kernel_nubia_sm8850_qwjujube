__int64 __fastcall populate_dot11f_max_chan_switch_time(__int64 a1, char *a2, __int64 a3)
{
  __int64 result; // x0
  char v6; // w8
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wlan_utils_get_vdev_remaining_channel_switch_time(*(_QWORD *)(a3 + 16));
  v7 = result;
  if ( (_DWORD)result
    || (wlan_util_vdev_mgr_compute_max_channel_switch_time(*(_QWORD *)(a3 + 16), (int *)&v7), (result = v7) != 0) )
  {
    a2[3] = (unsigned int)(1000 * result) >> 26;
    v6 = 1;
    a2[1] = (unsigned int)(1000 * result) >> 10;
    a2[2] = (unsigned int)(1000 * result) >> 18;
  }
  else
  {
    v6 = 0;
  }
  *a2 = v6;
  _ReadStatusReg(SP_EL0);
  return result;
}
