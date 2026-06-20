__int64 __fastcall wlan_print_cached_sae_auth_logs(__int64 a1, __int64 a2, unsigned int a3)
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
  unsigned int *v14; // x8
  __int64 v15; // x19
  __int64 v16; // x20
  __int64 ext_hdl; // x0
  _DWORD *v19; // x21
  bool v20; // zf
  bool v21; // zf
  bool v22; // zf
  bool v23; // zf
  bool v24; // zf
  bool v25; // zf
  bool v26; // zf
  bool v27; // zf
  bool v28; // zf
  __int64 v29; // x21
  unsigned int v30; // w22
  unsigned int *v31; // x8

  v3 = a3;
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 67);
  if ( !v5 )
  {
    v16 = jiffies;
    if ( wlan_print_cached_sae_auth_logs___last_ticks - jiffies + 125 < 0 )
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
        "wlan_print_cached_sae_auth_logs",
        v3);
      wlan_print_cached_sae_auth_logs___last_ticks = v16;
    }
    return 16;
  }
  v14 = (unsigned int *)*(unsigned int *)(v5 + 16);
  v15 = v5;
  if ( (_DWORD)v14 )
  {
LABEL_3:
    wlan_objmgr_vdev_release_ref(v15, 0x43u, v14, v6, v7, v8, v9, v10, v11, v12, v13);
    return 16;
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
  if ( !ext_hdl )
  {
    v29 = jiffies;
    v14 = (unsigned int *)(wlan_print_cached_sae_auth_logs___last_ticks_4 - jiffies);
    if ( wlan_print_cached_sae_auth_logs___last_ticks_4 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev legacy private object is NULL",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_print_cached_sae_auth_logs");
      wlan_print_cached_sae_auth_logs___last_ticks_4 = v29;
    }
    goto LABEL_3;
  }
  v19 = (_DWORD *)(ext_hdl + 336);
  if ( *(_QWORD *)(ext_hdl + 360)
    && (*(_DWORD *)a2 == *v19
      ? (v20 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 340))
      : (v20 = 0),
        v20) )
  {
    v30 = 0;
  }
  else if ( *(_QWORD *)(ext_hdl + 2944)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 2920)
           ? (v21 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 2924))
           : (v21 = 0),
             v21) )
  {
    v30 = 1;
  }
  else if ( *(_QWORD *)(ext_hdl + 5528)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 5504)
           ? (v22 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 5508))
           : (v22 = 0),
             v22) )
  {
    v30 = 2;
  }
  else if ( *(_QWORD *)(ext_hdl + 8112)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 8088)
           ? (v23 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 8092))
           : (v23 = 0),
             v23) )
  {
    v30 = 3;
  }
  else if ( *(_QWORD *)(ext_hdl + 10696)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 10672)
           ? (v24 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 10676))
           : (v24 = 0),
             v24) )
  {
    v30 = 4;
  }
  else if ( *(_QWORD *)(ext_hdl + 13280)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 13256)
           ? (v25 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 13260))
           : (v25 = 0),
             v25) )
  {
    v30 = 5;
  }
  else if ( *(_QWORD *)(ext_hdl + 15864)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 15840)
           ? (v26 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 15844))
           : (v26 = 0),
             v26) )
  {
    v30 = 6;
  }
  else if ( *(_QWORD *)(ext_hdl + 18448)
         && (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 18424)
           ? (v27 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 18428))
           : (v27 = 0),
             v27) )
  {
    v30 = 7;
  }
  else
  {
    if ( !*(_QWORD *)(ext_hdl + 21032)
      || (*(_DWORD *)a2 == *(_DWORD *)(ext_hdl + 21008)
        ? (v28 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(ext_hdl + 21012))
        : (v28 = 0),
          !v28) )
    {
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: No cached SAE auth logs",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_print_cached_sae_auth_logs");
      goto LABEL_3;
    }
    v30 = 8;
  }
  if ( *(_QWORD *)&v19[646 * v30 + 6] )
  {
    host_diag_event_report_payload(3355, 323, &v19[646 * v30]);
    qdf_mem_set(&v19[646 * v30], 0x143u, 0);
  }
  if ( *(_QWORD *)((char *)&v19[646 * v30 + 86] + 3) )
  {
    host_diag_event_report_payload(3355, 323, (char *)&v19[646 * v30 + 80] + 3);
    qdf_mem_set((char *)&v19[646 * v30 + 80] + 3, 0x143u, 0);
  }
  if ( *(_QWORD *)((char *)&v19[646 * v30 + 167] + 2) )
  {
    host_diag_event_report_payload(3355, 323, (char *)&v19[646 * v30 + 161] + 2);
    qdf_mem_set((char *)&v19[646 * v30 + 161] + 2, 0x143u, 0);
  }
  if ( *(_QWORD *)((char *)&v19[646 * v30 + 248] + 1) )
  {
    host_diag_event_report_payload(3355, 323, (char *)&v19[646 * v30 + 242] + 1);
    qdf_mem_set((char *)&v19[646 * v30 + 242] + 1, 0x143u, 0);
  }
  if ( *(_QWORD *)&v19[646 * v30 + 329] )
  {
    host_diag_event_report_payload(3355, 323, &v19[646 * v30 + 323]);
    qdf_mem_set(&v19[646 * v30 + 323], 0x143u, 0);
  }
  if ( *(_QWORD *)((char *)&v19[646 * v30 + 409] + 3) )
  {
    host_diag_event_report_payload(3355, 323, (char *)&v19[646 * v30 + 403] + 3);
    qdf_mem_set((char *)&v19[646 * v30 + 403] + 3, 0x143u, 0);
  }
  if ( *(_QWORD *)((char *)&v19[646 * v30 + 490] + 2) )
  {
    host_diag_event_report_payload(3355, 323, (char *)&v19[646 * v30 + 484] + 2);
    qdf_mem_set((char *)&v19[646 * v30 + 484] + 2, 0x143u, 0);
  }
  v31 = *(unsigned int **)((char *)&v19[646 * v30 + 571] + 1);
  if ( v31 )
  {
    host_diag_event_report_payload(3355, 323, (char *)&v19[646 * v30 + 565] + 1);
    qdf_mem_set((char *)&v19[646 * v30 + 565] + 1, 0x143u, 0);
  }
  wlan_objmgr_vdev_release_ref(v15, 0x43u, v31, v6, v7, v8, v9, v10, v11, v12, v13);
  return 0;
}
