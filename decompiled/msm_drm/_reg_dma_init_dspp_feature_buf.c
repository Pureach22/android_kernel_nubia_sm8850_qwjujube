__int64 __fastcall reg_dma_init_dspp_feature_buf(
        unsigned int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  __int64 v6; // x15
  __int64 v7; // d14
  __int64 v9; // x21
  __int64 v10; // x20
  unsigned __int64 v11; // x8
  __int64 result; // x0
  unsigned __int64 v13; // x9
  unsigned __int64 *v14; // x22
  _DWORD *v15; // x8
  unsigned __int64 v16; // x8
  __int64 v17; // x22
  __int64 v18; // x20
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 *v21; // x22
  _DWORD *v22; // x8
  unsigned __int64 v23; // x8
  __int64 v24; // x20
  __int64 v25; // x19
  unsigned __int64 v26; // x8
  __int64 v27; // x9
  char *v28; // x11
  __int64 *v29; // x20
  _DWORD *v30; // x8
  __int64 v31; // x0
  __int64 v32; // x21
  __int64 v33; // x20
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x9
  unsigned __int64 *v36; // x22
  _DWORD *v37; // x8
  unsigned __int64 v38; // x8
  __int64 v39; // x20
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x9
  __int64 v42; // x0
  char v43; // cc
  __int64 v44; // x21
  __int64 v45; // x20
  unsigned __int64 ops; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 *v48; // x22
  _DWORD *v49; // x8
  unsigned __int64 v50; // x8
  __int64 v51; // x22
  __int64 v52; // x20
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x9
  unsigned __int64 *v55; // x22
  _DWORD *v56; // x8
  unsigned __int64 v57; // x8
  __int64 v58; // x22
  __int64 v59; // x20
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x9
  unsigned __int64 *v62; // x22
  _DWORD *v63; // x8
  unsigned __int64 v64; // x8
  __int64 v65; // x8
  __int64 v66; // x2
  __int64 v67; // x21
  __int64 v68; // x19
  unsigned int v69; // w22
  unsigned int v70; // w20
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x9
  __int64 *v73; // x21
  _DWORD *v74; // x8
  bool v75; // zf

  switch ( a1 )
  {
    case 5u:
      v44 = *(unsigned int *)(a2 + 64);
      if ( (unsigned int)v44 > 4 )
        goto LABEL_113;
      v45 = *(unsigned int *)(a2 + 1496);
      if ( (unsigned int)v45 > 2 )
        goto LABEL_113;
      ops = sde_reg_dma_get_ops((unsigned int)v45);
      result = 4294966772LL;
      if ( !ops || ops > 0xFFFFFFFFFFFFF000LL )
        return result;
      v47 = 16 * v44 + 8 * v45 + 400;
      v48 = (unsigned __int64 *)((char *)dspp_buf + v47);
      if ( !(unsigned __int64 *)((char *)dspp_buf + v47) )
        goto LABEL_102;
      if ( v47 > 0x7CF )
        goto LABEL_114;
      if ( *v48 )
        goto LABEL_77;
      v49 = *(_DWORD **)(ops + 48);
      if ( *(v49 - 1) != 70798817 )
        __break(0x8228u);
      v50 = ((__int64 (__fastcall *)(__int64, _QWORD))v49)(560, (unsigned int)v45);
      result = 4294967274LL;
      *v48 = v50;
      if ( v50 )
      {
        if ( v50 <= 0xFFFFFFFFFFFFF000LL )
        {
LABEL_77:
          v51 = *(unsigned int *)(a2 + 64);
          if ( (unsigned int)v51 > 4 )
            goto LABEL_113;
          v52 = *(unsigned int *)(a2 + 1496);
          if ( (unsigned int)v52 > 2 )
            goto LABEL_113;
          v53 = sde_reg_dma_get_ops((unsigned int)v52);
          result = 4294966772LL;
          if ( !v53 || v53 > 0xFFFFFFFFFFFFF000LL )
            return result;
          v54 = 16 * v51 + 8 * v52 + 480;
          v55 = (unsigned __int64 *)((char *)dspp_buf + v54);
          if ( !(unsigned __int64 *)((char *)dspp_buf + v54) )
            goto LABEL_102;
          if ( v54 > 0x7CF )
            goto LABEL_114;
          if ( *v55 )
            goto LABEL_78;
          v56 = *(_DWORD **)(v53 + 48);
          if ( *(v56 - 1) != 70798817 )
            __break(0x8228u);
          v57 = ((__int64 (__fastcall *)(__int64, _QWORD))v56)(560, (unsigned int)v52);
          result = 4294967274LL;
          *v55 = v57;
          if ( v57 )
          {
            if ( v57 <= 0xFFFFFFFFFFFFF000LL )
            {
LABEL_78:
              v58 = *(unsigned int *)(a2 + 64);
              if ( (unsigned int)v58 > 4 )
                goto LABEL_113;
              v59 = *(unsigned int *)(a2 + 1496);
              if ( (unsigned int)v59 > 2 )
                goto LABEL_113;
              v60 = sde_reg_dma_get_ops((unsigned int)v59);
              result = 4294966772LL;
              if ( !v60 || v60 > 0xFFFFFFFFFFFFF000LL )
                return result;
              v61 = 16 * v58 + 8 * v59 + 560;
              v62 = (unsigned __int64 *)((char *)dspp_buf + v61);
              if ( !(unsigned __int64 *)((char *)dspp_buf + v61) )
                goto LABEL_102;
              if ( v61 > 0x7D0 )
                goto LABEL_114;
              if ( *v62 )
                goto LABEL_89;
              v63 = *(_DWORD **)(v60 + 48);
              if ( *(v63 - 1) != 70798817 )
                __break(0x8228u);
              v64 = ((__int64 (__fastcall *)(__int64, _QWORD))v63)(560, (unsigned int)v59);
              result = 4294967274LL;
              *v62 = v64;
              if ( v64 )
              {
                if ( v64 <= 0xFFFFFFFFFFFFF000LL )
                {
LABEL_89:
                  v65 = *(unsigned int *)(a2 + 64);
                  if ( (unsigned int)v65 <= 4 )
                  {
                    v66 = *(unsigned int *)(a2 + 1496);
                    if ( (unsigned int)v66 <= 2 )
                      return reg_dma_buf_init(&dspp_buf[2 * v65 + 80 + v66], 0x230u, v66);
                  }
                  goto LABEL_113;
                }
              }
            }
          }
        }
      }
      break;
    case 0x11u:
      v32 = *(unsigned int *)(a2 + 64);
      if ( (unsigned int)v32 > 4 )
        goto LABEL_113;
      v33 = *(unsigned int *)(a2 + 1496);
      if ( (unsigned int)v33 > 2 )
        goto LABEL_113;
      v34 = sde_reg_dma_get_ops((unsigned int)v33);
      result = 4294966772LL;
      if ( !v34 || v34 > 0xFFFFFFFFFFFFF000LL )
        return result;
      v35 = 16 * v32 + 8 * v33 + 1440;
      v36 = (unsigned __int64 *)((char *)dspp_buf + v35);
      if ( !(unsigned __int64 *)((char *)dspp_buf + v35) )
        goto LABEL_102;
      if ( v35 > 0x7CF )
        goto LABEL_114;
      if ( *v36 )
        goto LABEL_45;
      v37 = *(_DWORD **)(v34 + 48);
      if ( *(v37 - 1) != 70798817 )
        __break(0x8228u);
      v38 = ((__int64 (__fastcall *)(__int64, _QWORD))v37)(22368, (unsigned int)v33);
      result = 4294967274LL;
      *v36 = v38;
      if ( v38 )
      {
        if ( v38 <= 0xFFFFFFFFFFFFF000LL )
        {
LABEL_45:
          v39 = *(unsigned int *)(a2 + 64);
          if ( (unsigned int)v39 <= 4 )
          {
            v25 = *(unsigned int *)(a2 + 1496);
            if ( (unsigned int)v25 <= 2 )
            {
              v40 = sde_reg_dma_get_ops((unsigned int)v25);
              result = 4294966772LL;
              if ( !v40 || v40 > 0xFFFFFFFFFFFFF000LL )
                return result;
              v41 = 16 * v39 + 8 * v25 + 1520;
              v29 = (__int64 *)((char *)dspp_buf + v41);
              if ( (char *)dspp_buf + v41 )
              {
                if ( v41 <= 0x7CF )
                {
                  if ( !*v29 )
                  {
                    v30 = *(_DWORD **)(v40 + 48);
                    v31 = 768;
                    goto LABEL_53;
                  }
                  return 0;
                }
LABEL_114:
                __break(1u);
                *(_QWORD *)(v6 - 24) = v7;
                *(double *)(v6 - 16) = a6;
                return reg_dmav1_setup_dspp_vlutv18();
              }
LABEL_102:
              _drm_err("invalid buf\n");
              return 4294967274LL;
            }
          }
LABEL_113:
          __break(0x5512u);
          goto LABEL_114;
        }
      }
      break;
    case 0x15u:
      v9 = *(unsigned int *)(a2 + 64);
      if ( (unsigned int)v9 > 4 )
        goto LABEL_113;
      v10 = *(unsigned int *)(a2 + 1496);
      if ( (unsigned int)v10 > 2 )
        goto LABEL_113;
      v11 = sde_reg_dma_get_ops((unsigned int)v10);
      result = 4294966772LL;
      if ( !v11 || v11 > 0xFFFFFFFFFFFFF000LL )
        return result;
      v13 = 16 * v9 + 8 * v10 + 1760;
      v14 = (unsigned __int64 *)((char *)dspp_buf + v13);
      if ( !(unsigned __int64 *)((char *)dspp_buf + v13) )
        goto LABEL_102;
      if ( v13 > 0x7CF )
        goto LABEL_114;
      if ( *v14 )
        goto LABEL_25;
      v15 = *(_DWORD **)(v11 + 48);
      if ( *(v15 - 1) != 70798817 )
        __break(0x8228u);
      v16 = ((__int64 (__fastcall *)(__int64, _QWORD))v15)(1080, (unsigned int)v10);
      result = 4294967274LL;
      *v14 = v16;
      if ( v16 )
      {
        if ( v16 <= 0xFFFFFFFFFFFFF000LL )
        {
LABEL_25:
          v17 = *(unsigned int *)(a2 + 64);
          if ( (unsigned int)v17 > 4 )
            goto LABEL_113;
          v18 = *(unsigned int *)(a2 + 1496);
          if ( (unsigned int)v18 > 2 )
            goto LABEL_113;
          v19 = sde_reg_dma_get_ops((unsigned int)v18);
          result = 4294966772LL;
          if ( !v19 || v19 > 0xFFFFFFFFFFFFF000LL )
            return result;
          v20 = 16 * v17 + 8 * v18 + 1840;
          v21 = (unsigned __int64 *)((char *)dspp_buf + v20);
          if ( !(unsigned __int64 *)((char *)dspp_buf + v20) )
            goto LABEL_102;
          if ( v20 > 0x7CF )
            goto LABEL_114;
          if ( *v21 )
            goto LABEL_26;
          v22 = *(_DWORD **)(v19 + 48);
          if ( *(v22 - 1) != 70798817 )
            __break(0x8228u);
          v23 = ((__int64 (__fastcall *)(__int64, _QWORD))v22)(580, (unsigned int)v18);
          result = 4294967274LL;
          *v21 = v23;
          if ( v23 )
          {
            if ( v23 <= 0xFFFFFFFFFFFFF000LL )
            {
LABEL_26:
              v24 = *(unsigned int *)(a2 + 64);
              if ( (unsigned int)v24 <= 4 )
              {
                v25 = *(unsigned int *)(a2 + 1496);
                if ( (unsigned int)v25 <= 2 )
                {
                  v26 = sde_reg_dma_get_ops((unsigned int)v25);
                  result = 4294966772LL;
                  if ( !v26 || v26 > 0xFFFFFFFFFFFFF000LL )
                    return result;
                  v27 = 16 * v24;
                  v28 = (char *)&dspp_buf[2 * v24 + v25];
                  v29 = (__int64 *)(v28 + 1920);
                  if ( v28 != (char *)-1920LL )
                  {
                    if ( (unsigned __int64)(8 * v25 + v27 + 1920) <= 0x7CF )
                    {
                      if ( !*v29 )
                      {
                        v30 = *(_DWORD **)(v26 + 48);
                        v31 = 21028;
LABEL_53:
                        if ( *(v30 - 1) != 70798817 )
                          __break(0x8228u);
                        v42 = ((__int64 (__fastcall *)(__int64, _QWORD))v30)(v31, (unsigned int)v25);
                        v43 = (v42 != -4096) & __CFADD__(v42, 4096);
                        *v29 = v42;
LABEL_107:
                        if ( v43 )
                          v75 = 1;
                        else
                          v75 = v42 == 0;
                        if ( v75 )
                          return 4294967274LL;
                        else
                          return 0;
                      }
                      return 0;
                    }
                    goto LABEL_114;
                  }
                  goto LABEL_102;
                }
              }
              goto LABEL_113;
            }
          }
        }
      }
      break;
    default:
      if ( a1 <= 0x18 && ((0x1FFF4FFuLL >> a1) & 1) != 0 )
      {
        v67 = *(unsigned int *)(a2 + 64);
        if ( (unsigned int)v67 <= 4 )
        {
          v68 = *(unsigned int *)(a2 + 1496);
          if ( (unsigned int)v68 <= 2 )
          {
            v69 = feature_map[a1];
            v70 = feature_reg_dma_sz[a1];
            v71 = sde_reg_dma_get_ops((unsigned int)v68);
            result = 4294966772LL;
            if ( !v71 || v71 > 0xFFFFFFFFFFFFF000LL )
              return result;
            v72 = 16 * v67 + 80LL * v69 + 8 * v68;
            v73 = (__int64 *)((char *)dspp_buf + v72);
            if ( (char *)dspp_buf + v72 )
            {
              if ( v72 <= 0x7CF )
              {
                if ( !*v73 )
                {
                  v74 = *(_DWORD **)(v71 + 48);
                  if ( *(v74 - 1) != 70798817 )
                    __break(0x8228u);
                  v42 = ((__int64 (__fastcall *)(_QWORD, _QWORD))v74)(v70, (unsigned int)v68);
                  v43 = (v42 != -4096) & __CFADD__(v42, 4096);
                  *v73 = v42;
                  goto LABEL_107;
                }
                return 0;
              }
              goto LABEL_114;
            }
            goto LABEL_102;
          }
        }
      }
      goto LABEL_113;
  }
  return result;
}
