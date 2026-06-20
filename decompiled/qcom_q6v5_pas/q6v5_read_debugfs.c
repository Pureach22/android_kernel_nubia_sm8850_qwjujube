__int64 __fastcall q6v5_read_debugfs(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x25
  __int64 v8; // x21
  const char *v9; // x26
  unsigned __int64 v10; // x23
  __int64 v11; // x19

  v4 = *(_QWORD *)(a1 + 32);
  v8 = _kmalloc_noprof(a3, 3264);
  if ( !v8 )
    return -12;
  v9 = *(const char **)(v4 + 328);
  v10 = 0;
  do
  {
    v9 = *(const char **)v9;
    if ( v9 == *(const char **)(v4 + 328) )
      break;
    v10 += snprintf((char *)(v8 + v10), a3 - v10, "%s\n", v9 + 16);
  }
  while ( v10 < a3 );
  if ( *a4 >= (signed __int64)v10 )
  {
    v11 = 0;
  }
  else if ( simple_read_from_buffer(a2, v10, a4, v8, a3) >= 0 )
  {
    v11 = v10;
  }
  else
  {
    v11 = -14;
  }
  kfree(v8);
  return v11;
}
