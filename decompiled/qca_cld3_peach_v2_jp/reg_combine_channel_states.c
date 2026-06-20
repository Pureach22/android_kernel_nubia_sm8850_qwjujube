__int64 __fastcall reg_combine_channel_states(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // w9

  if ( a1 >= a2 )
    v2 = a2;
  else
    v2 = a1;
  if ( a2 == 4 || a1 == 4 )
    return 4;
  else
    return v2;
}
