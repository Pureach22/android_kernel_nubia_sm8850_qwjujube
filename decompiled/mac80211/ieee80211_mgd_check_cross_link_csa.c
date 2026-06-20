__int64 __fastcall ieee80211_mgd_check_cross_link_csa(__int64 result, unsigned int a2, __int64 a3)
{
  unsigned __int16 *v3; // x8
  unsigned __int64 v4; // x9
  unsigned int v6; // w10
  unsigned int v8; // w11
  int v9; // w10
  bool v10; // zf
  unsigned __int64 v11; // x10
  int v12; // w11
  __int64 v13; // x10
  __int64 v14; // x21
  char *v15; // x24
  char *v16; // x23
  __int64 v17; // x27
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned int v20; // w9
  int v21; // w10
  char v22; // w10
  char v23; // w11
  __int64 v24; // x10
  int v25; // w22
  __int64 v26; // x26
  __int64 v27; // x0
  __int64 v28; // x27
  unsigned __int64 v29; // x25
  __int64 v30; // x22
  __int64 v31; // x20
  __int64 v32; // x23
  __int64 v33; // x24
  __int64 v34; // x8
  char *v35; // [xsp+8h] [xbp-148h]
  _QWORD v36[8]; // [xsp+10h] [xbp-140h] BYREF
  _QWORD v37[15]; // [xsp+50h] [xbp-100h] BYREF
  _QWORD v38[17]; // [xsp+C8h] [xbp-88h] BYREF

  v38[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int16 **)(a3 + 448);
  memset(v38, 0, 120);
  memset(v37, 0, sizeof(v37));
  if ( !v3 )
    goto LABEL_25;
  v4 = *(_QWORD *)(a3 + 720);
  if ( v4 < 2 )
    goto LABEL_25;
  v6 = *v3;
  v8 = v6 & 7;
  if ( v8 <= 1 )
  {
    if ( (v6 & 7) != 0 )
    {
      if ( v8 != 1 )
        goto LABEL_27;
      if ( (v6 & 0x10) != 0 )
        LOBYTE(v9) = 2;
      else
        LOBYTE(v9) = 1;
    }
    else
    {
      if ( (v6 & 0x10) != 0 )
        v12 = 8;
      else
        v12 = 7;
      v9 = v12
         + (((unsigned __int8)(v6 & 0xE0) >> 5) & 1)
         + (((unsigned __int8)v6 >> 5) & 2)
         + ((v6 >> 6) & 2)
         + ((v6 >> 7) & 2)
         + ((v6 >> 9) & 1);
    }
LABEL_23:
    if ( (unsigned __int64)(unsigned __int8)v9 + 2 <= v4
      && *((unsigned __int8 *)v3 + 2) >= (unsigned int)(unsigned __int8)v9 )
    {
      goto LABEL_26;
    }
    goto LABEL_25;
  }
  switch ( v8 )
  {
    case 2u:
      v10 = (v6 & 0x10) == 0;
      v11 = 8;
      if ( v10 )
        v11 = 2;
      if ( v11 <= v4 )
        goto LABEL_26;
      goto LABEL_25;
    case 3u:
      LOBYTE(v9) = 7;
      goto LABEL_23;
    case 4u:
      if ( v4 >= 9 )
      {
LABEL_26:
        v13 = (unsigned __int8)(*((_BYTE *)v3 + 2) + 2);
        goto LABEL_28;
      }
LABEL_25:
      _ReadStatusReg(SP_EL0);
      return result;
  }
LABEL_27:
  __break(0x800u);
  v3 = *(unsigned __int16 **)(a3 + 448);
  v4 = *(_QWORD *)(a3 + 720);
  v13 = 0;
LABEL_28:
  v14 = v4 - v13;
  v35 = (char *)v3 + v13;
  if ( (__int64)(v4 - v13) < 2 )
  {
LABEL_51:
    v28 = 8LL * a2;
    v29 = 0;
    v30 = result + 4568;
    while ( 1 )
    {
      if ( v28 == v29 )
        goto LABEL_53;
      v31 = *(_QWORD *)(v30 + v29);
      if ( !v31 )
        goto LABEL_53;
      v32 = v38[v29 / 8];
      if ( v32 )
      {
        v33 = v37[v29 / 8];
        result = cfg80211_defragment_element(v38[v29 / 8], v35, v14, v38[v29 / 8], v33, 254);
        if ( result != v33 )
        {
          __break(0x800u);
          goto LABEL_53;
        }
        v34 = *(unsigned __int8 *)(v32 + 2);
        memset(&v36[3], 0, 32);
        --v34;
        v36[2] = v33 - v34;
        v36[0] = 5;
        v36[1] = v32 + v34 + 3;
        v36[7] = 0xFFFFFFFFLL;
        result = ieee802_11_parse_elems_full(v36);
        v32 = result;
        if ( !result )
          goto LABEL_53;
      }
      ieee80211_sta_process_chanswitch(v31, 0, 0, a3, (_QWORD *)v32, 1);
      result = kfree(v32);
LABEL_53:
      v29 += 8LL;
      if ( v29 == 120 )
        goto LABEL_25;
    }
  }
  v15 = (char *)v3 + v4;
  v16 = (char *)v3 + v13;
  v17 = result + 4568;
  v18 = v4 - v13;
  while ( 1 )
  {
    v19 = (unsigned __int8)v16[1];
    if ( v18 < v19 + 2 )
      goto LABEL_51;
    if ( !*v16 && (unsigned int)v19 >= 3 )
    {
      v20 = *((unsigned __int16 *)v16 + 1);
      v21 = ((v20 >> 4) & 8 | (v20 >> 5) & 2) + ((v20 >> 7) & 2);
      if ( (v20 & 0x20) != 0 )
        v22 = v21 + 7;
      else
        v22 = v21 + 1;
      v23 = v22 + 2;
      if ( (v20 & 0x400) == 0 )
        v23 = v22 + 1;
      if ( (~v20 & 0x210) != 0 )
        v23 = v22;
      v24 = (unsigned __int8)v16[4];
      if ( (unsigned int)v24 >= (unsigned __int8)(v23 + ((v20 & 0x800) != 0)) && v24 + 2 <= v19 )
      {
        v25 = v20 & 0xF;
        if ( v25 != 15 && v25 != a2 && *(_QWORD *)(v17 + 8LL * (v20 & 0xF)) )
          break;
      }
    }
LABEL_32:
    v16 += (unsigned __int8)v16[1] + 2;
    v18 = v15 - v16;
    if ( v15 - v16 <= 1 )
      goto LABEL_51;
  }
  v26 = result;
  v27 = cfg80211_defragment_element(v16, v35, v14, 0, 0, 254);
  if ( v27 < 0 )
  {
    __break(0x800u);
LABEL_31:
    result = v26;
    goto LABEL_32;
  }
  if ( v25 != 15 )
  {
    v37[v25] = v27;
    v38[v25] = v16;
    goto LABEL_31;
  }
  __break(1u);
  return ieee80211_sta_wmm_params();
}
