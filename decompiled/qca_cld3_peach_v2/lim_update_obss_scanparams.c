_WORD *__fastcall lim_update_obss_scanparams(_WORD *result, unsigned __int16 *a2)
{
  int v2; // w9
  int v3; // w9
  int v4; // w9
  int v5; // w9
  int v6; // w9
  int v7; // w9
  int v8; // w9

  v2 = a2[2];
  if ( (unsigned int)(v2 - 11) <= 0x3DC )
    result[4320] = v2;
  v3 = a2[1];
  if ( (unsigned int)(v3 - 6) <= 0x3E1 )
    result[4319] = v3;
  v4 = a2[6];
  if ( (unsigned int)(v4 - 6) <= 0x5D )
    result[4324] = v4;
  v5 = a2[5];
  if ( (unsigned int)(v5 - 21) <= 0x26FA )
    result[4323] = v5;
  v6 = a2[4];
  if ( (unsigned int)(v6 - 201) <= 0x2646 )
    result[4322] = v6;
  v7 = a2[3];
  if ( (unsigned int)(v7 - 11) <= 0x378 )
    result[4321] = v7;
  v8 = a2[7];
  if ( (unsigned int)(v8 - 1) <= 0x62 )
    result[4325] = v8;
  return result;
}
