__int64 __fastcall bcl_sid1_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 (*v3)(void); // x8

  v2 = *(_QWORD *)(a1 + 1520);
  if ( v2 )
  {
    v3 = *(__int64 (**)(void))(v2 + 72);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != -1976687147 )
        __break(0x8228u);
      *a2 = v3();
    }
  }
  return 0;
}
