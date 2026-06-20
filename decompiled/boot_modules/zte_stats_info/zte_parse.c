__int64 __fastcall zte_parse(_WORD *a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x21
  unsigned int v9; // w19

  if ( !a1 )
    return 1;
  v2 = (unsigned __int16)*a1 - 4;
  if ( v2 > 0x124 )
    return 4294967289LL;
  if ( *a1 == 4 )
    return 4294967274LL;
  v6 = _kmalloc_noprof((unsigned __int16)(*a1 - 4), 3264);
  if ( !v6 )
    return 4294967284LL;
  v7 = (unsigned __int16)v2;
  v8 = v6;
  nla_strscpy(v6, a1, v7);
  v9 = bitmap_parselist(v8, a2, nr_cpu_ids);
  kfree(v8);
  return v9;
}
