bool __fastcall is_multi_link_roam(_BOOL8 result)
{
  if ( result )
    return *(_BYTE *)(result + 2497) != 0;
  return result;
}
