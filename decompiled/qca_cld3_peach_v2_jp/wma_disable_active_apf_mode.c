__int64 __fastcall wma_disable_active_apf_mode(
        __int64 *a1,
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
  unsigned int active; // w0
  unsigned int v35; // w20
  const char *v36; // x2
  unsigned __int8 v37[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  if ( !a2 )
  {
    v12 = "%s: DHCP indication is NULL";
    goto LABEL_5;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Disabling active apf mode",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_disable_active_apf_mode");
  if ( !(unsigned int)wma_find_vdev_id_by_addr((__int64)a1, a2 + 5, v37) )
  {
    v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1[3], v37[0], 8);
    if ( !v14 )
    {
      result = 4294967274LL;
      goto LABEL_6;
    }
    v23 = v14;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v14, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( cmpt_obj )
    {
      v33 = (unsigned int *)*(unsigned __int8 *)(cmpt_obj + 163);
      if ( (_DWORD)v33 != 2
        || (ucfg_pmo_is_apf_enabled(a1[3]) & 1) == 0
        || (qdf_trace_msg(
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
              "wma_disable_active_apf_mode",
              2,
              2,
              v37[0]),
            (active = wmi_unified_set_active_apf_mode_cmd(*a1)) == 0) )
      {
        v35 = 0;
LABEL_17:
        wlan_objmgr_vdev_release_ref(v23, 8u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
        result = v35;
        goto LABEL_6;
      }
      v35 = active;
      v36 = "%s: Failed to configure active APF mode";
    }
    else
    {
      v35 = -22;
      v36 = "%s: Failed to get vdev mlme obj!";
    }
    qdf_trace_msg(0x36u, 2u, v36, v25, v26, v27, v28, v29, v30, v31, v32, "wma_disable_active_apf_mode");
    goto LABEL_17;
  }
  v12 = "%s: Failed to find vdev id for DHCP indication";
LABEL_5:
  qdf_trace_msg(0x36u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wma_disable_active_apf_mode");
  result = 16;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
