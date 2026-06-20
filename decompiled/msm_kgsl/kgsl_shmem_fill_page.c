void __fastcall kgsl_shmem_fill_page(__int64 a1, __int64 a2, _QWORD *a3, int a4)
{
  unsigned __int64 v4; // x23
  _QWORD *v5; // x28
  _QWORD *v6; // x9
  _QWORD **v7; // x20
  _QWORD *v8; // x8
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned __int64 v12; // x24
  __int64 v13; // x19
  unsigned __int64 v14; // x9
  bool v15; // cc
  unsigned __int64 v16; // x8
  int v17; // w27
  bool v18; // cf
  unsigned int v19; // w25
  unsigned int v20; // w8
  unsigned int v21; // w21
  int v22; // w9
  int v23; // w8
  __int64 v24; // x0
  __int64 v25; // x22
  __int64 v26; // x28
  _QWORD *v27; // x21
  __int64 v28; // x27
  __int64 v29; // x22
  _QWORD *v30; // x1
  int v31; // w27
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x9
  unsigned int v34; // w8
  unsigned int v35; // w9
  unsigned __int64 v36; // x10
  int v38; // [xsp+14h] [xbp-Ch]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-8h]

  if ( a4 )
    return;
  v4 = *(_QWORD *)(a2 + 816);
  if ( !v4 || v4 > 0xFFFFFFFFFFFFF000LL )
    return;
  v5 = a3;
  v7 = (_QWORD **)(v4 + 192);
  v6 = *(_QWORD **)(v4 + 192);
  if ( v6 != (_QWORD *)(v4 + 192) )
  {
LABEL_5:
    *v5 = v6 - 1;
    v8 = (_QWORD *)v6[1];
    if ( (_QWORD *)*v8 == v6 && (v9 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
    {
      *(_QWORD *)(v9 + 8) = v8;
      *v8 = v9;
    }
    else
    {
      _list_del_entry_valid_or_report(v6);
    }
    *v6 = 0xDEAD000000000100LL;
    v6[1] = 0xDEAD000000000122LL;
    return;
  }
  v10 = *(_QWORD *)(v4 + 40);
  v11 = *(unsigned int *)(v4 + 104);
  v12 = v10 - (v11 << 12);
  if ( v10 == v11 << 12 )
  {
    LODWORD(v13) = 0;
    if ( !v12 )
      return;
    goto LABEL_23;
  }
  if ( v12 == 4096 )
    return;
  v13 = 1LL << ((unsigned __int8)__clz(v12) ^ 0x3Fu);
  if ( (unsigned int)v13 <= 0x1000 )
  {
LABEL_22:
    LODWORD(v13) = 4096;
    if ( !v12 )
      return;
    goto LABEL_23;
  }
  v14 = (unsigned int)v13;
  while ( v14 > v12 || (v13 & 0x1FFFFF) == 0 )
  {
    v14 = (unsigned int)v13 >> 1;
    v15 = (unsigned int)v13 > 0x2001;
    LODWORD(v13) = (unsigned int)v13 >> 1;
    if ( !v15 )
      goto LABEL_22;
  }
  if ( v12 )
  {
LABEL_23:
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = (unsigned int)v13 - 1LL;
    v17 = 0;
    v18 = v16 >= 0x1000;
    v19 = 20;
    v20 = 64 - __clz(v16 >> 12);
    if ( v18 )
      v21 = v20;
    else
      v21 = 0;
    while ( 1 )
    {
      v22 = (int)v21 <= 0 ? 3266 : 335874;
      v23 = kgsl_sharedmem_noretry_flag ? v22 | 0x12000 : v22;
      if ( (*(_QWORD *)StatusReg & 1) != 0 && (*(_BYTE *)(StatusReg + 2449) & 1) != 0 )
        break;
      v24 = _alloc_pages_noprof(v23 & 0x12CC2, v21, 0, 0);
      v25 = v24;
      if ( v24 )
      {
        split_page(v24, v21);
        if ( v21 == 31 )
          return;
        v38 = v17;
        v26 = (unsigned int)(1 << v21);
        v27 = (_QWORD *)(v25 + 8);
        v28 = (v25 << 6) + 0xFFFFD000000000LL;
        v29 = v26;
        do
        {
          clear_page(v28 & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL);
          v30 = *(_QWORD **)(v4 + 200);
          if ( v27 == v7 || v27 == v30 || (_QWORD **)*v30 != v7 )
          {
            _list_add_valid_or_report(v27, v30);
          }
          else
          {
            *(_QWORD *)(v4 + 200) = v27;
            *v27 = v7;
            v27[1] = v30;
            *v30 = v27;
          }
          --v29;
          v27 += 8;
          v28 += 4096;
        }
        while ( v29 );
        v12 -= (unsigned int)v13;
        if ( v12 )
        {
          v31 = v38;
          v13 = 1LL << ((unsigned __int8)__clz(v12) ^ 0x3Fu);
          if ( (unsigned int)v13 <= 0x1000 )
          {
LABEL_54:
            LODWORD(v13) = 4096;
          }
          else
          {
            v32 = (unsigned int)v13;
            while ( v32 > v12 || __clz(__rbit32(v13)) > v19 )
            {
              v32 = (unsigned int)v13 >> 1;
              v15 = (unsigned int)v13 > 0x2001;
              LODWORD(v13) = (unsigned int)v13 >> 1;
              if ( !v15 )
                goto LABEL_54;
            }
          }
        }
        else
        {
          v31 = v38;
          LODWORD(v13) = 0;
        }
        v17 = v31 + v26;
        v33 = (unsigned int)v13 - 1LL;
        v34 = __clz(v13);
        v5 = a3;
        if ( v33 >= 0x1000 )
          v21 = 64 - __clz(v33 >> 12);
        else
          v21 = 0;
      }
      else
      {
        v18 = v21-- != 0;
        if ( v21 == 0 || !v18 )
          return;
        if ( v21 <= 0x13 )
        {
          v13 = 4096LL << v21;
          if ( (unsigned int)(4096LL << v21) <= 0x1000 )
          {
LABEL_69:
            LODWORD(v13) = 4096;
          }
          else
          {
            v35 = 31 - __clz(v13);
            v36 = (4096LL << v21) & 0xFFFFF000LL;
            while ( v36 > ((4096LL << v21) & 0xFFFFF000uLL) || __clz(__rbit32(v13)) > v35 )
            {
              v36 = (unsigned int)v13 >> 1;
              v15 = (unsigned int)v13 > 0x2001;
              LODWORD(v13) = (unsigned int)v13 >> 1;
              if ( !v15 )
                goto LABEL_69;
            }
          }
        }
        else
        {
          LODWORD(v13) = 0;
        }
        v34 = __clz(v13);
      }
      v19 = 31 - v34;
      if ( !v12 )
      {
        if ( v17 < 1 )
          return;
        v6 = *v7;
        goto LABEL_5;
      }
    }
  }
}
