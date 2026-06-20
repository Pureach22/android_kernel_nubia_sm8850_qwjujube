__int64 __fastcall synx_debugfs_util_print_hash_table(_QWORD *a1, __int64 *a2, char a3)
{
  __int64 v3; // x8
  __int64 v7; // x0
  __int64 v8; // x1
  int v9; // w0
  __int64 v10; // x0
  __int16 v11; // w9
  __int64 v12; // x8
  __int64 result; // x0
  unsigned int v14; // w21
  const char *v15; // x24
  int v16; // w23
  unsigned __int64 *map_entry; // x0
  unsigned __int64 *v18; // x27
  unsigned __int64 v19; // x28
  __int16 v20; // w9
  __int64 v21; // x8
  __int64 v22; // x22
  int v23; // w26
  const char *v24; // x23
  __int64 v25; // x24
  unsigned int object_status; // w0
  const char *v27; // x3
  __int64 v28; // x1
  __int64 v29; // x0
  __int64 v30; // x1

  v3 = *a2;
  if ( (a3 & 1) == 0 )
  {
    v9 = scnprintf(*a1, v3 - *a1, "\n\t-------------LOCAL MAP TABLE------------\n");
    goto LABEL_5;
  }
  v7 = *a1;
  v8 = v3 - *a1;
  if ( (v8 & 0x1FFFFFFFFFFFFFFFLL) != 6 )
  {
    v9 = scnprintf(v7, v8, "\n\t-------------GLOBAL MAP TABLE------------\n");
LABEL_5:
    v7 = *a1 + v9;
    *a1 = v7;
  }
  v10 = *a1 + (int)scnprintf(v7, *a2 - v7, "\n\t\t");
  *a1 = v10;
  v11 = synx_columns;
  v12 = *a2;
  if ( (synx_columns & 8) != 0 && ((v12 - v10) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v10 = *a1 + (int)scnprintf(v10, v12 - v10, "|  STATUS  |");
    *a1 = v10;
    v11 = synx_columns;
    v12 = *a2;
  }
  if ( (v11 & 2) != 0 && ((v12 - v10) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v10 = *a1 + (int)scnprintf(v10, v12 - v10, "|  HANDLE  |");
    *a1 = v10;
    v11 = synx_columns;
    v12 = *a2;
  }
  if ( (v11 & 0x200) != 0 && ((v12 - v10) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v10 = *a1 + (int)scnprintf(v10, v12 - v10, "|  REF CNT |");
    *a1 = v10;
    v11 = synx_columns;
    v12 = *a2;
  }
  if ( (v11 & 4) != 0 && (unsigned __int64)(8 * (v12 - v10) - 18) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v10 = *a1 + (int)scnprintf(v10, v12 - v10, "| NUM BOUND |");
    *a1 = v10;
    v11 = synx_columns;
    v12 = *a2;
  }
  if ( (v11 & 0x40) != 0 && ((v12 - v10) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v10 = *a1 + (int)scnprintf(v10, v12 - v10, "| GLOBAL INDEX |");
    *a1 = v10;
    v11 = synx_columns;
    v12 = *a2;
  }
  if ( (v11 & 0x100) != 0 && ((v12 - v10) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v10 = *a1 + (int)scnprintf(v10, v12 - v10, "|  MAP CNT |");
    *a1 = v10;
    v12 = *a2;
  }
  result = scnprintf(v10, v12 - v10, "\n");
  *a1 += (int)result;
  v14 = lower_handle_id;
  if ( lower_handle_id <= (unsigned int)upper_handle_id )
  {
    v15 = "-----------------------------------------";
    v16 = a3 & 1;
    do
    {
      map_entry = (unsigned __int64 *)synx_util_get_map_entry(v14);
      v18 = map_entry;
      if ( map_entry )
      {
        if ( (unsigned __int64)map_entry <= 0xFFFFFFFFFFFFF000LL )
        {
          v19 = *map_entry;
          if ( *map_entry )
          {
            if ( v19 <= 0xFFFFFFFFFFFFF000LL && v16 == (v14 & 0x100000) >> 20 )
            {
              synx_util_get_object(*map_entry);
              mutex_lock(v19 + 72);
              v20 = synx_columns;
              v21 = *a2;
              v22 = *a1;
              if ( (synx_columns & 8) != 0 )
              {
                v23 = v16;
                v24 = v15;
                v25 = v21 - v22;
                if ( ((v21 - v22) & 0x1FFFFFFFFFFFFFFFLL) != 1 )
                {
                  object_status = synx_util_get_object_status(*v18);
                  if ( object_status >= 7 )
                  {
                    if ( object_status <= 0x40 )
                      v27 = "???";
                    else
                      v27 = "CUS";
                  }
                  else
                  {
                    v27 = (&off_24EC0)[object_status];
                  }
                  v22 = *a1 + (int)scnprintf(v22, v25, "\t\t%s", v27);
                  *a1 = v22;
                  v20 = synx_columns;
                  v21 = *a2;
                }
                v15 = v24;
                v16 = v23;
              }
              if ( (v20 & 2) != 0 && (unsigned __int64)(8 * (v21 - v22) - 11) <= 0xFFFFFFFFFFFFFFFALL )
              {
                v22 = *a1 + (int)scnprintf(v22, v21 - v22, "\t\t  %x", *((_DWORD *)v18 + 4));
                *a1 = v22;
                v20 = synx_columns;
                v21 = *a2;
              }
              if ( (v20 & 0x200) != 0 && (unsigned __int64)(8 * (v21 - v22) - 10) <= 0xFFFFFFFFFFFFFFFALL )
              {
                v22 = *a1 + (int)scnprintf(v22, v21 - v22, "\t  %d", *((_DWORD *)v18 + 2));
                *a1 = v22;
                v20 = synx_columns;
                v21 = *a2;
              }
              if ( (v20 & 4) != 0 && (unsigned __int64)(8 * (v21 - v22) - 10) <= 0xFFFFFFFFFFFFFFFALL )
              {
                v22 = *a1 + (int)scnprintf(v22, v21 - v22, "\t  %d", *(_DWORD *)(*v18 + 132));
                *a1 = v22;
                v20 = synx_columns;
                v21 = *a2;
              }
              if ( (v20 & 0x40) != 0 && (unsigned __int64)(8 * (v21 - v22) - 11) <= 0xFFFFFFFFFFFFFFFALL )
              {
                v22 = *a1 + (int)scnprintf(v22, v21 - v22, "\t\t  %d", *(_DWORD *)(*v18 + 344));
                *a1 = v22;
                v20 = synx_columns;
                v21 = *a2;
              }
              if ( (v20 & 0x100) != 0 && (unsigned __int64)(8 * (v21 - v22) - 11) <= 0xFFFFFFFFFFFFFFFALL )
              {
                v22 = *a1 + (int)scnprintf(v22, v21 - v22, "\t\t  %d", *(_DWORD *)(*v18 + 348));
                *a1 = v22;
                v21 = *a2;
              }
              v28 = v21 - v22;
              if ( (unsigned __int64)(8 * (v21 - v22) - 44) <= 0xFFFFFFFFFFFFFFFALL )
              {
                v22 = *a1 + (int)scnprintf(v22, v28, "\n\t-------------------------------------");
                *a1 = v22;
                v28 = *a2 - v22;
              }
              v29 = *a1 + (int)scnprintf(v22, v28, v15);
              *a1 = v29;
              v30 = *a2 - v29;
              if ( (v30 & 0x1FFFFFFFFFFFFFFFLL) != 2 )
                *a1 += (int)scnprintf(v29, v30, "-----------\n");
              mutex_unlock(v19 + 72);
              synx_util_put_object(v19);
            }
          }
        }
      }
      result = synx_util_release_map_entry(v18);
      ++v14;
    }
    while ( v14 <= upper_handle_id );
  }
  return result;
}
