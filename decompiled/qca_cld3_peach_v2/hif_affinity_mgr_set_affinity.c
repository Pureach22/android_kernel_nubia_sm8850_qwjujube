__int64 __fastcall hif_affinity_mgr_set_affinity(__int64 result)
{
  __int64 (*v1)(void); // x8

  if ( result )
  {
    v1 = *(__int64 (**)(void))(result + 464);
    if ( v1 )
    {
      if ( *((_DWORD *)v1 - 1) != 1838711590 )
        __break(0x8228u);
      return v1();
    }
  }
  return result;
}
