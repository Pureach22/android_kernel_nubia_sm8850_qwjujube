__int64 __fastcall sme_set_amsdu(__int64 result, char a2)
{
  *(_BYTE *)(result + 21624) = a2;
  return result;
}
