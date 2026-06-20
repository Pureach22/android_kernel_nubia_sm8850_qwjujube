__int64 __fastcall aw882xx_dev_check_profile_index(__int64 a1, int a2)
{
  if ( *(_DWORD *)(a1 + 624) <= (unsigned int)a2 || a2 < 0 )
    return 4294967274LL;
  else
    return 0;
}
