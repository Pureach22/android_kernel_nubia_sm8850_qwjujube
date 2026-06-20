int *__fastcall csr_fill_enc_type(int *result, unsigned int a2)
{
  if ( a2 )
  {
    if ( (a2 & 0x400) != 0 )
    {
      *result = 14;
    }
    else if ( (a2 & 0x200) != 0 )
    {
      *result = 13;
    }
    else if ( (a2 & 0x8C) != 0 )
    {
      *result = 6;
    }
    else if ( (a2 & 2) != 0 )
    {
      *result = 5;
    }
    else if ( (a2 & 0x140) != 0 )
    {
      *result = 10;
    }
    else if ( (a2 & 0x2010) != 0 )
    {
      *result = 7;
    }
    else if ( (a2 & 0x800) != 0 )
    {
      *result = 11;
    }
    else if ( (a2 & 0x1000) != 0 )
    {
      *result = 12;
    }
    else if ( (a2 & 0x8001) != 0 )
    {
      *result = 3;
    }
    else
    {
      *result = (a2 >> 14) & 4;
    }
  }
  else
  {
    *result = 0;
  }
  return result;
}
