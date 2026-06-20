__int64 __fastcall wma_send_probe_rsp_tmpl(
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
  char v14; // w1
  __int64 v15; // x9
  unsigned __int8 v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  _QWORD *v29; // x23
  __int64 v30; // x21
  __int64 v31; // x22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int8 v40[4]; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v41; // [xsp+10h] [xbp-30h]
  __int64 v42; // [xsp+18h] [xbp-28h]
  _DWORD v43[6]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40[0] = 0;
  if ( !a2 )
  {
    v12 = "%s: probe_rsp_info is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wma_find_vdev_id_by_addr((__int64)a1, a2 + 16, v40) )
  {
    v12 = "%s: failed to get vdev id";
LABEL_5:
    result = qdf_trace_msg(0x36u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wma_send_probe_rsp_tmpl");
    goto LABEL_6;
  }
  result = wmi_service_enabled(*a1, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    v14 = v40[0];
    v15 = a1[65];
    v16 = v40[0];
    v42 = 0;
    memset(v43, 0, sizeof(v43));
    v17 = *(_QWORD *)(v15 + 488LL * v40[0] + 192);
    LODWORD(v42) = *(_DWORD *)(a2 + 520);
    BYTE4(v42) = *(_BYTE *)(a2 + 556);
    *(_QWORD *)(a2 + 30) = -v17;
    v18 = a1[4];
    v41 = a2 + 6;
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v18, v14, 2u);
    if ( vdev_by_id_from_pdev )
    {
      v28 = (unsigned int *)*((unsigned int *)vdev_by_id_from_pdev + 4);
      if ( (_DWORD)v28 == 1 )
      {
        v29 = vdev_by_id_from_pdev;
        if ( (wlan_vdev_mlme_is_mlo_vdev((__int64)vdev_by_id_from_pdev, v20, v21, v22, v23, v24, v25, v26, v27) & 1) != 0 )
        {
          v28 = (unsigned int *)*((unsigned int *)v29 + 16);
          vdev_by_id_from_pdev = v29;
          if ( ((unsigned int)v28 & 0x80000) != 0 )
            v30 = 1LL << v16;
          else
            v30 = 0;
          if ( ((unsigned int)v28 & 0x100000) != 0 )
            v31 = 1LL << v16;
          else
            v31 = 0;
        }
        else
        {
          v30 = 0;
          v31 = 0;
          vdev_by_id_from_pdev = v29;
        }
      }
      else
      {
        v30 = 0;
        v31 = 0;
      }
      wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27);
      if ( v30 | v31 )
      {
        *(_QWORD *)&v43[1] = v30;
        *(_QWORD *)&v43[3] = v31;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: hw_link_id:%d cat1 lo:0x%x hi:0x%x cat2 lo:0x%x hi:0x%x",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wma_critical_update_set_notify_probe_rsp_tmpl",
          0,
          (unsigned int)v30,
          HIDWORD(v31));
      }
    }
    result = wmi_unified_probe_rsp_tmpl_send_cmd(*a1);
    if ( (result & 0x80000000) != 0 )
    {
      v12 = "%s: wmi_unified_probe_rsp_tmpl_send Failed";
      goto LABEL_5;
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
