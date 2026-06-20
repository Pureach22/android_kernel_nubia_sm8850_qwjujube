__int64 __fastcall dlm_is_bssid_in_reject_list(__int64 a1, __int64 a2)
{
  __int64 pdev_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 psoc_obj; // x0
  __int64 v15; // x21
  const char *v16; // x2
  __int64 result; // x0
  _QWORD *v18; // x1
  __int64 v20; // x24
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _QWORD *v41; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v42[2]; // [xsp+10h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = nullptr;
  v42[0] = 0;
  pdev_obj = dlm_get_pdev_obj();
  if ( !pdev_obj )
  {
    v16 = "%s: dlm_ctx is NULL";
    goto LABEL_7;
  }
  v13 = pdev_obj;
  psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
  if ( !psoc_obj )
  {
    v16 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
    goto LABEL_7;
  }
  v15 = psoc_obj;
  if ( (unsigned int)qdf_mutex_acquire(v13) )
  {
    v16 = "%s: failed to acquire reject_ap_list_lock";
LABEL_7:
    qdf_trace_msg(0x6Du, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "dlm_is_bssid_in_reject_list");
    goto LABEL_8;
  }
  qdf_list_peek_front((_QWORD *)(v13 + 64), v42);
  v18 = (_QWORD *)v42[0];
  if ( !v42[0] )
    goto LABEL_24;
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)(v13 + 64), v18, &v41);
    v20 = v42[0];
    dlm_update_ap_info(v42[0], v15 + 8, 0);
    if ( *(_BYTE *)(v20 + 104) )
      break;
    if ( v20 == -16 )
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
    }
    else
    {
      v29 = *(unsigned __int8 *)(v20 + 16);
      v30 = *(unsigned __int8 *)(v20 + 17);
      v31 = *(unsigned __int8 *)(v20 + 18);
      v32 = *(unsigned __int8 *)(v20 + 21);
    }
    qdf_trace_msg(
      0x6Du,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x cleared from list",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dlm_is_bssid_in_reject_list",
      v29,
      v30,
      v31,
      v32);
    qdf_list_remove_node(v13 + 64, (_QWORD *)v20);
    _qdf_mem_free(v20);
LABEL_16:
    v18 = v41;
    v41 = nullptr;
    v42[0] = v18;
    if ( !v18 )
      goto LABEL_24;
  }
  if ( *(_DWORD *)(v20 + 16) != *(_DWORD *)a2 || *(unsigned __int16 *)(v20 + 20) != *(unsigned __int16 *)(a2 + 4) )
    goto LABEL_16;
  qdf_trace_msg(
    0x6Du,
    8u,
    "%s: BSSID reject_ap_type 0x%x",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "dlm_is_bssid_in_reject_list",
    *(unsigned __int8 *)(v20 + 104));
  if ( (*(_BYTE *)(v20 + 104) & 0x13) != 0 )
  {
    qdf_trace_msg(
      0x6Du,
      8u,
      "%s: BSSID is present in deny list",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "dlm_is_bssid_in_reject_list");
    qdf_mutex_release(v13);
    result = 1;
    goto LABEL_9;
  }
LABEL_24:
  qdf_mutex_release(v13);
LABEL_8:
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
