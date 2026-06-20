__int64 __fastcall alloc_zspage(__int64 a1, int *a2, int a3)
{
  __int64 v3; // x22
  __int64 v6; // x0
  __int64 v7; // x20
  int v8; // w8
  int v9; // w9
  unsigned __int64 v10; // x24
  __int64 v11; // x0
  __int64 v12; // x23
  signed __int64 v13; // x8
  unsigned __int64 *v14; // x21
  unsigned __int64 *v15; // x21
  unsigned __int64 *v16; // x21
  unsigned __int64 *v17; // x21
  unsigned __int64 *v18; // x21
  unsigned __int64 *v19; // x21
  unsigned __int64 *v20; // x21
  unsigned __int64 *v21; // x21
  unsigned __int64 v23; // x10
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 v28; // x9
  __int64 v29; // x10
  unsigned __int64 v30; // x8
  int v31; // w23
  unsigned __int64 StatusReg; // x24
  unsigned __int64 v33; // x28
  __int64 *v34; // x8
  unsigned int v35; // w9
  __int64 v36; // x10
  __int64 v37; // x10
  int v38; // w9
  __int64 v39; // x9
  __int64 v40; // x8
  int v41; // w8
  int v42; // w9
  unsigned __int64 v44; // x23
  __int64 v45; // x24
  unsigned __int64 v51; // x10
  unsigned __int64 *v52; // [xsp+8h] [xbp-48h]
  unsigned __int64 v53; // [xsp+10h] [xbp-40h]
  __int64 v54; // [xsp+18h] [xbp-38h]
  __int64 v55; // [xsp+20h] [xbp-30h]
  __int64 v56; // [xsp+28h] [xbp-28h]
  __int64 v57; // [xsp+30h] [xbp-20h]
  __int64 v58; // [xsp+38h] [xbp-18h]
  __int64 v59; // [xsp+40h] [xbp-10h]
  __int64 v60; // [xsp+48h] [xbp-8h]

  LODWORD(v3) = a3;
  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = kmem_cache_alloc_noprof(*(_QWORD *)(a1 + 2056), a3 & 0xFFFFFEF5 | 0x100);
  v7 = v6;
  if ( !v6 )
    goto LABEL_76;
  do
  {
    v8 = *(_DWORD *)v7;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v9 = a2[52];
    v54 = 0;
    v55 = 0;
    v52 = nullptr;
    v53 = 0;
    *(_DWORD *)v7 = v8 & 0xFFC03FFF | 0x160000;
    *(_QWORD *)(v7 + 48) = 0;
    if ( v9 < 1 )
      goto LABEL_57;
    v10 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v11 = _alloc_pages_noprof((unsigned int)v3, 0, 0, 0);
      v12 = v11;
      if ( !v11 )
      {
        if ( v10 )
        {
          if ( (unsigned int)(v10 - 1) > 7 )
            goto LABEL_79;
          v14 = (&v52)[(unsigned int)(v10 - 1)];
          dec_zone_page_state(v14, 9);
          if ( *((_DWORD *)v14 + 12) != -1 )
            *((_DWORD *)v14 + 12) = -1;
          _free_pages(v14, 0);
          if ( v10 < 2 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 2) > 7 )
            goto LABEL_79;
          v15 = (&v52)[(unsigned int)(v10 - 2)];
          dec_zone_page_state(v15, 9);
          if ( *((_DWORD *)v15 + 12) != -1 )
            *((_DWORD *)v15 + 12) = -1;
          _free_pages(v15, 0);
          if ( v10 == 2 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 3) > 7 )
            goto LABEL_79;
          v16 = (&v52)[(unsigned int)(v10 - 3)];
          dec_zone_page_state(v16, 9);
          if ( *((_DWORD *)v16 + 12) != -1 )
            *((_DWORD *)v16 + 12) = -1;
          _free_pages(v16, 0);
          if ( v10 < 4 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 4) > 7 )
            goto LABEL_79;
          v17 = (&v52)[(unsigned int)(v10 - 4)];
          dec_zone_page_state(v17, 9);
          if ( *((_DWORD *)v17 + 12) != -1 )
            *((_DWORD *)v17 + 12) = -1;
          _free_pages(v17, 0);
          if ( v10 == 4 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 5) > 7 )
            goto LABEL_79;
          v18 = (&v52)[(unsigned int)(v10 - 5)];
          dec_zone_page_state(v18, 9);
          if ( *((_DWORD *)v18 + 12) != -1 )
            *((_DWORD *)v18 + 12) = -1;
          _free_pages(v18, 0);
          if ( v10 < 6 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 6) > 7 )
            goto LABEL_79;
          v19 = (&v52)[(unsigned int)(v10 - 6)];
          dec_zone_page_state(v19, 9);
          if ( *((_DWORD *)v19 + 12) != -1 )
            *((_DWORD *)v19 + 12) = -1;
          _free_pages(v19, 0);
          if ( v10 == 6 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 7) > 7 )
            goto LABEL_79;
          v20 = (&v52)[(unsigned int)(v10 - 7)];
          dec_zone_page_state(v20, 9);
          if ( *((_DWORD *)v20 + 12) != -1 )
            *((_DWORD *)v20 + 12) = -1;
          _free_pages(v20, 0);
          if ( v10 < 8 )
            goto LABEL_44;
          if ( (unsigned int)(v10 - 8) > 7 )
          {
LABEL_79:
            __break(1u);
LABEL_80:
            __break(0x5512u);
          }
          v21 = (&v52)[(unsigned int)(v10 - 8)];
          dec_zone_page_state(v21, 9);
          if ( *((_DWORD *)v21 + 12) != -1 )
            *((_DWORD *)v21 + 12) = -1;
          _free_pages(v21, 0);
        }
