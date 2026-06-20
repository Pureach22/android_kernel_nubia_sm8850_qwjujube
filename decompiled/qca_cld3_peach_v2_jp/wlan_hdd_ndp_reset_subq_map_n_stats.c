_DWORD *__fastcall wlan_hdd_ndp_reset_subq_map_n_stats(_DWORD *result)
{
  int v1; // w9
  int *v2; // x10
  int v3; // w11
  int v4; // w11
  int v5; // w11
  int v6; // w11
  int v7; // w11

  v1 = result[10524];
  v2 = result + 12989;
  if ( (v1 & 0x2000) != 0 )
  {
    v3 = *v2;
    v1 &= ~0x2000u;
    result[10524] = v1;
    *v2 = v3 + 1;
    if ( (v1 & 0x4000) == 0 )
    {
LABEL_3:
      if ( (v1 & 0x8000) == 0 )
        goto LABEL_4;
      goto LABEL_9;
    }
  }
  else if ( (v1 & 0x4000) == 0 )
  {
    goto LABEL_3;
  }
  v4 = result[12993];
  v1 &= ~0x4000u;
  result[10524] = v1;
  result[12993] = v4 + 1;
  if ( (v1 & 0x8000) == 0 )
  {
LABEL_4:
    if ( (v1 & 0x10000) == 0 )
      goto LABEL_5;
    goto LABEL_10;
  }
LABEL_9:
  v5 = result[12997];
  v1 &= ~0x8000u;
  result[10524] = v1;
  result[12997] = v5 + 1;
  if ( (v1 & 0x10000) == 0 )
  {
LABEL_5:
    if ( (v1 & 0x20000) == 0 )
      return result;
LABEL_11:
    v7 = result[13005];
    result[10524] = v1 & 0xFFFDFFFF;
    result[13005] = v7 + 1;
    return result;
  }
LABEL_10:
  v6 = result[13001];
  v1 &= ~0x10000u;
  result[10524] = v1;
  result[13001] = v6 + 1;
  if ( (v1 & 0x20000) != 0 )
    goto LABEL_11;
  return result;
}
