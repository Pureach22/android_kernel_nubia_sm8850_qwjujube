_QWORD *__fastcall htt_t2h_stats_handler(
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
  unsigned __int64 StatusReg; // x8
  _QWORD *v11; // x10
  _QWORD *v12; // x10
  int v13; // w11
  _QWORD *v14; // x9
  _QWORD *v15; // x11
  _QWORD *result; // x0
  __int64 v17; // x8
  int v18; // w22
  __int64 v19; // x1
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x20
  unsigned int v29; // w24
  char *v30; // x27
  __int64 v31; // x25
  int v32; // w23
  _QWORD *v33; // x8
  __int64 v34; // x21
  int v35; // w26
  unsigned __int64 v36; // x28
  __int64 v37; // x22
  __int64 v38; // x23
  const char *v39; // x2
  _DWORD *v40; // x21
  unsigned int v41; // w23
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  void *v50; // x0
  unsigned int *v51; // x27
  unsigned int v52; // w25
  __int64 v53; // x24
  unsigned __int64 v54; // x9
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x27
  unsigned int v64; // w24
  __int64 v65; // x1
  __int64 v66; // x25
  __int64 v67; // x15
  unsigned int v68; // w9
  unsigned int v75; // w11
  __int64 v76; // x4
  const char *v77; // x2
  __int64 v78; // x8
  __int64 v79; // x1
  __int64 v80; // x8
  unsigned int v83; // w9
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  _QWORD *v92; // x8
  __int64 v93; // x8
  __int64 v94; // [xsp+0h] [xbp-60h]
  unsigned __int64 v95; // [xsp+8h] [xbp-58h]
  char *v96; // [xsp+10h] [xbp-50h]
  int v97; // [xsp+1Ch] [xbp-44h]
  unsigned int *v98; // [xsp+20h] [xbp-40h]
  unsigned int v99; // [xsp+2Ch] [xbp-34h]
  __int64 v100; // [xsp+30h] [xbp-30h] BYREF
  _QWORD *v101; // [xsp+38h] [xbp-28h] BYREF
  _QWORD **v102; // [xsp+40h] [xbp-20h]
  __int64 v103; // [xsp+48h] [xbp-18h]
  __int64 v104; // [xsp+50h] [xbp-10h]
  __int64 v105; // [xsp+58h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v103 = 0;
  v104 = 0;
  v101 = nullptr;
  v102 = nullptr;
  v100 = 0;
  if ( !a1 )
  {
    result = (_QWORD *)qdf_trace_msg(0x3Fu, 2u, "soc is NULL", a2, a3, a4, a5, a6, a7, a8, a9);
    goto LABEL_119;
  }
  if ( !*(_DWORD *)(a1 + 56) )
  {
    result = (_QWORD *)qdf_trace_msg(
                         0x3Fu,
                         2u,
                         "soc: 0x%pK, init_done: %d",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a1,
                         *(unsigned int *)(a1 + 56));
    goto LABEL_119;
  }
  qdf_mem_set(&v100, 0x28u, 0);
  v102 = nullptr;
  v103 = 0;
  v101 = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 17928);
      *(_QWORD *)(a1 + 17936) |= 1uLL;
      if ( *(_DWORD *)(a1 + 18016) )
        goto LABEL_13;
LABEL_117:
      v93 = *(_QWORD *)(a1 + 17936);
      if ( (v93 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 17936) = v93 & 0xFFFFFFFFFFFFFFFELL;
        result = (_QWORD *)raw_spin_unlock_bh(a1 + 17928);
      }
      else
      {
        result = (_QWORD *)raw_spin_unlock(a1 + 17928);
      }
      goto LABEL_119;
    }
  }
  raw_spin_lock(a1 + 17928);
  if ( !*(_DWORD *)(a1 + 18016) )
    goto LABEL_117;
  do
  {
LABEL_13:
    v14 = *(_QWORD **)(a1 + 17992);
    if ( !v14 )
      break;
    v15 = *(_QWORD **)(a1 + 18000);
    --*(_DWORD *)(a1 + 18008);
    if ( v14 == v15 )
    {
      v11 = nullptr;
      *(_QWORD *)(a1 + 18000) = 0;
    }
    else
    {
      v11 = (_QWORD *)*v14;
    }
    *(_QWORD *)(a1 + 17992) = v11;
    *v14 = 0;
    v12 = v101 ? v102 : &v101;
    v13 = *(_DWORD *)(v14[28] + 12LL);
    *v12 = v14;
    v102 = (_QWORD **)v14;
    LODWORD(v103) = v103 + 1;
  }
  while ( (v13 & 0x800) == 0 );
  v17 = *(_QWORD *)(a1 + 17936);
  v18 = *(_DWORD *)(a1 + 18016) - 1;
  *(_DWORD *)(a1 + 18016) = v18;
  if ( (v17 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17936) = v17 & 0xFFFFFFFFFFFFFFFELL;
    result = (_QWORD *)raw_spin_unlock_bh(a1 + 17928);
    if ( !v18 )
      goto LABEL_20;
    goto LABEL_19;
  }
  result = (_QWORD *)raw_spin_unlock(a1 + 17928);
  if ( v18 )
