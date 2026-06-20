__int64 __fastcall policy_mgr_update_active_mlo_num_nlink(__int64 a1, unsigned int a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x8
  unsigned int v24; // w19
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x25
  int v43; // w8
  int v44; // w9
  const char *v45; // x2
  unsigned int v46; // w24
  int v47; // w8
  int v48; // w9
  int v49; // w8
  int v50; // w9
  __int64 v52; // [xsp+0h] [xbp-20h]
  __int64 v53; // [xsp+8h] [xbp-18h]

  _ReadStatusReg(SP_EL0);
  if ( (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) != 0 && (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Concurrency exists, cannot enter EMLSR mode",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_update_active_mlo_num_nlink");
    v24 = 16;
  }
  else
  {
    v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
    if ( v14 )
    {
      v23 = (unsigned int *)*(unsigned int *)(v14 + 16);
      if ( (_DWORD)v23 )
      {
        v24 = 16;
LABEL_39:
        wlan_objmgr_vdev_release_ref(v14, 0x18u, v23, v15, v16, v17, v18, v19, v20, v21, v22);
        goto LABEL_40;
      }
      v25 = v14;
      if ( wlan_cm_is_vdev_connected(v14, v15, v16, v17, v18, v19, v20, v21, v22) )
      {
        if ( (wlan_vdev_mlme_is_mlo_vdev(v25, v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Num active links: %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "policy_mgr_update_active_mlo_num_nlink",
            (unsigned __int8)a3);
          if ( (_BYTE)a3 )
          {
            v42 = *(_QWORD *)(*(_QWORD *)(v25 + 1360) + 3880LL);
            if ( *(unsigned __int8 *)(v42 + 6) == 255
              || !(*(_DWORD *)(v42 + 24) | *(unsigned __int16 *)(v42 + 28))
              || *(unsigned __int8 *)(v42 + 12) == 255 )
            {
              v46 = 0;
            }
            else
            {
              if ( v42 )
              {
                v43 = *(unsigned __int8 *)(v42 + 2);
                v44 = *(unsigned __int8 *)(v42 + 5);
              }
              else
              {
                v43 = 0;
                v44 = 0;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: linkid %d freq %d link addr: %02x:%02x:%02x:**:**:%02x",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "policy_mgr_update_active_mlo_num_nlink",
                v43,
                v44);
              v46 = 1 << *(_BYTE *)(v42 + 6);
            }
            if ( *(unsigned __int8 *)(v42 + 54) != 255
              && *(_DWORD *)(v42 + 72) | *(unsigned __int16 *)(v42 + 76)
              && *(unsigned __int8 *)(v42 + 60) != 255 )
            {
              v47 = v42 + 48;
              if ( v42 == -48 )
              {
                v48 = 0;
              }
              else
              {
                v47 = *(unsigned __int8 *)(v42 + 50);
                v48 = *(unsigned __int8 *)(v42 + 53);
              }
              LODWORD(v53) = v48;
              LODWORD(v52) = v47;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: linkid %d freq %d link addr: %02x:%02x:%02x:**:**:%02x",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "policy_mgr_update_active_mlo_num_nlink",
                v52,
                v53);
              v46 |= 1 << *(_BYTE *)(v42 + 54);
            }
            if ( *(unsigned __int8 *)(v42 + 102) != 255
              && *(_DWORD *)(v42 + 120) | *(unsigned __int16 *)(v42 + 124)
              && *(unsigned __int8 *)(v42 + 108) != 255 )
            {
              v49 = v42 + 96;
              if ( v42 == -96 )
              {
                v50 = 0;
              }
              else
              {
                v49 = *(unsigned __int8 *)(v42 + 98);
                v50 = *(unsigned __int8 *)(v42 + 101);
              }
              LODWORD(v53) = v50;
              LODWORD(v52) = v49;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: linkid %d freq %d link addr: %02x:%02x:%02x:**:**:%02x",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "policy_mgr_update_active_mlo_num_nlink",
                v52,
                v53);
              v46 |= 1 << *(_BYTE *)(v42 + 102);
            }
          }
          else
          {
            v46 = 0;
          }
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: link_bitmap: %d, force_active_cnt: %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "policy_mgr_update_active_mlo_num_nlink",
            v46,
            (unsigned __int8)a3);
          v24 = ml_nlink_vendor_command_set_link(a1, a2, 2, 1, 3, a3, v46, 0);
          goto LABEL_38;
        }
        v45 = "%s: vdev is not mlo vdev";
      }
      else
      {
        v45 = "%s: vdev is not in connected state";
      }
      qdf_trace_msg(0x4Fu, 2u, v45, v26, v27, v28, v29, v30, v31, v32, v33, "policy_mgr_update_active_mlo_num_nlink");
      v24 = 16;
LABEL_38:
      v14 = v25;
      goto LABEL_39;
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev_id: %d vdev not found",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_update_active_mlo_num_nlink",
      (unsigned __int8)a2);
    v24 = 16;
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v24;
}
