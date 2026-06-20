__int64 __fastcall wlan_hdd_add_monitor_check(
        __int64 *a1,
        _QWORD *a2,
        const char *a3,
        char a4,
        unsigned int a5,
        char a6)
{
  __int64 adapter; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x25
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  __int64 result; // x0
  unsigned __int8 *intf_addr; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _DWORD *v41; // x0
  _DWORD *v42; // x21
  int v43; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-18h] BYREF
  int v45; // [xsp+10h] [xbp-10h]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  adapter = hdd_get_adapter((__int64)a1, 0);
  if ( !adapter )
  {
    v30 = "%s: No station adapter";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v30, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_add_monitor_check");
    goto LABEL_7;
  }
  v21 = adapter;
  if ( !(unsigned int)policy_mgr_check_mon_concurrency(*a1) )
  {
    v45 = 0;
    v44 = 0;
    hdd_adapter_iterate(hdd_is_connection_in_progress_iterator, (__int64)&v44, v22, v23, v24, v25, v26, v27, v28, v29);
    if ( (unsigned __int8)v45 == 1 )
    {
      v30 = "%s: cannot add monitor mode, Connection in progress";
    }
    else
    {
      if ( (a6 & 1) != 0 && (unsigned __int8)policy_mgr_mode_specific_connection_count(*a1, 0, nullptr) )
        wlan_hdd_cm_issue_disconnect(*(_QWORD *)(v21 + 52832), 1, 1);
      v43 |= 8u;
      intf_addr = (unsigned __int8 *)wlan_hdd_get_intf_addr((__int64)a1, 6, v13, v14, v15, v16, v17, v18, v19, v20);
      v41 = hdd_open_adapter(a1, 6u, a3, intf_addr, a5, a4 & 1, &v43, v33, v34, v35, v36, v37, v38, v39, v40);
      if ( v41 )
      {
        v42 = v41;
        hdd_set_idle_ps_config((__int64)a1, 0, v13, v14, v15, v16, v17, v18, v19, v20);
        result = 0;
        *a2 = v42;
        goto LABEL_8;
      }
      v30 = "%s: hdd_open_adapter failed";
    }
    goto LABEL_6;
  }
LABEL_7:
  result = 4294967274LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
