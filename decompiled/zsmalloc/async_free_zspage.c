__int64 __fastcall async_free_zspage(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x24
  __int64 v4; // x20
  __int64 v5; // x9
  __int64 v6; // x10
  _QWORD *v7; // x11
  _QWORD *v8; // x20
  __int64 v9; // x19
  _QWORD *v10; // x8
  _QWORD *v11; // x25
  unsigned int *v12; // x21
  __int64 v13; // x22
  __int64 v14; // x9
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x8
  unsigned int v23; // w9
  unsigned int v26; // w23
  unsigned int v27; // w23
  unsigned __int64 v33; // x9
  int v34; // w8
  __int64 v35; // x23
  __int64 v36; // x8
  __int64 v38; // x9
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x8
  unsigned int v45; // w9
  unsigned int v48; // w26
  unsigned int v49; // w26
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x8
  __int64 v53; // x20
  _QWORD v54[3]; // [xsp+8h] [xbp-18h] BYREF

  v1 = result;
  v2 = 0;
  v3 = result - 2080;
  v54[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54[0] = v54;
  v54[1] = v54;
  do
  {
    v4 = *(_QWORD *)(v3 + 8 * v2);
    if ( v2 == *(_DWORD *)(v4 + 212) )
    {
      raw_spin_lock(*(_QWORD *)(v3 + 8 * v2));
      v5 = *(_QWORD *)(v4 + 8);
      if ( v5 != v4 + 8 )
      {
        v6 = v54[0];
        v7 = *(_QWORD **)(v4 + 16);
        *(_QWORD *)(v5 + 8) = v54;
        v54[0] = v5;
        *v7 = v6;
        *(_QWORD *)(v6 + 8) = v7;
        *(_QWORD *)(v4 + 8) = v4 + 8;
        *(_QWORD *)(v4 + 16) = v4 + 8;
      }
      result = raw_spin_unlock(v4);
    }
    ++v2;
  }
  while ( v2 != 255 );
  v8 = (_QWORD *)v54[0];
  if ( (_QWORD *)v54[0] != v54 )
  {
    v9 = v1 - 2088;
    do
    {
      v11 = (_QWORD *)*v8;
      v10 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v10 == v8 && (_QWORD *)v11[1] == v8 )
      {
        v11[1] = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      v12 = (unsigned int *)(v8 - 3);
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      while ( 1 )
      {
        raw_read_lock(v8 + 3);
        v13 = *(v8 - 1);
        v14 = *(_QWORD *)(v13 + 8);
        _X8 = (unsigned __int64 *)v13;
        if ( (v14 & 1) != 0 )
        {
          _X8 = (unsigned __int64 *)(v14 - 1);
          if ( (*(_QWORD *)(v14 - 1) & 1) != 0 )
            goto LABEL_16;
        }
        else if ( (*(_QWORD *)v13 & 1) != 0 )
        {
          goto LABEL_16;
        }
        __asm { PRFM            #0x11, [X8] }
        do
          v33 = __ldaxr(_X8);
        while ( __stxr(v33 | 1, _X8) );
        if ( (v33 & 1) == 0 )
          break;
LABEL_16:
        v16 = *(_QWORD *)(v13 + 8);
        v17 = v13;
        if ( (v16 & 1) != 0 )
          v17 = v16 - 1;
        _X8 = (unsigned int *)(v17 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
          v23 = __ldxr(_X8);
        while ( __stxr(v23 + 1, _X8) );
        raw_read_unlock(v8 + 3);
        v18 = *(_QWORD *)(v13 + 8);
        v19 = v13;
        if ( (v18 & 1) != 0 )
        {
          v19 = v18 - 1;
          if ( (*(_QWORD *)(v18 - 1) & 1) == 0 )
          {
LABEL_21:
            v20 = *(_QWORD *)(v13 + 8);
            if ( (v20 & 1) != 0 )
              goto LABEL_29;
            goto LABEL_32;
          }
        }
        else if ( (*(_QWORD *)v13 & 1) == 0 )
        {
          goto LABEL_21;
        }
        folio_wait_bit(v19, 0);
        v20 = *(_QWORD *)(v13 + 8);
        if ( (v20 & 1) != 0 )
LABEL_29:
          v13 = v20 - 1;
LABEL_32:
        _X8 = (unsigned int *)(v13 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v26 = __ldxr(_X8);
          v27 = v26 - 1;
        }
        while ( __stlxr(v27, _X8) );
        __dmb(0xBu);
        if ( !v27 )
          _folio_put(v13);
      }
      v34 = **(_DWORD **)(v13 + 40);
      if ( (v34 & 0x3FC000) != 0x160000 )
      {
LABEL_74:
        __break(0x800u);
        JUMPOUT(0xFFFFFFFFFD7C1400LL);
      }
      while ( 2 )
      {
        if ( (v34 & 1) == 0 )
        {
          v35 = *(_QWORD *)(v13 + 32);
          if ( v35 )
          {
            v36 = *(_QWORD *)(v35 + 8);
            if ( (v36 & 1) != 0 )
              _X8 = (unsigned __int64 *)(v36 - 1);
            else
              _X8 = *(unsigned __int64 **)(v13 + 32);
            if ( (*_X8 & 1) != 0 )
              goto LABEL_47;
            __asm { PRFM            #0x11, [X8] }
            do
              v51 = __ldaxr(_X8);
            while ( __stxr(v51 | 1, _X8) );
            if ( (v51 & 1) != 0 )
            {
LABEL_47:
              v38 = *(_QWORD *)(v35 + 8);
              v39 = v35;
              if ( (v38 & 1) != 0 )
                v39 = v38 - 1;
              _X8 = (unsigned int *)(v39 + 52);
              __asm { PRFM            #0x11, [X8] }
              do
                v45 = __ldxr(_X8);
              while ( __stxr(v45 + 1, _X8) );
              raw_read_unlock(v8 + 3);
              v40 = *(_QWORD *)(v35 + 8);
              v41 = v35;
              if ( (v40 & 1) != 0 )
              {
                v41 = v40 - 1;
                if ( (*(_QWORD *)(v40 - 1) & 1) != 0 )
                  goto LABEL_57;
LABEL_52:
                v42 = *(_QWORD *)(v35 + 8);
                if ( (v42 & 1) != 0 )
LABEL_58:
                  v35 = v42 - 1;
              }
              else
              {
                if ( (*(_QWORD *)v35 & 1) == 0 )
                  goto LABEL_52;
LABEL_57:
                folio_wait_bit(v41, 0);
                v42 = *(_QWORD *)(v35 + 8);
                if ( (v42 & 1) != 0 )
                  goto LABEL_58;
              }
              _X8 = (unsigned int *)(v35 + 52);
              __asm { PRFM            #0x11, [X8] }
              do
              {
                v48 = __ldxr(_X8);
                v49 = v48 - 1;
              }
              while ( __stlxr(v49, _X8) );
              __dmb(0xBu);
              if ( !v49 )
                _folio_put(v35);
              raw_read_lock(v8 + 3);
              v35 = v13;
            }
            v13 = v35;
            v34 = **(_DWORD **)(v35 + 40);
            if ( (v34 & 0x3FC000) != 0x160000 )
              goto LABEL_74;
            continue;
          }
        }
        break;
      }
      raw_read_unlock(v8 + 3);
      v52 = ((unsigned __int64)*v12 >> 5) & 0x1FF;
      if ( (unsigned int)v52 >= 0xFF )
        __break(0x5512u);
      v53 = *(_QWORD *)(v3 + 8 * v52);
      raw_spin_lock(v53);
      --*(_QWORD *)(v53 + 216);
      _free_zspage(v9, (unsigned int *)v53, (__int64)v12);
      result = raw_spin_unlock(v53);
      v8 = v11;
    }
    while ( v11 != v54 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
