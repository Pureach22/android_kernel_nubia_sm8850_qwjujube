__int64 __fastcall debugfs_panic_state_write(__int64 a1, char a2)
{
  char v2; // w9
  __int64 result; // x0
  char v4; // w9

  v2 = word_A630;
  result = 0;
  if ( (a2 & 1) == 0 )
    v2 = 0;
  LOBYTE(word_A62E) = v2;
  if ( (a2 & 2) != 0 )
    v4 = HIBYTE(word_A630);
  else
    v4 = 0;
  HIBYTE(word_A62E) = v4;
  return result;
}
