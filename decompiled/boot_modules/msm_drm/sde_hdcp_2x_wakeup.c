__int64 __fastcall sde_hdcp_2x_wakeup(__int64 a1)
{
  __int64 v1; // x21
  int v3; // w8
  int v4; // w5
  int v5; // w6
  int v6; // w8
  int v7; // w8
  unsigned int v8; // w9
  int v10; // w8
  unsigned int v11; // w9
  __int64 v12; // x20
  __int64 v13; // x23
  __int64 v14; // x22
  char v15; // w8
  _QWORD *v16; // x25
  _QWORD *v17; // x0
  unsigned __int8 *v18; // x10
  int v19; // w9
  int v20; // w10
  _QWORD *v21; // x8
  __int64 v22; // x9
  _QWORD *v23; // x9
  unsigned int v24; // w10
  unsigned int v25; // w10
  int v26; // w8
  unsigned int v27; // w9
  __int64 v28; // x22
  __int64 v29; // x24
  __int64 v30; // x23
  char v31; // w28
  __int64 *v32; // x20
  unsigned int v35; // w10
  unsigned int v36; // w9
  unsigned __int8 *v37; // x9
  __int64 *v38; // x8
  int v39; // w26
  int v40; // w27
  __int64 v41; // x0
  __int64 *v42; // x2
  unsigned int v49; // w8
  char v50; // [xsp+0h] [xbp-10h]

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
    return 4294967274LL;
  *(_DWORD *)(v1 + 120) = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(v1 + 128) = *(_DWORD *)(a1 + 16);
  if ( (completion_done(v1 + 224) & 1) == 0 )
    complete_all(v1 + 224);
  v3 = *(_DWORD *)a1;
  if ( *(int *)a1 <= 4 )
  {
    switch ( v3 )
    {
      case 1:
        _X10 = (unsigned int *)(v1 + 132);
        __asm { PRFM            #0x11, [X10] }
        while ( 1 )
        {
          v49 = __ldxr(_X10);
          if ( v49 )
            break;
          if ( !__stlxr(1u, _X10) )
          {
            __dmb(0xBu);
            break;
          }
        }
        if ( v49 )
          return 0;
        v10 = *(_DWORD *)v1;
        v11 = *(_DWORD *)(v1 + 8);
        v24 = *(_DWORD *)v1 - *(_DWORD *)(v1 + 4);
        *(_DWORD *)(v1 + 180) = *(_DWORD *)(a1 + 4);
        if ( v24 > v11 )
          goto LABEL_42;
        break;
      case 2:
        _X8 = (unsigned int *)(v1 + 176);
        __asm { PRFM            #0x11, [X8] }
        do
          v35 = __ldxr(_X8);
        while ( __stlxr(1u, _X8) );
        __dmb(0xBu);
        v26 = *(_DWORD *)v1;
        if ( !v35 )
        {
          v36 = *(_DWORD *)(v1 + 8);
          if ( v26 - *(_DWORD *)(v1 + 4) <= v36 )
          {
            *(_DWORD *)(v1 + 4LL * (v36 & v26) + 24) = 5;
            __dmb(0xAu);
            v26 = *(_DWORD *)v1 + 1;
            *(_DWORD *)v1 = v26;
          }
        }
        v27 = *(_DWORD *)(v1 + 8);
        if ( v26 - *(_DWORD *)(v1 + 4) > v27 )
          goto LABEL_56;
        goto LABEL_55;
      case 3:
        *(_BYTE *)(v1 + 136) = 0;
        *(_WORD *)(v1 + 168) = 0;
        *(_BYTE *)(v1 + 139) = 0;
        *(_DWORD *)(v1 + 172) = 0;
        *(_DWORD *)(v1 + 120) = 0;
        *(_DWORD *)(v1 + 176) = 0;
        v10 = *(_DWORD *)v1;
        v11 = *(_DWORD *)(v1 + 8);
        if ( *(_DWORD *)v1 - *(_DWORD *)(v1 + 4) > v11 )
        {
LABEL_42:
          kthread_unpark(*(_QWORD *)(v1 + 216));
          goto LABEL_79;
        }
        break;
      default:
LABEL_43:
        v25 = *(_DWORD *)(v1 + 8);
        if ( *(_DWORD *)v1 - *(_DWORD *)(v1 + 4) <= v25 )
        {
          *(_DWORD *)(v1 + 4LL * (v25 & *(_DWORD *)v1) + 24) = v3;
          __dmb(0xAu);
LABEL_78:
          ++*(_DWORD *)v1;
        }
LABEL_79:
        _wake_up(v1 + 56, 3, 1, 0);
        return 0;
    }
    *(_DWORD *)(v1 + 4LL * (v11 & v10) + 24) = *(_DWORD *)a1;
    __dmb(0xAu);
    ++*(_DWORD *)v1;
    goto LABEL_42;
  }
  if ( v3 <= 14 )
  {
    if ( v3 != 5 )
    {
      if ( v3 == 14 )
      {
        v4 = *(unsigned __int8 *)(v1 + 184);
        v5 = *(unsigned __int8 *)(a1 + 24);
        if ( v4 != v5 )
        {
          sde_evtlog_log(sde_dbg_base_evtlog, "sde_hdcp_2x_wakeup", 934, 8, 14, v4, v5, -1059143953, v50);
          LOBYTE(v4) = *(_BYTE *)(a1 + 24);
        }
        v6 = *(unsigned __int8 *)(v1 + 139);
        *(_BYTE *)(v1 + 184) = v4;
        if ( v6 != 1 )
          return 0;
        v7 = *(_DWORD *)v1;
        v8 = *(_DWORD *)(v1 + 8);
        if ( *(_DWORD *)v1 - *(_DWORD *)(v1 + 4) > v8 )
          goto LABEL_79;
        goto LABEL_77;
      }
      goto LABEL_43;
    }
    *(_DWORD *)(v1 + 176) = 1;
    v26 = *(_DWORD *)v1;
    v27 = *(_DWORD *)(v1 + 8);
    if ( *(_DWORD *)v1 - *(_DWORD *)(v1 + 4) > v27 )
      goto LABEL_56;
LABEL_55:
    *(_DWORD *)(v1 + 4LL * (v27 & v26) + 24) = *(_DWORD *)a1;
    __dmb(0xAu);
    ++*(_DWORD *)v1;
LABEL_56:
    kthread_park(*(_QWORD *)(v1 + 216));
    return 0;
  }
  if ( v3 != 15 )
  {
    if ( v3 == 16 )
    {
      v12 = *(unsigned __int8 *)(a1 + 40);
      if ( !*(_BYTE *)(a1 + 40) )
        return 0;
      v13 = *(_QWORD *)(a1 + 32);
      v14 = 0;
      v15 = 0;
      v16 = (_QWORD *)(v1 + 192);
      do
      {
        v17 = (_QWORD *)*v16;
        if ( (_QWORD *)*v16 != v16 )
        {
          v18 = (unsigned __int8 *)(v13 + 2 * v14);
          v19 = *v18;
          v20 = v18[1];
          while ( *((unsigned __int8 *)v17 + 17) != v20 || *((unsigned __int8 *)v17 + 16) != v19 )
          {
            v17 = (_QWORD *)*v17;
            if ( v17 == v16 )
              goto LABEL_26;
          }
          if ( v17 )
          {
            if ( *((_DWORD *)v17 + 5) )
            {
              *((_BYTE *)v17 + 24) = 0;
            }
            else
            {
              --*(_BYTE *)(v1 + 208);
              v21 = (_QWORD *)v17[1];
              if ( (_QWORD *)*v21 == v17 && (v22 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
              {
                *(_QWORD *)(v22 + 8) = v21;
                *v21 = v22;
              }
              else
              {
                _list_del_entry_valid_or_report();
                v17 = v23;
              }
              *v17 = 0xDEAD000000000100LL;
              v17[1] = 0xDEAD000000000122LL;
              kfree(v17);
            }
            v15 = 1;
          }
        }
LABEL_26:
        ++v14;
      }
      while ( v14 != v12 );
      if ( (v15 & 1) == 0 )
        return 0;
      v7 = *(_DWORD *)v1;
      v8 = *(_DWORD *)(v1 + 8);
      if ( *(_DWORD *)v1 - *(_DWORD *)(v1 + 4) > v8 )
        goto LABEL_79;
      goto LABEL_77;
    }
    goto LABEL_43;
  }
  v28 = *(unsigned __int8 *)(a1 + 40);
  if ( *(_BYTE *)(a1 + 40) )
  {
    v29 = *(_QWORD *)(a1 + 32);
    v30 = 0;
    v31 = 0;
    v32 = (__int64 *)(v1 + 192);
    _ReadStatusReg(SP_EL0);
    while ( 2 )
    {
      while ( 2 )
      {
        v37 = (unsigned __int8 *)(v29 + 2 * v30);
        v38 = (__int64 *)*v32;
        v39 = *v37;
        v40 = v37[1];
        while ( v38 != v32 )
        {
          if ( *((unsigned __int8 *)v38 + 17) == v40 && *((unsigned __int8 *)v38 + 16) == v39 )
          {
            if ( v38 )
              goto LABEL_60;
            break;
          }
          v38 = (__int64 *)*v38;
        }
        v41 = _kmalloc_cache_noprof(wake_up_process, 3520, 32);
        if ( v41 )
        {
          *(_QWORD *)v41 = v41;
          *(_QWORD *)(v41 + 8) = v41;
          *(_DWORD *)(v41 + 20) = 0;
          *(_BYTE *)(v41 + 16) = v39;
          *(_BYTE *)(v41 + 17) = v40;
          *(_BYTE *)(v41 + 24) = 1;
          v42 = (__int64 *)*v32;
          if ( *(__int64 **)(*v32 + 8) != v32 || (__int64 *)v41 == v32 || v42 == (__int64 *)v41 )
          {
            _list_add_valid_or_report();
          }
          else
          {
            v42[1] = v41;
            *(_QWORD *)v41 = v42;
            *(_QWORD *)(v41 + 8) = v32;
            *v32 = v41;
          }
          ++v30;
          v31 = 1;
          ++*(_BYTE *)(v1 + 208);
          if ( v30 != v28 )
            continue;
          goto LABEL_76;
        }
        break;
      }
LABEL_60:
      if ( ++v30 != v28 )
        continue;
      break;
    }
    if ( (v31 & 1) == 0 )
      return 0;
LABEL_76:
    v7 = *(_DWORD *)v1;
    v8 = *(_DWORD *)(v1 + 8);
    if ( *(_DWORD *)v1 - *(_DWORD *)(v1 + 4) > v8 )
      goto LABEL_79;
LABEL_77:
    *(_DWORD *)(v1 + 4LL * (v8 & v7) + 24) = *(_DWORD *)a1;
    __dmb(0xAu);
    goto LABEL_78;
  }
  return 0;
}
