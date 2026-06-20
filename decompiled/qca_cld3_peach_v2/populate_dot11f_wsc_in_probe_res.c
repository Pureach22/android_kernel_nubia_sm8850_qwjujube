__int64 __fastcall populate_dot11f_wsc_in_probe_res(__int64 a1, __int64 a2)
{
  char v4; // w8
  char v5; // w8
  char v6; // w8
  char v7; // w8
  __int64 v8; // x0
  int manufacturer_name; // w0
  char v10; // w8
  int model_name; // w0
  char v12; // w8
  int model_number; // w0
  char v14; // w8
  int manufacture_product_version; // w0
  char v16; // w8
  __int16 v17; // w8
  int manufacture_product_name; // w0
  char v19; // w8
  __int16 v20; // w8
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5802LL);
  *(_BYTE *)(a2 + 1) = 1;
  *(_BYTE *)(a2 + 2) = v4;
  v5 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5801LL);
  *(_BYTE *)(a2 + 3) = 1;
  *(_BYTE *)(a2 + 5) = 0;
  *(_BYTE *)(a2 + 7) = 0;
  *(_BYTE *)(a2 + 10) = 0;
  *(_BYTE *)(a2 + 14) = 0;
  *(_BYTE *)(a2 + 18) = 1;
  *(_BYTE *)(a2 + 4) = v5;
  v6 = *(_BYTE *)(a1 + 12256);
  *(_WORD *)(a2 + 20) = 1;
  if ( (v6 & 0xFE) == 2 )
    v7 = 1;
  else
    v7 = 3;
  *(_BYTE *)(a2 + 19) = v7;
  wlan_mlme_get_wps_uuid(*(_QWORD *)(a1 + 8) + 5800LL, (void *)(a2 + 21));
  *(_BYTE *)(a2 + 37) = 1;
  v8 = *(_QWORD *)(a1 + 21624);
  v22 = 64;
  manufacturer_name = wlan_mlme_get_manufacturer_name(v8, a2 + 39, &v22);
  v10 = v22;
  *(_BYTE *)(a2 + 103) = 1;
  if ( manufacturer_name )
    v10 = 0;
  v22 = 32;
  *(_BYTE *)(a2 + 38) = v10;
  model_name = wlan_mlme_get_model_name(*(_QWORD *)(a1 + 21624), a2 + 105, &v22);
  v12 = v22;
  *(_BYTE *)(a2 + 137) = 1;
  v22 = 32;
  if ( model_name )
    v12 = 0;
  *(_BYTE *)(a2 + 104) = v12;
  model_number = wlan_mlme_get_model_number(*(_QWORD *)(a1 + 21624), a2 + 139, &v22);
  v14 = v22;
  *(_BYTE *)(a2 + 171) = 1;
  v22 = 32;
  if ( model_number )
    v14 = 0;
  *(_BYTE *)(a2 + 138) = v14;
  manufacture_product_version = wlan_mlme_get_manufacture_product_version(*(_QWORD *)(a1 + 21624), a2 + 173, &v22);
  v16 = v22;
  *(_BYTE *)(a2 + 206) = 1;
  v22 = 32;
  if ( manufacture_product_version )
    v16 = 0;
  *(_BYTE *)(a2 + 172) = v16;
  *(_WORD *)(a2 + 208) = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5808LL);
  *(_DWORD *)(a2 + 210) = bswap32(*(_DWORD *)(*(_QWORD *)(a1 + 8) + 5812LL));
  v17 = *(_WORD *)(*(_QWORD *)(a1 + 8) + 5816LL);
  *(_BYTE *)(a2 + 216) = 1;
  *(_WORD *)(a2 + 214) = v17;
  manufacture_product_name = wlan_mlme_get_manufacture_product_name(*(_QWORD *)(a1 + 21624), a2 + 218, &v22);
  v19 = v22;
  *(_BYTE *)(a2 + 250) = 1;
  if ( manufacture_product_name )
    v19 = 0;
  *(_BYTE *)(a2 + 217) = v19;
  v20 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5804LL);
  *(_BYTE *)(a2 + 254) = 0;
  *(_BYTE *)a2 = 1;
  *(_WORD *)(a2 + 252) = v20;
  _ReadStatusReg(SP_EL0);
  return 0;
}
