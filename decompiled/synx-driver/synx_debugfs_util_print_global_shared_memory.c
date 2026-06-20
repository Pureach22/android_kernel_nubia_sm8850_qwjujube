__int64 __fastcall synx_debugfs_util_print_global_shared_memory(__int64 *a1, __int64 *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x9
  __int16 v8; // w9
  __int64 result; // x0
  unsigned int i; // w21
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x1
  __int16 v14; // w8
  __int64 v15; // x1
  const char *v16; // x3
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x1
  __int64 v22; // x1
  __int64 v23; // x1
  __int64 v24; // x1
  __int64 v25; // x1
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  __int64 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v5 = *a1;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v6 = v4 - v5;
  v26 = 0;
  v7 = 8 * (v4 - v5);
  if ( (unsigned __int64)(v7 - 58) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v5 = *a1 + (int)scnprintf(v5, v6, "\n\t  ------------- GLOBAL SHARED MEMORY ------------\n\t");
    *a1 = v5;
    v4 = *a2;
    v6 = *a2 - v5;
    v7 = 8 * v6;
  }
  if ( (unsigned __int64)(v7 - 12) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v5 = *a1 + (int)scnprintf(v5, v6, "| IDX |");
    *a1 = v5;
    v4 = *a2;
  }
  v8 = synx_columns;
  if ( (synx_columns & 8) != 0 && ((v4 - v5) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "|  STATUS  |");
    *a1 = v5;
    v8 = synx_columns;
    v4 = *a2;
  }
  if ( (v8 & 2) != 0 && (unsigned __int64)(8 * (v4 - v5) - 18) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "|  HANDLE   |");
    *a1 = v5;
    v8 = synx_columns;
    v4 = *a2;
  }
  if ( (v8 & 0x200) != 0 && ((v4 - v5) & 0x1FFFFFFFFFFFFFFFLL) != 2 )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "|  REF CNT |");
    *a1 = v5;
    v8 = synx_columns;
    v4 = *a2;
  }
  if ( (v8 & 0x400) != 0 && (unsigned __int64)(8 * (v4 - v5) - 18) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "| NUM CHILD |");
    *a1 = v5;
    v8 = synx_columns;
    v4 = *a2;
  }
  if ( (v8 & 0x800) != 0 && (unsigned __int64)(8 * (v4 - v5) - 20) <= 0xFFFFFFFFFFFFFFFALL )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "| SUBSCRIBERS |");
    *a1 = v5;
    v8 = synx_columns;
    v4 = *a2;
  }
  if ( (v8 & 0x1000) != 0 )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "| WAITERS |");
    *a1 = v5;
    v8 = synx_columns;
    v4 = *a2;
  }
  if ( (v8 & 0x2000) != 0 )
  {
    v5 = *a1 + (int)scnprintf(v5, v4 - v5, "|    PARENTS    |");
    *a1 = v5;
    v4 = *a2;
  }
  result = scnprintf(v5, v4 - v5, "\n");
  *a1 += (int)result;
  for ( i = lower_handle_id; i <= upper_handle_id; ++i )
  {
    result = synx_encode_handle(4095, 7, 1);
    if ( (i & 0x80000) == 0
      && i > 0x100000
      && (unsigned int)result >= i
      && (i & 0x100000) != 0
      && (unsigned int)(unsigned __int16)i - 1 <= 0xFFE )
    {
      result = synx_fetch_global_shared_memory_handle_details(i, &v26);
      if ( (result & 1) != 0
        && (v26
         || (_WORD)v27
         || __PAIR32__(WORD1(v27), 0) != WORD2(v27)
         || __PAIR32__(HIWORD(v27), 0) != (unsigned __int16)v28
         || WORD1(v28)
         || WORD2(v28)
         || HIWORD(v28)) )
      {
        v12 = *a1;
        v13 = *a2 - *a1;
        if ( (unsigned __int64)(8 * v13 - 12) <= 0xFFFFFFFFFFFFFFFALL )
        {
          v12 = *a1 + (int)scnprintf(v12, v13, "\t  %llu", (unsigned __int16)i);
          *a1 = v12;
        }
        v14 = synx_columns;
        if ( (synx_columns & 8) != 0 )
        {
          v15 = *a2 - v12;
          if ( (v15 & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            if ( (unsigned int)v26 >= 7 )
            {
              if ( (unsigned int)v26 <= 0x40 )
                v16 = "???";
              else
                v16 = "CUS";
            }
            else
            {
              v16 = (&off_24EC0)[(unsigned int)v26];
            }
            v12 = *a1 + (int)scnprintf(v12, v15, "\t %s", v16);
            *a1 = v12;
            v14 = synx_columns;
          }
        }
        if ( (v14 & 2) != 0 )
        {
          v17 = *a2 - v12;
          if ( (v17 & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v12 = *a1 + (int)scnprintf(v12, v17, "\t\t%x", HIDWORD(v26));
            *a1 = v12;
            v14 = synx_columns;
          }
        }
        if ( (v14 & 0x200) != 0 )
        {
          v18 = *a2 - v12;
          if ( (v18 & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v12 = *a1 + (int)scnprintf(v12, v18, "\t\t%d", (unsigned __int16)v27);
            *a1 = v12;
            v14 = synx_columns;
          }
        }
        if ( (v14 & 0x400) != 0 )
        {
          v19 = *a2 - v12;
          if ( (v19 & 0x1FFFFFFFFFFFFFFFLL) != 1 )
          {
            v12 = *a1 + (int)scnprintf(v12, v19, "\t\t%d", WORD1(v27));
            *a1 = v12;
            v14 = synx_columns;
          }
        }
        if ( (v14 & 0x800) != 0 )
        {
          v12 = *a1 + (int)scnprintf(v12, *a2 - v12, "\t%d", WORD2(v27));
          *a1 = v12;
          v14 = synx_columns;
        }
        if ( (v14 & 0x1000) != 0 )
        {
          v20 = *a2 - v12;
          if ( (unsigned __int64)(8 * v20 - 10) <= 0xFFFFFFFFFFFFFFFALL )
          {
            v12 = *a1 + (int)scnprintf(v12, v20, "\t\t%d\t", HIWORD(v27));
            *a1 = v12;
            v14 = synx_columns;
          }
        }
        if ( (v14 & 0x2000) != 0 )
        {
          if ( (_WORD)v28 )
          {
            v21 = *a2 - v12;
            if ( (unsigned __int64)(8 * v21 - 11) <= 0xFFFFFFFFFFFFFFFALL )
            {
              v12 = *a1 + (int)scnprintf(v12, v21, "   %2u", (unsigned __int16)v28);
              *a1 = v12;
            }
          }
          if ( WORD1(v28) )
          {
            v22 = *a2 - v12;
            if ( (unsigned __int64)(8 * v22 - 11) <= 0xFFFFFFFFFFFFFFFALL )
            {
              v12 = *a1 + (int)scnprintf(v12, v22, "   %2u", WORD1(v28));
              *a1 = v12;
            }
          }
          if ( WORD2(v28) )
          {
            v23 = *a2 - v12;
            if ( (unsigned __int64)(8 * v23 - 11) <= 0xFFFFFFFFFFFFFFFALL )
            {
              v12 = *a1 + (int)scnprintf(v12, v23, "   %2u", WORD2(v28));
              *a1 = v12;
            }
          }
          if ( HIWORD(v28) )
          {
            v24 = *a2 - v12;
            if ( (unsigned __int64)(8 * v24 - 11) <= 0xFFFFFFFFFFFFFFFALL )
            {
              v12 = *a1 + (int)scnprintf(v12, v24, "   %2u", HIWORD(v28));
              *a1 = v12;
            }
          }
        }
        v25 = *a2 - v12;
        if ( (v25 & 0x1FFFFFFFFFFFFFFFLL) != 5 )
        {
          v12 = *a1 + (int)scnprintf(v12, v25, "\n\t\t-------------------------------------");
          *a1 = v12;
          v25 = *a2 - v12;
        }
        v11 = *a1 + (int)scnprintf(v12, v25, "-----------------------------------------");
        *a1 = v11;
        result = scnprintf(v11, *a2 - v11, "------------------\n");
        *a1 += (int)result;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
