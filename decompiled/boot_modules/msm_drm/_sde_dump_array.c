__int64 __fastcall sde_dump_array(char a1, __int64 a2, char a3, __int64 a4)
{
  __int64 *v7; // x25
  unsigned int v8; // w24
  __int64 v9; // x0
  int v10; // w20
  __int64 is_enabled; // x0
  __int64 v12; // x19
  unsigned int v13; // w8
  unsigned int v20; // w10
  unsigned __int64 v21; // x0
  __int64 v22; // x20
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  char v26; // w24
  __int64 v27; // x28
  int v28; // w19
  char v29; // w22
  int v30; // w23
  __int64 v31; // x0
  __int64 result; // x0
  int v33; // w11
  __int64 v34; // x10
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x13
  int v37; // w14
  int v38; // w12
  int v39; // w13
  unsigned __int64 v40; // x12
  unsigned int v41; // w20
  _UNKNOWN **v42; // x8
  int v43; // w24
  unsigned __int64 v44; // x26
  __int64 v45; // x8
  int v46; // w19
  __int64 (__fastcall *v47)(_QWORD); // x8
  __int64 v48; // x0
  unsigned int v49; // w24
  int v50; // w26
  const char **v51; // x19
  const char *i; // x26
  unsigned __int64 v53; // x8
  __int64 v54; // x22
  __int64 v55; // x28
  __int64 v56; // x2
  unsigned __int64 v57; // x27
  unsigned __int64 v58; // x9
  __int64 v59; // x19
  __int64 v60; // x28
  __int64 v61; // x2
  int v62; // w9
  int v63; // w10
  __int64 v64; // x12
  int *v65; // x11
  int v66; // w13
  int v67; // w14
  int v68; // w15
  int v69; // t1
  __int64 v70; // x9
  __int64 v71; // x8
  int *v72; // x9
  int v73; // w10
  int v74; // t1
  int v75; // w22
  int v76; // w27
  char *v77; // x24
  _UNKNOWN **v78; // x19
  unsigned int v79; // w25
  unsigned __int64 v80; // x23
  unsigned __int64 v81; // x26
  __int64 v82; // [xsp+10h] [xbp-50h]
  unsigned int v83; // [xsp+1Ch] [xbp-44h]
  int v84; // [xsp+20h] [xbp-40h]
  char v85; // [xsp+24h] [xbp-3Ch]
  signed __int64 v86; // [xsp+28h] [xbp-38h]
  int v87; // [xsp+28h] [xbp-38h]
  int v88; // [xsp+34h] [xbp-2Ch]
  unsigned int v89; // [xsp+34h] [xbp-2Ch]
  __int64 v91; // [xsp+38h] [xbp-28h]
  char s[8]; // [xsp+40h] [xbp-20h] BYREF
  __int64 v93; // [xsp+48h] [xbp-18h]
  int v94; // [xsp+50h] [xbp-10h]
  __int64 v95; // [xsp+58h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&unk_2942D0);
  v7 = (__int64 *)qword_2942A8;
  if ( (__int64 *)qword_2942A8 == &qword_2942A8 )
  {
    v8 = 0;
  }
  else
  {
    v8 = 0;
    do
    {
      if ( v7 && v7[14] )
      {
        v34 = v7[2];
        v35 = v7[18];
        if ( (__int64 *)v34 == v7 + 2 )
        {
          v33 = ((v35 + 15) & 0xFFFFFFF0) + 120;
        }
        else
        {
          v33 = 0;
          do
          {
            v40 = *(unsigned int *)(v34 + 64);
            if ( (_DWORD)v40 || (v39 = v7[18], *(_DWORD *)(v34 + 68)) )
            {
              if ( v35 > v40 )
              {
                v36 = *(unsigned int *)(v34 + 68);
                _CF = (unsigned int)v36 >= (unsigned int)v40;
                v37 = v36 - v40;
                v38 = v35 - v40;
                if ( !_CF )
                  v37 = 0;
                if ( v35 < v36 )
                  v39 = v38;
                else
                  v39 = v37;
              }
              else
              {
                v39 = 0;
              }
            }
            v34 = *(_QWORD *)v34;
            v33 += ((v39 + 15) & 0xFFFFFFF0) + 120;
          }
          while ( (__int64 *)v34 != v7 + 2 );
        }
      }
      else
      {
        printk(&unk_23FB8D, "_sde_dbg_get_reg_blk_size");
        v33 = 0;
      }
      v7 = (__int64 *)*v7;
      v8 += v33;
    }
    while ( v7 != &qword_2942A8 );
  }
  v9 = qword_2942B8;
  if ( !qword_2942B8 )
  {
    v9 = vzalloc_noprof(v8);
    qword_2942B8 = v9;
  }
  v10 = dword_2945D8;
  qword_2942C0 = v9;
  is_enabled = sde_evtlog_is_enabled(sde_dbg_base, 0xFFFFFFFFLL);
  if ( (is_enabled & 1) != 0 )
    is_enabled = (__int64)sde_evtlog_dump_all((const char *)sde_dbg_base);
  if ( v10 == 2
    || (v12 = qword_2942C8, is_enabled = _pm_runtime_resume(qword_2942C8, 4), (is_enabled & 0x80000000) == 0) )
  {
    v84 = v10;
    v85 = a1;
    v82 = a2;
    v83 = dword_29437C;
    v88 = HIBYTE(word_294380);
    v21 = ktime_get(is_enabled);
    v86 = v21;
    if ( !a4
      || (v21 = list_sort(0, &qword_2942A8, sde_dump_blk_phys_addr_cmp),
          v22 = qword_2942A8,
          (__int64 *)qword_2942A8 == &qword_2942A8) )
    {
LABEL_20:
      v23 = ktime_get(v21);
      v24 = dev_info(
              qword_2942C8,
              "ctx:%d, reg-dump logging time start_us:%llu, end_us:%llu , duration_us:%llu\n",
              dword_2945D8,
              v86 / 1000,
              v23 / 1000,
              (v23 - v86) / 1000);
      v25 = ktime_get(v24);
      v26 = v83;
      v27 = v25;
      v28 = v88 & (v83 >> 3);
      v87 = v28;
      if ( v28 == 1 )
      {
        drm_printf(qword_2945A8, "---------------------------------\n");
        drm_printf(qword_2945A8, "[dbgbus_%s]\n", "sde");
        v28 = 1;
        v25 = drm_printf(qword_2945A8, "---------------------------------\n");
      }
      v30 = v84;
      v29 = v85;
      if ( (a4 & 0x1000) != 0 )
      {
        v25 = sde_dbg_dump_sde_dbg_bus(&qword_294388, (unsigned int)dword_29437C);
        if ( !v28 )
        {
LABEL_24:
          if ( (a4 & 0x4000) == 0 )
            goto LABEL_25;
          goto LABEL_60;
        }
      }
      else if ( !v28 )
      {
        goto LABEL_24;
      }
      drm_printf(qword_2945A8, "---------------------------------\n");
      drm_printf(qword_2945A8, "[dbgbus_%s]\n", "lutdma");
      v28 = v88 & (v83 >> 3);
      v25 = drm_printf(qword_2945A8, "---------------------------------\n");
      if ( (a4 & 0x4000) == 0 )
      {
LABEL_25:
        if ( !v28 )
          goto LABEL_26;
        goto LABEL_61;
      }
LABEL_60:
      v25 = sde_dbg_dump_sde_dbg_bus(&qword_2944E8, (unsigned int)dword_29437C);
      if ( !v28 )
      {
LABEL_26:
        if ( (a4 & 0x2000) == 0 )
          goto LABEL_27;
        goto LABEL_62;
      }
LABEL_61:
      drm_printf(qword_2945A8, "---------------------------------\n");
      drm_printf(qword_2945A8, "[dbgbus_%s]\n", "rsc");
      v28 = v88 & (v83 >> 3);
      v25 = drm_printf(qword_2945A8, "---------------------------------\n");
      if ( (a4 & 0x2000) == 0 )
      {
LABEL_27:
        if ( !v28 )
          goto LABEL_28;
        goto LABEL_63;
      }
LABEL_62:
      v25 = sde_dbg_dump_sde_dbg_bus(&qword_294490, (unsigned int)dword_29437C);
      if ( !v28 )
      {
LABEL_28:
        if ( (a4 & 0x8000) == 0 )
          goto LABEL_29;
        goto LABEL_64;
      }
LABEL_63:
      drm_printf(qword_2945A8, "---------------------------------\n");
      drm_printf(qword_2945A8, "[dbgbus_%s]\n", "vbif_rt");
      v28 = v88 & (v83 >> 3);
      v25 = drm_printf(qword_2945A8, "---------------------------------\n");
      if ( (a4 & 0x8000) == 0 )
      {
LABEL_29:
        if ( !v28 )
          goto LABEL_30;
        goto LABEL_65;
      }
LABEL_64:
      v25 = sde_dbg_dump_sde_dbg_bus(&qword_2943E0, (unsigned int)dword_29437C);
      if ( !v28 )
      {
LABEL_30:
        if ( (a4 & 0x10000) == 0 )
          goto LABEL_31;
        goto LABEL_66;
      }
LABEL_65:
      drm_printf(qword_2945A8, "---------------------------------\n");
      drm_printf(qword_2945A8, "[dbgbus_%s]\n", "dsi");
      v28 = v88 & (v83 >> 3);
      v25 = drm_printf(qword_2945A8, "---------------------------------\n");
      if ( (a4 & 0x10000) == 0 )
      {
LABEL_31:
        if ( !v28 )
          goto LABEL_32;
        goto LABEL_128;
      }
LABEL_66:
      v91 = qword_294460;
      if ( !qword_294460 )
        goto LABEL_127;
      v41 = dword_294440;
      if ( !dword_294440 )
        goto LABEL_127;
      v89 = dword_29437C;
      v42 = (_UNKNOWN **)sde_dbg_dsi_list;
      if ( sde_dbg_dsi_list == (_UNKNOWN *)&sde_dbg_dsi_list )
        goto LABEL_127;
      v43 = 0;
      LODWORD(v44) = 0;
      v94 = 0;
      *(_QWORD *)s = 0;
      v93 = 0;
      do
      {
        v42 = (_UNKNOWN **)*v42;
        v44 = (unsigned int)(v44 + 1);
        v43 += 16;
      }
      while ( v42 != &sde_dbg_dsi_list );
      if ( (unsigned int)dword_294440 >= 2 )
      {
        v45 = dword_294440 & 0xFFFFFFFE;
        v62 = 0;
        v63 = 0;
        v64 = v45;
        v65 = (int *)(qword_294460 + 52);
        do
        {
          v66 = *(v65 - 10);
          v67 = *(v65 - 8);
          v64 -= 2;
          v68 = *(v65 - 2);
          v69 = *v65;
          v65 += 16;
          v62 += v67 * v66;
          v63 += v69 * v68;
        }
        while ( v64 );
        v46 = v63 + v62;
        if ( v45 == dword_294440 )
          goto LABEL_120;
      }
      else
      {
        v45 = 0;
        v46 = 0;
      }
      v70 = qword_294460 + 32 * v45;
      v71 = (unsigned int)dword_294440 - v45;
      v72 = (int *)(v70 + 20);
      do
      {
        v73 = *(v72 - 2);
        v74 = *v72;
        v72 += 8;
        --v71;
        v46 += v74 * v73;
      }
      while ( v71 );
LABEL_120:
      v75 = dword_29437C & 5;
      snprintf(s, 0x14u, "%s-debugbus", (const char *)qword_294438);
      if ( (v89 & 5) != 0 )
        dev_err(qword_2942C8, "======== %s %s dump =========\n", "start", s);
      v76 = v46 * v43;
      mutex_lock(&sde_dbg_dsi_mutex);
      v77 = (char *)qword_294448;
      if ( (v89 & 0xA) != 0 && !qword_294448 )
      {
        v77 = (char *)vzalloc_noprof(v76);
        qword_294448 = (__int64)v77;
        dword_294454 = v76 >> 2;
      }
      v78 = (_UNKNOWN **)sde_dbg_dsi_list;
      if ( sde_dbg_dsi_list != (_UNKNOWN *)&sde_dbg_dsi_list )
      {
        v79 = 0;
        v80 = v76 / (4 * v44);
        v81 = v76 / v44;
        do
        {
          if ( v75 )
            dev_err(qword_2942C8, "%s: start_addr:0x%pK len:0x%zx offset=0x%x\n", (const char *)*(v78 - 2), v77, v81, 0);
          sde_dbg_dump_bus_entry(&qword_294438, v91, v41, *(v78 - 1), v77, v89, v79);
          if ( v77 )
            v77 += 4 * v80;
          v78 = (_UNKNOWN **)*v78;
          ++v79;
        }
        while ( v78 != &sde_dbg_dsi_list );
      }
      v25 = mutex_unlock(&sde_dbg_dsi_mutex);
      v26 = v83;
      v28 = v87;
      v30 = v84;
      v29 = v85;
LABEL_127:
      if ( !v28 )
      {
LABEL_32:
        if ( (a4 & 0x2000000) == 0 )
        {
LABEL_34:
          v31 = ktime_get(v25);
          dev_info(
            qword_2942C8,
            "debug-bus logging time start_us:%llu, end_us:%llu , duration_us:%llu\n",
            v27 / 1000,
            v31 / 1000,
            (v31 - v27) / 1000);
          if ( v30 != 2 )
            _pm_runtime_idle(qword_2942C8, 4);
          if ( (v29 & 1) != 0 && (v26 & 8) == 0 && dword_294350 )
            panic(v82);
          result = mutex_unlock(&unk_2942D0);
          goto LABEL_74;
        }
LABEL_33:
        v25 = sde_dbg_dump_sde_dbg_bus(&qword_294540, (unsigned int)dword_29437C);
        goto LABEL_34;
      }
LABEL_128:
      drm_printf(qword_2945A8, "---------------------------------\n");
      drm_printf(qword_2945A8, "[dbgbus_%s]\n", "dp");
      v25 = drm_printf(qword_2945A8, "---------------------------------\n");
      if ( (a4 & 0x2000000) == 0 )
        goto LABEL_34;
      goto LABEL_33;
    }
    while ( 1 )
    {
      if ( (*(_QWORD *)(v22 + 192) & a4) != 0 )
      {
        v21 = strnlen((const char *)(v22 + 32), 0x50u);
        if ( v21 >= 0x51 )
        {
          _fortify_panic(2, 80, v21 + 1);
LABEL_137:
          _fortify_panic(4, 80, 81);
        }
        if ( v21 )
        {
          if ( v21 == 80 )
            goto LABEL_137;
          if ( (a3 & 1) == 0
            || (v21 = strcmp((const char *)(v22 + 32), "vbif_rt"), (_DWORD)v21)
            && (v21 = strcmp((const char *)(v22 + 32), "vbif_nrt"), (_DWORD)v21)
            && (v21 = strcmp((const char *)(v22 + 32), "wb_2"), (_DWORD)v21) )
          {
            if ( v22 )
            {
              v49 = dword_29437C;
              if ( *(_QWORD *)(v22 + 112) || *(_QWORD *)(v22 + 176) )
              {
                v50 = dword_29437C & 5;
                if ( (dword_29437C & 5) != 0 )
                {
                  dev_err(qword_2942C8, "======== %s %s dump =========\n", "start", (const char *)(v22 + 32));
                  if ( (v49 & 8) != 0 )
                    goto LABEL_94;
                }
                else if ( (dword_29437C & 8) != 0 )
                {
LABEL_94:
                  if ( HIBYTE(word_294380) == 1 )
                    drm_printf(
                      qword_2945A8,
                      "%s:=========%s DUMP=========\n",
                      "_sde_dump_reg_by_ranges",
                      (const char *)(v22 + 32));
                }
                v47 = *(__int64 (__fastcall **)(_QWORD))(v22 + 176);
                if ( v47 )
                {
                  v48 = *(_QWORD *)(v22 + 184);
                  if ( *((_DWORD *)v47 - 1) != 251140989 )
                    __break(0x8228u);
                  v21 = v47(v48);
                }
                else
                {
                  v51 = (const char **)(v22 + 16);
                  if ( *(_QWORD *)(v22 + 16) == v22 + 16 )
                  {
                    v59 = *(_QWORD *)(v22 + 112);
                    if ( v50 )
                    {
                      dev_err(
                        qword_2942C8,
                        "%s: start_addr:0x%pK len:0x%zx offset=0x%x\n",
                        "base",
                        *(const void **)(v22 + 112),
                        *(_QWORD *)(v22 + 144),
                        0);
                      v59 = *(_QWORD *)(v22 + 112);
                    }
                    v60 = *(_QWORD *)(v22 + 144);
                    scnprintf(qword_2942C0, 80, (const char *)(v22 + 32));
                    v61 = *(_QWORD *)(v22 + 112);
                    qword_2942C0 += 120;
                    v21 = sde_dump_reg(v22 + 32, v49, v61, v59, v60, v22 + 168);
                  }
                  else
                  {
                    v21 = list_sort(0, v22 + 16, sde_dump_reg_range_cmp);
                    for ( i = *v51; i != (const char *)v51; i = *(const char **)i )
                    {
                      v57 = *((unsigned int *)i + 16);
                      v53 = *(_QWORD *)(v22 + 144);
                      if ( *((_QWORD *)i + 8) )
                      {
                        if ( v53 <= v57 )
                        {
                          LODWORD(v53) = 0;
                        }
                        else
                        {
                          v58 = *((unsigned int *)i + 17);
                          if ( v53 >= v58 )
                          {
                            LODWORD(v53) = v58 - v57;
                            if ( (unsigned int)v58 < (unsigned int)v57 )
                              LODWORD(v53) = 0;
                          }
                          else
                          {
                            LODWORD(v53) = v53 - v57;
                          }
                        }
                      }
                      else
                      {
                        v57 = 0;
                      }
                      v54 = *(_QWORD *)(v22 + 112);
                      v55 = (unsigned int)v53;
                      scnprintf(qword_2942C0, 80, (const char *)(v22 + 32));
                      qword_2942C0 += 80;
                      scnprintf(qword_2942C0, 40, i + 24);
                      v56 = *(_QWORD *)(v22 + 112);
                      qword_2942C0 += 40;
                      v21 = sde_dump_reg(i + 24, v49, v56, v54 + v57, v55, i + 16);
                    }
                  }
                }
                goto LABEL_80;
              }
            }
            v21 = printk(&unk_23FB8D, "_sde_dump_reg_by_ranges");
          }
        }
      }
LABEL_80:
      v22 = *(_QWORD *)v22;
      if ( (__int64 *)v22 == &qword_2942A8 )
        goto LABEL_20;
    }
  }
  v13 = *(_DWORD *)(v12 + 480);
  do
  {
    if ( !v13 )
      break;
    _X12 = (unsigned int *)(v12 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v20 = __ldxr(_X12);
      if ( v20 != v13 )
        break;
      if ( !__stlxr(v13 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v20 == v13;
    v13 = v20;
  }
  while ( !_ZF );
  result = printk(&unk_27789C, "_sde_dump_array");
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
