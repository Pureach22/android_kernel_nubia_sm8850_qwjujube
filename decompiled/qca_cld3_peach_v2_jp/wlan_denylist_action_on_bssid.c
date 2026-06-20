__int64 __fastcall wlan_denylist_action_on_bssid(__int64 a1, __int64 a2)
{
  __int64 pdev_obj; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 psoc_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  const char *v17; // x2
  __int64 result; // x0
  _QWORD *v19; // x1
  __int64 v20; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  bool v30; // zf
  int v31; // w9
  int v32; // w10
  int v33; // w11
  __int64 v34; // x4
  __int64 v35; // x5
  const char *v36; // x2
  __int64 v37; // x6
  __int64 v38; // x7
  unsigned int v39; // w20
  __int64 v40; // [xsp+0h] [xbp-60h]
  _QWORD *v41; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v42[2]; // [xsp+50h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = nullptr;
  v42[0] = 0;
  pdev_obj = dlm_get_pdev_obj();
  v5 = *(_QWORD *)(a1 + 80);
  v6 = pdev_obj;
  psoc_obj = dlm_get_psoc_obj(v5);
  if ( !v6 || !psoc_obj )
  {
    v17 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
    goto LABEL_6;
  }
  v16 = psoc_obj;
  if ( !(unsigned int)qdf_mutex_acquire(v6) )
  {
    qdf_list_peek_front((_QWORD *)(v6 + 64), v42);
    v19 = (_QWORD *)v42[0];
    if ( !v42[0] )
    {
LABEL_15:
      qdf_mutex_release(v6);
      goto LABEL_7;
    }
    while ( 1 )
    {
      qdf_list_peek_next((_QWORD *)(v6 + 64), v19, &v41);
      v20 = v42[0];
      if ( *(_DWORD *)(v42[0] + 16LL) == *(_DWORD *)(a2 + 1)
        && *(unsigned __int16 *)(v42[0] + 20LL) == *(unsigned __int16 *)(a2 + 5) )
      {
        break;
      }
      v19 = v41;
      v41 = nullptr;
      v42[0] = v19;
      if ( !v19 )
        goto LABEL_15;
    }
    dlm_update_ap_info(v42[0], v16 + 8, a2);
    if ( !*(_BYTE *)(v20 + 104) )
    {
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x cleared from list",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dlm_prune_old_entries_and_get_action",
        *(unsigned __int8 *)(v20 + 16),
        *(unsigned __int8 *)(v20 + 17),
        *(unsigned __int8 *)(v20 + 18),
        *(unsigned __int8 *)(v20 + 21));
      qdf_list_remove_node(v6 + 64, (_QWORD *)v20);
      _qdf_mem_free(v20);
      goto LABEL_42;
    }
    v30 = *(_DWORD *)(v20 + 16) == *(_DWORD *)(a2 + 1)
       && *(unsigned __int16 *)(v20 + 20) == *(unsigned __int16 *)(a2 + 5);
    v31 = *(_BYTE *)(v20 + 104) & 0x13;
    v32 = !v30;
    if ( v31 != 16 || v32 )
    {
      if ( (*(_BYTE *)(v20 + 104) & 0x13) == 0 )
      {
        if ( (*(_BYTE *)(v20 + 104) & 0xC) == 0 || v32 )
          goto LABEL_43;
        v34 = *(unsigned __int8 *)(a2 + 1);
        v35 = *(unsigned __int8 *)(a2 + 2);
        v36 = "%s: %02x:%02x:%02x:**:**:%02x in avoid list, reject ap type %d removing from candidate list";
        v37 = *(unsigned __int8 *)(a2 + 3);
        v38 = *(unsigned __int8 *)(a2 + 6);
        LODWORD(v40) = *(unsigned __int8 *)(v20 + 104);
        goto LABEL_41;
      }
      if ( v32 )
      {
LABEL_42:
        v31 = 0;
        goto LABEL_43;
      }
    }
    else if ( *(_DWORD *)(v20 + 40) > 0x3E418u )
    {
      if ( a2 )
        v33 = *(char *)(a2 + 60);
      else
        v33 = 0;
      qdf_trace_msg(
        0x6Du,
        4u,
        "%s: Allow BSSID %02x:%02x:%02x:**:**:%02x as the retry delay is greater than %u ms, expected RSSI = %d, current "
        "RSSI = %d, retry delay = %u ms original timeout %u time added %lu source %d reason %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dlm_prune_old_entries_and_get_action",
        *(unsigned __int8 *)(v20 + 16),
        *(unsigned __int8 *)(v20 + 17),
        *(unsigned __int8 *)(v20 + 18),
        *(unsigned __int8 *)(v20 + 21),
        255000,
        *(char *)(v20 + 28),
        v33,
        *(_DWORD *)(v20 + 24),
        *(_DWORD *)(v20 + 40),
        *(_QWORD *)(v20 + 32),
        *(_DWORD *)(v20 + 112),
        *(_DWORD *)(v20 + 108));
      if ( (*(_BYTE *)(v20 + 104) & 0xC) != 0 )
      {
        v34 = *(unsigned __int8 *)(v20 + 16);
        v35 = *(unsigned __int8 *)(v20 + 17);
        v36 = "%s: %02x:%02x:%02x:**:**:%02x in avoid list, deprioritize it";
        v37 = *(unsigned __int8 *)(v20 + 18);
        v38 = *(unsigned __int8 *)(v20 + 21);
LABEL_41:
        qdf_trace_msg(
          0x6Du,
          8u,
          v36,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "dlm_prune_old_entries_and_get_action",
          v34,
          v35,
          v37,
          v38,
          v40);
        v31 = 3;
LABEL_43:
        v39 = v31;
        qdf_mutex_release(v6);
        result = v39;
        goto LABEL_8;
      }
      goto LABEL_42;
    }
    qdf_trace_msg(
      0x6Du,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x in deny list, reject ap type %d removing from candidate list",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dlm_prune_old_entries_and_get_action",
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6),
      *(unsigned __int8 *)(v20 + 104));
    v31 = 1;
    if ( (*(_BYTE *)(v20 + 104) & 0x11) != 0 )
    {
      if ( *(_DWORD *)(v20 + 108) < 4u )
        v31 = 1;
      else
        v31 = 2;
    }
    goto LABEL_43;
  }
  v17 = "%s: failed to acquire reject_ap_list_lock";
LABEL_6:
  qdf_trace_msg(0x6Du, 2u, v17, v8, v9, v10, v11, v12, v13, v14, v15, "dlm_action_on_bssid");
LABEL_7:
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
