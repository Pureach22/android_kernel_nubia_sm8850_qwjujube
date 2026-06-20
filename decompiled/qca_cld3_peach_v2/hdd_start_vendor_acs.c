__int64 __fastcall hdd_start_vendor_acs(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  __int64 *v11; // x22
  unsigned int updated; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  const char *v22; // x2
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w0
  unsigned __int64 v48; // x9
  _BYTE v49[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 52832);
  v11 = *(__int64 **)(a1 + 24);
  v49[0] = 0;
  if ( (*(_BYTE *)(v10 + 2608) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Starting vendor app based ACS",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_create_acs_timer");
    v23 = _qdf_mem_malloc(0x10u, "hdd_create_acs_timer", 3324);
    if ( v23 )
    {
      *(_QWORD *)(v23 + 8) = a1;
      _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 + 52832) + 5968LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v48 = __ldxr(_X8);
      while ( __stxr(v48 | 8, _X8) );
      if ( !(unsigned int)qdf_mc_timer_init(
                            *(_QWORD *)(a1 + 52832) + 2440LL,
                            0,
                            (__int64)hdd_acs_response_timeout_handler,
                            v23) )
      {
        *(_BYTE *)(*(_QWORD *)(a1 + 52832) + 2608LL) = 1;
        goto LABEL_2;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to initialize acs response timeout timer",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_create_acs_timer");
      v21 = -14;
    }
    else
    {
      v21 = -12;
    }
    v22 = "%s: failed to create acs timer";
    goto LABEL_13;
  }
LABEL_2:
  updated = hdd_update_acs_timer_reason(a1, 0);
  if ( updated )
  {
    v21 = updated;
    v22 = "%s: failed to update acs timer reason";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_start_vendor_acs");
    goto LABEL_15;
  }
  if ( (unsigned int)wlan_mlme_get_acs_support_for_dfs_ltecoex(*v11, v49) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_acs_support_for_dfs_ltecoex failed, set def",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hdd_start_vendor_acs");
  v40 = wlan_sap_set_vendor_acs(*(_QWORD *)(*(_QWORD *)(a1 + 52832) + 272LL), v49[0] == 1);
  v21 = qdf_status_to_os_return(v40);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v21;
}
