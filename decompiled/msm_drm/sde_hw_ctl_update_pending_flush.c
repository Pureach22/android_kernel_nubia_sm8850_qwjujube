__int64 __fastcall sde_hw_ctl_update_pending_flush(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a1 + 96) |= *a2;
      return 0;
    }
  }
  return result;
}
