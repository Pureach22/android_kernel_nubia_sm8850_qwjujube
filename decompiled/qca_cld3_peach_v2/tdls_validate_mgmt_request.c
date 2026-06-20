__int64 __fastcall tdls_validate_mgmt_request(__int64 *a1)
{
  unsigned __int8 *v2; // x20
  __int64 v3; // x21
  __int64 result; // x0
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
  __int64 v21; // x0
  __int64 (__fastcall *v22)(_QWORD); // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  char v31; // w9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w8
  __int64 peer; // x0
  __int64 v42; // x4
  __int64 v43; // x5
  const char *v44; // x2
  __int64 v45; // x6
  __int64 v46; // x7
  __int64 v47; // x4
  unsigned int v48; // w8
  __int64 v49; // x0
  __int64 v50; // [xsp+0h] [xbp-40h]
  __int64 v51; // [xsp+8h] [xbp-38h]
  __int64 v52; // [xsp+10h] [xbp-30h]
  __int64 v53; // [xsp+18h] [xbp-28h]
  __int64 v54; // [xsp+28h] [xbp-18h] BYREF
  __int64 v55[2]; // [xsp+30h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (unsigned __int8 *)(a1 + 1);
  v3 = *a1;
  v54 = 0;
  v55[0] = 0;
  if ( (unsigned int)tdls_get_vdev_objects(v3, v55, &v54) )
  {
    result = 4294966772LL;
    goto LABEL_8;
  }
  if ( (tdls_is_vdev_allowed_to_tx(v3) & 1) == 0 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: STA is not connected or not authenticated.",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tdls_validate_mgmt_request");
    goto LABEL_7;
  }
  if ( (mlo_mgr_is_link_switch_in_progress(v3) & 1) != 0 )
  {
    qdf_trace_msg(
      0,
      4u,
      "%s: vdev:%d Link Switch in progress. TDLS is not allowed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tdls_validate_mgmt_request",
      *(unsigned __int8 *)(v3 + 168));
LABEL_7:
    result = 4294967285LL;
    goto LABEL_8;
  }
  if ( *v2 != 3 )
  {
    if ( (tdls_check_is_tdls_allowed(v3) & 1) == 0 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: TDLS not allowed, reject MGMT, action = %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "tdls_validate_mgmt_request",
        *v2);
      result = 0xFFFFFFFFLL;
      goto LABEL_8;
    }
    if ( *(_DWORD *)(v54 + 8) <= 1u )
    {
      qdf_trace_msg(
        0,
        4u,
        "%s: %02x:%02x:%02x:**:**:%02x TDLS mode is disabled. action %d declined.",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "tdls_validate_mgmt_request",
        *((unsigned __int8 *)a1 + 9),
        *((unsigned __int8 *)a1 + 10),
        *((unsigned __int8 *)a1 + 11),
        *((unsigned __int8 *)a1 + 14),
        *((unsigned __int8 *)a1 + 8));
      result = 4294966772LL;
      goto LABEL_8;
    }
    v47 = *v2;
    if ( *(_BYTE *)(v54 + 214) == 1 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: nss switch in progress, action %d declined %02x:%02x:%02x:**:**:%02x",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "tdls_validate_mgmt_request",
        v47,
        *((unsigned __int8 *)a1 + 9),
        *((unsigned __int8 *)a1 + 10),
        *((unsigned __int8 *)a1 + 11),
        *((unsigned __int8 *)a1 + 14));
      goto LABEL_7;
    }
    if ( (unsigned int)v47 <= 2 && tdls_is_progress(v55[0], (char *)a1 + 9, 1) && !*((_BYTE *)a1 + 16) )
    {
      v42 = *((unsigned __int8 *)a1 + 8);
      v43 = *((unsigned __int8 *)a1 + 9);
      v44 = "%s: setup is ongoing. action %d declined for %02x:%02x:%02x:**:**:%02x";
      v45 = *((unsigned __int8 *)a1 + 10);
      v46 = *((unsigned __int8 *)a1 + 11);
      v40 = *((unsigned __int8 *)a1 + 14);
      goto LABEL_41;
    }
  }
  v21 = *(unsigned __int8 *)(v3 + 168);
  v22 = *(__int64 (__fastcall **)(_QWORD))(v54 + 248);
  if ( *((_DWORD *)v22 - 1) != 2116364946 )
    __break(0x8228u);
  if ( (v22(v21) & 1) != 0 )
  {
    v31 = 1;
  }
  else
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: admission ctrl set to VI, send the frame with least AC (BK) for action %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "tdls_validate_mgmt_request",
      *v2);
    v31 = 0;
  }
  v40 = *((unsigned __int8 *)a1 + 8);
  *((_BYTE *)a1 + 57) = v31;
  if ( v40 <= 1 )
  {
    if ( *(unsigned __int16 *)(v54 + 200) <= (unsigned int)*(unsigned __int16 *)(v54 + 202) )
    {
      result = tdls_validate_setup_frames();
      goto LABEL_8;
    }
    peer = tdls_find_peer(v55[0], (char *)a1 + 9);
    if ( peer )
    {
      v40 = *v2;
      if ( (*(_DWORD *)(peer + 36) & 0xFFFFFFFE) == 4 )
      {
        v42 = *((unsigned __int8 *)a1 + 9);
        v43 = *((unsigned __int8 *)a1 + 10);
        v44 = "%s: %02x:%02x:%02x:**:**:%02x already connected action %d declined.";
        v45 = *((unsigned __int8 *)a1 + 11);
        v46 = *((unsigned __int8 *)a1 + 14);
LABEL_41:
        LODWORD(v50) = v40;
        goto LABEL_42;
      }
    }
    else
    {
      v40 = *v2;
    }
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: tdls_mgmt %02x:%02x:%02x:**:**:%02x action %d, dialog_token %d status %d, len = %zu",
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
    v40,
    *((unsigned __int8 *)a1 + 15),
    *((unsigned __int8 *)a1 + 16),
    a1[3]);
  v48 = *((unsigned __int8 *)a1 + 8);
  *((_DWORD *)a1 + 8) = 0;
  if ( v48 == 3 )
  {
    v49 = tdls_find_peer(v55[0], (char *)a1 + 9);
    if ( !v49 )
    {
      v42 = *((unsigned __int8 *)a1 + 9);
      v43 = *((unsigned __int8 *)a1 + 10);
      v44 = "%s: %02x:%02x:%02x:**:**:%02x peer doesn't exist";
      v45 = *((unsigned __int8 *)a1 + 11);
      v46 = *((unsigned __int8 *)a1 + 14);
LABEL_42:
      qdf_trace_msg(
        0,
        2u,
        v44,
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
        v43,
        v45,
        v46,
        v50,
        v51,
        v52,
        v53);
      result = 0xFFFFFFFFLL;
      goto LABEL_8;
    }
    v40 = *(_DWORD *)(v49 + 36);
    if ( (v40 & 0xFFFFFFFE) != 4 )
    {
      v42 = *((unsigned __int8 *)a1 + 9);
      v44 = "%s: %02x:%02x:%02x:**:**:%02x peer doesn't exist or not connected %d dialog_token %d status %d, tdls_validate->len = %zu";
      v43 = *((unsigned __int8 *)a1 + 10);
      v45 = *((unsigned __int8 *)a1 + 11);
      v46 = *((unsigned __int8 *)a1 + 14);
      v53 = a1[3];
      LODWORD(v52) = *((unsigned __int8 *)a1 + 16);
      LODWORD(v51) = *((unsigned __int8 *)a1 + 15);
      goto LABEL_41;
    }
    v48 = *((unsigned __int8 *)a1 + 8);
    *((_DWORD *)a1 + 8) = *(unsigned __int8 *)(v49 + 40);
  }
  result = 0;
  if ( v48 <= 0xE && ((1 << v48) & 0x4006) != 0 )
  {
    tdls_set_cap(v55[0], (__int64)a1 + 9, 1);
    result = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
