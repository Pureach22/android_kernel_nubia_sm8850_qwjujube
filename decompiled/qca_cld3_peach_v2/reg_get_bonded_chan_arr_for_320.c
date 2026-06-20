__int64 __fastcall reg_get_bonded_chan_arr_for_320(__int64 a1, unsigned int a2, int a3, _QWORD *a4)
{
  __int64 result; // x0
  void *v5; // x8
  unsigned int v6; // w8

  result = 0;
  if ( a3 > 6424 )
  {
    if ( a3 > 6744 )
    {
      if ( a3 == 6745 )
      {
        v5 = &unk_AD7E94;
        goto LABEL_45;
      }
      if ( a3 == 6905 )
      {
        v5 = &unk_AD7E98;
        goto LABEL_45;
      }
    }
    else
    {
      if ( a3 == 6425 )
      {
        v5 = &unk_AD7E8C;
        goto LABEL_45;
      }
      if ( a3 == 6585 )
      {
        v5 = &unk_AD7E90;
        goto LABEL_45;
      }
    }
  }
  else if ( a3 > 6104 )
  {
    if ( a3 == 6105 )
    {
      v5 = &unk_AD7E84;
      goto LABEL_45;
    }
    if ( a3 == 6265 )
    {
      v5 = &unk_AD7E88;
      goto LABEL_45;
    }
  }
  else
  {
    v5 = &bonded_chan_320mhz_list_freq;
    if ( a3 )
    {
      if ( a3 != 5650 )
        return result;
LABEL_45:
      *a4 = v5;
      return 1;
    }
    result = 0;
    if ( a2 >> 2 >= 0x55F && a2 <= 0x1658 )
    {
      result = 1;
      *a4 = &bonded_chan_320mhz_list_freq;
    }
    v6 = a2 >> 4;
    if ( a2 >= 0x1743 && v6 <= 0x186 )
    {
      a4[(unsigned int)result] = &unk_AD7E84;
      result = (unsigned int)(result + 1);
    }
    if ( (unsigned int)result <= 1 )
    {
      if ( a2 >= 0x17E3 && v6 <= 0x190 )
      {
        a4[(unsigned int)result] = &unk_AD7E88;
        result = (unsigned int)(result + 1);
      }
      if ( (unsigned int)result <= 1 )
      {
        if ( a2 >= 0x1883 && v6 <= 0x19A )
        {
          a4[(unsigned int)result] = &unk_AD7E8C;
          result = (unsigned int)(result + 1);
        }
        if ( (unsigned int)result <= 1 )
        {
          if ( a2 >= 0x1923 && v6 <= 0x1A4 )
          {
            a4[(unsigned int)result] = &unk_AD7E90;
            result = (unsigned int)(result + 1);
          }
          if ( (unsigned int)result <= 1 )
          {
            if ( a2 >= 0x19C3 && v6 <= 0x1AE )
            {
              a4[(unsigned int)result] = &unk_AD7E94;
              result = (unsigned int)(result + 1);
            }
            if ( (unsigned int)result <= 1 && a2 >= 0x1A63 && v6 <= 0x1B8 )
            {
              a4[(unsigned int)result] = &unk_AD7E98;
              return (unsigned int)(result + 1);
            }
          }
        }
      }
    }
  }
  return result;
}
