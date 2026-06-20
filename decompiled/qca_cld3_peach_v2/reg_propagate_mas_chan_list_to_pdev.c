__int64 __fastcall reg_propagate_mas_chan_list_to_pdev(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x24
  __int64 pdev_obj; // x0
  __int64 v17; // x22
  unsigned int v18; // w25
  __int64 result; // x0
  _DWORD *v20; // x8
  __int64 v21; // x23
  const char *v22; // x2
  __int64 inited; // x0
  _QWORD *v24; // x25
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w5
  __int64 v34; // x4
  __int64 v35; // x9
  __int64 v36; // x10
  int v37; // w11
  int v38; // w12
  int v39; // w13
  int v40; // w11
  int v41; // w12
  int v42; // w13
  int v43; // w11
  int v44; // w12
  int v45; // w11
  int v46; // w11
  int v47; // w11
  double updated; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  void (__fastcall *v56)(_QWORD); // x8
  _BYTE v57[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v58; // [xsp+8h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57[0] = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xDu);
  if ( !comp_private_obj )
  {
    v22 = "%s: psoc priv obj is NULL";
LABEL_10:
    result = qdf_trace_msg(0x51u, 2u, v22, v7, v8, v9, v10, v11, v12, v13, v14, "reg_propagate_mas_chan_list_to_pdev");
    goto LABEL_34;
  }
  v15 = comp_private_obj;
  pdev_obj = reg_get_pdev_obj(a2);
  if ( !pdev_obj )
  {
    v22 = "%s: reg pdev priv obj is NULL";
    goto LABEL_10;
  }
  v17 = pdev_obj;
  v18 = *(unsigned __int8 *)(a2 + 40);
  result = reg_get_psoc_tx_ops(a1);
  if ( !result )
  {
LABEL_34:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v20 = *(_DWORD **)(result + 128);
  v21 = result;
  if ( v20 )
  {
    if ( *(v20 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _BYTE *))v20)(a1, v18, v57);
  }
  else
  {
    v57[0] = v18;
  }
  inited = (__int64)qdf_mem_copy((void *)(v17 + 58946), (const void *)(v15 + 93960), 8u);
  if ( v57[0] < 4uLL )
  {
    inited = reg_init_pdev_mas_chan_list((_BYTE *)v17, v15 + 30364LL * v57[0]);
    if ( v57[0] <= 2uLL )
    {
      v24 = (_QWORD *)(v17 + 56728);
      ((void (__fastcall *)(__int64, __int64))reg_save_reg_rules_to_pdev)(v15 + 30364LL * v57[0] + 29624, v17);
      if ( *(_BYTE *)(v17 + 56760) == 1 && *(_BYTE *)(v17 + 57610) )
      {
        v33 = 0;
      }
      else if ( (reg_does_country_supp_c2c(*v24) & 1) != 0
             && (reg_is_indoor_ap_detected(*v24) & 1) != 0
             && *(_BYTE *)(v17 + 57613) )
      {
        v33 = 3;
      }
      else
      {
        v33 = *(_BYTE *)(v17 + 57612) ? 2 : 4;
      }
      v34 = *(unsigned __int8 *)(v17 + 56760);
      *(_DWORD *)(v17 + 58204) = v33;
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: indoor_chan_enabled %d ap_pwr_type %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "reg_set_ap_pwr_type",
        v34);
      inited = (__int64)qdf_mem_set((void *)(v17 + 36940), 0x3ED0u, 0);
      v35 = -16080;
      do
      {
        v36 = v17 + 37156 + v35;
        v35 += 268;
        v37 = *(_DWORD *)(v36 + 15924);
        v38 = *(_DWORD *)(v36 + 15928);
        v39 = *(_DWORD *)(v36 + 15932);
        *(_QWORD *)(v36 + 16080) = 0;
        *(_DWORD *)(v36 + 15924) = v37 | 1;
        v40 = *(_DWORD *)(v36 + 15936);
        *(_DWORD *)(v36 + 15928) = v38 | 1;
        v41 = *(_DWORD *)(v36 + 15940);
        *(_DWORD *)(v36 + 15932) = v39 | 1;
        v42 = *(_DWORD *)(v36 + 15944);
        *(_DWORD *)(v36 + 15936) = v40 | 1;
        v43 = v41 | 1;
        v44 = *(_DWORD *)(v36 + 15948);
        *(_DWORD *)(v36 + 15940) = v43;
        *(_DWORD *)(v36 + 15944) = v42 | 1;
        *(_DWORD *)(v36 + 15948) = v44 | 1;
        v45 = *(_DWORD *)(v36 + 15952);
        *(_QWORD *)(v36 + 16088) = 0;
        *(_QWORD *)(v36 + 16096) = 0;
        *(_DWORD *)(v36 + 15952) = v45 | 1;
        v46 = *(_DWORD *)(v36 + 15956);
        *(_QWORD *)(v36 + 16104) = 0;
        *(_QWORD *)(v36 + 16112) = 0;
        *(_DWORD *)(v36 + 15956) = v46 | 1;
        v47 = *(_DWORD *)(v36 + 15960);
        *(_QWORD *)(v36 + 16120) = 0;
        *(_DWORD *)(v36 + 16128) = 0;
        *(_DWORD *)(v36 + 15960) = v47 | 1;
        *(_DWORD *)(v36 + 15964) |= 1u;
        *(_DWORD *)(v36 + 15968) |= 1u;
        *(_DWORD *)(v36 + 15972) |= 1u;
      }
      while ( v35 );
      if ( v57[0] <= 2uLL )
      {
        *(_BYTE *)(v17 + 58200) = *(_BYTE *)(v15 + v57[0] + 91092);
        reg_init_indoor_channel_list(a2);
        reg_compute_indoor_list_on_cc_change(a1, a2);
        updated = reg_update_channel_ranges(a2);
        reg_compute_pdev_current_chan_list(v17, updated, v49, v50, v51, v52, v53, v54, v55);
        v56 = *(void (__fastcall **)(_QWORD))(v21 + 152);
        if ( v56 )
        {
          if ( *((_DWORD *)v56 - 1) != -2099273483 )
            __break(0x8228u);
          v56(a2);
        }
        if ( *a3 )
          result = reg_send_scheduler_msg_sb(a1, a2);
        else
          result = reg_send_scheduler_msg_nb(a1, a2);
        goto LABEL_34;
      }
    }
  }
  __break(0x5512u);
  return reg_copy_from_super_chan_info_to_reg_channel(inited);
}
