__int64 __fastcall hif_set_grp_intr_affinity(__int64 result)
{
  __int64 (*v1)(void); // x8

  if ( result )
  {
    v1 = *(__int64 (**)(void))(result + 456);
    if ( *((_DWORD *)v1 - 1) != -1964134686 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
