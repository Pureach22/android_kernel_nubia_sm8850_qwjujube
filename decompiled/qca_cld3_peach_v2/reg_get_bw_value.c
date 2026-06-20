__int64 __fastcall reg_get_bw_value(unsigned int a1)
{
  if ( a1 > 9 )
    return 0;
  else
    return word_AD8180[a1];
}
