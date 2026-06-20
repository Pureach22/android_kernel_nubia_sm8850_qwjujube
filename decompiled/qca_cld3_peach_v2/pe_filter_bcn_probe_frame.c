bool __fastcall pe_filter_bcn_probe_frame(_BYTE *a1, unsigned __int8 *a2)
{
  int v2; // w9

  if ( !a1[21709] )
    return 0;
  v2 = a2[16];
  if ( (unsigned __int8)a1[21710] == v2
    && (unsigned __int8)a1[21711] == a2[17]
    && (unsigned __int8)a1[21712] == a2[18]
    && (unsigned __int8)a1[21713] == a2[19]
    && (unsigned __int8)a1[21714] == a2[20]
    && (unsigned __int8)a1[21715] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21716] == v2
    && (unsigned __int8)a1[21717] == a2[17]
    && (unsigned __int8)a1[21718] == a2[18]
    && (unsigned __int8)a1[21719] == a2[19]
    && (unsigned __int8)a1[21720] == a2[20]
    && (unsigned __int8)a1[21721] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21722] == v2
    && (unsigned __int8)a1[21723] == a2[17]
    && (unsigned __int8)a1[21724] == a2[18]
    && (unsigned __int8)a1[21725] == a2[19]
    && (unsigned __int8)a1[21726] == a2[20]
    && (unsigned __int8)a1[21727] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21728] == v2
    && (unsigned __int8)a1[21729] == a2[17]
    && (unsigned __int8)a1[21730] == a2[18]
    && (unsigned __int8)a1[21731] == a2[19]
    && (unsigned __int8)a1[21732] == a2[20]
    && (unsigned __int8)a1[21733] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21734] == v2
    && (unsigned __int8)a1[21735] == a2[17]
    && (unsigned __int8)a1[21736] == a2[18]
    && (unsigned __int8)a1[21737] == a2[19]
    && (unsigned __int8)a1[21738] == a2[20]
    && (unsigned __int8)a1[21739] == a2[21] )
  {
    return 1;
  }
  return (unsigned __int8)a1[21740] == v2
      && (unsigned __int8)a1[21741] == a2[17]
      && (unsigned __int8)a1[21742] == a2[18]
      && (unsigned __int8)a1[21743] == a2[19]
      && (unsigned __int8)a1[21744] == a2[20]
      && (unsigned __int8)a1[21745] == a2[21];
}
