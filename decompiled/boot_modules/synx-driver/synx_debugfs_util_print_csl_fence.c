__int64 __fastcall synx_debugfs_util_print_csl_fence(_QWORD *a1, __int64 *a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v6; // x1
  _QWORD *v7; // x24
  __int16 v8; // w9
  __int64 i; // x21
  __int64 v10; // x8
  unsigned __int64 v11; // x23
  __int64 v13; // x27
  unsigned int v15; // w8
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x9
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x0
  __int64 v23; // x1
  _QWORD *map_entry; // x0
  _QWORD *v25; // x26
  unsigned __int64 v26; // x0
  _QWORD *v27; // x22
  __int64 v28; // x24
  __int64 v29; // x25
  unsigned int object_status; // w0
  const char *v31; // x3
  __int64 v32; // x1
  unsigned int v37; // w8
  int v39; // w8

  v3 = *a2;
  v4 = *a1;
  v6 = *a2 - v4;
  if ( (v6 & 0x1FFFFFFFFFFFFFFFLL) != 6 )
  {
    v4 = *a1 + (int)scnprintf(v4, v6, "\n\t------------- CSL FENCE MAP TABLE------------\n");
    *a1 = v4;
    v3 = *a2;
  }
  v7 = &_ksymtab_synx_async_wait;
  v8 = synx_columns;
  if ( (synx_columns & 0x10) != 0 && (unsigned __int64)(8 * (v3 - v4) - 35) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|           CSL FENCE        |");
    *a1 = v4;
    v8 = synx_columns;
    v3 = *a2;
  }
  if ( (v8 & 8) != 0 && (unsigned __int64)(8 * (v3 - v4) - 19) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|   STATUS   |");
    *a1 = v4;
    v8 = synx_columns;
    v3 = *a2;
  }
  if ( (v8 & 2) != 0 && (unsigned __int64)(8 * (v3 - v4) - 20) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|    HANDLE   |");
    *a1 = v4;
    v8 = synx_columns;
    v3 = *a2;
  }
  if ( (v8 & 0x200) != 0 && ((v3 - v4) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v4 = *a1 + (int)scnprintf(v4, v3 - v4, "|    REF CNT   |");
    *a1 = v4;
    v3 = *a2;
  }
  *a1 += (int)scnprintf(v4, v3 - v4, "\n");
  raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
  for ( i = 0; i != 256; ++i )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * i + 20520);
    v11 = v10 - 24;
    if ( v10 )
      _ZF = v10 == 24;
    else
      _ZF = 1;
    if ( !_ZF )
    {
      while ( 1 )
      {
        if ( v11 > 0xFFFFFFFFFFFFF000LL )
          return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
        v13 = *(_QWORD *)(v11 + 24);
        _X28 = (unsigned int *)(v11 + 16);
        __asm { PRFM            #0x11, [X28] }
        do
          v37 = __ldxr(_X28);
        while ( __stxr(v37 + 1, _X28) );
        if ( !v37 )
          break;
        if ( (((v37 + 1) | v37) & 0x80000000) != 0 )
        {
          v32 = 1;
LABEL_56:
          refcount_warn_saturate(v11 + 16, v32);
        }
        v15 = *(_DWORD *)(v11 + 8);
        if ( v15 >= lower_handle_id && v15 <= upper_handle_id )
        {
          v16 = v7[357];
          if ( (v16 & 0x10) != 0 )
          {
            v17 = *a2 - *a1;
            if ( (v17 & 0x1FFFFFFFFFFFFFFFLL) != 1 )
            {
              *a1 += (int)scnprintf(*a1, v17, "%llu", *(_QWORD *)v11);
              v16 = v7[357];
            }
          }
          if ( (v16 & 8) != 0 )
          {
            map_entry = (_QWORD *)synx_util_get_map_entry(*(unsigned int *)(v11 + 8));
            if ( map_entry )
            {
              v25 = map_entry;
              if ( (unsigned __int64)map_entry <= 0xFFFFFFFFFFFFF000LL )
              {
                v26 = *map_entry;
                if ( *v25 )
                {
                  if ( v26 <= 0xFFFFFFFFFFFFF000LL )
                  {
                    v27 = v7;
                    v28 = *a2;
                    v29 = *a1;
                    object_status = synx_util_get_object_status(v26);
                    if ( object_status >= 7 )
                    {
                      if ( object_status <= 0x40 )
                        v31 = "???";
                      else
                        v31 = "CUS";
                    }
                    else
                    {
                      v31 = (&off_24EC0)[object_status];
                    }
                    *a1 += (int)scnprintf(v29, v28 - v29, "\t%s", v31);
                    synx_util_release_map_entry(v25);
                    v7 = v27;
                  }
                }
              }
            }
          }
          v18 = v7[357];
          v19 = *a2;
          v20 = *a1;
          if ( (v18 & 2) != 0 && ((v19 - v20) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v20 = *a1 + (int)scnprintf(v20, v19 - v20, "\t\t%d", *(_DWORD *)(v11 + 8));
            *a1 = v20;
            v18 = v7[357];
            v19 = *a2;
          }
          if ( (v18 & 0x200) != 0 )
          {
            v20 = *a1 + (int)scnprintf(v20, v19 - v20, "\t%d", *_X28);
            *a1 = v20;
            v19 = *a2;
          }
          v21 = v19 - v20;
          if ( (unsigned __int64)(8 * (v19 - v20) - 44) <= 0xFFFFFFFFFFFFFFFALL )
          {
            v20 = *a1 + (int)scnprintf(v20, v21, "\n\t-------------------------------------");
            *a1 = v20;
            v21 = *a2 - v20;
          }
          v22 = *a1 + (int)scnprintf(v20, v21, "-----------------------------------------");
          *a1 = v22;
          v23 = *a2 - v22;
          if ( (v23 & 0x1FFFFFFFFFFFFFFFLL) != 2 )
            *a1 += (int)scnprintf(v22, v23, "-----------\n");
        }
        __asm { PRFM            #0x11, [X28] }
        do
          v39 = __ldxr(_X28);
        while ( __stlxr(v39 - 1, _X28) );
        if ( v39 == 1 )
        {
          __dmb(9u);
          synx_util_destroy_data(v11 + 16);
          if ( !v13 )
            goto LABEL_16;
        }
        else if ( v39 <= 0 )
        {
          refcount_warn_saturate(v11 + 16, 3);
          if ( !v13 )
            goto LABEL_16;
        }
        else if ( !v13 )
        {
          goto LABEL_16;
        }
        v11 = v13 - 24;
        if ( v13 == 24 )
          goto LABEL_16;
      }
      v32 = 2;
      goto LABEL_56;
    }
LABEL_16:
    ;
  }
  return raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
}
