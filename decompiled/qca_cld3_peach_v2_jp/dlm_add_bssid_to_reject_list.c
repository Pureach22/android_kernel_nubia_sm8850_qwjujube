__int64 __fastcall dlm_add_bssid_to_reject_list(__int64 a1, __int64 a2)
{
  __int64 pdev_obj; // x20
  __int64 psoc_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  __int64 result; // x0
  const char *v26; // x2
  _QWORD *v27; // x1
  __int64 v29; // x25
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  unsigned int v42; // w0
  unsigned int v43; // w19
  _QWORD *v44; // x0
  _QWORD *v45; // x23
  __int64 v46; // x1
  __int64 v47; // x0
  _QWORD *v48; // [xsp+0h] [xbp-20h] BYREF
  __int64 v49[3]; // [xsp+8h] [xbp-18h] BYREF

  v49[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = nullptr;
  v49[0] = 0;
  pdev_obj = dlm_get_pdev_obj();
  psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
  if ( !pdev_obj || (v14 = psoc_obj) == 0 )
  {
    v26 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
LABEL_9:
    qdf_trace_msg(0x6Du, 2u, v26, v6, v7, v8, v9, v10, v11, v12, v13, "dlm_add_bssid_to_reject_list");
    result = 4;
    goto LABEL_10;
  }
  if ( !(*(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4)) || (*(_BYTE *)a2 & 1) != 0 )
  {
    v26 = "%s: Zero/Broadcast BSSID received, entry not added";
    goto LABEL_9;
  }
  v15 = qdf_mutex_acquire(pdev_obj);
  if ( v15 )
  {
    v24 = v15;
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: failed to acquire reject_ap_list_lock",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dlm_add_bssid_to_reject_list");
    result = v24;
    goto LABEL_10;
  }
  qdf_list_peek_front((_QWORD *)(pdev_obj + 64), v49);
  v27 = (_QWORD *)v49[0];
  if ( v49[0] )
  {
    do
    {
      qdf_list_peek_next((_QWORD *)(pdev_obj + 64), v27, &v48);
      v29 = v49[0];
      dlm_update_ap_info(v49[0], (_QWORD *)(v14 + 8), 0);
      if ( *(_BYTE *)(v29 + 104) )
      {
        if ( *(_DWORD *)(v29 + 16) == *(_DWORD *)a2 && *(unsigned __int16 *)(v29 + 20) == *(unsigned __int16 *)(a2 + 4) )
        {
          v46 = v14 + 8;
          v47 = v29;
LABEL_29:
          dlm_modify_entry(v47, v46, a2);
          dlm_send_reject_ap_list_to_fw(a1, pdev_obj + 64, v14 + 8);
          qdf_mutex_release(pdev_obj);
          result = 0;
          goto LABEL_10;
        }
      }
      else
      {
        if ( v29 == -16 )
        {
          v40 = 0;
          v38 = 0;
          v39 = 0;
          v41 = 0;
        }
        else
        {
          v38 = *(unsigned __int8 *)(v29 + 16);
          v39 = *(unsigned __int8 *)(v29 + 17);
          v40 = *(unsigned __int8 *)(v29 + 18);
          v41 = *(unsigned __int8 *)(v29 + 21);
        }
        qdf_trace_msg(
          0x6Du,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x cleared from list",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "dlm_add_bssid_to_reject_list",
          v38,
          v39,
          v40,
          v41,
          v48);
        qdf_list_remove_node(pdev_obj + 64, (_QWORD *)v29);
        _qdf_mem_free(v29);
      }
      v27 = v48;
      v48 = nullptr;
      v49[0] = (__int64)v27;
    }
    while ( v27 );
  }
  if ( *(_DWORD *)(pdev_obj + 80) == 22 && (v42 = dlm_remove_lowest_delta_entry(pdev_obj + 64, v14 + 8)) != 0 )
  {
    v43 = v42;
    qdf_mutex_release(pdev_obj);
    result = v43;
  }
  else
  {
    v44 = (_QWORD *)_qdf_mem_malloc(0x80u, "dlm_add_bssid_to_reject_list", 1534);
    if ( v44 )
    {
      v45 = v44;
      qdf_list_insert_back((_QWORD *)(pdev_obj + 64), v44);
      v46 = v14 + 8;
      v47 = (__int64)v45;
      goto LABEL_29;
    }
    qdf_mutex_release(pdev_obj);
    result = 16;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
