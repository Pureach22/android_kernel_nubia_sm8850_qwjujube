__int64 __fastcall qdf_debugfs_seq_show(__int64 a1, _BYTE *a2)
{
  __int64 (**v2)(void); // x8
  __int64 (*v3)(void); // x9
  int v5; // w0

  v2 = *(__int64 (***)(void))(a1 + 128);
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      if ( *((_DWORD *)v3 - 1) != 1466028272 )
        __break(0x8229u);
      v5 = v3();
      if ( a2 && v5 != 3 )
        *a2 = 1;
    }
  }
  return 0;
}
