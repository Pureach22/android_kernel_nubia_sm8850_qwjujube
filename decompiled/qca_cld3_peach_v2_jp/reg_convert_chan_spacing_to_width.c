__int64 __fastcall reg_convert_chan_spacing_to_width(__int64 result, _WORD *a2)
{
  int v2; // w8

  v2 = (unsigned __int16)result;
  if ( (unsigned __int16)result <= 0x27u )
  {
    result = 20;
    if ( v2 == 20 || v2 == 25 )
      goto LABEL_5;
  }
  else if ( (unsigned __int16)result == 160 || (unsigned __int16)result == 80 || (unsigned __int16)result == 40 )
  {
LABEL_5:
    *a2 = result;
    return result;
  }
  *a2 = 0;
  return 0;
}
