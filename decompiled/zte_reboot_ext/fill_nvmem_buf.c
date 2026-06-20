const char *__fastcall fill_nvmem_buf(const char *s, const char *a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  const char *v8; // x24
  const char *v10; // x26
  const char *v11; // x25
  size_t v12; // x23
  size_t v13; // x24

  v8 = s;
  if ( s )
  {
    s = (const char *)strlen(s);
    v10 = s;
    if ( a2 )
      goto LABEL_3;
LABEL_6:
    v11 = nullptr;
    v12 = 0;
    if ( !v8 )
      goto LABEL_12;
LABEL_7:
    if ( v10 )
    {
      v12 = (unsigned __int64)v10 >= a5 ? a5 : (size_t)v10;
      s = (const char *)memcpy((void *)(a3 + a4), v8, v12);
      if ( (unsigned __int64)v10 >= a5 )
        return s;
    }
    goto LABEL_12;
  }
  v10 = nullptr;
  if ( !a2 )
    goto LABEL_6;
LABEL_3:
  s = (const char *)strlen(a2);
  v11 = s;
  v12 = 0;
  if ( v8 )
    goto LABEL_7;
LABEL_12:
  if ( !a2
    || !v11
    || ((unsigned __int64)v11 >= a5 - v12 ? (v13 = a5 - v12) : (v13 = (size_t)v11),
        s = (const char *)memcpy((void *)(a3 + v12 + a4), a2, v13),
        v12 += v13,
        v12 < a5) )
  {
    if ( a5 > v12 )
      return (const char *)memset((void *)(a3 + v12 + a4), 0, a5 - v12);
  }
  return s;
}
