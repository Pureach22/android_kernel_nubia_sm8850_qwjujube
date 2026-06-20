void gsi_handle_irq()
{
  int v0; // w27
  unsigned int v1; // w19
  unsigned int (*v2)(void); // x8
  __int64 v3; // x0
  unsigned int (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  unsigned __int64 v6; // x21
  int v7; // w24
  __int64 v8; // x20
  long double v9; // q0
  unsigned __int64 StatusReg; // x9
  __int64 v11; // x8
  int v12; // w11
  int v13; // w9
  int v14; // w9
  void (__fastcall *v15)(_QWORD); // x8
  void (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x20
  int v18; // w24
  int v19; // w25
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  unsigned __int64 v23; // x26
  int v24; // w20
  __int64 v25; // x8
  unsigned int *v26; // x24
  __int64 v27; // x4
  __int64 v28; // x25
  __int64 v29; // x2
  _DWORD *v30; // x8
  __int64 v31; // x1
  unsigned __int64 v32; // x23
  __int64 v33; // x8
  int v34; // w28
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v38; // x20
  __int64 v39; // x23
  unsigned __int64 v40; // x4
  unsigned int *v41; // x24
  __int64 v42; // x4
  __int64 v43; // x25
  __int64 v44; // x26
  __int64 v45; // x2
  _DWORD *v46; // x8
  __int64 v47; // x1
  __int64 v48; // x8
  unsigned int v49; // w24
  int v50; // w28
  unsigned int v51; // w25
  long double v52; // q0
  __int64 v53; // x8
  __int64 v54; // x9
  void (__fastcall *v55)(_QWORD, long double); // x8
  __int64 *v56; // x0
  int v57; // w24
  int v58; // w20
  unsigned int j; // w25
  unsigned int v60; // w26
  int k; // w21
  unsigned int v62; // w24
  int i; // w25
  int v64; // w24
  int v65; // w20
  unsigned int n; // w25
  unsigned int v67; // w26
  int ii; // w21
  unsigned int v69; // w24
  int m; // w25
  void (__fastcall *v71)(_QWORD); // x8
  __int64 v72; // x9
  __int64 v73; // x10
  __int64 v74; // x20
  int v75; // w8
  __int64 v76; // x9
  __int64 v77; // x10
  __int64 v78; // x20
  int v79; // w8
  __int64 v80; // x9
  bool v81; // zf
  unsigned int v82; // w8
  int bit_map_array_size; // w0
  __int64 v84; // x20
  unsigned int v85; // w8
  unsigned int v86; // w0
  __int64 v87; // x20
  __int64 v88; // x25
  unsigned int reg_nk; // w21
  unsigned __int64 v90; // x20
  __int64 v91; // x23
  __int64 v92; // x24
  __int64 v93; // x26
  unsigned int v94; // w21
  unsigned __int64 v95; // x20
  __int64 v96; // x23
  __int64 v97; // x25
  __int64 v98; // x24
  __int64 v99; // x21
  __int64 v100; // x26
  unsigned int v101; // w23
  __int64 v102; // x27
  __int64 v103; // x25
  __int64 v104; // x24
  __int64 v105; // x21
  unsigned int v106; // w23
  __int64 v107; // x26
  __int64 v108; // x27
  long double v109; // q0
  __int64 v110; // [xsp+8h] [xbp-98h]
  __int64 v111; // [xsp+10h] [xbp-90h]
  __int64 v112; // [xsp+10h] [xbp-90h]
  __int64 v113; // [xsp+18h] [xbp-88h] BYREF
  __int64 v114; // [xsp+20h] [xbp-80h]
  __int64 v115; // [xsp+28h] [xbp-78h]
  int v116; // [xsp+30h] [xbp-70h]
  int v117; // [xsp+34h] [xbp-6Ch] BYREF
  __int64 v118; // [xsp+38h] [xbp-68h] BYREF
  __int64 v119; // [xsp+40h] [xbp-60h]
  __int64 v120; // [xsp+48h] [xbp-58h] BYREF
  __int64 v121; // [xsp+50h] [xbp-50h]
  __int64 v122; // [xsp+58h] [xbp-48h]
  __int64 v123; // [xsp+60h] [xbp-40h]
  __int64 v124; // [xsp+68h] [xbp-38h] BYREF
  __int64 v125; // [xsp+70h] [xbp-30h]
  __int64 v126; // [xsp+78h] [xbp-28h] BYREF
  __int64 v127; // [xsp+80h] [xbp-20h]
  __int64 v128; // [xsp+88h] [xbp-18h] BYREF
  __int64 v129; // [xsp+90h] [xbp-10h]
  __int64 v130; // [xsp+98h] [xbp-8h]

  v130 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v113 = 0;
  v1 = *(_DWORD *)(gsi_ctx + 20);
  v2 = *(unsigned int (**)(void))(gsi_ctx + 136);
  v116 = 0;
  v114 = 0;
  v115 = 0;
  if ( *((_DWORD *)v2 - 1) != 1874538549 )
    __break(0x8228u);
  if ( !v2() )
  {
LABEL_201:
    _ReadStatusReg(SP_EL0);
    return;
  }
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))gsihal_read_reg_n_fields)(6, v1, &v113);
    if ( !(_DWORD)v5 )
      goto LABEL_201;
    LODWORD(v6) = 29264;
    v7 = v5;
    v8 = *(unsigned int *)(gsi_ctx + 29264);
    v3 = sched_clock(v5);
    if ( (unsigned int)v8 >= 0x14 )
      __break(0x5512u);
    *(_QWORD *)(gsi_ctx + 24 * v8 + 28784) = v3;
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    *(_QWORD *)(gsi_ctx + 24 * v8 + 28792) = StatusReg;
    *(_DWORD *)(gsi_ctx + 24 * v8 + 28800) = v7;
    v11 = gsi_ctx;
    v12 = v116;
    v13 = *(_DWORD *)(gsi_ctx + 29264);
    if ( v13 == 19 )
      v14 = 0;
    else
      v14 = v13 + 1;
    *(_DWORD *)(gsi_ctx + 29264) = v14;
    if ( v12 )
    {
      v122 = 0;
      v123 = 0;
      v82 = *(_DWORD *)(v11 + 16);
      v120 = 0;
      v121 = 0;
      if ( v82 < 0xA )
      {
        reg_nk = gsihal_read_reg_nk(7, v1, 0);
        gsihal_write_reg_nk(9, v1, 0);
        v90 = 0;
        v91 = 16360;
        v92 = 448;
        while ( 1 )
        {
          if ( ((reg_nk >> v90) & 1) != 0 )
          {
            v93 = gsi_ctx;
            if ( v90 >= *(unsigned int *)(gsi_ctx + 28608) )
            {
              dev_err(
                *(_QWORD *)(gsi_ctx + 8),
                "%s:%d invalid channel %d\n",
                "gsi_handle_ch_ctrl",
                378,
                (unsigned int)v90);
              goto LABEL_201;
            }
            gsihal_read_reg_nk_fields(8, v1, (unsigned int)v90, &v120);
            *(_DWORD *)(v93 + v92 - 144) = HIDWORD(v120);
            complete(v93 + v92);
            ++*(_QWORD *)(gsi_ctx + v91);
          }
          ++v90;
          v91 += 56;
          v92 += 448;
          if ( v90 == 32 )
            goto LABEL_201;
        }
      }
      bit_map_array_size = gsihal_get_bit_map_array_size(v3);
      if ( bit_map_array_size < 1 )
        goto LABEL_201;
      v84 = 0;
      v112 = (unsigned int)bit_map_array_size;
LABEL_184:
      v98 = 1792 * (v84 & 0x7FFFFFF) + 16360;
      v99 = 32 * (v84 & 0x7FFFFFF);
      v100 = (14336 * (v84 & 0x7FFFFFF)) | 0x1C0;
      v101 = gsihal_read_reg_nk(125, v1, (unsigned int)v84);
      gsihal_write_reg_nk(129, v1, (unsigned int)v84);
      v102 = 0;
      while ( 1 )
      {
        if ( ((v101 >> v102) & 1) != 0 )
        {
          v103 = gsi_ctx;
          if ( (unsigned __int64)(v99 + v102) > 0x23
            || v99 + v102 >= (unsigned __int64)*(unsigned int *)(gsi_ctx + 28608) )
          {
            dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid channel %d\n", "gsi_handle_ch_ctrl", 353, 32 * v84 + v102);
LABEL_183:
            if ( ++v84 == v112 )
              goto LABEL_201;
            goto LABEL_184;
          }
          gsihal_read_reg_nk_fields(8, v1, (unsigned int)(32 * v84 + v102), &v120);
          *(_DWORD *)(v103 + v100 - 144) = HIDWORD(v120);
          complete(v103 + v100);
          ++*(_QWORD *)(gsi_ctx + v98);
        }
        ++v102;
        v98 += 56;
        v100 += 448;
        if ( v102 == 32 )
          goto LABEL_183;
      }
    }
    if ( HIDWORD(v115) )
    {
      v121 = 0;
      v122 = 0;
      v85 = *(_DWORD *)(v11 + 16);
      v120 = 0;
      if ( v85 >= 0xA )
      {
        v86 = gsihal_get_bit_map_array_size(v3);
        if ( !v86 )
          goto LABEL_201;
        v87 = 0;
        v88 = v86;
LABEL_193:
        v104 = 10496 * (v87 & 0x7FFFFFF) + 18456;
        v105 = 32 * (v87 & 0x7FFFFFF);
        v106 = gsihal_read_reg_nk(126, v1, (unsigned int)v87);
        gsihal_write_reg_nk(130, v1, (unsigned int)v87);
        v107 = 0;
        while ( 1 )
        {
          if ( ((v106 >> v107) & 1) != 0 )
          {
            v108 = gsi_ctx;
            if ( (unsigned __int64)(v105 + v107) > 0x1E
              || v105 + v107 >= (unsigned __int64)*(unsigned int *)(gsi_ctx + 28612) )
            {
              dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid event %d\n", "gsi_handle_ev_ctrl", 417, 32 * v87 + v107);
LABEL_192:
              if ( ++v87 == v88 )
                goto LABEL_201;
              goto LABEL_193;
            }
            gsihal_read_reg_nk_fields(12, v1, (unsigned int)(32 * v87 + v107), &v120);
            *(_DWORD *)(v108 + v104) = HIDWORD(v120);
            complete(v108 + v104 + 128);
          }
          ++v107;
          v104 += 328;
          if ( v107 == 32 )
            goto LABEL_192;
        }
      }
      v94 = gsihal_read_reg_nk(10, v1, 0);
      gsihal_write_reg_nk(11, v1, 0);
      v95 = 0;
      v96 = 18456;
      while ( 1 )
      {
        if ( ((v94 >> v95) & 1) != 0 )
        {
          v97 = gsi_ctx;
          if ( v95 == 31 || v95 >= *(unsigned int *)(gsi_ctx + 28612) )
          {
            dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid event %d\n", "gsi_handle_ev_ctrl", 441, (unsigned int)v95);
            goto LABEL_201;
          }
          gsihal_read_reg_nk_fields(12, v1, (unsigned int)v95, &v120);
          *(_DWORD *)(v97 + v96) = HIDWORD(v120);
          complete(v97 + v96 + 128);
        }
        ++v95;
        v96 += 328;
        if ( v95 == 32 )
          goto LABEL_201;
      }
    }
    if ( !(_DWORD)v115 )
      goto LABEL_29;
    v119 = 0;
    v117 = 0;
    ((void (__fastcall *)(__int64, _QWORD, int *))gsihal_read_reg_n_fields)(13, v1, &v117);
    v118 = *(_QWORD *)(gsi_ctx + 128);
    if ( !HIBYTE(v117) )
      goto LABEL_18;
    v49 = gsihal_read_reg_nk(14, v1, 0);
    if ( *(_DWORD *)(gsi_ctx + 16) >= 2u )
      gsihal_write_reg_nk(14, v1, 0);
    gsihal_write_reg_nk(15, v1, 0);
    v129 = 0;
    v50 = HIBYTE(v49) & 0xF;
    v127 = 0;
    LODWORD(v6) = v49 >> 28;
    v51 = (v49 >> 19) & 0x1F;
    v125 = 0;
    v122 = 0;
    v123 = 0;
    v120 = 0;
    v121 = 0;
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d log err_type=%u ee=%u idx=%u\n",
      "gsi_handle_glob_err",
      471,
      v50,
      v49 >> 28,
      v51);
    v0 = (unsigned __int16)v49 >> 12;
    v52 = dev_err(
            *(_QWORD *)(gsi_ctx + 8),
            "%s:%d code=%u arg1=%u arg2=%u arg3=%u\n",
            "gsi_handle_glob_err",
            473,
            v0,
            (v49 >> 8) & 0xF,
            (unsigned __int8)v49 >> 4,
            v49 & 0xF);
    v53 = gsi_ctx;
    if ( v50 == 3 )
      break;
    if ( v50 == 2 )
    {
      if ( v51 >= *(_DWORD *)(gsi_ctx + 28608) )
      {
        __break(0x800u);
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unexpected ch %d\n", "gsi_handle_glob_err", 490, v51, *(double *)&v52);
        goto LABEL_18;
      }
      v72 = gsi_ctx + 448LL * v51;
      v73 = *(_QWORD *)(v72 + 296);
      v74 = v72 + 184;
      WORD2(v129) = v49;
      v128 = v73;
      if ( (unsigned __int16)((unsigned __int16)v49 >> 12) > 3u )
      {
        switch ( v0 )
        {
          case 4:
            v75 = 4;
            goto LABEL_158;
          case 6:
            if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
              goto LABEL_207;
            LODWORD(v129) = 1;
            break;
          case 8:
            if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
              goto LABEL_215;
            v75 = 5;
LABEL_158:
            LODWORD(v129) = v75;
            break;
          default:
            goto LABEL_214;
        }
      }
      else
      {
        switch ( v0 )
        {
          case 1:
            if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
              goto LABEL_211;
            gsihal_read_reg_nk_fields(8, (unsigned int)v6, v51, &v120);
            v80 = *(_QWORD *)(v74 + 368) + 1LL;
            v81 = HIDWORD(v120) == 15;
            *(_DWORD *)(v74 + 120) = HIDWORD(v120);
            *(_QWORD *)(v74 + 368) = v80;
            if ( v81 )
              goto LABEL_212;
            LODWORD(v129) = 0;
            break;
          case 2:
            if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
              goto LABEL_205;
            v75 = 2;
            goto LABEL_158;
          case 3:
            if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
              goto LABEL_213;
            LODWORD(v129) = 3;
            complete(v72 + 448);
            break;
          default:
            goto LABEL_214;
        }
      }
      v55 = *(void (__fastcall **)(_QWORD, long double))(v74 + 96);
      v56 = &v128;
      if ( *((_DWORD *)v55 - 1) != -1142912610 )
        __break(0x8228u);
      goto LABEL_161;
    }
    if ( v50 == 1 )
    {
      v54 = *(_QWORD *)(gsi_ctx + 128);
      v55 = *(void (__fastcall **)(_QWORD, long double))(gsi_ctx + 104);
      v56 = &v124;
      WORD2(v125) = v49;
      v124 = v54;
      if ( *((_DWORD *)v55 - 1) != 1830842481 )
        __break(0x8228u);
      goto LABEL_161;
    }
