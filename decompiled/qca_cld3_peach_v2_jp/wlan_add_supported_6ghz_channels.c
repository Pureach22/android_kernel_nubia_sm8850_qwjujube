__int64 __fastcall wlan_add_supported_6ghz_channels(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4, char a5)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w23
  int v19; // w8
  unsigned __int16 v20; // w9
  __int64 v21; // x24
  __int64 v22; // x26
  int v23; // w27
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    if ( a3 )
    {
      v18 = *(_DWORD *)(result + 6176);
      if ( v18 )
      {
        v19 = 0;
        v20 = 0;
        v21 = result + 5776;
        do
        {
          v22 = v20;
          v23 = v19;
          result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v21 + 4LL * v20));
          if ( (result & 1) != 0 )
          {
            result = wlan_reg_freq_to_chan(a2, *(_DWORD *)(v21 + 4 * v22), v24, v25, v26, v27, v28, v29, v30, v31);
            *(_BYTE *)(a3 + (unsigned __int16)v23) = result;
            v19 = v23 + 1;
            if ( (a5 & 1) != 0 )
            {
              v19 = v23 + 2;
              *(_BYTE *)(a3 + (unsigned __int16)(v23 + 1)) = 1;
            }
          }
          else
          {
            v19 = v23;
          }
          v20 = v22 + 1;
        }
        while ( v18 > (unsigned __int16)(v22 + 1) );
        goto LABEL_12;
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s: chan_list buffer NULL",
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 "wlan_add_supported_6ghz_channels");
    }
    LOBYTE(v19) = 0;
LABEL_12:
    *a4 = v19;
  }
  return result;
}
