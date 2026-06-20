__int64 __fastcall clear_fence_array_tracker(char a1)
{
  __int64 *v2; // x20
  __int64 *v3; // x27
  __int64 v4; // x22
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  int v9; // w8
  __int64 **v10; // x8
  __int64 *v11; // x9
  unsigned int v18; // w8
  unsigned int v19; // w8

  mutex_lock(&unk_7BC0);
  v2 = (__int64 *)qword_7BF0;
  if ( (__int64 *)qword_7BF0 != &qword_7BF0 )
  {
    while ( 1 )
    {
      v3 = (__int64 *)*v2;
      v4 = *(v2 - 1);
      if ( (*(_QWORD *)(v4 + 48) & 1) != 0 )
        goto LABEL_12;
      v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v4 + 8) + 32LL);
      if ( !v5 )
        goto LABEL_13;
      v6 = *(v2 - 1);
      if ( *((_DWORD *)v5 - 1) != 1879296680 )
        __break(0x8228u);
      if ( (v5(v6) & 1) != 0 )
        break;
      LODWORD(v5) = 0;
      if ( (a1 & 1) != 0 )
      {
LABEL_14:
        if ( *(_QWORD *)(v4 + 80) )
        {
          if ( ((unsigned __int8)v5 & 1) != 0 )
            goto LABEL_21;
        }
        else
        {
          *(_DWORD *)(v4 + 68) = 0;
          if ( ((unsigned __int8)v5 & 1) != 0 )
          {
LABEL_21:
            if ( v4 )
            {
              _X0 = (unsigned int *)(v4 + 56);
              __asm { PRFM            #0x11, [X0] }
              do
                v9 = __ldxr(_X0);
              while ( __stlxr(v9 - 1, _X0) );
              if ( v9 == 1 )
              {
                __dmb(9u);
                dma_fence_release(_X0);
              }
              else if ( v9 <= 0 )
              {
                refcount_warn_saturate(_X0, 3);
              }
            }
            v10 = (__int64 **)v2[1];
            if ( *v10 == v2 && (v11 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
            {
              v11[1] = (__int64)v10;
              *v10 = v11;
            }
            else
            {
              _list_del_entry_valid_or_report(v2);
            }
            *v2 = 0xDEAD000000000100LL;
            v2[1] = 0xDEAD000000000122LL;
            kfree(v2 - 1);
            goto LABEL_5;
          }
        }
        _X9 = (unsigned int *)(v4 + 72);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v18 = __ldxr(_X9);
          v19 = v18 - 1;
        }
        while ( __stlxr(v19, _X9) );
        __dmb(0xBu);
        if ( !v19 )
          dma_fence_signal(v4);
        goto LABEL_21;
      }
LABEL_20:
      if ( (_DWORD)v5 )
        goto LABEL_21;
LABEL_5:
      v2 = v3;
      if ( v3 == &qword_7BF0 )
        return mutex_unlock(&unk_7BC0);
    }
    dma_fence_signal(v4);
LABEL_12:
    LODWORD(v5) = 1;
LABEL_13:
    if ( (a1 & 1) != 0 )
      goto LABEL_14;
    goto LABEL_20;
  }
  return mutex_unlock(&unk_7BC0);
}
