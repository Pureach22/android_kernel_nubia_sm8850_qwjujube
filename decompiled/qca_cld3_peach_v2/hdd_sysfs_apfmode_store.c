__int64 __fastcall hdd_sysfs_apfmode_store(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 *context; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w21
  __int64 v43; // x20
  char *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned __int64 StatusReg; // x8
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x1
  unsigned int *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  unsigned __int64 v83; // x22
  char is_apf_mode_enabled; // w8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int *v93; // x8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x8
  __int64 v103; // [xsp+8h] [xbp-58h] BYREF
  __int64 v104; // [xsp+10h] [xbp-50h] BYREF
  __int64 v105; // [xsp+18h] [xbp-48h] BYREF
  unsigned int v106; // [xsp+24h] [xbp-3Ch] BYREF
  char *stringp; // [xsp+28h] [xbp-38h] BYREF
  _QWORD v108[4]; // [xsp+30h] [xbp-30h] BYREF
  char v109; // [xsp+50h] [xbp-10h]
  __int64 v110; // [xsp+58h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v103 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_apfmode_store", a1, a2, a3, a4, a5, a6, a7, a8);
  v23 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_apfmode_store",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  if ( !v23 )
  {
    v23 = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v103, (__int64)"hdd_sysfs_apfmode_store");
    if ( !v23 )
    {
      v109 = 0;
      memset(v108, 0, sizeof(v108));
      v106 = 0;
      v104 = 0;
      v105 = 0;
      if ( !wlan_hdd_validate_modules_state((__int64)context, v24, v25, v26, v27, v28, v29, v30, v31) )
        goto LABEL_12;
      v33 = hdd_sysfs_validate_and_copy_buf(v108, 33, a11, a12);
      if ( v33 )
      {
        v42 = v33;
        v43 = jiffies;
        if ( _hdd_sysfs_apfmode_store___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid input",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "__hdd_sysfs_apfmode_store");
          _hdd_sysfs_apfmode_store___last_ticks = v43;
        }
        a12 = v42;
        goto LABEL_13;
      }
      stringp = (char *)v108;
      v44 = strsep(&stringp, " ");
      if ( !v44 || (unsigned int)kstrtouint(v44, 0, &v106) )
      {
LABEL_12:
        a12 = -22;
LABEL_13:
        _osif_psoc_sync_op_stop(v103, (__int64)"hdd_sysfs_apfmode_store");
        goto LABEL_4;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: apfmode %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "__hdd_sysfs_apfmode_store",
        v106);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(context + 4);
      }
      else
      {
        raw_spin_lock_bh(context + 4);
        context[5] |= 1uLL;
      }
      hdd_get_front_adapter_no_lock((__int64)context, &v105);
      if ( v105 )
      {
        hdd_adapter_dev_hold_debug(v105, 0x43u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
        v63 = v105;
      }
      else
      {
        v63 = 0;
      }
      hdd_get_next_adapter_no_lock((__int64)context, v63, &v104);
      if ( v104 )
        hdd_adapter_dev_hold_debug(v104, 0x43u, v64, v65, v66, v67, v68, v69, v70, v71, v72);
      v73 = context[5];
      if ( (v73 & 1) != 0 )
      {
        context[5] = v73 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(context + 4);
        v82 = v105;
        if ( !v105 )
          goto LABEL_13;
      }
      else
      {
        raw_spin_unlock(context + 4);
        v82 = v105;
        if ( !v105 )
          goto LABEL_13;
      }
      v83 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( !*(_DWORD *)(v82 + 40) )
          {
            is_apf_mode_enabled = ucfg_pmo_is_apf_mode_enabled(*context, v74, v75, v76, v77, v78, v79, v80, v81);
            v82 = v105;
            if ( (is_apf_mode_enabled & 1) != 0 )
            {
              ucfg_pmo_set_apf_mode(*context, v106, *(unsigned __int8 *)(*(_QWORD *)(v105 + 52832) + 8LL));
              v82 = v105;
            }
          }
          hdd_adapter_dev_put_debug(v82, 0x43u, v74, v75, v76, v77, v78, v79, v80, v81);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v83 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v83 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(context + 4);
          }
          else
          {
            raw_spin_lock_bh(context + 4);
            context[5] |= 1uLL;
          }
          v105 = v104;
          hdd_get_next_adapter_no_lock((__int64)context, v104, &v104);
          hdd_validate_next_adapter(&v105, &v104, 0x43u, v85, v86, v87, v88, v89, v90, v91, v92);
          if ( v104 )
            hdd_adapter_dev_hold_debug(v104, 0x43u, v93, v94, v95, v96, v97, v98, v99, v100, v101);
          v102 = context[5];
          if ( (v102 & 1) != 0 )
            break;
          raw_spin_unlock(context + 4);
          v82 = v105;
          if ( !v105 )
            goto LABEL_13;
        }
        context[5] = v102 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(context + 4);
        v82 = v105;
      }
      while ( v105 );
      goto LABEL_13;
    }
  }
  a12 = v23;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return a12;
}
