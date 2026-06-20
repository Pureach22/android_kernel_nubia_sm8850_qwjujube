__int64 __fastcall reg_is_chan_disabled_and_not_nol(__int64 a1)
{
  char v2; // w8

  if ( (reg_is_state_allowed(*(unsigned int *)(a1 + 8)) & 1) != 0
    || (*(_BYTE *)(a1 + 12) & 1) == 0
    || (*(_BYTE *)(a1 + 25) & 1) != 0 )
  {
    v2 = 0;
  }
  else
  {
    v2 = *(_BYTE *)(a1 + 26) ^ 1;
  }
  return v2 & 1;
}
