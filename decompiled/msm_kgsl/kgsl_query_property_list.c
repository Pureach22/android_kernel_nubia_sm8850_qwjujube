__int64 __fastcall kgsl_query_property_list(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 v3; // x19
  const char *v4; // x8
  __int64 v5; // x9
  _DWORD *v6; // x10
  int v7; // t1
  __int64 (*v8)(void); // x8
  __int64 (*v9)(void); // x9

  if ( a2 )
  {
    if ( a3 >= 9 )
      v3 = 9;
    else
      v3 = a3;
    if ( a3 )
    {
      v4 = "\b";
      v5 = v3;
      v6 = a2;
      do
      {
        v7 = *(_DWORD *)v4;
        v4 += 16;
        --v5;
        *v6++ = v7;
      }
      while ( v5 );
    }
    else
    {
      LODWORD(v3) = 0;
    }
    v9 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8752) + 232LL);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != -722337215 )
        __break(0x8229u);
      LODWORD(v3) = v9() + v3;
    }
  }
  else
  {
    v8 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8752) + 232LL);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != -722337215 )
        __break(0x8228u);
      LODWORD(v3) = v8() + 9;
    }
    else
    {
      LODWORD(v3) = 9;
    }
  }
  return (unsigned int)v3;
}
