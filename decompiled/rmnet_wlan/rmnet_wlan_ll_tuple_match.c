__int64 __fastcall rmnet_wlan_ll_tuple_match(__int64 result)
{
  __int64 v1; // x9
  int v2; // w8
  int v3; // w8
  int v4; // w10
  unsigned __int8 *v5; // x10
  int v6; // w8
  int v7; // w10
  unsigned __int8 *v8; // x10
  bool v9; // zf
  bool v10; // zf
  unsigned __int16 *v11; // x8
  int v12; // w8
  int v13; // w8
  __int64 v14; // [xsp+0h] [xbp-40h]
  __int64 v15; // [xsp+0h] [xbp-40h]
  __int64 v16; // [xsp+8h] [xbp-38h]
  __int64 v17; // [xsp+8h] [xbp-38h]
  __int64 v18; // [xsp+10h] [xbp-30h] BYREF
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = rmnet_wlan_ll_tuple_cache;
  if ( !rmnet_wlan_ll_tuple_cache )
    goto LABEL_27;
  v2 = *(unsigned __int16 *)(result + 180);
  if ( v2 != 56710 )
  {
    if ( v2 != 8 )
      goto LABEL_27;
    v3 = *(_DWORD *)(result + 112);
    v4 = *(_DWORD *)(result + 116);
    LODWORD(v20) = 0;
    v18 = 0;
    v19 = 0;
    if ( v3 - v4 <= 19 )
    {
      if ( !result )
        goto LABEL_27;
      v14 = rmnet_wlan_ll_tuple_cache;
      v16 = result;
      v12 = skb_copy_bits(result, 0, &v18, 20);
      v1 = v14;
      result = v16;
      v5 = (unsigned __int8 *)&v18;
      if ( v12 < 0 )
        goto LABEL_27;
    }
    else
    {
      v5 = *(unsigned __int8 **)(result + 224);
      if ( !v5 )
        goto LABEL_27;
    }
    if ( *(_BYTE *)(v1 + 36) != *v5 >> 4
      && *((_DWORD *)v5 + 3) != *(_DWORD *)v1
      && *((_DWORD *)v5 + 4) != *(_DWORD *)(v1 + 16)
      || v5[9] != 17 )
    {
      goto LABEL_27;
    }
LABEL_24:
    v11 = (unsigned __int16 *)(*(_QWORD *)(result + 216) + *(unsigned __int16 *)(result + 182));
    if ( *v11 == *(unsigned __int16 *)(v1 + 32) && v11[1] == *(unsigned __int16 *)(v1 + 34) )
    {
      *(_DWORD *)(result + 144) = -1687355136;
      result = rmnet_wlan_stats_update(21);
    }
    goto LABEL_27;
  }
  v6 = *(_DWORD *)(result + 112);
  v7 = *(_DWORD *)(result + 116);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  if ( v6 - v7 <= 39 )
  {
    if ( !result )
      goto LABEL_27;
    v15 = rmnet_wlan_ll_tuple_cache;
    v17 = result;
    v13 = skb_copy_bits(result, 0, &v18, 40);
    v1 = v15;
    result = v17;
    v8 = (unsigned __int8 *)&v18;
    if ( v13 < 0 )
      goto LABEL_27;
  }
  else
  {
    v8 = *(unsigned __int8 **)(result + 224);
    if ( !v8 )
      goto LABEL_27;
  }
  if ( *(_BYTE *)(v1 + 36) == *v8 >> 4
    || (*((_QWORD *)v8 + 1) == *(_QWORD *)v1 ? (v9 = *((_QWORD *)v8 + 2) == *(_QWORD *)(v1 + 8)) : (v9 = 0),
        v9
     || (*((_QWORD *)v8 + 3) == *(_QWORD *)(v1 + 16) ? (v10 = *((_QWORD *)v8 + 4) == *(_QWORD *)(v1 + 24)) : (v10 = 0),
         v10)) )
  {
    if ( v8[6] == 17 )
      goto LABEL_24;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
