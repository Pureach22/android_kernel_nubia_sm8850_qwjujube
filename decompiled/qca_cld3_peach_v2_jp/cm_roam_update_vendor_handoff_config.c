__int64 __fastcall cm_roam_update_vendor_handoff_config(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 rso_config_fl; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  unsigned __int64 v24; // x26
  unsigned int *v25; // x27
  int v26; // w8
  int v27; // w24
  int v28; // w25
  unsigned int v29; // w20

  v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 1);
  if ( !v3 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "cm_roam_update_vendor_handoff_config");
    return 16;
  }
  v12 = v3;
  rso_config_fl = wlan_cm_get_rso_config_fl(v3, "cm_roam_update_vendor_handoff_config", 994);
  if ( !rso_config_fl )
    goto LABEL_30;
  v23 = rso_config_fl;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: received vendor handoff event from FW with num_entries %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "cm_roam_update_vendor_handoff_config",
    a2[1]);
  v14 = (unsigned int *)a2[1];
  if ( !(_DWORD)v14 )
  {
LABEL_28:
    v29 = 0;
    goto LABEL_31;
  }
  v24 = 0;
  v25 = a2 + 3;
  while ( 1 )
  {
    if ( v24 == 8 )
    {
      __break(0x5512u);
      JUMPOUT(0x61AAF1C);
    }
    v28 = *(v25 - 1);
    v27 = *v25;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: param id:%d, param value:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_roam_update_vendor_handoff_config",
      (unsigned int)v28,
      *v25);
    if ( v28 > 4 )
      break;
    if ( v28 > 2 )
    {
      if ( v28 == 3 )
        *(_DWORD *)(v23 + 184) = v27;
      else
        *(_WORD *)(v23 + 146) = 1000 * v27;
    }
    else if ( v28 == 1 )
    {
      if ( v27 >= 0 )
        LOBYTE(v26) = v27;
      else
        v26 = -v27;
      *(_BYTE *)(v23 + 128) = v26;
      *(_BYTE *)(v23 + 129) = v26;
    }
    else
    {
      if ( v28 != 2 )
        goto LABEL_29;
      *(_BYTE *)(v23 + 189) = v27;
    }
LABEL_9:
    v14 = (unsigned int *)a2[1];
    ++v24;
    v25 += 2;
    if ( v24 >= (unsigned __int64)v14 )
      goto LABEL_28;
  }
  if ( v28 <= 6 )
  {
    if ( v28 == 5 )
      *(_DWORD *)(v23 + 136) = v27;
    else
      *(_DWORD *)(v23 + 140) = v27;
    goto LABEL_9;
  }
  if ( v28 == 7 )
  {
    *(_DWORD *)(v23 + 104) = v27;
    goto LABEL_9;
  }
  if ( v28 == 8 )
  {
    *(_WORD *)(v23 + 192) = v27;
    goto LABEL_9;
  }
LABEL_29:
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Invalid param id",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "cm_roam_update_vendor_handoff_config");
LABEL_30:
  v29 = 16;
LABEL_31:
  wlan_objmgr_vdev_release_ref(v12, 1u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  return v29;
}