LABEL_19:
    result = (_QWORD *)queue_work_on(32, system_wq, a1 + 17944);
LABEL_20:
  v28 = v101;
  if ( !v101 )
    goto LABEL_119;
  v29 = 0;
  v30 = nullptr;
  v31 = 0;
  v32 = 255;
  v97 = 0;
  v95 = _ReadStatusReg(SP_EL0);
  do
  {
    LODWORD(v103) = v103 - 1;
    if ( v28 == v102 )
    {
      v33 = nullptr;
      v102 = nullptr;
    }
    else
    {
      v33 = (_QWORD *)*v28;
    }
    v34 = v28[28];
    v101 = v33;
    *v28 = 0;
    v35 = *(_DWORD *)(v34 + 4);
    LODWORD(v104) = *(unsigned __int16 *)(v34 + 14);
    v36 = *(unsigned int *)(v34 + 8);
    if ( (v36 & 3) != 0 )
      __break(0x5512u);
    v37 = *(_QWORD *)(a1 + 72);
    if ( !v35 && (v36 & 0x10) != 0 )
      goto LABEL_28;
    v99 = v32;
    if ( v35 || (v36 & 0x20) == 0 )
      goto LABEL_39;
    v38 = *(_QWORD *)(v37 + 8);
    if ( !v38 )
    {
      v39 = "%s: soc is null";
LABEL_37:
      qdf_trace_msg(0x80u, 2u, v39, v20, v21, v22, v23, v24, v25, v26, v27, "dp_htt_stats_sysfs_update_config", v94);
      goto LABEL_38;
    }
    if ( !*(_QWORD *)(v38 + 17584) )
    {
      v39 = "%s: soc->sysfs_config is NULL";
      goto LABEL_37;
    }
    *(_DWORD *)(*(_QWORD *)(v38 + 17584) + 152LL) = qdf_get_current_pid();
    *(_DWORD *)(*(_QWORD *)(v38 + 17584) + 148LL) = 1;
LABEL_38:
    v32 = v99;
LABEL_39:
    v40 = (_DWORD *)(v34 + 16);
    v97 |= (v36 >> 3) & 1;
    if ( !(_DWORD)v104 )
      goto LABEL_100;
    if ( (unsigned int)v104 >= 0x800 )
      v41 = 2048;
    else
      v41 = v104;
    do
    {
      if ( v31 )
      {
        if ( !v29 )
        {
          _qdf_mem_free(v31);
          goto LABEL_108;
        }
        if ( v29 > v41 )
          goto LABEL_44;
        v50 = v30;
        v96 = v30;
        v51 = (unsigned int *)v31;
        v52 = v29;
        qdf_mem_copy(v50, v40, v29);
        v53 = (__int64)v51;
        v98 = v51;
      }
      else
      {
        v54 = ((unsigned __int64)(unsigned int)*v40 >> 12) & 0xFFF;
        if ( !(_DWORD)v54 )
          goto LABEL_108;
        v29 = v54 + 4;
        v99 = *v40 & 0xFFF;
        if ( (int)v54 + 4 > v41 )
        {
          v31 = _qdf_mem_malloc(v54 + 4, "dp_process_htt_stat_msg", 2384);
          v30 = (char *)v31;
          if ( !v31 )
          {
            qdf_trace_msg(0x3Fu, 2u, "Alloc failed", v42, v43, v44, v45, v46, v47, v48, v49);
LABEL_108:
            for ( result = v28; ; *result = 0 )
            {
              _qdf_nbuf_free((__int64)result);
              result = v101;
              if ( !v101 )
                break;
              LODWORD(v103) = v103 - 1;
              if ( v101 == v102 )
              {
                v92 = nullptr;
                v102 = nullptr;
              }
              else
              {
                v92 = (_QWORD *)*v101;
              }
              v101 = v92;
            }
            goto LABEL_119;
          }
LABEL_44:
          qdf_mem_copy(v30, v40, v41);
          v30 += v41;
          v29 -= v41;
          continue;
        }
        v52 = v54 + 4;
        v96 = v30;
        v53 = 0;
        v98 = v40;
      }
      if ( (v97 & 1) != 0 )
        dp_htt_stats_copy_tag(v37, v99, (int)v98);
      else
        dp_htt_stats_print_tag(v37, v99, v98);
      if ( (v99 & 0xFFFFFFFE) == 0x3C )
        dp_peer_update_inactive_time(v37, v99, v98);
      v63 = v53;
      v64 = v52;
      if ( (v36 & 0x40) != 0 )
      {
        if ( v99 == 88 )
        {
          qdf_mem_copy((void *)(v37 + 7944), v98, 0x80u);
          qdf_event_set(v37 + 96224, v65);
          if ( (v36 & 0x80) != 0 )
            goto LABEL_80;
          goto LABEL_86;
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Tag mismatch",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "dp_htt_set_pdev_obss_stats");
      }
      if ( (v36 & 0x80) != 0 )
      {
        if ( v99 == 203 )
        {
          if ( (unsigned __int8)v98[1] <= 5u )
          {
            v66 = *(_QWORD *)(v37 + 8);
            v94 = v98[1];
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v95 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v95 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v66 + 18984);
            }
            else
            {
              raw_spin_lock_bh(v66 + 18984);
              *(_QWORD *)(v66 + 18992) |= 1uLL;
            }
            v67 = *(_QWORD *)(v66 + 8 * (v94 & 7) + 12960);
            if ( v67 )
            {
              v68 = *(_DWORD *)(v67 + 43384);
              while ( v68 )
              {
                _X13 = (unsigned int *)(v67 + 43384);
                __asm { PRFM            #0x11, [X13] }
                while ( 1 )
                {
                  v75 = __ldxr(_X13);
                  if ( v75 != v68 )
                    break;
                  if ( !__stlxr(v68 + 1, _X13) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v75 == v68;
                v68 = v75;
                if ( _ZF )
                {
                  _X8 = (unsigned int *)(v67 + 43440);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v83 = __ldxr(_X8);
                  while ( __stxr(v83 + 1, _X8) );
                  v78 = *(_QWORD *)(v66 + 18992);
                  v94 = v67;
                  if ( (v78 & 1) != 0 )
                  {
                    *(_QWORD *)(v66 + 18992) = v78 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(v66 + 18984);
                  }
                  else
                  {
                    raw_spin_unlock(v66 + 18984);
                  }
                  qdf_mem_copy((void *)(v94 + 46204), v98, 0x18u);
                  qdf_event_set(v37 + 96272, v79);
                  dp_vdev_unref_delete(*(_QWORD *)(v37 + 8), v94, 13);
                  goto LABEL_86;
                }
              }
            }
            v80 = *(_QWORD *)(v66 + 18992);
            if ( (v80 & 1) != 0 )
            {
              *(_QWORD *)(v66 + 18992) = v80 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v66 + 18984);
            }
            else
            {
              raw_spin_unlock(v66 + 18984);
            }
          }
          v77 = "%s: unable to get vdev for vdev id %d";
          v76 = v98[1];
        }
        else
        {
LABEL_80:
          v76 = v99;
          v77 = "%s: Tag mismatch, received tag %d";
        }
        qdf_trace_msg(0x45u, 2u, v77, v55, v56, v57, v58, v59, v60, v61, v62, "dp_htt_set_vdev_nss_stats", v76, v94);
      }
LABEL_86:
      v40 = (_DWORD *)((char *)v40 + v64);
      v41 -= v64;
      if ( v63 )
      {
        _qdf_mem_free(v63);
        v31 = 0;
        v30 = nullptr;
      }
      else
      {
        v30 = v96;
        v31 = 0;
      }
      v29 = 0;
    }
    while ( v41 );
    v32 = v99;
    if ( (unsigned int)v104 >= 0x800 )
      LODWORD(v104) = v104 - 2048;
LABEL_100:
    if ( !v35
      && (v36 & 0x20) != 0
      && (*((_BYTE *)v40 + 13) & 8) != 0
      && (unsigned int)qdf_event_set(*(_QWORD *)(a1 + 17584) + 96LL, v19) )
    {
      qdf_trace_msg(
        0x80u,
        2u,
        "%s: %pK:event compl Fail to set event ",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "dp_htt_stats_sysfs_set_event",
        a1);
    }
LABEL_28:
    result = (_QWORD *)_qdf_nbuf_free((__int64)v28);
    v28 = v101;
  }
  while ( v101 );
LABEL_119:
  _ReadStatusReg(SP_EL0);
  return result;
}
