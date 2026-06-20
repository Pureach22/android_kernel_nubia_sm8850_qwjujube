__int64 __fastcall reg_dmav1_setup_ltm_vlutv1(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x26
  __int64 v3; // x27
  const void *v6; // x1
  __int64 v7; // x23
  __int64 v8; // x4
  unsigned __int64 v9; // x24
  __int64 v10; // x21
  __int64 ops; // x22
  __int64 v12; // x28
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // w8
  __int64 (__fastcall *v16)(_QWORD); // x9
  unsigned int v17; // w0
  unsigned __int64 v18; // x9
  __int64 v19; // x8
  unsigned int v20; // w9
  __int64 (__fastcall *v21)(_QWORD); // x8
  unsigned int v22; // w0
  __int64 result; // x0
  __int64 v24; // x1
  __int64 v25; // x8
  int v26; // w9
  unsigned int v27; // w20
  unsigned int v28; // w0
  int v29; // w9
  __int64 v30; // x8
  __int64 v31; // x5
  int v32; // w4
  int v33; // w6
  __int64 v34; // x10
  __int64 v35; // x8
  unsigned int v36; // w9
  __int64 v37; // x8
  __int64 (__fastcall *v38)(__int64 *, __int64); // x8
  __int64 v39; // x1
  unsigned int v40; // w0
  unsigned __int64 StatusReg; // x22
  __int64 v42; // x28
  __int64 v43; // [xsp+8h] [xbp-C8h]
  int v44; // [xsp+14h] [xbp-BCh]
  __int64 v45; // [xsp+18h] [xbp-B8h] BYREF
  __int64 v46; // [xsp+20h] [xbp-B0h]
  __int64 v47; // [xsp+28h] [xbp-A8h]
  _QWORD v48[3]; // [xsp+30h] [xbp-A0h] BYREF
  __int64 v49; // [xsp+48h] [xbp-88h]
  __int64 v50; // [xsp+50h] [xbp-80h]
  unsigned __int64 v51; // [xsp+58h] [xbp-78h]
  unsigned __int64 v52; // [xsp+60h] [xbp-70h]
  __int64 v53; // [xsp+68h] [xbp-68h] BYREF
  __int128 v54; // [xsp+70h] [xbp-60h]
  __int64 v55; // [xsp+80h] [xbp-50h]
  __int64 v56; // [xsp+88h] [xbp-48h]
  __int64 v57; // [xsp+90h] [xbp-40h]
  __int64 v58; // [xsp+98h] [xbp-38h]
  __int64 v59; // [xsp+A0h] [xbp-30h]
  _QWORD v60[2]; // [xsp+A8h] [xbp-28h] BYREF
  int v61; // [xsp+B8h] [xbp-18h]
  _BYTE v62[4]; // [xsp+BCh] [xbp-14h]
  __int64 v63; // [xsp+C0h] [xbp-10h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v55 = 0;
  v53 = 0;
  v54 = 0u;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  memset(v48, 0, sizeof(v48));
  v45 = 0;
  v46 = 0;
  v61 = 0;
  v60[0] = 0;
  v60[1] = 0;
  if ( a1 && a2 )
  {
    v6 = (const void *)a2[2];
    v7 = *(unsigned int *)(a1 + 64);
    v8 = *(unsigned int *)(a1 + 1496);
    if ( v6 && (unsigned int)v7 <= 4 && (unsigned int)v8 < 2 )
    {
      if ( (unsigned __int64)(16 * v7 + 8 * v8 + 1360) > 0x7CF )
        goto LABEL_57;
      v2 = &ltm_buf[2 * v7];
      if ( v2[v8 + 170] )
      {
        if ( *a2 )
        {
          v3 = *((unsigned int *)a2 + 7);
          v9 = 4 * v3;
          v10 = _kvmalloc_node_noprof(4 * v3, 0, 3520, 0xFFFFFFFFLL);
          while ( 1 )
          {
            ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
            if ( (unsigned int)reg_dmav1_setup_ltm_vlutv1_common(a1, a2, &v53, v10, v60) )
              break;
            if ( (_DWORD)v3 )
            {
              v12 = -20;
              v44 = *((_DWORD *)a2 + 7);
              v13 = -v3;
              v3 = -5;
              v43 = v13;
              while ( v12 )
              {
                if ( ((v3 + 5) & 0x3FFFFFFFFFFFFFFFLL) == 5 )
                  goto LABEL_57;
                v14 = *(unsigned int *)&v62[v12];
                if ( (unsigned int)v14 > 4 )
                  break;
                HIDWORD(v54) = 0;
                v15 = ltm_mapping[v14];
                *(_QWORD *)((char *)&v54 + 4) = 0;
                v56 = 0;
                v57 = 0;
                v16 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
                LODWORD(v53) = 0;
                HIDWORD(v53) = v15;
                if ( *((_DWORD *)v16 - 1) != -1839634494 )
                  __break(0x8229u);
                v17 = v16(&v53);
                if ( v17 )
                {
                  _drm_err("write decode select failed ret %d\n", v17);
                  goto LABEL_53;
                }
                v18 = v12 + 20;
                v19 = v10 + v12;
                if ( v44 == 1 )
                {
                  if ( v9 <= v18 )
                    goto LABEL_57;
                  v20 = *(_DWORD *)(v19 + 20) & 0xFFFCFFFF;
                }
                else
                {
                  if ( v9 <= v18 )
                    goto LABEL_57;
                  v20 = *(_DWORD *)(v19 + 20) | 0x10000;
                }
                *(_DWORD *)(v19 + 20) = v20;
                HIDWORD(v54) = 4;
                *(_QWORD *)((char *)&v54 + 4) = 0;
                v56 = v10 + v12 + 20;
                v57 = 0x4FEFCFFADLL;
                v21 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
                LODWORD(v53) = 5;
                if ( *((_DWORD *)v21 - 1) != -1839634494 )
                  __break(0x8228u);
                v22 = v21(&v53);
                if ( v22 )
                {
                  _drm_err("write opmode failed ret %d\n", v22);
                  goto LABEL_53;
                }
                ++v3;
                v12 += 4;
                if ( v43 + v3 == -5 )
                  goto LABEL_43;
              }
            }
            else
            {
LABEL_43:
              v30 = a2[2];
              v47 = 0;
              memset(v48, 0, sizeof(v48));
              v45 = v30;
              v46 = 0;
              v31 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v31 <= 1 )
              {
                if ( (unsigned __int64)(16 * v7 + 8 * v31 + 1360) > 0x7CF )
                {
LABEL_57:
                  __break(1u);
                }
                else
                {
                  LODWORD(v46) = 1;
                  v32 = *(_DWORD *)(a1 + 64);
                  v33 = *(_DWORD *)(a1 + 28);
                  *(_QWORD *)((char *)&v48[1] + 4) = 0x1100000000LL;
                  v34 = a2[20];
                  v35 = v2[v31 + 170];
                  v49 = a2[19];
                  v50 = v34;
                  v36 = *((_DWORD *)a2 + 43);
                  LODWORD(v34) = *((_DWORD *)a2 + 44);
                  v47 = v35;
                  LODWORD(v35) = *((_DWORD *)a2 + 42);
                  *(_QWORD *)((char *)v48 + 4) = 0;
                  v52 = __PAIR64__(v34, v36);
                  v51 = __PAIR64__(*((_DWORD *)a2 + 7), v35);
                  sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_ltm_vlutv1", 5775, -1, v32, v31, v33, 1, 239);
                  v37 = *(unsigned int *)(a1 + 28);
                  if ( (unsigned int)v37 <= 2 )
                  {
                    v38 = *(__int64 (__fastcall **)(__int64 *, __int64))(ops + 8 * v37 + 16);
                    if ( v38 )
                    {
                      v39 = *(unsigned int *)(a1 + 1496);
                      if ( *((_DWORD *)v38 - 1) != 1772228465 )
                        __break(0x8228u);
                      v40 = v38(&v45, v39);
                      if ( v40 )
                        _drm_err("failed to kick off ret %d\n", v40);
                    }
                    break;
                  }
                }
              }
            }
LABEL_58:
            __break(0x5512u);
            v9 = 4 * v3;
            StatusReg = _ReadStatusReg(SP_EL0);
            v42 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_ltm_vlutv1__alloc_tag;
            v10 = _kvmalloc_node_noprof(4 * v3, 0, 3520, 0xFFFFFFFFLL);
            *(_QWORD *)(StatusReg + 80) = v42;
          }
LABEL_53:
          result = kvfree(v10);
        }
        else
        {
          _drm_dev_dbg(0, 0, 1, "Disable LTM vlut feature\n");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "reg_dmav1_setup_ltm_vlutv1",
            5731,
            -1,
            *(_DWORD *)(a1 + 64),
            *(_DWORD *)(a1 + 1496),
            *(_DWORD *)(a1 + 28),
            0,
            239);
          v24 = *(unsigned int *)(a1 + 64);
          if ( (unsigned int)v24 < 5 )
          {
            v25 = *(unsigned int *)(a1 + 1496);
            if ( (unsigned int)v25 >= 2 )
              goto LABEL_58;
            if ( ((4 * v25) | (unsigned __int64)(8 * v24)) > 0x27 )
              goto LABEL_57;
            v26 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL);
            ltm_vlut_ops_mask[2 * v24 + v25] &= ~8u;
            v27 = v26 + 4;
            if ( *(_DWORD *)(a1 + 28) )
            {
              printk(&unk_243701, "offset");
              v28 = 0;
            }
            else
            {
              v28 = sde_reg_read(a1, v27);
            }
            if ( (v28 & 1) != 0 )
              v29 = -16806739;
            else
              v29 = 196608;
            if ( *(_DWORD *)(a1 + 28) )
              result = printk(&unk_25F249, "offset");
            else
              result = sde_reg_write(a1, v27, v29 & v28, "offset");
          }
          else
          {
            result = _drm_err("invalid ltm idx %d\n", v24);
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
      result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v6, v7, 17, v8);
    }
  }
  else
  {
    result = _drm_err("invalid ctx %pK cfg %pK\n", (const void *)a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
