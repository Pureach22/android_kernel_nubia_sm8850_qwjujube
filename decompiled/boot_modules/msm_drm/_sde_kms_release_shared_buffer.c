__int64 __fastcall sde_kms_release_shared_buffer(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 v4; // x9
  _BOOL4 v6; // w8
  bool v7; // zf
  unsigned int v8; // w8
  unsigned __int64 v9; // x9
  __int64 result; // x0
  unsigned __int64 v11; // x10
  unsigned __int64 v12; // x19
  __int64 v13; // x20
  bool v14; // cf

  if ( a1 && a2 )
  {
    v4 = a4;
    v6 = a3 != a1 || a4 > a2;
    v7 = !v6;
    if ( v6 )
      v8 = 0;
    else
      v8 = a4;
    if ( !v7 )
      v4 = 0;
    v9 = v4 + a1;
    result = 0;
    v11 = v9 + a2 - v8;
    v12 = (v9 >> 12) - (v11 >> 12);
    if ( v9 >> 12 < v11 >> 12 )
    {
      v13 = (v9 >> 12 << 6) - 0x140000000LL;
      do
      {
        free_reserved_page(v13 - ((__int64)memstart_addr >> 12 << 6));
        v14 = __CFADD__(v12++, 1);
        v13 += 64;
      }
      while ( !v14 );
      return 0;
    }
  }
  else
  {
    printk(&unk_223EAA, "_sde_kms_release_shared_buffer");
    return 4294967274LL;
  }
  return result;
}
