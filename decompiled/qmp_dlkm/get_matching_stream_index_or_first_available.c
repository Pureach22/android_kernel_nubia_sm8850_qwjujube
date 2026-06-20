__int64 __fastcall get_matching_stream_index_or_first_available(__int64 a1)
{
  __int64 result; // x0
  bool v2; // w8
  int v3; // w16
  int v4; // w11
  unsigned __int8 v5; // w8
  int v6; // w11
  int v7; // w8
  bool v8; // zf
  unsigned int v13; // w0
  unsigned int v14; // w19

  if ( aggregator_[0] == a1 )
    return 0;
  if ( qword_B288 == a1 )
    return 1;
  if ( qword_B4A0 == a1 )
    return 2;
  if ( qword_B6B8 == a1 )
    return 3;
  if ( qword_B8D0 == a1 )
    return 4;
  if ( qword_BAE8 == a1 )
    return 5;
  if ( qword_BD00 == a1 )
    return 6;
  v8 = qword_BF18 == a1;
  result = 7;
  if ( !v8 )
  {
    v2 = aggregator_[0] != 0;
    if ( aggregator_[0] )
      v3 = -1;
    else
      v3 = 0;
    v4 = qword_B288 == 0 && v2;
    v5 = v4 ^ v2;
    if ( v4 )
      v6 = 1;
    else
      v6 = v3;
    if ( ((qword_B4A0 == 0) & v5) != 0 )
      v7 = 2;
    else
      v7 = v6;
    v8 = v7 == -1 && qword_B6B8 == 0;
    if ( v8 )
      v7 = 3;
    if ( v7 == -1 && qword_B8D0 == 0 )
      v7 = 4;
    if ( v7 == -1 && qword_BAE8 == 0 )
      v7 = 5;
    if ( v7 == -1 && qword_BD00 == 0 )
      v7 = 6;
    if ( v7 == -1 && qword_BF18 == 0 )
      v13 = 7;
    else
      v13 = v7;
    if ( v13 <= 7 )
    {
      v14 = v13;
      memset(&aggregator_[67 * v13], 0, 0x218u);
      return v14;
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
