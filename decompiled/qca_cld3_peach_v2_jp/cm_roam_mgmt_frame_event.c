__int64 __fastcall cm_roam_mgmt_frame_event(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  unsigned int v8; // w23
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x0
  char v14; // w9
  int v15; // w10
  int v16; // w8
  __int64 v17; // x0
  char v18; // w0
  unsigned int v19; // w8
  long double v20; // q0
  int v21; // w9
  char v22; // w8
  __int16 v23; // w10
  char v24; // w0
  unsigned __int64 v25; // x24
  unsigned __int8 *v26; // x23
  int v27; // w8
  char v28; // w9
  char v29; // w9
  unsigned __int64 v30; // t2
  char v31; // w10
  unsigned int v32; // w22
  char v33; // w9
  __int64 v34; // x8
  __int64 v35; // x0
  _BYTE s[331]; // [xsp+15h] [xbp-14Bh] BYREF

  *(_QWORD *)&s[323] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x143u);
  qdf_mem_set(s, 0x143u, 0);
  v8 = *(_DWORD *)(a2 + 8);
  *(_WORD *)&s[6] = *(unsigned __int8 *)(a1 + 104);
  *(_QWORD *)&s[8] = qdf_get_time_of_the_day_us();
  v13 = ktime_get(*(_QWORD *)&s[8], v9, v10, v11, v12);
  *(_QWORD *)&s[16] = 1000LL * v8;
  *(_QWORD *)&s[24] = v13 / 1000;
  qdf_mem_copy(s, (const void *)(a2 + 1), 6u);
  v14 = *(_BYTE *)(a2 + 22);
  v15 = *(unsigned __int16 *)(a2 + 20);
  s[32] = 5;
  v16 = *(_DWORD *)(a2 + 28);
  v17 = *(unsigned int *)(a2 + 16);
  s[33] = v14;
  *(_DWORD *)&s[48] = v15;
  *(_DWORD *)&s[52] = v16;
  v18 = wlan_convert_host_to_diag_tx_fail_reason(v17);
  v19 = *(_DWORD *)(a2 + 16);
  s[56] = v18;
  *(double *)&v20 = wlan_diag_get_tx_status(v19);
  v21 = *a3;
  v22 = *(_BYTE *)(a2 + 24);
  v23 = *(_WORD *)(a2 + 34);
  s[37] = v24;
  s[36] = v22;
  *(_WORD *)&s[42] = v23;
  if ( v21 == 1 && *((_WORD *)a3 + 2) )
  {
    v25 = 0;
    v26 = a3 + 97;
    while ( (unsigned int)qdf_mem_cmp(s, v26, 6u) )
    {
      if ( v25 <= 7 )
      {
        ++v25;
        v26 += 60;
        if ( *((unsigned __int16 *)a3 + 2) > (unsigned int)(unsigned __int16)v25 )
          continue;
      }
      goto LABEL_9;
    }
    *(_DWORD *)&s[52] = -*(_DWORD *)(v26 + 19);
  }
LABEL_9:
  if ( *(_BYTE *)(a2 + 12) != 3 )
  {
    HIDWORD(v30) = *(unsigned __int8 *)(a2 + 13);
    LODWORD(v30) = HIDWORD(v30);
    v27 = v30 >> 4;
    if ( v27 > 2 )
    {
      if ( v27 > 10 )
      {
        if ( v27 == 11 )
        {
          if ( *(_BYTE *)(a2 + 14) )
            LOWORD(v27) = 3;
          else
            LOWORD(v27) = 2;
          goto LABEL_43;
        }
        if ( v27 == 12 )
        {
          if ( *(_BYTE *)(a2 + 14) )
            LOWORD(v27) = 8;
          else
            LOWORD(v27) = 9;
          goto LABEL_43;
        }
      }
      else
      {
        if ( v27 == 3 )
        {
          LOWORD(v27) = 7;
          goto LABEL_43;
        }
        if ( v27 == 10 )
        {
          if ( !*(_BYTE *)(a2 + 14) )
            LOWORD(v27) = 11;
          goto LABEL_43;
        }
      }
      goto LABEL_37;
    }
    if ( v27 )
    {
      if ( v27 == 1 )
      {
        LOWORD(v27) = 5;
        goto LABEL_43;
      }
      if ( v27 != 2 )
      {
LABEL_37:
        LOWORD(v27) = 40;
        goto LABEL_43;
      }
      LOWORD(v27) = 6;
    }
    else
    {
      LOWORD(v27) = 4;
    }
LABEL_43:
    v33 = *(_BYTE *)(a2 + 36);
    v31 = s[39];
    v32 = 3355;
    *(_WORD *)&s[40] = v27;
    v29 = 4 * v33;
    goto LABEL_44;
  }
  LOWORD(v27) = (unsigned __int8)(*(_BYTE *)(a2 + 13) - 1) + 29;
  v28 = *(_BYTE *)(a2 + 36);
  if ( (unsigned int)*(unsigned __int8 *)(a2 + 13) - 1 >= 6 )
    LOWORD(v27) = 40;
  *(_WORD *)&s[40] = v27;
  if ( (v28 & 1) != 0 )
  {
    v29 = 4;
  }
  else if ( (v28 & 2) != 0 )
  {
    v29 = 8;
  }
  else if ( (v28 & 4) != 0 )
  {
    v29 = 12;
  }
  else
  {
    v29 = 0;
  }
  v31 = s[39];
  v32 = 3363;
LABEL_44:
  s[39] = v31 & 3 | v29;
  if ( (v27 & 0xFFFC) == 8 )
    s[38] = *(_BYTE *)(a2 + 24);
  if ( (v27 & 0xFFFD) == 8 )
    wlan_populate_vsie(a1, s, 0, v20);
  host_diag_event_report_payload(v32, 323, s);
  if ( (*(_WORD *)&s[40] & 0xFFFD) == 5 && *(_BYTE *)a4 == 1 && !*(_DWORD *)(a4 + 8) )
  {
    v34 = *(_QWORD *)(a1 + 152);
    if ( v34 )
      v35 = *(_QWORD *)(v34 + 80);
    else
      v35 = 0;
    wlan_connectivity_sta_info_event(v35, *(unsigned __int8 *)(a1 + 104), 1);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
