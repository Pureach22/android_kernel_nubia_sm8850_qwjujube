__int64 __fastcall drv_cmd_set_channel_switch(
        __int64 a1,
        __int64 *a2,
        char *s,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  const char *v12; // x2
  const char *v13; // x2
  size_t v17; // x0
  const char *v18; // x0
  int v19; // w8
  const char *v20; // x2
  char v21; // t1
  __int64 result; // x0
  unsigned int v23; // w20
  unsigned int v24; // w22
  unsigned __int8 v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w1
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w19
  __int64 v44; // [xsp+0h] [xbp-10h] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)a1;
  v44 = 0;
  if ( (*(_DWORD *)(v11 + 40) | 2) != 3 )
  {
    v13 = "%s: IOCTL CHANNEL_SWITCH not supported for mode %d";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "drv_cmd_set_channel_switch", v44, v45);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  if ( (*(_QWORD *)(a1 + 5968) & 2) == 0 )
  {
    v12 = "%s: SAP not started";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "drv_cmd_set_channel_switch", v44);
    goto LABEL_16;
  }
  v17 = strlen(s);
  v18 = (const char *)strnchr(s, v17, 32);
  if ( !v18 )
  {
    v20 = "%s: No argument after the command";
    goto LABEL_14;
  }
  v19 = *(unsigned __int8 *)v18;
  if ( v19 != 32 )
  {
    v20 = "%s: No space after the command ";
LABEL_14:
    qdf_trace_msg(0x33u, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_parse_set_channel_switch_command", v44, v45);
    v12 = "%s: Invalid CHANNEL_SWITCH command";
    goto LABEL_15;
  }
  while ( (unsigned __int8)v19 == 32 )
  {
    v21 = *++v18;
    LOBYTE(v19) = v21;
  }
  if ( !(_BYTE)v19 )
  {
    v20 = "%s: No argument followed by spaces";
    goto LABEL_14;
  }
  if ( sscanf(v18, "%u %u", (char *)&v44 + 4, &v44) != 2 )
  {
    v20 = "%s: Arguments retrieval from cmd string failed";
    goto LABEL_14;
  }
  if ( (int)v44 > 79 )
  {
    if ( (_DWORD)v44 == 80 )
    {
      v23 = 2;
      goto LABEL_30;
    }
    if ( (_DWORD)v44 == 160 )
    {
      v23 = 3;
      goto LABEL_30;
    }
    goto LABEL_27;
  }
  if ( (_DWORD)v44 == 20 )
  {
    v23 = 0;
    goto LABEL_30;
  }
  if ( (_DWORD)v44 != 40 )
  {
LABEL_27:
    v13 = "%s: BW %d is not allowed for CHANNEL_SWITCH";
    goto LABEL_5;
  }
  v23 = 1;
LABEL_30:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: CH:%d BW:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "drv_cmd_set_channel_switch",
    HIDWORD(v44),
    v44,
    v45);
  wlan_hdd_set_sap_csa_reason(*a2, *(_BYTE *)(a1 + 8), 2u);
  v24 = HIDWORD(v44);
  v25 = wlan_reg_max_5ghz_ch_num();
  v34 = HIDWORD(v44);
  if ( v24 <= v25 )
  {
    v34 = wlan_reg_legacy_chan_to_freq(a2[1], HIDWORD(v44), v26, v27, v28, v29, v30, v31, v32, v33);
    HIDWORD(v44) = v34;
  }
  result = hdd_softap_set_channel_change((__int64 *)a1, v34, 0, v23, 0, 0, 1);
  if ( (_DWORD)result )
  {
    v43 = result;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Set channel change fail",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "drv_cmd_set_channel_switch");
    result = v43;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
