__int64 __fastcall ctx_print(__int64 a1)
{
  __int64 v2; // x27
  int v3; // w21
  __int64 v4; // x20
  const char *v5; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w6
  __int64 v9; // x23
  int v10; // w8
  const char *v11; // x3
  __int64 v12; // x21
  char *v13; // x9
  __int64 v14; // x26
  __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x22
  int v18; // w8
  unsigned __int64 v19; // x21
  __int64 v20; // x2
  __int64 v21; // x2
  __int64 v22; // x2
  __int64 v23; // x2
  __int64 v24; // x2
  __int64 v25; // x2
  __int64 v26; // x2
  __int64 v27; // x2
  __int64 v28; // x2
  unsigned __int64 v29; // x25
  __int64 *v30; // x20
  __int64 *j; // x22
  __int64 *v32; // t1
  __int64 v34; // x22
  unsigned int v35; // w8
  unsigned int v37; // w23
  unsigned int v43; // w9
  int v44; // w8
  unsigned __int64 v45; // x8
  unsigned __int64 i; // x23
  __int64 v47; // x8
  int v48; // w2
  __int64 v49; // x26
  __int64 v50; // x28
  __int64 v51; // x21
  __int64 v52; // x26
  int v53; // w2
  int v54; // w28
  __int64 v55; // x8
  __int64 v56; // x0
  const char *v57; // x1
  __int64 v58; // x2
  __int64 v59; // x26
  int v60; // w8
  unsigned __int64 v61; // x23
  __int64 v62; // x2
  __int64 v63; // x2
  __int64 v64; // x2
  __int64 v65; // x26
  int v66; // w8
  unsigned __int64 v67; // x23
  __int64 v68; // x2
  __int64 v69; // x2
  __int64 v70; // x2
  __int64 v71; // x2
  __int64 v72; // x2
  __int64 v73; // x2
  int v75; // w8
  __int64 v76; // [xsp+8h] [xbp-28h]
  __int64 v77; // [xsp+10h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_DWORD *)(v2 + 4);
  v4 = v2;
  v5 = kgsl_context_type(*(_DWORD *)(v2 + 400));
  v6 = *(_QWORD *)(v2 + 24);
  v7 = *(_QWORD *)(v6 + 8);
  if ( v7 )
    v8 = *(_DWORD *)(v7 + 112);
  else
    v8 = 0;
  seq_printf(
    a1,
    "id: %u type: %s priority: %d process: %s (%d) tid: %d\n",
    v3,
    v5,
    *(_DWORD *)(v2 + 8),
    (const char *)(v6 + 16),
    v8,
    *(_DWORD *)(v2 + 12));
  seq_write(a1, "flags: ", 7);
  v9 = 0;
  v10 = 1;
  v11 = "NO_GMEM_ALLOC";
  v12 = *(_DWORD *)(v2 + 200) & 0xFE0F0FFF;
  do
  {
    v14 = *(_QWORD *)((char *)&unk_173A70 + v9);
    if ( (v14 & v12) != 0 )
    {
      if ( v10 )
        v15 = 0;
      else
        v15 = 124;
      seq_printf(a1, "%c%s", v15, v11);
      v10 = 0;
      v12 &= ~v14;
    }
    v13 = (char *)&unk_173A70 + v9;
    v9 += 16;
    v11 = *((const char **)v13 + 3);
  }
  while ( v9 != 224 );
  if ( v12 )
  {
    if ( v10 )
      v16 = 0;
    else
      v16 = 124;
    seq_printf(a1, "%c0x%lx", v16, v12);
  }
  else if ( v10 )
  {
    seq_write(a1, "None", 4);
  }
  seq_write(a1, " priv: ", 7);
  v17 = *(_QWORD *)(v2 + 32);
  if ( (v17 & 1) != 0 )
  {
    seq_printf(a1, "%c%s", 0, "submitted");
    v18 = 0;
    v19 = v17 & 0xFFFFFFFFFFFFFFFELL;
    if ( (v17 & 2) == 0 )
      goto LABEL_26;
  }
  else
  {
    v18 = 1;
    v19 = *(_QWORD *)(v2 + 32);
    if ( (v17 & 2) == 0 )
      goto LABEL_26;
  }
  if ( (v17 & 1) != 0 )
    v20 = 124;
  else
    v20 = 0;
  seq_printf(a1, "%c%s", v20, "detached");
  v18 = 0;
  v19 &= ~2uLL;
LABEL_26:
  if ( (v19 & 4) != 0 )
  {
    if ( v18 )
      v22 = 0;
    else
      v22 = 124;
    seq_printf(a1, "%c%s", v22, "invalid");
    v18 = 0;
    v19 &= ~4uLL;
    if ( (v19 & 8) == 0 )
    {
LABEL_28:
      if ( (v19 & 0x10000) == 0 )
        goto LABEL_29;
      goto LABEL_46;
    }
  }
  else if ( (v19 & 8) == 0 )
  {
    goto LABEL_28;
  }
  if ( v18 )
    v23 = 0;
  else
    v23 = 124;
  seq_printf(a1, "%c%s", v23, "pagefault");
  v18 = 0;
  v19 &= ~8uLL;
  if ( (v19 & 0x10000) == 0 )
  {
LABEL_29:
    if ( (v19 & 0x20000) == 0 )
      goto LABEL_30;
    goto LABEL_50;
  }
LABEL_46:
  if ( v18 )
    v24 = 0;
  else
    v24 = 124;
  seq_printf(a1, "%c%s", v24, "fault");
  v18 = 0;
  v19 &= ~0x10000uLL;
  if ( (v19 & 0x20000) == 0 )
  {
LABEL_30:
    if ( (v19 & 0x40000) == 0 )
      goto LABEL_31;
    goto LABEL_54;
  }
LABEL_50:
  if ( v18 )
    v25 = 0;
  else
    v25 = 124;
  seq_printf(a1, "%c%s", v25, "gpu_hang");
  v18 = 0;
  v19 &= ~0x20000uLL;
  if ( (v19 & 0x40000) == 0 )
  {
LABEL_31:
    if ( (v19 & 0x80000) == 0 )
      goto LABEL_32;
    goto LABEL_58;
  }
LABEL_54:
  if ( v18 )
    v26 = 0;
  else
    v26 = 124;
  seq_printf(a1, "%c%s", v26, "gpu_hang_ft");
  v18 = 0;
  v19 &= ~0x40000uLL;
  if ( (v19 & 0x80000) == 0 )
  {
LABEL_32:
    if ( (v19 & 0x100000) == 0 )
      goto LABEL_33;
LABEL_62:
    if ( v18 )
      v28 = 0;
    else
      v28 = 124;
    seq_printf(a1, "%c%s", v28, "force_preamble");
    v18 = 0;
    v19 &= ~0x100000uLL;
    if ( v19 )
      goto LABEL_34;
    goto LABEL_66;
  }
LABEL_58:
  if ( v18 )
    v27 = 0;
  else
    v27 = 124;
  seq_printf(a1, "%c%s", v27, "skip_end_of_frame");
  v18 = 0;
  v19 &= ~0x80000uLL;
  if ( (v19 & 0x100000) != 0 )
    goto LABEL_62;
LABEL_33:
  if ( v19 )
  {
LABEL_34:
    if ( v18 )
      v21 = 0;
    else
      v21 = 124;
    seq_printf(a1, "%c0x%lx", v21, v19);
    goto LABEL_68;
  }
LABEL_66:
  if ( v18 )
    seq_write(a1, "None", 4);
LABEL_68:
  seq_putc(a1, 10);
  seq_write(a1, "timestamps: ", 12);
  kgsl_readtimestamp(*(_QWORD *)(v2 + 40));
  kgsl_readtimestamp(*(_QWORD *)(v2 + 40));
  kgsl_readtimestamp(*(_QWORD *)(v2 + 40));
  seq_printf(a1, "queued: %u consumed: %u retired: %u global:%u\n", 0, 0, 0, *(_DWORD *)(v2 + 396));
  seq_write(a1, "drawqueue:\n", 11);
  v76 = v2;
  raw_spin_lock(v2 + 404);
  v29 = *(unsigned int *)(v2 + 1432);
  if ( v29 != *(_DWORD *)(v2 + 1436) )
  {
    v77 = v2 + 408;
    do
    {
      if ( v29 >= 0x80 )
        __break(0x5512u);
      v34 = *(_QWORD *)(v77 + 8 * v29);
      _X27 = (unsigned int *)(v34 + 32);
      v35 = *(_DWORD *)(v34 + 32);
      if ( v35 )
      {
        do
        {
          __asm { PRFM            #0x11, [X27] }
          do
            v43 = __ldxr(_X27);
          while ( v43 == v35 && __stxr(v35 + 1, _X27) );
          v37 = v35;
          if ( v43 == v35 )
            break;
          v37 = 0;
          v35 = v43;
        }
        while ( v43 );
      }
      else
      {
        v37 = 0;
      }
      if ( (((v37 + 1) | v37) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X27, 0);
        if ( v37 )
        {
LABEL_88:
          v44 = *(_DWORD *)(v34 + 16);
          if ( v44 == 1 )
          {
            v56 = a1;
            v57 = " cmdobj ";
            v58 = 8;
          }
          else
          {
            if ( v44 != 2 )
            {
              if ( v44 == 4 )
              {
                seq_write(a1, " syncobj ", 9);
                v45 = *(unsigned int *)(v34 + 64);
                if ( (_DWORD)v45 )
                {
                  for ( i = 0; i < v45; ++i )
                  {
                    if ( i <= 0x1F && ((*(_QWORD *)(v34 + 72) >> i) & 1) != 0 )
                    {
                      v47 = *(_QWORD *)(v34 + 56) + 120 * i;
                      v48 = *(_DWORD *)(v47 + 4);
                      if ( v48 == 2 )
                      {
                        v52 = *(_QWORD *)(v47 + 48);
                        if ( v52 )
                        {
                          v53 = *(_DWORD *)(v52 + 8);
                          if ( v53 )
                          {
                            v54 = 1;
                            v55 = *(_QWORD *)(v47 + 48);
                            do
                            {
                              seq_printf(a1, "timeline: %d seqno: %lld", v53, *(_QWORD *)v55);
                              v55 = v52 + 16LL * v54++;
                              v53 = *(_DWORD *)(v55 + 8);
                            }
                            while ( v53 );
                          }
                        }
                      }
                      else if ( v48 == 1 )
                      {
                        v49 = *(_QWORD *)(v47 + 48);
                        if ( v49 && *(int *)(v49 + 8) >= 1 )
                        {
                          v50 = 0;
                          v51 = 0;
                          do
                          {
                            seq_printf(a1, "sync: %s", (const char *)(*(_QWORD *)v49 + v50));
                            ++v51;
                            v50 += 74;
                          }
                          while ( v51 < *(int *)(v49 + 8) );
                        }
                      }
                      else if ( v48 )
                      {
                        seq_printf(a1, "sync: type: %d", v48);
                      }
                      else
                      {
                        seq_printf(
                          a1,
                          "sync: ctx: %u ts: %u",
                          *(_DWORD *)(*(_QWORD *)(v47 + 16) + 4LL),
                          *(_DWORD *)(v47 + 24));
                      }
                      seq_putc(a1, 10);
                      v45 = *(unsigned int *)(v34 + 64);
                    }
                  }
                }
              }
              goto LABEL_134;
            }
            v56 = a1;
            v57 = " markerobj ";
            v58 = 11;
          }
          seq_write(v56, v57, v58);
          seq_printf(a1, "\t %u ", *(_DWORD *)(v34 + 20));
          seq_write(a1, " priv: ", 7);
          v59 = *(_QWORD *)(v34 + 56);
          if ( (v59 & 1) != 0 )
          {
            seq_printf(a1, "%c%s", 0, "skip");
            v60 = 0;
            v61 = v59 & 0xFFFFFFFFFFFFFFFELL;
            if ( (v59 & 2) == 0 )
              goto LABEL_122;
          }
          else
          {
            v60 = 1;
            v61 = *(_QWORD *)(v34 + 56);
            if ( (v59 & 2) == 0 )
              goto LABEL_122;
          }
          if ( (v59 & 1) != 0 )
            v62 = 124;
          else
            v62 = 0;
          seq_printf(a1, "%c%s", v62, "force_preamble");
          v60 = 0;
          v61 &= ~2uLL;
LABEL_122:
          if ( (v61 & 4) != 0 )
          {
            if ( v60 )
              v64 = 0;
            else
              v64 = 124;
            seq_printf(a1, "%c%s", v64, "wait_for_idle");
            v60 = 0;
            v61 &= ~4uLL;
            if ( v61 )
              goto LABEL_124;
          }
          else if ( v61 )
          {
LABEL_124:
            if ( v60 )
              v63 = 0;
            else
              v63 = 124;
            seq_printf(a1, "%c0x%lx", v63, v61);
            goto LABEL_134;
          }
          if ( v60 )
            seq_write(a1, "None", 4);
LABEL_134:
          seq_write(a1, " flags: ", 8);
          v65 = *(_QWORD *)(v34 + 24);
          if ( (v65 & 2) != 0 )
          {
            seq_printf(a1, "%c%s", 0, "MARKER");
            v66 = 0;
            v67 = v65 & 0xFFFFFFFFFFFFFFFDLL;
            if ( (v65 & 8) == 0 )
              goto LABEL_142;
          }
          else
          {
            v66 = 1;
            v67 = *(_QWORD *)(v34 + 24);
            if ( (v65 & 8) == 0 )
              goto LABEL_142;
          }
          if ( (v65 & 2) != 0 )
            v68 = 124;
          else
            v68 = 0;
          seq_printf(a1, "%c%s", v68, "CTX_SWITCH");
          v66 = 0;
          v67 &= ~8uLL;
LABEL_142:
          if ( (v67 & 0x400) != 0 )
          {
            if ( v66 )
              v70 = 0;
            else
              v70 = 124;
            seq_printf(a1, "%c%s", v70, "SYNC");
            v66 = 0;
            v67 &= ~0x400uLL;
            if ( (v67 & 0x100) != 0 )
              goto LABEL_155;
LABEL_144:
            if ( (v67 & 0x800) == 0 )
              goto LABEL_145;
LABEL_159:
            if ( v66 )
              v72 = 0;
            else
              v72 = 124;
            seq_printf(a1, "%c%s", v72, "PWR_CONSTRAINT");
            v66 = 0;
            v67 &= ~0x800uLL;
            if ( (v67 & 4) != 0 )
              goto LABEL_163;
LABEL_146:
            if ( v67 )
              goto LABEL_147;
LABEL_167:
            if ( v66 )
              seq_write(a1, "None", 4);
          }
          else
          {
            if ( (v67 & 0x100) == 0 )
              goto LABEL_144;
LABEL_155:
            if ( v66 )
              v71 = 0;
            else
              v71 = 124;
            seq_printf(a1, "%c%s", v71, "EOF");
            v66 = 0;
            v67 &= ~0x100uLL;
            if ( (v67 & 0x800) != 0 )
              goto LABEL_159;
LABEL_145:
            if ( (v67 & 4) == 0 )
              goto LABEL_146;
LABEL_163:
            if ( v66 )
              v73 = 0;
            else
              v73 = 124;
            seq_printf(a1, "%c%s", v73, "IB_LIST");
            v66 = 0;
            v67 &= ~4uLL;
            if ( !v67 )
              goto LABEL_167;
LABEL_147:
            if ( v66 )
              v69 = 0;
            else
              v69 = 124;
            seq_printf(a1, "%c0x%lx", v69, v67);
          }
          if ( v34 )
          {
            __asm { PRFM            #0x11, [X27] }
            do
              v75 = __ldxr(_X27);
            while ( __stlxr(v75 - 1, _X27) );
            if ( v75 == 1 )
            {
              __dmb(9u);
              kgsl_drawobj_destroy_object((__int64)_X27);
            }
            else if ( v75 <= 0 )
            {
              refcount_warn_saturate(_X27, 3);
            }
          }
          seq_putc(a1, 10);
        }
      }
      else if ( v37 )
      {
        goto LABEL_88;
      }
      v29 = ((int)v29 + 1) & 0x7FLL;
    }
    while ( v29 != *(_DWORD *)(v4 + 1436) );
  }
  raw_spin_unlock(v76 + 404);
  seq_write(a1, "events:\n", 8);
  raw_spin_lock(v76 + 72);
  v32 = *(__int64 **)(v4 + 80);
  v30 = (__int64 *)(v4 + 80);
  for ( j = v32; j != v30; j = (__int64 *)*j )
    seq_printf(a1, "\t%d: %pS created: %u\n", *((_DWORD *)j - 6), (const void *)*(j - 2), *((_DWORD *)j + 4));
  raw_spin_unlock(v76 + 72);
  _ReadStatusReg(SP_EL0);
  return 0;
}
