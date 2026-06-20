__int64 __fastcall wlan_get_320_center_freq(__int64 result, int *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w9

  *a2 = 0;
  *a3 = 0;
  if ( (unsigned int)(result - 5500) <= 0x12C )
  {
    v3 = 5650;
LABEL_5:
    *a2 = v3;
    return result;
  }
  if ( (unsigned int)(result - 5955) <= 0x8C )
  {
    v3 = 6105;
    goto LABEL_5;
  }
  if ( (unsigned int)(result - 6115) <= 0x8C )
  {
    v4 = 6105;
    v5 = 6265;
LABEL_17:
    *a2 = v4;
    *a3 = v5;
    return result;
  }
  if ( (unsigned int)(result - 6275) <= 0x8C )
  {
    v4 = 6265;
    v5 = 6425;
    goto LABEL_17;
  }
  if ( (unsigned int)(result - 6435) <= 0x8C )
  {
    v4 = 6425;
    v5 = 6585;
    goto LABEL_17;
  }
  if ( (unsigned int)(result - 6595) <= 0x8C )
  {
    v4 = 6585;
    v5 = 6745;
    goto LABEL_17;
  }
  if ( (unsigned int)(result - 6755) <= 0x8C )
  {
    v4 = 6745;
    v5 = 6905;
    goto LABEL_17;
  }
  if ( (unsigned int)(result - 6915) <= 0x8C )
  {
    v3 = 6905;
    goto LABEL_5;
  }
  return result;
}
