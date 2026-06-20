__int64 __fastcall ieee80211_config_bw(__int64 *a1, _QWORD *a2, char a3, _QWORD *a4)
{
  __int64 v5; // x8
  unsigned int v6; // w9
  __int64 v7; // x20
  __int64 v8; // x1
  unsigned int *v9; // x8
  unsigned int *v12; // x23
  __int64 v14; // x2
  unsigned int v15; // w0
  unsigned int v16; // w8
  __int64 v17; // x8
  int v18; // w8
  unsigned int v19; // w25
  _QWORD *v20; // x22
  _QWORD *v21; // x8
  __int64 v22; // x9
  __int64 v23; // x11
  __int64 v24; // x12
  __int64 v25; // x9
  __int64 v26; // x11
  __int64 v27; // x12
  __int64 v28; // x9
  __int64 v29; // x11
  __int64 v30; // x12
  __int64 result; // x0
  __int64 v32; // x22
  unsigned int v33; // w20
  __int64 v34; // x19
  __int64 v35; // x0
  __int64 v36; // x8
  unsigned int v37; // w19
  __int64 v38; // x21
  __int64 v39; // x3
  unsigned int v40; // w0
  __int64 v41; // x3
  __int64 v42; // x10
  _QWORD *v43; // x8
  __int64 v44; // x9
  __int64 v45; // x9
  __int64 v46; // x9
  __int64 *v47; // x2
  unsigned int v48; // w19
  _DWORD *v49; // [xsp+18h] [xbp-68h] BYREF
  __int64 v50; // [xsp+20h] [xbp-60h]
  __int64 v51; // [xsp+28h] [xbp-58h]
  __int64 v52; // [xsp+30h] [xbp-50h]
  _DWORD *v53; // [xsp+38h] [xbp-48h] BYREF
  __int64 v54; // [xsp+40h] [xbp-40h]
  __int64 v55; // [xsp+48h] [xbp-38h]
  __int64 v56; // [xsp+50h] [xbp-30h]
  _DWORD *v57; // [xsp+58h] [xbp-28h]
  __int64 v58; // [xsp+60h] [xbp-20h]
  __int64 v59; // [xsp+68h] [xbp-18h]
  __int64 v60; // [xsp+70h] [xbp-10h]
  __int64 v61; // [xsp+78h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[118];
  v6 = *((_DWORD *)a1 + 138);
  v7 = *a1;
  v59 = 0;
  v60 = 0;
  v8 = *(_QWORD *)(v5 + 136);
  v58 = 0;
  if ( v6 < 2 )
  {
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  v9 = (unsigned int *)a2[18];
  v12 = (unsigned int *)(a1 + 69);
  v51 = 0;
  v52 = 0;
  v49 = nullptr;
  v50 = 0;
  if ( v9 )
    v14 = *v9;
  else
    v14 = 0;
  v15 = ieee80211_determine_ap_chan(v7, v8, v14, a2, 1, v12, &v49);
  v16 = *v12;
  if ( v15 == *v12 )
  {
    v57 = nullptr;
    v53 = v49;
    v54 = v50;
    v55 = v51;
    v56 = v52;
    if ( v15 >= 5 && (*(_BYTE *)(v7 + 5872) & 0x20) == 0 )
    {
      v57 = v49;
      v58 = v50;
      v59 = v51;
      v60 = v52;
    }
    v17 = a2[17];
    if ( v17 )
    {
      v18 = *(unsigned __int16 *)(v17 + 2);
      if ( *(unsigned __int16 *)(a1[118] + 112) != v18 )
      {
        *a4 |= 0x10uLL;
        *(_WORD *)(a1[118] + 112) = v18;
      }
    }
    while ( 1 )
    {
      v19 = *((_DWORD *)a1 + 139);
      if ( v19 >= (unsigned int)ieee80211_min_bw_limit_from_chandef(&v53) )
        break;
      ieee80211_chandef_downgrade(&v53, 0);
    }
    if ( *v49 == 3 && *v12 >= 4 )
    {
      v20 = a2 + 61;
      ieee80211_rearrange_tpe(v20);
      if ( bcmp((const void *)(a1[118] + 724), v20, 0x68u) )
      {
        v21 = (_QWORD *)(a1[118] + 724);
        *v21 = *v20;
        v22 = v20[4];
        v23 = v20[1];
        v24 = v20[2];
        v21[3] = v20[3];
        v21[4] = v22;
        v21[1] = v23;
        v21[2] = v24;
        v25 = v20[8];
        v26 = v20[5];
        v27 = v20[6];
        v21[7] = v20[7];
        v21[8] = v25;
        v21[5] = v26;
        v21[6] = v27;
        v28 = v20[12];
        v29 = v20[9];
        v30 = v20[10];
        v21[11] = v20[11];
        v21[12] = v28;
        v21[9] = v29;
        v21[10] = v30;
        *a4 |= 0x800000000uLL;
      }
    }
    if ( !ieee80211_chanreq_identical((__int64)&v53, a1[118] + 136) )
    {
      v36 = *a1;
      if ( *(_WORD *)(*a1 + 5800) )
        printk(&unk_B7F80, v36 + 1640, *((unsigned int *)a1 + 2), a1 + 67);
      else
        printk(&unk_B9680, v36 + 1640, a1 + 67, (unsigned int)v53[1]);
      if ( (cfg80211_chandef_valid(&v53) & 1) == 0 )
      {
        printk(&unk_B8625, v7 + 1640, a1 + 67, v39);
        result = 4294967274LL;
        goto LABEL_20;
      }
      if ( (a3 & 1) == 0 )
      {
        v42 = v58;
        result = 0;
        v43 = (_QWORD *)a1[118];
        v43[21] = v57;
        v43[22] = v42;
        v44 = v60;
        v43[23] = v59;
        v43[24] = v44;
        v45 = v54;
        v43[17] = v53;
        v43[18] = v45;
        v46 = v56;
        v43[19] = v55;
        v43[20] = v46;
        goto LABEL_20;
      }
      v40 = ieee80211_link_change_chanreq(a1, (__int64 *)&v53, a4);
      if ( v40 )
      {
        v47 = a1 + 67;
        v48 = v40;
        printk(&unk_B8BFA, v7 + 1640, v47, v41);
        result = v48;
        goto LABEL_20;
      }
      cfg80211_schedule_channels_check(v7 + 16);
    }
    goto LABEL_19;
  }
  v32 = *a1;
  v33 = v15;
  if ( *(_WORD *)(*a1 + 5800) )
  {
    v37 = *((_DWORD *)a1 + 2);
    v38 = ieee80211_conn_mode_str(v16);
    ieee80211_conn_mode_str(v33);
    printk(&unk_B9DF8, v32 + 1640, v37, v38);
  }
  else
  {
    v34 = ieee80211_conn_mode_str(v16);
    v35 = ieee80211_conn_mode_str(v33);
    printk(&unk_BAC03, v32 + 1640, v34, v35);
  }
  result = 4294967274LL;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
