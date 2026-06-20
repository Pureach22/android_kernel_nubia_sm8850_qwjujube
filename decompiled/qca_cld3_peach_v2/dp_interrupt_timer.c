__int64 __fastcall dp_interrupt_timer(__int64 a1)
{
  _QWORD *v2; // x21
  int v3; // w20
  __int64 num_mac_rings; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w23
  unsigned int v7; // w22
  __int64 v8; // x9
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x22
  __int64 v21; // x0
  __int64 (__fastcall *v22)(_QWORD); // x8
  __int64 v23; // x0
  char v24; // w0
  __int64 v25; // x4
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w26
  unsigned int v35; // w25
  int v36; // w24
  const char *v37; // x2
  const char *v38; // x3
  __int64 v39; // x8
  _DWORD *v40; // x8
  int v41; // w0
  __int64 v42; // x8
  __int64 v43; // x8
  _DWORD *v44; // x8
  unsigned __int64 v45; // x8
  __int64 v46; // x21
  __int64 v47; // x1
  __int64 v48; // x0
  __int64 v49; // x21
  __int64 v50; // x20
  _DWORD *v51; // x8
  __int64 v52; // x20
  unsigned int multiplier; // w0
  __int64 v54; // x21
  unsigned __int64 v55; // [xsp+0h] [xbp-30h]
  __int64 v56; // [xsp+0h] [xbp-30h]
  __int64 v57; // [xsp+8h] [xbp-28h] BYREF
  __int64 v58; // [xsp+10h] [xbp-20h]
  __int64 v59; // [xsp+18h] [xbp-18h]
  __int64 v60; // [xsp+20h] [xbp-10h]
  __int64 v61; // [xsp+28h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 72);
  LOBYTE(v3) = wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40));
  num_mac_rings = wlan_cfg_get_num_mac_rings(v2[36]);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = num_mac_rings;
  ++*(_DWORD *)(StatusReg + 16);
  v7 = *(_DWORD *)(StatusReg + 40);
  v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v8;
  if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
    preempt_schedule(num_mac_rings);
  result = wlan_cfg_is_poll_mode_enabled(*(_QWORD *)(a1 + 40));
  if ( (result & 1) != 0 )
  {
    result = wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40));
    if ( !(_DWORD)result )
    {
      if ( !*(_DWORD *)(a1 + 56) )
        goto LABEL_62;
      if ( (int)wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40)) < 1 )
      {
LABEL_61:
        v52 = jiffies;
        multiplier = qdf_timer_get_multiplier();
        result = mod_timer(a1 + 17784, v52 + 2LL * multiplier);
        goto LABEL_62;
      }
      v49 = 0;
      v50 = a1 + 7848;
      while ( v49 != 19 )
      {
        v51 = *(_DWORD **)(a1 + 1872);
        if ( *(v51 - 1) != -4250500 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v51)(v50, 0xFFFF, v7);
        ++v49;
        v50 += 200;
        if ( v49 >= (int)wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40)) )
          goto LABEL_61;
      }
      goto LABEL_65;
    }
  }
  if ( !*(_DWORD *)(a1 + 56) )
    goto LABEL_62;
  if ( !v2 )
    goto LABEL_9;
  v18 = v2[12057];
  if ( !v18 )
    goto LABEL_9;
  v19 = *(unsigned int *)(v18 + 32);
  if ( (_DWORD)v19 == 3 )
    goto LABEL_9;
  if ( (unsigned int)v19 > 2 )
LABEL_65:
    __break(0x5512u);
  v20 = *((unsigned int *)v2 + v19 + 68);
  if ( (_DWORD)v20 != -1 )
  {
    if ( (unsigned int)v20 <= 1 )
    {
      v21 = *(_QWORD *)(a1 + 64);
      v59 = 0;
      v60 = 0;
      v3 = *(_DWORD *)(a1 + 4 * v20 + 11448);
      v57 = 0;
      v58 = 0;
      LODWORD(v60) = 1;
      hif_hist_record_event(v21, (__int64)&v57, v3);
      goto LABEL_14;
    }
    goto LABEL_65;
  }
