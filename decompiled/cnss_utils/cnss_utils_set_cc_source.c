void __fastcall cnss_utils_set_cc_source(__int64 a1, int a2)
{
  if ( cnss_utils_priv )
    *(_DWORD *)(cnss_utils_priv + 448) = a2;
}
