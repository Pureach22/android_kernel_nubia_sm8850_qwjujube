__int64 __fastcall hdd_update_vhtcap_2g(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x19
  const char *v13; // x2
  __int64 result; // x0
  int v15; // w4
  char v16[4]; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v17; // [xsp+10h] [xbp-40h] BYREF
  __int64 v18; // [xsp+18h] [xbp-38h] BYREF
  __int64 v19; // [xsp+20h] [xbp-30h]
  __int64 v20; // [xsp+28h] [xbp-28h]
  __int64 v21; // [xsp+30h] [xbp-20h]
  __int64 v22; // [xsp+38h] [xbp-18h]
  __int64 v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v17 = 0;
  v18 = 0;
  v16[0] = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 0;
  if ( v9 && (v10 = *(_QWORD *)(v9 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    if ( (unsigned int)wlan_mlme_get_vht_for_24ghz(v9, v16) )
    {
      v13 = "%s: Failed to get 2g vht mode";
    }
    else
    {
      if ( (wmi_service_enabled(v11, 0x5Cu, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
      {
        if ( (unsigned int)wma_get_caps_for_phyidx_hwmode(&v18, 0, 1) )
        {
          v13 = "%s: Failed to get phy caps";
          goto LABEL_7;
        }
        LOBYTE(v15) = (_DWORD)v19 != 0;
      }
      else
      {
        if ( (unsigned int)wlan_reg_get_chip_mode(a1[1], &v17) )
        {
          v13 = "%s: Failed to get chip mode";
          goto LABEL_7;
        }
        v15 = (unsigned __int8)v17 >> 7;
      }
      v16[0] &= v15;
      qdf_trace_msg(0x33u, 8u, "%s: vht 2g target: %d, cfg: %d", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_update_vhtcap_2g");
      result = wlan_mlme_set_vht_for_24ghz(*a1, v16[0]);
      if ( !(_DWORD)result )
        goto LABEL_8;
      v13 = "%s: Failed to update 2g vht mode";
    }
  }
  else
  {
    v13 = "%s: wmi handle is NULL";
  }
LABEL_7:
  result = qdf_trace_msg(0x33u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_update_vhtcap_2g");
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
