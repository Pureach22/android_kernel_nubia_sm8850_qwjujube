__int64 __fastcall hdd_softap_deauth_current_sta(
        unsigned __int8 *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v13; // x23
  int v17; // w0
  int v18; // w22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  int v30; // w8
  const char *v31; // x2
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v43; // x8
  unsigned __int64 v44; // x23
  __int64 v45; // x8
  _QWORD v46[2]; // [xsp+10h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46[0] = a2;
  if ( !a1 )
  {
    v31 = "%s: link_info is NULL";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v31, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_softap_deauth_current_sta");
    result = 4;
    goto LABEL_24;
  }
  v11 = *(_QWORD *)a1;
  v13 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  if ( !v13 )
  {
    v31 = "%s: hdd_ctx is NULL";
    goto LABEL_13;
  }
  qdf_event_reset((__int64)(a1 + 168));
  if ( *(_DWORD *)a3 != -1 || *(__int16 *)(a3 + 4) != -1 )
    sme_send_disassoc_req_frame(*(_QWORD *)(v13 + 16), a1[8], a3, *(unsigned __int16 *)(a3 + 12), 0);
  v17 = hdd_softap_sta_deauth(a1, a3);
  if ( v17 )
  {
    v18 = v17;
    hdd_softap_set_sta_info_deauth_flag(v11);
    if ( a2 == -32 )
    {
      v29 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
    }
    else
    {
      v27 = *(unsigned __int8 *)(a2 + 32);
      v28 = *(unsigned __int8 *)(a2 + 33);
      v29 = *(unsigned __int8 *)(a2 + 34);
      v30 = *(unsigned __int8 *)(a2 + 37);
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev %d STA removal failed for %02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_softap_deauth_current_sta",
      a1[8],
      v27,
      v28,
      v29,
      v30);
    if ( v18 == 6 )
      result = 0;
    else
      result = 17;
    goto LABEL_24;
  }
  if ( *(_DWORD *)(a2 + 32) == -1 && *(__int16 *)(a2 + 36) == -1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v11 + 38872);
    }
    else
    {
      raw_spin_lock_bh(v11 + 38872);
      *(_QWORD *)(v11 + 38880) |= 1uLL;
    }
    hdd_get_front_sta_info_no_lock(v11 + 38848, v46);
    if ( v46[0] )
      hdd_take_sta_info_ref(v11 + 38848, v46[0], 0, 12);
    hdd_get_next_sta_info_no_lock(v11 + 38848);
    v43 = *(_QWORD *)(v11 + 38880);
    if ( (v43 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 38880) = v43 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11 + 38872);
      if ( v46[0] )
      {
LABEL_33:
        v44 = _ReadStatusReg(SP_EL0);
        do
        {
          while ( 1 )
          {
            hdd_softap_set_sta_info_deauth_flag(v11);
            hdd_put_sta_info_ref(v11 + 38848, v46, 1, 12);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v44 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v44 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v11 + 38872);
            }
            else
            {
              raw_spin_lock_bh(v11 + 38872);
              *(_QWORD *)(v11 + 38880) |= 1uLL;
            }
            v46[0] = 0;
            hdd_get_next_sta_info_no_lock(v11 + 38848);
            v45 = *(_QWORD *)(v11 + 38880);
            if ( (v45 & 1) != 0 )
              break;
            raw_spin_unlock(v11 + 38872);
            if ( !v46[0] )
              goto LABEL_45;
          }
          *(_QWORD *)(v11 + 38880) = v45 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v11 + 38872);
        }
        while ( v46[0] );
      }
    }
    else
    {
      raw_spin_unlock(v11 + 38872);
      if ( v46[0] )
        goto LABEL_33;
    }
LABEL_45:
    result = 0;
    goto LABEL_24;
  }
  hdd_softap_set_sta_info_deauth_flag(v11);
  result = qdf_wait_for_event_completion((__int64)(a1 + 168), 0x2710u);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Deauth time expired",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_softap_deauth_current_sta");
    result = 0;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
