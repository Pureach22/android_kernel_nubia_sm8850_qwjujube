__int64 __fastcall sme_update_fine_time_measurement_capab(__int64 a1, unsigned int a2, unsigned int a3)
{
  char v6; // w8
  char v7; // w9
  char v8; // w8
  __int64 result; // x0

  ucfg_wifi_pos_set_ftm_cap(*(_QWORD *)(a1 + 21624), a3);
  v6 = *(_BYTE *)(a1 + 20224);
  v7 = *(_BYTE *)(a1 + 17487);
  if ( a3 )
  {
    *(_BYTE *)(a1 + 20224) = v6 | 4;
    v8 = v7 | 4;
  }
  else
  {
    *(_BYTE *)(a1 + 20224) = v6 & 0xFB;
    v8 = v7 & 0xFB;
  }
  *(_BYTE *)(a1 + 17487) = v8;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    wlan_roam_update_cfg(*(_QWORD *)(a1 + 21624), a2, 0x22u);
    return qdf_mutex_release(a1 + 12848);
  }
  return result;
}
