__int64 __fastcall populate_dot11f_supp_channels(__int64 a1, _BYTE *a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  int v26; // w25
  unsigned int v27; // w8
  int v28; // w10
  unsigned __int8 *v29; // x28
  unsigned __int8 *v30; // x26
  unsigned __int8 v31; // w10
  unsigned __int8 v32; // w20
  unsigned int v33; // w9
  __int64 v34; // x27
  int v35; // w1
  __int16 v36; // [xsp+Ch] [xbp-74h] BYREF
  char v37; // [xsp+Eh] [xbp-72h]
  _QWORD v38[12]; // [xsp+10h] [xbp-70h] BYREF
  char v39; // [xsp+70h] [xbp-10h]
  __int64 v40; // [xsp+78h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a4 + 284);
  v39 = 0;
  memset(v38, 0, sizeof(v38));
  v37 = 0;
  v36 = 0;
  if ( wlan_reg_is_5ghz_ch_freq(v7) )
  {
    wlan_add_supported_5ghz_channels(*(_QWORD *)(a1 + 21552), *(_QWORD *)(a1 + 21560), (__int64)v38 + 1, v38, 0);
  }
  else if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a4 + 284)) )
  {
    wlan_add_supported_6ghz_channels(*(_QWORD *)(a1 + 21552), *(_QWORD *)(a1 + 21560), (__int64)v38 + 1, v38, 0);
  }
  a2[1] = v38[0];
  result = wlan_reg_read_current_country(*(_QWORD *)(a1 + 21552), &v36, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( a2[1] )
  {
    v25 = 0;
    v26 = 0;
    do
    {
      if ( (unsigned __int8)v26 > 0x5Fu )
      {
LABEL_22:
        __break(1u);
LABEL_23:
        __break(0x5512u);
      }
      v29 = (unsigned __int8 *)v38 + (unsigned __int8)v26 + 1;
      result = wlan_reg_dmn_get_opclass_from_channel(
                 (unsigned __int8 *)&v36,
                 *v29,
                 0,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24);
      if ( v25 == 48 )
        goto LABEL_23;
      v30 = &a2[2 * v25 + 2];
      v31 = *v29;
      v30[1] = 1;
      v27 = (unsigned __int8)a2[1];
      *v30 = v31;
      if ( v27 > (unsigned __int8)(v26 + 1) )
      {
        v32 = result;
        v33 = (unsigned __int8)(v26 + 1);
        v34 = (unsigned __int8)v26 - 1LL;
        while ( 1 )
        {
          if ( (unsigned __int64)++v34 > 0x5F || v33 > 0x5F )
            goto LABEL_22;
          v35 = *((unsigned __int8 *)v38 + v33 + 1);
          if ( *v29 + 4 != v35 )
            goto LABEL_8;
          result = wlan_reg_dmn_get_opclass_from_channel(
                     (unsigned __int8 *)&v36,
                     v35,
                     0,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     v24);
          if ( (unsigned __int8)result != v32 )
            break;
          v28 = v26 + 1;
          v33 = (unsigned __int8)v26 + 2;
          v29 = (unsigned __int8 *)v38 + (unsigned __int8)++v26 + 1;
          ++v30[1];
          v27 = (unsigned __int8)a2[1];
          if ( v33 >= v27 )
            goto LABEL_9;
        }
        LOBYTE(v27) = a2[1];
      }
LABEL_8:
      v28 = v26;
LABEL_9:
      v26 = v28 + 1;
      ++v25;
    }
    while ( (unsigned __int8)(v28 + 1) < (unsigned int)(unsigned __int8)v27 );
  }
  else
  {
    LOBYTE(v25) = 0;
  }
  a2[1] = v25;
  *a2 = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
