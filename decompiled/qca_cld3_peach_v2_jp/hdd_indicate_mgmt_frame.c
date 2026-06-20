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
  __int64 v20; // x21
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
  __int64 v34; // x24
  __int64 v35; // x22
  __int64 v36; // x8
  _QWORD *v37; // x1
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w23
  unsigned __int64 v47; // x26
  __int64 v49; // x10
  unsigned __int64 v50; // x12
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 *v60; // x24
  __int64 v61; // x8
  __int64 v62; // x8
  unsigned int *v63; // x8
  unsigned int v64; // w10
  __int64 v65; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  unsigned int v81; // w9
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x8
  __int64 v91; // x9
  unsigned __int64 v92; // x8
  __int64 v93; // x9
  unsigned int *v94; // x9
  unsigned int v95; // w12
  __int64 v96; // x9
  __int64 v97; // x9
  unsigned __int64 v98; // x8
  __int64 v99; // x9
  unsigned int *v100; // x9
  unsigned int v101; // w12
  __int64 v102; // x9
  unsigned int v105; // w9
  unsigned int v107; // w9
  __int64 *v108; // [xsp+8h] [xbp-18h] BYREF
  int v109; // [xsp+10h] [xbp-10h]
  __int16 v110; // [xsp+14h] [xbp-Ch]
  __int64 v111; // [xsp+18h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
    if ( (unsigned int)ieee80211_hdrlen(a1[8]) > (unsigned int)v20 )
    {
      v29 = "%s:  Invalid frame length";
LABEL_4:
      result = qdf_trace_msg(0x33u, 2u, v29, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_indicate_mgmt_frame");
      goto LABEL_83;
    }
    v30 = *((unsigned __int8 *)a1 + 8);
    v110 = 0;
    v109 = 0;
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
      goto LABEL_83;
    }
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
    v108 = nullptr;
    v33 = qdf_list_peek_front(context + 6, &v108);
    if ( (_DWORD)v33 || (v37 = v108, v34 = (__int64)(v108 - 1), v108 == &qword_8) )
    {
      v34 = 0;
    }
    else
    {
      v91 = *(__int64 *)((char *)&off_18 + (_QWORD)v108);
      if ( v91 )
      {
        v92 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v92 + 16);
        v93 = *(_QWORD *)(v91 + 1320);
        v94 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v93);
        do
          v95 = __ldxr(v94);
        while ( __stxr(v95 + 1, v94) );
        v96 = *(_QWORD *)(v92 + 16) - 1LL;
        *(_DWORD *)(v92 + 16) = v96;
        if ( !v96 || !*(_QWORD *)(v92 + 16) )
        {
          v20 = (__int64)v37;
          preempt_schedule_notrace(v33);
          v37 = (_QWORD *)v20;
        }
      }
      _X8 = (unsigned int *)(v37 + 6583);
LABEL_116:
      __asm { PRFM            #0x11, [X8] }
      do
        v105 = __ldxr(_X8);
      while ( __stxr(v105 + 1, _X8) );
      v108 = nullptr;
      result = qdf_list_peek_next(context + 6, v37, &v108);
      if ( !(_DWORD)result )
      {
        v20 = (__int64)v108;
        v35 = (__int64)(v108 - 1);
        if ( v108 != &qword_8 )
        {
          v97 = *(__int64 *)((char *)&off_18 + (_QWORD)v108);
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
LABEL_114:
              preempt_schedule_notrace(result);
          }
          _X8 = (unsigned int *)(v20 + 52664);
          __asm { PRFM            #0x11, [X8] }
          do
            v107 = __ldxr(_X8);
          while ( __stxr(v107 + 1, _X8) );
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
        goto LABEL_83;
    }
    else
    {
      result = raw_spin_unlock(context + 4);
      if ( !v34 )
        goto LABEL_83;
    }
    v46 = 0;
    v47 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (*(_QWORD *)(v34 + 1640) & 1) != 0 )
      {
        _X8 = (unsigned int *)(v34 + 52832);
        if ( v34 != -52832 )
        {
          if ( v46 <= 6 )
            v49 = 6;
          else
            v49 = v46;
          if ( v46 > 5 )
            goto LABEL_113;
          *((_BYTE *)&v109 + v46) = *(_BYTE *)(v34 + 52840);
          v50 = v46 + 1LL;
          if ( 19 * (unsigned __int8)((unsigned int)(v34 - *(_DWORD *)(v34 + 52832)) >> 4) == 0xFF
            && (*(_QWORD *)(v34 + 1640) & 1) != 0 )
          {
            if ( v50 == v49 )
              goto LABEL_113;
            if ( v46 == 5 )
              goto LABEL_115;
            *((_BYTE *)&v109 + v50) = *(_BYTE *)(v34 + 52840);
            v50 = v46 + 2LL;
            if ( 19 * (unsigned __int8)((unsigned int)(v34 - *(_DWORD *)(v34 + 52832)) >> 4) == 0xFF
              && (*(_QWORD *)(v34 + 1640) & 1) != 0 )
            {
              if ( v50 == v49 )
                goto LABEL_113;
              if ( v46 > 3 )
                goto LABEL_115;
              *((_BYTE *)&v109 + v50) = *(_BYTE *)(v34 + 52840);
              v50 = v46 + 3LL;
              if ( 19 * (unsigned __int8)((unsigned int)(v34 - *(_DWORD *)(v34 + 52832)) >> 4) == 0xFF
                && (*(_QWORD *)(v34 + 1640) & 1) != 0 )
              {
                if ( v50 == v49 )
                  goto LABEL_113;
                if ( v46 == 3 )
                  goto LABEL_115;
                *((_BYTE *)&v109 + v50) = *(_BYTE *)(v34 + 52840);
                v50 = v46 | 4LL;
                if ( 19 * (unsigned __int8)((unsigned int)(v34 - *(_DWORD *)(v34 + 52832)) >> 4) == 0xFF
                  && (*(_QWORD *)(v34 + 1640) & 1) != 0 )
                {
                  if ( v50 == v49 )
                    goto LABEL_113;
                  if ( v50 > 5 )
                    goto LABEL_115;
                  *((_BYTE *)&v109 + v50) = *(_BYTE *)(v34 + 52840);
                  v50 = v46 + 5LL;
                  if ( 19 * (unsigned __int8)((unsigned int)(v34 - *(_DWORD *)(v34 + 52832)) >> 4) == 0xFF
                    && (*(_QWORD *)(v34 + 1640) & 1) != 0 )
                  {
                    if ( v50 == v49 )
                      goto LABEL_113;
                    if ( v46 )
                    {
LABEL_115:
                      __break(1u);
                      goto LABEL_116;
                    }
                    *((_BYTE *)&v109 + v50) = *(_BYTE *)(v34 + 52840);
                    if ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v34 - *(_DWORD *)(v34 + 52832)) >> 4))
                      && (*(_QWORD *)(v34 + 1640) & 1) != 0 )
                    {
                      goto LABEL_113;
                    }
                    LODWORD(v50) = 6;
                  }
                }
              }
            }
          }
          v46 = v50;
        }
      }
      hdd_adapter_dev_put_debug(v34, 0x25u, v38, v39, v40, v41, v42, v43, v44, v45);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v47 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v47 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(context + 4);
        if ( !v35 )
          goto LABEL_69;
