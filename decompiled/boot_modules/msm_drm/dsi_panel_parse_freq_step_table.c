__int64 __fastcall dsi_panel_parse_freq_step_table(__int64 a1, __int64 *a2)
{
  __int64 v2; // x27
  __int64 (__fastcall *v3)(__int64, const char *, char *); // x8
  __int64 v4; // x0
  unsigned __int64 v5; // x22
  __int64 v6; // x0
  int v7; // w3
  const char *v8; // x21
  __int64 v9; // x19
  __int64 (__fastcall *v10)(__int64, const char *, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x3
  int v13; // w0
  __int64 result; // x0
  _DWORD *v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // w3
  unsigned int v19; // w20
  unsigned __int64 v20; // x23
  __int64 v21; // x24
  __int64 v22; // x0
  __int64 v23; // x28
  __int64 (__fastcall *v24)(__int64, const char *, __int64, __int64); // x8
  __int64 v25; // x0
  __int64 v26; // x3
  int v27; // w0
  __int64 (__fastcall *v28)(__int64, const char *, __int64, unsigned __int64); // x9
  __int64 v29; // x0
  unsigned __int64 v30; // x3
  unsigned int v31; // w0
  unsigned int v32; // w8
  __int64 v33; // x0
  __int64 v34; // x26
  int v35; // w8
  int v36; // w3
  int v37; // w10
  int v38; // w9
  unsigned __int64 v39; // x11
  unsigned __int64 v40; // x11
  int v41; // w11
  int v42; // w4
  unsigned __int64 v43; // x16
  unsigned int v44; // w13
  int v45; // w20
  bool v46; // w8
  int v47; // w9
  int v48; // w8
  unsigned __int64 v49; // x10
  unsigned __int64 v50; // x10
  bool v51; // cf
  __int64 v52; // x15
  unsigned __int64 v53; // x11
  __int64 v54; // x26
  unsigned __int64 v55; // x25
  unsigned __int64 v56; // x11
  __int64 v57; // x8
  unsigned int v58; // w9
  unsigned int v59; // w10
  unsigned __int64 v60; // x11
  unsigned __int64 v61; // x11
  int v62; // w11
  unsigned __int64 v63; // x28
  _DWORD *v64; // x0
  unsigned int v65; // w9
  __int64 v66; // x10
  int v67; // w11
  unsigned int v68; // w14
  unsigned int v69; // w12
  unsigned __int64 v70; // x15
  unsigned __int64 v72; // x9
  unsigned __int64 v73; // x9
  unsigned __int64 v74; // x15
  int v75; // w9
  int v76; // w13
  char v78; // w14
  unsigned int v79; // w13
  __int64 v80; // x8
  int v81; // w9
  __int64 v82; // x24
  __int64 v83; // x9
  unsigned int v84; // w25
  unsigned __int64 StatusReg; // x20
  __int64 v86; // x23
  __int64 v87; // [xsp+20h] [xbp-50h]
  __int64 v88; // [xsp+28h] [xbp-48h]
  __int64 v89; // [xsp+30h] [xbp-40h]
  unsigned __int64 v90; // [xsp+38h] [xbp-38h]
  unsigned __int64 v91; // [xsp+40h] [xbp-30h]
  unsigned int v92; // [xsp+48h] [xbp-28h]
  unsigned __int64 v93; // [xsp+50h] [xbp-20h]
  unsigned __int64 v94; // [xsp+58h] [xbp-18h]
  _QWORD v95[2]; // [xsp+60h] [xbp-10h] BYREF

  v95[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95[0] = 0;
  if ( a1 && (v2 = *(_QWORD *)(a1 + 184)) != 0 )
  {
    v3 = (__int64 (__fastcall *)(__int64, const char *, char *))a2[2];
    v4 = *a2;
    v5 = (unsigned __int64)a2;
    if ( *((_DWORD *)v3 - 1) != -1612502898 )
      __break(0x8228u);
    v6 = v3(v4, "qcom,mdss-dsi-qsync-freq-step-sequence", (char *)v95 + 4);
    v7 = HIDWORD(v95[0]);
    if ( !v6 || (v95[0] & 0x100000000LL) != 0 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: qsync-freq-step-sequence error data %d length\n",
        HIDWORD(v95[0]));
    }
    else
    {
      HIDWORD(v95[0]) >>= 2;
      v8 = (const char *)(v7 & 0xFFFFFFFC);
      v9 = _kmalloc_noprof(v8, 3520);
      if ( !v9 )
      {
LABEL_114:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Error allocating memory for freq_patterrn_arr32\n");
        result = 4294967284LL;
        goto LABEL_119;
      }
      while ( 1 )
      {
        v10 = *(__int64 (__fastcall **)(__int64, const char *, __int64, __int64))(v5 + 56);
        v11 = *(_QWORD *)v5;
        v12 = HIDWORD(v95[0]);
        if ( *((_DWORD *)v10 - 1) != 905330014 )
          __break(0x8228u);
        v13 = v10(v11, "qcom,mdss-dsi-qsync-freq-step-sequence", v9, v12);
        if ( v13 )
        {
          LODWORD(v5) = v13;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: cannot read dsi freq steps %d\n");
LABEL_118:
          kfree(v9);
          result = (unsigned int)v5;
          goto LABEL_119;
        }
        v15 = *(_DWORD **)(v5 + 16);
        v16 = *(_QWORD *)v5;
        if ( *(v15 - 1) != -1612502898 )
          __break(0x8228u);
        v17 = ((__int64 (__fastcall *)(__int64, const char *, _QWORD *))v15)(
                v16,
                "qcom,mdss-dsi-qsync-freq-step-sequence-interval",
                v95);
        v18 = v95[0];
        if ( !v17 || (v95[0] & 1) != 0 )
          break;
        v19 = v95[0] & 0xFFFFFFFC;
        LODWORD(v95[0]) >>= 2;
        v20 = v18 & 0xFFFFFFFC;
        v21 = _kmalloc_noprof(v20, 3520);
        v22 = _kmalloc_noprof(v19 / 3uLL, 3520);
        v23 = v22;
        if ( !v21 || !v22 )
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Error allocating memory for property\n");
LABEL_116:
          LODWORD(v5) = -12;
          goto LABEL_117;
        }
        v24 = *(__int64 (__fastcall **)(__int64, const char *, __int64, __int64))(v5 + 56);
        v25 = *(_QWORD *)v5;
        v26 = LODWORD(v95[0]);
        if ( *((_DWORD *)v24 - 1) != 905330014 )
          __break(0x8228u);
        v27 = v24(v25, "qcom,mdss-dsi-qsync-freq-step-sequence-interval", v21, v26);
        if ( v27 )
        {
          LODWORD(v5) = v27;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: cannot read dsi freq steps %d\n", v27);
LABEL_117:
          kfree(v23);
          goto LABEL_118;
        }
        v28 = *(__int64 (__fastcall **)(__int64, const char *, __int64, unsigned __int64))(v5 + 56);
        v29 = *(_QWORD *)v5;
        v30 = LODWORD(v95[0]) / 3uLL;
        if ( *((_DWORD *)v28 - 1) != 905330014 )
          __break(0x8229u);
        v31 = v28(v29, "qcom,mdss-dsi-qsync-freq-pattren-needs-selfrefresh", v23, v30);
        v5 = v31;
        if ( v31 )
          printk(&unk_260433, v31);
        v32 = LODWORD(v95[0]) / 3;
        if ( LODWORD(v95[0]) != 3 * (LODWORD(v95[0]) / 3) )
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Frame interval length mismatch %d\n");
          goto LABEL_118;
        }
        LODWORD(v95[0]) /= 3u;
        *(_DWORD *)(v2 + 2472) = v32;
        v90 = v19 / 3uLL;
        v94 = 32LL * *(unsigned int *)(v2 + 2472);
        v33 = _kmalloc_noprof(v94, 3520);
        v34 = v33;
        if ( !v33 )
          goto LABEL_116;
        v35 = v95[0];
        *(_QWORD *)(v2 + 2464) = v33;
        if ( v35 )
        {
          v36 = 0;
          v37 = 2;
          v38 = v35;
          do
          {
            v39 = 4LL * v37;
            v51 = v20 >= v39;
            v40 = v20 - v39;
            if ( !v51 || v40 < 4 )
              goto LABEL_113;
            --v38;
            v41 = *(_DWORD *)(v21 + 4LL * v37);
            v37 += 3;
            v36 += v41;
          }
          while ( v38 );
          v42 = HIDWORD(v95[0]) >> 1;
          if ( v36 == HIDWORD(v95[0]) >> 1 )
          {
            v43 = v94;
            v44 = 0;
            v45 = 0;
            _ReadStatusReg(SP_EL0);
            v87 = v33;
            v88 = v23;
            while ( 1 )
            {
              v47 = 3 * v44;
              v48 = 3 * v44 + 1;
              v49 = 4LL * v48;
              v51 = v20 >= v49;
              v50 = v20 - v49;
              v51 = v51 && v50 >= 4;
              if ( !v51 )
                goto LABEL_113;
              if ( v43 < ((32LL * (int)v44) | 0xCuLL) )
                goto LABEL_113;
              v52 = 32LL * (int)v44;
              v53 = 4LL * (v47 + 2);
              v54 = v34 + v52;
              *(_DWORD *)(v54 + 12) = *(_DWORD *)(v21 + 4LL * v48);
              if ( v20 < v53 )
                goto LABEL_113;
              if ( v20 - v53 < 4 )
                goto LABEL_113;
              v55 = v52 | 0x10;
              if ( v43 < (v52 | 0x10uLL) )
                goto LABEL_113;
              v56 = 4LL * v47;
              v57 = *(unsigned int *)(v21 + 4LL * (v47 + 2));
              *(_DWORD *)(v54 + 16) = v57;
              if ( v20 < v56 )
                goto LABEL_113;
              if ( v20 - v56 < 4 )
                goto LABEL_113;
              if ( v43 < (v52 | 0x14uLL) )
                goto LABEL_113;
              *(_DWORD *)(v54 + 20) = *(_DWORD *)(v21 + 4LL * v47);
              if ( v43 < (v52 | 0x18uLL) )
                goto LABEL_113;
              v58 = 0;
              *(_DWORD *)(v54 + 24) = v44;
              if ( (_DWORD)v57 )
              {
                v59 = v45 + 1;
                do
                {
                  v60 = 4LL * v59;
                  v51 = (unsigned __int64)v8 >= v60;
                  v61 = (unsigned __int64)&v8[-v60];
                  if ( !v51 || v61 < 4 )
                    goto LABEL_113;
                  --v57;
                  v62 = *(_DWORD *)(v9 + 4LL * v59);
                  v59 += 2;
                  v58 += v62;
                }
                while ( v57 );
              }
              if ( v43 < (v52 | 8uLL) )
                goto LABEL_113;
              v91 = (32LL * (int)v44) | 0xC;
              v93 = 32LL * (int)v44;
              v89 = (int)v44;
              v92 = v44;
              *(_DWORD *)(v54 + 8) = v58;
              v63 = 4LL * v58;
              v64 = (_DWORD *)_kmalloc_noprof(v63, 3520);
              v43 = v94;
              if ( !v64 )
              {
                drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to create frequency stepping array.\n");
                v23 = v88;
                goto LABEL_116;
              }
              if ( v94 < v55 )
                goto LABEL_113;
              v65 = *(_DWORD *)(v54 + 16);
              if ( v65 )
              {
                v66 = 0;
                v67 = 0;
                do
                {
                  v68 = v45 + 2 * v66;
                  v69 = v68 | 1;
                  v70 = 4LL * (v68 | 1);
                  if ( (unsigned __int64)v8 < v70 || (unsigned __int64)&v8[-v70] < 4 )
                    goto LABEL_113;
                  if ( *(_DWORD *)(v9 + 4LL * v69) )
                  {
                    v72 = 4LL * (unsigned int)(v45 + 2 * v66);
                    v51 = (unsigned __int64)v8 >= v72;
                    v73 = (unsigned __int64)&v8[-v72];
                    if ( v51 && v73 >= 4 )
                    {
                      v51 = (unsigned __int64)v8 >= v70;
                      v74 = (unsigned __int64)&v8[-v70];
                      v75 = *(_DWORD *)(v9 + 4LL * v68);
                      v76 = 0;
                      v78 = !v51 || v74 < 4;
                      while ( v63 > 4 * (unsigned __int64)(unsigned int)(v67 + v76) )
                      {
                        v64[v67 + v76] = v75;
                        if ( (v78 & 1) != 0 )
                          break;
                        if ( (unsigned int)++v76 >= *(_DWORD *)(v9 + 4LL * v69) )
                        {
                          if ( v94 >= v55 )
                          {
                            v65 = *(_DWORD *)(v54 + 16);
                            v67 += v76;
                            goto LABEL_69;
                          }
                          goto LABEL_113;
                        }
                      }
                    }
                    goto LABEL_113;
                  }
LABEL_69:
                  ;
                }
                while ( ++v66 < (unsigned __int64)v65 );
              }
              if ( v94 <= v93 )
                goto LABEL_113;
              *(_QWORD *)v54 = v64;
              if ( !(_DWORD)v5 )
                break;
              if ( v94 < v91 || !v63 )
                goto LABEL_113;
              v23 = v88;
              v79 = v92;
              if ( *(_DWORD *)(v54 + 12) >= *v64 )
              {
                if ( v94 < (v93 | 0x1C) )
                  goto LABEL_113;
                v46 = 1;
LABEL_42:
                *(_BYTE *)(v54 + 28) = v46;
              }
              v44 = v79 + 1;
              v45 += 2 * v65;
              v34 = v87;
              if ( v44 >= LODWORD(v95[0]) )
                goto LABEL_103;
            }
            if ( v90 < 4 * v89 )
              goto LABEL_113;
            if ( v90 - 4 * v89 < 4 )
              goto LABEL_113;
            v23 = v88;
            v79 = v92;
            if ( v94 < (v93 | 0x1C) )
              goto LABEL_113;
            v46 = *(_DWORD *)(v88 + 4 * v89) != 0;
            goto LABEL_42;
          }
LABEL_112:
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: Mismatch detected in pattern count %d From step seq:%d.\n",
            v36,
            v42);
          goto LABEL_117;
        }
        v43 = v94;
        if ( HIDWORD(v95[0]) >= 2 )
        {
          v42 = HIDWORD(v95[0]) >> 1;
          v36 = 0;
          goto LABEL_112;
        }
LABEL_103:
        if ( !*(_DWORD *)(v2 + 2472) )
          goto LABEL_117;
        v80 = *(_QWORD *)(v2 + 2464);
        v81 = 0;
        v8 = "[msm-dsi-debug]: usecaseIdx:%d FI:%d, AP_SR:%d Num freq steps:%d Total steps:%d %p\n";
        while ( 1 )
        {
          v82 = v81;
          if ( v43 < ((32LL * v81) | 0x1CuLL) )
            break;
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: usecaseIdx:%d FI:%d, AP_SR:%d Num freq steps:%d Total steps:%d %p\n",
            *(_DWORD *)(v80 + 32LL * v81 + 20),
            *(_DWORD *)(v80 + 32LL * v81 + 12),
            *(unsigned __int8 *)(v34 + 32LL * v81 + 28),
            *(_DWORD *)(v80 + 32LL * v81 + 16),
            *(_DWORD *)(v80 + 32LL * v81 + 8),
            (const void *)(v80 + 32LL * v81));
          v80 = *(_QWORD *)(v2 + 2464);
          v83 = v80 + 32 * v82;
          if ( *(_DWORD *)(v83 + 8) )
          {
            v84 = 0;
            do
            {
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]:  %d\n", *(_DWORD *)(*(_QWORD *)v83 + 4LL * (int)v84));
              v80 = *(_QWORD *)(v2 + 2464);
              ++v84;
              v83 = v80 + 32 * v82;
            }
            while ( v84 < *(_DWORD *)(v83 + 8) );
          }
          v81 = v82 + 1;
          v43 = v94;
          if ( (unsigned int)(v82 + 1) >= *(_DWORD *)(v2 + 2472) )
            goto LABEL_117;
        }
LABEL_113:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v86 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &dsi_panel_parse_freq_step_table__alloc_tag;
        v9 = _kmalloc_noprof(v8, 3520);
        *(_QWORD *)(StatusReg + 80) = v86;
        if ( !v9 )
          goto LABEL_114;
      }
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: qsync-freq-step-sequence-interval error data %d length\n",
        LODWORD(v95[0]));
    }
    result = 4294967274LL;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    result = 4294967274LL;
  }
LABEL_119:
  _ReadStatusReg(SP_EL0);
  return result;
}
