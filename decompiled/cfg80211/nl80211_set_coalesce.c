__int64 __fastcall nl80211_set_coalesce(__int64 a1, __int64 a2)
{
  int **v2; // x27
  int *v3; // x8
  _WORD *v4; // x10
  int v5; // w9
  int v6; // w21
  unsigned __int16 *v7; // x10
  unsigned int v8; // w11
  __int64 v9; // x11
  __int64 result; // x0
  int *v11; // x19
  int v12; // w8
  __int64 v13; // x20
  __int64 v14; // x23
  __int64 v15; // x24
  __int64 v16; // x25
  __int64 v18; // x8
  __int64 v19; // x8
  unsigned __int64 v20; // x19
  int *v21; // x0
  int *v22; // x26
  __int64 v23; // x8
  _WORD *v24; // x8
  unsigned int v25; // w20
  int v26; // w23
  unsigned __int16 *v27; // x24
  _DWORD *v28; // x25
  unsigned int v29; // w8
  int *v30; // x9
  int v31; // w0
  __int64 v32; // x21
  int *v33; // x12
  bool v34; // cf
  char v36; // w9
  int v37; // w8
  int v38; // w8
  int v39; // w22
  unsigned __int16 *v40; // x9
  unsigned int v41; // w10
  __int64 v42; // x10
  __int64 v43; // x0
  unsigned __int64 v44; // x8
  _WORD *v45; // x9
  int v46; // w21
  unsigned __int64 v47; // x8
  int v48; // w22
  unsigned __int16 *v49; // x28
  bool v50; // cf
  char v51; // w8
  unsigned int v52; // w9
  size_t v53; // x23
  unsigned __int64 v54; // x24
  int v55; // w8
  unsigned __int64 v56; // x25
  int *v57; // x0
  char *v58; // x0
  size_t v59; // x1
  __int64 v60; // x8
  __int64 v61; // x8
  _DWORD *v62; // x8
  __int64 (__fastcall *v63)(int **, int *); // x8
  int v64; // w8
  __int64 v65; // x22
  _DWORD *v66; // x23
  __int64 v67; // x25
  _DWORD *v68; // x24
  unsigned __int64 v69; // x8
  int *v70; // x21
  __int64 v71; // x20
  bool v74; // w27
  unsigned __int64 v75; // x8
  char v77; // w28
  unsigned __int64 StatusReg; // x19
  __int64 v79; // x0
  __int64 v80; // x1
  __int64 v81; // x2
  __int64 v82; // x8
  _DWORD *v83; // [xsp+18h] [xbp-88h]
  unsigned __int16 *v84; // [xsp+20h] [xbp-80h]
  int v85; // [xsp+28h] [xbp-78h]
  unsigned int v86; // [xsp+2Ch] [xbp-74h]
  int *v87; // [xsp+30h] [xbp-70h]
  unsigned __int64 v88; // [xsp+38h] [xbp-68h]
  int *v89; // [xsp+40h] [xbp-60h]
  char v90; // [xsp+4Ch] [xbp-54h]
  _DWORD *v91; // [xsp+50h] [xbp-50h]
  __int64 v92; // [xsp+58h] [xbp-48h] BYREF
  _WORD *v93; // [xsp+60h] [xbp-40h]
  _WORD *v94; // [xsp+68h] [xbp-38h]
  __int64 v95; // [xsp+70h] [xbp-30h]
  __int64 v96; // [xsp+78h] [xbp-28h] BYREF
  __int64 v97; // [xsp+80h] [xbp-20h]
  __int64 v98; // [xsp+88h] [xbp-18h]
  _WORD *v99; // [xsp+90h] [xbp-10h]
  __int64 v100; // [xsp+98h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(int ***)(a2 + 48);
  v3 = v2[294];
  if ( !v3 || !*((_QWORD *)*v2 + 90) )
  {
    result = 4294967201LL;
    goto LABEL_11;
  }
  v4 = *(_WORD **)(*(_QWORD *)(a2 + 32) + 1456LL);
  if ( !v4 )
  {
    v11 = v2[82];
    if ( v11 )
    {
      v12 = *v11;
      if ( *v11 >= 1 )
      {
        v13 = 0;
        do
        {
          v14 = (__int64)&v11[6 * v13 + 2];
          if ( v14 )
          {
            if ( *(int *)(v14 + 16) >= 1 )
            {
              v15 = 0;
              v16 = 0;
              do
              {
                kfree(*(_QWORD *)(*(_QWORD *)(v14 + 8) + v15));
                ++v16;
                v15 += 24;
              }
              while ( v16 < *(int *)(v14 + 16) );
            }
            kfree(*(_QWORD *)(v14 + 8));
            v12 = *v11;
          }
          ++v13;
        }
        while ( v13 < v12 );
      }
      kfree(v11);
    }
    v2[82] = nullptr;
    goto LABEL_107;
  }
  v5 = (unsigned __int16)(*v4 - 4);
  if ( (unsigned int)v5 < 4 )
  {
    v6 = 0;
  }
  else
  {
    v6 = 0;
    v7 = v4 + 2;
    do
    {
      v8 = *v7;
      if ( v8 < 4 )
        break;
      if ( v5 < v8 )
        break;
      ++v6;
      v9 = (v8 + 3) & 0x1FFFC;
      v5 -= v9;
      v7 = (unsigned __int16 *)((char *)v7 + v9);
    }
    while ( v5 > 3 );
  }
  if ( v6 > *v3 )
  {
    result = 4294967274LL;
    goto LABEL_11;
  }
  v18 = 24LL * v6;
  v34 = __CFADD__(v18, 8);
  v19 = v18 + 8;
  if ( v34 )
    v19 = -1;
  if ( is_mul_ok(v6, 0x18u) )
    v20 = v19;
  else
    v20 = -1;
  v21 = (int *)_kmalloc_noprof(v20, 3520);
  v22 = v21;
  if ( !v21 )
  {
    result = 4294967284LL;
    goto LABEL_11;
  }
  v23 = *(_QWORD *)(a2 + 32);
  *v21 = v6;
  v24 = *(_WORD **)(v23 + 1456);
  v25 = (unsigned __int16)(*v24 - 4);
  if ( v25 < 4 )
  {
LABEL_112:
    v63 = *((__int64 (__fastcall **)(int **, int *))*v2 + 90);
    if ( v63 )
    {
      if ( *((_DWORD *)v63 - 1) != -172733808 )
        __break(0x8228u);
      v31 = v63(v2 + 124, v22);
    }
    else
    {
      v31 = -95;
    }
    if ( !v31 )
    {
      cfg80211_free_coalesce(v2[82]);
      result = 0;
      v2[82] = v22;
      goto LABEL_11;
    }
  }
  else
  {
    v26 = 0;
    v27 = v24 + 2;
    v28 = v21 + 2;
    _ReadStatusReg(SP_EL0);
    v83 = v21 + 2;
    v87 = v21;
    while ( 1 )
    {
      v29 = *v27;
      if ( v29 < 4 || v25 < v29 )
        goto LABEL_112;
      v98 = 0;
      v99 = nullptr;
      v30 = v2[294];
      v96 = 0;
      v97 = 0;
      v94 = nullptr;
      v95 = 0;
      v92 = 0;
      v93 = nullptr;
      v89 = v30;
      v31 = _nla_parse(&v96, 3, v27 + 2, (unsigned __int16)(*v27 - 4), &nl80211_coalesce_policy, 0, 0);
      if ( v31 )
        goto LABEL_125;
      v32 = 24LL * v26;
      v33 = &v28[(unsigned __int64)v32 / 4];
      v34 = v20 >= v32 + 8 && v20 - (v32 + 8) >= 4;
      v36 = !v34 || v26 < 0;
      if ( v97 )
      {
        if ( (v36 & 1) != 0 )
          goto LABEL_156;
        v37 = *(_DWORD *)(v97 + 4);
        *v33 = v37;
      }
      else
      {
        if ( (v36 & 1) != 0 )
          goto LABEL_156;
        v37 = *v33;
      }
      v22 = v89;
      if ( v37 > v89[1] )
        goto LABEL_119;
      if ( v98 )
      {
        if ( v26 < 0 || v20 < v32 + 12 || v20 - (v32 + 12) < 4 )
          goto LABEL_156;
        v33[1] = *(_DWORD *)(v98 + 4);
      }
      if ( !v99 )
        goto LABEL_119;
      v38 = (unsigned __int16)(*v99 - 4);
      if ( (unsigned int)v38 < 4 )
      {
        v39 = 0;
      }
      else
      {
        v39 = 0;
        v40 = v99 + 2;
        do
        {
          v41 = *v40;
          if ( v41 < 4 )
            break;
          if ( v38 < v41 )
            break;
          ++v39;
          v42 = (v41 + 3) & 0x1FFFC;
          v38 -= v42;
          v40 = (unsigned __int16 *)((char *)v40 + v42);
        }
        while ( v38 > 3 );
      }
      if ( v39 > v89[2] )
      {
LABEL_119:
        v31 = -22;
        goto LABEL_125;
      }
      v91 = &v28[(unsigned __int64)v32 / 4];
      if ( !is_mul_ok(v39, 0x18u) )
        break;
      v43 = _kmalloc_noprof(24LL * v39, 3520);
      v44 = v32 + 16;
      if ( v26 < 0 || v20 < v32 + 16 || v20 - (v32 + 16) < 8 )
        goto LABEL_156;
      *((_QWORD *)v91 + 1) = v43;
      if ( !v43 )
        goto LABEL_124;
      v84 = v27;
      v85 = v26;
      v86 = v25;
      if ( v20 < v32 + 24 || v20 - (v32 + 24) < 4 )
        goto LABEL_156;
      v45 = v99;
      v91[4] = v39;
      v46 = (unsigned __int16)(*v45 - 4);
      if ( (unsigned int)v46 >= 4 )
      {
        v34 = v20 >= v44;
        v47 = v20 - v44;
        v48 = 0;
        v49 = v45 + 2;
        v50 = v34 && v47 >= 8;
        v88 = v47;
        v51 = !v50;
        v90 = v51;
        while ( 1 )
        {
          v52 = *v49;
          if ( v52 < 4 || v46 < v52 )
            goto LABEL_103;
          v31 = _nla_parse(&v92, 3, v49 + 2, (unsigned __int16)(v52 - 4), &nl80211_packet_pattern_policy, 0, 0);
          if ( v31 )
            goto LABEL_125;
          v31 = -22;
          if ( !v93 )
            goto LABEL_125;
          if ( !v94 )
            goto LABEL_125;
          v53 = (unsigned __int16)(*v94 - 4);
          v54 = (unsigned int)(v53 + 7) >> 3;
          if ( (_DWORD)v54 != (unsigned __int16)(*v93 - 4) || v22[3] < (int)v53 || v22[4] > (int)v53 )
            goto LABEL_125;
          v55 = v95;
          if ( v95 )
            v55 = *(_DWORD *)(v95 + 4);
          if ( v55 > v22[5] )
            goto LABEL_125;
          if ( (v90 & 1) != 0 )
            goto LABEL_156;
          *(_DWORD *)(*((_QWORD *)v91 + 1) + 24LL * v48 + 20) = v55;
          v56 = (unsigned int)(v54 + v53);
          v57 = (int *)_kmalloc_noprof(v56, 3264);
          v22 = v57;
          if ( !v57 )
            goto LABEL_124;
          if ( (v90 & 1) != 0 )
            goto LABEL_156;
          *(_QWORD *)(*((_QWORD *)v91 + 1) + 24LL * v48) = v57;
          if ( v56 < v54 )
            goto LABEL_159;
          memcpy(v57, v93 + 2, (unsigned int)(v53 + 7) >> 3);
          if ( (v90 & 1) != 0 )
            goto LABEL_156;
          v58 = (char *)v22 + v54;
          *(_QWORD *)(*((_QWORD *)v91 + 1) + 24LL * v48 + 8) = (char *)v22 + v54;
          if ( v88 < 8 )
            goto LABEL_156;
          v22 = v89;
          v59 = v56 >= v54 ? v56 - v54 : 0LL;
          *(_DWORD *)(*((_QWORD *)v91 + 1) + 24LL * v48 + 16) = v53;
          if ( v59 < v53 )
            break;
          memcpy(v58, v94 + 2, v53);
          ++v48;
          v60 = (*v49 + 3) & 0x1FFFC;
          v46 -= v60;
          v49 = (unsigned __int16 *)((char *)v49 + v60);
          if ( v46 <= 3 )
            goto LABEL_103;
        }
        _fortify_panic(17, v59);
LABEL_159:
        _fortify_panic(17, (unsigned int)(v54 + v53));
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v79 = _traceiter_rdev_set_coalesce(0, v2 + 124, 0);
          v82 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v82;
          if ( !v82 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v79, v80, v81);
        }
LABEL_107:
        v62 = *((_DWORD **)*v2 + 90);
        if ( v62 )
        {
          if ( *(v62 - 1) != -172733808 )
            __break(0x8228u);
          ((void (__fastcall *)(int **, _QWORD))v62)(v2 + 124, 0);
        }
        result = 0;
        goto LABEL_11;
      }
LABEL_103:
      v28 = v83;
      v22 = v87;
      v26 = v85 + 1;
      v61 = (*v84 + 3) & 0x1FFFC;
      v25 -= v61;
      v27 = (unsigned __int16 *)((char *)v84 + v61);
      if ( (int)(v86 - v61) <= 3 )
        goto LABEL_112;
    }
    if ( v26 < 0 || v20 < v32 + 16 || v20 - (v32 + 16) < 8 )
      goto LABEL_156;
    *((_QWORD *)v91 + 1) = 0;
LABEL_124:
    v31 = -12;
LABEL_125:
    v22 = v87;
  }
  v64 = *v22;
  LODWORD(v91) = v31;
  if ( *v22 < 1 )
    goto LABEL_157;
  v65 = 0;
  v66 = v22 + 2;
  while ( 1 )
  {
    v67 = 24 * v65;
    v68 = &v66[6 * v65];
    if ( !v68 )
      goto LABEL_129;
    v69 = v67 + 24;
    if ( v67 + 24 < 0 || v20 < v67 + 24 || v20 - (v67 + 24) < 4 )
      goto LABEL_156;
    v70 = v22;
    if ( (int)v68[4] >= 1 )
      break;
LABEL_153:
    if ( v67 + 16 < 0 || v20 < v67 + 16 || v20 - (v67 + 16) < 8 )
      goto LABEL_156;
    kfree(*((_QWORD *)v68 + 1));
    v64 = *v70;
    v22 = v70;
LABEL_129:
    if ( ++v65 >= v64 )
      goto LABEL_157;
  }
  v71 = 0;
  v22 = nullptr;
  v74 = v20 < v67 + 16 || v20 - (v67 + 16) < 8 || v67 + 16 < 0;
  v34 = v20 >= v69;
  v75 = v20 - v69;
  v77 = !v34 || v75 < 4;
  while ( !v74 )
  {
    kfree(*(_QWORD *)(*((_QWORD *)v68 + 1) + v71));
    if ( (v77 & 1) != 0 )
      break;
    v22 = (int *)((char *)v22 + 1);
    v71 += 24;
    if ( (__int64)v22 >= (int)v68[4] )
      goto LABEL_153;
  }
LABEL_156:
  __break(1u);
LABEL_157:
  kfree(v22);
  result = (unsigned int)v91;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
