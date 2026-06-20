__int64 __fastcall geni_i3c_handle_err(__int64 result, __int16 a2)
{
  __int64 v3; // x19

  v3 = result;
  if ( (a2 & 0x200) != 0 )
  {
    result = geni_i3c_err(result, 0);
    if ( (a2 & 0x400) == 0 )
    {
LABEL_3:
      if ( (a2 & 0x800) == 0 )
        goto LABEL_4;
      goto LABEL_14;
    }
  }
  else if ( (a2 & 0x400) == 0 )
  {
    goto LABEL_3;
  }
  result = geni_i3c_err(v3, 1u);
  if ( (a2 & 0x800) == 0 )
  {
LABEL_4:
    if ( (a2 & 0x1000) == 0 )
      goto LABEL_5;
    goto LABEL_15;
  }
LABEL_14:
  result = geni_i3c_err(v3, 2u);
  if ( (a2 & 0x1000) == 0 )
  {
LABEL_5:
    if ( (a2 & 0x2000) == 0 )
      goto LABEL_6;
    goto LABEL_16;
  }
LABEL_15:
  result = geni_i3c_err(v3, 3u);
  if ( (a2 & 0x2000) == 0 )
  {
LABEL_6:
    if ( (a2 & 0x4000) == 0 )
      goto LABEL_7;
    goto LABEL_17;
  }
LABEL_16:
  result = geni_i3c_err(v3, 4u);
  if ( (a2 & 0x4000) == 0 )
  {
LABEL_7:
    if ( (a2 & 2) == 0 )
      goto LABEL_8;
    goto LABEL_18;
  }
LABEL_17:
  result = geni_i3c_err(v3, 5u);
  if ( (a2 & 2) == 0 )
  {
LABEL_8:
    if ( (a2 & 4) == 0 )
      goto LABEL_9;
    goto LABEL_19;
  }
LABEL_18:
  result = geni_i3c_err(v3, 6u);
  if ( (a2 & 4) == 0 )
  {
LABEL_9:
    if ( (a2 & 0x20) == 0 )
      return result;
    return geni_i3c_err(v3, 8u);
  }
LABEL_19:
  result = geni_i3c_err(v3, 7u);
  if ( (a2 & 0x20) == 0 )
    return result;
  return geni_i3c_err(v3, 8u);
}
