__int64 __fastcall policy_mgr_need_opportunistic_upgrade(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1
  __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  int v35; // w25
  unsigned __int8 *v36; // x26
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int preferred_dbs_action_table; // w0
  int v46; // w8
  __int64 v47; // [xsp+0h] [xbp-30h]
  __int64 v48; // [xsp+10h] [xbp-20h] BYREF
  __int64 v49; // [xsp+18h] [xbp-18h]
  unsigned int v50; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v48 = 0;
  v49 = 0;
  if ( (policy_mgr_is_hwmode_offload_enabled() & 1) != 0 )
  {
    policy_mgr_get_sap_ch_width_update_action(a1, 255, 0, &v50, a2);
    result = v50;
    goto LABEL_48;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v23 = "%s: Invalid Context";
    goto LABEL_8;
  }
  v14 = context;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
    v25 = jiffies;
    if ( policy_mgr_need_opportunistic_upgrade___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: driver isn't dbs capable, no further action needed",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_need_opportunistic_upgrade");
      result = 0;
      policy_mgr_need_opportunistic_upgrade___last_ticks = v25;
    }
    else
    {
LABEL_11:
      result = 0;
    }
    goto LABEL_48;
  }
  if ( (unsigned int)policy_mgr_get_current_hw_mode(a1, &v48) )
  {
    v23 = "%s: policy_mgr_get_current_hw_mode failed";
LABEL_8:
    v24 = 2;
LABEL_9:
    qdf_trace_msg(0x4Fu, v24, v23, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_need_opportunistic_upgrade");
    result = 0;
    goto LABEL_48;
  }
  if ( !HIBYTE(v48) )
  {
    v23 = "%s: current HW mode is non-DBS capable";
    v24 = 8;
    goto LABEL_9;
  }
  qdf_mutex_acquire(v14 + 56);
  v34 = 0;
  v35 = 0;
  v36 = (unsigned __int8 *)&qword_81C458 + 4;
  while ( 1 )
  {
    LODWORD(v47) = *((_DWORD *)v36 - 2);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: index:%d mac:%d in_use:%d chan:%d org_nss:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "policy_mgr_need_opportunistic_upgrade",
      (unsigned int)v34,
      *(v36 - 16),
      *v36,
      *((unsigned int *)v36 - 6),
      v47);
    if ( *(v36 - 16) == 1 )
      break;
    if ( !*(v36 - 16) && *v36 == 1 )
    {
      v35 |= 1u;
      if ( v35 == 3 )
        goto LABEL_40;
    }
LABEL_15:
    ++v34;
    v36 += 36;
    if ( v34 == 5 )
    {
      if ( a2 )
        *a2 = 4;
      if ( dword_81C454 == 2 && BYTE4(qword_81C458) == 1
        || dword_81C478 == 2 && (qword_81C47C & 0x100000000LL) != 0
        || dword_81C49C == 2 && (qword_81C4A0 & 0x100000000LL) != 0
        || dword_81C4C0 == 2 && (qword_81C4C4 & 0x100000000LL) != 0
        || dword_81C4E4 == 2 && (qword_81C4E8 & 0x100000000LL) != 0 )
      {
        qdf_mutex_release(v14 + 56);
        result = 5;
      }
      else
      {
        qdf_mutex_release(v14 + 56);
        result = 4;
      }
      goto LABEL_48;
    }
  }
  if ( *v36 != 1 )
    goto LABEL_15;
  if ( (policy_mgr_is_hw_dbs_required_for_band(a1, 1) & 1) != 0 && wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v36 - 6)) )
  {
    qdf_mutex_release(v14 + 56);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: 2X2 DBS capable with 2.4 GHZ connection",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "policy_mgr_need_opportunistic_upgrade");
    goto LABEL_41;
  }
  v35 |= 2u;
  if ( v35 != 3 )
    goto LABEL_15;
LABEL_40:
  qdf_mutex_release(v14 + 56);
LABEL_41:
  if ( !HIBYTE(v48) || (policy_mgr_is_2x2_1x1_dbs_capable(a1) & 1) == 0 )
    goto LABEL_11;
  preferred_dbs_action_table = policy_mgr_get_preferred_dbs_action_table(a1, 255, 0, 0);
  v46 = preferred_dbs_action_table;
  if ( HIDWORD(v49) == 10 && preferred_dbs_action_table == 12 )
  {
    result = 13;
    if ( a2 )
      *a2 = 10;
  }
  else
  {
    result = 0;
    if ( HIDWORD(v49) == 12 && v46 == 10 )
    {
      if ( a2 )
        *a2 = 10;
      result = 11;
    }
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
