size_t __fastcall reg_dmav1_setup_dspp_memcol_protv17(__int64 a1, _QWORD *a2)
{
  const void *v4; // x1
  __int64 v5; // x2
  unsigned int v6; // w4
  __int64 *v7; // x8
  int v8; // w1
  __int64 v9; // x9
  int v10; // w8
  size_t result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  __int64 v16; // x0
  size_t v17; // x21
  __int64 v18; // x8
  __int64 v19; // x9
  unsigned __int64 *v20; // x8
  void (__fastcall *v21)(_QWORD); // x9
  unsigned __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 (__fastcall *v25)(_QWORD); // x8
  unsigned int v26; // w0
  __int64 v27; // x8
  __int64 (__fastcall *v28)(_QWORD); // x9
  unsigned int v29; // w0
  unsigned int v30; // w8
  __int64 v31; // x10
  int v32; // w9
  int v33; // w9
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x12
  int v37; // w6
  unsigned int v38; // w11
  unsigned __int64 v39; // x10
  unsigned int v40; // w11
  __int64 v41; // x8
  __int64 (__fastcall *v42)(__int64 *, __int64); // x8
  __int64 v43; // x1
  int v44; // [xsp+14h] [xbp-9Ch] BYREF
  __int64 v45; // [xsp+18h] [xbp-98h] BYREF
  __int64 v46; // [xsp+20h] [xbp-90h]
  unsigned __int64 v47; // [xsp+28h] [xbp-88h]
  __int64 v48; // [xsp+30h] [xbp-80h]
  __int64 v49; // [xsp+38h] [xbp-78h]
  __int64 v50; // [xsp+40h] [xbp-70h]
  __int64 v51; // [xsp+48h] [xbp-68h]
  unsigned __int64 v52; // [xsp+50h] [xbp-60h]
  unsigned __int64 v53; // [xsp+58h] [xbp-58h]
  unsigned __int64 v54; // [xsp+60h] [xbp-50h]
  __int64 v55; // [xsp+68h] [xbp-48h] BYREF
  __int128 v56; // [xsp+70h] [xbp-40h]
  unsigned __int64 v57; // [xsp+80h] [xbp-30h]
  int *v58; // [xsp+88h] [xbp-28h]
  __int64 v59; // [xsp+90h] [xbp-20h]
  __int64 v60; // [xsp+98h] [xbp-18h]
  __int64 v61; // [xsp+A0h] [xbp-10h]
  __int64 v62; // [xsp+A8h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  v61 = 0;
  v58 = nullptr;
  v59 = 0;
  v57 = 0;
  v55 = 0;
  v56 = 0u;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v44 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid param ctx %pK cfg %pK\n", (const void *)a1, a2);
    goto LABEL_37;
  }
  v4 = (const void *)a2[2];
  v5 = *(unsigned int *)(a1 + 64);
  v6 = *(_DWORD *)(a1 + 1496);
  if ( !v4 || (unsigned int)v5 > 4 || v6 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v4, v5, 8, v6);
    goto LABEL_37;
  }
  if ( &dspp_buf[2 * v5] == (unsigned __int64 *)-640LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_37;
  }
  v7 = (__int64 *)*a2;
  *((_DWORD *)a2 + 40) = a2[20] & 0xFF0F0FFF | 0x701000;
  if ( !v7 )
  {
    v12 = _drm_dev_dbg(0, 0, 1, "disable memcolor prot feature\n");
    reg_dma_dspp_memcol_off(a1, (__int64)a2, 8u, v12, v13, v14, v15);
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "reg_dmav1_setup_dspp_memcol_protv17",
               3244,
               -1,
               *(_DWORD *)(a1 + 64),
               *(_DWORD *)(a1 + 1496),
               *(_DWORD *)(a1 + 28),
               0,
               239);
    goto LABEL_37;
  }
  v8 = *((_DWORD *)a2 + 2);
  if ( v8 != 48 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v8, 0x30u);
    goto LABEL_37;
  }
  v9 = *v7;
  if ( !*v7 )
    goto LABEL_12;
  v10 = ((_DWORD)v9 << 15) & 0x40000 | ((v9 & 7) << 22) | ((((unsigned int)v9 >> 4) & 1) << 17);
  if ( (v9 & 0x20) != 0 )
  {
    v10 |= 8u;
  }
  else if ( !v10 )
  {
LABEL_12:
    result = _drm_err("Invalid memcolor prot config 0x%x\n", 0);
    goto LABEL_37;
  }
  v16 = *(unsigned int *)(a1 + 1496);
  v44 = v10 | 0x100000;
  result = sde_reg_dma_get_ops(v16);
  if ( result )
  {
    v17 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v18 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v18 < 5 )
      {
        v19 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v19 <= 1 )
        {
          if ( ((16 * v18) | (8 * v19) | 0x280uLL) > 0x7D0 )
            goto LABEL_49;
          v20 = &dspp_buf[2 * v18 + v19];
          v21 = *(void (__fastcall **)(_QWORD))(result + 64);
          v22 = v20[80];
          if ( *((_DWORD *)v21 - 1) != -870478129 )
            __break(0x8229u);
          v21(v22);
          v23 = *(unsigned int *)(a1 + 64);
          v55 = 0;
          v56 = 0u;
          v57 = 0;
          v58 = nullptr;
          v59 = 0;
          v60 = 0;
          v61 = 0;
          if ( (unsigned int)v23 <= 4 )
          {
            v24 = *(unsigned int *)(a1 + 1496);
            HIDWORD(v55) = dspp_mapping[v23];
            LODWORD(v56) = 8;
            if ( (unsigned int)v24 <= 1 )
            {
              if ( ((16 * v23) | (8 * v24) | 0x280uLL) > 0x7D0 )
                goto LABEL_49;
              HIDWORD(v56) = 0;
              DWORD1(v56) = 0;
              v59 = 0;
              v57 = dspp_buf[2 * v23 + 80 + v24];
              v58 = nullptr;
              v25 = *(__int64 (__fastcall **)(_QWORD))(v17 + 8);
              if ( *((_DWORD *)v25 - 1) != -1839634494 )
                __break(0x8228u);
              v26 = v25(&v55);
              if ( v26 )
              {
                result = _drm_err("write decode select failed ret %d\n", v26);
                goto LABEL_37;
              }
              v27 = *(_QWORD *)(a1 + 72);
              *(_QWORD *)((char *)&v56 + 4) = 0;
              HIDWORD(v56) = *(_DWORD *)(*(_QWORD *)(v27 + 48) + 128LL);
              v58 = &v44;
              v59 = 0x4FE39FFF7LL;
              v28 = *(__int64 (__fastcall **)(_QWORD))(v17 + 8);
              LODWORD(v55) = 5;
              if ( *((_DWORD *)v28 - 1) != -1839634494 )
                __break(0x8229u);
              v29 = v28(&v55);
              if ( v29 )
              {
                result = _drm_err("setting opcode failed ret %d\n", v29);
                goto LABEL_37;
              }
              v30 = *((_DWORD *)a2 + 44);
              if ( v30 <= 4 )
              {
                v31 = a2[2];
                v32 = hfi_dspp_idx_map[v30];
                v47 = 0;
                v48 = 0;
                v49 = 0;
                v50 = 0;
                v33 = v32 | 1;
                v45 = v31;
                v46 = 0;
                *((_DWORD *)a2 + 42) = v33;
                v34 = *(unsigned int *)(a1 + 64);
                if ( (unsigned int)v34 <= 4 )
                {
                  v35 = *(unsigned int *)(a1 + 1496);
                  if ( (unsigned int)v35 <= 1 )
                  {
                    if ( ((16 * v34) | (8 * v35) | 0x280uLL) <= 0x7D0 )
                    {
                      v36 = a2[19];
                      LODWORD(v46) = 1;
                      v37 = *(_DWORD *)(a1 + 28);
                      LODWORD(v50) = 8;
                      v51 = v36;
                      v38 = *((_DWORD *)a2 + 40);
                      LODWORD(v36) = *((_DWORD *)a2 + 41);
                      v39 = dspp_buf[2 * v34 + 80 + v35];
                      LODWORD(v49) = 0;
                      v52 = __PAIR64__(v36, v38);
                      v40 = *((_DWORD *)a2 + 43);
                      v47 = v39;
                      v54 = __PAIR64__(v30, v40);
                      v53 = __PAIR64__(*((_DWORD *)a2 + 7), v33);
                      result = sde_evtlog_log(
                                 sde_dbg_base_evtlog,
                                 "reg_dmav1_setup_dspp_memcol_protv17",
                                 3309,
                                 -1,
                                 v34,
                                 v35,
                                 v37,
                                 1,
                                 239);
                      v41 = *(unsigned int *)(a1 + 28);
                      if ( (unsigned int)v41 <= 2 )
                      {
                        v42 = *(__int64 (__fastcall **)(__int64 *, __int64))(v17 + 8 * v41 + 16);
                        if ( v42 )
                        {
                          v43 = *(unsigned int *)(a1 + 1496);
                          if ( *((_DWORD *)v42 - 1) != 1772228465 )
                            __break(0x8228u);
                          result = v42(&v45, v43);
                          if ( (_DWORD)result )
                            result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
                        }
                        goto LABEL_37;
                      }
                      goto LABEL_48;
                    }
LABEL_49:
                    __break(1u);
                    JUMPOUT(0x24B09C);
                  }
                }
              }
            }
          }
        }
      }
LABEL_48:
      __break(0x5512u);
      goto LABEL_49;
    }
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
