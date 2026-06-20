__int64 __fastcall wlan_ser_remove_non_scan_cmd(__int64 a1, __int64 a2, unsigned int *a3, __int64 a4)
{
  unsigned int v4; // w22
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x4
  __int64 v18; // x5
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x1
  char v29; // w21
  __int64 pdev_queue_obj; // x0
  unsigned __int64 v31; // x9

  v4 = a4;
  result = wlan_serialization_remove_cmd_from_vdev_queue(a1, a2, a3, a4);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result != 24 )
    {
      v17 = *a3;
      v18 = a3[1];
      v19 = result;
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: Failed to remove type %d id %d from vdev queue",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "wlan_ser_remove_non_scan_cmd",
        v17,
        v18);
      return v19;
    }
  }
  else if ( (unsigned int)wlan_serialization_remove_cmd_from_pdev_queue(a1, a2, a3, v4) )
  {
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: Failed to remove type %d id %d from pdev active/pending queue",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_ser_remove_non_scan_cmd",
      *a3,
      a3[1]);
    return 16;
  }
  else if ( (_BYTE)v4 )
  {
    v28 = *(unsigned int *)(*(_QWORD *)a2 + 32LL);
    v29 = *(_BYTE *)(*(_QWORD *)a2 + 52LL);
    pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(a1, v28);
    if ( (v29 & 2) != 0 )
      *(_BYTE *)(pdev_queue_obj + 80) = 0;
    v31 = *(unsigned __int8 *)(*((_QWORD *)a3 + 4) + 168LL);
    *(_QWORD *)(pdev_queue_obj + ((v31 >> 3) & 0x18) + 72) &= ~(1LL << v31);
    return 0;
  }
  else
  {
    return 0;
  }
  return result;
}
