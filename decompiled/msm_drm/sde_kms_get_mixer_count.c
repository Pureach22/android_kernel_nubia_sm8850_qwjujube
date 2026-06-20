__int64 __fastcall sde_kms_get_mixer_count(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 v7; // x22
  __int64 v8; // x23
  unsigned __int64 v9; // x24
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x26
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  unsigned int v16; // w11
  unsigned int v17; // w10
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x11
  unsigned int v21; // w11
  unsigned int v22; // w10
  __int64 v23; // x8
  __int64 v24; // x9
  char v25; // w10
  __int64 v26; // x25
  unsigned __int64 v28; // x13
  unsigned __int64 v29; // x11
  __int64 v30; // x14
  unsigned __int64 v31; // x12
  unsigned int v32; // w15
  char v33; // w16
  char v34; // w14
  bool v35; // cf
  bool v36; // cc
  __int64 v37; // x15
  __int64 v38; // x26
  __int64 v39; // x14
  unsigned int v40; // w15
  char v41; // w13
  char v42; // w14
  char v43; // w16
  int v44; // w22
  int v45; // w23
  int v46; // w0
  void *v48; // x0

  if ( !a4 )
  {
    v48 = &unk_216361;
LABEL_73:
    printk(v48, "sde_kms_get_mixer_count");
    return 4294967274LL;
  }
  *a4 = 1;
  if ( !a1 || !a2 || !a3 )
  {
    v48 = &unk_2503C4;
    goto LABEL_73;
  }
  v7 = *(_QWORD *)(a1 + 2016) << 32;
  v8 = (unsigned __int64)*(unsigned int *)(a3 + 24) << 32;
  v9 = (unsigned __int64)*(unsigned __int16 *)(a2 + 4) << 32;
  v10 = (unsigned __int64)*(unsigned __int16 *)(a2 + 10) << 32;
  v11 = (unsigned __int64)*(unsigned __int16 *)(a2 + 20) << 32;
  v12 = drm_mode_vrefresh(a2);
  v13 = v12 << 32;
  v14 = 62;
  do
  {
    if ( ((v10 >> v14) & 1) != 0 )
      break;
    --v14;
  }
  while ( v14 );
  v15 = 62;
  do
  {
    if ( ((v11 >> v15) & 1) != 0 )
      break;
    --v15;
  }
  while ( v15 );
  v16 = v15 + v14;
  v17 = v15 + v14 - 61;
  if ( v16 <= 0x3D )
  {
    v18 = v11 * v10;
    LOBYTE(v17) = 0;
LABEL_15:
    v18 >>= 32 - (unsigned __int8)v17;
    goto LABEL_16;
  }
  v18 = (v10 >> ((v17 >> 1) + (v17 & 1))) * (v11 >> (v17 >> 1));
  if ( v17 < 0x21 )
  {
    if ( v17 == 32 )
      goto LABEL_16;
    goto LABEL_15;
  }
  v18 <<= (unsigned __int8)v16 - 93;
LABEL_16:
  v19 = 62;
  do
  {
    if ( (((unsigned __int64)v18 >> v19) & 1) != (unsigned __int64)v18 >> 63 )
      break;
    --v19;
  }
  while ( v19 );
  v20 = 62;
  do
  {
    if ( (((unsigned __int64)v13 >> v20) & 1) != (unsigned __int64)(unsigned int)v12 >> 31 )
      break;
    --v20;
  }
  while ( v20 );
  v21 = v20 + v19;
  v22 = v21 - 61;
  if ( v21 <= 0x3D )
  {
    v23 = v18 * v13;
    LOBYTE(v22) = 0;
LABEL_26:
    v23 >>= 32 - (unsigned __int8)v22;
    goto LABEL_27;
  }
  v23 = (v18 >> ((v22 >> 1) + (v22 & 1))) * (v13 >> (v22 >> 1));
  if ( v22 < 0x21 )
  {
    if ( v21 == 93 )
      goto LABEL_27;
    goto LABEL_26;
  }
  v23 <<= (unsigned __int8)v21 - 93;
LABEL_27:
  v24 = 0;
  while ( (((unsigned __int64)v23 >> ((unsigned __int8)v24 + 62)) & 1) == (unsigned __int64)v23 >> 63 )
  {
    if ( --v24 == -62 )
      goto LABEL_34;
  }
  if ( (unsigned int)(v24 + 32) >= 0xFFFFFFC2 )
  {
LABEL_34:
    v25 = 0;
    v26 = 0x10CCCCCCDLL * v23;
LABEL_35:
    v26 >>= 32 - v25;
    goto LABEL_36;
  }
  v25 = v24 + 33;
  v26 = (v23 >> (((unsigned int)(v24 + 33) >> 1) + ((v24 + 33) & 1)))
      * (0x10CCCCCCDuLL >> ((unsigned int)(v24 + 33) >> 1));
  if ( (unsigned int)v24 < 0xFFFFFFDF )
  {
    v26 <<= (unsigned __int8)v24 + 1;
    goto LABEL_36;
  }
  if ( (_DWORD)v24 != -1 )
    goto LABEL_35;
LABEL_36:
  if ( v26 <= v7 && (__int64)v9 <= v8 )
  {
    HIDWORD(v38) = HIDWORD(v26);
LABEL_62:
    if ( (_drm_debug & 4) != 0 )
    {
      v44 = *(unsigned __int16 *)(a2 + 10);
      v45 = *(unsigned __int16 *)(a2 + 20);
      v46 = drm_mode_vrefresh(a2);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[%s] h=%d v=%d fps=%d lm=%d mode_clk=%u max_clk=%llu\n",
        (const char *)(a2 + 80),
        v44,
        v45,
        v46,
        *a4,
        HIDWORD(v38),
        *(_QWORD *)(a1 + 2016));
    }
    return 0;
  }
  else
  {
    v28 = 0;
    while ( 1 )
    {
      v29 = v28 + 2;
      v30 = 62;
      v31 = (v28 + 2) << 32;
      do
      {
        if ( (((unsigned __int64)v26 >> v30) & 1) != (unsigned __int64)v26 >> 63 )
          break;
        --v30;
      }
      while ( v30 );
      v32 = 62 - v30;
      v33 = v30 - 30;
      v34 = 30 - v30;
      v35 = v32 >= 0x20;
      v36 = v32 > 0x20;
      v37 = v26 << v32;
      if ( v35 )
        v33 = 0;
      if ( !v36 )
        v34 = 0;
      v38 = (v37 / (__int64)(v31 >> v33)) >> v34;
      v39 = 62;
      do
      {
        if ( ((v9 >> v39) & 1) != 0 )
          break;
        --v39;
      }
      while ( v39 );
      if ( v28 >= 3 )
        break;
      v40 = 62 - v39;
      v41 = v39 - 30;
      v42 = 30 - v39;
      if ( v40 >= 0x20 )
        v43 = 0;
      else
        v43 = v41;
      if ( v40 <= 0x20 )
        v42 = 0;
      v28 = v29;
      if ( v38 <= v7 )
      {
        v28 = v29;
        if ( ((__int64)(v9 << v40) / (__int64)(v31 >> v43)) >> v42 <= v8 )
        {
          *a4 = v29;
          goto LABEL_62;
        }
      }
    }
    *a4 = 6;
    printk(&unk_23894F, "sde_kms_get_mixer_count");
    drm_mode_vrefresh(a2);
    printk(&unk_253DFD, "sde_kms_get_mixer_count");
    return 4294967274LL;
  }
}
