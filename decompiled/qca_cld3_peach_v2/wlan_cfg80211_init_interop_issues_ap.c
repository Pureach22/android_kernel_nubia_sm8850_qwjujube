__int64 __fastcall wlan_cfg80211_init_interop_issues_ap(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  unsigned int v11; // w0
  __int64 v12; // x0
  __int64 result; // x0
  __int64 (__fastcall *v14)(_QWORD); // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-B0h] BYREF
  _QWORD v16[2]; // [xsp+20h] [xbp-A0h] BYREF
  int v17; // [xsp+30h] [xbp-90h] BYREF
  __int16 v18; // [xsp+34h] [xbp-8Ch]
  _QWORD v19[17]; // [xsp+38h] [xbp-88h] BYREF

  v19[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = -1;
  v17 = -1;
  memset(v19, 0, 128);
  v16[0] = 0;
  v16[1] = 0;
  v15[1] = 0;
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    v10 = "%s: Operation not supported in FTM mode";
    v11 = 51;
LABEL_6:
    result = qdf_trace_msg(v11, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, "wlan_cfg80211_init_interop_issues_ap");
    goto LABEL_7;
  }
  v14 = wlan_cfg80211_send_interop_issues_ap_cb;
  ucfg_register_interop_issues_ap_callback(a1, &v14, v2, v3, v4, v5, v6, v7, v8, v9);
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v10 = "%s: Invalid psoc";
    v11 = 72;
    goto LABEL_6;
  }
  LOBYTE(v19[0]) = 1;
  ucfg_set_interop_issues_ap_config(v12, (__int64)v19);
  v15[0] = a1;
  qdf_mem_copy((char *)v16 + 4, &v17, 6u);
  result = wlan_cfg80211_send_interop_issues_ap_cb(v15);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
