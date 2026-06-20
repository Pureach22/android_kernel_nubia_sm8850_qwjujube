__int64 __fastcall dp_get_context_size_be(unsigned int a1)
{
  if ( a1 > 3 )
    return 0;
  else
    return (__int64)*(&off_B353E8 + a1);
}