LABEL_18:
    if ( BYTE2(v117) )
      complete(gsi_ctx + 28616);
    if ( BYTE1(v117) )
    {
      LODWORD(v119) = 2;
      v15 = *(void (__fastcall **)(_QWORD))(gsi_ctx + 104);
      if ( *((_DWORD *)v15 - 1) != 1830842481 )
        __break(0x8228u);
      v15(&v118);
    }
    if ( (_BYTE)v117 )
    {
      LODWORD(v119) = 3;
      v16 = *(void (__fastcall **)(_QWORD))(gsi_ctx + 104);
      if ( *((_DWORD *)v16 - 1) != 1830842481 )
        __break(0x8228u);
      v16(&v118);
    }
    v3 = gsihal_write_reg_nk(16, v1, 0);
LABEL_29:
    if ( !HIDWORD(v114) )
      goto LABEL_82;
    v121 = 0;
    v122 = 0;
    v120 = 0;
    if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
    {
      v18 = gsihal_read_reg_nk(19, v1, 0);
      v19 = gsihal_read_reg_nk(3, v1, 0);
      v3 = gsihal_write_reg_nk(20, v1, 0);
      v23 = 0;
      v24 = v18 & v19;
      while ( 1 )
      {
        if ( (v24 & (1 << v23)) != 0 )
        {
          v25 = gsi_ctx;
          if ( v23 == 31 || v23 >= *(unsigned int *)(gsi_ctx + 28612) )
          {
            v9 = dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid event %d\n", "gsi_handle_ieob", 911, v23);
            goto LABEL_82;
          }
          v26 = (unsigned int *)(gsi_ctx + 328 * v23 + 18328);
          if ( *(_DWORD *)(gsi_ctx + 328 * v23 + 18332) )
          {
            v27 = *v26;
            if ( (_DWORD)v27 != 2 )
              goto LABEL_204;
            v28 = raw_spin_lock_irqsave(gsi_ctx + 328 * v23 + 18464, v20, v21, v22, v27);
            do
            {
              v30 = *((_DWORD **)v26 + 15);
              v31 = *((unsigned __int8 *)v26 + 132);
              if ( *(v30 - 1) != -1228272253 )
                __break(0x8228u);
              v32 = ((__int64 (__fastcall *)(unsigned int *, __int64, _QWORD))v30)(v26, v31, v1)
                  | ((unsigned __int64)v26[43] << 32);
              v33 = *((_QWORD *)v26 + 23);
              *((_QWORD *)v26 + 21) = v32;
              if ( v33 == v32 || *(_DWORD *)(*((_QWORD *)v26 + 36) + 300LL) )
                break;
              gsi_process_evt_re(v26, &v120, 1);
              v6 = 1;
              if ( *((_QWORD *)v26 + 23) != v32 )
              {
                while ( !*(_DWORD *)(*((_QWORD *)v26 + 36) + 300LL) )
                {
                  ++v6;
                  gsi_process_evt_re(v26, &v120, 1);
                  if ( *((_QWORD *)v26 + 23) == v32 )
                    goto LABEL_43;
                }
                v6 = 0;
              }
LABEL_43:
              v29 = *((unsigned __int8 *)v26 + 132);
              *((_QWORD *)v26 + 20) = *((_QWORD *)v26 + 22);
              gsihal_write_reg_nk(17, *(unsigned int *)(gsi_ctx + 20), v29);
            }
            while ( v6 );
            v3 = raw_spin_unlock_irqrestore(v26 + 34, v28);
          }
        }
        if ( ++v23 == 32 )
          goto LABEL_82;
      }
    }
    v3 = gsihal_get_bit_map_array_size(v3);
    if ( (int)v3 >= 1 )
    {
      v17 = 0;
      v110 = (unsigned int)v3;
LABEL_54:
      v34 = gsihal_read_reg_nk(131, v1, (unsigned int)v17);
      v0 = gsihal_read_reg_nk(132, v1, (unsigned int)v17);
      v3 = gsihal_write_reg_nk(133, v1, (unsigned int)v17);
      v111 = v17;
      v38 = (unsigned int)(32 * v17);
      v39 = 0;
      while ( 1 )
      {
        if ( (v34 & v0 & (1 << v39)) != 0 )
        {
          v40 = v39 + v38;
          if ( (unsigned __int64)(v39 + v38) > 0x1E || v40 >= *(unsigned int *)(gsi_ctx + 28612) )
          {
            v9 = dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid event %d\n", "gsi_handle_ieob", 855, v40);
LABEL_53:
            v17 = v111 + 1;
            if ( v111 + 1 == v110 )
              break;
            goto LABEL_54;
          }
          v41 = (unsigned int *)(gsi_ctx + 328 * v40 + 18328);
          if ( *(_DWORD *)(gsi_ctx + 328 * v40 + 18332) )
          {
            v42 = *v41;
            if ( (_DWORD)v42 != 2 )
            {
              dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unexpected irq intf %d\n", "gsi_handle_ieob", 870, v42);
              __break(0x800u);
LABEL_204:
              dev_err(*(_QWORD *)(v25 + 8), "%s:%d Unexpected irq intf %d\n", "gsi_handle_ieob", 925, v27);
              __break(0x800u);
LABEL_205:
              dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 517, v6);
              __break(0x800u);
LABEL_206:
              dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 561, v6);
              __break(0x800u);
LABEL_207:
              dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 533, v6);
              __break(0x800u);
LABEL_208:
              dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 567, v6);
              __break(0x800u);
LABEL_209:
              dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected event log code %d\n", "gsi_handle_glob_err", 581, v0);
              __break(0x800u);
              goto LABEL_210;
            }
            v43 = raw_spin_lock_irqsave(v41 + 34, v35, v36, v37, v42);
            do
            {
              v46 = *((_DWORD **)v41 + 15);
              v47 = *((unsigned __int8 *)v41 + 132);
              if ( *(v46 - 1) != -1228272253 )
                __break(0x8228u);
              v6 = ((__int64 (__fastcall *)(unsigned int *, __int64, _QWORD))v46)(v41, v47, v1)
                 | ((unsigned __int64)v41[43] << 32);
              v48 = *((_QWORD *)v41 + 23);
              *((_QWORD *)v41 + 21) = v6;
              if ( v48 == v6 || *(_DWORD *)(*((_QWORD *)v41 + 36) + 300LL) )
                break;
              gsi_process_evt_re(v41, &v120, 1);
              v44 = 1;
              if ( *((_QWORD *)v41 + 23) != v6 )
              {
                while ( !*(_DWORD *)(*((_QWORD *)v41 + 36) + 300LL) )
                {
                  ++v44;
                  gsi_process_evt_re(v41, &v120, 1);
                  if ( *((_QWORD *)v41 + 23) == v6 )
                    goto LABEL_64;
                }
                v44 = 0;
              }
LABEL_64:
              v45 = *((unsigned __int8 *)v41 + 132);
              *((_QWORD *)v41 + 20) = *((_QWORD *)v41 + 22);
              gsihal_write_reg_nk(17, *(unsigned int *)(gsi_ctx + 20), v45);
            }
            while ( v44 );
            v3 = raw_spin_unlock_irqrestore(v41 + 34, v43);
          }
        }
        if ( ++v39 == 32 )
          goto LABEL_53;
      }
    }
