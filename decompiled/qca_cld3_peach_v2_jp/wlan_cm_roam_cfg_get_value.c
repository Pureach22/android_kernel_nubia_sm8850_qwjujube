__int64 __fastcall wlan_cm_roam_cfg_get_value(__int64 a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v9; // x23
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int *v19; // x8
  __int64 v21; // x22
  __int64 ext_hdl_fl; // x20
  unsigned int *v23; // x8
  unsigned int v24; // w21

  qdf_mem_set(a4, 0x20u, 0);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v9 = psoc_ext_obj_fl;
  v10 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_cm_roam_cfg_get_value");
    return 16;
  }
  v19 = (unsigned int *)*(unsigned int *)(v10 + 16);
  if ( ((unsigned int)v19 & 0xFFFFFFFD) != 0
    || (v21 = v10,
        ext_hdl_fl = cm_get_ext_hdl_fl(
                       v10,
                       (__int64)"wlan_cm_roam_cfg_get_value",
                       0x384u,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18),
        v10 = v21,
        !ext_hdl_fl) )
  {
    wlan_objmgr_vdev_release_ref(v10, 2u, v19, v11, v12, v13, v14, v15, v16, v17, v18);
    return 16;
  }
  switch ( a3 )
  {
    case 0u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 93);
      goto LABEL_25;
    case 1u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 94);
      goto LABEL_50;
    case 2u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 96);
      goto LABEL_50;
    case 3u:
      v23 = (unsigned int *)*(unsigned __int16 *)(ext_hdl_fl + 146);
      goto LABEL_50;
    case 4u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 184);
      goto LABEL_50;
    case 6u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 132);
      goto LABEL_50;
    case 7u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 136);
      goto LABEL_50;
    case 8u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 104);
      goto LABEL_50;
    case 9u:
    case 0x12u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 92);
      goto LABEL_46;
    case 0xCu:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 189);
      goto LABEL_50;
    case 0xDu:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 128);
      goto LABEL_50;
    case 0xEu:
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: is_agg: %d, control_enable: %d, alert_rssi_th: %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cm_roam_cfg_get_value",
        *(unsigned __int8 *)(ext_hdl_fl + 1367),
        *(unsigned __int8 *)(ext_hdl_fl + 92),
        *(unsigned int *)(v9 + 2484));
      if ( *(_BYTE *)(ext_hdl_fl + 1367) == 1 && (*(_BYTE *)(ext_hdl_fl + 92) & 1) == 0 )
      {
        v23 = (unsigned int *)*(unsigned __int8 *)(v9 + 2568);
        v24 = 0;
        v10 = v21;
      }
      else
      {
        v23 = (unsigned int *)*(unsigned int *)(v9 + 2484);
        v10 = v21;
        v24 = 0;
        if ( !(_DWORD)v23 )
          v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 129);
      }
      goto LABEL_51;
    case 0xFu:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 194);
      goto LABEL_50;
    case 0x10u:
      v23 = (unsigned int *)*(unsigned __int16 *)(ext_hdl_fl + 192);
      goto LABEL_50;
    case 0x11u:
      v23 = (unsigned int *)*(unsigned __int16 *)(ext_hdl_fl + 144);
      goto LABEL_50;
    case 0x13u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 677);
      goto LABEL_50;
    case 0x14u:
      v24 = 0;
      *((_BYTE *)a4 + 8) = *(_BYTE *)(ext_hdl_fl + 826) != 0;
      v23 = (unsigned int *)*(unsigned __int16 *)(ext_hdl_fl + 828);
      goto LABEL_51;
    case 0x15u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 830);
      goto LABEL_46;
    case 0x16u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 831);
      goto LABEL_46;
    case 0x17u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 832);
      goto LABEL_46;
    case 0x18u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 836);
      goto LABEL_50;
    case 0x19u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 833);
      goto LABEL_46;
    case 0x1Au:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 868);
      goto LABEL_25;
    case 0x1Bu:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 944);
      goto LABEL_50;
    case 0x1Cu:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 156);
      goto LABEL_50;
    case 0x1Du:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 190);
      goto LABEL_50;
    case 0x1Eu:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 224);
      goto LABEL_50;
    case 0x1Fu:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 1366);
      goto LABEL_46;
    case 0x20u:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 1367);
      goto LABEL_46;
    case 0x21u:
      v23 = (unsigned int *)*(unsigned int *)(v9 + 3432);
      goto LABEL_50;
    case 0x22u:
      v23 = (unsigned int *)*(unsigned int *)(v9 + 3436);
      goto LABEL_50;
    case 0x23u:
      v23 = (unsigned int *)*(unsigned int *)(v9 + 2564);
LABEL_25:
      v24 = 0;
      a4[1] = (_DWORD)v23;
      break;
    case 0x24u:
      v23 = (unsigned int *)*(unsigned __int8 *)(v9 + 2568);
      goto LABEL_50;
    case 0x29u:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 216);
      goto LABEL_50;
    case 0x2Au:
      v23 = (unsigned int *)*(unsigned int *)(ext_hdl_fl + 220);
LABEL_50:
      v24 = 0;
LABEL_51:
      *a4 = (_DWORD)v23;
      break;
    case 0x2Bu:
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 1368);
LABEL_46:
      v24 = 0;
      *((_BYTE *)a4 + 8) = (_BYTE)v23;
      break;
    default:
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Invalid roam config requested:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cm_roam_cfg_get_value",
        a3);
      v10 = v21;
      v24 = 16;
      break;
  }
  wlan_objmgr_vdev_release_ref(v10, 2u, v23, v11, v12, v13, v14, v15, v16, v17, v18);
  return v24;
}
