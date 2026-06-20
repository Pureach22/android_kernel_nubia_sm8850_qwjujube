__int64 __fastcall wlansap_update_sap_chan_list(__int64 a1, const void *a2, unsigned __int16 a3)
{
  unsigned __int8 v3; // w23
  size_t v6; // x21
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x22
  __int64 v12; // x0
  unsigned __int8 v13; // w24
  unsigned int v14; // w8
  __int64 v15; // x23
  __int64 v16; // x9
  char v18; // w23
  void *v19; // x0
  unsigned int v20; // w8
  __int64 v21; // x20
  __int64 v22; // x9

  v3 = a3;
  v6 = 4LL * a3;
  v7 = _qdf_mem_malloc(v6, "wlansap_update_sap_chan_list", 4295);
  if ( !v7 )
    return 4294967284LL;
  v8 = v7;
  v9 = *(_QWORD *)(a1 + 1160);
  if ( v9 )
  {
    _qdf_mem_free(v9);
    *(_BYTE *)(a1 + 1168) = 0;
  }
  *(_QWORD *)(a1 + 1160) = v8;
  v10 = _qdf_mem_malloc(v6, "wlansap_update_sap_chan_list", 4305);
  if ( !v10 )
    return 4294967284LL;
  v11 = v10;
  v12 = *(_QWORD *)(a1 + 1176);
  v13 = v3;
  if ( !v12 )
  {
    v18 = 0;
    goto LABEL_19;
  }
  v14 = *(unsigned __int8 *)(a1 + 1184);
  if ( !*(_BYTE *)(a1 + 1184) )
  {
    v18 = 1;
    goto LABEL_18;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = *(_QWORD *)(a1 + 1176);
    if ( v16 )
      break;
LABEL_8:
    if ( ++v15 >= (unsigned __int64)v14 )
    {
      v18 = 1;
      goto LABEL_17;
    }
  }
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v16 + 4 * v15)) )
  {
    v14 = *(unsigned __int8 *)(a1 + 1184);
    goto LABEL_8;
  }
  v18 = 0;
LABEL_17:
  v12 = *(_QWORD *)(a1 + 1176);
LABEL_18:
  _qdf_mem_free(v12);
  *(_BYTE *)(a1 + 1184) = 0;
LABEL_19:
  v19 = *(void **)(a1 + 1160);
  *(_QWORD *)(a1 + 1176) = v11;
  qdf_mem_copy(v19, a2, (unsigned int)v6);
  qdf_mem_copy(*(void **)(a1 + 1176), a2, (unsigned int)v6);
  v20 = v13;
  *(_BYTE *)(a1 + 1184) = v13;
  *(_BYTE *)(a1 + 1168) = v13;
  if ( !v13 )
    goto LABEL_27;
  v21 = 0;
  while ( 2 )
  {
    v22 = *(_QWORD *)(a1 + 1176);
    if ( !v22 )
    {
LABEL_21:
      if ( ++v21 >= (unsigned __int64)v20 )
      {
        LOBYTE(v20) = 0;
        goto LABEL_27;
      }
      continue;
    }
    break;
  }
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v22 + 4 * v21)) )
  {
    v20 = *(unsigned __int8 *)(a1 + 1184);
    goto LABEL_21;
  }
  LOBYTE(v20) = 1;
LABEL_27:
  *(_BYTE *)(a1 + 1185) = v18 & v20;
  sap_dump_acs_channel(a1 + 1144);
  return 0;
}
