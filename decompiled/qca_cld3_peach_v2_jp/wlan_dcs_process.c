__int64 __fastcall wlan_dcs_process(
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
  unsigned int v11; // w21
  __int64 comp_private_obj; // x0
  const char *v14; // x2
  __int64 v15; // x21
  int v16; // w9
  __int64 result; // x0
  __int64 v18; // x8
  char v19; // w22
  const char *v20; // x2
  const char *v21; // x3
  int v22; // w0
  unsigned int v23; // w21
  __int64 pdev_by_id; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _DWORD *v43; // x9
  __int64 v44; // x0

  if ( !a1 || !a2 )
  {
    v14 = "%s: psoc or event is NULL";
LABEL_18:
    qdf_trace_msg(0x74u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dcs_process");
    return 4;
  }
  v11 = *(_DWORD *)(a2 + 72);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: dcs psoc object is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_dcs_get_pdev_private_obj");
    goto LABEL_17;
  }
  if ( v11 >= 3 )
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: invalid pdev_id: %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_dcs_get_pdev_private_obj",
      v11);
LABEL_17:
    v14 = "%s: dcs pdev private object is null";
    goto LABEL_18;
  }
  v15 = comp_private_obj + 384LL * v11;
  if ( !v15 )
    goto LABEL_17;
  if ( *(_DWORD *)(v15 + 4) >= 2u )
    qdf_trace_msg(
      0x74u,
      8u,
      "%s: dcs_enable: %u, interference_type: %u, pdev_id: %u, vdev_id: %d ",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_dcs_process",
      *(unsigned __int8 *)(v15 + 1),
      *(unsigned int *)(a2 + 68),
      *(unsigned int *)(a2 + 72),
      *(unsigned __int8 *)(a2 + 76));
  v16 = *(_DWORD *)(a2 + 68);
  result = 0;
  if ( v16 <= 3 )
  {
    if ( v16 == 1 )
      return result;
    if ( v16 == 2 )
    {
      if ( *(_BYTE *)(v15 + 1) )
      {
        if ( (*(_BYTE *)(v15 + 1) & 2) != 0 )
        {
          v19 = wlan_dcs_wlan_interference_process(a1, *(unsigned __int8 *)(a2 + 76), a2);
          v18 = a1;
        }
        else
        {
          v18 = a1;
          v19 = 0;
        }
        v43 = *(_DWORD **)(v15 + 376);
        if ( v43 && *(_BYTE *)(v15 + 48) )
        {
          v44 = *(unsigned __int8 *)(v15 + 368);
          *(_BYTE *)(v15 + 48) = 0;
          if ( *(v43 - 1) != -2055091431 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v43)(v44, v15 + 128, 0);
          v18 = a1;
        }
        if ( (v19 & 1) != 0 )
          wlan_dcs_frequency_control(v18, v15, a2);
      }
      return 0;
    }
    goto LABEL_22;
  }
  if ( v16 == 4 )
  {
    v22 = *(_DWORD *)(a2 + 84);
    if ( v22 )
    {
      if ( *(_DWORD *)(a2 + 96) )
      {
        if ( *(_DWORD *)(a2 + 80) != 8 )
        {
          v23 = *(unsigned __int8 *)(a2 + 72);
          if ( wlan_reg_is_6ghz_chan_freq(v22) )
          {
            pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, v23, 0x4Bu);
            if ( pdev_by_id )
            {
              v33 = pdev_by_id;
              qdf_trace_msg(
                0x74u,
                8u,
                "%s: pdev id %u width %u freq %u freq0 %u fre1 %u bitmap 0x%x",
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                "wlan_dcs_awgn_process",
                v23,
                *(unsigned int *)(a2 + 80),
                *(unsigned int *)(a2 + 84),
                *(unsigned int *)(a2 + 88),
                *(_DWORD *)(a2 + 92),
                *(_DWORD *)(a2 + 96));
              wlan_objmgr_pdev_iterate_obj_list(
                v33,
                2,
                (void (__fastcall *)(__int64, __int64, __int64))wlan_dcs_process_awgn_sta,
                a2 + 80,
                0,
                0x4Bu);
              wlan_objmgr_pdev_iterate_obj_list(
                v33,
                2,
                (void (__fastcall *)(__int64, __int64, __int64))wlan_dcs_process_awgn_sap,
                a2 + 80,
                0,
                0x4Bu);
              wlan_objmgr_pdev_release_ref(v33, 0x4Bu, v34, v35, v36, v37, v38, v39, v40, v41, v42);
            }
            else
            {
              qdf_trace_msg(
                0x74u,
                2u,
                "%s: Invalid pdev id %d",
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                "wlan_dcs_awgn_process",
                v23);
            }
            return 0;
          }
        }
      }
    }
    v20 = "%s: Invalid awgnim event";
    v21 = "wlan_dcs_awgn_process";
LABEL_30:
    qdf_trace_msg(0x74u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, v21);
    return 0;
  }
  if ( v16 != 8 )
  {
LABEL_22:
    v20 = "%s: unidentified interference type reported";
    v21 = "wlan_dcs_process";
    goto LABEL_30;
  }
  return result;
}
