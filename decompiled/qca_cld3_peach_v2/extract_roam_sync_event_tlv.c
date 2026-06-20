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
  unsigned int *v12; // x23
  __int64 v13; // x8
  const char *v14; // x2
  unsigned int v15; // w4
  const char *v16; // x2
  __int64 v20; // x0
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w0
  unsigned int v31; // w20
  unsigned int *v32; // x8
  __int64 rso_config_fl; // x0
  _DWORD *v35; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w8
  unsigned int v45; // w10
  int v46; // w25
  __int64 v47; // x0

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
    v20 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            **(_QWORD **)(a1 + 760),
            v15,
            1);
    if ( !v20 )
    {
      v16 = "%s: For vdev:%d object is NULL";
      goto LABEL_20;
    }
    v21 = v20;
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
      v30 = 16;
      goto LABEL_17;
    }
    rso_config_fl = wlan_cm_get_rso_config_fl(
                      v20,
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
    v35 = (_DWORD *)rso_config_fl;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: synch payload: LEN bcn:%d, req:%d, rsp:%d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "extract_roam_sync_event_tlv",
      v12[8],
      v12[10],
      v12[9]);
    v44 = v12[8];
    if ( v44 )
    {
      v45 = v12[9];
    }
    else
    {
      v45 = v12[9];
      if ( !*(_QWORD *)(v12 + 9) )
      {
        v46 = v35[223] + v35[218] + v35[227] + v35[230];
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Updated synch payload: LEN bcn:%d, link bcn: %d req:%d, rsp:%d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "extract_roam_sync_event_tlv");
        goto LABEL_29;
      }
    }
    v46 = v12[10] + v44 + v45;
LABEL_29:
    v47 = _qdf_mem_malloc((unsigned int)(v46 + 2816), "extract_roam_sync_event_tlv", 2672);
    if ( v47 )
    {
      *a12 = v47;
      v30 = wmi_fill_roam_sync_buffer(a1, v21, v35, v47, a2);
      if ( !v30 )
      {
        v31 = 0;
        goto LABEL_18;
      }
    }
    else
    {
      v30 = 2;
    }
LABEL_17:
    v31 = v30;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: %d Failed to extract roam sync ind",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "extract_roam_sync_event_tlv");
    wlan_cm_roam_state_change(*(_QWORD *)(v21 + 216), v12[1], 3u, 0x24u);
LABEL_18:
    wlan_objmgr_vdev_release_ref(v21, 1u, v32, v22, v23, v24, v25, v26, v27, v28, v29);
    return v31;
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
