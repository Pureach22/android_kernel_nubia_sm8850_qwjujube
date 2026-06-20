__int64 __fastcall rt_handler(
        __int64 result,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 *a5)
{
  __int64 i; // x10
  __int64 v6; // x12
  char v7; // w13
  __int64 v8; // x12
  __int64 v9; // x11
  __int64 v10; // x14
  __int64 v11; // x8
  int v12; // w15
  int v13; // w9
  unsigned int v14; // w15
  char v15; // w9
  char v16; // w15
  unsigned int v17; // w16
  char v18; // w15
  int v19; // w14
  __int64 v20; // x13
  int v21; // w15
  unsigned int v22; // w12
  char v23; // w11
  unsigned int v24; // w16
  char v25; // w14
  __int64 j; // x9
  unsigned int v27; // w10
  __int64 v28; // x8
  _BYTE *v29; // x1
  __int64 v31; // x22
  unsigned int v32; // w9
  __int64 v33; // x8
  size_t v34; // x19
  __int64 v35; // x23
  __int64 v36; // x21
  __int64 v37; // x20
  unsigned int v38; // w9
  char v39; // w10
  char v40; // w8
  __int64 v41; // x19
  __int64 v42; // x19
  int v43; // w21
  _BYTE *v44; // x11
  __int64 v45; // x10
  char *v46; // x12
  char v47; // w15
  int v48; // w15
  int v49; // w16
  unsigned int v50; // w15
  unsigned int v51; // w17
  unsigned __int64 StatusReg; // x24
  __int64 v53; // x25
  char v54[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(unsigned __int8 *)(result + 2818) != a2 && *(_BYTE *)(result + 2819) == 1 )
  {
    for ( i = 0; i != 64; ++i )
    {
      v6 = result + i;
      if ( !*(_BYTE *)(result + i + 2626) )
      {
        v7 = *(_BYTE *)(v6 + 2754);
        *(_BYTE *)(v6 + 2626) = 32;
        *(_BYTE *)(v6 + 2754) = v7 + 1;
      }
    }
    *(_QWORD *)(result + 2626) = 0;
    *(_QWORD *)(result + 2634) = 0;
    *(_QWORD *)(result + 2642) = 0;
    *(_QWORD *)(result + 2650) = 0;
    *(_QWORD *)(result + 2658) = 0;
    *(_QWORD *)(result + 2666) = 0;
    *(_QWORD *)(result + 2674) = 0;
    *(_QWORD *)(result + 2682) = 0;
    *(_QWORD *)(result + 2802) = 0;
    *(_QWORD *)(result + 2810) = 0;
    *(_QWORD *)(result + 2786) = 0;
    *(_QWORD *)(result + 2794) = 0;
    *(_QWORD *)(result + 2770) = 0;
    *(_QWORD *)(result + 2778) = 0;
    *(_QWORD *)(result + 2754) = 0;
    *(_QWORD *)(result + 2762) = 0;
    *(_QWORD *)(result + 2690) = 0;
    *(_QWORD *)(result + 2698) = 0;
    *(_QWORD *)(result + 2706) = 0;
    *(_QWORD *)(result + 2714) = 0;
    *(_QWORD *)(result + 2722) = 0;
    *(_QWORD *)(result + 2730) = 0;
    *(_QWORD *)(result + 2738) = 0;
    *(_QWORD *)(result + 2746) = 0;
  }
  *(_BYTE *)(result + 2818) = a2;
  *(_BYTE *)(result + 2819) = 1;
  if ( !a3 )
    goto LABEL_54;
  v8 = result + 2626;
  v9 = result + 2690;
  if ( a3 > 2u )
    v10 = 2854;
  else
    v10 = 2855;
  v11 = result + 2754;
  if ( *(unsigned __int8 *)(result + v10) > 2u )
  {
    v15 = 0;
    goto LABEL_29;
  }
  v12 = *a5;
  if ( !*a5 )
  {
    v12 = 32;
    *a5 = 32;
  }
  v13 = *(unsigned __int8 *)(v8 + a4);
  if ( v13 == v12 )
  {
    v14 = *(unsigned __int8 *)(v11 + a4);
    if ( v14 >= 2 )
    {
      *(_BYTE *)(v11 + a4) = 2;
      v15 = 0;
      *(_BYTE *)(v9 + a4) = *a5;
      goto LABEL_29;
    }
    v15 = 0;
    v16 = v14 + 1;
LABEL_28:
    *(_BYTE *)(v11 + a4) = v16;
    goto LABEL_29;
  }
  v17 = *(unsigned __int8 *)(v11 + a4);
  if ( *(unsigned __int8 *)(v9 + a4) != v12 )
  {
    v15 = 0;
    if ( *(_BYTE *)(v11 + a4) )
    {
      *(_BYTE *)(v9 + a4) = v12;
      goto LABEL_29;
    }
    *(_BYTE *)(v8 + a4) = v12;
    v16 = 1;
    goto LABEL_28;
  }
  *(_BYTE *)(v9 + a4) = v13;
  if ( v17 <= 1 )
    v18 = 2;
  else
    v18 = 3;
  *(_BYTE *)(v11 + a4) = v18;
  v15 = v17 > 1;
  *(_BYTE *)(v8 + a4) = *a5;
LABEL_29:
  if ( a3 == 1 )
    goto LABEL_49;
  if ( *(unsigned __int8 *)(result + v10) <= 2u )
  {
    v19 = a5[1];
    if ( !a5[1] )
    {
      v19 = 32;
      a5[1] = 32;
    }
    v20 = a4 + 1LL;
    v21 = *(unsigned __int8 *)(v8 + v20);
    if ( v21 == v19 )
    {
      v22 = *(unsigned __int8 *)(v11 + v20);
      if ( v22 >= 2 )
      {
        *(_BYTE *)(v11 + v20) = 2;
        *(_BYTE *)(v9 + v20) = a5[1];
        goto LABEL_48;
      }
      v23 = v22 + 1;
LABEL_47:
      *(_BYTE *)(v11 + v20) = v23;
      goto LABEL_48;
    }
    v24 = *(unsigned __int8 *)(v11 + v20);
    if ( *(unsigned __int8 *)(v9 + v20) != v19 )
    {
      if ( *(_BYTE *)(v11 + v20) )
      {
        *(_BYTE *)(v9 + v20) = v19;
        goto LABEL_48;
      }
      *(_BYTE *)(v8 + v20) = v19;
      v23 = 1;
      goto LABEL_47;
    }
    *(_BYTE *)(v9 + v20) = v21;
    if ( v24 <= 1 )
      v25 = 2;
    else
      v25 = 3;
    *(_BYTE *)(v11 + v20) = v25;
    if ( v24 > 1 )
      v15 = 1;
    *(_BYTE *)(v8 + v20) = a5[1];
  }
LABEL_48:
  if ( a3 != 2 )
  {
    v44 = a5 + 2;
    v45 = a3 - 2LL;
    v46 = (char *)(a4 + result + 2756);
    do
    {
      if ( *(unsigned __int8 *)(result + 2855) <= 2u )
      {
        v48 = (unsigned __int8)*v44;
        if ( !*v44 )
        {
          v48 = 32;
          *v44 = 32;
        }
        v49 = (unsigned __int8)*(v46 - 128);
        if ( v49 == v48 )
        {
          v50 = (unsigned __int8)*v46;
          if ( v50 > 1 )
          {
            *v46 = 2;
            LOBYTE(v48) = *v44;
LABEL_91:
            *(v46 - 64) = v48;
            goto LABEL_80;
          }
          *v46 = v50 + 1;
        }
        else
        {
          v51 = (unsigned __int8)*v46;
          if ( (unsigned __int8)*(v46 - 64) == v48 )
          {
            *(v46 - 64) = v49;
            if ( v51 <= 1 )
              v47 = 2;
            else
              v47 = 3;
            *v46 = v47;
            v15 |= v51 > 1;
            *(v46 - 128) = *v44;
            goto LABEL_80;
          }
          if ( *v46 )
            goto LABEL_91;
          *(v46 - 128) = v48;
          *v46 = 1;
        }
      }
LABEL_80:
      --v45;
      ++v44;
      ++v46;
    }
    while ( v45 );
  }
LABEL_49:
  if ( (v15 & 1) != 0 )
  {
    for ( j = 0; j != 64; ++j )
    {
      v27 = *(unsigned __int8 *)(v11 + j);
      if ( v27 >= 2 )
        *(_BYTE *)(v11 + j) = v27 - 1;
    }
  }
LABEL_54:
  v28 = 0;
  v29 = (_BYTE *)(result + 2626);
  while ( *(unsigned __int8 *)(result + v28 + 2754) >= 2u )
  {
    if ( *(_BYTE *)(result + v28 + 2626) != 13 && v28++ != 63 )
      continue;
    v31 = 0;
    while ( v29[v31] != 13 )
    {
      if ( ++v31 == 64 )
      {
        v32 = 64;
        goto LABEL_64;
      }
    }
    v32 = (unsigned __int8)v31;
    if ( !(_BYTE)v31 )
      break;
LABEL_64:
    v33 = 0;
    v34 = v32;
    while ( *(unsigned __int8 *)(result + v33 + 2562) == *(unsigned __int8 *)(result + v33 + 2626) )
    {
      if ( v32 == ++v33 )
        goto LABEL_74;
    }
    if ( v32 != (unsigned __int8)v33 )
    {
      v35 = result;
      memmove((void *)(result + 2562), v29, v32);
      v36 = (unsigned int)(v31 + 5);
      v37 = _kmalloc_noprof(v36, 2080);
      if ( v37 )
      {
        while ( 1 )
        {
          v38 = *(unsigned __int16 *)(v35 + 2550);
          v39 = *(_BYTE *)(v35 + 2552);
          v40 = *(_BYTE *)(v35 + 2818);
          *(_BYTE *)v37 = v34;
          *(_BYTE *)(v37 + 1) = v39;
          *(_BYTE *)(v37 + 4) = v40;
          *(_WORD *)(v37 + 2) = bswap32(v38) >> 16;
          if ( v36 - 5 >= v34 )
            break;
          _fortify_panic(17, v36 - 5);
          v36 = (unsigned int)(v31 + 5);
          StatusReg = _ReadStatusReg(SP_EL0);
          v53 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &display_rt__alloc_tag;
          v37 = _kmalloc_noprof(v36, 2080);
          *(_QWORD *)(StatusReg + 80) = v53;
          if ( !v37 )
            goto LABEL_93;
        }
        memcpy((void *)(v37 + 5), (const void *)(v35 + 2562), v34);
        v41 = raw_spin_lock_irqsave(v35 + 1980);
        _kfifo_in(v35 + 3184, v37, (unsigned int)(v31 + 5));
        raw_spin_unlock_irqrestore(v35 + 1980, v41);
        v54[0] = 5;
        v42 = raw_spin_lock_irqsave(v35 + 1976);
        v43 = _kfifo_in(v35 + 3160, v54, 1);
        raw_spin_unlock_irqrestore(v35 + 1976, v42);
        if ( v43 )
          _wake_up(v35 + 2520, 1, 1, 0);
        result = kfree(v37);
      }
      else
      {
LABEL_93:
        result = printk(&unk_DBBA, "display_rt");
      }
    }
    break;
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
