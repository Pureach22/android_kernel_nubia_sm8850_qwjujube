__int64 __fastcall gsi_alloc_channel(_DWORD *a1, __int64 a2, _QWORD *a3)
{
  __int64 v3; // x22
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x4
  __int64 v8; // x21
  unsigned __int64 v9; // x4
  __int64 v10; // x8
  int v11; // w8
  unsigned int v12; // w9
  __int64 v13; // x9
  __int64 v14; // x1
  __int64 v15; // x0
  long double v16; // q0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x11
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x11
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x1
  int v35; // w8
  int v36; // w5
  __int64 v37; // x2
  __int64 v38; // x10
  unsigned int v40; // w9
  __int64 v41; // x9
  unsigned int v42; // w8
  __int64 v43; // x11
  unsigned int v44; // w8
  __int64 result; // x0
  __int64 v47; // x8
  unsigned int v48; // w19
  unsigned int v54; // w9
  unsigned int v56; // w9
  _QWORD v57[2]; // [xsp+0h] [xbp-10h] BYREF

  v57[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_alloc_channel", 2919);
    result = 4294967288LL;
    goto LABEL_44;
  }
  if ( !a1 || !a3 || gsi_ctx != a2 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params props=%pK dev_hdl=0x%lx chan_hdl=%pK\n",
      "gsi_alloc_channel",
      2925,
      a1,
      a2,
      a3);
    result = 4294967290LL;
    goto LABEL_44;
  }
  if ( (unsigned int)gsi_validate_channel_props(a1) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params\n", "gsi_alloc_channel", 2930);
    result = 4294967290LL;
    goto LABEL_44;
  }
  v7 = *((_QWORD *)a1 + 2);
  v8 = gsi_ctx;
  if ( v7 != -1 )
  {
    v6 = *(unsigned int *)(gsi_ctx + 28612);
    if ( v7 >= v6 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid evt ring=%lu\n", "gsi_alloc_channel", 2936, v7);
      result = 4294967290LL;
      goto LABEL_44;
    }
    if ( v7 >= 0x1F )
      goto LABEL_36;
    v6 = gsi_ctx + 18328;
    if ( *(_DWORD *)(gsi_ctx + 18328 + 328 * v7 + 308) )
    {
      v6 += 328 * v7;
      if ( *(_BYTE *)(v6 + 88) == 1 )
      {
        v6 = **(unsigned int **)(v6 + 288);
        if ( (_DWORD)v6 != 5 )
        {
          dev_err(
            *(_QWORD *)(gsi_ctx + 8),
            "%s:%d evt ring=%lu exclusively used by ch_hdl=%pK\n",
            "gsi_alloc_channel",
            2946,
            v7,
            a3);
          result = 4294967289LL;
          goto LABEL_44;
        }
      }
    }
  }
  v9 = *((unsigned __int8 *)a1 + 8);
  if ( v9 > 0x24 )
    goto LABEL_64;
  v10 = gsi_ctx + 448LL * *((unsigned __int8 *)a1 + 8);
  if ( *(_BYTE *)(v10 + 480) == 1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan %d already allocated\n", "gsi_alloc_channel", 2953, v9);
    result = 4294967288LL;
    goto LABEL_44;
  }
  v3 = v10 + 184;
  memset((void *)(v10 + 184), 0, 0x1C0u);
  v11 = *a1;
  if ( *a1 <= 0xFu && ((1 << v11) & 0x8050) != 0 )
    v12 = a1[6];
  else
    v12 = a1[7] / a1[6];
  v13 = 16LL * v12;
  if ( v11 == 5 )
    v14 = v13 + 272;
  else
    v14 = v13;
  v15 = devm_kmalloc(*(_QWORD *)(v8 + 8), v14, 3520);
  if ( !v15 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d context not allocated\n", "gsi_alloc_channel", 2977);
    result = 4294967292LL;
    goto LABEL_44;
  }
  v8 = v15;
  _mutex_init(v3 + 216, "&ctx->mlock", &gsi_alloc_channel___key, v16);
  *(_DWORD *)(v3 + 264) = 0;
  _init_swait_queue_head(v3 + 272, "&x->wait", &init_completion___key);
  *(_DWORD *)(v3 + 300) = 0;
  v22 = *((_QWORD *)a1 + 1);
  v21 = *((_QWORD *)a1 + 2);
  *(_QWORD *)v3 = *(_QWORD *)a1;
  *(_QWORD *)(v3 + 8) = v22;
  *(_QWORD *)(v3 + 16) = v21;
  v23 = *((_QWORD *)a1 + 6);
  v24 = *((_QWORD *)a1 + 3);
  v25 = *((_QWORD *)a1 + 4);
  *(_QWORD *)(v3 + 40) = *((_QWORD *)a1 + 5);
  *(_QWORD *)(v3 + 48) = v23;
  *(_QWORD *)(v3 + 24) = v24;
  *(_QWORD *)(v3 + 32) = v25;
  v26 = *((_QWORD *)a1 + 10);
  v27 = *((_QWORD *)a1 + 7);
  v28 = *((_QWORD *)a1 + 8);
  *(_QWORD *)(v3 + 72) = *((_QWORD *)a1 + 9);
  *(_QWORD *)(v3 + 80) = v26;
  *(_QWORD *)(v3 + 56) = v27;
  *(_QWORD *)(v3 + 64) = v28;
  v29 = *((_QWORD *)a1 + 14);
  v30 = *((_QWORD *)a1 + 11);
  v31 = *((_QWORD *)a1 + 12);
  *(_QWORD *)(v3 + 104) = *((_QWORD *)a1 + 13);
  *(_QWORD *)(v3 + 112) = v29;
  v32 = gsi_ctx;
  *(_QWORD *)(v3 + 88) = v30;
  *(_QWORD *)(v3 + 96) = v31;
  if ( *(_DWORD *)(v32 + 16) == 5 )
  {
    mutex_lock(v32 + 28512, v17, v18, v19, v20);
    *(_DWORD *)(v3 + 120) = 1;
    v33 = gsi_ctx + 28512;
    goto LABEL_28;
  }
  v57[0] = 0;
  mutex_lock(v32 + 28512, v17, v18, v19, v20);
  v6 = *((unsigned __int8 *)a1 + 8);
  if ( v6 > 0x23 )
  {
LABEL_64:
    do
    {
LABEL_36:
      __break(0x5512u);
LABEL_37:
      v40 = *(unsigned __int8 *)(v6 + 304);
      *(_BYTE *)(v6 + 304) = v40 + 1;
    }
    while ( v40 > 1 );
LABEL_38:
    *(_QWORD *)(v6 + 8LL * v40 + 288) = v3;
    goto LABEL_39;
  }
  v34 = *(unsigned int *)(gsi_ctx + 20);
  ++*(_QWORD *)(gsi_ctx + 56LL * *((unsigned __int8 *)a1 + 8) + 16312);
  v35 = *((unsigned __int8 *)a1 + 8);
  LODWORD(v57[0]) = 0;
  HIDWORD(v57[0]) = v35;
  ((void (__fastcall *)(__int64, __int64, _QWORD *))gsihal_write_reg_n_fields)(55, v34, v57);
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 264, 1250) )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d chan_hdl=%u timed out\n",
      "gsi_alloc_channel",
      2997,
      *((unsigned __int8 *)a1 + 8));
    v48 = -11;
