__int64 __fastcall pld_set_mode(char a1)
{
  if ( !pld_ctx )
    return 4294967284LL;
  *(_BYTE *)(pld_ctx + 36) = a1;
  return 0;
}
