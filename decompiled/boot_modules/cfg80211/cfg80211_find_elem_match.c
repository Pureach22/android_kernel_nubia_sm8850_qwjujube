unsigned __int8 *__fastcall cfg80211_find_elem_match(
        unsigned __int8 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        void *s2,
        size_t n,
        unsigned int a6)
{
  unsigned __int64 v6; // x8
  unsigned __int8 *v8; // x19
  int v9; // w22
  unsigned __int8 *v10; // x23
  unsigned int v11; // w24
  __int64 v12; // x25
  size_t v13; // x21
  __int64 v14; // x9

  if ( a3 >= 2 )
  {
    v6 = a3;
    v8 = a2;
    v9 = a1;
    v10 = &a2[a3];
    v11 = a6 + n;
    v12 = a6;
    v13 = (unsigned int)n;
    do
    {
      v14 = v8[1];
      if ( v6 < (unsigned int)(v14 + 2) )
        break;
      if ( v11 <= (unsigned int)v14 && *v8 == v9 )
      {
        if ( !bcmp(&v8[v12 + 2], s2, v13) )
          return v8;
        v14 = v8[1];
      }
      v8 += v14 + 2;
      v6 = v10 - v8;
    }
    while ( v10 - v8 > 1 );
  }
  return nullptr;
}
