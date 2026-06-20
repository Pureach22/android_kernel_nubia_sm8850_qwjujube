__int64 __fastcall reg_fetch_punc_bitmap(__int64 result)
{
  if ( result )
    return *(unsigned __int16 *)(result + 22);
  return result;
}
