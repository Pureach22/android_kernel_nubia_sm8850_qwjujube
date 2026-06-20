_DWORD *__fastcall policy_mgr_get_hw_mode_params(
        _DWORD *result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8
  int v14; // w8
  int v15; // w8
  _DWORD *v16; // x20
  unsigned int v18; // w0
  unsigned int v19; // w8
  unsigned int v20; // w9
  unsigned int v21; // w20

  if ( !result )
    return (_DWORD *)qdf_trace_msg(
                       0x4Fu,
                       2u,
                       "%s: Invalid capabilities",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       "policy_mgr_get_hw_mode_params");
  v10 = result[15];
  if ( v10 <= result[24] )
    v10 = result[24];
  v11 = ((v10 - ((v10 >> 1) & 0x55555555)) & 0x33333333) + (((v10 - ((v10 >> 1) & 0x55555555)) >> 2) & 0x33333333);
  *(_DWORD *)a2 = (16843009 * ((v11 + (v11 >> 4)) & 0xF0F0F0F)) >> 24;
  v12 = result[16];
  if ( v12 <= result[25] )
    v12 = result[25];
  *(_DWORD *)(a2 + 4) = (16843009
                       * ((((v12 - ((v12 >> 1) & 0x55555555)) & 0x33333333)
                         + (((v12 - ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333)
                         + ((((v12 - ((v12 >> 1) & 0x55555555)) & 0x33333333)
                           + (((v12 - ((v12 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
                        & 0xF0F0F0F)) >> 24;
  v13 = result[8];
  if ( v13 <= result[17] )
    v13 = result[17];
  if ( v13 > 6 )
    v14 = 0;
  else
    v14 = dword_9E7360[v13];
  *(_DWORD *)(a2 + 8) = v14;
  v15 = result[6];
  *(_DWORD *)(a2 + 12) = v15;
  if ( (v15 & 2) != 0 )
  {
    v16 = result;
    if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
      v18 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
    else
      v18 = wlan_reg_max_5ghz_chan_freq();
    v19 = v16[61];
    if ( v19 >= v18 )
      v20 = v18;
    else
      v20 = v16[61];
    if ( v19 )
      v21 = v20;
    else
      v21 = v18;
    result = (_DWORD *)wlan_reg_min_6ghz_chan_freq();
    *(_BYTE *)(a2 + 16) = v21 > (unsigned __int16)result;
  }
  return result;
}
