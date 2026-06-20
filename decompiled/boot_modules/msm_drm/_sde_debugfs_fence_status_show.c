__int64 __fastcall sde_debugfs_fence_status_show(__int64 a1)
{
  int *v1; // x24
  __int64 v2; // x25
  __int64 v3; // x19
  __int64 *i; // x26
  __int64 result; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 lock; // x0
  __int64 v9; // x23
  unsigned int v10; // w8
  unsigned int v12; // w28
  unsigned int v18; // w9
  __int64 v19; // x0
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x8
  _QWORD v24[2]; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = a1;
  if ( a1 && (v1 = *(int **)(a1 + 128)) != nullptr )
  {
    v24[0] = 0;
    v24[1] = 0;
    v2 = *((_QWORD *)v1 + 251);
    v3 = *(_QWORD *)v1;
    if ( *((_BYTE *)v1 + 6040) == 1 )
    {
      seq_write(a1, "===Input fence===\n", 18);
      for ( i = *(__int64 **)(*(_QWORD *)v1 + 840LL); i != (__int64 *)(*(_QWORD *)v1 + 840LL); i = (__int64 *)*i )
      {
        if ( ((*(_DWORD *)(*((_QWORD *)v1 + 251) + 12LL) >> *((_DWORD *)i + 437)) & 1) != 0 )
        {
          v6 = i[220];
          if ( v6 )
          {
            seq_printf(v25[0], "plane:%u stage:%d\n", *((_DWORD *)i + 24), *(_DWORD *)(v6 + 1760));
            v7 = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "_sde_debugfs_fence_status_show",
                   8725,
                   -1,
                   v1[28],
                   *((_DWORD *)i + 24),
                   *(_QWORD *)(v6 + 1752),
                   -1059143953,
                   v24[0]);
            if ( *(_QWORD *)(v6 + 1752) )
            {
              lock = _rcu_read_lock(v7);
              v9 = *(_QWORD *)(v6 + 1752);
              _X22 = (unsigned int *)(v9 + 56);
              v10 = *(_DWORD *)(v9 + 56);
              if ( v10 )
              {
                do
                {
                  __asm { PRFM            #0x11, [X22] }
                  do
                    v18 = __ldxr(_X22);
                  while ( v18 == v10 && __stxr(v10 + 1, _X22) );
                  v12 = v10;
                  if ( v18 == v10 )
                    break;
                  v12 = 0;
                  v10 = v18;
                }
                while ( v18 );
              }
              else
              {
                v12 = 0;
              }
              if ( (((v12 + 1) | v12) & 0x80000000) != 0 )
              {
                v19 = refcount_warn_saturate(_X22, 0);
                _rcu_read_unlock(v19);
                if ( v9 )
                {
LABEL_22:
                  if ( v12 )
                  {
                    sde_fence_list_dump(v9, v25);
                    __asm { PRFM            #0x11, [X22] }
                    do
                      v21 = __ldxr(_X22);
                    while ( __stlxr(v21 - 1, _X22) );
                    if ( v21 == 1 )
                    {
                      __dmb(9u);
                      dma_fence_release(_X22);
                    }
                    else if ( v21 <= 0 )
                    {
                      refcount_warn_saturate(_X22, 3);
                    }
                  }
                }
              }
              else
              {
                _rcu_read_unlock(lock);
                if ( v9 )
                  goto LABEL_22;
              }
            }
          }
        }
      }
    }
    seq_putc(v25[0], 10);
    seq_write(v25[0], "===Release fence===\n", 20);
    sde_debugfs_timeline_dump(*((_QWORD *)v1 + 404), v1 + 28, v25);
    seq_putc(v25[0], 10);
    seq_write(v25[0], "===Retire fence===\n", 19);
    drm_connector_list_iter_begin(v3, v24);
    while ( 1 )
    {
      v22 = drm_connector_list_iter_next(v24);
      if ( !v22 )
        break;
      v23 = *(_QWORD *)(v22 + 2512);
      if ( v23 && *(int **)(v23 + 8) == v1 && *(int *)(v2 + 464) <= 15 )
        sde_debugfs_timeline_dump(*(_QWORD *)(v22 + 2864), v22 + 64, v25);
    }
    drm_connector_list_iter_end(v24);
    seq_putc(v25[0], 10);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
