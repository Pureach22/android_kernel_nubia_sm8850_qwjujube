__int64 __fastcall adreno_rpmh_build_bw_votes(
        __int64 *a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        __int16 a5,
        unsigned int a6,
        char a7)
{
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x27
  __int64 v16; // x0
  unsigned int v17; // w15
  __int16 v18; // w20
  __int64 v19; // x21
  __int64 *v20; // x28
  __int64 v21; // x0
  __int64 aux_data; // x26
  __int64 v23; // x12
  __int64 v24; // x13
  __int64 v25; // x21
  unsigned __int64 v26; // x26
  __int64 v27; // x0
  int *v28; // x8
  __int64 v29; // x9
  unsigned __int64 v30; // x10
  __int64 v31; // x11
  int v32; // w13
  int v33; // w12
  unsigned int v34; // w15
  unsigned __int64 v35; // x17
  unsigned __int64 v36; // x14
  unsigned __int64 v37; // x16
  unsigned __int64 v38; // x15
  __int64 v39; // x17
  unsigned __int64 v40; // x0
  __int64 v42; // x16
  __int64 v44; // x14
  int v45; // w13
  int v46; // w13
  __int64 *v47; // x14
  unsigned int v48; // w20
  unsigned int v49; // w20
  _QWORD v53[2]; // [xsp+30h] [xbp-10h] BYREF

  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = _kmalloc_cache_noprof(idr_find, 3520, 32);
  v13 = v12;
  if ( !v12 )
  {
LABEL_68:
    v13 = -12;
    goto LABEL_69;
  }
  if ( a2 < 0 )
  {
    *(_QWORD *)(v12 + 8) = 0;
    goto LABEL_63;
  }
  v14 = _kmalloc_noprof(8LL * (unsigned int)a2, 3520);
  *(_QWORD *)(v13 + 8) = v14;
  if ( !v14 )
  {
LABEL_63:
    v16 = *(_QWORD *)(v13 + 24);
    if ( v16 )
    {
      v49 = 0;
      do
      {
        if ( v49 >= *(_DWORD *)(v13 + 16) )
          break;
        kfree(*(_QWORD *)(v16 + 8LL * (int)v49));
        v16 = *(_QWORD *)(v13 + 24);
        ++v49;
      }
      while ( v16 );
    }
LABEL_67:
    kfree(v16);
    kfree(*(_QWORD *)(v13 + 8));
    kfree(v13);
    goto LABEL_68;
  }
  v15 = a4;
  if ( (a4 & 0x80000000) != 0 )
  {
    v16 = 0;
    *(_QWORD *)(v13 + 24) = 0;
    goto LABEL_67;
  }
  v16 = _kmalloc_noprof(8LL * a4, 3520);
  *(_QWORD *)(v13 + 24) = v16;
  if ( !v16 )
    goto LABEL_67;
  v17 = a2 - 1;
  *(_DWORD *)(v13 + 4) = a2;
  *(_DWORD *)(v13 + 16) = a4;
  if ( a2 >= 1 )
  {
    v18 = a5;
    v19 = 0;
    v20 = a1;
    do
    {
      v21 = *v20;
      v53[0] = 0;
      aux_data = cmd_db_read_aux_data(v21, v53);
      *(_DWORD *)(*(_QWORD *)(v13 + 8) + v19) = cmd_db_read_addr(*v20);
      v19 += 4;
      *((_DWORD *)v20 + 4) = *(_DWORD *)aux_data;
      *((_WORD *)v20 + 10) = *(_WORD *)(aux_data + 4);
      *((_BYTE *)v20 + 22) = *(_BYTE *)(aux_data + 6);
      v20 += 3;
    }
    while ( 4LL * (unsigned int)a2 != v19 );
    a5 = v18;
    v17 = a2 - 1;
    v23 = 0;
    do
    {
      if ( v23 == a2 - 1 )
      {
        v24 = v23 + 1;
      }
      else
      {
        v24 = v23 + 1;
        if ( BYTE6(a1[3 * v23 + 2]) == BYTE6(a1[3 * v23 + 5]) )
          goto LABEL_12;
      }
      *(_DWORD *)v13 |= 1 << v23;
LABEL_12:
      v23 = v24;
    }
    while ( v24 != a2 );
  }
  if ( (int)v15 >= 1 )
  {
    v25 = 24LL * v17;
    v26 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( a2 < 0 )
        v27 = 0;
      else
        v27 = _kmalloc_noprof(4LL * a2, 3520);
      *(_QWORD *)(*(_QWORD *)(v13 + 24) + 8 * v26) = v27;
      v16 = *(_QWORD *)(v13 + 24);
      v28 = *(int **)(v16 + 8 * v26);
      if ( !v28 )
      {
        if ( v16 )
        {
          v48 = 0;
          do
          {
            if ( v48 >= *(_DWORD *)(v13 + 16) )
              break;
            kfree(*(_QWORD *)(v16 + 8LL * (int)v48));
            v16 = *(_QWORD *)(v13 + 24);
            ++v48;
          }
          while ( v16 );
        }
        goto LABEL_67;
      }
      if ( (a7 & 1) != 0 )
      {
        v29 = *(unsigned int *)(a3 + 4 * v26);
        if ( a2 >= 1 )
          goto LABEL_26;
      }
      else
      {
        v29 = 0;
        if ( a2 >= 1 )
        {
LABEL_26:
          v30 = 0;
          v31 = *(unsigned int *)(a3 + 4 * v26);
          if ( v26 >= a6 )
            v32 = a5 & 0x3FFF | 0x20000000;
          else
            v32 = 0x20000000;
          if ( v31 | v29 )
            v33 = v32;
          else
            v33 = 0;
          do
          {
            if ( v25 == v30 || BYTE6(a1[v30 / 8 + 2]) != BYTE6(a1[v30 / 8 + 5]) )
              v46 = 0x40000000;
            else
              v46 = 0;
            v47 = &a1[v30 / 8];
            if ( HIBYTE(a1[v30 / 8 + 2]) == 1 )
            {
              v45 = v46 | v33;
            }
            else
            {
              v34 = *((unsigned __int16 *)v47 + 10);
              v35 = *((unsigned int *)v47 + 2);
              v36 = *((unsigned int *)v47 + 4);
              v37 = 1000 * (v34 * (unsigned __int64)(unsigned int)v29 / v35);
              v38 = 1000 * (v34 * (unsigned __int64)(unsigned int)v31 / v35);
              v39 = v37 / v36;
              v40 = v38 / v36;
              if ( v37 / v36 >= 0x3FFF )
                v39 = 0x3FFF;
              if ( v40 >= 0x3FFF )
                v40 = 0x3FFF;
              if ( v37 >= v36 || v29 == 0 )
                v42 = v39;
              else
                v42 = 1;
              if ( v38 >= v36 || v31 == 0 )
                v44 = v40;
              else
                v44 = 1;
              v45 = (((v42 | v44) != 0) << 29) | ((_DWORD)v42 << 14) | v44 | v46;
            }
            v30 += 24LL;
            *v28++ = v45;
          }
          while ( 24LL * (unsigned int)a2 != v30 );
        }
      }
      ++v26;
    }
    while ( v26 != v15 );
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return v13;
}
