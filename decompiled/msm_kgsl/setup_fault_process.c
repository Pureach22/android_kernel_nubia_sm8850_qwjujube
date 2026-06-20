__int64 *__fastcall setup_fault_process(_QWORD *a1, __int64 a2)
{
  __int64 *v4; // x19
  unsigned int v6; // w8
  unsigned int v7; // w22
  unsigned int v13; // w9
  __int64 v14; // x8
  _DWORD *v15; // x8
  __int64 v16; // x22
  unsigned int asid; // w0
  __int64 v18; // x8
  __int64 v19; // x21
  __int64 v20; // x9
  __int64 (__fastcall *v21)(_QWORD); // x9
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x21
  __int64 *v26; // x21
  __int64 v27; // x22
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 (*v30)(void); // x8
  unsigned int v32; // w8
  unsigned int v33; // w23
  unsigned int v35; // w9

  if ( !a2 )
  {
    v4 = nullptr;
LABEL_12:
    v14 = a1[11];
    if ( v14 )
      goto LABEL_20;
LABEL_26:
    v16 = 0;
    if ( !v4 )
      goto LABEL_24;
    goto LABEL_27;
  }
  v4 = *(__int64 **)(a2 + 24);
  if ( !v4 )
    goto LABEL_12;
  _X0 = (unsigned int *)v4 + 9;
  v6 = *((_DWORD *)v4 + 9);
  if ( v6 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( v13 == v6 && __stxr(v6 + 1, _X0) );
      v7 = v6;
      if ( v13 == v6 )
        break;
      v7 = 0;
      v6 = v13;
    }
    while ( v13 );
  }
  else
  {
    v7 = 0;
  }
  if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
    refcount_warn_saturate(_X0, 0);
  if ( !v7 )
    v4 = nullptr;
  v14 = a1[11];
  if ( !v14 )
    goto LABEL_26;
LABEL_20:
  v15 = *(_DWORD **)(v14 + 24);
  if ( !v15 )
    goto LABEL_26;
  if ( *(v15 - 1) != -200603286 )
    __break(0x8228u);
  v16 = ((__int64 (__fastcall *)(_QWORD *, __int64))v15)(a1 + 7, a2);
  if ( !v4 )
  {
LABEL_24:
    if ( (a1[13] & 0x40) == 0 )
      return nullptr;
    goto LABEL_38;
  }
LABEL_27:
  asid = kgsl_mmu_pagetable_get_asid(v4[8]);
  v18 = v4[8];
  v19 = asid;
  if ( v18 && (v20 = *(_QWORD *)(v18 + 96)) != 0 && (v21 = *(__int64 (__fastcall **)(_QWORD))(v20 + 48)) != nullptr )
  {
    v22 = v4[8];
    if ( *((_DWORD *)v21 - 1) != 1831526433 )
      __break(0x8229u);
    v23 = v21(v22);
  }
  else
  {
    v23 = 0;
  }
  v24 = v19 << 48;
  if ( (int)v19 < 0 )
    v24 = 0;
  v25 = v23 | v24;
  if ( v16 == (v23 | v24) )
    return v4;
  kgsl_process_private_put(v4);
  dev_err(*a1, "snapshot: ptbase mismatch hw %llx sw %llx\n", v16, v25);
  if ( (a1[13] & 0x40) == 0 )
    return nullptr;
LABEL_38:
  raw_read_lock(&unk_3A870);
  v26 = (__int64 *)qword_3A800;
  if ( (__int64 *)qword_3A800 != &qword_3A800 )
  {
    v27 = v16 & 0xFFFFFFFFFFFFLL;
    while ( 1 )
    {
      v28 = *(v26 - 1);
      if ( !v28 )
        goto LABEL_50;
      v29 = *(_QWORD *)(v28 + 96);
      if ( !v29 )
        break;
      v30 = *(__int64 (**)(void))(v29 + 48);
      if ( v30 )
      {
        if ( *((_DWORD *)v30 - 1) != 1831526433 )
          __break(0x8228u);
        v28 = v30();
        v4 = v26 - 9;
        if ( v26 == (__int64 *)&_crc_kgsl_gpu_num_freqs )
          goto LABEL_41;
      }
      else
      {
        v28 = 0;
        v4 = v26 - 9;
        if ( v26 == (__int64 *)&_crc_kgsl_gpu_num_freqs )
          goto LABEL_41;
      }
LABEL_51:
      if ( v28 == v27 )
      {
        _X0 = (unsigned int *)v26 - 9;
        v32 = *((_DWORD *)v26 - 9);
        if ( v32 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v35 = __ldxr(_X0);
            while ( v35 == v32 && __stxr(v32 + 1, _X0) );
            v33 = v32;
            if ( v35 == v32 )
              break;
            v33 = 0;
            v32 = v35;
          }
          while ( v35 );
        }
        else
        {
          v33 = 0;
        }
        if ( (((v33 + 1) | v33) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(_X0, 0);
          if ( v33 )
            goto LABEL_67;
        }
        else if ( v33 )
        {
          goto LABEL_67;
        }
      }
LABEL_41:
      v26 = (__int64 *)*v26;
      if ( v26 == &qword_3A800 )
        goto LABEL_66;
    }
    v28 = 0;
LABEL_50:
    v4 = v26 - 9;
    if ( v26 == (__int64 *)&_crc_kgsl_gpu_num_freqs )
      goto LABEL_41;
    goto LABEL_51;
  }
LABEL_66:
  v4 = nullptr;
LABEL_67:
  raw_read_unlock(&unk_3A870);
  return v4;
}