LABEL_44:
        kmem_cache_free(*(_QWORD *)(a1 + 2056), v7);
        v7 = 0;
        goto LABEL_76;
      }
      if ( *(unsigned __int8 *)(v11 + 51) << 24 != -167772160 )
        *(_DWORD *)(v11 + 48) = -167772160;
      v6 = inc_zone_page_state(v11, 9);
      if ( v10 == 8 )
        goto LABEL_80;
      if ( (v10 & 0x1FFFFFFFFFFFFFFFLL) == 8 )
        goto LABEL_79;
      v13 = a2[52];
      (&v52)[v10++] = (unsigned __int64 *)v12;
    }
    while ( (__int64)v10 < v13 );
    if ( (int)v13 < 1 )
      goto LABEL_57;
    _X9 = v52;
    v52[4] = 0;
    _X9[5] = v7;
    *(_QWORD *)(v7 + 16) = _X9;
    __asm { PRFM            #0x11, [X9] }
    do
      v51 = __ldxr(_X9);
    while ( __stxr(v51 | 0x8000, _X9) );
    if ( a2[51] == 1 && a2[52] == 1 )
    {
      *(_DWORD *)v7 |= 1u;
      if ( (_DWORD)v13 != 1 )
        goto LABEL_50;
      goto LABEL_57;
    }
    if ( (_DWORD)v13 == 1 )
      goto LABEL_57;
LABEL_50:
    v23 = v53;
    *(_QWORD *)(v53 + 32) = 0;
    *(_QWORD *)(v23 + 40) = v7;
    _X9[4] = v23;
    if ( (_DWORD)v13 != 2 )
    {
      v24 = v54;
      *(_QWORD *)(v54 + 32) = 0;
      *(_QWORD *)(v24 + 40) = v7;
      *(_QWORD *)(v23 + 32) = v24;
      if ( (_DWORD)v13 != 3 )
      {
        v25 = v55;
        *(_QWORD *)(v55 + 32) = 0;
        *(_QWORD *)(v25 + 40) = v7;
        *(_QWORD *)(v24 + 32) = v25;
        if ( (_DWORD)v13 != 4 )
        {
          v26 = v56;
          *(_QWORD *)(v56 + 32) = 0;
          *(_QWORD *)(v26 + 40) = v7;
          *(_QWORD *)(v25 + 32) = v26;
          if ( (_DWORD)v13 != 5 )
          {
            v27 = v57;
            *(_QWORD *)(v57 + 32) = 0;
            *(_QWORD *)(v27 + 40) = v7;
            *(_QWORD *)(v26 + 32) = v27;
            if ( (_DWORD)v13 != 6 )
            {
              v28 = v58;
              *(_QWORD *)(v58 + 32) = 0;
              *(_QWORD *)(v28 + 40) = v7;
              *(_QWORD *)(v27 + 32) = v28;
              if ( (_DWORD)v13 != 7 )
              {
                v29 = v59;
                *(_QWORD *)(v59 + 32) = 0;
                *(_QWORD *)(v29 + 40) = v7;
                *(_QWORD *)(v28 + 32) = v29;
                if ( (_DWORD)v13 != 8 )
                  goto LABEL_79;
              }
            }
          }
        }
      }
    }
LABEL_57:
    v3 = *(_QWORD *)(v7 + 16);
    if ( !v3 )
    {
LABEL_75:
      v41 = a2[53];
      v42 = *(_DWORD *)v7;
      *(_DWORD *)(v7 + 8) = 0;
      *(_QWORD *)(v7 + 40) = a1;
      *(_DWORD *)v7 = v42 & 0xFFFFC01F | (32 * (v41 & 0x1FF));
      break;
    }
    v30 = 0;
    v31 = 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      *(_DWORD *)(v3 + 48) = v30 | (*(unsigned __int16 *)(v3 + 50) << 16);
      ++*(_DWORD *)(StatusReg + 16);
      ++*(_DWORD *)(StatusReg + 3220);
      v33 = v30 + a2[50];
      v34 = (__int64 *)((((v3 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                      + (v30 & 0xFFFFFFFFFFFFFFF8LL));
      if ( v33 <= 0xFFF )
      {
        v35 = 2 * v31;
        do
        {
          v36 = v35;
          ++v31;
          v35 += 2;
          *v34 = v36;
          v37 = a2[50];
          v33 += v37;
          v34 = (__int64 *)((char *)v34 + (v37 & 0xFFFFFFFFFFFFFFF8LL));
        }
        while ( v33 < 0x1000 );
      }
      v38 = **(_DWORD **)(v3 + 40);
      if ( (v38 & 0x3FC000) != 0x160000 )
        break;
      if ( (v38 & 1) != 0 )
        v3 = 0;
      else
        v3 = *(_QWORD *)(v3 + 32);
      v39 = (unsigned int)(2 * v31);
      if ( v3 )
        ++v31;
      else
        v39 = -2;
      *v34 = v39;
      --*(_DWORD *)(StatusReg + 3220);
      v40 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v40;
      if ( v40 && *(_QWORD *)(StatusReg + 16) )
      {
        v30 = v33 & 0xFFF;
        if ( !v3 )
          goto LABEL_75;
      }
      else
      {
        v6 = preempt_schedule(v6);
        v30 = v33 & 0xFFF;
        if ( !v3 )
          goto LABEL_75;
      }
    }
    __break(0x800u);
    v44 = _ReadStatusReg(SP_EL0);
    v45 = *(_QWORD *)(v44 + 80);
    *(_QWORD *)(v44 + 80) = &cache_alloc_zspage__alloc_tag;
    v6 = kmem_cache_alloc_noprof(*(_QWORD *)(a1 + 2056), v3 & 0xFFFFFEF5 | 0x100);
    v7 = v6;
    *(_QWORD *)(v44 + 80) = v45;
  }
  while ( v6 );
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return v7;
}
