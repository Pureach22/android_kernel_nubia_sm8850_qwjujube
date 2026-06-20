const char *__fastcall lim_mlm_state_str(unsigned int a1)
{
  if ( a1 > 0x1C )
    return "INVALID MLM state";
  else
    return off_AFC650[a1];
}
