bool __fastcall pe_filter_bcn_probe_frame(_BYTE *a1, unsigned __int8 *a2)
{
  int v2; // w9

  if ( !a1[21637] )
    return 0;
  v2 = a2[16];
  if ( (unsigned __int8)a1[21638] == v2
    && (unsigned __int8)a1[21639] == a2[17]
    && (unsigned __int8)a1[21640] == a2[18]
    && (unsigned __int8)a1[21641] == a2[19]
    && (unsigned __int8)a1[21642] == a2[20]
    && (unsigned __int8)a1[21643] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21644] == v2
    && (unsigned __int8)a1[21645] == a2[17]
    && (unsigned __int8)a1[21646] == a2[18]
    && (unsigned __int8)a1[21647] == a2[19]
    && (unsigned __int8)a1[21648] == a2[20]
    && (unsigned __int8)a1[21649] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21650] == v2
    && (unsigned __int8)a1[21651] == a2[17]
    && (unsigned __int8)a1[21652] == a2[18]
    && (unsigned __int8)a1[21653] == a2[19]
    && (unsigned __int8)a1[21654] == a2[20]
    && (unsigned __int8)a1[21655] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21656] == v2
    && (unsigned __int8)a1[21657] == a2[17]
    && (unsigned __int8)a1[21658] == a2[18]
    && (unsigned __int8)a1[21659] == a2[19]
    && (unsigned __int8)a1[21660] == a2[20]
    && (unsigned __int8)a1[21661] == a2[21] )
  {
    return 1;
  }
  if ( (unsigned __int8)a1[21662] == v2
    && (unsigned __int8)a1[21663] == a2[17]
    && (unsigned __int8)a1[21664] == a2[18]
    && (unsigned __int8)a1[21665] == a2[19]
    && (unsigned __int8)a1[21666] == a2[20]
    && (unsigned __int8)a1[21667] == a2[21] )
  {
    return 1;
  }
  return (unsigned __int8)a1[21668] == v2
      && (unsigned __int8)a1[21669] == a2[17]
      && (unsigned __int8)a1[21670] == a2[18]
      && (unsigned __int8)a1[21671] == a2[19]
      && (unsigned __int8)a1[21672] == a2[20]
      && (unsigned __int8)a1[21673] == a2[21];
}
