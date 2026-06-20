__int64 __fastcall dp_psoc_obj_create_notification(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v3; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 values; // x0
  unsigned __int16 v13; // w22
  int v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x2
  const char *v26; // x1
  unsigned int v27; // w22
  int conparam; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w4
  int v38; // w22
  int v39; // w8
  __int64 v40; // x8
  __int64 v41; // x0
  int v42; // w8
  __int64 v43; // x0
  _QWORD v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = gp_dp_ctx;
  v3 = wlan_objmgr_psoc_component_obj_attach(a1, 0x2Eu, gp_dp_ctx, 0);
  if ( !v3 )
  {
    *(_QWORD *)v2 = a1;
    values = cfg_psoc_get_values(a1);
    v13 = strlen((const char *)(values + 3964)) + 1;
    *(_DWORD *)(v2 + 56) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4044);
    *(_DWORD *)(v2 + 60) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4048);
    *(_DWORD *)(v2 + 64) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4052);
    *(_DWORD *)(v2 + 68) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4060);
    *(_DWORD *)(v2 + 72) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4056);
    *(_DWORD *)(v2 + 76) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4064);
    *(_DWORD *)(v2 + 80) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4068);
    *(_DWORD *)(v2 + 84) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4072);
    *(_DWORD *)(v2 + 88) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4076);
    *(_DWORD *)(v2 + 128) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4108);
    *(_BYTE *)(v2 + 132) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4112);
    *(_BYTE *)(v2 + 96) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4080);
    v14 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4084);
    if ( (v14 & 1) != 0 )
    {
      *(_DWORD *)(v2 + 100) = 1;
      if ( (v14 & 2) != 0 )
        *(_BYTE *)(v2 + 104) = 1;
    }
    *(_DWORD *)(v2 + 92) = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 4088);
    *(_DWORD *)(v2 + 108) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4092);
    *(_DWORD *)(v2 + 112) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4096);
    *(_DWORD *)(v2 + 120) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4100);
    *(_DWORD *)(v2 + 116) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4104);
    *(_BYTE *)(v2 + 124) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4024);
    *(_BYTE *)(v2 + 222) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4151);
    *(_BYTE *)(v2 + 223) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4152);
    *(_DWORD *)(v2 + 136) = *(_DWORD *)(cfg_psoc_get_values(a1) + 3960);
    *(_DWORD *)(v2 + 140) = *(_DWORD *)(cfg_psoc_get_values(a1) + 3956);
    if ( v13 > 0x1Du )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: ini string length greater than max size %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "dp_cfg_init",
        30);
      v26 = "e";
      v24 = v2 + 144;
      v25 = 1;
    }
    else
    {
      v23 = cfg_psoc_get_values(a1);
      v24 = v2 + 144;
      v25 = v13;
      v26 = (const char *)(v23 + 3964);
    }
    sized_strscpy(v24, v26, v25);
    *(_BYTE *)(v2 + 24) = *(_BYTE *)(cfg_psoc_get_values(a1) + 3995);
    v27 = *(_DWORD *)(cfg_psoc_get_values(a1) + 3996);
    *(_DWORD *)(v2 + 28) = v27;
    conparam = cds_get_conparam();
    if ( (~v27 & 0xA) != 0 )
      v37 = v27;
    else
      v37 = v27 & 0xFFFFFFF7;
    v38 = conparam;
    if ( (~v37 & 3) != 0 )
    {
      if ( (v37 & 1) != 0 )
      {
        *(_BYTE *)(v2 + 370) = 1;
        if ( (v37 & 2) != 0 )
          goto LABEL_26;
        goto LABEL_20;
      }
      if ( (v37 & 0x10) == 0 )
      {
        if ( (v37 & 2) != 0 )
          goto LABEL_26;
        goto LABEL_20;
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: rx_mode wrong configuration. Make it default",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "dp_set_rx_mode_value");
      LOBYTE(v37) = 20;
    }
    if ( v38 == 4 )
    {
      *(_BYTE *)(v2 + 371) = 0;
      if ( (v37 & 2) != 0 )
        goto LABEL_26;
    }
    else
    {
      *(_BYTE *)(v2 + 371) = 1;
      if ( (v37 & 2) != 0 )
      {
LABEL_26:
        *(_BYTE *)(v2 + 368) = 1;
        if ( (v37 & 4) != 0 )
        {
LABEL_27:
          *(_BYTE *)(v2 + 372) = 1;
          if ( (v37 & 8) != 0 )
            goto LABEL_28;
          goto LABEL_22;
        }
LABEL_21:
        if ( (v37 & 8) != 0 )
        {
LABEL_28:
          v39 = 1;
          *(_BYTE *)(v2 + 369) = 1;
          goto LABEL_29;
        }
LABEL_22:
        v39 = *(unsigned __int8 *)(v2 + 369);
LABEL_29:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: rx_mode:%u dp_rx_threads:%u rx_thread:%u napi:%u rps:%u dynamic rps %u",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "dp_set_rx_mode_value",
          *(unsigned __int8 *)(v2 + 368),
          v39);
        *(_BYTE *)(v2 + 174) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4025);
        *(_DWORD *)(v2 + 176) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4028);
        *(_BYTE *)(v2 + 180) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4032);
        *(_DWORD *)(v2 + 212) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4036);
        v40 = *(unsigned int *)(cfg_psoc_get_values(a1) + 4012);
        v45[0] = 0;
        *(_QWORD *)(v2 + 48) = v40;
        *(_BYTE *)(v2 + 181) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4120);
        v41 = cfg_psoc_get_values(a1);
        qdf_uint8_array_parse((_BYTE *)(v41 + 4121), v2 + 182, 20, v45);
        *(_DWORD *)(v2 + 204) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4144);
        v42 = *(_DWORD *)(cfg_psoc_get_values(a1) + 4116);
        v45[0] = 0;
        *(_BYTE *)(v2 + 202) = v42;
        *(_BYTE *)(v2 + 181) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4120);
        v43 = cfg_psoc_get_values(a1);
        qdf_uint8_array_parse((_BYTE *)(v43 + 4121), v2 + 182, 20, v45);
        *(_DWORD *)(v2 + 204) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4144);
        dp_fisa_cfg_init(v2 + 24, a1);
        *(_BYTE *)(v2 + 220) = *(_BYTE *)(cfg_psoc_get_values(a1) + 4150);
        wlan_dp_stc_cfg_init(v2 + 24, a1);
        *(_BYTE *)(v2 + 236) = *(_BYTE *)(cfg_psoc_get_values(a1) + 758);
        *(_DWORD *)(v2 + 228) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4160);
        *(_DWORD *)(v2 + 232) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4164);
        target_if_dp_register_tx_ops(v2 + 768);
        target_if_dp_register_rx_ops(v2 + 840);
        goto LABEL_30;
      }
    }
LABEL_20:
    if ( (v37 & 4) != 0 )
      goto LABEL_27;
    goto LABEL_21;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Failed to attach psoc component obj",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "dp_psoc_obj_create_notification");
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v3;
}
