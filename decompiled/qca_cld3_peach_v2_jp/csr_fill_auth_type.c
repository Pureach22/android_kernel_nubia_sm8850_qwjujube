int *__fastcall csr_fill_auth_type(int *result, int a2, int a3, int a4)
{
  int v4; // w8
  int v5; // w8
  int v6; // w8

  v4 = 1;
  if ( !a2 || (a2 & 3) != 0 )
  {
LABEL_45:
    *result = v4;
    return result;
  }
  if ( (a2 & 0x10) != 0 )
  {
    if ( (a4 & 0x18001) != 0 )
      v5 = 4;
    else
      v5 = 1;
    *result = v5;
  }
  else
  {
    if ( (a2 & 4) != 0 )
    {
      *result = 2;
      return result;
    }
    if ( (a2 & 0x6C8) != 0 )
    {
      if ( (a3 & 0x200000) != 0 )
      {
        *result = 21;
      }
      else if ( (a3 & 0x100000) != 0 )
      {
        *result = 20;
      }
      else if ( (a3 & 0x80000) != 0 )
      {
        *result = 19;
      }
      else if ( (a3 & 0x40000) != 0 )
      {
        *result = 18;
      }
      else if ( (a3 & 0x10000000) != 0 )
      {
        *result = 30;
      }
      else if ( (a3 & 0x8000000) != 0 )
      {
        *result = 29;
      }
      else if ( (a3 & 0x800) != 0 )
      {
        *result = 27;
      }
      else if ( (a3 & 0x400) != 0 )
      {
        *result = 3;
      }
      else if ( (a3 & 0x800000) != 0 )
      {
        *result = 22;
      }
      else if ( (a3 & 0x8000) != 0 )
      {
        *result = 26;
      }
      else if ( (a3 & 0x400000) != 0 )
      {
        *result = 23;
      }
      else if ( (a3 & 0x20) != 0 )
      {
        *result = 10;
      }
      else if ( (a3 & 0x40) != 0 )
      {
        *result = 11;
      }
      else if ( (a3 & 1) != 0 )
      {
        *result = 8;
      }
      else if ( (a3 & 2) != 0 )
      {
        *result = 9;
      }
      else if ( (a3 & 0x4000) != 0 )
      {
        *result = 15;
      }
      else if ( (a3 & 0x100) != 0 )
      {
        *result = 16;
      }
      else if ( (a3 & 0x80) != 0 )
      {
        *result = 17;
      }
      else if ( (a3 & 0x10000) != 0 )
      {
        *result = 24;
      }
      else if ( (a3 & 0x20000) != 0 )
      {
        *result = 25;
      }
      else
      {
        *result = (a3 << 7 >> 31) & 0x1C;
      }
      return result;
    }
    if ( (a2 & 0x20) == 0 )
    {
      if ( (a2 & 0x100) == 0 )
      {
        *result = 1;
        return result;
      }
      v4 = (a3 << 19 >> 31) & 0xD;
      if ( (a3 & 0x2000) != 0 )
        v4 = 12;
      goto LABEL_45;
    }
    if ( (a3 & 1) != 0 )
    {
      *result = 5;
    }
    else if ( (a3 & 2) != 0 )
    {
      *result = 6;
    }
    else
    {
      if ( (a3 & 0x4000) != 0 )
        v6 = 14;
      else
        v6 = 7;
      *result = v6;
    }
  }
  return result;
}
