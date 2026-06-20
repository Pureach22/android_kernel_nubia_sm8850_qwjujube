__int64 __fastcall writeback_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v6; // x8
  __int64 v7; // x19
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x24
  char v10; // w25
  int v11; // w26
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x22
  __int64 next_zero_bit; // x0
  __int64 v16; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x8
  int *v25; // x8
  int v26; // w9
  int v27; // t1
  int v28; // w0
  int v29; // w23
  __int64 v30; // x8
  unsigned int *v31; // x8
  int v32; // w9
  int v33; // t1
  __int64 v34; // x8
  unsigned __int64 v37; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v43; // x9
  __int64 result; // x0
  int v45; // w8
  __int64 v46; // x8
  unsigned __int64 v49; // x9
  unsigned __int64 v52; // x10
  _QWORD v53[2]; // [xsp+0h] [xbp-C0h] BYREF
  unsigned __int64 v54; // [xsp+10h] [xbp-B0h] BYREF
  _QWORD v55[4]; // [xsp+18h] [xbp-A8h] BYREF
  __int64 v56; // [xsp+38h] [xbp-88h]
  __int64 v57; // [xsp+40h] [xbp-80h]
  __int64 v58; // [xsp+48h] [xbp-78h]
  __int64 v59; // [xsp+50h] [xbp-70h]
  __int64 v60; // [xsp+58h] [xbp-68h]
  __int64 v61; // [xsp+60h] [xbp-60h]
  __int64 v62; // [xsp+68h] [xbp-58h]
  __int64 v63; // [xsp+70h] [xbp-50h]
  __int64 v64; // [xsp+78h] [xbp-48h]
  __int64 v65; // [xsp+80h] [xbp-40h]
  __int64 v66; // [xsp+88h] [xbp-38h]
  __int64 v67; // [xsp+90h] [xbp-30h]
  __int64 v68; // [xsp+98h] [xbp-28h]
  __int64 v69; // [xsp+A0h] [xbp-20h]
  __int64 v70; // [xsp+A8h] [xbp-18h]
  __int64 v71; // [xsp+B0h] [xbp-10h]
  __int64 v72; // [xsp+B8h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 224);
  v54 = 0;
  v60 = 0;
  v61 = 0;
  v7 = *(_QWORD *)(v6 + 88);
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v8 = *(_QWORD *)(v7 + 216);
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v9 = v8 >> 12;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  memset(v55, 0, sizeof(v55));
  v53[0] = 0;
  v53[1] = 0;
  if ( (sysfs_streq(a3, "idle") & 1) != 0 )
  {
    v10 = 2;
    v11 = 1;
LABEL_9:
    down_read(v7 + 32);
    if ( !*(_QWORD *)(v7 + 216) )
    {
      a4 = -22;
      goto LABEL_70;
    }
    if ( !*(_QWORD *)(v7 + 240) )
    {
      a4 = -19;
      goto LABEL_70;
    }
    v12 = _alloc_pages_noprof(3264, 0, 0, 0);
    if ( !v12 )
    {
      a4 = -12;
      goto LABEL_70;
    }
    if ( !v9 )
      goto LABEL_59;
    v13 = v12;
    v14 = 0;
    while ( 1 )
    {
      raw_spin_lock(v7 + 248);
      if ( *(_BYTE *)(v7 + 252) == 1 && !*(_QWORD *)(v7 + 256) )
      {
        raw_spin_unlock(v7 + 248);
        a4 = -5;
LABEL_66:
        if ( v14 )
        {
          v46 = 1LL << v14;
          v12 = v13;
          _X10 = (unsigned __int64 *)(*(_QWORD *)(v7 + 272) + 8LL * ((unsigned int)v14 >> 6));
          __asm { PRFM            #0x11, [X10] }
          do
            v49 = __ldxr(_X10);
          while ( __stlxr(v49 & ~v46, _X10) );
          __dmb(0xBu);
          if ( (v49 & v46) == 0 )
            __break(0x800u);
          _X8 = (unsigned __int64 *)(v7 + 192);
          __asm { PRFM            #0x11, [X8] }
          do
            v52 = __ldxr(_X8);
          while ( __stxr(v52 - 1, _X8) );
        }
        else
        {
LABEL_58:
          v12 = v13;
        }
LABEL_59:
        _free_pages(v12, 0);
LABEL_70:
        up_read(v7 + 32);
        result = a4;
        goto LABEL_71;
      }
      raw_spin_unlock(v7 + 248);
      if ( !v14 )
      {
        v14 = 1;
        do
        {
          next_zero_bit = find_next_zero_bit(*(_QWORD *)(v7 + 272), *(_QWORD *)(v7 + 280), v14);
          if ( next_zero_bit == *(_QWORD *)(v7 + 280) )
            goto LABEL_57;
          v16 = 1LL << next_zero_bit;
          v14 = next_zero_bit;
          _X10 = (unsigned __int64 *)(*(_QWORD *)(v7 + 272) + 8LL * ((unsigned int)next_zero_bit >> 6));
          __asm { PRFM            #0x11, [X10] }
          do
            v23 = __ldxr(_X10);
          while ( __stlxr(v23 | v16, _X10) );
          __dmb(0xBu);
        }
        while ( (v23 & v16) != 0 );
        _X8 = (unsigned __int64 *)(v7 + 192);
        __asm { PRFM            #0x11, [X8] }
        do
          v37 = __ldxr(_X8);
        while ( __stxr(v37 + 1, _X8) );
        if ( !next_zero_bit )
        {
LABEL_57:
          a4 = -28;
          goto LABEL_58;
        }
      }
      raw_spin_lock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
      v24 = *(_QWORD *)v7 + 16LL * (unsigned int)v54;
      v27 = *(_DWORD *)(v24 + 8);
      v25 = (int *)(v24 + 8);
      v26 = v27;
      if ( (v27 & 0x7FFF) == 0
        || (v26 & 0xE000) != 0
        || (v10 & 2) != 0 && (v26 & 0x20000) == 0
        || (v10 & 1) != 0 && (v26 & 0x10000) == 0
        || (((*(_QWORD *)&v26 & 0x40000LL) == 0) & ~v11) != 0 )
      {
        goto LABEL_33;
      }
      *v25 = v26 | 0x8000;
      *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) |= 0x20000u;
      raw_spin_unlock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
      if ( (unsigned int)zram_read_page((__int64 *)v7, v13, v54, 0) )
      {
        raw_spin_lock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
        *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) &= ~0x8000u;
      }
      else
      {
        bio_init(v55, *(_QWORD *)(v7 + 264), v53, 1, 2049);
        v56 = 8 * v14;
        _bio_add_page(v55, v13, 4096, 0);
        v28 = submit_bio_wait(v55);
        if ( v28 )
        {
          v29 = v28;
          raw_spin_lock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
          *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) &= ~0x8000u;
          *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) &= ~0x20000u;
          raw_spin_unlock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
          a4 = v29;
          goto LABEL_34;
        }
        _X8 = (unsigned __int64 *)(v7 + 208);
        __asm { PRFM            #0x11, [X8] }
        do
          v40 = __ldxr(_X8);
        while ( __stxr(v40 + 1, _X8) );
        raw_spin_lock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
        v30 = *(_QWORD *)v7 + 16LL * (unsigned int)v54;
        v33 = *(_DWORD *)(v30 + 8);
        v31 = (unsigned int *)(v30 + 8);
        v32 = v33;
        if ( ((v33 & 0x1FFF) != 0 || (v32 & 0x6000) != 0) && (v32 & 0x20000) != 0 )
        {
          zram_free_page((_QWORD *)v7, v54);
          *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) &= ~0x8000u;
          *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) |= 0x4000u;
          *(_QWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54) = v14;
          _X8 = (unsigned __int64 *)(v7 + 160);
          __asm { PRFM            #0x11, [X8] }
          do
            v43 = __ldxr(_X8);
          while ( __stxr(v43 + 1, _X8) );
          raw_spin_lock(v7 + 248);
          if ( *(_BYTE *)(v7 + 252) == 1 )
          {
            v34 = *(_QWORD *)(v7 + 256);
            if ( v34 )
              *(_QWORD *)(v7 + 256) = v34 - 1;
          }
          raw_spin_unlock(v7 + 248);
          v14 = 0;
          goto LABEL_33;
        }
        *v31 = v32 & 0xFFFF7FFF;
      }
      *(_DWORD *)(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 8) &= ~0x20000u;
LABEL_33:
      raw_spin_unlock(*(_QWORD *)v7 + 16LL * (unsigned int)v54 + 12);
LABEL_34:
      --v9;
      ++v54;
      if ( !v9 )
        goto LABEL_66;
    }
  }
  if ( (sysfs_streq(a3, "huge") & 1) != 0 )
  {
    v11 = 1;
    v10 = 1;
    goto LABEL_9;
  }
  if ( (sysfs_streq(a3, "huge_idle") & 1) != 0 )
  {
    v10 = 3;
    v11 = 1;
    goto LABEL_9;
  }
  if ( (sysfs_streq(a3, "incompressible") & 1) != 0 )
  {
    v11 = 0;
    v10 = 4;
    goto LABEL_9;
  }
  if ( strncmp(a3, "page_index=", 0xBu) )
  {
    result = -22;
    goto LABEL_71;
  }
  v45 = kstrtoll(a3 + 11, 10, &v54);
  result = -22;
  if ( !v45 && v54 < v9 )
  {
    v10 = 0;
    v11 = 1;
    v9 = 1;
    goto LABEL_9;
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
