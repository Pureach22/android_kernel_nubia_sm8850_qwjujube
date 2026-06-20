__int64 __fastcall aw_cali_misc_read(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 *a4)
{
  _QWORD *v6; // x21
  __int64 *v7; // x8
  __int64 v8; // x1
  __int64 v9; // x0
  __int64 v10; // x22
  unsigned __int64 v11; // x26
  __int64 v12; // x24
  int v13; // w0
  int devs_re_range; // w0
  unsigned __int64 v15; // x25
  __int64 v16; // x26
  _DWORD *v17; // x27
  int v18; // w0
  unsigned __int64 v19; // x26
  int v20; // w0
  __int64 (__fastcall *v21)(char *, __int64); // x8
  unsigned int v22; // w0
  int v23; // w0
  unsigned __int64 v24; // x25
  _DWORD *v25; // x27
  int v26; // w0
  unsigned __int64 v27; // x27
  int v28; // w0
  int v29; // w0
  __int64 (__fastcall *v30)(_QWORD); // x8
  int v31; // w0
  unsigned __int64 v32; // x26
  int v33; // w0
  unsigned __int64 v34; // x26
  int v35; // w0
  unsigned __int64 v36; // x26
  int v37; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v39; // x9
  __int64 v40; // x0
  unsigned __int64 v41; // x9
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v50; // x9
  __int64 v51; // x8
  __int64 *v53; // x8
  __int64 v54; // x1
  void *v55; // x0
  __int64 *v56; // x8
  __int64 v57; // x1
  __int64 *v58; // x8
  __int64 v59; // x1
  void *v60; // x0
  __int64 *v61; // x8
  __int64 *v62; // x8
  __int64 *v63; // x8
  __int64 *v64; // x8
  __int64 *v65; // x8
  __int64 *v66; // x8
  __int64 *v67; // x8
  __int64 *v68; // x8
  __int64 *v69; // x8
  __int64 *v70; // x8
  __int64 *v71; // x8
  __int64 v72; // x1
  unsigned __int64 v73; // [xsp+0h] [xbp-1E0h]
  _QWORD v74[8]; // [xsp+10h] [xbp-1D0h] BYREF
  _QWORD v75[8]; // [xsp+50h] [xbp-190h] BYREF
  _QWORD v76[8]; // [xsp+90h] [xbp-150h] BYREF
  char s[8]; // [xsp+D0h] [xbp-110h] BYREF
  __int64 v78; // [xsp+D8h] [xbp-108h]
  __int64 v79; // [xsp+E0h] [xbp-100h]
  __int64 v80; // [xsp+E8h] [xbp-F8h]
  __int64 v81; // [xsp+F0h] [xbp-F0h]
  __int64 v82; // [xsp+F8h] [xbp-E8h]
  __int64 v83; // [xsp+100h] [xbp-E0h]
  __int64 v84; // [xsp+108h] [xbp-D8h]
  __int64 v85; // [xsp+110h] [xbp-D0h]
  __int64 v86; // [xsp+118h] [xbp-C8h]
  __int64 v87; // [xsp+120h] [xbp-C0h]
  __int64 v88; // [xsp+128h] [xbp-B8h]
  __int64 v89; // [xsp+130h] [xbp-B0h]
  __int64 v90; // [xsp+138h] [xbp-A8h]
  __int64 v91; // [xsp+140h] [xbp-A0h]
  __int64 v92; // [xsp+148h] [xbp-98h]
  __int64 v93; // [xsp+150h] [xbp-90h]
  __int64 v94; // [xsp+158h] [xbp-88h]
  __int64 v95; // [xsp+160h] [xbp-80h]
  __int64 v96; // [xsp+168h] [xbp-78h]
  __int64 v97; // [xsp+170h] [xbp-70h]
  __int64 v98; // [xsp+178h] [xbp-68h]
  __int64 v99; // [xsp+180h] [xbp-60h]
  __int64 v100; // [xsp+188h] [xbp-58h]
  __int64 v101; // [xsp+190h] [xbp-50h]
  __int64 v102; // [xsp+198h] [xbp-48h]
  __int64 v103; // [xsp+1A0h] [xbp-40h]
  __int64 v104; // [xsp+1A8h] [xbp-38h]
  __int64 v105; // [xsp+1B0h] [xbp-30h]
  __int64 v106; // [xsp+1B8h] [xbp-28h]
  __int64 v107; // [xsp+1C0h] [xbp-20h]
  __int64 v108; // [xsp+1C8h] [xbp-18h]
  __int64 v109; // [xsp+1D0h] [xbp-10h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a1 + 32);
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v7 = (__int64 *)v6[14];
  v89 = 0;
  v90 = 0;
  v87 = 0;
  v88 = 0;
  v8 = v7[14];
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  *(_QWORD *)s = 0;
  v78 = 0;
  memset(v76, 0, sizeof(v76));
  memset(v75, 0, sizeof(v75));
  memset(v74, 0, sizeof(v74));
  if ( !v8 )
    v8 = *v7;
  v9 = printk(&unk_26EB3, v8, "aw_cali_misc_read");
  if ( *a4 )
  {
    v10 = 0;
    *a4 = 0;
    goto LABEL_87;
  }
  if ( g_msic_wr_flag <= 9 )
  {
    if ( g_msic_wr_flag > 6 )
    {
      switch ( g_msic_wr_flag )
      {
        case 7:
          LODWORD(v10) = aw_cali_svc_get_devs_cali_f0((__int64)v6, (__int64)v76, 8u);
          if ( (int)v10 < 1 )
          {
            v65 = (__int64 *)v6[14];
            v59 = v65[14];
            if ( !v59 )
              v59 = *v65;
            v60 = &unk_243AB;
            goto LABEL_125;
          }
          v34 = 0;
          LODWORD(v12) = 0;
          while ( (unsigned int)v12 <= 0x100 && v34 <= 7 )
          {
            v35 = snprintf(
                    &s[(unsigned int)v12],
                    256LL - (unsigned int)v12,
                    "%s:%d ",
                    ch_name[v34],
                    *((_DWORD *)v76 + v34));
            ++v34;
            v12 = (unsigned int)(v35 + v12);
            if ( (unsigned int)v10 == v34 )
              goto LABEL_76;
          }
          break;
        case 8:
          LODWORD(v10) = aw_cali_svc_get_devs_f0((__int64)v6, (__int64)v76, 8u);
          if ( (int)v10 < 1 )
          {
            v63 = (__int64 *)v6[14];
            v59 = v63[14];
            if ( !v59 )
              v59 = *v63;
            v60 = &unk_27431;
            goto LABEL_125;
          }
          v32 = 0;
          LODWORD(v12) = 0;
          while ( (unsigned int)v12 <= 0x100 && v32 <= 7 )
          {
            v33 = snprintf(
                    &s[(unsigned int)v12],
                    256LL - (unsigned int)v12,
                    "%s:%d ",
                    ch_name[v32],
                    *((_DWORD *)v76 + v32));
            ++v32;
            v12 = (unsigned int)(v33 + v12);
            if ( (unsigned int)v10 == v32 )
              goto LABEL_76;
          }
          break;
        case 9:
          LODWORD(v10) = aw_cali_svc_get_devs_te((__int64)v6, (__int64)v76, 8u);
          if ( (int)v10 >= 1 )
          {
            v11 = 0;
            LODWORD(v12) = 0;
            while ( (unsigned int)v12 <= 0x100 && v11 <= 7 )
            {
              v13 = snprintf(
                      &s[(unsigned int)v12],
                      256LL - (unsigned int)v12,
                      "%s:%d ",
                      ch_name[v11],
                      *((_DWORD *)v76 + v11));
              ++v11;
              v12 = (unsigned int)(v13 + v12);
              if ( (unsigned int)v10 == v11 )
                goto LABEL_76;
            }
            break;
          }
          v68 = (__int64 *)v6[14];
          v59 = v68[14];
          if ( !v59 )
            v59 = *v68;
          v60 = &unk_235A2;
LABEL_125:
          printk(v60, v59, "aw_cali_misc_read");
          v10 = (int)v10;
          goto LABEL_87;
        default:
          goto LABEL_92;
      }
LABEL_134:
      __break(0x5512u);
    }
    if ( g_msic_wr_flag != 5 )
    {
      if ( g_msic_wr_flag == 6 )
      {
        LODWORD(v10) = aw_cali_svc_get_devs_r0((__int64)v6, (__int64)v76, 8u);
        if ( (int)v10 < 1 )
        {
          v67 = (__int64 *)v6[14];
          v59 = v67[14];
          if ( !v59 )
            v59 = *v67;
          v60 = &unk_246EB;
          goto LABEL_125;
        }
        v19 = 0;
        LODWORD(v12) = 0;
        while ( (unsigned int)v12 <= 0x100 && v19 <= 7 )
        {
          v20 = snprintf(
                  &s[(unsigned int)v12],
                  256LL - (unsigned int)v12,
                  "%s:%d mOhms ",
                  ch_name[v19],
                  *((_DWORD *)v76 + v19));
          ++v19;
          v12 = (unsigned int)(v20 + v12);
          if ( (unsigned int)v10 == v19 )
            goto LABEL_76;
        }
        goto LABEL_134;
      }
      if ( !g_msic_wr_flag )
      {
        v53 = (__int64 *)v6[14];
        v54 = v53[14];
        if ( !v54 )
          v54 = *v53;
        v55 = &unk_2404C;
        goto LABEL_129;
      }
      goto LABEL_92;
    }
    LODWORD(v10) = aw_cali_svc_get_devs_cali_re((__int64)v6, (__int64)v76, 8u);
    if ( (int)v10 < 1 )
    {
      v69 = (__int64 *)v6[14];
      v59 = v69[14];
      if ( !v59 )
        v59 = *v69;
      v60 = &unk_2357C;
      goto LABEL_125;
    }
    v36 = 0;
    LODWORD(v12) = 0;
    do
    {
      if ( (unsigned int)v12 > 0x100 || v36 >= 8 )
        goto LABEL_134;
      v37 = snprintf(
              &s[(unsigned int)v12],
              256LL - (unsigned int)v12,
              "%s:%d mOhms ",
              ch_name[v36],
              *((_DWORD *)v76 + v36));
      ++v36;
      v12 = (unsigned int)(v37 + v12);
    }
    while ( (unsigned int)v10 != v36 );
LABEL_76:
    if ( (unsigned int)v12 > 0x100 )
      goto LABEL_134;
    v29 = snprintf(&s[v12], 256 - v12, "\n");
    goto LABEL_78;
  }
  if ( g_msic_wr_flag <= 12 )
  {
    if ( g_msic_wr_flag == 10 )
    {
      LODWORD(v10) = aw_cali_svc_get_devs_st((__int64)v6, (__int64)v76, 8u);
      if ( (int)v10 < 1 )
      {
        v58 = (__int64 *)v6[14];
        v59 = v58[14];
        if ( !v59 )
          v59 = *v58;
        v60 = &unk_27468;
        goto LABEL_125;
      }
      v73 = a2;
      v24 = 0;
      LODWORD(v12) = 0;
      v25 = (_DWORD *)v76 + 1;
      do
      {
        if ( (unsigned int)v12 > 0x100 || v24 > 7 )
          goto LABEL_134;
        v26 = snprintf(
                &s[(unsigned int)v12],
                256LL - (unsigned int)v12,
                "%s:R0 %d mOhms Te %d ",
                ch_name[v24++],
                *(v25 - 1),
                *v25);
        v12 = (unsigned int)(v26 + v12);
        v25 += 2;
      }
      while ( (unsigned int)v10 != v24 );
LABEL_53:
      if ( (unsigned int)v12 > 0x100 )
        goto LABEL_134;
      v29 = snprintf(&s[v12], 256 - v12, "\n");
      a2 = v73;
LABEL_78:
      v23 = v29 + v12;
      goto LABEL_79;
    }
    if ( g_msic_wr_flag != 12 )
      goto LABEL_92;
    v21 = (__int64 (__fastcall *)(char *, __int64))v6[142];
    if ( !v21 )
    {
      v64 = (__int64 *)v6[14];
      v54 = v64[14];
      if ( !v54 )
        v54 = *v64;
      v55 = &unk_2789C;
      goto LABEL_129;
    }
    if ( *((_DWORD *)v21 - 1) != -1328559663 )
      __break(0x8228u);
    v22 = v21(s, 256);
    if ( (v22 & 0x80000000) != 0 )
    {
      v70 = (__int64 *)v6[14];
      v54 = v70[14];
      if ( !v54 )
        v54 = *v70;
      v55 = &unk_2704F;
      goto LABEL_129;
    }
    if ( v22 > 0x100 )
      goto LABEL_134;
    v23 = snprintf(&s[v22], 256LL - v22, "\n") + v22;
  }
  else
  {
    if ( g_msic_wr_flag != 13 )
    {
      v73 = a2;
      if ( g_msic_wr_flag == 15 )
      {
        LODWORD(v10) = aw_cali_svc_get_devs_cali_f0_q((__int64)v6, (__int64)v76, (__int64)v75, 8u);
        if ( (int)v10 < 1 )
        {
          v61 = (__int64 *)v6[14];
          v59 = v61[14];
          if ( !v59 )
            v59 = *v61;
          v60 = &unk_278C3;
          goto LABEL_125;
        }
        v27 = 0;
        LODWORD(v12) = 0;
        while ( (unsigned int)v12 <= 0x100 && v27 <= 7 )
        {
          v28 = snprintf(
                  &s[(unsigned int)v12],
                  256LL - (unsigned int)v12,
                  "%s:f0:%d q:%d",
                  ch_name[v27],
                  *((_DWORD *)v76 + v27),
                  *((_DWORD *)v75 + v27));
          ++v27;
          v12 = (unsigned int)(v28 + v12);
          if ( (unsigned int)v10 == v27 )
            goto LABEL_53;
        }
        goto LABEL_134;
      }
      if ( g_msic_wr_flag == 16 )
      {
        devs_re_range = aw_cali_svc_get_devs_re_range((__int64)v6, (__int64)v74);
        if ( devs_re_range >= 1 )
        {
          v15 = 0;
          LODWORD(v12) = 0;
          v16 = (unsigned int)devs_re_range;
          v17 = (_DWORD *)v74 + 1;
          while ( (unsigned int)v12 <= 0x100 && v15 <= 7 )
          {
            v18 = snprintf(
                    &s[(unsigned int)v12],
                    256LL - (unsigned int)v12,
                    "%s:re_min:%d re_max:%d ",
                    ch_name[v15++],
                    *(v17 - 1),
                    *v17);
            v12 = (unsigned int)(v18 + v12);
            v17 += 2;
            if ( v16 == v15 )
              goto LABEL_53;
          }
          goto LABEL_134;
        }
        v66 = (__int64 *)v6[14];
        v54 = v66[14];
        if ( !v54 )
          v54 = *v66;
        v55 = &unk_26CE5;
LABEL_129:
        printk(v55, v54, "aw_cali_misc_read");
        v10 = -22;
        goto LABEL_87;
      }
LABEL_92:
      v56 = (__int64 *)v6[14];
      v57 = v56[14];
      if ( !v57 )
        v57 = *v56;
      printk(&unk_26D1A, v57, "aw_cali_misc_read");
      g_msic_wr_flag = 0;
      v10 = -22;
      goto LABEL_87;
    }
    v30 = (__int64 (__fastcall *)(_QWORD))v6[143];
    if ( !v30 )
    {
      v62 = (__int64 *)v6[14];
      v54 = v62[14];
      if ( !v54 )
        v54 = *v62;
      v55 = &unk_267C6;
      goto LABEL_129;
    }
    if ( *((_DWORD *)v30 - 1) != 1874538549 )
      __break(0x8228u);
    v31 = v30(v9);
    v23 = snprintf(s, 0x100u, "dev_num:%d\n", v31);
  }
LABEL_79:
  v10 = v23;
  if ( (unsigned int)v23 >= 0x101 )
  {
    _copy_overflow(256, v23);
  }
  else
  {
    _check_object_size(s, v23, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v39 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v39 = a2 & ((__int64)(a2 << 8) >> 8);
    v40 = v10;
    if ( 0x8000000000LL - v10 >= v39 )
    {
      v41 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v47 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v47 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v47);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v41);
      v40 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, s, v10);
      v48 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v50 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v50 - 4096);
      _WriteStatusReg(TTBR1_EL1, v50);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v48);
    }
    if ( !v40 )
    {
      v51 = *a4;
      g_msic_wr_flag = 0;
      *a4 = v51 + v10;
      goto LABEL_87;
    }
  }
  v71 = (__int64 *)v6[14];
  v72 = v71[14];
  if ( !v72 )
    v72 = *v71;
  printk(&unk_278E6, v72, "aw_cali_misc_read");
  g_msic_wr_flag = 0;
  v10 = -14;
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return v10;
}
