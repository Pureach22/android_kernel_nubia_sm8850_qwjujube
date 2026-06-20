__int64 __fastcall synx_debugfs_util_print_dma_fence(_QWORD *a1, __int64 *a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v6; // x1
  __int16 v7; // w9
  __int64 v8; // x9
  const char *v9; // x21
  _DWORD *v10; // x27
  __int64 v11; // x8
  unsigned __int64 v12; // x25
  __int64 v14; // x22
  _DWORD *v15; // x28
  unsigned int v17; // w9
  unsigned int v18; // w10
  __int16 v19; // w9
  __int64 v20; // x8
  __int64 v21; // x26
  _DWORD *v22; // x24
  const char *v23; // x27
  __int64 v24; // x21
  unsigned int v25; // w0
  const char *v26; // x3
  __int64 v27; // x1
  __int64 v28; // x1
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v32; // x1
  unsigned int v37; // w8
  int v39; // w8
  __int64 v41; // [xsp+8h] [xbp-8h]

  v3 = *a2;
  v4 = *a1;
  v6 = *a2 - v4;
  if ( (unsigned __int64)(8 * v6 - 52) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v6, "\n\t-------------DMA FENCE MAP TABLE------------\n");
    *a1 = v4;
    v3 = *a2;
  }
  v7 = synx_columns;
  if ( (synx_columns & 0x10) != 0 && (unsigned __int64)(8 * (v3 - v4) - 36) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|         DMA FENCE           |");
    *a1 = v4;
    v7 = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 8) != 0 && (unsigned __int64)(8 * (v3 - v4) - 19) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|   STATUS   |");
    *a1 = v4;
    v7 = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 2) != 0 )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|         HANDLE          |");
    *a1 = v4;
    v7 = synx_columns;
    v3 = *a2;
  }
  if ( (v7 & 0x200) != 0 && ((v3 - v4) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|    REF CNT   |");
    *a1 = v4;
    v3 = *a2;
  }
  *a1 += (int)scnprintf(v4, v3 - v4, "\n");
  raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
  v8 = 0;
  v9 = "-----------------------------------------";
  v10 = &_ksymtab_synx_async_wait;
  do
  {
    v41 = v8;
    v11 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * v8 + 2064);
    v12 = v11 - 16;
    if ( v11 )
      _ZF = v11 == 16;
    else
      _ZF = 1;
    if ( !_ZF )
    {
      do
      {
        v14 = *(_QWORD *)(v12 + 16);
        if ( v12 > 0xFFFFFFFFFFFFF000LL )
        {
LABEL_63:
          if ( !v14 )
            break;
          goto LABEL_64;
        }
        v15 = *(_DWORD **)(v12 + 8);
        if ( v15 )
        {
          _X0 = v15 + 14;
          __asm { PRFM            #0x11, [X0] }
          do
            v37 = __ldxr(_X0);
          while ( __stxr(v37 + 1, _X0) );
          if ( v37 )
          {
            if ( (((v37 + 1) | v37) & 0x80000000) == 0 )
              goto LABEL_24;
            v32 = 1;
          }
          else
          {
            v32 = 2;
          }
          refcount_warn_saturate(_X0, v32);
        }
LABEL_24:
        v17 = v10[712];
        if ( *(_DWORD *)v12 < v17 || *(_DWORD *)v12 > (unsigned int)upper_handle_id )
        {
          v18 = *(_DWORD *)(v12 + 4);
          if ( v18 < v17 || v18 > upper_handle_id )
            goto LABEL_51;
        }
        v19 = synx_columns;
        v20 = *a2;
        v21 = *a1;
        if ( (synx_columns & 0x10) != 0 )
        {
          v21 = *a1 + (int)scnprintf(*a1, v20 - v21, "\t%p", v15);
          *a1 = v21;
          v19 = synx_columns;
          v20 = *a2;
          if ( (synx_columns & 8) == 0 )
          {
LABEL_30:
            if ( (v19 & 2) != 0 )
              goto LABEL_42;
            goto LABEL_31;
          }
        }
        else if ( (synx_columns & 8) == 0 )
        {
          goto LABEL_30;
        }
        v22 = v10;
        v23 = v9;
        v24 = v20 - v21;
        if ( ((v20 - v21) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
        {
          v25 = _fence_state(v15, 0);
          if ( v25 >= 7 )
          {
            if ( v25 <= 0x40 )
              v26 = "???";
            else
              v26 = "CUS";
          }
          else
          {
            v26 = (&off_24EC0)[v25];
          }
          v21 = *a1 + (int)scnprintf(v21, v24, "\t\t%s", v26);
          *a1 = v21;
          v19 = synx_columns;
          v20 = *a2;
        }
        v9 = v23;
        v10 = v22;
        if ( (v19 & 2) != 0 )
        {
LABEL_42:
          v27 = v20 - v21;
          if ( ((v20 - v21) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v21 = *a1 + (int)scnprintf(v21, v27, "\t\t%d", *(_DWORD *)v12);
            *a1 = v21;
            v27 = *a2 - v21;
          }
          v21 = *a1 + (int)scnprintf(v21, v27, "\t%d", *(_DWORD *)(v12 + 4));
          *a1 = v21;
          v20 = *a2;
          if ( (synx_columns & 0x200) == 0 )
            goto LABEL_47;
LABEL_45:
          if ( ((v20 - v21) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v21 = *a1 + (int)scnprintf(v21, v20 - v21, "\t\t%d", v15[14]);
            *a1 = v21;
            v20 = *a2;
          }
          goto LABEL_47;
        }
LABEL_31:
        if ( (v19 & 0x200) != 0 )
          goto LABEL_45;
LABEL_47:
        v28 = v20 - v21;
        if ( (unsigned __int64)(8 * (v20 - v21) - 44) <= 0xFFFFFFFFFFFFFFFALL )
        {
          v21 = *a1 + (int)scnprintf(v21, v28, "\n\t-------------------------------------");
          *a1 = v21;
          v28 = *a2 - v21;
        }
        v29 = *a1 + (int)scnprintf(v21, v28, v9);
        *a1 = v29;
        v30 = *a2 - v29;
        if ( (v30 & 0x1FFFFFFFFFFFFFFFLL) != 2 )
          *a1 += (int)scnprintf(v29, v30, "-----------\n");
LABEL_51:
        if ( !v15 )
          goto LABEL_63;
        _X0 = v15 + 14;
        __asm { PRFM            #0x11, [X0] }
        do
          v39 = __ldxr(_X0);
        while ( __stlxr(v39 - 1, _X0) );
        if ( v39 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
          if ( !v14 )
            break;
        }
        else
        {
          if ( v39 > 0 )
            goto LABEL_63;
          refcount_warn_saturate(_X0, 3);
          if ( !v14 )
            break;
        }
LABEL_64:
        v12 = v14 - 16;
      }
      while ( v14 != 16 );
    }
    v8 = v41 + 1;
  }
  while ( v41 != 1023 );
  return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
}
