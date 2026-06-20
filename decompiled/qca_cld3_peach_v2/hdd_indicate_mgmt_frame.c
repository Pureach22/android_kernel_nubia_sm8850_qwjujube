__int64 __fastcall hdd_indicate_mgmt_frame(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  unsigned int v20; // w19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  int v30; // w1
  __int64 link_info_by_vdev; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v33; // x0
  __int64 v34; // x22
  __int64 v35; // x19
  __int64 v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int64 v45; // x25
  unsigned __int64 v46; // x28
  __int64 v47; // x10
  __int64 v48; // x8
  unsigned int v49; // w10
  __int64 v50; // x11
  __int64 v51; // x12
  __int64 v52; // x10
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x21
  __int64 *v63; // x22
  __int64 v64; // x8
  __int64 v65; // x8
  unsigned int *v66; // x8
  unsigned int v67; // w10
  __int64 v68; // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x8
  unsigned int v84; // w9
  __int64 v85; // x19
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x8
  __int64 v95; // x22
  __int64 *v96; // x1
  __int64 v97; // x9
  unsigned __int64 v98; // x8
  __int64 v99; // x9
  unsigned int *v100; // x9
  unsigned int v101; // w12
  __int64 v102; // x9
  __int64 v104; // x0
  __int64 *v105; // x21
  __int64 v106; // x9
  unsigned __int64 v107; // x8
  __int64 v108; // x9
  unsigned int *v109; // x9
  unsigned int v110; // w12
  __int64 v111; // x9
  __int64 *v113; // x19
  unsigned int v115; // w9
  unsigned int v117; // w9
  unsigned __int16 *v118; // [xsp+8h] [xbp-28h]
  __int64 *v119; // [xsp+10h] [xbp-20h] BYREF
  __int64 v120; // [xsp+18h] [xbp-18h]
  char v121; // [xsp+20h] [xbp-10h]
  __int64 v122; // [xsp+28h] [xbp-8h]

  v122 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_indicate_mgmt_frame", a2, a3, a4, a5, a6, a7, a8, a9);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_indicate_mgmt_frame",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18);
  if ( !(_DWORD)result )
  {
    v20 = *a1;
    if ( (unsigned int)ieee80211_hdrlen(a1[8]) > v20 )
    {
      v29 = "%s:  Invalid frame length";
LABEL_4:
      result = qdf_trace_msg(0x33u, 2u, v29, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_indicate_mgmt_frame");
      goto LABEL_71;
    }
    v30 = *((unsigned __int8 *)a1 + 8);
    v121 = 0;
    v120 = 0;
    if ( v30 != 255 )
    {
      if ( v30 == 50 )
      {
        link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, 0);
        if ( !link_info_by_vdev )
        {
          link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, 1);
          if ( !link_info_by_vdev )
          {
            link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, 2);
            if ( !link_info_by_vdev )
            {
              link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, 3);
              if ( !link_info_by_vdev )
              {
                link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, 4);
                if ( !link_info_by_vdev )
                  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, 5);
              }
            }
          }
        }
      }
      else
      {
        link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, v30);
        if ( !link_info_by_vdev )
        {
          v29 = "%s: Invalid vdev";
          goto LABEL_4;
        }
      }
      result = hdd_indicate_mgmt_frame_to_user(
                 link_info_by_vdev,
                 *a1,
                 a1 + 8,
                 *((unsigned __int8 *)a1 + 9),
                 *((unsigned int *)a1 + 1),
                 *((unsigned __int8 *)a1 + 10),
                 *((unsigned int *)a1 + 3));
      goto LABEL_71;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
        goto LABEL_101;
    }
    raw_spin_lock(context + 4);
LABEL_17:
    v119 = nullptr;
    v33 = qdf_list_peek_front(context + 6, &v119);
    if ( (_DWORD)v33 || (v96 = v119, v34 = (__int64)(v119 - 1), v119 == &qword_8) )
    {
      v34 = 0;
    }
    else
    {
      v97 = *(__int64 *)((char *)&off_18 + (_QWORD)v119);
      if ( v97 )
      {
        v98 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v98 + 16);
        v99 = *(_QWORD *)(v97 + 1320);
        v100 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v99);
        do
          v101 = __ldxr(v100);
        while ( __stxr(v101 + 1, v100) );
        v102 = *(_QWORD *)(v98 + 16) - 1LL;
        *(_DWORD *)(v98 + 16) = v102;
        if ( !v102 || !*(_QWORD *)(v98 + 16) )
        {
          v113 = v96;
          preempt_schedule_notrace(v33);
          v96 = v113;
        }
      }
      _X8 = (unsigned int *)(v96 + 6583);
      __asm { PRFM            #0x11, [X8] }
      do
        v115 = __ldxr(_X8);
      while ( __stxr(v115 + 1, _X8) );
      v119 = nullptr;
      v104 = qdf_list_peek_next(context + 6, v96, &v119);
      if ( !(_DWORD)v104 )
      {
        v105 = v119;
        v35 = (__int64)(v119 - 1);
        if ( v119 != &qword_8 )
        {
          v106 = *(__int64 *)((char *)&off_18 + (_QWORD)v119);
          if ( v106 )
          {
            v107 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v107 + 16);
            v108 = *(_QWORD *)(v106 + 1320);
            v109 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v108);
            do
              v110 = __ldxr(v109);
            while ( __stxr(v110 + 1, v109) );
            v111 = *(_QWORD *)(v107 + 16) - 1LL;
            *(_DWORD *)(v107 + 16) = v111;
            if ( !v111 || !*(_QWORD *)(v107 + 16) )
              preempt_schedule_notrace(v104);
          }
          _X8 = (unsigned int *)(v105 + 6583);
          __asm { PRFM            #0x11, [X8] }
          do
            v117 = __ldxr(_X8);
          while ( __stxr(v117 + 1, _X8) );
        }
        goto LABEL_20;
      }
    }
    v35 = 0;
