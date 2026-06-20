__int64 __fastcall wlan_denylist_action_on_bssid(__int64 a1, __int64 a2)
{
  __int64 pdev_obj; // x19
  __int64 psoc_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x25
  const char *v15; // x2
  __int64 result; // x0
  _QWORD *v17; // x1
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _BOOL4 v38; // w10
  int v39; // w10
  unsigned int v40; // w20
  __int64 v41; // x4
  __int64 v42; // x5
  const char *v43; // x2
  __int64 v44; // x6
  __int64 v45; // x7
  __int64 v46; // [xsp+0h] [xbp-70h]
  __int64 v47; // [xsp+8h] [xbp-68h]
  __int64 v48; // [xsp+10h] [xbp-60h]
  __int64 v49; // [xsp+18h] [xbp-58h]
  _QWORD *v50; // [xsp+48h] [xbp-28h] BYREF
  _QWORD v51[4]; // [xsp+50h] [xbp-20h] BYREF

  v51[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = nullptr;
  v51[0] = 0;
  pdev_obj = dlm_get_pdev_obj();
  psoc_obj = dlm_get_psoc_obj(*(_QWORD *)(a1 + 80));
  if ( !pdev_obj || !psoc_obj )
  {
    v15 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
    goto LABEL_6;
  }
  v14 = psoc_obj;
  if ( !(unsigned int)qdf_mutex_acquire(pdev_obj) )
  {
    qdf_list_peek_front((_QWORD *)(pdev_obj + 64), v51);
    v17 = (_QWORD *)v51[0];
    if ( !v51[0] )
    {
LABEL_34:
      qdf_mutex_release(pdev_obj);
      goto LABEL_7;
    }
    while ( 1 )
    {
      qdf_list_peek_next((_QWORD *)(pdev_obj + 64), v17, &v50);
      v26 = v51[0];
      if ( *(_DWORD *)(v51[0] + 16LL) == *(_DWORD *)(a2 + 1)
        && *(unsigned __int16 *)(v51[0] + 20LL) == *(unsigned __int16 *)(a2 + 5) )
      {
        break;
      }
      if ( *(_QWORD *)(a2 + 1824) )
      {
        LODWORD(v47) = *(unsigned __int8 *)(a2 + 1913);
        LODWORD(v49) = *(unsigned __int8 *)(a2 + 1917);
        LODWORD(v48) = *(unsigned __int8 *)(a2 + 1914);
        LODWORD(v46) = *(unsigned __int8 *)(a2 + 1912);
        qdf_trace_msg(
          0x6Du,
          8u,
          "%s: dlm entry mld %02x:%02x:%02x:**:**:%02x entry mld%02x:%02x:%02x:**:**:%02x",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "dlm_is_mld_address_match",
          *(unsigned __int8 *)(v51[0] + 22LL),
          *(unsigned __int8 *)(v51[0] + 23LL),
          *(unsigned __int8 *)(v51[0] + 24LL),
          *(unsigned __int8 *)(v51[0] + 27LL),
          v46,
          v47,
          v48,
          v49);
        if ( *(_DWORD *)(v26 + 22) == *(_DWORD *)(a2 + 1912)
          && *(unsigned __int16 *)(v26 + 26) == *(unsigned __int16 *)(a2 + 1916) )
        {
          break;
        }
      }
      v17 = v50;
      v50 = nullptr;
      v51[0] = v17;
      if ( !v17 )
        goto LABEL_34;
    }
    dlm_update_ap_info(v26, v14 + 8, a2);
    if ( *(_BYTE *)(v26 + 136) )
    {
      v38 = *(_DWORD *)(v26 + 16) != *(_DWORD *)(a2 + 1)
         || *(unsigned __int16 *)(v26 + 20) != *(unsigned __int16 *)(a2 + 5);
      if ( (*(_BYTE *)(v26 + 136) & 0x13) != 0x10 || v38 )
      {
        if ( (*(_BYTE *)(v26 + 136) & 0x13) == 0 )
        {
          if ( (*(_BYTE *)(v26 + 136) & 0xC) != 0 )
          {
            if ( (*(_BYTE *)(v26 + 136) & 8) != 0
              && *(_DWORD *)(v26 + 22) | *(unsigned __int16 *)(v26 + 26)
              && *(_BYTE *)(v26 + 49) )
            {
              if ( (dlm_is_11be_entry_allowed(a1, a2, v26, pdev_obj + 64) & 1) != 0 )
                v40 = 0;
              else
                v40 = 3;
              goto LABEL_60;
            }
            if ( !v38 )
            {
              v41 = *(unsigned __int8 *)(a2 + 1);
              v42 = *(unsigned __int8 *)(a2 + 2);
              v43 = "%s: %02x:%02x:%02x:**:**:%02x in avoid list, reject ap type %d removing from candidate list";
              v44 = *(unsigned __int8 *)(a2 + 3);
              v45 = *(unsigned __int8 *)(a2 + 6);
              LODWORD(v46) = *(unsigned __int8 *)(v26 + 136);
LABEL_58:
              qdf_trace_msg(
                0x6Du,
                8u,
                v43,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                "dlm_prune_old_entries_and_get_action",
                v41,
                v42,
                v44,
                v45,
                v46);
              v40 = 3;
              goto LABEL_60;
            }
          }
LABEL_59:
          v40 = 0;
          goto LABEL_60;
        }
      }
      else if ( *(_DWORD *)(v26 + 72) > 0x3E418u )
      {
        if ( a2 )
          v39 = *(char *)(a2 + 60);
        else
          v39 = 0;
        LODWORD(v49) = *(_DWORD *)(v26 + 56);
        LODWORD(v48) = v39;
        LODWORD(v47) = *(char *)(v26 + 60);
        LODWORD(v46) = 255000;
        qdf_trace_msg(
          0x6Du,
          4u,
          "%s: Allow BSSID %02x:%02x:%02x:**:**:%02x as the retry delay is greater than %u ms, expected RSSI = %d, curren"
          "t RSSI = %d, retry delay = %u ms original timeout %u time added %lu source %d reason %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "dlm_prune_old_entries_and_get_action",
          *(unsigned __int8 *)(v26 + 16),
          *(unsigned __int8 *)(v26 + 17),
          *(unsigned __int8 *)(v26 + 18),
          *(unsigned __int8 *)(v26 + 21),
          v46,
          v47,
          v48,
          v49,
          *(_DWORD *)(v26 + 72),
          *(_QWORD *)(v26 + 64),
          *(_DWORD *)(v26 + 144),
          *(_DWORD *)(v26 + 140));
        if ( (*(_BYTE *)(v26 + 136) & 0xC) != 0 )
        {
          v41 = *(unsigned __int8 *)(v26 + 16);
          v42 = *(unsigned __int8 *)(v26 + 17);
          v43 = "%s: %02x:%02x:%02x:**:**:%02x in avoid list, deprioritize it";
          v44 = *(unsigned __int8 *)(v26 + 18);
          v45 = *(unsigned __int8 *)(v26 + 21);
          goto LABEL_58;
        }
        goto LABEL_59;
      }
      if ( (*(_BYTE *)(v26 + 136) & 2) == 0
        || !(*(_DWORD *)(v26 + 22) | *(unsigned __int16 *)(v26 + 26))
        || !*(_BYTE *)(v26 + 49) )
      {
        if ( !v38 )
        {
          LODWORD(v46) = *(unsigned __int8 *)(v26 + 136);
          qdf_trace_msg(
            0x6Du,
            8u,
            "%s: %02x:%02x:%02x:**:**:%02x in deny list, reject ap type %d removing from candidate list",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "dlm_prune_old_entries_and_get_action",
            *(unsigned __int8 *)(a2 + 1),
            *(unsigned __int8 *)(a2 + 2),
            *(unsigned __int8 *)(a2 + 3),
            *(unsigned __int8 *)(a2 + 6),
            v46);
          if ( (*(_BYTE *)(v26 + 136) & 0x11) != 0 )
          {
            if ( *(_DWORD *)(v26 + 140) < 4u )
              v40 = 1;
            else
              v40 = 2;
          }
          else
          {
            v40 = 1;
          }
          goto LABEL_60;
        }
        goto LABEL_59;
      }
      v40 = (dlm_is_11be_entry_allowed(a1, a2, v26, pdev_obj + 64) & 1) == 0;
    }
    else
    {
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x cleared from list",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "dlm_prune_old_entries_and_get_action",
        *(unsigned __int8 *)(v26 + 16),
        *(unsigned __int8 *)(v26 + 17),
        *(unsigned __int8 *)(v26 + 18),
        *(unsigned __int8 *)(v26 + 21));
      qdf_list_remove_node(pdev_obj + 64, (_QWORD *)v26);
      _qdf_mem_free(v26);
      v40 = 0;
    }
LABEL_60:
    qdf_mutex_release(pdev_obj);
    result = v40;
    goto LABEL_8;
  }
  v15 = "%s: failed to acquire reject_ap_list_lock";
LABEL_6:
  qdf_trace_msg(0x6Du, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "dlm_action_on_bssid");
LABEL_7:
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
