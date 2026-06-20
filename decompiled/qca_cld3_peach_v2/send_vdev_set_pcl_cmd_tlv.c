__int64 __fastcall send_vdev_set_pcl_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x23
  __int64 v5; // x0
  _DWORD *v6; // x9
  __int64 v7; // x19
  __int64 v8; // x8
  _DWORD *v9; // x9
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v4 = *(unsigned int *)(*((_QWORD *)a2 + 1) + 820LL);
  v5 = wmi_buf_alloc_fl(a1, 4 * (int)v4 + 12, "send_vdev_set_pcl_cmd_tlv", 0x720u);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 56819716;
  v6[1] = *a2;
  v6[2] = (unsigned __int16)(4 * v4) | 0x100000;
  if ( (_DWORD)v4 )
  {
    v8 = 0;
    v9 = v6 + 3;
    while ( v8 != 102 )
    {
      v9[v8] = *(unsigned __int8 *)(*((_QWORD *)a2 + 1) + v8 + 824);
      if ( v4 == ++v8 )
        goto LABEL_6;
    }
    __break(0x5512u);
    return send_set_roam_trigger_cmd_tlv();
  }
  else
  {
LABEL_6:
    wmi_mtrace(0x5028u, *a2, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v7,
               4 * (int)v4 + 12,
               0x5028u,
               "send_vdev_set_pcl_cmd_tlv",
               0x735u,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_VDEV_SET_PCL_CMDID",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_vdev_set_pcl_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
  }
  return result;
}
