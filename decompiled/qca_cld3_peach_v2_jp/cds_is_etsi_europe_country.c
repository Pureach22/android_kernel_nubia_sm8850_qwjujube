bool __fastcall cds_is_etsi_europe_country(unsigned __int8 *a1)
{
  unsigned __int64 v1; // x11
  bool v2; // w9
  char *v3; // x10
  bool v4; // cf

  v1 = 0;
  v2 = 1;
  v3 = "TBEBGCZDKEEFRDEISIEITELESCYLVLILTLUHUMTNLNOPLPTROSISKTRFISECHUKHR";
  do
  {
    if ( *a1 == (unsigned __int8)*(v3 - 1) && a1[1] == (unsigned __int8)*v3 )
      break;
    v4 = v1++ >= 0x20;
    v3 += 2;
    v2 = !v4;
  }
  while ( v1 != 33 );
  return v2;
}
