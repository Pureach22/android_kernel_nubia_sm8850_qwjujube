__int64 __fastcall wma_enable_active_apf_mode(
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
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 cmpt_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  __int64 v34; // x4
  unsigned int v35; // w21
  unsigned int v36; // w20
  const char *v37; // x2
  __int64 v38; // x4
  unsigned int v39; // w22
  unsigned int active; // w0
  unsigned __int8 v41[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41[0] = 0;
  if ( !a2 )
  {
    v12 = "%s: DHCP indication is NULL";
    goto LABEL_5;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Enabling active apf mode",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_enable_active_apf_mode");
  if ( !(unsigned int)wma_find_vdev_id_by_addr(a1, a2 + 5, v41) )
  {
    v14 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            *(_QWORD *)(a1 + 24),
            v41[0],
            8);
    if ( !v14 )
    {
      result = 4294967274LL;
      goto LABEL_6;
    }
    v23 = v14;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v14, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( cmpt_obj )
    {
      v33 = (unsigned int *)*(unsigned __int8 *)(cmpt_obj + 179);
      if ( (_DWORD)v33 != 2 || (ucfg_pmo_is_apf_enabled(*(_QWORD *)(a1 + 24)) & 1) == 0 )
        goto LABEL_22;
      v34 = *(unsigned int *)(a1 + 3352);
      if ( (unsigned int)v34 >= 3 )
      {
        v35 = 2;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid Active APF Mode %d; Using 'disabled'",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wma_get_fw_active_apf_mode");
      }
      else
      {
        v35 = dword_B09F88[v34];
      }
      v38 = *(unsigned int *)(a1 + 3356);
      if ( (unsigned int)v38 >= 3 )
      {
        v39 = 2;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid Active APF Mode %d; Using 'disabled'",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wma_get_fw_active_apf_mode");
      }
      else
      {
        v39 = dword_B09F88[v38];
      }
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Configuring Active APF Mode UC:%d MC/BC:%d for vdev %u",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wma_enable_active_apf_mode",
        v35,
        v39,
        v41[0]);
      active = wmi_unified_set_active_apf_mode_cmd(*(_QWORD *)a1);
      if ( !active )
      {
LABEL_22:
        v36 = 0;
        goto LABEL_23;
      }
      v36 = active;
      v37 = "%s: Failed to configure active APF mode";
    }
    else
    {
      v36 = -22;
      v37 = "%s: Failed to get vdev mlme obj!";
    }
    qdf_trace_msg(0x36u, 2u, v37, v25, v26, v27, v28, v29, v30, v31, v32, "wma_enable_active_apf_mode");
LABEL_23:
    wlan_objmgr_vdev_release_ref(v23, 8u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
    result = v36;
    goto LABEL_6;
  }
  v12 = "%s: Failed to find vdev id for DHCP indication";
LABEL_5:
  qdf_trace_msg(0x36u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wma_enable_active_apf_mode");
  result = 16;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
