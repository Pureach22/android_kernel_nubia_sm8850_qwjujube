bool __fastcall sde_evtlog_is_enabled(_BOOL8 result, int a2)
{
  if ( result )
    return (*(_DWORD *)(result + 786452) & a2) != 0;
  return result;
}