LABEL_57:
        v108 = nullptr;
        v51 = qdf_list_peek_next(context + 6, (_QWORD *)(v35 + 8), &v108);
        v20 = (__int64)(v108 - 1);
        if ( (_DWORD)v51 )
          v60 = nullptr;
        else
          v60 = v108 - 1;
        if ( (__int64 *)v35 == v60 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v35, 0x25u, v67, v68, v69, v70, v71, v72, v73, v74);
          goto LABEL_69;
        }
        if ( v60 )
        {
          v61 = v60[4];
          if ( v61 )
          {
            ++*(_DWORD *)(v47 + 16);
            v62 = *(_QWORD *)(v61 + 1320);
            v63 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v62);
            do
              v64 = __ldxr(v63);
            while ( __stxr(v64 + 1, v63) );
            v65 = *(_QWORD *)(v47 + 16) - 1LL;
            *(_DWORD *)(v47 + 16) = v65;
            if ( !v65 || !*(_QWORD *)(v47 + 16) )
              preempt_schedule_notrace(v51);
          }
          _X8 = (unsigned int *)(v60 + 6584);
          __asm { PRFM            #0x11, [X8] }
          do
            v81 = __ldxr(_X8);
          while ( __stxr(v81 + 1, _X8) );
        }
        else
        {
          v20 = 0;
        }
        v34 = v35;
        v75 = context[5];
        if ( (v75 & 1) != 0 )
          goto LABEL_74;
LABEL_70:
        result = raw_spin_unlock(context + 4);
        v35 = v20;
        if ( !v34 )
          goto LABEL_84;
      }
      else
      {
        raw_spin_lock_bh(context + 4);
        context[5] |= 1uLL;
        if ( v35 )
          goto LABEL_57;
LABEL_69:
        v20 = 0;
        v34 = 0;
        v75 = context[5];
        if ( (v75 & 1) == 0 )
          goto LABEL_70;
LABEL_74:
        context[5] = v75 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(context + 4);
        v35 = v20;
        if ( !v34 )
        {
LABEL_84:
          if ( (int)v46 < 1 )
            break;
          v20 = 0;
          v35 = v46;
          while ( v20 != 6 )
          {
            result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       *context,
                       *((unsigned __int8 *)&v109 + v20),
                       6);
            if ( result )
            {
              v90 = *(_QWORD *)(result + 608);
              if ( v90 )
              {
                v90 = *(_QWORD *)(v90 + 8);
                if ( v90 )
                {
                  v34 = result;
                  hdd_indicate_mgmt_frame_to_user(
                    v90,
                    *a1,
                    a1 + 8,
                    *((unsigned __int8 *)a1 + 9),
                    *((unsigned int *)a1 + 1),
                    *((unsigned __int8 *)a1 + 10),
                    *((unsigned int *)a1 + 3));
                  result = v34;
                }
              }
              result = wlan_objmgr_vdev_release_ref(
                         result,
                         6u,
                         (unsigned int *)v90,
                         v82,
                         v83,
                         v84,
                         v85,
                         v86,
                         v87,
                         v88,
                         v89);
            }
            if ( v46 == ++v20 )
              goto LABEL_83;
          }
LABEL_113:
          __break(0x5512u);
          goto LABEL_114;
        }
      }
    }
  }
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
