__int64 __fastcall tdls_scan_callback(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w21
  unsigned int v4; // w0
  __int64 result; // x0
  __int64 v6; // x20
  __int64 comp_private_obj; // x0
  unsigned int *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  __int64 v27; // x22
  unsigned int v28; // w22
  int v29; // w4
  int v30; // w8
  unsigned __int64 v31; // x25
  bool v32; // w23
  __int64 v33; // x24
  _QWORD *v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v35[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(a1 + 8)
    || (v1 = *(_QWORD *)a1, v3 = policy_mgr_mode_specific_vdev_id(*(_QWORD *)a1, 0), v3 == 255)
    && ((v4 = policy_mgr_mode_specific_vdev_id(v1, 2), v4 == 255)
     || (v3 = v4, (unsigned int)policy_mgr_get_connection_count_with_mlo(v1) != 1)) )
  {
    result = 0;
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v1, v3, 17);
    if ( result )
    {
      v6 = result;
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 0xAu);
      if ( !comp_private_obj )
      {
        v28 = 0;
LABEL_39:
        wlan_objmgr_vdev_release_ref(v6, 0x11u, v8, v9, v10, v11, v12, v13, v14, v15, v16);
        result = v28;
        goto LABEL_40;
      }
      v17 = comp_private_obj;
      if ( tdls_is_progress(comp_private_obj, 0, 0) )
      {
        v26 = *(_DWORD *)(a1 + 16);
        *(_DWORD *)(a1 + 16) = v26 + 1;
        v27 = jiffies;
        if ( v26 < 5 )
        {
          if ( tdls_scan_callback___last_ticks_58 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0,
              3u,
              "%s: tdls in progress. scan rejected %d",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "tdls_scan_callback");
            tdls_scan_callback___last_ticks_58 = v27;
          }
          v28 = 8;
          v29 = *(unsigned __int16 *)(a1 + 202);
          if ( !*(_WORD *)(a1 + 202) )
            goto LABEL_38;
        }
        else
        {
          if ( tdls_scan_callback___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0,
              4u,
              "%s: Allow scan during tdls, as scan reject count %d reached threshold",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "tdls_scan_callback");
            tdls_scan_callback___last_ticks = v27;
          }
          v28 = 0;
          *(_DWORD *)(a1 + 16) = 0;
          v29 = *(unsigned __int16 *)(a1 + 202);
          if ( !*(_WORD *)(a1 + 202) )
            goto LABEL_38;
        }
      }
      else
      {
        v28 = 0;
        v29 = *(unsigned __int16 *)(a1 + 202);
        if ( !*(_WORD *)(a1 + 202) )
        {
LABEL_38:
          tdls_set_current_mode(a1, 0, 0, 1u, v18, v19, v20, v21, v22, v23, v24, v25);
          goto LABEL_39;
        }
      }
      v30 = *(_DWORD *)(a1 + 156);
      if ( (v30 & 0x10) != 0 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: TDLS Scan enabled so allow scan, tdls peers cnt %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "tdls_scan_callback");
      }
      else
      {
        if ( v29 != 1 || (v30 & 4) == 0 )
          goto LABEL_37;
        v31 = 0;
        v32 = 0;
        v33 = v17 + 8;
        v35[0] = nullptr;
        while ( (unsigned int)qdf_list_peek_front((_QWORD *)(v33 + 24 * v31), v35) )
        {
LABEL_24:
          v32 = v31++ > 0xE;
          if ( v31 == 16 )
            goto LABEL_34;
        }
        while ( !v35[0] || *((_DWORD *)v35[0] + 9) != 4 || *((_BYTE *)v35[0] + 50) )
        {
          if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v33 + 24 * v31), v35[0], v35) )
            goto LABEL_24;
        }
LABEL_34:
        if ( v32 )
          qdf_trace_msg(
            0,
            8u,
            "%s: All peers (num %d) bufSTAs, we can be sleep sta, so allow scan, tdls mode changed to %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "tdls_scan_callback",
            1,
            *(unsigned int *)(a1 + 8));
        else
LABEL_37:
          tdls_disable_offchan_and_teardown_links(v6, v18, v19, v20, v21, v22, v23, v24, v25);
      }
      goto LABEL_38;
    }
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
