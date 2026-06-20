__int64 __fastcall dp_catalog_put(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  void (*v3)(void); // x8
  void (*v4)(void); // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1192);
    v2 = result;
    if ( v1 )
    {
      v3 = *(void (**)(void))(v1 + 16);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != -798667322 )
          __break(0x8228u);
        v3();
      }
    }
    v4 = *(void (**)(void))(*(_QWORD *)(v2 - 32) + 864LL);
    if ( *((_DWORD *)v4 - 1) != 680055959 )
      __break(0x8228u);
    v4();
    return devm_kfree(*(_QWORD *)(v2 - 144));
  }
  return result;
}
