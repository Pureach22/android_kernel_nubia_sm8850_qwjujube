__int64 __fastcall is_skip_op_required(__int64 a1)
{
  if ( !a1 )
    return 0;
  if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
    return 1;
  return *(_BYTE *)(a1 + 1641) & 1;
}
