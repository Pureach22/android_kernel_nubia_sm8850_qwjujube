void __fastcall sde_encoder_phys_wb_setup_cwb(__int64 a1, char a2)
{
  __int64 v3; // x20
  __int64 v4; // x22
  unsigned int *v5; // x25
  __int64 v6; // x24
  __int64 v7; // x23
  __int64 disp_op; // x0
  __int64 v10; // x1
  __int64 v11; // x9
  _WORD *v12; // x8
  int v13; // w8
  int v14; // w9
  int v15; // w4
  _BOOL4 v16; // w10
  __int64 v17; // x8
  int v18; // w5
  unsigned int v19; // w26
  __int64 v20; // x24
  __int64 v21; // x27
  __int64 v22; // x26
  __int64 v23; // x11
  void (__fastcall *v24)(_QWORD); // x8
  int v25; // w4
  int v26; // w13
  __int64 v27; // x13
  int v28; // w13
  int *v29; // x12
  int *v30; // x13
  int v31; // w13
  int *v32; // x13
  int v33; // w13
  int v34; // w12
  __int64 v35; // x9
  int v36; // w9
  int v37; // w9
  void (__fastcall *v38)(__int64, __int64); // x9
  __int64 v39; // x1
  _QWORD *v40; // x28
  _DWORD *v41; // x8
  __int64 v42; // x2
  _DWORD *v43; // x8
  __int64 v44; // x2
  _DWORD *v45; // x8
  _DWORD *v46; // x8
  _DWORD *v47; // x8
  int v48; // w4
  __int64 v49; // x8
  int v50; // w5
  __int64 v51; // x8
  int v52; // w5
  __int64 v53; // x8
  int v54; // w8
  _QWORD v55[3]; // [xsp+10h] [xbp-70h] BYREF
  int v56; // [xsp+28h] [xbp-58h]
  int v57; // [xsp+2Ch] [xbp-54h]
  __int64 v58; // [xsp+30h] [xbp-50h]
  __int64 v59; // [xsp+38h] [xbp-48h]
  __int64 v60; // [xsp+40h] [xbp-40h]
  __int64 v61; // [xsp+48h] [xbp-38h]
  __int64 v62; // [xsp+50h] [xbp-30h]
  __int64 v63; // [xsp+58h] [xbp-28h]
  __int64 v64; // [xsp+60h] [xbp-20h]
  __int64 v65; // [xsp+68h] [xbp-18h]
  __int64 v66; // [xsp+70h] [xbp-10h]
  __int64 v67; // [xsp+78h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 2290) & 1) == 0 )
  {
    if ( (_drm_debug & 4) == 0 )
    {
LABEL_123:
      _ReadStatusReg(SP_EL0);
      return;
    }
    if ( *(_QWORD *)a1 )
    {
      v15 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_26;
    }
    else
    {
      v15 = -1;
      if ( !a1 )
        goto LABEL_26;
    }
    v17 = *(_QWORD *)(a1 + 2864);
    if ( v17 )
    {
      v18 = *(_DWORD *)(v17 + 12) - 1;
LABEL_27:
      _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] not in CWB mode. early return\n", v15, v18);
      goto LABEL_123;
    }
LABEL_26:
    v18 = -1;
    goto LABEL_27;
  }
  v3 = *(_QWORD *)(a1 + 496);
  if ( !v3
    || !*(_QWORD *)(a1 + 416)
    || (v4 = *(_QWORD *)(a1 + 2680)) == 0
    || (v5 = (unsigned int *)(v3 + 32), *(_DWORD *)(v3 + 32) >= 0xEu) )
  {
    printk(&unk_21AC7E, "_sde_encoder_phys_wb_setup_cwb");
    goto LABEL_123;
  }
  v6 = *(_QWORD *)(a1 + 2936);
  if ( *(_DWORD *)(v6 + 2192) >= 5u )
  {
    printk(&unk_27EAB7, "_sde_encoder_phys_wb_setup_cwb");
    goto LABEL_123;
  }
  v7 = *(_QWORD *)(a1 + 504);
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( (a2 & 1) != 0 )
  {
    if ( !a1 || (v11 = *(_QWORD *)(a1 + 2936)) == 0 || (v12 = *(_WORD **)(v11 + 2008)) == nullptr )
    {
      v19 = disp_op;
      printk(&unk_247128, "_sde_encoder_is_single_lm_partial_update");
      disp_op = v19;
      goto LABEL_36;
    }
    if ( *(_DWORD *)(v11 + 2192) != 2 )
    {
LABEL_36:
      v13 = 0;
      v14 = 1;
      goto LABEL_38;
    }
    if ( v12[280] )
    {
      if ( v12[281] )
      {
        if ( v12 != (_WORD *)-564LL && v12[284] )
        {
          v13 = (unsigned __int16)v12[285];
          if ( !v13 )
          {
            v14 = 1;
            goto LABEL_38;
          }
          goto LABEL_37;
        }
        goto LABEL_36;
      }
      if ( v12 == (_WORD *)-564LL )
      {
LABEL_37:
        v14 = *(_DWORD *)(v6 + 2192);
        v13 = 1;
LABEL_38:
        v16 = v13;
        if ( *(_DWORD *)(a1 + 2292) )
        {
          v14 = 2;
          v13 = 1;
          v16 = 1;
        }
        goto LABEL_40;
      }
    }
    else if ( v12 == (_WORD *)-564LL )
    {
      goto LABEL_37;
    }
    if ( v12[284] && v12[285] )
      goto LABEL_36;
    goto LABEL_37;
  }
  v14 = *(_DWORD *)(v6 + 2192);
  v13 = 0;
  v16 = (unsigned int)v14 > 1;
