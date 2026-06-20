unsigned int *__fastcall ieee80211_vif_inc_num_mcast(unsigned int *result)
{
  unsigned int v1; // w8
  unsigned int v8; // w9
  unsigned int v11; // w9

  v1 = result[1180];
  if ( v1 == 4 )
  {
    _X8 = result + 572;
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 + 1, _X8) );
  }
  else if ( v1 == 3 )
  {
    _X8 = result + 644;
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stxr(v8 + 1, _X8) );
  }
  return result;
}
