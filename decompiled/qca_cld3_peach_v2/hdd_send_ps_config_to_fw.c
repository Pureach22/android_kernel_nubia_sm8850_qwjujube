__int64 __fastcall hdd_send_ps_config_to_fw(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x20
  __int64 v30; // x26
  __int64 v31; // x20
  __int64 v32; // x20
  __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x10

  result = _hdd_validate_adapter((__int64)a1, (__int64)"hdd_send_ps_config_to_fw", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
    return result;
  v19 = a1[3];
  result = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1[6604] + 32LL), v11, v12, v13, v14, v15, v16, v17, v18);
  if ( (result & 1) == 0 )
    return sme_ps_update(*(_QWORD *)(v19 + 16), *(unsigned __int8 *)(a1[6604] + 8LL));
  if ( a1 )
  {
    v28 = a1[3];
    if ( v28 && (v29 = *(_QWORD *)(v28 + 16)) != 0 )
    {
      if ( (a1[205] & 1) != 0 )
      {
        v30 = (__int64)(a1 + 6605);
      }
      else
      {
        v30 = (__int64)(a1 + 7366);
        if ( a1 == (_QWORD *)-58928LL || (a1[205] & 2) == 0 )
        {
          v30 = (__int64)(a1 + 8127);
          if ( a1 == (_QWORD *)-65016LL || (a1[205] & 4) == 0 )
            return result;
        }
      }
      do
      {
        result = sme_ps_update(v29, *(unsigned __int8 *)(v30 + 8));
        if ( (unsigned __int8)(73 * ((unsigned int)(v30 - *(_DWORD *)v30 - 52840) >> 3) + 1) > 2u )
          break;
        v33 = (unsigned __int8)(73 * ((unsigned int)(v30 - *(_DWORD *)v30 - 52840) >> 3) + 1);
        v30 = 0;
        v34 = (__int64)&a1[761 * (unsigned int)v33 + 6605];
        do
        {
          if ( v30 )
            break;
          v35 = a1[205] >> v33++;
          v30 = (v35 << 63 >> 63) & v34;
          v34 += 6088;
        }
        while ( v33 != 3 );
      }
      while ( v30 );
    }
    else
    {
      v31 = jiffies;
      if ( hdd_send_mlo_ps_to_fw___last_ticks_72 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: null mac_handle pointer",
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   "hdd_send_mlo_ps_to_fw");
        hdd_send_mlo_ps_to_fw___last_ticks_72 = v31;
      }
    }
  }
  else
  {
    v32 = jiffies;
    if ( hdd_send_mlo_ps_to_fw___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: null hdd_adapter pointer",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "hdd_send_mlo_ps_to_fw");
      hdd_send_mlo_ps_to_fw___last_ticks = v32;
    }
  }
  return result;
}
