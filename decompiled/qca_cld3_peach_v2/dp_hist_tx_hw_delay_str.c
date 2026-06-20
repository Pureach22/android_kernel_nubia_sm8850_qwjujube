const char *__fastcall dp_hist_tx_hw_delay_str(unsigned __int8 a1)
{
  if ( a1 <= 0xDu )
    return dp_hist_hw_tx_comp_dbucket_str[a1];
  else
    return "Invalid index";
}
