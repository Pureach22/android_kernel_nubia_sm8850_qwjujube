__int64 __fastcall synx_encode_handle(unsigned int a1, int a2, char a3)
{
  int v3; // w8
  unsigned int v4; // w8

  if ( (a3 & 1) != 0 )
    v3 = 16;
  else
    v3 = 0;
  v4 = a1 + ((v3 | a2) << 16);
  if ( a1 <= 0xFFF )
    return v4;
  else
    return 0;
}
