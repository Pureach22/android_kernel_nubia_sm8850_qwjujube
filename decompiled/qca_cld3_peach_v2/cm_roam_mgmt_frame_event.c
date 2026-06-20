__int64 __fastcall cm_roam_mgmt_frame_event(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  unsigned int v8; // w23
  __int64 v9; // x0
  char v10; // w9
  int v11; // w10
  int v12; // w8
  __int64 v13; // x0
  char v14; // w0
  unsigned int v15; // w8
  long double v16; // q0
  int v17; // w9
  char v18; // w8
  __int16 v19; // w10
  char v20; // w0
  unsigned __int64 v21; // x24
  unsigned __int8 *v22; // x23
  unsigned __int16 v23; // w8
  char v24; // w9
  char v25; // w9
  int v26; // w8
  unsigned __int64 v27; // t2
  unsigned int v28; // w22
  unsigned int v29; // w23
  int v30; // w9
  unsigned int v31; // w0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x4
  unsigned int v40; // w19
  __int64 result; // x0
  __int64 v42; // x1
  _BYTE *v43; // x21
  int v44; // t1
  __int64 v45; // x8
  __int64 v46; // x0
  _BYTE s[331]; // [xsp+15h] [xbp-14Bh] BYREF

  *(_QWORD *)&s[323] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x143u);
  qdf_mem_set(s, 0x143u, 0);
  v8 = *(_DWORD *)(a2 + 8);
  *(_WORD *)&s[6] = *(unsigned __int8 *)(a1 + 168);
  *(_QWORD *)&s[8] = qdf_get_time_of_the_day_us();
  v9 = ktime_get(*(_QWORD *)&s[8]);
  *(_QWORD *)&s[16] = 1000LL * v8;
  *(_QWORD *)&s[24] = v9 / 1000;
  qdf_mem_copy(s, (const void *)(a2 + 1), 6u);
  v10 = *(_BYTE *)(a2 + 22);
  v11 = *(unsigned __int16 *)(a2 + 20);
  s[32] = 5;
  v12 = *(_DWORD *)(a2 + 28);
  v13 = *(unsigned int *)(a2 + 16);
  s[33] = v10;
  *(_DWORD *)&s[48] = v11;
  *(_DWORD *)&s[52] = v12;
  v14 = wlan_convert_host_to_diag_tx_fail_reason(v13);
  v15 = *(_DWORD *)(a2 + 16);
  s[56] = v14;
  *(double *)&v16 = wlan_diag_get_tx_status(v15);
  v17 = *a3;
  v18 = *(_BYTE *)(a2 + 24);
  v19 = *(_WORD *)(a2 + 34);
  s[37] = v20;
  s[36] = v18;
  *(_WORD *)&s[42] = v19;
  if ( v17 == 1 && *((_WORD *)a3 + 2) )
  {
    v21 = 0;
    v22 = a3 + 97;
    while ( (unsigned int)qdf_mem_cmp(s, v22, 6u) )
    {
      if ( v21 <= 7 )
      {
        ++v21;
        v22 += 60;
        if ( *((unsigned __int16 *)a3 + 2) > (unsigned int)(unsigned __int16)v21 )
          continue;
      }
      goto LABEL_9;
    }
    *(_DWORD *)&s[52] = -*(_DWORD *)(v22 + 19);
  }
LABEL_9:
  if ( *(_BYTE *)(a2 + 12) == 3 )
  {
    v23 = (unsigned __int8)(*(_BYTE *)(a2 + 13) - 1) + 29;
    v24 = *(_BYTE *)(a2 + 36);
    if ( (unsigned int)*(unsigned __int8 *)(a2 + 13) - 1 >= 6 )
      v23 = 40;
    *(_WORD *)&s[40] = v23;
    if ( (v24 & 1) != 0 )
    {
      v25 = 4;
    }
    else if ( (v24 & 2) != 0 )
    {
      v25 = 8;
    }
    else if ( (v24 & 4) != 0 )
    {
      v25 = 12;
    }
    else
    {
      v25 = 0;
    }
    v28 = 0;
    v29 = 3363;
    s[39] = s[39] & 3 | v25;
    goto LABEL_49;
  }
  HIDWORD(v27) = *(unsigned __int8 *)(a2 + 13);
  LODWORD(v27) = HIDWORD(v27);
  v26 = v27 >> 4;
  if ( v26 > 2 )
  {
    if ( v26 > 10 )
    {
      if ( v26 == 11 )
      {
        if ( *(_BYTE *)(a2 + 14) )
          v23 = 3;
        else
          v23 = 2;
        goto LABEL_43;
      }
      if ( v26 == 12 )
      {
        if ( *(_BYTE *)(a2 + 14) )
          v23 = 8;
        else
          v23 = 9;
        goto LABEL_43;
      }
    }
    else
    {
      if ( v26 == 3 )
      {
        v23 = 7;
        goto LABEL_43;
      }
      if ( v26 == 10 )
      {
        if ( *(_BYTE *)(a2 + 14) )
          v23 = 10;
        else
          v23 = 11;
        goto LABEL_43;
      }
    }
    goto LABEL_37;
  }
  if ( v26 )
  {
    if ( v26 == 1 )
    {
      v23 = 5;
      goto LABEL_43;
    }
    if ( v26 != 2 )
    {
LABEL_37:
      v23 = 40;
      goto LABEL_43;
    }
    v23 = 6;
  }
  else
  {
    v23 = 4;
  }
LABEL_43:
  v30 = *(unsigned __int8 *)(a2 + 36);
  *(_WORD *)&s[40] = v23;
  s[39] = s[39] & 3 | (4 * v30);
  if ( v30 )
  {
    v31 = wlan_populate_roam_mld_log_param(a1, s, v23, v16);
    if ( v31 )
    {
      v39 = *(unsigned __int8 *)(a1 + 168);
      v40 = v31;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev: %d Unable to populate MLO parameter",
        *(double *)&v16,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "cm_roam_mgmt_frame_event",
        v39);
      result = v40;
      goto LABEL_64;
    }
    v23 = *(_WORD *)&s[40];
    v28 = 1;
  }
  else
  {
    v28 = 0;
  }
  v29 = 3355;
LABEL_49:
  if ( (v23 & 0xFFFC) == 8 )
    s[38] = *(_BYTE *)(a2 + 24);
  if ( (v23 & 0xFFFD) == 8 )
    wlan_populate_vsie(a1, s, 0, v16);
  host_diag_event_report_payload(v29, 323, s);
  if ( (*(_WORD *)&s[40] & 0xFFFD) == 5 )
  {
    v44 = *(unsigned __int8 *)(a2 + 40);
    v43 = (_BYTE *)(a2 + 40);
    if ( v44 == 1 )
      cm_roam_mlo_setup_event(a1, v42, v43);
    else
      wlan_connectivity_mlo_setup_event(a1, v28);
    if ( *(_BYTE *)a4 == 1 && !*(_DWORD *)(a4 + 8) )
    {
      v45 = *(_QWORD *)(a1 + 216);
      if ( v45 )
        v46 = *(_QWORD *)(v45 + 80);
      else
        v46 = 0;
      wlan_connectivity_sta_info_event(v46, *(unsigned __int8 *)(a1 + 168), 1);
    }
  }
  result = 0;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
