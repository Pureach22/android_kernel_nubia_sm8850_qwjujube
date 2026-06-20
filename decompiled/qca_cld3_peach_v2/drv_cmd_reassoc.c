__int64 __fastcall drv_cmd_reassoc(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  int v13; // w4
  __int64 v14; // x8
  __int64 v16; // x9
  __int64 v17; // x20
  __int64 v18; // x9
  __int64 v19; // x3
  const char *v20; // x2
  const char *v21; // x3
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x0
  unsigned int v33; // w0
  __int64 v34; // x10
  __int64 v35; // x11
  __int64 v37; // x9
  __int64 v38; // x21
  __int64 v39; // x9
  __int64 v40; // x20
  unsigned int v41; // [xsp+Ch] [xbp-34h] BYREF
  int v42; // [xsp+10h] [xbp-30h] BYREF
  __int16 v43; // [xsp+14h] [xbp-2Ch]
  int v44; // [xsp+18h] [xbp-28h] BYREF
  __int16 v45; // [xsp+1Ch] [xbp-24h]
  _QWORD v46[2]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_DWORD *)(a13 + 12);
  if ( v13 <= 25 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid command, total_len = %d", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_parse_reassoc");
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( *(_BYTE *)(a11 + 25) )
  {
    v14 = *a1;
    v46[0] = a11;
    v16 = *(_QWORD *)(v14 + 52832);
    v17 = *(_QWORD *)(v14 + 24);
    v41 = 0;
    v42 = 0;
    v18 = *(_QWORD *)(v16 + 32);
    v45 = 0;
    v44 = 0;
    v19 = *(_QWORD *)(v18 + 216);
    v43 = 0;
    if ( (unsigned int)hdd_parse_bssid_and_chan(v46, &v44, &v41, v19) )
    {
      v20 = "%s: Failed to parse reassoc command data";
      v21 = "hdd_parse_reassoc_v1";
LABEL_17:
      qdf_trace_msg(0x33u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, v21);
      goto LABEL_18;
    }
    qdf_mem_copy(&v42, &v44, 6u);
    result = hdd_check_and_reject_reassoc_command(a1, &v42);
    if ( !(_DWORD)result )
    {
      v31 = *a1;
      v32 = *(_QWORD *)(v17 + 8);
LABEL_10:
      v33 = ucfg_wlan_cm_roam_invoke(
              v32,
              *(unsigned __int8 *)(*(_QWORD *)(v31 + 52832) + 8LL),
              (unsigned __int8 *)&v42,
              v41,
              0x13u,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30);
      result = qdf_status_to_os_return(v33);
      goto LABEL_19;
    }
    goto LABEL_19;
  }
  v45 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  if ( (unsigned int)v13 <= 0x1F )
  {
    v20 = "%s: Invalid command length";
LABEL_16:
    v21 = "hdd_parse_reassoc_v2";
    goto LABEL_17;
  }
  v34 = *(_QWORD *)(a11 + 8);
  v35 = *(_QWORD *)(a11 + 16);
  v37 = *(_QWORD *)(*a1 + 52832);
  v38 = *(_QWORD *)(*a1 + 24);
  v47 = *(_QWORD *)(a11 + 24);
  v39 = *(_QWORD *)(v37 + 32);
  v46[0] = v34;
  v46[1] = v35;
  v40 = *(_QWORD *)(v39 + 216);
  if ( (mac_pton(v46, &v44) & 1) == 0 )
  {
    v20 = "%s: MAC address parsing failed";
    goto LABEL_16;
  }
  if ( (hdd_check_and_fill_freq(HIDWORD(v47), &v41, v40) & 1) == 0 )
    goto LABEL_18;
  qdf_mem_copy(&v42, &v44, 6u);
  result = hdd_check_and_reject_reassoc_command(a1, &v42);
  if ( !(_DWORD)result )
  {
    v31 = *a1;
    v32 = *(_QWORD *)(v38 + 8);
    goto LABEL_10;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
