__int64 __fastcall lim_get_htcb_state(int a1)
{
  if ( (unsigned int)(a1 - 1) > 9 )
    return 0;
  else
    return dword_A0A0A8[a1 - 1];
}
