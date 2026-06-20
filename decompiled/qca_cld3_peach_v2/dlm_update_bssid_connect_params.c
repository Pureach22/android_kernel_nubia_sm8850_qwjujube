__int64 __fastcall dlm_update_bssid_connect_params(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 pdev_obj; // x19
  __int64 psoc_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x24
  const char *v16; // x2
  __int64 result; // x0
  _QWORD *v18; // x1
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v40; // x22
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _QWORD *v57; // [xsp+10h] [xbp-20h] BYREF
  _QWORD *v58; // [xsp+18h] [xbp-18h] BYREF
  int v59; // [xsp+20h] [xbp-10h] BYREF
  __int16 v60; // [xsp+24h] [xbp-Ch]
  __int64 v61; // [xsp+28h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = a2;
  v60 = WORD2(a2);
  v57 = nullptr;
  v58 = nullptr;
  pdev_obj = dlm_get_pdev_obj(a1);
  psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
  if ( !pdev_obj || !psoc_obj )
  {
    v16 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
    goto LABEL_6;
  }
  v15 = psoc_obj;
  if ( (unsigned int)qdf_mutex_acquire(pdev_obj) )
  {
    v16 = "%s: failed to acquire reject_ap_list_lock";
LABEL_6:
    result = qdf_trace_msg(0x6Du, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "dlm_update_bssid_connect_params");
    goto LABEL_7;
  }
  qdf_list_peek_front((_QWORD *)(pdev_obj + 64), &v58);
  v18 = v58;
  if ( !v58 )
    goto LABEL_9;
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)(pdev_obj + 64), v18, &v57);
    v19 = (__int64)v58;
    if ( !v58 )
    {
      v18 = v57;
      if ( v57 )
        goto LABEL_10;
    }
    if ( !(unsigned int)qdf_mem_cmp(v58 + 2, &v59, 6u) )
      break;
    v18 = v57;
LABEL_10:
    v57 = nullptr;
    v58 = v18;
    if ( !v18 )
      goto LABEL_9;
  }
  if ( v19 == -16 )
  {
    v30 = 0;
    v28 = 0;
    v29 = 0;
    v31 = 0;
  }
  else
  {
    v28 = *(unsigned __int8 *)(v19 + 16);
    v29 = *(unsigned __int8 *)(v19 + 17);
    v30 = *(unsigned __int8 *)(v19 + 18);
    v31 = *(unsigned __int8 *)(v19 + 21);
  }
  qdf_trace_msg(
    0x6Du,
    8u,
    "%s: %02x:%02x:%02x:**:**:%02x present in DLM reject list, updating connect info con_state = %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "dlm_update_bssid_connect_params",
    v28,
    v29,
    v30,
    v31,
    a3);
  if ( v19 )
  {
    if ( a3 == 1 )
    {
      dlm_update_ap_info(v19, (_QWORD *)(v15 + 8), 0);
      if ( (*(_BYTE *)(v19 + 136) & 2) != 0 )
      {
        v40 = *(_QWORD *)(v19 + 112);
      }
      else
      {
        v40 = *(_QWORD *)(v19 + 152);
        if ( (*(_BYTE *)(v19 + 136) & 8) != 0 && *(_QWORD *)(v19 + 96) > v40 )
          v40 = *(_QWORD *)(v19 + 96);
      }
      if ( qdf_mc_timer_get_system_time() - v40 > 1000LL * *(_QWORD *)(v15 + 24) )
      {
        *(_BYTE *)(v19 + 136) &= 0xD1u;
        qdf_trace_msg(
          0x6Du,
          8u,
          "%s: updated reject ap type %d ",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "dlm_update_bssid_connect_params");
        if ( !*(_BYTE *)(v19 + 136) )
        {
          qdf_trace_msg(
            0x6Du,
            8u,
            "%s: Bad Bssid timer expired/AP cleared from all denylisting, removed %02x:%02x:%02x:**:**:%02x from list",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "dlm_update_bssid_connect_params",
            *(unsigned __int8 *)(v19 + 16),
            *(unsigned __int8 *)(v19 + 17),
            *(unsigned __int8 *)(v19 + 18),
            *(unsigned __int8 *)(v19 + 21));
          qdf_list_remove_node(pdev_obj + 64, (_QWORD *)v19);
          _qdf_mem_free(v19);
          dlm_send_reject_ap_list_to_fw(a1, pdev_obj + 64, v15 + 8);
        }
      }
    }
    else if ( a3 )
    {
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: Invalid AP connection state received %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "dlm_update_bssid_connect_params",
        a3);
    }
    else
    {
      *(_QWORD *)(v19 + 152) = qdf_mc_timer_get_system_time();
    }
  }
LABEL_9:
  result = qdf_mutex_release(pdev_obj);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
