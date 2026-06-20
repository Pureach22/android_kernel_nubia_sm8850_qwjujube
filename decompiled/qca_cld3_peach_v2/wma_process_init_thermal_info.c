__int64 __fastcall wma_process_init_thermal_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  int v21; // w9
  int v22; // w10
  int v23; // w11
  int v24; // w12
  int v25; // w13
  int v26; // w14
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w10
  __int64 result; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  _QWORD *context; // x0
  void (**v54)(void); // x8
  void (*v55)(void); // x8
  __int64 v56; // [xsp+0h] [xbp-F0h]

  _ReadStatusReg(SP_EL0);
  if ( a1 && a2 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: TM enable %d period %d action %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_process_init_thermal_info",
      *(unsigned __int8 *)(a2 + 25),
      *(unsigned int *)(a2 + 28),
      *(unsigned int *)(a2 + 40));
    qdf_trace_msg(
      0x36u,
      8u,
      "Throttle Duty Cycle Level in percentage:\n0 %d\n1 %d\n2 %d\n3 %d\n4 %d\n5 %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      *(unsigned __int8 *)(a2 + 32),
      *(unsigned __int8 *)(a2 + 33),
      *(unsigned __int8 *)(a2 + 34),
      *(unsigned __int8 *)(a2 + 35),
      *(unsigned __int8 *)(a2 + 36),
      *(unsigned __int8 *)(a2 + 37));
    *(_BYTE *)(a1 + 673) = *(_BYTE *)(a2 + 25);
    *(_WORD *)(a1 + 648) = *(_WORD *)a2;
    *(_WORD *)(a1 + 650) = *(_WORD *)(a2 + 2);
    *(_WORD *)(a1 + 652) = *(_WORD *)(a2 + 4);
    *(_WORD *)(a1 + 654) = *(_WORD *)(a2 + 6);
    *(_WORD *)(a1 + 656) = *(_WORD *)(a2 + 8);
    v20 = *(unsigned __int16 *)(a2 + 10);
    *(_WORD *)(a1 + 658) = v20;
    v21 = *(unsigned __int16 *)(a2 + 12);
    *(_WORD *)(a1 + 660) = v21;
    v22 = *(unsigned __int16 *)(a2 + 14);
    *(_WORD *)(a1 + 662) = v22;
    v23 = *(unsigned __int16 *)(a2 + 16);
    *(_WORD *)(a1 + 664) = v23;
    v24 = *(unsigned __int16 *)(a2 + 18);
    *(_WORD *)(a1 + 666) = v24;
    v25 = *(unsigned __int16 *)(a2 + 20);
    *(_WORD *)(a1 + 668) = v25;
    v26 = *(unsigned __int16 *)(a2 + 22);
    *(_BYTE *)(a1 + 672) = 0;
    *(_WORD *)(a1 + 670) = v26;
    *(_DWORD *)(a1 + 688) = *(_DWORD *)(a2 + 40);
    LODWORD(v56) = v20;
    qdf_trace_msg(
      0x36u,
      8u,
      "TM level min max:\n0 %d   %d\n1 %d   %d\n2 %d   %d\n3 %d   %d\n4 %d   %d\n5 %d   %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v56,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26);
    v43 = *(unsigned __int8 *)(a1 + 673);
    *(_BYTE *)(a1 + 680) = *(_BYTE *)(a2 + 32);
    *(_BYTE *)(a1 + 681) = *(_BYTE *)(a2 + 33);
    *(_BYTE *)(a1 + 682) = *(_BYTE *)(a2 + 34);
    *(_BYTE *)(a1 + 683) = *(_BYTE *)(a2 + 35);
    *(_BYTE *)(a1 + 684) = *(_BYTE *)(a2 + 36);
    *(_BYTE *)(a1 + 685) = *(_BYTE *)(a2 + 37);
    if ( v43 )
    {
      if ( (*(_BYTE *)(a1 + 3952) & 1) == 0 )
      {
        context = _cds_get_context(71, (__int64)"wma_process_init_thermal_info", v35, v36, v37, v38, v39, v40, v41, v42);
        if ( context && *context && (v54 = *(void (***)(void))(*context + 128LL)) != nullptr )
        {
          v55 = *v54;
          if ( v55 )
          {
            if ( *((_DWORD *)v55 - 1) != -2121806202 )
              __break(0x8228u);
            v55();
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "cdp_throttle_init_period");
        }
        goto LABEL_17;
      }
      result = wmi_unified_thermal_mitigation_param_cmd_send(*(_QWORD *)a1);
      if ( !(_DWORD)result )
      {
LABEL_17:
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: TM sending to fw: min_temp %d max_temp %d enable %d act %d",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "wma_update_thermal_cfg_to_fw",
          *(unsigned __int16 *)(a1 + 648),
          *(unsigned __int16 *)(a1 + 650),
          *(unsigned __int8 *)(a1 + 673),
          *(unsigned int *)(a1 + 688));
        result = wmi_unified_set_thermal_mgmt_cmd(*(_QWORD *)a1);
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: TM Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_init_thermal_info");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
