__int64 __fastcall rmnet_shs_cpu_from_idx(unsigned __int8 a1, unsigned __int8 a2)
{
  int v2; // w10
  unsigned int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w10
  int v7; // w8
  int v8; // w10
  int v9; // w8
  int v10; // w10
  int v12; // w8
  int v13; // w10
  int v14; // w8
  int v15; // w9
  int v16; // w8

  if ( a1 )
  {
    v2 = a2 & 1;
  }
  else
  {
    v2 = 0;
    v3 = 0;
    if ( (a2 & 1) != 0 )
      return v3;
  }
  if ( v2 == a1 )
  {
    if ( (a2 & 2) != 0 )
      return 1;
    v4 = 0;
  }
  else
  {
    v4 = (a2 >> 1) & 1;
  }
  v5 = v2 + v4;
  if ( v5 == a1 )
  {
    if ( (a2 & 4) != 0 )
      return 2;
    v6 = 0;
  }
  else
  {
    v6 = (a2 >> 2) & 1;
  }
  v7 = v5 + v6;
  if ( v7 == a1 )
  {
    if ( (a2 & 8) != 0 )
      return 3;
    v8 = 0;
  }
  else
  {
    v8 = (a2 >> 3) & 1;
  }
  v9 = v7 + v8;
  if ( v9 == a1 )
  {
    if ( (a2 & 0x10) != 0 )
      return 4;
    v10 = 0;
  }
  else
  {
    v10 = (a2 >> 4) & 1;
  }
  v12 = v9 + v10;
  if ( v12 == a1 )
  {
    if ( (a2 & 0x20) != 0 )
      return 5;
    v13 = 0;
  }
  else
  {
    v13 = (a2 >> 5) & 1;
  }
  v14 = v12 + v13;
  if ( v14 != a1 )
  {
    v15 = (a2 >> 6) & 1;
    goto LABEL_31;
  }
  if ( (a2 & 0x40) == 0 )
  {
    v15 = 0;
LABEL_31:
    v16 = v14 + v15;
    if ( (char)a2 <= -1 && v16 == a1 )
      return 7;
    else
      return (unsigned int)-1;
  }
  return 6;
}
