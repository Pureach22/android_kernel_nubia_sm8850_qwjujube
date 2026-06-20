__int64 __fastcall recover_dispatch_q(_QWORD *a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x27
  __int64 v7; // x22
  unsigned __int64 v9; // x20
  __int64 v10; // x0
  unsigned __int64 v11; // x10
  unsigned __int64 v12; // x23
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x26
  unsigned __int64 v17; // x28
  __int64 v18; // x0
  __int64 v19; // x9
  __int64 v20; // x21
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  const char *v25; // x4
  __int64 v26; // x8
  __int64 v27; // x10
  const char *v28; // x2
  __int64 v29; // x10
  __int64 v30; // x10
  int v31; // w3
  _BOOL4 v32; // w12
  unsigned __int64 StatusReg; // x23
  __int64 v34; // x26
  unsigned __int64 v41; // x10
  unsigned __int64 v44; // x9
  unsigned __int64 v47; // x8
  __int64 v48; // x1
  __int64 v49; // x2
  __int64 v50; // x3
  __int64 v51; // x25
  unsigned __int64 v52; // x8
  __int64 v53; // x9
  const char *v54; // x2
  __int64 v55; // x10
  int v56; // w3
  __int64 v57; // x10
  unsigned __int64 v58; // x24
  __int64 v59; // x1
  __int64 v60; // x2
  __int64 v61; // x3
  unsigned __int64 v63; // x9
  unsigned __int64 v65; // x9
  unsigned __int64 v68; // x14
  __int64 v69; // x13
  unsigned __int64 v72; // x11
  unsigned __int64 v75; // x10
  unsigned __int64 v78; // x10
  unsigned __int64 v81; // x8
  _QWORD *i; // x11
  _QWORD *v83; // t1
  unsigned __int64 v86; // x9
  unsigned __int64 v89; // x8
  __int64 v90; // x13
  unsigned __int64 v93; // x9
  unsigned __int64 v96; // x8
  __int64 v97; // x8
  const char *v98; // x2
  __int64 v99; // x9
  __int64 v100; // x9
  int v101; // w3
  unsigned __int64 v104; // x9
  unsigned __int64 v107; // x9
  unsigned __int64 v110; // x10
  unsigned __int64 v113; // x9
  unsigned __int64 v116; // x12
  unsigned __int64 v119; // x11
  unsigned __int64 v122; // x9
  unsigned __int64 v125; // x9
  unsigned __int64 v128; // x11
  unsigned __int64 *v129; // [xsp+8h] [xbp-8h]

  v7 = a2;
  v9 = 8LL * *(unsigned int *)(a2 + 1024);
  v10 = _kmalloc_noprof(v9, 3520);
  v129 = (unsigned __int64 *)v10;
  while ( 1 )
  {
    v12 = *(unsigned int *)(v7 + 1028);
    v13 = *(unsigned int *)(v7 + 1032);
    LODWORD(v14) = (_DWORD)v129;
    if ( v129 )
      break;
    if ( v12 == v13 )
      goto LABEL_17;
    while ( v12 < 0x80 )
    {
      v20 = *(_QWORD *)(v7 + 8 * v12);
      adreno_drawctxt_set_guilty(a1, *(_QWORD *)(v20 + 8));
      kgsl_drawobj_destroy(v20, v21, v22, v23);
      v12 = ((int)v12 + 1) & 0x7FLL;
      if ( v12 == *(_DWORD *)(v7 + 1032) )
        goto LABEL_17;
    }
LABEL_56:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v34 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &recover_dispatch_q__alloc_tag;
    v9 = 8LL * *(unsigned int *)(v7 + 1024);
    v10 = _kmalloc_noprof(v9, 3520);
    v129 = (unsigned __int64 *)v10;
    *(_QWORD *)(StatusReg + 80) = v34;
  }
  if ( v12 == v13 )
    goto LABEL_17;
  v15 = 0;
  _X8 = 1;
  do
  {
    if ( v12 > 0x7F )
      goto LABEL_56;
    LODWORD(v17) = v15;
    if ( v9 <= 8LL * (int)v15 )
      goto LABEL_186;
    LODWORD(v4) = _X8;
    v14 = *(unsigned int *)(v7 + 1032);
    v11 = *(_QWORD *)(v7 + 8 * v12);
    v12 = ((_BYTE)v12 + 1) & 0x7F;
    v15 = (unsigned int)(v15 + 1);
    v129[(int)v17] = v11;
    _X8 = (unsigned int)(_X8 + 1);
  }
  while ( v12 != v14 );
  if ( !a3 || !(_DWORD)v15 )
    goto LABEL_66;
  v12 = *v129;
  if ( (*(_QWORD *)(*v129 + 72) & 0x40) != 0 )
  {
    v18 = ktime_get(v10);
    v19 = *(_QWORD *)(v12 + 8);
    if ( (v18 - *(_QWORD *)(v19 + 264)) / 1000000 > (unsigned int)fault_throttle_time )
    {
      *(_QWORD *)(*(_QWORD *)(v12 + 8) + 264LL) = ktime_get(v18);
      *(_DWORD *)(*(_QWORD *)(v12 + 8) + 256LL) = 1;
      if ( (*(_QWORD *)(v12 + 72) & 0x10) != 0 )
        goto LABEL_34;
      goto LABEL_21;
    }
    ++*(_DWORD *)(v19 + 256);
    if ( *(_DWORD *)(*(_QWORD *)(v12 + 8) + 256LL) > (unsigned int)fault_throttle_burst )
    {
      _X10 = (unsigned __int64 *)(v12 + 72);
      __asm { PRFM            #0x11, [X10] }
      do
        v128 = __ldxr(_X10);
      while ( __stxr(v128 | 0x10, _X10) );
      v27 = *(_QWORD *)(v12 + 8);
      if ( v27 )
      {
        v29 = *(_QWORD *)(v27 + 24);
        if ( v29 )
          v28 = (const char *)(v29 + 16);
        else
          v28 = "unknown";
      }
      else
      {
        v28 = "unknown";
        v29 = 0x183560000F4F68LL;
      }
      v30 = *(_QWORD *)(v29 + 8);
      if ( v30 )
        v31 = *(_DWORD *)(v30 + 112);
      else
        v31 = 0;
      dev_err(
        *a1,
        "%s[%d]: gpu fault threshold exceeded %d faults in %d msecs\n",
        v28,
        v31,
        fault_throttle_burst,
        fault_throttle_time);
      if ( (*(_QWORD *)(v12 + 72) & 0x10) != 0 )
        goto LABEL_34;
      goto LABEL_21;
    }
  }
  if ( (*(_QWORD *)(v12 + 72) & 0x10) != 0 )
    goto LABEL_34;
LABEL_21:
  if ( (*(_QWORD *)(v12 + 72) & 0x20) == 0 )
  {
    v25 = "failed";
    v26 = *(_QWORD *)(v12 + 8);
    if ( v26 )
      goto LABEL_35;
    goto LABEL_36;
  }
LABEL_34:
  v25 = "skipped";
  *(_QWORD *)(v12 + 72) = 0;
  v26 = *(_QWORD *)(v12 + 8);
  if ( v26 )
  {
LABEL_35:
    if ( (*(_QWORD *)(v26 + 32) & 2) == 0 )
      goto LABEL_37;
  }
LABEL_36:
  v25 = "detached";
  *(_QWORD *)(v12 + 72) = 0;
LABEL_37:
  _X8 = (unsigned __int64 *)(v12 + 72);
  __asm { PRFM            #0x11, [X8] }
  do
    v44 = __ldxr(_X8);
  while ( __stxr(v44 | 0x80000000, _X8) );
  if ( (a3 & 2) != 0 )
  {
    _X9 = (unsigned __int64 *)(v12 + 72);
    __asm { PRFM            #0x11, [X9] }
    do
      v72 = __ldxr(_X9);
    while ( __stxr(v72 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
  }
  if ( (a3 & 0x44) != 0 )
    *(_QWORD *)(v12 + 72) = 0;
  if ( (*(_QWORD *)(*(_QWORD *)(v12 + 8) + 32LL) & 8) != 0 )
  {
    _X8 = (unsigned __int64 *)(v12 + 72);
    __asm { PRFM            #0x11, [X8] }
    do
      v75 = __ldxr(_X8);
    while ( __stxr(v75 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    _X8 = (unsigned __int64 *)(*(_QWORD *)(v12 + 8) + 32LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v78 = __ldxr(_X8);
    while ( __stxr(v78 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
  }
  _X9 = (unsigned __int64 *)(v12 + 72);
  __asm { PRFM            #0x11, [X9] }
  do
    v47 = __ldxr(_X9);
  while ( __stlxr(v47 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
  __dmb(0xBu);
  if ( (v47 & 2) != 0 )
  {
    _X8 = (unsigned __int64 *)(v12 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v86 = __ldxr(_X8);
      v14 = v86 | 2;
      v11 = __stxr(v14, _X8);
    }
    while ( (_DWORD)v11 );
    goto LABEL_66;
  }
  _X9 = (unsigned __int64 *)(v12 + 72);
  __asm { PRFM            #0x11, [X9] }
  do
    v81 = __ldxr(_X9);
  while ( __stlxr(v81 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
  __dmb(0xBu);
  if ( (v81 & 4) != 0 )
  {
    _X8 = (unsigned __int64 *)(v12 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v93 = __ldxr(_X8);
      v11 = __stxr(v93 | 4, _X8);
    }
    while ( (_DWORD)v11 );
    if ( (unsigned int)v17 <= 0x7FFFFFFE )
    {
      _X8 = 0;
      LODWORD(v14) = a4;
      while ( v9 > 8 * _X8 )
      {
        v11 = v129[_X8];
        if ( v11 && *(_DWORD *)(*(_QWORD *)(v11 + 8) + 4LL) == *(_DWORD *)(*(_QWORD *)(v12 + 8) + 4LL) )
        {
          v83 = *(_QWORD **)(v11 + 88);
          v11 += 88LL;
          for ( i = v83; i != (_QWORD *)v11; i = (_QWORD *)*i )
          {
            if ( i[4] == a4 )
            {
              i[7] |= 2uLL;
              if ( a4 )
                break;
            }
          }
        }
        if ( ++_X8 == v15 )
          goto LABEL_66;
      }
      goto LABEL_186;
    }
LABEL_17:
    *(_DWORD *)(v7 + 1024) = 0;
    *(_DWORD *)(v7 + 1032) = 0;
    *(_DWORD *)(v7 + 1028) = 0;
    goto LABEL_18;
  }
  _X9 = (unsigned __int64 *)(v12 + 72);
  __asm { PRFM            #0x11, [X9] }
  do
    v89 = __ldxr(_X9);
  while ( __stlxr(v89 & 0xFFFFFFFFFFFFFF7FLL, _X9) );
  __dmb(0xBu);
  if ( (v89 & 0x80) != 0 )
  {
    _X8 = *(_QWORD *)(v12 + 8);
    if ( (int)v15 < 2 )
    {
      if ( (_DWORD)v15 != 1 )
      {
LABEL_174:
        _X8 = (unsigned __int64 *)(v12 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v104 = __ldxr(_X8);
          v14 = v104 | 1;
          v11 = __stxr(v14, _X8);
        }
        while ( (_DWORD)v11 );
        *(_QWORD *)(v12 + 80) = 0;
        goto LABEL_66;
      }
LABEL_158:
      if ( _X8 )
      {
        _X9 = (unsigned __int64 *)(_X8 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v110 = __ldxr(_X9);
        while ( __stxr(v110 | 0x200000, _X9) );
        *(_DWORD *)(_X8 + 1516) = *(_QWORD *)(*v129 + 72);
      }
      goto LABEL_174;
    }
    LODWORD(v14) = 1;
    v11 = 8;
    while ( v9 > v11 )
    {
      v90 = *(unsigned __int64 *)((char *)v129 + v11);
      if ( *(_DWORD *)(*(_QWORD *)(v90 + 8) + 4LL) == *(_DWORD *)(_X8 + 4) )
      {
        *(_QWORD *)(v90 + 72) = *(_QWORD *)(*v129 + 72);
        if ( v9 > v11 )
        {
          _X11 = (unsigned __int64 *)(*(unsigned __int64 *)((char *)v129 + v11) + 56);
          __asm { PRFM            #0x11, [X11] }
          do
            v116 = __ldxr(_X11);
          while ( __stxr(v116 | 2, _X11) );
          if ( v9 > v11 )
          {
            v11 = *(unsigned __int64 *)((char *)v129 + v11);
            goto LABEL_187;
          }
        }
        break;
      }
      v11 += 8LL;
      LODWORD(v14) = v14 + 1;
      if ( 8LL * (unsigned int)v4 == v11 )
        goto LABEL_158;
    }
LABEL_186:
    __break(1u);
LABEL_187:
    _X10 = (unsigned __int64 *)(v11 + 80);
    __asm { PRFM            #0x11, [X10] }
    do
      v119 = __ldxr(_X10);
    while ( __stxr(v119 | 0x80, _X10) );
    if ( (_DWORD)v15 != (_DWORD)v14 )
      goto LABEL_174;
    goto LABEL_158;
  }
  _X9 = (unsigned __int64 *)(v12 + 72);
  __asm { PRFM            #0x11, [X9] }
  do
    v96 = __ldxr(_X9);
  while ( __stlxr(v96 & 0xFFFFFFFFFFFFFFF7LL, _X9) );
  __dmb(0xBu);
  if ( (v96 & 8) != 0 )
  {
    _X8 = (unsigned __int64 *)(v12 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v107 = __ldxr(_X8);
      v11 = __stxr(v107 | 8, _X8);
    }
    while ( (_DWORD)v11 );
    LODWORD(v14) = 2147483646;
    _X8 = *(_QWORD *)(v12 + 8);
    if ( (unsigned int)v17 <= 0x7FFFFFFE )
    {
      v14 = 0;
      v11 = 8LL * (unsigned int)v4;
      v32 = 1;
      while ( v9 > v14 )
      {
        v69 = *(unsigned __int64 *)((char *)v129 + v14);
        if ( *(_DWORD *)(*(_QWORD *)(v69 + 8) + 4LL) == *(_DWORD *)(*(_QWORD *)(v12 + 8) + 4LL) )
        {
          if ( !v32 )
          {
            _X8 = (unsigned __int64 *)(v69 + 56);
            __asm { PRFM            #0x11, [X8] }
            do
            {
              v125 = __ldxr(_X8);
              v14 = v125 | 2;
              v11 = __stxr(v14, _X8);
            }
            while ( (_DWORD)v11 );
            goto LABEL_66;
          }
          _X12 = (unsigned __int64 *)(v69 + 56);
          __asm { PRFM            #0x11, [X12] }
          do
            v68 = __ldxr(_X12);
          while ( __stxr(v68 | 1, _X12) );
          v32 = (*(_BYTE *)(v69 + 25) & 1) == 0;
        }
        v14 += 8LL;
        if ( v11 == v14 )
          goto LABEL_51;
      }
      goto LABEL_186;
    }
    v32 = 1;
LABEL_51:
    if ( v32 && _X8 )
    {
      _X8 = (unsigned __int64 *)(_X8 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v113 = __ldxr(_X8);
        v14 = v113 | 0x80000;
        v11 = __stxr(v14, _X8);
      }
      while ( (_DWORD)v11 );
    }
    else if ( !v32 && _X8 )
    {
      _X8 = (unsigned __int64 *)(_X8 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v122 = __ldxr(_X8);
        v14 = v122 | 0x100000;
        v11 = __stxr(v14, _X8);
      }
      while ( (_DWORD)v11 );
    }
  }
  else
  {
    v97 = *(_QWORD *)(v12 + 8);
    if ( v97 )
    {
      v99 = *(_QWORD *)(v97 + 24);
      if ( v99 )
        v98 = (const char *)(v99 + 16);
      else
        v98 = "unknown";
    }
    else
    {
      v98 = "unknown";
      v99 = 0x183560000F4F68LL;
    }
    v100 = *(_QWORD *)(v99 + 8);
    if ( v100 )
      v101 = *(_DWORD *)(v100 + 112);
    else
      v101 = 0;
    dev_err(*a1, "%s[%d]: gpu %s ctx %d ts %u\n", v98, v101, v25, *(_DWORD *)(v97 + 4), *(_DWORD *)(v12 + 20));
    adreno_drawctxt_set_guilty(a1, *(_QWORD *)(v12 + 8));
  }
LABEL_66:
  *(_QWORD *)(v7 + 1024) = 0;
  *(_DWORD *)(v7 + 1032) = 0;
  if ( (unsigned int)v17 <= 0x7FFFFFFE )
  {
    _X8 = (unsigned int)v4;
    v12 = 0;
    do
    {
      if ( v9 <= v12 )
        goto LABEL_186;
      _X8 = (__int64)v129;
      v7 = *(unsigned __int64 *)((char *)v129 + v12);
      if ( v7 )
      {
        _X8 = *(_QWORD *)(v7 + 8);
        if ( !_X8 || (v14 = *(_QWORD *)(_X8 + 32), (v14 & 2) != 0) || (_X8 = *(_QWORD *)(_X8 + 32), (_X8 & 4) != 0) )
        {
          if ( v9 <= v12 )
            goto LABEL_186;
          *(unsigned __int64 *)((char *)v129 + v12) = 0;
          rt_mutex_lock(a1 + 1386);
          kgsl_cancel_events_timestamp(a1, *(_QWORD *)(v7 + 8) + 64LL, *(unsigned int *)(v7 + 20));
          rt_mutex_unlock(a1 + 1386);
          kgsl_drawobj_destroy(v7, v48, v49, v50);
        }
      }
      v12 += 8LL;
    }
    while ( 8LL * (unsigned int)v4 != v12 );
    v17 = 0;
    v51 = 0;
    _X8 = 0;
    while ( 1 )
    {
      v12 = 8 * v51;
      if ( v9 <= 8 * v51 )
        goto LABEL_186;
      v7 = (unsigned int)v4;
      v14 = v129[v51];
      if ( v14 )
        break;
LABEL_79:
      ++v51;
      v17 += 8LL;
      LODWORD(v4) = v7 - 1;
      if ( v51 == v15 )
        goto LABEL_18;
    }
    if ( (_DWORD)_X8 )
    {
      if ( v9 <= v12 )
        goto LABEL_186;
    }
    else
    {
      _X8 = v14 + 56;
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v65 = __ldxr((unsigned __int64 *)_X8);
        v14 = v65 | 2;
        v11 = __stxr(v14, (unsigned __int64 *)_X8);
      }
      while ( (_DWORD)v11 );
      if ( v9 <= v12 )
        goto LABEL_186;
    }
    _X8 = v129[v51] + 56;
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v63 = __ldxr((unsigned __int64 *)_X8);
      v14 = v63 | 4;
      v11 = __stxr(v14, (unsigned __int64 *)_X8);
    }
    while ( (_DWORD)v11 );
    if ( v9 <= v12 )
      goto LABEL_186;
    if ( !(unsigned int)sendcmd(a1, v129[v51]) )
    {
LABEL_78:
      _X8 = 1;
      goto LABEL_79;
    }
    if ( v9 <= v12 )
      goto LABEL_186;
    v52 = v129[v51];
    v53 = *(_QWORD *)(v52 + 8);
    if ( v53 )
    {
      v57 = *(_QWORD *)(v53 + 24);
      if ( v57 )
        v54 = (const char *)(v57 + 16);
      else
        v54 = "unknown";
      v55 = *(_QWORD *)(v57 + 8);
      if ( v55 )
        goto LABEL_89;
    }
    else
    {
      v54 = "unknown";
      v55 = MEMORY[0x183560000F4F70];
      if ( MEMORY[0x183560000F4F70] )
      {
LABEL_89:
        v56 = *(_DWORD *)(v55 + 112);
        goto LABEL_95;
      }
    }
    v56 = 0;
LABEL_95:
    dev_err(*a1, "%s[%d]: gpu reset failed ctx %u ts %u\n", v54, v56, *(_DWORD *)(v53 + 4), *(_DWORD *)(v52 + 20));
    if ( v9 <= v12 )
      goto LABEL_186;
    adreno_drawctxt_set_guilty(a1, *(_QWORD *)(v129[v51] + 8));
    _X8 = (unsigned int)(v15 - v51);
    if ( (int)_X8 >= 1 )
    {
      v4 = (unsigned int)v4;
      v58 = v17;
      while ( v9 > v58 )
      {
        v12 = *(unsigned __int64 *)((char *)v129 + v58);
        if ( v12 )
        {
          _X8 = *(_QWORD *)(v12 + 8);
          if ( !_X8 || (v14 = *(_QWORD *)(_X8 + 32), (v14 & 2) != 0) || (_X8 = *(_QWORD *)(_X8 + 32), (_X8 & 4) != 0) )
          {
            if ( v9 <= v58 )
              goto LABEL_186;
            *(unsigned __int64 *)((char *)v129 + v58) = 0;
            rt_mutex_lock(a1 + 1386);
            kgsl_cancel_events_timestamp(a1, *(_QWORD *)(v12 + 8) + 64LL, *(unsigned int *)(v12 + 20));
            rt_mutex_unlock(a1 + 1386);
            kgsl_drawobj_destroy(v12, v59, v60, v61);
          }
        }
        --v4;
        v58 += 8LL;
        _X8 = 1;
        if ( !v4 )
          goto LABEL_79;
      }
      goto LABEL_186;
    }
    goto LABEL_78;
  }
LABEL_18:
  _X8 = a1 + 1780;
  __asm { PRFM            #0x11, [X8] }
  do
    v41 = __ldxr(_X8);
  while ( __stxr(v41 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
  return kfree(v129);
}
