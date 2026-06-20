__int64 __fastcall qdf_debugfs_single_show(__int64 a1)
{
  void (**v1)(void); // x8
  void (*v2)(void); // x9

  v1 = *(void (***)(void))(a1 + 128);
  if ( v1 )
  {
    v2 = *v1;
    if ( *v1 )
    {
      if ( *((_DWORD *)v2 - 1) != 1466028272 )
        __break(0x8229u);
      v2();
    }
  }
  return 0;
}
