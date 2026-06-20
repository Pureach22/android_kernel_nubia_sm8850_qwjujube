__int64 __fastcall extract_roam_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned __int8 *a12)
{
  _DWORD *v12; // x20
  unsigned int v13; // w4
  __int64 result; // x0
  const char *v15; // x2
  __int64 v16; // x8
  unsigned int v17; // w8
  int v18; // w8
  unsigned int v19; // w5
  int v20; // w9
  _QWORD *v21; // x19
  int v23; // w8
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x5
  const char *v34; // x4
  _QWORD *v35; // x22
  __int64 v36; // x0
  __int64 v37; // x19

  if ( !a10 )
  {
    v15 = "%s: Empty roam_sync_event param buf";
LABEL_7:
    qdf_trace_msg(0x31u, 8u, v15, a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_event_tlv");
    return 16;
  }
  v12 = *(_DWORD **)a10;
  if ( !*(_QWORD *)a10 )
  {
    v15 = "%s: received null event data from target";
    goto LABEL_7;
  }
  v13 = (unsigned __int8)v12[1];
  *a12 = v12[1];
  if ( v13 >= 6 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid vdev id from firmware: %u",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_event_tlv");
    return 4294967274LL;
  }
  v16 = *(_QWORD *)(a10 + 32);
  if ( v16 )
  {
    v17 = *(_DWORD *)(v16 + 16);
    if ( v17 > *(_DWORD *)(a10 + 56) )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: invalid vdev mac entries %d %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_event_tlv",
        v17);
      return 16;
    }
  }
  v18 = v12[2];
  v19 = 0;
  v20 = 1;
  if ( v18 > 4 )
  {
    if ( v18 <= 6 )
    {
      if ( v18 != 5 )
      {
        v21 = (_QWORD *)a10;
        goto LABEL_27;
      }
    }
    else if ( v18 != 7 && v18 != 8 )
    {
      v21 = (_QWORD *)a10;
      if ( v18 != 9 )
        goto LABEL_28;
LABEL_27:
      v20 = 0;
      v19 = v12[2];
      goto LABEL_28;
    }
LABEL_26:
    v21 = (_QWORD *)a10;
    goto LABEL_27;
  }
  if ( v18 > 2 )
  {
    if ( v18 != 3 )
    {
      v21 = (_QWORD *)a10;
      goto LABEL_27;
    }
    goto LABEL_26;
  }
  if ( v18 == 1 )
    goto LABEL_26;
  v21 = (_QWORD *)a10;
  if ( v18 == 2 )
    goto LABEL_27;
LABEL_28:
  *((_DWORD *)a12 + 4) = v19;
  *((_DWORD *)a12 + 5) = v12[3];
  v23 = v12[4];
  if ( (unsigned int)(v23 - 1) >= 0xC )
    v23 = 0;
  *((_DWORD *)a12 + 6) = v23;
  *((_DWORD *)a12 + 7) = v12[5];
  *((_DWORD *)a12 + 8) = v12[6];
  if ( v20 )
    v24 = (unsigned int *)(a12 + 24);
  else
    v24 = (unsigned int *)(a12 + 20);
  wlan_roam_debug_log(v13, 0xBu, 0xFFFFu, 0, 0, v19, *v24);
  qdf_dp_trace_record_event(6, *a12, 0xFFu, 6, 34);
  v33 = *((unsigned int *)a12 + 4);
  if ( (unsigned int)v33 > 9 )
    v34 = "Invalid";
  else
    v34 = off_B34230[v33];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: FW_ROAM_EVT: Reason:%s[%d], Notif %x for vdevid %x, rssi %d, params %d, params1 %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "extract_roam_event_tlv",
    v34,
    v33,
    *((unsigned int *)a12 + 6),
    *a12,
    *((_DWORD *)a12 + 5),
    *((_DWORD *)a12 + 7),
    *((_DWORD *)a12 + 8));
  v35 = v21;
  if ( v21[4] )
  {
    v36 = _qdf_mem_malloc(0x54u, "extract_roam_event_tlv", 1128);
    if ( !v36 )
      return 2;
    v37 = v36;
    wmi_extract_pdev_hw_mode_trans_ind(v35[4], v35[6], 0, 0, v36);
    *((_QWORD *)a12 + 5) = v37;
  }
  result = 0;
  if ( v12[6] )
    *((_QWORD *)a12 + 6) = v35[2];
  return result;
}
