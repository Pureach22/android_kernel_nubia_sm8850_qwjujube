__int64 __fastcall reg_dmav1_setup_vig_igc_common(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5, __int64 a6)
{
  __int64 v11; // x8
  int v12; // w1
  int v13; // w26
  __int64 v14; // x21
  int v15; // w24
  int v16; // w28
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w25
  __int64 v19; // x8
  int *v20; // x10
  int v21; // w11
  int v22; // w12
  int v23; // w13
  int v24; // w14
  int v25; // w11
  int *v26; // x12
  __int64 (__fastcall *v27)(_QWORD); // x8
  __int64 (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x8
  int *v30; // x9
  int v31; // w10
  int v32; // w11
  int v33; // w12
  int v34; // w13
  int v35; // w10
  int *v36; // x11
  __int64 (__fastcall *v37)(_QWORD); // x8
  __int64 (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x8
  int *v40; // x9
  int v41; // w10
  int v42; // w11
  int v43; // w12
  int v44; // w13
  int v45; // w10
  int *v46; // x11
  __int64 (__fastcall *v47)(_QWORD); // x8
  int v48; // w8
  __int64 (__fastcall *v49)(_QWORD); // x9
  unsigned int v50; // w0
  int v51; // w8
  __int64 (__fastcall *v52)(_QWORD); // x9
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a3 + 56);
  v12 = *(_DWORD *)(a4 + 8);
  v54[0] = 0;
  v13 = *(_DWORD *)(*(_QWORD *)(v11 + 48) + 336LL);
  if ( v12 != 4632 )
    _drm_err("invalid size of payload len %d exp %zd\n", v12, 0x1218u);
  v14 = _kvmalloc_node_noprof(512, 0, 3520, 0xFFFFFFFFLL);
  if ( !v14 )
  {
    v18 = -12;
    goto LABEL_49;
  }
  if ( *(_DWORD *)(a3 + 28) )
  {
    printk(&unk_243701, "ctx->cap->sblk->igc_blk[0].base");
    v15 = 0;
  }
  else
  {
    v15 = sde_reg_read(a3, *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a3 + 56) + 48LL) + 328LL));
  }
  v16 = v13 + 432;
  *(_DWORD *)a2 = 1;
  *(_DWORD *)(a2 + 20) = v13 + 432;
  *(_QWORD *)(a2 + 12) = 0;
  *(_QWORD *)(a2 + 32) = v54;
  *(_QWORD *)(a2 + 40) = 0x400000000LL;
  v17 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
  LODWORD(v54[0]) = 0;
  HIDWORD(v54[0]) = v15;
  if ( *((_DWORD *)v17 - 1) != -1839634494 )
    __break(0x8228u);
  v18 = v17(a2);
  if ( v18 )
    goto LABEL_9;
  v19 = 0;
  v20 = (int *)(a6 + 12);
  do
  {
    v21 = *(v20 - 1);
    v22 = *v20;
    v23 = v20[1];
    v24 = v20[2];
    v20 += 4;
    v25 = v21 & a5 | ((v22 & a5) << 16);
    v26 = (int *)(v14 + v19);
    v19 += 8;
    *v26 = v25;
    v26[1] = v23 & a5 | ((v24 & a5) << 16);
  }
  while ( v19 != 512 );
  *(_DWORD *)(a2 + 20) = v13 + 436;
  *(_DWORD *)a2 = 3;
  *(_QWORD *)(a2 + 12) = 0;
  *(_QWORD *)(a2 + 32) = v14;
  *(_QWORD *)(a2 + 40) = 0x20000000000LL;
  v27 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
  if ( *((_DWORD *)v27 - 1) != -1839634494 )
    __break(0x8228u);
  v18 = v27(a2);
  if ( v18 )
  {
LABEL_15:
    _drm_err("lut write failed ret %d\n", v18);
    goto LABEL_16;
  }
  *(_DWORD *)(a2 + 20) = v16;
  *(_DWORD *)a2 = 1;
  *(_QWORD *)(a2 + 12) = 0;
  *(_QWORD *)(a2 + 32) = v54;
  *(_QWORD *)(a2 + 40) = 0x400000000LL;
  v28 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
  LODWORD(v54[0]) = 0;
  if ( *((_DWORD *)v28 - 1) != -1839634494 )
    __break(0x8228u);
  v18 = v28(a2);
  if ( !v18 )
  {
    v29 = 0;
    v30 = (int *)(a6 + 1044);
    do
    {
      v31 = *(v30 - 3);
      v32 = *(v30 - 2);
      v33 = *(v30 - 1);
      v34 = *v30;
      v30 += 4;
      v35 = v31 & a5 | ((v32 & a5) << 16);
      v36 = (int *)(v14 + v29);
      v29 += 8;
      *v36 = v35;
      v36[1] = v33 & a5 | ((v34 & a5) << 16);
    }
    while ( v29 != 512 );
    *(_QWORD *)(a2 + 12) = 0;
    *(_DWORD *)a2 = 3;
    *(_DWORD *)(a2 + 20) = v13 + 440;
    *(_QWORD *)(a2 + 32) = v14;
    *(_QWORD *)(a2 + 40) = 0x20000000000LL;
    v37 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
    if ( *((_DWORD *)v37 - 1) != -1839634494 )
      __break(0x8228u);
    v18 = v37(a2);
    if ( v18 )
      goto LABEL_15;
    *(_DWORD *)(a2 + 20) = v16;
    *(_DWORD *)a2 = 1;
    *(_QWORD *)(a2 + 12) = 0;
    *(_QWORD *)(a2 + 32) = v54;
    *(_QWORD *)(a2 + 40) = 0x400000000LL;
    v38 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
    LODWORD(v54[0]) = 0;
    if ( *((_DWORD *)v38 - 1) != -1839634494 )
      __break(0x8228u);
    v18 = v38(a2);
    if ( !v18 )
    {
      v39 = 0;
      v40 = (int *)(a6 + 2068);
      do
      {
        v41 = *(v40 - 3);
        v42 = *(v40 - 2);
        v43 = *(v40 - 1);
        v44 = *v40;
        v40 += 4;
        v45 = v41 & a5 | ((v42 & a5) << 16);
        v46 = (int *)(v14 + v39);
        v39 += 8;
        *v46 = v45;
        v46[1] = v43 & a5 | ((v44 & a5) << 16);
      }
      while ( v39 != 512 );
      *(_QWORD *)(a2 + 12) = 0;
      *(_DWORD *)a2 = 3;
      *(_DWORD *)(a2 + 20) = v13 + 444;
      *(_QWORD *)(a2 + 32) = v14;
      *(_QWORD *)(a2 + 40) = 0x20000000000LL;
      v47 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
      if ( *((_DWORD *)v47 - 1) != -1839634494 )
        __break(0x8228u);
      v18 = v47(a2);
      if ( !v18 )
      {
        if ( (*(_BYTE *)a6 & 1) != 0 )
          v48 = *(_DWORD *)(a6 + 3080) & 0xF | 0x10;
        else
          v48 = 0;
        *(_DWORD *)a2 = 1;
        *(_DWORD *)(a2 + 20) = v13 + 448;
        *(_QWORD *)(a2 + 12) = 0;
        *(_QWORD *)(a2 + 32) = (char *)v54 + 4;
        *(_QWORD *)(a2 + 40) = 0x400000000LL;
        v49 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
        HIDWORD(v54[0]) = v48;
        if ( *((_DWORD *)v49 - 1) != -1839634494 )
          __break(0x8229u);
        v50 = v49(a2);
        if ( v50 )
        {
          v18 = v50;
          _drm_err("dither strength failed ret %d\n", v50);
        }
        else
        {
          *(_DWORD *)(a2 + 20) = v13;
          *(_DWORD *)a2 = 5;
          *(_QWORD *)(a2 + 12) = 0;
          *(_QWORD *)(a2 + 32) = (char *)v54 + 4;
          *(_QWORD *)(a2 + 40) = 0x40001001FLL;
          if ( (v15 & 0x100) != 0 )
            v51 = 768;
          else
            v51 = v15 & 0x200 | 0x100;
          v52 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8);
          HIDWORD(v54[0]) = v51;
          if ( *((_DWORD *)v52 - 1) != -1839634494 )
            __break(0x8229u);
          v18 = v52(a2);
          if ( v18 )
            _drm_err("setting opcode failed ret %d\n", v18);
        }
        goto LABEL_16;
      }
      goto LABEL_15;
    }
  }
LABEL_9:
  _drm_err("VIG IGC index write failed ret %d\n", v18);
LABEL_16:
  kvfree(v14);
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v18;
}
