__int64 __fastcall lim_check_for_ml_probe_req(__int64 a1)
{
  __int64 v1; // x8

  if ( !a1 )
    return 29;
  v1 = *(_QWORD *)(a1 + 112);
  if ( !v1 )
    return 29;
  if ( *(_BYTE *)(v1 + 4545) )
    return 0;
  return 16;
}
