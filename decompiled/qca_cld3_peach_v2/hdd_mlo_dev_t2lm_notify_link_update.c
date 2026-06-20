__int64 __fastcall hdd_mlo_dev_t2lm_notify_link_update(__int64 a1, unsigned int *a2)
{
  __int64 link_info_from_objmgr; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  unsigned int v22; // w1

  link_info_from_objmgr = wlan_hdd_get_link_info_from_objmgr();
  if ( !link_info_from_objmgr )
  {
    v21 = "%s: Invalid VDEV";
    v22 = 2;
    goto LABEL_5;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "hdd_mlo_dev_t2lm_notify_link_update",
    *(_QWORD *)(*(_QWORD *)link_info_from_objmgr + 32LL) + 296LL);
  if ( (unsigned int)hdd_tid_to_link_map(a1, a2, v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    v21 = "%s: tid to link map change failed ";
    v22 = 8;
LABEL_5:
    qdf_trace_msg(0x33u, v22, v21, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_mlo_dev_t2lm_notify_link_update");
    return 16;
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v5, v6, v7, v8, v9, v10, v11, v12, "hdd_mlo_dev_t2lm_notify_link_update");
  return 0;
}
