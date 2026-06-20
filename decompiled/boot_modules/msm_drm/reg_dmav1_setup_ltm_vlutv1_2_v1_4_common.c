unsigned __int64 __fastcall reg_dmav1_setup_ltm_vlutv1_2_v1_4_common(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v3; // x21
  _QWORD *v4; // x26
  const void *v7; // x1
  __int64 v8; // x23
  __int64 v9; // x4
  __int64 v10; // x25
  int *v11; // x27
  __int64 ops; // x22
  __int64 v13; // x9
  unsigned __int64 v14; // x24
  _BOOL4 v15; // w28
  __int64 v16; // x8
  int v17; // w8
  __int64 (__fastcall *v18)(_QWORD); // x9
  unsigned int v19; // w0
  __int64 (__fastcall *v20)(_QWORD); // x8
  unsigned int v21; // w0
  __int64 (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w0
  __int64 v24; // x8
  unsigned __int64 result; // x0
  __int64 v26; // x22
  __int64 v27; // x8
  void (__fastcall *v28)(_QWORD); // x9
  __int64 v29; // x0
  int v30; // w9
  __int64 v31; // x8
  __int64 (__fastcall *v32)(_QWORD); // x8
  int v33; // w0
  __int64 v34; // x8
  __int64 v35; // x5
  int v36; // w4
  int v37; // w6
  __int64 v38; // x10
  __int64 v39; // x8
  unsigned int v40; // w9
  __int64 v41; // x8
  __int64 (__fastcall *v42)(__int64 *, __int64); // x8
  __int64 v43; // x1
  int v44; // w0
  __int64 v45; // x8
  __int64 v46; // x9
  int v47; // w10
  unsigned int v48; // w22
  int v49; // w0
  __int64 (__fastcall *v50)(_QWORD); // x9
  __int64 v51; // x1
  __int64 v52; // x8
  __int64 v53; // x10
  __int64 v54; // x9
  __int64 v55; // x8
  __int64 v56; // x8
  int v57; // w11
  __int64 (__fastcall *v58)(_QWORD); // x8
  unsigned __int64 StatusReg; // x22
  __int64 v60; // x24
  __int64 v61; // [xsp+8h] [xbp-168h]
  _BOOL4 v62; // [xsp+1Ch] [xbp-154h] BYREF
  __int64 v63; // [xsp+20h] [xbp-150h] BYREF
  __int64 v64; // [xsp+28h] [xbp-148h]
  __int64 v65; // [xsp+30h] [xbp-140h]
  _QWORD v66[3]; // [xsp+38h] [xbp-138h] BYREF
  __int64 v67; // [xsp+50h] [xbp-120h]
  __int64 v68; // [xsp+58h] [xbp-118h]
  unsigned __int64 v69; // [xsp+60h] [xbp-110h]
  unsigned __int64 v70; // [xsp+68h] [xbp-108h]
  __int64 v71; // [xsp+70h] [xbp-100h] BYREF
  __int128 v72; // [xsp+78h] [xbp-F8h]
  __int64 v73; // [xsp+88h] [xbp-E8h]
  int *v74; // [xsp+90h] [xbp-E0h]
  __int64 v75; // [xsp+98h] [xbp-D8h]
  __int64 v76; // [xsp+A0h] [xbp-D0h]
  __int64 v77; // [xsp+A8h] [xbp-C8h]
  unsigned int v78; // [xsp+B4h] [xbp-BCh] BYREF
  __int64 v79; // [xsp+B8h] [xbp-B8h] BYREF
  __int64 v80; // [xsp+C0h] [xbp-B0h]
  __int64 v81; // [xsp+C8h] [xbp-A8h]
  __int64 v82; // [xsp+D0h] [xbp-A0h]
  __int64 v83; // [xsp+D8h] [xbp-98h]
  __int64 v84; // [xsp+E0h] [xbp-90h]
  __int64 v85; // [xsp+E8h] [xbp-88h]
  int v86; // [xsp+F0h] [xbp-80h]
  __int64 v87; // [xsp+F4h] [xbp-7Ch]
  int v88; // [xsp+FCh] [xbp-74h]
  int v89; // [xsp+100h] [xbp-70h]
  int v90; // [xsp+104h] [xbp-6Ch]
  __int64 v91; // [xsp+108h] [xbp-68h] BYREF
  __int128 v92; // [xsp+110h] [xbp-60h]
  __int64 v93; // [xsp+120h] [xbp-50h]
  unsigned int *v94; // [xsp+128h] [xbp-48h]
  __int64 v95; // [xsp+130h] [xbp-40h]
  __int64 v96; // [xsp+138h] [xbp-38h]
  __int64 v97; // [xsp+140h] [xbp-30h]
  _QWORD v98[2]; // [xsp+148h] [xbp-28h] BYREF
  int v99; // [xsp+158h] [xbp-18h]
  __int64 v100; // [xsp+160h] [xbp-10h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = 0;
  v77 = 0;
  v74 = nullptr;
  v75 = 0;
  v73 = 0;
  v71 = 0;
  v72 = 0u;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  memset(v66, 0, sizeof(v66));
  v63 = 0;
  v64 = 0;
  v62 = 0;
  v99 = 0;
  v98[0] = 0;
  v98[1] = 0;
  if ( a1 && a2 )
  {
    v7 = (const void *)a2[2];
    v8 = *(unsigned int *)(a1 + 64);
    v9 = *(unsigned int *)(a1 + 1496);
    if ( v7 && (unsigned int)v8 <= 4 && (unsigned int)v9 < 2 )
    {
      v10 = 16 * v8;
      if ( (unsigned __int64)(16 * v8 + 8 * v9 + 1360) > 0x7CF )
        goto LABEL_76;
      v4 = &ltm_buf[2 * v8];
      if ( v4[v9 + 170] )
      {
        if ( *a2 )
        {
          v3 = *((unsigned int *)a2 + 7);
          v11 = (int *)_kvmalloc_node_noprof(4 * v3, 0, 3520, 0xFFFFFFFFLL);
          while ( 1 )
          {
            ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
            if ( (unsigned int)reg_dmav1_setup_ltm_vlutv1_common(
                                 a1,
                                 (__int64)a2,
                                 (__int64)&v71,
                                 v11,
                                 (unsigned int *)v98) )
              break;
            if ( (_DWORD)v3 )
            {
              v13 = 4 * v3;
              v14 = 0;
              v3 = 5;
              v61 = v13;
              v15 = *((_DWORD *)a2 + 7) != 1;
              while ( v14 != 20 )
              {
                v16 = *(unsigned int *)((char *)v98 + v14);
                if ( (unsigned int)v16 > 4 )
                  break;
                HIDWORD(v72) = 0;
                *(_QWORD *)((char *)&v72 + 4) = 0;
                v17 = ltm_mapping[v16];
                v74 = nullptr;
                v75 = 0;
                v18 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
                LODWORD(v71) = 0;
                HIDWORD(v71) = v17;
                if ( *((_DWORD *)v18 - 1) != -1839634494 )
                  __break(0x8229u);
                v19 = v18(&v71);
                if ( v19 )
                {
                  _drm_err("write decode select failed ret %d\n", v19);
                  goto LABEL_56;
                }
                *(_QWORD *)((char *)&v72 + 4) = 0;
                HIDWORD(v72) = 24;
                v74 = (int *)&v62;
                v62 = v15;
                v75 = 0x4FFFFFFFCLL;
                v20 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
                LODWORD(v71) = 5;
                if ( *((_DWORD *)v20 - 1) != -1839634494 )
                  __break(0x8228u);
                v21 = v20(&v71);
                if ( v21 )
                {
                  _drm_err("write merge_ctrl failed ret %d\n", v21);
                  goto LABEL_56;
                }
                *(_QWORD *)((char *)&v72 + 4) = 0;
                HIDWORD(v72) = 4;
                LODWORD(v71) = 5;
                v74 = &v11[v14 / 4];
                v75 = 0x4FEFCFFADLL;
                v22 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
                if ( *((_DWORD *)v22 - 1) != -1839634494 )
                  __break(0x8228u);
                v23 = v22(&v71);
                if ( v23 )
                {
                  _drm_err("write opmode failed ret %d\n", v23);
                  goto LABEL_56;
                }
                v14 += 4LL;
                if ( v61 == v14 )
                {
                  v24 = a2[2];
                  v65 = 0;
                  memset(v66, 0, sizeof(v66));
                  v63 = v24;
                  v64 = 0;
                  if ( (unsigned int)v8 <= 4 )
                    goto LABEL_45;
                  break;
                }
              }
            }
            else
            {
              v34 = a2[2];
              v65 = 0;
              memset(v66, 0, sizeof(v66));
              v63 = v34;
              v64 = 0;
LABEL_45:
              v35 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v35 <= 1 )
              {
                if ( (unsigned __int64)(v10 + 8 * v35 + 1360) > 0x7CF )
                {
LABEL_76:
                  __break(1u);
                }
                else
                {
                  LODWORD(v64) = 1;
                  v36 = *(_DWORD *)(a1 + 64);
                  v37 = *(_DWORD *)(a1 + 28);
                  *(_QWORD *)((char *)&v66[1] + 4) = 0x1100000000LL;
                  v38 = a2[20];
                  v39 = v4[v35 + 170];
                  v67 = a2[19];
                  v68 = v38;
                  v40 = *((_DWORD *)a2 + 43);
                  LODWORD(v38) = *((_DWORD *)a2 + 44);
                  v65 = v39;
                  LODWORD(v39) = *((_DWORD *)a2 + 42);
                  *(_QWORD *)((char *)v66 + 4) = 0;
                  v70 = __PAIR64__(v38, v40);
                  v69 = __PAIR64__(*((_DWORD *)a2 + 7), v39);
                  sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "reg_dmav1_setup_ltm_vlutv1_2_v1_4_common",
                    5859,
                    -1,
                    v36,
                    v35,
                    v37,
                    1,
                    239);
                  v41 = *(unsigned int *)(a1 + 28);
                  if ( (unsigned int)v41 <= 2 )
                  {
                    v42 = *(__int64 (__fastcall **)(__int64 *, __int64))(ops + 8 * v41 + 16);
                    if ( v42 )
                    {
                      v43 = *(unsigned int *)(a1 + 1496);
                      if ( *((_DWORD *)v42 - 1) != 1772228465 )
                        __break(0x8228u);
                      v44 = v42(&v63, v43);
                      if ( v44 )
                        _drm_err("failed to kick off ret %d\n", v44);
                    }
                    break;
                  }
                }
              }
            }
LABEL_77:
            __break(0x5512u);
            StatusReg = _ReadStatusReg(SP_EL0);
            v60 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_ltm_vlutv1_2_v1_4_common__alloc_tag;
            v11 = (int *)_kvmalloc_node_noprof(4 * v3, 0, 3520, 0xFFFFFFFFLL);
            *(_QWORD *)(StatusReg + 80) = v60;
          }
LABEL_56:
          result = kvfree(v11);
        }
        else
        {
          LODWORD(v8) = a3;
          _drm_dev_dbg(0, 0, 1, "Disable LTM vlut feature\n");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "reg_dmav1_setup_ltm_vlutv1_2_v1_4_common",
            5807,
            -1,
            *(_DWORD *)(a1 + 64),
            *(_DWORD *)(a1 + 1496),
            *(_DWORD *)(a1 + 28),
            0,
            239);
          v26 = *(unsigned int *)(a1 + 64);
          v96 = 0;
          v97 = 0;
          v94 = nullptr;
          v95 = 0;
          v93 = 0;
          v91 = 0;
          v92 = 0u;
          v78 = 0;
          if ( (unsigned int)v26 < 5 )
          {
            result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
            if ( result )
            {
              v3 = result;
              if ( result <= 0xFFFFFFFFFFFFF000LL )
              {
                v27 = *(unsigned int *)(a1 + 1496);
                if ( (unsigned int)v27 >= 2 )
                  goto LABEL_77;
                v10 = 16 * v26;
                if ( (unsigned __int64)(16 * v26 + 8 * v27 + 1360) > 0x7D0 )
                  goto LABEL_76;
                v4 = &ltm_buf[2 * v26];
                v28 = *(void (__fastcall **)(_QWORD))(result + 64);
                v29 = v4[v27 + 170];
                if ( *((_DWORD *)v28 - 1) != -870478129 )
                  __break(0x8229u);
                v28(v29);
                v30 = ltm_mapping[v26];
                v31 = *(unsigned int *)(a1 + 1496);
                LODWORD(v91) = 0;
                v92 = 0x11u;
                v93 = 0;
                v94 = nullptr;
                v95 = 0;
                v96 = 0;
                v97 = 0;
                HIDWORD(v91) = v30;
                if ( (unsigned int)v31 > 1 )
                  goto LABEL_77;
                if ( (unsigned __int64)(v10 + 8 * v31 + 1360) > 0x7D0 )
                  goto LABEL_76;
                DWORD1(v92) = 0;
                v95 = 0;
                v93 = v4[v31 + 170];
                v94 = nullptr;
                v32 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8);
                if ( *((_DWORD *)v32 - 1) != -1839634494 )
                  __break(0x8228u);
                v33 = v32(&v91);
                if ( v33 )
                {
                  result = _drm_err("write decode select failed ret %d\n", v33);
                }
                else
                {
                  v45 = *(unsigned int *)(a1 + 64);
                  if ( (unsigned int)v45 > 4 )
                    goto LABEL_77;
                  v46 = *(unsigned int *)(a1 + 1496);
                  if ( (unsigned int)v46 > 1 )
                    goto LABEL_77;
                  if ( ((4 * v46) | (unsigned __int64)(8 * v45)) > 0x27 )
                    goto LABEL_76;
                  v47 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL);
                  ltm_vlut_ops_mask[2 * v45 + v46] &= ~8u;
                  v48 = v47 + 4;
                  if ( *(_DWORD *)(a1 + 28) )
                  {
                    printk(&unk_243701, "offset");
                    v49 = 0;
                  }
                  else
                  {
                    v49 = sde_reg_read(a1, v48);
                  }
                  *(_QWORD *)((char *)&v92 + 4) = 0;
                  HIDWORD(v92) = v48;
                  v94 = &v78;
                  v95 = 0x400000000LL;
                  v50 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8);
                  LODWORD(v91) = 1;
                  v78 = v49 & ~(_DWORD)v8 & 0xFEFF8CAD & (v49 << 31 >> 31);
                  if ( *((_DWORD *)v50 - 1) != -1839634494 )
                    __break(0x8229u);
                  result = v50(&v91);
                  if ( (_DWORD)result )
                  {
                    result = _drm_err("setting reg failed ret %d\n", result);
                  }
                  else
                  {
                    v51 = *(unsigned int *)(a1 + 1496);
                    v52 = a2[2];
                    v83 = 0;
                    v84 = 0;
                    v81 = 0;
                    v82 = 0;
                    v79 = v52;
                    v80 = 0;
                    if ( (unsigned int)v51 > 1 )
                      goto LABEL_77;
                    if ( (unsigned __int64)(v10 + 8 * v51 + 1360) > 0x7D0 )
                      goto LABEL_76;
                    v53 = a2[19];
                    LODWORD(v80) = 1;
                    v54 = *(_QWORD *)((char *)a2 + 164);
                    v85 = v53;
                    v55 = v4[v51 + 170];
                    v87 = v54;
                    LODWORD(v54) = *((_DWORD *)a2 + 43);
                    LODWORD(v53) = *((_DWORD *)a2 + 44);
                    v81 = v55;
                    v56 = *(unsigned int *)(a1 + 28);
                    LODWORD(v84) = 17;
                    v57 = *((_DWORD *)a2 + 40);
                    v89 = v54;
                    LODWORD(v54) = *((_DWORD *)a2 + 7);
                    v90 = v53;
                    v86 = v57;
                    v88 = v54;
                    if ( (unsigned int)v56 > 2 )
                      goto LABEL_77;
                    v58 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8 * v56 + 16);
                    if ( v58 )
                    {
                      if ( *((_DWORD *)v58 - 1) != 1772228465 )
                        __break(0x8228u);
                      result = v58(&v79);
                      if ( (_DWORD)result )
                        result = _drm_err("failed to kick off ret %d\n", result);
                    }
                  }
                }
              }
            }
          }
          else
          {
            result = _drm_err("invalid ltm idx %d\n", v26);
          }
        }
      }
      else
      {
        result = _drm_err("invalid dma_buf\n");
      }
    }
    else
    {
      result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v7, v8, 17, v9);
    }
  }
  else
  {
    result = _drm_err("invalid ctx %pK cfg %pK\n", (const void *)a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
