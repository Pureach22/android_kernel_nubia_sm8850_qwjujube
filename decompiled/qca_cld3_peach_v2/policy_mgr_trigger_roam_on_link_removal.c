__int64 __fastcall policy_mgr_trigger_roam_on_link_removal(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char v9; // w26
  __int64 v10; // x19
  unsigned int v11; // w20
  __int64 v12; // x21
  _QWORD *context; // x0
  _QWORD *v14; // x22
  __int64 v15; // x23
  int v16; // w24
  __int64 result; // x0
  unsigned int v18; // w24
  unsigned __int64 v19; // x27
  const char *v20; // x2
  unsigned int v21; // w1
  unsigned int v22; // w25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x28
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char v50; // [xsp+4h] [xbp-3Ch]
  _BYTE v51[4]; // [xsp+8h] [xbp-38h] BYREF
  _BYTE v52[4]; // [xsp+Ch] [xbp-34h] BYREF
  int v53; // [xsp+10h] [xbp-30h] BYREF
  __int16 v54; // [xsp+14h] [xbp-2Ch]
  int v55; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int8 v56; // [xsp+1Ch] [xbp-24h]
  _QWORD v57[2]; // [xsp+20h] [xbp-20h] BYREF
  int v58; // [xsp+30h] [xbp-10h]
  __int64 v59; // [xsp+38h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  v11 = *(unsigned __int8 *)(a1 + 168);
  v52[0] = 0;
  v51[0] = 0;
  v56 = 0;
  v55 = 0;
  v58 = 0;
  v57[0] = 0;
  v57[1] = 0;
  v54 = 0;
  v53 = 0;
  if ( !v10 || (v12 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v20 = "%s: Failed to get psoc";
    goto LABEL_13;
  }
  context = (_QWORD *)policy_mgr_get_context(*(_QWORD *)(v10 + 80));
  if ( !context )
  {
    v20 = "%s: Invalid Context";
    goto LABEL_13;
  }
  v14 = context;
  policy_mgr_get_ml_sta_info(context, v52, v51, (__int64)&v55, (__int64)v57, nullptr, 0, 0);
  v15 = v52[0];
  if ( !v52[0] )
  {
    v20 = "%s: unexpected event, no ml sta";
LABEL_34:
    v21 = 8;
    goto LABEL_14;
  }
  v16 = v51[0];
  if ( v52[0] > 5u || v51[0] > 5u || v52[0] <= (unsigned int)v51[0] )
  {
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: unexpected ml sta num %d %d",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "policy_mgr_trigger_roam_on_link_removal",
               v52[0],
               v51[0]);
    goto LABEL_15;
  }
  result = wlan_get_vdev_link_removed_flag_by_vdev_id(v12, (unsigned __int8)v55);
  if ( (result & 1) != 0 )
  {
    v18 = v15 - v16;
    if ( (unsigned __int8)v18 >= 2u )
    {
      result = wlan_get_vdev_link_removed_flag_by_vdev_id(v12, BYTE1(v55));
      if ( (result & 1) == 0 )
        goto LABEL_15;
      if ( (unsigned __int8)v18 != 2 )
      {
        result = wlan_get_vdev_link_removed_flag_by_vdev_id(v12, BYTE2(v55));
        if ( (result & 1) == 0 )
          goto LABEL_15;
        if ( (unsigned __int8)v18 != 3 )
        {
          result = wlan_get_vdev_link_removed_flag_by_vdev_id(v12, HIBYTE(v55));
          if ( (result & 1) == 0 )
            goto LABEL_15;
          if ( (unsigned __int8)v18 != 4 )
          {
            result = wlan_get_vdev_link_removed_flag_by_vdev_id(v12, v56);
            if ( (result & 1) == 0 )
              goto LABEL_15;
            if ( (unsigned __int8)v18 != 5 )
            {
LABEL_44:
              __break(0x5512u);
LABEL_45:
              if ( v9 == -1 )
              {
                v20 = "%s: no link removed, unexpected";
                goto LABEL_34;
              }
              if ( (unsigned __int8)v18 == 255 )
              {
                v20 = "%s: no find assoc vdev, unexpected";
                goto LABEL_34;
              }
              if ( (v50 & 1) != 0 )
              {
                v20 = "%s: ml sta is non-connected state, don't trigger roam";
                goto LABEL_34;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: link removal detected, try roaming on vdev id: %d",
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                "policy_mgr_trigger_roam_on_link_removal");
              v54 = 0;
              v53 = 0;
              result = wlan_cm_roam_invoke(v10, v18, &v53, 0, 4);
              if ( !(_DWORD)result )
                goto LABEL_15;
              v20 = "%s: roam invoke failed";
LABEL_13:
              v21 = 2;
LABEL_14:
              result = qdf_trace_msg(
                         0x4Fu,
                         v21,
                         v20,
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "policy_mgr_trigger_roam_on_link_removal");
              goto LABEL_15;
            }
          }
        }
      }
    }
    if ( (_DWORD)v15 != 1 )
    {
      v19 = 0;
      v9 = -1;
      v18 = 255;
      v50 = 0;
      do
      {
        if ( v9 == -1 )
        {
          if ( v19 > 4 )
            goto LABEL_44;
          v22 = *((unsigned __int8 *)&v55 + v19);
          if ( (wlan_get_vdev_link_removed_flag_by_vdev_id(v12, *((unsigned __int8 *)&v55 + v19)) & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: removal link vdev %d is removed ",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "policy_mgr_trigger_roam_on_link_removal",
              v11);
            v9 = v22;
          }
          else
          {
            v9 = -1;
          }
        }
        else
        {
          if ( v19 > 4 )
            goto LABEL_44;
          v22 = *((unsigned __int8 *)&v55 + v19);
        }
        v31 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*v14, v22, 24);
        if ( v31 )
        {
          v40 = v31;
          if ( !wlan_cm_is_vdev_connected(v31, v32, v33, v34, v35, v36, v37, v38, v39) )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: ml sta vdev %d is not connected state",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "policy_mgr_trigger_roam_on_link_removal",
              v22);
            v41 = (_DWORD *)(&off_0 + 1);
            v50 = 1;
          }
          wlan_objmgr_vdev_release_ref(v40, 0x18u, v41, v42, v43, v44, v45, v46, v47, v48, v49);
          if ( (_BYTE)v18 == 0xFF )
          {
            if ( (wlan_vdev_mlme_get_is_mlo_link(v12, v22) & 1) != 0 )
              v18 = -1;
            else
              v18 = v22;
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: invalid vdev for id %d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "policy_mgr_trigger_roam_on_link_removal",
            v22);
        }
        ++v19;
      }
      while ( v15 != v19 );
      goto LABEL_45;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
