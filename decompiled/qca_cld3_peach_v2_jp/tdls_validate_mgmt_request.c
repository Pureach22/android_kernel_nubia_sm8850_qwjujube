__int64 __fastcall tdls_validate_mgmt_request(__int64 *a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 (__fastcall *v13)(_QWORD); // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w9
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w8
  __int64 v32; // x11
  __int64 peer; // x0
  __int64 v34; // x4
  __int64 v35; // x5
  const char *v36; // x2
  __int64 v37; // x6
  __int64 v38; // x7
  const char *v39; // x3
  int v40; // w9
  int v41; // w10
  __int64 v42; // x4
  unsigned int v43; // w8
  __int64 v44; // x0
  __int64 v45; // [xsp+0h] [xbp-40h]
  __int64 v46; // [xsp+8h] [xbp-38h]
  __int64 v47; // [xsp+10h] [xbp-30h]
  __int64 v48; // [xsp+18h] [xbp-28h]
  __int64 v49; // [xsp+28h] [xbp-18h] BYREF
  __int64 v50[2]; // [xsp+30h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v49 = 0;
  v50[0] = 0;
  if ( (unsigned int)tdls_get_vdev_objects(v2, v50, &v49) )
  {
    result = 4294966772LL;
    goto LABEL_43;
  }
  if ( (tdls_is_vdev_allowed_to_tx(v2) & 1) == 0 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: STA is not connected or not authenticated.",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "tdls_validate_mgmt_request");
    result = 4294967285LL;
    goto LABEL_43;
  }
  if ( *((_BYTE *)a1 + 8) != 3 )
  {
    if ( (tdls_check_is_tdls_allowed(v2) & 1) == 0 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: TDLS not allowed, reject MGMT, action = %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "tdls_validate_mgmt_request",
        *((unsigned __int8 *)a1 + 8));
LABEL_42:
      result = 0xFFFFFFFFLL;
      goto LABEL_43;
    }
    if ( *(_DWORD *)(v49 + 8) <= 1u )
    {
      qdf_trace_msg(
        0,
        4u,
        "%s: %02x:%02x:%02x:**:**:%02x TDLS mode is disabled. action %d declined.",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "tdls_validate_mgmt_request",
        *((unsigned __int8 *)a1 + 9),
        *((unsigned __int8 *)a1 + 10),
        *((unsigned __int8 *)a1 + 11),
        *((unsigned __int8 *)a1 + 14),
        *((unsigned __int8 *)a1 + 8));
      result = 4294966772LL;
      goto LABEL_43;
    }
    v42 = *((unsigned __int8 *)a1 + 8);
    if ( *(_BYTE *)(v49 + 214) == 1 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: nss switch in progress, action %d declined %02x:%02x:%02x:**:**:%02x",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "tdls_validate_mgmt_request",
        v42,
        *((unsigned __int8 *)a1 + 9),
        *((unsigned __int8 *)a1 + 10),
        *((unsigned __int8 *)a1 + 11),
        *((unsigned __int8 *)a1 + 14));
      result = 4294967285LL;
      goto LABEL_43;
    }
    if ( (unsigned int)v42 <= 2 && tdls_is_progress(v50[0], (char *)a1 + 9, 1) && !*((_BYTE *)a1 + 16) )
    {
      v34 = *((unsigned __int8 *)a1 + 8);
      v35 = *((unsigned __int8 *)a1 + 9);
      v36 = "%s: setup is ongoing. action %d declined for %02x:%02x:%02x:**:**:%02x";
      v37 = *((unsigned __int8 *)a1 + 10);
      v38 = *((unsigned __int8 *)a1 + 11);
      v31 = *((unsigned __int8 *)a1 + 14);
      goto LABEL_19;
    }
  }
  v12 = *(unsigned __int8 *)(v2 + 104);
  v13 = *(__int64 (__fastcall **)(_QWORD))(v49 + 248);
  if ( *((_DWORD *)v13 - 1) != 2116364946 )
    __break(0x8228u);
  if ( (v13(v12) & 1) != 0 )
  {
    v22 = 1;
  }
  else
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: admission ctrl set to VI, send the frame with least AC (BK) for action %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tdls_validate_mgmt_request",
      *((unsigned __int8 *)a1 + 8));
    v22 = 0;
  }
  v31 = *((unsigned __int8 *)a1 + 8);
  *((_BYTE *)a1 + 57) = v22;
  if ( v31 <= 1 )
  {
    v32 = v49;
    if ( *(unsigned __int16 *)(v49 + 200) <= (unsigned int)*(unsigned __int16 *)(v49 + 202) )
    {
      if ( !v31 )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: %02x:%02x:%02x:**:**:%02x TDLS Max peer already connected. action (%d) declined. Num of peers (%d), Max allowed (%d).",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "tdls_validate_setup_frames",
          *((unsigned __int8 *)a1 + 9),
          *((unsigned __int8 *)a1 + 10),
          *((unsigned __int8 *)a1 + 11),
          *((unsigned __int8 *)a1 + 14),
          0,
          *(unsigned __int16 *)(v49 + 202),
          *(unsigned __int16 *)(v49 + 200));
        result = 4294967274LL;
        goto LABEL_43;
      }
      v34 = *((unsigned __int8 *)a1 + 9);
      v35 = *((unsigned __int8 *)a1 + 10);
      *((_BYTE *)a1 + 16) = 1;
      v37 = *((unsigned __int8 *)a1 + 11);
      v40 = *(unsigned __int16 *)(v32 + 202);
      v41 = *(unsigned __int16 *)(v32 + 200);
      v36 = "%s: %02x:%02x:%02x:**:**:%02x TDLS Max peer already connected, send response status (%d). Num of peers (%d),"
            " Max allowed (%d).";
      v38 = *((unsigned __int8 *)a1 + 14);
      v39 = "tdls_validate_setup_frames";
      goto LABEL_39;
    }
    peer = tdls_find_peer(v50[0], (char *)a1 + 9);
    if ( peer )
    {
      v31 = *((unsigned __int8 *)a1 + 8);
      if ( (*(_DWORD *)(peer + 36) & 0xFFFFFFFE) == 4 )
      {
        v34 = *((unsigned __int8 *)a1 + 9);
        v35 = *((unsigned __int8 *)a1 + 10);
        v36 = "%s: %02x:%02x:%02x:**:**:%02x already connected action %d declined.";
        v37 = *((unsigned __int8 *)a1 + 11);
        v38 = *((unsigned __int8 *)a1 + 14);
LABEL_19:
        v39 = "tdls_validate_mgmt_request";
LABEL_40:
        LODWORD(v45) = v31;
        goto LABEL_41;
      }
    }
    else
    {
      v31 = *((unsigned __int8 *)a1 + 8);
    }
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: tdls_mgmt %02x:%02x:%02x:**:**:%02x action %d, dialog_token %d status %d, len = %zu",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "tdls_validate_mgmt_request",
    *((unsigned __int8 *)a1 + 9),
    *((unsigned __int8 *)a1 + 10),
    *((unsigned __int8 *)a1 + 11),
    *((unsigned __int8 *)a1 + 14),
    v31,
    *((unsigned __int8 *)a1 + 15),
    *((unsigned __int8 *)a1 + 16),
    a1[3]);
  v43 = *((unsigned __int8 *)a1 + 8);
  *((_DWORD *)a1 + 8) = 0;
  if ( v43 == 3 )
  {
    v44 = tdls_find_peer(v50[0], (char *)a1 + 9);
    if ( !v44 )
    {
      v34 = *((unsigned __int8 *)a1 + 9);
      v35 = *((unsigned __int8 *)a1 + 10);
      v36 = "%s: %02x:%02x:%02x:**:**:%02x peer doesn't exist";
      v37 = *((unsigned __int8 *)a1 + 11);
      v38 = *((unsigned __int8 *)a1 + 14);
      v39 = "tdls_validate_mgmt_request";
LABEL_41:
      qdf_trace_msg(0, 2u, v36, v14, v15, v16, v17, v18, v19, v20, v21, v39, v34, v35, v37, v38, v45, v46, v47, v48);
      goto LABEL_42;
    }
    v31 = *(_DWORD *)(v44 + 36);
    if ( (v31 & 0xFFFFFFFE) == 4 )
    {
      v43 = *((unsigned __int8 *)a1 + 8);
      *((_DWORD *)a1 + 8) = *(unsigned __int8 *)(v44 + 40);
      goto LABEL_34;
    }
    v40 = *((unsigned __int8 *)a1 + 15);
    v41 = *((unsigned __int8 *)a1 + 16);
    v34 = *((unsigned __int8 *)a1 + 9);
    v36 = "%s: %02x:%02x:%02x:**:**:%02x peer doesn't exist or not connected %d dialog_token %d status %d, tdls_validate->len = %zu";
    v35 = *((unsigned __int8 *)a1 + 10);
    v37 = *((unsigned __int8 *)a1 + 11);
    v38 = *((unsigned __int8 *)a1 + 14);
    v48 = a1[3];
    v39 = "tdls_validate_mgmt_request";
LABEL_39:
    LODWORD(v47) = v41;
    LODWORD(v46) = v40;
    goto LABEL_40;
  }
LABEL_34:
  result = 0;
  if ( v43 <= 0xE && ((1 << v43) & 0x4006) != 0 )
  {
    tdls_set_cap(v50[0], (__int64)a1 + 9, 1);
    result = 0;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