LABEL_9:
  LODWORD(v20) = -1;
LABEL_14:
  __isb(0xFu);
  v55 = _ReadStatusReg(CNTVCT_EL0);
  v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 40LL);
  if ( v22 )
  {
    v23 = *(_QWORD *)(a1 + 16);
    if ( *((_DWORD *)v22 - 1) != -1548408 )
      __break(0x8228u);
    v24 = v22(v23);
    v25 = v24 & 1;
    if ( (v24 & 1) == 0 )
      v6 = 1;
  }
  else
  {
    v25 = 0;
    v6 = 1;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: dbs_enable %d, max_mac_rings %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "dp_update_num_mac_rings_for_dbs",
    v25,
    v6,
    v55);
  v34 = 0xFFFF;
  do
  {
    if ( v6 )
    {
      v35 = 0;
      v36 = 0;
      while ( 1 )
      {
        if ( (_DWORD)v20 == v35 )
        {
          if ( (unsigned __int8)v3 > 0x12u )
            goto LABEL_65;
          v39 = *(_QWORD *)(a1 + 20112);
          if ( !v39 )
          {
            v37 = "%s: monitor soc is NULL";
            goto LABEL_46;
          }
          v40 = *(_DWORD **)(v39 + 432);
          if ( !v40 )
          {
            v37 = "%s: callback not registered";
LABEL_46:
            v38 = "dp_monitor_process";
LABEL_25:
            qdf_trace_msg(0x92u, 8u, v37, v26, v27, v28, v29, v30, v31, v32, v33, v38);
            goto LABEL_26;
          }
          if ( *(v40 - 1) != 208847759 )
            __break(0x8228u);
          v41 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v40)(
                  a1,
                  a1 + 200LL * (unsigned __int8)v3 + 7848,
                  (unsigned int)v20,
                  (unsigned int)v34);
          if ( !v41 )
            goto LABEL_26;
        }
        else
        {
          v42 = *(_QWORD *)(v2[1] + 20112LL);
          if ( !v42 )
          {
            v37 = "%s: monitor soc is NULL";
            goto LABEL_24;
          }
          v43 = *(_QWORD *)(v42 + 416);
          if ( !v43 || (v44 = *(_DWORD **)(v43 + 232)) == nullptr )
          {
            v37 = "%s: callback not registered";
LABEL_24:
            v38 = "dp_monitor_drop_packets_for_mac";
            goto LABEL_25;
          }
          if ( *(v44 - 1) != 1758040130 )
            __break(0x8228u);
          v41 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD))v44)(v2, v35, (unsigned int)v34, 0);
          if ( !v41 )
            goto LABEL_26;
        }
        v34 -= v41;
        if ( v34 < 1 )
          goto LABEL_51;
        v36 += v41;
LABEL_26:
        if ( v6 == ++v35 )
          goto LABEL_48;
      }
    }
    v36 = 0;
LABEL_48:
    __isb(0xFu);
    v45 = _ReadStatusReg(CNTVCT_EL0);
  }
  while ( v36 && v45 - v56 < 0x5DC01 );
  if ( v36 )
  {
LABEL_51:
    v46 = jiffies;
    v47 = v46 + (unsigned int)qdf_timer_get_multiplier();
  }
  else
  {
    v54 = jiffies;
    v47 = v54 + 2LL * (unsigned int)qdf_timer_get_multiplier();
  }
  result = mod_timer(a1 + 17784, v47);
  if ( (_DWORD)v20 != -1 )
  {
    v48 = *(_QWORD *)(a1 + 64);
    v59 = 0;
    v57 = 0;
    v58 = 0;
    v60 = 2;
    result = hif_hist_record_event(v48, (__int64)&v57, v3);
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
