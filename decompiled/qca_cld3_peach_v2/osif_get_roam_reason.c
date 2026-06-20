__int64 __fastcall osif_get_roam_reason(__int16 a1)
{
  if ( (unsigned __int16)(a1 - 1) > 0xBu )
    return 0;
  else
    return dword_ACFB94[(unsigned __int16)(a1 - 1)];
}
