__int64 __fastcall cfg80211_copy_elem_with_frags(
        unsigned __int8 *src,
        unsigned __int64 a2,
        __int64 a3,
        void **a4,
        __int64 a5)
{
  char *v5; // x23
  unsigned __int64 v6; // x24
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 v13; // x9
  __int64 v14; // x23
  __int64 v15; // x10
  void **v16; // x8
  unsigned __int8 *v17; // x19
  size_t v18; // x2

  if ( (unsigned __int64)src < a2
    || (v5 = (char *)(src + 2), v6 = a2 + a3, (unsigned __int64)(src + 2) > a2 + a3)
    || (v8 = src[1], (unsigned __int64)&v5[v8] > v6) )
  {
    result = 0;
    __break(0x800u);
  }
  else
  {
    v9 = a5 + 2304;
    if ( v8 + 2 <= a5 + 2304 - (__int64)*a4 )
    {
      memcpy(*a4, src, v8 + 2);
      v13 = (__int64)*a4 + src[1] + 2;
      *a4 = (void *)v13;
      if ( src[1] == 255 )
      {
        v14 = v6 - (_QWORD)v5 - 255;
        v15 = a5;
        if ( v14 >= 2 )
        {
          v16 = a4;
          v17 = src + 257;
          do
          {
            v18 = v17[1] + 2LL;
            if ( v14 < v18 || *v17 != 242 )
              break;
            if ( (__int64)v18 > v9 - v13 )
              return 0;
            memcpy(*v16, v17, v18);
            v13 = (__int64)*a4 + v17[1] + 2;
            *a4 = (void *)v13;
            if ( v17[1] != 255 )
            {
              v15 = a5;
              return v13 - v15;
            }
            v14 -= 257;
            v16 = a4;
            v17 += 257;
            v15 = a5;
          }
          while ( v14 > 1 );
        }
        return v13 - v15;
      }
      else
      {
        return v13 - a5;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