LABEL_20:
    v36 = context[5];
    if ( (v36 & 1) != 0 )
    {
      context[5] = v36 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(context + 4);
      if ( !v34 )
        goto LABEL_71;
    }
    else
    {
      result = raw_spin_unlock(context + 4);
      if ( !v34 )
        goto LABEL_71;
    }
    v118 = a1;
    v45 = 0;
    a1 = (_WORD *)(&qword_48 + 1);
    v46 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_QWORD *)(v34 + 1640) & 1) != 0 && (v47 = v34 + 52840, v34 != -52840)
        || (*(_QWORD *)(v34 + 1640) & 2) != 0 && (v47 = v34 + 58928, v34 != -58928)
        || (*(_QWORD *)(v34 + 1640) & 4) != 0 && (v47 = v34 + 65016, v34 != -65016) )
      {
        v48 = 9;
        if ( v45 > 9 )
          v48 = v45;
        while ( v45 != v48 )
        {
          if ( v45 > 8 )
            goto LABEL_100;
          *((_BYTE *)&v120 + v45++) = *(_BYTE *)(v47 + 8);
          v49 = 73 * ((unsigned int)(v47 - *(_DWORD *)v47 - 52840) >> 3) + 1;
          if ( (unsigned __int8)v49 <= 2u )
          {
            v50 = (unsigned __int8)v49;
            v47 = 0;
            v51 = v34 + 52840 + 6088LL * (unsigned int)v50;
            do
            {
              if ( v47 )
                break;
              v52 = *(_QWORD *)(v34 + 1640) >> v50++;
              v47 = (v52 << 63 >> 63) & v51;
              v51 += 6088;
            }
            while ( v50 != 3 );
            if ( v47 )
              continue;
          }
          v45 = (unsigned int)v45;
          goto LABEL_41;
        }
        goto LABEL_99;
      }
LABEL_41:
      hdd_adapter_dev_put_debug(v34, 0x25u, v37, v38, v39, v40, v41, v42, v43, v44);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v46 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v46 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(context + 4);
        if ( !v35 )
          goto LABEL_57;
LABEL_45:
        v119 = nullptr;
        v53 = qdf_list_peek_next(context + 6, (_QWORD *)(v35 + 8), &v119);
        v62 = (__int64)(v119 - 1);
        if ( (_DWORD)v53 )
          v63 = nullptr;
        else
          v63 = v119 - 1;
        if ( (__int64 *)v35 == v63 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v35, 0x25u, v70, v71, v72, v73, v74, v75, v76, v77);
          goto LABEL_57;
        }
        if ( v63 )
        {
          v64 = v63[4];
          if ( v64 )
          {
            ++*(_DWORD *)(v46 + 16);
            v65 = *(_QWORD *)(v64 + 1320);
            v66 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v65);
            do
              v67 = __ldxr(v66);
            while ( __stxr(v67 + 1, v66) );
            v68 = *(_QWORD *)(v46 + 16) - 1LL;
            *(_DWORD *)(v46 + 16) = v68;
            if ( !v68 || !*(_QWORD *)(v46 + 16) )
              preempt_schedule_notrace(v53);
          }
          _X8 = (unsigned int *)(v63 + 6584);
          __asm { PRFM            #0x11, [X8] }
          do
            v84 = __ldxr(_X8);
          while ( __stxr(v84 + 1, _X8) );
        }
        else
        {
          v62 = 0;
        }
        v34 = v35;
        v78 = context[5];
        if ( (v78 & 1) != 0 )
          goto LABEL_62;
LABEL_58:
        result = raw_spin_unlock(context + 4);
        v35 = v62;
        if ( !v34 )
          goto LABEL_72;
      }
      else
      {
        raw_spin_lock_bh(context + 4);
        context[5] |= 1uLL;
        if ( v35 )
          goto LABEL_45;
LABEL_57:
        v62 = 0;
        v34 = 0;
        v78 = context[5];
        if ( (v78 & 1) == 0 )
          goto LABEL_58;
LABEL_62:
        context[5] = v78 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(context + 4);
        v35 = v62;
        if ( !v34 )
        {
LABEL_72:
          if ( (int)v45 < 1 )
            break;
          v85 = 0;
          while ( v85 != 9 )
          {
            result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       *context,
                       *((unsigned __int8 *)&v120 + v85),
                       6);
            if ( result )
            {
              v94 = *(_QWORD *)(result + 680);
              if ( v94 )
              {
                v94 = *(_QWORD *)(v94 + 8);
                if ( v94 )
                {
                  v95 = result;
                  hdd_indicate_mgmt_frame_to_user(
                    v94,
                    *v118,
                    v118 + 8,
                    *((unsigned __int8 *)v118 + 9),
                    *((unsigned int *)v118 + 1),
                    *((unsigned __int8 *)v118 + 10),
                    *((unsigned int *)v118 + 3));
                  result = v95;
                }
              }
              result = wlan_objmgr_vdev_release_ref(
                         result,
                         6u,
                         (unsigned int *)v94,
                         v86,
                         v87,
                         v88,
                         v89,
                         v90,
                         v91,
                         v92,
                         v93);
            }
            if ( v45 == ++v85 )
              goto LABEL_71;
          }
LABEL_99:
          __break(0x5512u);
LABEL_100:
          __break(1u);
LABEL_101:
          raw_spin_lock_bh(context + 4);
          context[5] |= 1uLL;
          goto LABEL_17;
        }
      }
    }
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
