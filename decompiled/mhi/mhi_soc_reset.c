__int64 __fastcall mhi_soc_reset(__int64 a1)
{
  __int64 (*v1)(void); // x8
  __int64 (*v3)(void); // x9

  v1 = *(__int64 (**)(void))(a1 + 584);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -2145957670 )
      __break(0x8228u);
    return v1();
  }
  else
  {
    v3 = *(__int64 (**)(void))(a1 + 576);
    if ( *((_DWORD *)v3 - 1) != -242010890 )
      __break(0x8229u);
    return v3();
  }
}
