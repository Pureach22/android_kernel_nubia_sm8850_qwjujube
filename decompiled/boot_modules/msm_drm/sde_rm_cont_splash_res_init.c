__int64 __fastcall sde_rm_cont_splash_res_init(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 v6; // x22
  int v7; // w21
  unsigned int v8; // w23
  __int64 v9; // x28
  __int64 v10; // x8
  unsigned __int8 (__fastcall *v11)(_QWORD); // x9
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x25
  __int64 v15; // x23
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x26
  __int64 v19; // x9
  __int64 v20; // x9
  unsigned int (__fastcall *v21)(__int64, __int64, __int64); // x9
  __int64 v22; // x1
  __int64 v23; // x8
  __int64 v24; // x8
  unsigned int (__fastcall *v25)(_QWORD); // x8
  __int64 v26; // x25
  __int64 v27; // x8
  void (__fastcall *v28)(__int64, __int64, __int64); // x8
  __int64 v29; // x1
  __int64 v30; // x8
  unsigned __int64 v31; // x9
  int v32; // w10
  __int64 v33; // x8
  __int64 (__fastcall *v34)(_QWORD); // x8
  unsigned int v35; // w0
  int v36; // w25
  __int64 v37; // x22
  __int64 i; // x26
  __int64 v39; // x8
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  __int64 v50; // x8
  __int64 (__fastcall *v51)(__int64, __int64, __int64); // x8
  __int64 v52; // x2
  __int64 v53; // x8
  unsigned __int64 v54; // x9
  int v55; // w10
  __int64 v56; // x9
  unsigned __int64 v57; // x8
  int v58; // w9
  __int64 result; // x0
  void *v60; // x0
  __int64 v61; // [xsp+8h] [xbp-68h]
  __int64 v62; // [xsp+10h] [xbp-60h]
  unsigned int v63; // [xsp+1Ch] [xbp-54h]
  __int64 v64; // [xsp+20h] [xbp-50h] BYREF
  __int64 v65; // [xsp+28h] [xbp-48h]
  __int64 v66; // [xsp+30h] [xbp-40h]
  __int64 v67; // [xsp+38h] [xbp-38h] BYREF
  __int64 v68; // [xsp+40h] [xbp-30h]
  __int64 v69; // [xsp+48h] [xbp-28h]
  __int64 v70; // [xsp+50h] [xbp-20h] BYREF
  __int64 v71; // [xsp+58h] [xbp-18h]
  __int64 v72; // [xsp+60h] [xbp-10h]
  __int64 v73; // [xsp+68h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  v66 = 0;
  v64 = 0;
  if ( !a3 || !a1 || !a2 || !a4 )
  {
    v60 = &unk_27A3ED;
LABEL_86:
    printk(v60, "sde_rm_cont_splash_res_init");
    result = 4294967274LL;
    goto LABEL_83;
  }
  v6 = a3;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "mixer_count=%d, ctl_count=%d, dsc_count=%d\n", a4[1738], a4[1362], a4[2598]);
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v60 = &unk_234896;
    goto LABEL_86;
  }
  v64 = 0;
  v65 = 0;
  v66 = 0x500000000LL;
  if ( (sde_rm_get_hw_locked(a2, (__int64)&v64, 1) & 1) != 0 )
  {
    v7 = 0;
    v8 = 0;
    v61 = v6;
    v62 = v6 + 176;
    while ( 1 )
    {
      if ( v8 >= *(_DWORD *)(v6 + 8) )
        goto LABEL_82;
      v9 = *(_QWORD *)(v65 + 40);
      v10 = *(unsigned int *)(v9 + 28);
      if ( (unsigned int)v10 >= 3 )
        goto LABEL_88;
      v11 = *(unsigned __int8 (__fastcall **)(_QWORD))(v9 + 8 * v10 + 1264);
      if ( !v11 )
        break;
      v12 = *(_QWORD *)(v65 + 40);
      if ( *((_DWORD *)v11 - 1) != 1814623283 )
        __break(0x8229u);
      if ( v11(v12) )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "finding resources for display=%d ctl=%d\n", v7, *(_DWORD *)(v65 + 36) - 1);
        v63 = v8;
        v13 = v62 + 80LL * (v7 != 0);
        if ( v13 && v9 )
        {
          v72 = 0x200000000LL;
          v70 = 0;
          v71 = 0;
          v67 = 0;
          v68 = 0;
          v69 = 0xA00000000LL;
          if ( (sde_rm_get_hw_locked(a2, (__int64)&v70, 1) & 1) != 0 )
          {
            v14 = 0;
            v15 = v9 + 1408;
            while ( 1 )
            {
              if ( *(unsigned __int8 *)(v13 + 73) > 3u )
                goto LABEL_50;
              v16 = *(unsigned int *)(v9 + 28);
              if ( (unsigned int)v16 >= 3 )
                goto LABEL_88;
              v17 = v71;
              v18 = *(_QWORD *)(v71 + 40);
              if ( *(_QWORD *)(v15 + 8 * v16) )
                break;
              v19 = *(unsigned int *)(v18 + 28);
              if ( (unsigned int)v19 > 2 )
                goto LABEL_88;
              if ( *(_QWORD *)(v18 + 8 * v19 + 352) )
                break;
LABEL_23:
              if ( (sde_rm_get_hw_locked(a2, (__int64)&v70, 1) & 1) == 0 )
                goto LABEL_50;
            }
            *(_BYTE *)(v13 + 64) = 0;
            v20 = *(unsigned int *)(v9 + 28);
            if ( (unsigned int)v20 > 2 )
              goto LABEL_88;
            v21 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(v15 + 8 * v20);
            if ( v21 )
            {
              v22 = *(unsigned int *)(v17 + 36);
              if ( *((_DWORD *)v21 - 1) != -1647562398 )
                __break(0x8229u);
              v14 = v21(v9, v22, v13 + 48);
            }
            v23 = *(unsigned int *)(v18 + 28);
            if ( (unsigned int)v23 > 2 )
              goto LABEL_88;
            if ( !*(_QWORD *)(v18 + 352 + 8 * v23) )
              goto LABEL_45;
            v24 = *(unsigned int *)(v9 + 28);
            if ( (unsigned int)v24 > 2 )
              goto LABEL_88;
            v25 = *(unsigned int (__fastcall **)(_QWORD))(v9 + 1600 + 8 * v24);
            if ( v25 )
            {
              v26 = 1LL << (*(_BYTE *)(v71 + 36) - 1);
              if ( *((_DWORD *)v25 - 1) != 1814623283 )
                __break(0x8228u);
              v14 = (unsigned int)v26 & v25(v9);
              if ( v14 )
              {
                v27 = *(unsigned int *)(v18 + 28);
                if ( (unsigned int)v27 > 2 )
                  goto LABEL_88;
                v28 = *(void (__fastcall **)(__int64, __int64, __int64))(v18 + 352 + 8 * v27);
                v29 = *(unsigned int *)(v71 + 36);
                if ( *((_DWORD *)v28 - 1) != -1764326290 )
                  __break(0x8228u);
                v28(v18, v29, v13 + 48);
                goto LABEL_47;
              }
            }
            else
            {
LABEL_45:
              if ( v14 )
              {
LABEL_47:
                v30 = v71;
                v31 = *(unsigned __int8 *)(v13 + 73);
                v32 = *(_DWORD *)(v71 + 36);
                *(_BYTE *)(v13 + 73) = v31 + 1;
                if ( v31 > 3 )
                  goto LABEL_88;
                *(_BYTE *)(v13 + 36 + v31) = v32;
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "lm_cnt=%d lm_id %d pipe_cnt%ld\n",
                    *(unsigned __int8 *)(v13 + 73),
                    *(_DWORD *)(v30 + 36) - 1,
                    v14);
                goto LABEL_23;
              }
            }
            v14 = 0;
            if ( *(_BYTE *)(v13 + 64) != 1 )
              goto LABEL_23;
            goto LABEL_47;
          }
LABEL_50:
          v33 = *(unsigned int *)(v9 + 28);
          if ( (unsigned int)v33 > 2 )
            goto LABEL_88;
          v34 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8 * v33 + 1552);
          if ( v34 )
          {
            if ( *((_DWORD *)v34 - 1) != 1814623283 )
              __break(0x8228u);
            v35 = v34(v9);
            if ( v35 )
            {
              v36 = v35;
              v37 = v35;
              for ( i = 1; i != 15; ++i )
              {
                v39 = 1LL << i;
                if ( ((1LL << i) & v37) != 0 && (*(_QWORD *)(v13 + 48) & v39) == 0 && (*(_QWORD *)(v13 + 56) & v39) == 0 )
                {
                  _X9 = (unsigned __int64 *)(v13 + 48);
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v46 = __ldxr(_X9);
                  while ( __stxr(v46 | v39, _X9) );
                  _X9 = (unsigned __int64 *)(v13 + 56);
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v49 = __ldxr(_X9);
                  while ( __stxr(v49 | v39, _X9) );
                  if ( (_drm_debug & 4) != 0 )
                    _drm_dev_dbg(0, 0, 0, "pipe %d is active:0x%x but not staged\n", i, v36);
                }
              }
            }
          }
          if ( (sde_rm_get_hw_locked(a2, (__int64)&v67, 1) & 1) != 0 )
          {
            while ( 1 )
            {
              v50 = *(unsigned int *)(v9 + 28);
              if ( (unsigned int)v50 > 2 )
                break;
              v51 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v9 + 1336 + 8 * v50);
              if ( !v51 )
                goto LABEL_75;
              v52 = *(unsigned int *)(v68 + 36);
              if ( *((_DWORD *)v51 - 1) != 1939339277 )
                __break(0x8228u);
              if ( (v51(v9, 10, v52) & 1) != 0 )
              {
LABEL_75:
                v53 = v68;
                v54 = *(unsigned __int8 *)(v13 + 74);
                v55 = *(_DWORD *)(v68 + 36);
                *(_BYTE *)(v13 + 74) = v54 + 1;
                if ( v54 > 3 )
                  break;
                *(_BYTE *)(v13 + 40 + v54) = v55;
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "CTL[%d] path, using dsc[%d]\n",
                    *(_DWORD *)(v9 + 64),
                    *(_DWORD *)(v53 + 36) - 1);
              }
              if ( (sde_rm_get_hw_locked(a2, (__int64)&v67, 1) & 1) == 0 )
                goto LABEL_79;
            }
LABEL_88:
            __break(0x5512u);
          }
        }
        else
        {
          printk(&unk_27A3ED, "_sde_rm_get_hw_blk_for_cont_splash");
        }
LABEL_79:
        v56 = v65;
        v57 = *(unsigned __int8 *)(v13 + 72);
        *(_BYTE *)v13 = 1;
        v6 = v61;
        v58 = *(_DWORD *)(v56 + 36);
        *(_BYTE *)(v13 + 72) = v57 + 1;
        if ( v57 > 3 )
          goto LABEL_88;
        v8 = v63 + 1;
        *(_BYTE *)(v13 + v57 + 32) = v58;
      }
      ++v7;
      if ( (sde_rm_get_hw_locked(a2, (__int64)&v64, 1) & 1) == 0 )
        goto LABEL_82;
    }
    if ( !(_DWORD)v10 )
    {
      v60 = &unk_212664;
      goto LABEL_86;
    }
  }
LABEL_82:
  result = 0;
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
