int *__fastcall ieee80211_fill_txq_stats(int *result, _DWORD *a2)
{
  int v2; // w8

  v2 = *result;
  if ( (*result & 2) != 0 )
  {
    if ( (v2 & 4) != 0 )
      goto LABEL_3;
  }
  else
  {
    v2 |= 2u;
    *result = v2;
    result[1] = a2[26];
    if ( (v2 & 4) != 0 )
    {
LABEL_3:
      if ( (v2 & 8) != 0 )
        goto LABEL_4;
      goto LABEL_13;
    }
  }
  v2 |= 4u;
  *result = v2;
  result[2] = a2[27];
  if ( (v2 & 8) != 0 )
  {
LABEL_4:
    if ( (v2 & 0x10) != 0 )
      goto LABEL_5;
    goto LABEL_14;
  }
LABEL_13:
  v2 |= 8u;
  *result = v2;
  result[3] = a2[30];
  if ( (v2 & 0x10) != 0 )
  {
LABEL_5:
    if ( (v2 & 0x20) != 0 )
      goto LABEL_6;
    goto LABEL_15;
  }
LABEL_14:
  v2 |= 0x10u;
  *result = v2;
  result[4] = a2[41];
  if ( (v2 & 0x20) != 0 )
  {
LABEL_6:
    if ( (v2 & 0x40) != 0 )
      goto LABEL_7;
    goto LABEL_16;
  }
LABEL_15:
  v2 |= 0x20u;
  *result = v2;
  result[5] = a2[43];
  if ( (v2 & 0x40) != 0 )
  {
LABEL_7:
    if ( (v2 & 0x100) != 0 )
      goto LABEL_8;
    goto LABEL_17;
  }
LABEL_16:
  v2 |= 0x40u;
  *result = v2;
  result[6] = a2[28];
  if ( (v2 & 0x100) != 0 )
  {
LABEL_8:
    if ( (v2 & 0x200) != 0 )
      goto LABEL_9;
    goto LABEL_18;
  }
LABEL_17:
  v2 |= 0x100u;
  *result = v2;
  result[8] = a2[29];
  if ( (v2 & 0x200) != 0 )
  {
LABEL_9:
    if ( (v2 & 0x400) != 0 )
      return result;
LABEL_19:
    *result = v2 | 0x400;
    result[10] = a2[32];
    return result;
  }
LABEL_18:
  v2 |= 0x200u;
  *result = v2;
  result[9] = a2[31];
  if ( (v2 & 0x400) == 0 )
    goto LABEL_19;
  return result;
}
