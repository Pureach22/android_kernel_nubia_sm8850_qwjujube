__int64 __fastcall sha1_update(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8

  if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 56LL) + 25LL) == 1 )
  {
    v1 = a1;
    v2 = copy_source();
    a1 = v1;
    if ( v2 )
      return 4294967284LL;
  }
  *(_QWORD *)(a1 + 216) += *(unsigned int *)(a1 + 48);
  return sha_update();
}