LABEL_54:
    mutex_unlock(gsi_ctx + 28512);
    devm_kfree(*(_QWORD *)(gsi_ctx + 8), v8);
    result = v48;
    goto LABEL_44;
  }
  v36 = *(_DWORD *)(v3 + 120);
  if ( v36 != 1 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d chan_hdl=%u allocation failed state=%d\n",
      "gsi_alloc_channel",
      3004,
      *((unsigned __int8 *)a1 + 8),
      v36);
    v48 = -4;
    goto LABEL_54;
  }
  v33 = gsi_ctx + 28512;
LABEL_28:
  mutex_unlock(v33);
  v37 = *((_QWORD *)a1 + 2);
  if ( (unsigned __int8)(v37 - 31) <= 0xDFu )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid erindex %u\n", "gsi_alloc_channel", 3018, (unsigned __int8)v37);
    devm_kfree(*(_QWORD *)(gsi_ctx + 8), v8);
    result = 4294967290LL;
    goto LABEL_44;
  }
  if ( (unsigned __int8)v37 > 0x1Eu )
    goto LABEL_39;
  v38 = gsi_ctx;
  *(_QWORD *)(v3 + 208) = gsi_ctx + 328 * (v37 & 0x1F) + 18328;
  if ( *(unsigned __int8 *)(v38 + 328 * (v37 & 0x1F) + 18632) >= 2u )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d too many channels sharing the same event ring %u\n",
      "gsi_alloc_channel",
      3029,
      (unsigned __int8)v37);
    __break(0x800u);
    goto LABEL_59;
  }
  if ( *a1 != 5 )
  {
    _X8 = (unsigned int *)(v38 + 328 * (v37 & 0x1F) + 18636);
LABEL_59:
    __asm { PRFM            #0x11, [X8] }
    do
      v56 = __ldxr(_X8);
    while ( __stxr(v56 + 1, _X8) );
    v6 = *(_QWORD *)(v3 + 208);
    if ( *(_BYTE *)(v6 + 88) != 1 )
      goto LABEL_37;
    if ( *(_DWORD *)(v6 + 308) != 1 )
      goto LABEL_39;
    v40 = *(unsigned __int8 *)(v6 + 304);
    *(_BYTE *)(v6 + 304) = v40 + 1;
    if ( v40 < 2 )
      goto LABEL_38;
    goto LABEL_36;
  }
LABEL_39:
  gsi_program_chan_ctx(a1, *(unsigned int *)(gsi_ctx + 20));
  *(_DWORD *)(v3 + 128) = 0;
  *(_QWORD *)(v3 + 136) = *((_QWORD *)a1 + 7);
  v41 = *((_QWORD *)a1 + 5);
  *(_QWORD *)(v3 + 144) = v41;
  *(_QWORD *)(v3 + 152) = v41;
  *(_QWORD *)(v3 + 160) = v41;
  *(_QWORD *)(v3 + 168) = v41;
  *(_QWORD *)(v3 + 176) = v41;
  v42 = a1[7];
  *(_DWORD *)(v3 + 184) = v42;
  v43 = (unsigned __int8)a1[6];
  *(_BYTE *)(v3 + 188) = a1[6];
  v44 = v42 / (unsigned int)v43 - 1;
  *(_WORD *)(v3 + 190) = v44;
  *(_QWORD *)(v3 + 192) = v43 + (unsigned int)v43 * (unsigned __int64)(unsigned __int16)v44 + v41;
  if ( !*((_WORD *)a1 + 16) )
    *(_WORD *)(v3 + 32) = v44;
  *(_QWORD *)(v3 + 200) = v8;
  *a3 = *((unsigned __int8 *)a1 + 8);
  *(_BYTE *)(v3 + 296) = 1;
  *(_QWORD *)(v3 + 432) = (unsigned int)jiffies_to_msecs(jiffies);
  _X8 = (unsigned int *)(gsi_ctx + 28580);
  __asm { PRFM            #0x11, [X8] }
  do
    v54 = __ldxr(_X8);
  while ( __stxr(v54 + 1, _X8) );
  result = 0;
  if ( *a1 == 5 )
  {
    v47 = gsi_ctx + 24576;
    *(_BYTE *)(gsi_ctx + 28664) = *((_BYTE *)a1 + 8);
    *(_BYTE *)(v47 + 4089) = *((_QWORD *)a1 + 2);
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
