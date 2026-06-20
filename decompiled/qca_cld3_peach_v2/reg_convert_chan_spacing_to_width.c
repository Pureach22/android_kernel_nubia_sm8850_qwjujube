__int64 __fastcall reg_convert_chan_spacing_to_width(__int64 result, __int16 *a2)
{
  __int16 v2; // w9

  if ( (unsigned __int16)result <= 0x4Fu )
  {
    v2 = 20;
    if ( (unsigned __int16)result != 20 && (unsigned __int16)result != 25 )
    {
      v2 = result;
      if ( (unsigned __int16)result != 40 )
        goto LABEL_5;
    }
LABEL_9:
    *a2 = v2;
    return result;
  }
  if ( (unsigned __int16)result != 80 && (unsigned __int16)result != 160 )
  {
    v2 = result;
    if ( (unsigned __int16)result != 320 )
    {
LABEL_5:
      *a2 = 0;
      return result;
    }
    goto LABEL_9;
  }
  *a2 = result;
  return result;
}
