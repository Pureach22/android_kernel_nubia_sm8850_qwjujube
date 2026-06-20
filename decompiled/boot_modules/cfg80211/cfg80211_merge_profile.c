size_t __fastcall cfg80211_merge_profile(int a1, int a2, __int64 a3, __int64 a4, char *dest, size_t a6)
{
  size_t v6; // x19
  __int64 v7; // x26
  __int64 v14; // x8
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x9
  _BYTE *v17; // x28
  __int64 v18; // x11
  size_t v19; // x2
  _BYTE *v20; // x1

  v6 = *(unsigned __int8 *)(a4 + 1);
  if ( v6 > a6 )
    return 0;
  v7 = a4 + 2;
  memcpy(dest, (const void *)(a4 + 2), *(unsigned __int8 *)(a4 + 1));
  v14 = a3 + 2 + *(unsigned __int8 *)(a3 + 1);
  if ( ((a1 - (_DWORD)v14 + a2) & 0xFFFFFFFE) != 0 )
  {
    v15 = (unsigned int)(a1 - v14 + a2);
    v16 = v14 + v15;
LABEL_5:
    v17 = (_BYTE *)v14;
    do
    {
      v18 = (unsigned __int8)v17[1];
      if ( v15 < v18 + 2 )
        break;
      if ( *v17 == 71 )
      {
        if ( (unsigned int)v18 >= 4 )
        {
          if ( v17 )
          {
            if ( v7 + (unsigned __int64)*(unsigned __int8 *)(a4 + 1) >= v14 - 1 )
            {
              v19 = (unsigned __int8)v17[4];
              v20 = v17 + 5;
              if ( &v17[v18 + 2] >= &v17[v19 + 5] && (unsigned int)v19 >= 2 && !v17[3] && *v20 != 83 && v6 + v19 <= a6 )
              {
                memcpy(&dest[v6], v20, v19);
                v14 = a3 + 2 + *(unsigned __int8 *)(a3 + 1);
                v6 += (unsigned __int8)v17[4];
                v15 = (unsigned int)(a1 - v14 + a2);
                v16 = v14 + v15;
                if ( ((a1 - (_DWORD)v14 + a2) & 0xFFFFFFFE) != 0 )
                  goto LABEL_5;
              }
            }
          }
        }
        return v6;
      }
      v17 += v18 + 2;
      v15 = v16 - (_QWORD)v17;
    }
    while ( (__int64)(v16 - (_QWORD)v17) > 1 );
  }
  return v6;
}
