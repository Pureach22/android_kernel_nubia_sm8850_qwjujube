__int64 __fastcall cfr_enh_init_pdev(
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
  __int64 comp_private_obj; // x0
  __int64 v13; // x22
  __int64 v14; // x0
  _BYTE *v15; // x23
  int target_type; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  int v26; // w19
  __int64 v27; // x8
  __int64 (__fastcall *v28)(__int64, __int64, __int64 *, __int64 (__fastcall *)()); // x8
  unsigned int v29; // w0
  const char *v30; // x2
  unsigned int v31; // w19
  const char *v32; // x2
  __int64 v33; // x8
  _QWORD *v34; // x0
  unsigned int v35; // w0
  __int64 v36; // x8
  _QWORD *v37; // x0
  unsigned int v38; // w0
  int v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 result; // x0
  __int64 v49; // x8
  char v50; // w10
  __int64 v51; // x9
  int v52; // w9
  __int64 v53; // x9
  int v54; // w11
  __int64 v55; // [xsp+0h] [xbp-10h] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v32 = "%s: PDEV is NULL!";
LABEL_28:
    qdf_trace_msg(0x6Au, 2u, v32, a3, a4, a5, a6, a7, a8, a9, a10, "cfr_enh_init_pdev");
    result = 29;
    goto LABEL_29;
  }
  if ( !a1 )
  {
    v32 = "%s: PSOC is NULL";
    goto LABEL_28;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a2, 0x1Eu);
  if ( !comp_private_obj )
  {
    v32 = "%s: pcfr is NULL!";
    goto LABEL_28;
  }
  v13 = comp_private_obj;
  v14 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Eu);
  if ( !v14 )
  {
    v32 = "%s: cfr_sc is NULL";
    goto LABEL_28;
  }
  v15 = (_BYTE *)v14;
  target_type = target_if_cfr_get_target_type(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  v25 = *(_QWORD *)(a2 + 80);
  v26 = target_type;
  v55 = 0x100000001LL;
  if ( v25 && (v27 = *(_QWORD *)(v25 + 2128)) != 0 )
  {
    v28 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64 (__fastcall *)()))(v27 + 1760);
    if ( v28 )
    {
      if ( *((_DWORD *)v28 - 1) != 1596014264 )
        __break(0x8228u);
      v29 = v28(a2, 1, &v55, enh_cfr_dbr_event_handler);
      if ( v29 )
      {
        v30 = "%s: Failed to register with dbr";
LABEL_12:
        v31 = v29;
LABEL_34:
        qdf_trace_msg(0x6Au, 2u, v30, v17, v18, v19, v20, v21, v22, v23, v24, "cfr_enh_init_pdev", v55);
        result = v31;
        goto LABEL_29;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: tx_ops is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_register_to_dbr_enh",
      v55,
      v56);
  }
  v33 = *(_QWORD *)(a1 + 2800);
  if ( !v33 || (v34 = *(_QWORD **)(v33 + 16)) == nullptr )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Unable to get wmi handle",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_register_tx_completion_enh_event_handler",
      v55);
    v31 = 29;
LABEL_31:
    v30 = "%s: Failed to register with tx event handler";
    goto LABEL_34;
  }
  v35 = wmi_unified_register_event_handler(
          v34,
          0xD1u,
          (__int64)target_if_peer_capture_event,
          1u,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24);
  if ( (v35 | 0x10) != 0x10 )
  {
    v31 = v35;
    goto LABEL_31;
  }
  v36 = *(_QWORD *)(a1 + 2800);
  if ( !v36 || (v37 = *(_QWORD **)(v36 + 16)) == nullptr )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Unable to get wmi handle",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_register_phase_delta_for_rcc_event_handler",
      v55);
    v31 = 29;
