__int64 __fastcall ml_nlink_init_disallow_modes(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BYTE v21[4]; // [xsp+14h] [xbp-3Ch] BYREF
  __int16 v22; // [xsp+18h] [xbp-38h] BYREF
  char v23; // [xsp+1Ah] [xbp-36h]
  __int16 v24; // [xsp+1Ch] [xbp-34h] BYREF
  char v25; // [xsp+1Eh] [xbp-32h]
  _QWORD v26[3]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v27; // [xsp+38h] [xbp-18h] BYREF
  int v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v25 = 0;
  v24 = 0;
  v28 = 0;
  v27 = 0;
  v23 = 0;
  v22 = 0;
  memset(v26, 0, sizeof(v26));
  result = mlo_is_mld_sta(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
    if ( (result & 1) != 0 )
    {
      result = wlan_mlme_is_aux_emlsr_support(a1);
      if ( (result & 1) != 0 )
      {
        result = mlo_mgr_is_link_switch_in_progress(a2);
        if ( (result & 1) == 0 )
        {
          result = mlo_is_link_recfg_in_progress(a2);
          if ( (result & 1) == 0 )
          {
            result = ml_nlink_get_link_info(a1, a2, 8, 3, (int)v26, (int)&v27, (int)&v24, (int)&v22, (__int64)v21);
            if ( v21[0] >= 2u )
            {
              result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
              if ( (result & 1) != 0 )
              {
                result = wlan_mlme_is_aux_emlsr_support(a1);
                if ( (result & 1) != 0 )
                  result = ml_nlink_update_disallow_modes(a1, a2, 1, nullptr, 0, v13, v14, v15, v16, v17, v18, v19, v20);
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
