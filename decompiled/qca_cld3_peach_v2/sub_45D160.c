// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_45D160(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  unsigned __int16 v4; // w23
  unsigned __int8 *ie_ptr_from_eid; // x25
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int8 v14; // w9
  unsigned __int8 v15; // w1
  bool is_6ghz_op_class; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w1
  __int64 op_class_width; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x20
  __int64 v69; // x20
  __int64 v70; // x20
  __int64 v71; // x20
  __int64 v72; // x19
  __int64 v73; // x20
  __int64 v74; // x21
  __int64 v75; // x22
  char v76; // w23
  unsigned __int8 *v77; // x24
  __int16 v78; // w26
  unsigned __int64 v79; // x27
  unsigned __int8 *v80; // x28
  __int64 result; // x0
  unsigned __int16 v82; // [xsp-98h] [xbp-98h] BYREF
  unsigned __int8 v83; // [xsp-94h] [xbp-94h] BYREF
  unsigned __int8 v84[4]; // [xsp-90h] [xbp-90h] BYREF
  unsigned int v85; // [xsp-8Ch] [xbp-8Ch]
  unsigned __int8 v86; // [xsp-88h] [xbp-88h]
  int v87; // [xsp-84h] [xbp-84h]
  unsigned __int8 v88; // [xsp-7Eh] [xbp-7Eh]
  int v89; // [xsp-78h] [xbp-78h]

  if ( !v74 )
    return populate_dot11f_sr_info(a1, a2, a3);
LABEL_10:
  op_class_width = wlan_reg_get_op_class_width();
LABEL_16:
  wlan_reg_convert_chan_spacing_to_width(op_class_width, (__int16 *)&v82);
  result = wlan_reg_find_chwidth_from_bw(v82);
  v87 = result;
  if ( v85 )
  {
    result = wlan_reg_is_disable_for_pwrmode(v74, v85, 0, v52, v53, v54, v55, v56, v57, v58, v59);
    if ( (result & 1) != 0 )
    {
      v69 = jiffies;
      if ( lim_process_beacon_mlo___last_ticks_8 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "reg disable freq %d from xcsa ie newchannel %d link %d",
                   v60,
                   v61,
                   v62,
                   v63,
                   v64,
                   v65,
                   v66,
                   v67,
                   v85,
                   v77[4],
                   v78 & 0xF);
        lim_process_beacon_mlo___last_ticks_8 = v69;
      }
    }
    else
    {
      v43 = v89 | 2;
LABEL_19:
      v89 = v43;
      result = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int8 *, __int64))mlo_sta_handle_csa_standby_link)(
                 v75,
                 v78 & 0xF,
                 v84,
                 v73);
      if ( (v76 & 1) == 0 )
        result = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int8 *))mlo_sta_csa_save_params)(
                   v75,
                   v78 & 0xF,
                   v84);
      while ( 1 )
      {
        ++v79;
        v80 += 516;
        if ( v79 >= *(unsigned __int16 *)(v72 + 3460) )
          break;
        qdf_mem_set(v84, 0x24u, 0);
        if ( v79 == 4 )
        {
          __break(0x5512u);
          JUMPOUT(0x3D34A0);
        }
        v3 = *v80;
        v78 = *((_WORD *)v80 - 1);
        v4 = *((_WORD *)v80 - 3) - v3 - 4;
        ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x25u, &v80[v3], v4);
        v77 = wlan_get_ie_ptr_from_eid(0x3Cu, &v80[v3], v4);
        v76 = ((__int64 (__fastcall *)(__int64, _QWORD))mlo_is_sta_csa_synced)(v75, v78 & 0xF);
        result = mlo_mgr_get_ap_link_by_link_id(v75, v78 & 0xF);
        if ( !result )
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     2u,
                     "%s: link info null",
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     "lim_process_beacon_mlo");
          break;
        }
        if ( v77 )
        {
          v14 = v77[4];
          v86 = v77[2];
          v15 = v77[3];
          v84[0] = v14;
          v88 = v15;
          is_6ghz_op_class = wlan_reg_is_6ghz_op_class(v74, v15);
          v25 = v77[4];
          if ( is_6ghz_op_class )
          {
            v85 = wlan_reg_chan_band_to_freq(v74, v25, 4u, v17, v18, v19, v20, v21, v22, v23, v24);
            goto LABEL_10;
          }
          v85 = wlan_reg_legacy_chan_to_freq(v74, v25, v17, v18, v19, v20, v21, v22, v23, v24);
          op_class_width = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                             &v83,
                             v84[0],
                             v77[3],
                             v44,
                             v45,
                             v46,
                             v47,
                             v48,
                             v49,
                             v50,
                             v51);
          goto LABEL_16;
        }
        if ( ie_ptr_from_eid )
        {
          v84[0] = ie_ptr_from_eid[3];
          result = wlan_reg_legacy_chan_to_freq(v74, v84[0], v6, v7, v8, v9, v10, v11, v12, v13);
          v85 = result;
          if ( (_DWORD)result )
          {
            result = wlan_reg_is_disable_for_pwrmode(v74, result, 0, v27, v28, v29, v30, v31, v32, v33, v34);
            if ( (result & 1) == 0 )
            {
              v86 = ie_ptr_from_eid[2];
              v43 = v89 | 1;
              goto LABEL_19;
            }
            v71 = jiffies;
            if ( lim_process_beacon_mlo___last_ticks_12 - jiffies + 125 < 0 )
            {
              result = qdf_trace_msg(
                         0x35u,
                         8u,
                         "reg disable freq %d from csa ie newchannel %d link %d",
                         v35,
                         v36,
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v85,
                         ie_ptr_from_eid[3],
                         v78 & 0xF);
              lim_process_beacon_mlo___last_ticks_12 = v71;
            }
          }
          else
          {
            v70 = jiffies;
            if ( lim_process_beacon_mlo___last_ticks_10 - jiffies + 125 < 0 )
            {
              result = qdf_trace_msg(
                         0x35u,
                         8u,
                         "invalid freq from csa ie newchannel %d link %d",
                         v27,
                         v28,
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         ie_ptr_from_eid[3],
                         v78 & 0xF);
              lim_process_beacon_mlo___last_ticks_10 = v70;
            }
          }
          break;
        }
      }
    }
  }
  else
  {
    v68 = jiffies;
    if ( lim_process_beacon_mlo___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "invalid freq from xcsa ie newchannel %d link %d",
                 v52,
                 v53,
                 v54,
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v77[4],
                 v78 & 0xF);
      lim_process_beacon_mlo___last_ticks = v68;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