LABEL_82:
    if ( (_DWORD)v114 )
    {
      if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
      {
        v62 = gsihal_read_reg_nk(21, v1, 0);
        v3 = gsihal_write_reg_nk(21, v1, 0);
        for ( i = 0; i != 32; ++i )
        {
          if ( ((v62 >> i) & 1) != 0 )
            v9 = dev_err(
                   *(_QWORD *)(gsi_ctx + 8),
                   "%s:%d ch %u was inter-EE changed\n",
                   "gsi_handle_inter_ee_ch_ctrl",
                   982,
                   i);
        }
      }
      else
      {
        v3 = gsihal_get_bit_map_array_size(v3);
        if ( (int)v3 >= 1 )
        {
          v57 = v3;
          v58 = 0;
          for ( j = 0; j != v57; ++j )
          {
            v60 = gsihal_read_reg_nk(134, v1, j);
            v3 = gsihal_write_reg_nk(134, v1, j);
            for ( k = 0; k != 32; ++k )
            {
              if ( ((v60 >> k) & 1) != 0 )
                v9 = dev_err(
                       *(_QWORD *)(gsi_ctx + 8),
                       "%s:%d ch %u was inter-EE changed\n",
                       "gsi_handle_inter_ee_ch_ctrl",
                       971,
                       v58 + k);
            }
            v58 += 32;
          }
        }
      }
    }
    if ( HIDWORD(v113) )
    {
      if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
      {
        v69 = gsihal_read_reg_nk(23, v1, 0);
        v3 = gsihal_write_reg_nk(24, v1, 0);
        for ( m = 0; m != 32; ++m )
        {
          if ( ((v69 >> m) & 1) != 0 )
            v9 = dev_err(
                   *(_QWORD *)(gsi_ctx + 8),
                   "%s:%d evt %u was inter-EE changed\n",
                   "gsi_handle_inter_ee_ev_ctrl",
                   1015,
                   m);
        }
      }
      else
      {
        v3 = gsihal_get_bit_map_array_size(v3);
        if ( (int)v3 >= 1 )
        {
          v64 = v3;
          v65 = 0;
          for ( n = 0; n != v64; ++n )
          {
            v67 = gsihal_read_reg_nk(136, v1, n);
            v3 = gsihal_write_reg_nk(137, v1, n);
            for ( ii = 0; ii != 32; ++ii )
            {
              if ( ((v67 >> ii) & 1) != 0 )
                v9 = dev_err(
                       *(_QWORD *)(gsi_ctx + 8),
                       "%s:%d evt %u was inter-EE changed\n",
                       "gsi_handle_inter_ee_ev_ctrl",
                       1004,
                       v65 + ii);
            }
            v65 += 32;
          }
        }
      }
    }
    if ( (_DWORD)v113 )
    {
      v121 = 0;
      LODWORD(v128) = 0;
      ((void (__fastcall *)(__int64, _QWORD, __int64 *, long double))gsihal_read_reg_n_fields)(25, v1, &v128, v9);
      v120 = *(_QWORD *)(gsi_ctx + 128);
      if ( (_BYTE)v128 )
        LODWORD(v121) = 7;
      if ( BYTE1(v128) )
        LODWORD(v121) = 6;
      if ( BYTE2(v128) )
        LODWORD(v121) = 5;
      if ( BYTE3(v128) )
        LODWORD(v121) = 4;
      v71 = *(void (__fastcall **)(_QWORD))(gsi_ctx + 104);
      if ( v71 )
      {
        if ( *((_DWORD *)v71 - 1) != 1830842481 )
          __break(0x8228u);
        v71(&v120);
      }
      v3 = gsihal_write_reg_nk(26, v1, 0);
    }
    v4 = *(unsigned int (__fastcall **)(_QWORD))(gsi_ctx + 136);
    if ( *((_DWORD *)v4 - 1) != 1874538549 )
      __break(0x8228u);
    if ( !v4(v3) )
      goto LABEL_201;
  }
  if ( v51 >= *(_DWORD *)(gsi_ctx + 28612) )
  {
    __break(0x800u);
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unexpected ev %d\n", "gsi_handle_glob_err", 552, v51, *(double *)&v52);
    goto LABEL_18;
  }
  v76 = gsi_ctx + 328LL * v51;
  v77 = *(_QWORD *)(v76 + 18432);
  WORD2(v127) = v49;
  v126 = v77;
  v78 = v76 + 18328;
  if ( (unsigned __int16)((unsigned __int16)v49 >> 12) <= 3u )
  {
    if ( v0 == 2 )
    {
      if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
        goto LABEL_206;
      LODWORD(v127) = 0;
    }
    else
    {
      if ( v0 != 3 )
        goto LABEL_209;
      if ( (_DWORD)v6 != *(_DWORD *)(gsi_ctx + 20) )
        goto LABEL_208;
      LODWORD(v127) = 1;
      complete(v76 + 18584);
    }
LABEL_145:
    v55 = *(void (__fastcall **)(_QWORD, long double))(v78 + 96);
    v56 = &v126;
    if ( *((_DWORD *)v55 - 1) != -1375699703 )
      __break(0x8228u);
LABEL_161:
    v55(v56, v52);
    goto LABEL_18;
  }
  if ( v0 == 4 )
  {
    v79 = 2;
LABEL_144:
    LODWORD(v127) = v79;
    goto LABEL_145;
  }
  if ( v0 != 5 )
    goto LABEL_209;
  if ( (_DWORD)v6 == *(_DWORD *)(gsi_ctx + 20) )
  {
    v79 = 3;
    goto LABEL_144;
  }
LABEL_210:
  dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 576, v6);
  __break(0x800u);
LABEL_211:
  dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 499, v6);
  __break(0x800u);
LABEL_212:
  dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Unexpected channel state %d\n", "gsi_handle_glob_err", 511, 15);
  __break(0x800u);
LABEL_213:
  dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 523, v6);
  __break(0x800u);
LABEL_214:
  dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected event log code %d\n", "gsi_handle_glob_err", 545, v0);
  __break(0x800u);
LABEL_215:
  v109 = dev_err(*(_QWORD *)(v53 + 8), "%s:%d unexpected EE in event %d\n", "gsi_handle_glob_err", 540, v6);
  __break(0x800u);
  gsi_map_base(v109);
}
