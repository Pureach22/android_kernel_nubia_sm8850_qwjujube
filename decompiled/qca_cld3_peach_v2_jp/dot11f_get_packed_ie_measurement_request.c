__int64 __fastcall dot11f_get_packed_ie_measurement_request(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w9
  __int64 result; // x0
  unsigned int v6; // w10
  int v7; // w9
  unsigned int *v8; // x3

  if ( !*a2 )
    return 0;
  v3 = *a3;
  result = 0;
  *a3 += 3;
  v6 = (unsigned __int8)a2[3];
  if ( v6 <= 4 )
  {
    if ( (unsigned __int8)a2[3] <= 2u )
      goto LABEL_12;
    if ( v6 != 3 )
      return result;
    v7 = v3 + 9;
    v8 = (unsigned int *)&IES_measurement_requestchannel_load;
    goto LABEL_18;
  }
  if ( (unsigned __int8)a2[3] > 7u )
  {
    if ( v6 == 8 )
    {
      v7 = v3 + 4;
      v8 = (unsigned int *)&IES_measurement_requestlci;
    }
    else
    {
      if ( v6 != 16 )
        return result;
      v7 = v3 + 6;
      v8 = (unsigned int *)&IES_measurement_requestftmrr;
    }
    goto LABEL_18;
  }
  if ( v6 == 5 )
  {
    v7 = v3 + 16;
    v8 = (unsigned int *)&IES_measurement_requestBeacon;
LABEL_18:
    *a3 = v7;
    return get_packed_size_core(a1, (__int64)a2, a3, v8);
  }
  if ( v6 == 7 )
  {
LABEL_12:
    *a3 = v3 + 14;
    return 0;
  }
  return result;
}