LABEL_40:
  v20 = *(_QWORD *)(v6 + 2208);
  if ( v20 )
  {
    if ( (unsigned int)disp_op > 2 )
      goto LABEL_125;
    v21 = (unsigned int)disp_op;
    v22 = v20 + 8LL * (unsigned int)disp_op;
    if ( *(_QWORD *)(v22 + 880) )
    {
      v23 = *(_QWORD *)(v4 + 56);
      if ( (*(_QWORD *)(v23 + 32) & 0x20000) != 0 || (*(_QWORD *)(v23 + 32) & 0x40000) != 0 )
      {
        v65 = 0;
        v66 = 0;
        v63 = 0;
        v64 = 0;
        v61 = 0;
        v62 = 0;
        v59 = 0;
        v60 = 0;
        v26 = *(_DWORD *)(v4 + 48);
        v55[2] = 0x100000000LL;
        v57 = 0;
        v58 = 0;
        v55[0] = 0;
        v55[1] = 0;
        v56 = v26;
        if ( v14 >= 1 )
        {
          v27 = 48;
          if ( (*(_QWORD *)(v23 + 32) & 0x40000LL) == 0 )
            v27 = 32;
          v28 = *(_DWORD *)(v3 + v27);
          LODWORD(v59) = 1;
          HIDWORD(v59) = v28;
          if ( v14 != 1 )
          {
            v29 = (int *)(v3 + 48);
            v30 = (int *)((*(_QWORD *)(v23 + 32) & 0x40000LL) != 0 ? v3 + 48 : v3 + 32);
            v31 = *v30;
            LODWORD(v59) = 2;
            LODWORD(v60) = v31 + 1;
            if ( v14 != 2 )
            {
              v32 = (int *)((*(_QWORD *)(v23 + 32) & 0x40000LL) != 0 ? v3 + 48 : v3 + 32);
              v33 = *v32;
              LODWORD(v59) = 3;
              HIDWORD(v60) = v33 + 2;
              if ( v14 != 3 )
              {
                if ( (*(_QWORD *)(v23 + 32) & 0x40000LL) == 0 )
                  v29 = (int *)(v3 + 32);
                v34 = *v29;
                LODWORD(v59) = 4;
                LODWORD(v61) = v34 + 3;
                if ( v14 != 4 )
                {
                  LODWORD(v59) = 5;
                  goto LABEL_125;
                }
              }
            }
          }
        }
        v35 = *(_QWORD *)(v3 + 56);
        if ( !v35 )
          v16 = 0;
        if ( v16 )
        {
          v36 = *(_DWORD *)(v35 + 32);
          v57 = 1;
          LODWORD(v58) = v36;
        }
        if ( v7 )
        {
          v37 = *(_DWORD *)(v7 + 40);
          LODWORD(v66) = v66 + 1;
          HIDWORD(v66) = v37;
        }
        v38 = *(void (__fastcall **)(__int64, __int64))(v3 + 8LL * (unsigned int)disp_op + 376);
        if ( v38 )
        {
          if ( v13 )
            v39 = 2;
          else
            v39 = 0;
          if ( *((_DWORD *)v38 - 1) != -671500202 )
            __break(0x8229u);
          v38(v3, v39);
        }
        v40 = (_QWORD *)(v4 + 8 * v21);
        v41 = (_DWORD *)v40[41];
        if ( v41 && (*(_QWORD *)(*(_QWORD *)(v4 + 56) + 32LL) & 0x20000) != 0 )
        {
          v42 = *v5;
          if ( *(v41 - 1) != 1726930563 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v41)(v4, a2 & 1, v42);
        }
        v43 = (_DWORD *)v40[44];
        if ( v43 && (*(_QWORD *)(*(_QWORD *)(v4 + 56) + 32LL) & 0x40000) != 0 )
        {
          v44 = *v5;
          if ( *(v43 - 1) != 1726930563 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v43)(v4, a2 & 1, v44);
        }
        v45 = (_DWORD *)v40[32];
        if ( v45 && (a2 & 1) == 0 )
        {
          if ( *(v45 - 1) != 1313938762 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v45)(v4, a1 + 2696, 0);
        }
        if ( v7 )
        {
          v46 = *(_DWORD **)(v7 + 8 * v21 + 48);
          if ( v46 )
          {
            if ( (a2 & 1) == 0 )
            {
              if ( *(v46 - 1) != -204335525 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, _QWORD))v46)(v7, 0, 0);
            }
          }
        }
        v47 = *(_DWORD **)(v22 + 856);
        if ( !v47 )
          goto LABEL_123;
        if ( *(v47 - 1) != -1511553041 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v47)(v20, v55, a2 & 1);
        if ( (_drm_debug & 4) == 0 )
          goto LABEL_123;
        if ( *(_QWORD *)a1 )
        {
          v48 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          if ( !a1 )
            goto LABEL_118;
        }
        else
        {
          v48 = -1;
          if ( !a1 )
            goto LABEL_118;
        }
        v51 = *(_QWORD *)(a1 + 2864);
        if ( v51 )
        {
          v52 = *(_DWORD *)(v51 + 12) - 1;
LABEL_119:
          v53 = *(_QWORD *)(v3 + 56);
          if ( v53 )
            v54 = *(_DWORD *)(v53 + 32) - 1;
          else
            v54 = -1;
          _drm_dev_dbg(
            0,
            0,
            0,
            "[enc:%d wb:%d] in CWB/DCWB mode on CTL_%d PP-%d merge3d:%d\n",
            v48,
            v52,
            *(_DWORD *)(v20 + 64) - 1,
            *(_DWORD *)(v3 + 32) - 1,
            v54);
          goto LABEL_123;
        }
LABEL_118:
        v52 = -1;
        goto LABEL_119;
      }
    }
  }
  v10 = a1 + 676;
  *(_DWORD *)(a1 + 692) = 0;
  *(_QWORD *)(a1 + 676) = 0;
  *(_QWORD *)(a1 + 684) = 0;
  *(_DWORD *)(a1 + 680) = *(_DWORD *)(v4 + 48);
  if ( !v20 )
    goto LABEL_123;
  if ( (unsigned int)disp_op <= 2 )
  {
    v24 = *(void (__fastcall **)(_QWORD))(v20 + 8LL * (unsigned int)disp_op + 904);
    if ( !v24 )
      goto LABEL_123;
    if ( *((_DWORD *)v24 - 1) != 115244286 )
      __break(0x8228u);
    v24(v20);
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_123;
    if ( *(_QWORD *)a1 )
    {
      v25 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_113;
    }
    else
    {
      v25 = -1;
      if ( !a1 )
        goto LABEL_113;
    }
    v49 = *(_QWORD *)(a1 + 2864);
    if ( v49 )
    {
      v50 = *(_DWORD *)(v49 + 12) - 1;
LABEL_114:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d wb:%d] in CWB/DCWB mode adding WB for CTL_%d\n",
        v25,
        v50,
        *(_DWORD *)(v20 + 64) - 1);
      goto LABEL_123;
    }
LABEL_113:
    v50 = -1;
    goto LABEL_114;
  }
LABEL_125:
  __break(0x5512u);
  sde_encoder_phys_wb_update_cwb_flush(disp_op, v10);
}