LABEL_33:
    v30 = "%s: Failed to register with phase delta event handler";
    goto LABEL_34;
  }
  v38 = wmi_unified_register_event_handler(
          v37,
          0xF4u,
          (__int64)&target_if_pdev_aoa_phasedaelta_event_handler,
          1u,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24);
  if ( (v38 | 0x10) != 0x10 )
  {
    v31 = v38;
    goto LABEL_33;
  }
  *(_BYTE *)(v13 + 1385) = 1;
  *(_BYTE *)(v13 + 152) = *(_BYTE *)(a2 + 40);
  *(_QWORD *)(v13 + 744) = 0xFFFF;
  *(_BYTE *)(v13 + 177) = 16;
  *(_WORD *)(v13 + 153) = 255;
  *(_BYTE *)(v13 + 1440) = v15[10];
  *(_BYTE *)(v13 + 1441) = v15[11];
  v39 = (unsigned __int8)v15[12];
  *(_BYTE *)(v13 + 1442) = v39;
  if ( v39 )
  {
    qdf_mem_set((void *)(v13 + 2936), 0x20u, 0);
    qdf_mem_set((void *)(v13 + 1944), 0x3E0u, 0);
    *(_DWORD *)(v13 + 1940) = 0;
  }
  target_if_cfr_default_ta_ra_config((char *)(v13 + 152), 1, 0xFFFFu);
  v29 = target_if_cfr_config_rcc(a2, v13 + 152, v40, v41, v42, v43, v44, v45, v46, v47);
  if ( v29 )
  {
    v30 = "%s: Sending WMI to configure default has failed";
    goto LABEL_12;
  }
  target_if_cfr_update_global_cfg(a2);
  v49 = v13;
  *(_QWORD *)(v13 + 744) = 0;
  *(_WORD *)(v13 + 40) = 10;
  if ( v26 <= 31 )
  {
    if ( v26 == 26 )
    {
      v50 = 26;
      v53 = 0x4168000000FFLL;
LABEL_55:
      *(_QWORD *)(v13 + 44) = v53;
      v52 = 37;
      goto LABEL_58;
    }
    if ( v26 == 29 )
    {
      v50 = 28;
      v51 = 0x10E0000000FFLL;
      goto LABEL_57;
    }
    if ( v26 != 30 )
      goto LABEL_53;
LABEL_49:
    v51 = 0x40E0000000FFLL;
    if ( v26 == 30 )
      v50 = 30;
    else
      v50 = 36;
    goto LABEL_57;
  }
  if ( v26 <= 35 )
  {
    if ( v26 != 32 )
    {
      if ( v26 == 35 )
      {
        v50 = 35;
        v51 = 0x20F8000000FFLL;
LABEL_57:
        *(_QWORD *)(v13 + 44) = v51;
        v52 = 4;
        goto LABEL_58;
      }
LABEL_53:
      v50 = 24;
      v51 = 0x3FA0000000FFLL;
      goto LABEL_57;
    }
    v50 = 32;
    v53 = 0xFE000000007FLL;
    goto LABEL_55;
  }
  if ( v26 == 36 )
    goto LABEL_49;
  if ( v26 != 39 )
    goto LABEL_53;
  v50 = 38;
  *(_QWORD *)(v13 + 44) = 0x7EB000000080LL;
  v52 = 8;
LABEL_58:
  v54 = *(unsigned __int8 *)(v13 + 1384);
  *(_BYTE *)(v13 + 10) = v50;
  *(_DWORD *)(v13 + 92) = v52;
  if ( !v54 )
  {
    *(_QWORD *)(v13 + 1368) = lut_ageout_timer_task;
    *(_QWORD *)(v13 + 1376) = v13;
    init_timer_key(v13 + 1328, _os_timer_shim_17, 0, 0, 0);
    v49 = v13;
    *(_BYTE *)(v13 + 1384) = 1;
  }
  result = 0;
  *(_DWORD *)(v49 + 1704) = 0;
  *(_QWORD *)(v49 + 1712) = 0;
  *(_BYTE *)(v49 + 1720) = 1;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
