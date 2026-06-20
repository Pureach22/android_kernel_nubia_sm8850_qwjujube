__int64 __fastcall extract_roam_sync_event_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 *a12)
{
  unsigned int *v12; // x22
  __int64 v13; // x8
  const char *v14; // x2
  unsigned int v15; // w4
  const char *v16; // x2
  __int64 v19; // x0
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w0
  unsigned int v30; // w20
  unsigned int *v31; // x8
  __int64 rso_config_fl; // x0
  _DWORD *v34; // x21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w8
  unsigned int v44; // w10
  int v45; // w24
  __int64 v46; // x0

  if ( !a2 )
  {
    v14 = "%s: Empty roam_sync_event param buf";
LABEL_10:
    qdf_trace_msg(0x31u, 8u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "extract_roam_sync_event_tlv");
    return 16;
  }
  v12 = *(unsigned int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    v14 = "%s: received null event data from target";
    goto LABEL_10;
  }
  v13 = *(_QWORD *)(a2 + 112);
  if ( !v13 || *(_DWORD *)(v13 + 16) <= *(_DWORD *)(a2 + 136) )
  {
    v15 = v12[1];
    if ( v15 >= 6 )
    {
      v16 = "%s: received invalid vdev_id %d";
LABEL_20:
      qdf_trace_msg(0x31u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "extract_roam_sync_event_tlv");
      return 16;
    }
    v19 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            **(_QWORD **)(a1 + 760),
            v15,
            1);
    if ( !v19 )
    {
      v16 = "%s: For vdev:%d object is NULL";
      goto LABEL_20;
    }
    v20 = v19;
    if ( v12[8] > *(_DWORD *)(a2 + 24) || v12[10] > *(_DWORD *)(a2 + 104) || v12[9] > *(_DWORD *)(a2 + 40) )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Invalid sync payload: LEN bcn:%d, req:%d, rsp:%d, vdev:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "extract_roam_sync_event_tlv");
LABEL_16:
      v29 = 16;
      goto LABEL_17;
    }
    rso_config_fl = wlan_cm_get_rso_config_fl(
                      v19,
                      (__int64)"extract_roam_sync_event_tlv",
                      0xA3Du,
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10);
    if ( !rso_config_fl )
      goto LABEL_16;
    v34 = (_DWORD *)rso_config_fl;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: synch payload: LEN bcn:%d, req:%d, rsp:%d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "extract_roam_sync_event_tlv",
      v12[8],
      v12[10],
      v12[9]);
    v43 = v12[8];
    if ( v43 )
    {
      v44 = v12[9];
    }
    else
    {
      v44 = v12[9];
      if ( !*(_QWORD *)(v12 + 9) )
      {
        v45 = v34[223] + v34[218] + v34[227] + v34[230];
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Updated synch payload: LEN bcn:%d, link bcn: %d req:%d, rsp:%d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "extract_roam_sync_event_tlv");
        goto LABEL_29;
      }
    }
    v45 = v12[10] + v43 + v44;
LABEL_29:
    v46 = _qdf_mem_malloc((unsigned int)(v45 + 2504), "extract_roam_sync_event_tlv", 2672);
    if ( v46 )
    {
      *a12 = v46;
      v29 = wmi_fill_roam_sync_buffer(v20, v34, v46, a2);
      if ( !v29 )
      {
        v30 = 0;
        goto LABEL_18;
      }
    }
    else
    {
      v29 = 2;
    }
LABEL_17:
    v30 = v29;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: %d Failed to extract roam sync ind",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "extract_roam_sync_event_tlv");
    wlan_cm_roam_state_change(*(_QWORD *)(v20 + 152), v12[1], 3, 0x24u);
LABEL_18:
    wlan_objmgr_vdev_release_ref(v20, 1u, v31, v21, v22, v23, v24, v25, v26, v27, v28);
    return v30;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: invalid vdev mac entries %d %d in roam sync",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "extract_roam_sync_event_tlv");
  return 16;
}
