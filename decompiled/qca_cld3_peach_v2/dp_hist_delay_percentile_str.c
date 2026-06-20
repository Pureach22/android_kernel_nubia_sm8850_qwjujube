const char *__fastcall dp_hist_delay_percentile_str(unsigned __int8 a1)
{
  if ( a1 <= 0xDu )
    return dp_hist_delay_percentile_dbucket_str[a1];
  else
    return "Invalid index";
}
