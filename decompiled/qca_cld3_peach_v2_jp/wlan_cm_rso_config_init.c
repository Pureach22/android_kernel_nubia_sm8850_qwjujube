__int64 __fastcall wlan_cm_rso_config_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 psoc_ext_obj_fl; // x0
  __int64 v6; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  __int64 v24; // x24
  _DWORD *v25; // x22
  unsigned __int8 *v26; // x25
  unsigned int v27; // t1
  __int64 result; // x0
  int v29; // w8
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  v30 = 7;
  if ( v2 && *(_QWORD *)(v2 + 80) && (psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(v2 + 80))) != 0 )
  {
    v6 = psoc_ext_obj_fl;
    qdf_mutex_create(a2);
    *(_DWORD *)(a2 + 136) = *(unsigned __int16 *)(v6 + 1734);
    *(_DWORD *)(a2 + 140) = *(_DWORD *)(v6 + 1736);
    *(_DWORD *)(a2 + 132) = *(unsigned __int16 *)(v6 + 1732);
    *(_BYTE *)(a2 + 128) = *(_DWORD *)(v6 + 1720);
    *(_BYTE *)(a2 + 129) = *(_DWORD *)(v6 + 1720);
    *(_BYTE *)(a2 + 130) = *(_BYTE *)(v6 + 1584);
    *(_BYTE *)(a2 + 148) = *(_DWORD *)(v6 + 1724);
    *(_BYTE *)(a2 + 149) = *(_DWORD *)(v6 + 1728);
    *(_BYTE *)(a2 + 150) = *(_BYTE *)(v6 + 1748);
    *(_BYTE *)(a2 + 151) = *(_BYTE *)(v6 + 1749);
    *(_DWORD *)(a2 + 104) = *(_DWORD *)(v6 + 1712);
    *(_DWORD *)(a2 + 108) = *(_DWORD *)(v6 + 1716);
    *(_WORD *)(a2 + 144) = *(_DWORD *)(v6 + 1740);
    *(_WORD *)(a2 + 146) = *(_DWORD *)(v6 + 1744);
    *(_DWORD *)(a2 + 184) = *(_DWORD *)(v6 + 1944);
    *(_BYTE *)(a2 + 188) = *(_BYTE *)(v6 + 3412);
    *(_BYTE *)(a2 + 194) = *(_DWORD *)(v6 + 1780);
    *(_WORD *)(a2 + 192) = *(_WORD *)(v6 + 1778);
    *(_DWORD *)(a2 + 196) = *(_DWORD *)(v6 + 1932);
    *(_DWORD *)(a2 + 200) = *(_DWORD *)(v6 + 1936);
    *(_BYTE *)(a2 + 112) = *(_BYTE *)(v6 + 1885);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: number of channels: %u",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_cm_rso_config_init");
    if ( *(_BYTE *)(a2 + 112) )
    {
      v23 = _qdf_mem_malloc(4LL * *(unsigned __int8 *)(a2 + 112), "wlan_cm_rso_config_init", 1879);
      *(_QWORD *)(a2 + 120) = v23;
      if ( !v23 )
      {
        *(_BYTE *)(a2 + 112) = 0;
        result = 2;
        goto LABEL_11;
      }
      v24 = *(unsigned __int8 *)(v6 + 1885);
      if ( *(_BYTE *)(v6 + 1885) )
      {
        v25 = (_DWORD *)v23;
        v26 = (unsigned __int8 *)(v6 + 1785);
        do
        {
          v27 = *v26++;
          --v24;
          *v25++ = wlan_reg_legacy_chan_to_freq(v2, v27, v15, v16, v17, v18, v19, v20, v21, v22);
        }
        while ( v24 );
      }
    }
    else
    {
      *(_QWORD *)(a2 + 120) = 0;
    }
    *(_DWORD *)(a2 + 152) = *(_DWORD *)(v6 + 1756);
    *(_DWORD *)(a2 + 156) = *(_DWORD *)(v6 + 1760);
    *(_DWORD *)(a2 + 160) = *(_DWORD *)(v6 + 1764);
    *(_DWORD *)(a2 + 164) = *(_DWORD *)(v6 + 1768);
    *(_BYTE *)(a2 + 189) = *(_BYTE *)(v6 + 1704);
    *(_BYTE *)(a2 + 190) = *(_BYTE *)(v6 + 1705);
    *(_BYTE *)(a2 + 224) = *(_BYTE *)(v6 + 1706);
    *(_BYTE *)(a2 + 191) = *(_BYTE *)(v6 + 1707);
    ucfg_reg_get_band(*(_QWORD *)(a1 + 152), &v30, v15, v16, v17, v18, v19, v20, v21, v22);
    v29 = v30;
    result = 0;
    *(_BYTE *)(a2 + 1366) = 0;
    *(_DWORD *)(a2 + 944) = v29;
  }
  else
  {
    result = 4;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
