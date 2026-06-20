__int64 __fastcall dump_bufinfo(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 *v3; // x26
  __int64 v4; // x1
  __int64 *v5; // x8
  void *v6; // x11
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x23
  unsigned int v16; // w8
  unsigned int v18; // w19
  unsigned int v24; // w9
  __int64 v25; // x19
  __int64 v26; // x28
  __int64 v27; // x20
  __int64 (__fastcall *v28)(_QWORD); // x8
  const char *v29; // x24
  __int64 (__fastcall *v30)(_QWORD); // x8
  const char *v31; // x25
  const char *v32; // x5
  __int64 (__fastcall *v33)(_QWORD); // x8
  char v34; // w0
  __int64 v35; // x8
  __int64 v36; // x9
  int v38; // w8
  int v39; // w0
  __int64 v40; // x9
  __int64 v41; // x8
  _QWORD *v42; // x23
  int v43; // w21
  const char **v44; // x10
  const char *v45; // x3
  int v46; // w0
  __int64 v47; // x8
  __int64 v48; // x9
  __int64 result; // x0
  __int64 v50; // x9
  __int64 v53; // [xsp+28h] [xbp-38h] BYREF
  __int64 v54; // [xsp+30h] [xbp-30h]
  __int64 v55; // [xsp+38h] [xbp-28h]
  __int64 v56; // [xsp+40h] [xbp-20h]
  __int64 v57; // [xsp+48h] [xbp-18h]
  __int64 v58; // [xsp+50h] [xbp-10h]
  __int64 v59; // [xsp+58h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[15];
  v3 = *(__int64 **)a2;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  if ( (unsigned int)ww_mutex_lock(v2, 0) )
    goto LABEL_51;
  v5 = (__int64 *)a1[1];
  v6 = &unk_112C48;
  v7 = *((unsigned int *)v5 + 12);
  v8 = *((unsigned int *)v5 + 3);
  v9 = *v5;
  v10 = *(_QWORD *)(v5[5] + 64);
  if ( a1[9] )
    v6 = (void *)a1[9];
  v11 = v3[2]
      + (int)scnprintf(
               *v3 + v3[2],
               v3[1] - v3[2],
               "%08zu\t%08x\t%08x\t%08ld\t%s\t%08lu\t%s\n",
               *a1,
               v7,
               v8,
               v9,
               a1[8],
               v10,
               v6);
  v12 = v3[1] - 1;
  v3[2] = v11;
  if ( v11 == v12 )
    goto LABEL_51;
  LODWORD(v54) = 3;
  v13 = a1[15];
  v55 = 0;
  v53 = v13;
  v14 = dma_resv_iter_first(&v53);
  if ( v14 )
  {
    v15 = v14;
    do
    {
      _X22 = (unsigned int *)(v15 + 56);
      v16 = *(_DWORD *)(v15 + 56);
      if ( v16 )
      {
        do
        {
          __asm { PRFM            #0x11, [X22] }
          do
            v24 = __ldxr(_X22);
          while ( v24 == v16 && __stxr(v16 + 1, _X22) );
          v18 = v16;
          if ( v24 == v16 )
            break;
          v18 = 0;
          v16 = v24;
        }
        while ( v24 );
      }
      else
      {
        v18 = 0;
      }
      if ( (((v18 + 1) | v18) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(v15 + 56, 0);
        if ( !v18 )
          goto LABEL_8;
      }
      else if ( !v18 )
      {
        goto LABEL_8;
      }
      v25 = v3[1];
      v26 = v3[2];
      v27 = *v3;
      v28 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v15 + 8) + 8LL);
      if ( *((_DWORD *)v28 - 1) != -352706110 )
        __break(0x8228u);
      v29 = (const char *)v28(v15);
      v30 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v15 + 8) + 16LL);
      if ( *((_DWORD *)v30 - 1) != -352706110 )
        __break(0x8228u);
      v31 = (const char *)v30(v15);
      v32 = (const char *)&unk_112C48;
      if ( (*(_QWORD *)(v15 + 48) & 1) == 0 )
      {
        v33 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v15 + 8) + 32LL);
        if ( v33 )
        {
          if ( *((_DWORD *)v33 - 1) != 1879296680 )
            __break(0x8228u);
          v34 = v33(v15);
          v32 = "un";
          if ( (v34 & 1) != 0 )
          {
            dma_fence_signal(v15);
            v32 = (const char *)&unk_112C48;
          }
        }
        else
        {
          v32 = "un";
        }
      }
      v35 = v3[2] + (int)scnprintf(v27 + v26, v25 - v26, "\tFence: %s %s %ssignalled\n", v29, v31, v32);
      v36 = v3[1] - 1;
      v3[2] = v35;
      if ( v35 == v36 )
        goto LABEL_51;
      __asm { PRFM            #0x11, [X22] }
      do
        v38 = __ldxr(_X22);
      while ( __stlxr(v38 - 1, _X22) );
      if ( v38 == 1 )
      {
        __dmb(9u);
        dma_fence_release(v15 + 56);
      }
      else if ( v38 <= 0 )
      {
        refcount_warn_saturate(v15 + 56, 3);
      }
LABEL_8:
      v15 = dma_resv_iter_next(&v53);
    }
    while ( v15 );
  }
  v39 = scnprintf(*v3 + v3[2], v3[1] - v3[2], "\tAttached Devices:\n");
  v40 = v3[1];
  v41 = v3[2] + v39;
  v3[2] = v41;
  if ( v41 == v40 - 1 )
    goto LABEL_51;
  v42 = (_QWORD *)a1[2];
  if ( v42 != a1 + 2 )
  {
    v43 = 0;
    while ( 1 )
    {
      v44 = (const char **)*(v42 - 1);
      v45 = v44[14];
      if ( !v45 )
        v45 = *v44;
      v46 = scnprintf(*v3 + v41, v40 - v41, "\t%s\n", v45);
      v40 = v3[1];
      v41 = v3[2] + v46;
      v3[2] = v41;
      if ( v41 == v40 - 1 )
        break;
      v42 = (_QWORD *)*v42;
      ++v43;
      if ( v42 == a1 + 2 )
        goto LABEL_49;
    }
LABEL_51:
    printk(&unk_113654, v4);
    result = 4294967268LL;
    goto LABEL_52;
  }
  v43 = 0;
LABEL_49:
  ww_mutex_unlock(a1[15]);
  v47 = v3[2] + (int)scnprintf(*v3 + v3[2], v3[1] - v3[2], "Total %d devices attached\n\n", v43);
  v48 = v3[1] - 1;
  v3[2] = v47;
  if ( v47 == v48 )
    goto LABEL_51;
  result = 0;
  v50 = *(_QWORD *)(a2 + 24);
  ++*(_DWORD *)(a2 + 16);
  *(_QWORD *)(a2 + 24) = v50 + *a1;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
