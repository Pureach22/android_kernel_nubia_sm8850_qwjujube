__int64 __fastcall p2p_check_ap_assist_dfs_group_cli(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x20
  unsigned int operation_chan_freq; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 comp_private_obj; // x0
  char v14; // w11
  __int16 v15; // w9
  int v16; // w8
  __int64 result; // x0
  unsigned int v18; // w21
  __int64 v19; // x22
  __int64 v20; // x0
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 v23; // x23
  __int64 v24; // x0
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  char v38; // w8
  _DWORD *v39; // x9
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int8 v50; // [xsp+Ch] [xbp-34h]
  _QWORD v51[2]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v52; // [xsp+20h] [xbp-20h] BYREF
  __int64 v53; // [xsp+28h] [xbp-18h]
  int v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 216);
  v54 = 0;
  v52 = 0;
  v53 = 0;
  if ( !v1 )
    goto LABEL_45;
  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)((char *)v51 + 5) = 0;
  v51[0] = 0;
  v49 = 0;
  v50 = 0;
  operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a1);
  if ( (wlan_reg_is_dfs_for_freq(v1, operation_chan_freq, v5, v6, v7, v8, v9, v10, v11, v12) & 1) != 0 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v14 = *(_BYTE *)(comp_private_obj + 958);
      v15 = *(_WORD *)(comp_private_obj + 971);
      v16 = *(unsigned __int8 *)(comp_private_obj + 963);
      *(_DWORD *)((char *)v51 + 1) = *(_DWORD *)(comp_private_obj + 967);
      *(_WORD *)((char *)v51 + 5) = v15;
      if ( (v14 & 1) != 0 )
      {
        result = 0;
        goto LABEL_46;
      }
      if ( v16 )
      {
        v23 = *(_QWORD *)(v2 + 2128);
        if ( *(_QWORD *)(v23 + 240) )
        {
          policy_mgr_get_mode_specific_conn_info(v2, (unsigned __int64)&v52, (unsigned __int64)&v49, 0);
          if ( (_DWORD)v52 )
          {
            if ( (_DWORD)v52 == operation_chan_freq )
            {
              v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                      v2,
                      (unsigned __int8)v49,
                      15);
              if ( v24 )
              {
                v19 = v24;
                if ( !(unsigned int)wlan_vdev_is_up_active_state(v24) )
                  goto LABEL_48;
                wlan_objmgr_vdev_release_ref(v19, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
              }
            }
            if ( HIDWORD(v52) )
            {
              if ( HIDWORD(v52) == operation_chan_freq )
              {
                v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                        v2,
                        BYTE1(v49),
                        15);
                if ( v34 )
                {
                  v19 = v34;
                  if ( !(unsigned int)wlan_vdev_is_up_active_state(v34) )
                    goto LABEL_48;
                  wlan_objmgr_vdev_release_ref(v19, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
                }
              }
              if ( (_DWORD)v53 )
              {
                if ( (_DWORD)v53 == operation_chan_freq )
                {
                  v35 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                          v2,
                          BYTE2(v49),
                          15);
                  if ( v35 )
                  {
                    v19 = v35;
                    if ( !(unsigned int)wlan_vdev_is_up_active_state(v35) )
                      goto LABEL_48;
                    wlan_objmgr_vdev_release_ref(v19, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
                  }
                }
                if ( HIDWORD(v53) )
                {
                  if ( HIDWORD(v53) == operation_chan_freq )
                  {
                    v36 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                            v2,
                            HIBYTE(v49),
                            15);
                    if ( v36 )
                    {
                      v19 = v36;
                      if ( !(unsigned int)wlan_vdev_is_up_active_state(v36) )
                        goto LABEL_48;
                      wlan_objmgr_vdev_release_ref(v19, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
                    }
                  }
                  LODWORD(v19) = 0;
                  if ( !v54 )
                    goto LABEL_41;
                  if ( v54 != operation_chan_freq )
                    goto LABEL_41;
                  v37 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                          v2,
                          v50,
                          15);
                  v19 = v37;
                  if ( !v37 )
                    goto LABEL_41;
                  if ( (unsigned int)wlan_vdev_is_up_active_state(v37) )
                  {
                    wlan_objmgr_vdev_release_ref(v19, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
                    goto LABEL_40;
                  }
LABEL_48:
                  wlan_objmgr_vdev_release_ref(v19, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
                  *(_WORD *)((char *)v51 + 5) = 0;
                  LODWORD(v19) = 1;
                  *(_DWORD *)((char *)v51 + 1) = 0;
                  goto LABEL_41;
                }
              }
            }
          }
LABEL_40:
          LODWORD(v19) = 0;
LABEL_41:
          v38 = *(_BYTE *)(a1 + 168);
          v39 = *(_DWORD **)(v23 + 240);
          *(_DWORD *)((char *)v51 + 7) = 0;
          LOBYTE(v51[0]) = v38;
          *(_WORD *)((char *)&v51[1] + 3) = 0;
          if ( *(v39 - 1) != -356578761 )
            __break(0x8229u);
          v40 = ((__int64 (__fastcall *)(__int64, _QWORD *))v39)(v2, v51);
          if ( v40 )
          {
            v18 = v40;
            qdf_trace_msg(
              0x4Eu,
              8u,
              "%s: Failed to send assisted AP params %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "p2p_check_ap_assist_dfs_group_cli");
          }
          else
          {
            v18 = 0;
          }
          goto LABEL_7;
        }
      }
    }
LABEL_45:
    result = 4;
    goto LABEL_46;
  }
  v18 = 0;
  LODWORD(v19) = 1;
LABEL_7:
  v20 = wlan_objmgr_psoc_get_comp_private_obj(v2, 5u);
  if ( v20 )
  {
    v21 = *(_DWORD **)(v20 + 208);
    if ( v21 )
    {
      v22 = *(unsigned __int8 *)(a1 + 168);
      if ( *(v21 - 1) != 2130452855 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v21)(v22, (unsigned int)v19 ^ 1);
    }
  }
  result = v18;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
