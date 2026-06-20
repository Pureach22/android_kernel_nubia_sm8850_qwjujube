__int64 __fastcall sub_8D10(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w13

  if ( (v4 & 0x1000000) == 0 )
    JUMPOUT(0x7D5C);
  return swr_write(a1, a2, a3, a4);
}
