__int64 __fastcall hdd_update_acs_channel_list(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x23
  __int64 v5; // x21
  int v6; // w22
  unsigned int v7; // w0

  v2 = result;
  if ( *(_BYTE *)(result + 1168) )
  {
    v3 = 4LL * *(unsigned __int8 *)(result + 1168);
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = *(_DWORD *)(*(_QWORD *)(v2 + 1160) + v5);
      if ( a2 == 1 )
      {
        result = wlan_reg_is_24ghz_ch_freq(v7);
        if ( (result & 1) == 0 )
          goto LABEL_4;
      }
      else
      {
        result = wlan_reg_is_5ghz_ch_freq(v7);
        if ( (result & 1) == 0 )
        {
          result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(*(_QWORD *)(v2 + 1160) + v5));
          if ( (result & 1) == 0 )
            goto LABEL_4;
        }
      }
      *(_DWORD *)(*(_QWORD *)(v2 + 1160) + 4LL * v6++) = *(_DWORD *)(*(_QWORD *)(v2 + 1160) + v5);
LABEL_4:
      v5 += 4;
      if ( v3 == v5 )
        goto LABEL_12;
    }
  }
  LOBYTE(v6) = 0;
LABEL_12:
  *(_BYTE *)(v2 + 1168) = v6;
  return result;
}
