__int64 __fastcall target_if_cfr_config_rcc(
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
  __int64 pdev_wmi_handle; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 comp_private_obj; // x0
  unsigned int v24; // w21
  const char *v26; // x2
  __int64 v27; // x23
  __int64 v28; // x0
  int v29; // w1
  __int64 v30; // x24
  _QWORD *vdev_by_id_from_pdev; // x0
  unsigned __int16 *v32; // x25
  __int64 v33; // x22
  bool is_24ghz_ch_freq; // w0
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  __int64 v45; // x0

  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_wmi_handle )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev_wmi_handle is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_cfr_config_rcc");
    return 29;
  }
  v21 = pdev_wmi_handle;
  if ( a1 )
  {
    v22 = *(_QWORD *)(a1 + 80);
    if ( v22 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v22, 0x1Eu);
      if ( comp_private_obj )
      {
        if ( *(_BYTE *)(comp_private_obj + 9) )
        {
          v24 = 255;
LABEL_23:
          qdf_trace_msg(
            0x6Au,
            8u,
            "%s: is_cfr_pdev_id_soc %d, pdev_id %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "target_if_cfr_get_pdev_id",
            *(unsigned __int8 *)(comp_private_obj + 9),
            v24);
          goto LABEL_24;
        }
        v27 = comp_private_obj;
        v24 = *(unsigned __int8 *)(a1 + 40);
        v28 = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
        if ( v28 )
        {
          v29 = *(unsigned __int8 *)(v28 + 153);
          if ( v29 == 255 )
          {
LABEL_22:
            comp_private_obj = v27;
            goto LABEL_23;
          }
          v30 = v28;
          vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, v29, 0x30u);
          if ( vdev_by_id_from_pdev )
          {
            v32 = (unsigned __int16 *)vdev_by_id_from_pdev[4];
            v33 = (__int64)vdev_by_id_from_pdev;
            if ( v32 )
            {
              qdf_trace_msg(
                0x6Au,
                8u,
                "%s: bss freq %d",
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                "target_if_cfr_get_mac_id",
                *v32);
              is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*v32);
              v24 = is_24ghz_ch_freq;
              *(_BYTE *)(v30 + 154) = is_24ghz_ch_freq;
            }
            else
            {
              qdf_trace_msg(
                0x6Au,
                4u,
                "%s: null bss chan",
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                "target_if_cfr_get_mac_id");
            }
            wlan_objmgr_vdev_release_ref(v33, 0x30u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
            goto LABEL_22;
          }
          v44 = "%s: null vdev";
        }
        else
        {
          v44 = "%s: null pcfr";
        }
        qdf_trace_msg(0x6Au, 2u, v44, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_cfr_get_mac_id");
        goto LABEL_22;
      }
      v26 = "%s: null psoc cfr";
    }
    else
    {
      v26 = "%s: null psoc";
    }
  }
  else
  {
    v26 = "%s: null pdev";
  }
  qdf_trace_msg(0x6Au, 2u, v26, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_cfr_get_pdev_id");
  LOBYTE(v24) = 0;
LABEL_24:
  v45 = *(_QWORD *)(a2 + 592);
  *(_BYTE *)a2 = v24;
  *(_BYTE *)(a2 + 25) = count_set_bits(v45);
  return wmi_unified_send_cfr_rcc_cmd(v21, a2);
}
