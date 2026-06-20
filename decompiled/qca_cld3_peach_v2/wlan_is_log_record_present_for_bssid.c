__int64 __fastcall wlan_is_log_record_present_for_bssid(__int64 a1, unsigned int *a2, unsigned int a3)
{
  unsigned __int8 v3; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 ext_hdl; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  bool v32; // zf
  bool v33; // zf
  bool v34; // zf
  __int64 v35; // x20
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x20

  v3 = a3;
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 67);
  if ( v5 )
  {
    v14 = v5;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( ext_hdl )
    {
      if ( *(_QWORD *)(ext_hdl + 360) )
      {
        v25 = (unsigned int *)*a2;
        if ( (_DWORD)v25 == *(_DWORD *)(ext_hdl + 336)
          && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(ext_hdl + 340) )
        {
          goto LABEL_51;
        }
      }
      if ( *(_QWORD *)(ext_hdl + 2944) )
      {
        v25 = (unsigned int *)*a2;
        if ( (_DWORD)v25 == *(_DWORD *)(ext_hdl + 2920)
          && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(ext_hdl + 2924) )
        {
          goto LABEL_51;
        }
      }
      if ( *(_QWORD *)(ext_hdl + 5528) )
      {
        v25 = (unsigned int *)*a2;
        if ( (_DWORD)v25 == *(_DWORD *)(ext_hdl + 5504)
          && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(ext_hdl + 5508) )
        {
          goto LABEL_51;
        }
      }
      if ( *(_QWORD *)(ext_hdl + 8112) )
      {
        v25 = (unsigned int *)*a2;
        if ( (_DWORD)v25 == *(_DWORD *)(ext_hdl + 8088)
          && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(ext_hdl + 8092) )
        {
          goto LABEL_51;
        }
      }
      if ( *(_QWORD *)(ext_hdl + 10696) )
      {
        v25 = (unsigned int *)*(unsigned __int16 *)(ext_hdl + 10676);
        if ( *a2 == *(_DWORD *)(ext_hdl + 10672) && *((unsigned __int16 *)a2 + 2) == (_DWORD)v25 )
          goto LABEL_51;
      }
      if ( *(_QWORD *)(ext_hdl + 13280) )
      {
        v25 = (unsigned int *)*(unsigned __int16 *)(ext_hdl + 13260);
        if ( *a2 == *(_DWORD *)(ext_hdl + 13256) && *((unsigned __int16 *)a2 + 2) == (_DWORD)v25 )
          goto LABEL_51;
      }
      if ( *(_QWORD *)(ext_hdl + 15864)
        && ((v25 = (unsigned int *)*(unsigned __int16 *)(ext_hdl + 15844), *a2 == *(_DWORD *)(ext_hdl + 15840))
          ? (v32 = *((unsigned __int16 *)a2 + 2) == (_DWORD)v25)
          : (v32 = 0),
            v32)
        || (v25 = (unsigned int *)(ext_hdl + 18424), *(_QWORD *)(ext_hdl + 18448))
        && (*a2 == *v25 ? (v33 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(ext_hdl + 18428)) : (v33 = 0),
            v33)
        || *(_QWORD *)(ext_hdl + 21032)
        && ((v25 = (unsigned int *)*(unsigned __int16 *)(ext_hdl + 21012), *a2 == *(_DWORD *)(ext_hdl + 21008))
          ? (v34 = *((unsigned __int16 *)a2 + 2) == (_DWORD)v25)
          : (v34 = 0),
            v34) )
      {
LABEL_51:
        wlan_objmgr_vdev_release_ref(v14, 0x43u, v25, v17, v18, v19, v20, v21, v22, v23, v24);
        return 1;
      }
      wlan_objmgr_vdev_release_ref(v14, 0x43u, v25, v17, v18, v19, v20, v21, v22, v23, v24);
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v14, 0x43u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      v45 = jiffies;
      if ( wlan_is_log_record_present_for_bssid___last_ticks_6 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: vdev legacy private object is NULL",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "wlan_is_log_record_present_for_bssid");
        wlan_is_log_record_present_for_bssid___last_ticks_6 = v45;
        return 0;
      }
    }
  }
  else
  {
    v35 = jiffies;
    if ( wlan_is_log_record_present_for_bssid___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: Invalid vdev:%d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_is_log_record_present_for_bssid",
        v3);
      wlan_is_log_record_present_for_bssid___last_ticks = v35;
      return 0;
    }
  }
  return 0;
}
