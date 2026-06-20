__int64 __fastcall wlan_ser_add_non_scan_cmd(__int64 a1, __int64 a2, unsigned int a3)
{
  int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 result; // x0
  unsigned int v17; // w22
  int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  __int64 v28; // x5
  const char *v29; // x2
  __int64 v30; // x4
  __int64 v31; // x5
  const char *v32; // x2
  __int64 v33; // x24
  int v34; // w8
  __int64 v35; // x2
  unsigned int v36; // w19
  int v37; // w23
  __int64 pdev_queue_obj; // x0
  unsigned __int64 v39; // x9
  _QWORD v40[2]; // [xsp+0h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40[0] = 0;
  v6 = wlan_serialization_add_cmd_to_vdev_queue(a1, a2);
  if ( v6 == 3 )
  {
    v15 = jiffies;
    if ( wlan_ser_add_non_scan_cmd___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: List is full cannot add type %d cmd id %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "wlan_ser_add_non_scan_cmd",
        *(unsigned int *)(a2 + 32),
        *(unsigned int *)(a2 + 36));
      wlan_ser_add_non_scan_cmd___last_ticks = v15;
    }
    result = 3;
    goto LABEL_28;
  }
  if ( !(_BYTE)a3 )
  {
    if ( !v6 )
    {
      v17 = 0;
      v18 = wlan_serialization_add_cmd_to_pdev_queue(a1, a2, 0);
      if ( !v18 )
        goto LABEL_22;
      if ( v18 != 3 )
      {
        v27 = *(unsigned int *)(a2 + 32);
        v28 = *(unsigned int *)(a2 + 36);
        v29 = "%s: Failed to add type %d cmd id %d to pdev pending queue";
        goto LABEL_21;
      }
LABEL_16:
      v33 = jiffies;
      if ( wlan_ser_add_non_scan_cmd___last_ticks_4 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: pdev List is full cannot add type %d cmd id %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "wlan_ser_add_non_scan_cmd",
          *(unsigned int *)(a2 + 32),
          *(unsigned int *)(a2 + 36));
        wlan_ser_add_non_scan_cmd___last_ticks_4 = v33;
      }
      v34 = 3;
      goto LABEL_19;
    }
    v30 = *(unsigned int *)(a2 + 32);
    v31 = *(unsigned int *)(a2 + 36);
    v32 = "%s: Failed to add type %d cmd id %d to vdev pending queue";
LABEL_13:
    qdf_trace_msg(0x4Cu, 2u, v32, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_ser_add_non_scan_cmd", v30, v31);
    result = 6;
    goto LABEL_28;
  }
  if ( v6 != 1 )
  {
    v30 = *(unsigned int *)(a2 + 32);
    v31 = *(unsigned int *)(a2 + 36);
    v32 = "%s: Failed to add type %d cmd id %d to vdev active queue";
    goto LABEL_13;
  }
  v17 = 1;
  v18 = wlan_serialization_add_cmd_to_pdev_queue(a1, a2, a3);
  if ( v18 == 1 )
    goto LABEL_22;
  if ( v18 == 3 )
    goto LABEL_16;
  v27 = *(unsigned int *)(a2 + 32);
  v28 = *(unsigned int *)(a2 + 36);
  v29 = "%s: Failed to add type %d cmd id %d to pdev active queue";
LABEL_21:
  v37 = v18;
  qdf_trace_msg(0x4Cu, 2u, v29, v19, v20, v21, v22, v23, v24, v25, v26, "wlan_ser_add_non_scan_cmd", v27, v28);
  v18 = v37;
LABEL_22:
  v34 = 6;
  if ( v18 != v17 )
  {
LABEL_19:
    v35 = a2 + 32;
    v36 = v34;
    wlan_serialization_remove_cmd_from_vdev_queue(a1, v40, v35, a3);
    result = v36;
    goto LABEL_28;
  }
  if ( (_BYTE)a3 )
  {
    pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(a1, *(unsigned int *)(a2 + 32));
    v39 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 64) + 104LL);
    *(_QWORD *)(pdev_queue_obj + ((v39 >> 3) & 0x18) + 72) |= 1LL << v39;
    if ( (*(_BYTE *)(a2 + 52) & 2) != 0 )
      *(_BYTE *)(pdev_queue_obj + 80) = 1;
    result = v17;
  }
  else
  {
    result = v17;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
