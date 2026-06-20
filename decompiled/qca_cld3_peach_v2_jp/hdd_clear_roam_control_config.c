__int64 __fastcall hdd_clear_roam_control_config(__int64 a1, __int64 a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _WORD *v14; // x2
  const char *v15; // x2
  __int64 v16; // x21
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w22
  unsigned int v36; // w0
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w20
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w19
  _QWORD s[41]; // [xsp+8h] [xbp-148h] BYREF

  s[40] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x140u);
  v14 = *(_WORD **)(a2 + 176);
  if ( !v14 )
  {
    v15 = "%s: Attribute CONTROL_CONFIG is not present";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "hdd_clear_roam_control_config");
    result = 4294967274LL;
    goto LABEL_8;
  }
  if ( ((__int16)v14[1] & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_6:
    v15 = "%s: nla_parse failed";
    goto LABEL_7;
  }
  v16 = *(_QWORD *)(a1 + 16);
  if ( (unsigned int)_nla_parse(s, 39, v14 + 2, (unsigned __int16)(*v14 - 4), &roam_control_policy, 31, 0) )
    goto LABEL_6;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Clear the control config done through SET",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "hdd_clear_roam_control_config");
  if ( s[3] )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Disable roam control config done through SET",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_clear_roam_control_config");
    v26 = sme_set_roam_config_enable(*(_QWORD *)(a1 + 16), a3, 0);
    if ( v26 )
    {
      v35 = v26;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to enable/disable roam control config",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_clear_roam_control_config");
      v36 = v35;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Reset roam trigger bitmap to 0x%x",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_clear_roam_control_config",
        0x1FFF);
      v37 = hdd_send_roam_triggers_to_sme(a1, a3, 0x1FFF, 0);
      if ( v37 )
      {
        v46 = v37;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to restore roam trigger bitmap",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_clear_roam_control_config");
        v36 = v46;
      }
      else
      {
        result = sme_roam_control_restore_default_config(v16, a3);
        if ( !(_DWORD)result )
          goto LABEL_8;
        v55 = result;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to config roam control",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "hdd_clear_roam_control_config");
        v36 = v55;
      }
    }
    result = qdf_status_to_os_return(v36);
    goto LABEL_8;
  }
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
