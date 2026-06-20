__int64 __fastcall btfm_get_bt_soc_index(int a1)
{
  __int64 result; // x0
  int v3; // w9

  if ( a1 <= 1075839487 )
  {
    if ( (unsigned int)(a1 - 1075839232) < 6 )
      return 0;
    goto LABEL_12;
  }
  result = 1;
  if ( a1 <= 1075905023 )
  {
    if ( a1 == 1075839488 )
      return 0;
    v3 = 1075904768;
  }
  else
  {
    if ( a1 == 1075905024 || a1 == 1076240640 )
      return result;
    v3 = 1076437248;
  }
  if ( a1 != v3 )
  {
LABEL_12:
    printk(&unk_7817, "btfm_get_bt_soc_index");
    return 1;
  }
  return result;
}
