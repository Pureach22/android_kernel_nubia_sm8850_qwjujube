__int64 __fastcall policy_mgr_get_allowed_tdls_offchannel_freq(__int64 a1, __int64 a2, _DWORD *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  int v15; // w21
  int connection_info; // w8
  char *v17; // x8
  int v18; // w8
  __int64 result; // x0
  __int64 *v20; // x8
  __int64 v21; // [xsp+0h] [xbp-30h] BYREF
  __int64 v22; // [xsp+8h] [xbp-28h] BYREF
  __int64 v23; // [xsp+10h] [xbp-20h] BYREF
  __int64 v24; // [xsp+18h] [xbp-18h]
  __int64 v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  *a3 = 0;
  if ( (policy_mgr_current_concurrency_is_mcc(a1) & 1) != 0 )
  {
    policy_mgr_dump_current_concurrency(a1);
    v14 = "%s: TDLS off channel not allowed in MCC";
LABEL_15:
    qdf_trace_msg(
      0x4Fu,
      8u,
      v14,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_get_allowed_tdls_offchannel_freq",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26);
    goto LABEL_16;
  }
  if ( (policy_mgr_is_sta_connected_2g(a1) & 1) == 0 )
  {
    v14 = "%s: STA not-connected on 2.4 Ghz";
    goto LABEL_15;
  }
  v15 = *(unsigned __int8 *)(a2 + 104);
  connection_info = (unsigned __int8)policy_mgr_get_connection_info(a1, &v21);
  if ( connection_info == 1 )
  {
LABEL_21:
    result = 1;
    goto LABEL_17;
  }
  if ( connection_info == 3 )
  {
    if ( HIDWORD(v21) == HIDWORD(v22) && HIDWORD(v21) == HIDWORD(v23) )
    {
LABEL_20:
      *a3 = 0;
      goto LABEL_21;
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v21), HIDWORD(v22)) & 1) == 0 )
    {
      if ( v15 == BYTE1(v21) )
        goto LABEL_30;
      if ( v15 == BYTE1(v22) )
        goto LABEL_36;
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v21), HIDWORD(v23)) & 1) == 0 )
    {
      if ( v15 == BYTE1(v21) )
      {
        v20 = &v23;
        goto LABEL_37;
      }
      if ( v15 == BYTE1(v23) )
      {
LABEL_36:
        v20 = &v21;
        goto LABEL_37;
      }
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v22), HIDWORD(v23)) & 1) != 0 )
      goto LABEL_16;
    if ( v15 == BYTE1(v22) )
    {
      v20 = &v23;
LABEL_37:
      v18 = *((_DWORD *)v20 + 1);
LABEL_38:
      *a3 = v18;
      result = 1;
      goto LABEL_17;
    }
    if ( v15 != BYTE1(v23) )
      goto LABEL_16;
LABEL_30:
    v20 = &v22;
    goto LABEL_37;
  }
  if ( connection_info != 2 )
  {
    v14 = "%s: TDLS off channel not allowed on > 3 port conc";
    goto LABEL_15;
  }
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
    v14 = "%s: Disable TDLS Off-Channel on non-DBS solution";
    goto LABEL_15;
  }
  if ( (policy_mgr_current_concurrency_is_scc(a1) & 1) != 0 )
    goto LABEL_20;
  if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
  {
    if ( v15 == BYTE1(v21) )
      v17 = (char *)&v22 + 4;
    else
      v17 = (char *)&v21 + 4;
    v18 = *(_DWORD *)v17;
    goto LABEL_38;
  }
LABEL_16:
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
