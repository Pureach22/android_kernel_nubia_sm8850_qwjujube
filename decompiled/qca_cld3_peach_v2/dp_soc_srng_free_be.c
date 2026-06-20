void __fastcall dp_soc_srng_free_be(__int64 a1)
{
  if ( (*(_BYTE *)(a1 + 20096) & 2) != 0 )
  {
    if ( *(_BYTE *)(a1 + 20121) )
      JUMPOUT(0x500520);
  }
  JUMPOUT(0x500548);
}
