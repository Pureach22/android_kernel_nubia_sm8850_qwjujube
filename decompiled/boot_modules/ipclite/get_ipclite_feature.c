bool __fastcall get_ipclite_feature(int a1)
{
  return ((unsigned int)feature_mask & a1) != 0;
}
