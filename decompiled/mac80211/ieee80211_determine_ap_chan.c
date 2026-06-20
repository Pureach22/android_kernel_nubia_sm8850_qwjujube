__int64 __fastcall ieee80211_determine_ap_chan(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        _QWORD *a4,
        char a5,
        _DWORD *a6,
        __int64 *a7)
{
  __int64 v7; // x8
  unsigned __int8 *v8; // x22
  __int64 v10; // x24
  __int64 v11; // x23
  unsigned __int8 *v13; // x21
  unsigned __int16 v14; // w9
  __int64 v15; // x28
  unsigned int v16; // w8
  int v17; // w8
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 result; // x0
  unsigned int v25; // w0
  __int64 v26; // x2
  unsigned __int64 v27; // x3
  __int64 v28; // x2
  __int64 v29; // x3
  unsigned int v30; // w22
  char v31; // w8
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x11
  void *v35; // x0
  unsigned int v36; // w22
  int v37; // w8
  void *v38; // x0
  char v39; // w9
  __int64 v40; // x0
  __int64 v41; // x2
  __int64 v42; // x3
  __int64 v43; // x9
  __int64 v44; // x10
  __int16 v45; // w8
  __int64 v46; // x2
  __int64 v47; // x3
  __int64 v48; // x9
  __int64 v49; // x10
  void *v50; // x0
  unsigned int v51; // [xsp+Ch] [xbp-54h]
  __int64 v53; // [xsp+18h] [xbp-48h] BYREF
  __int64 v54; // [xsp+20h] [xbp-40h]
  __int64 v55; // [xsp+28h] [xbp-38h]
  __int64 v56; // [xsp+30h] [xbp-30h]
  __int64 v57; // [xsp+38h] [xbp-28h] BYREF
  __int64 v58; // [xsp+40h] [xbp-20h]
  __int64 v59; // [xsp+48h] [xbp-18h]
  __int64 v60; // [xsp+50h] [xbp-10h]
  __int64 v61; // [xsp+58h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *a2;
  if ( (unsigned int)v7 >= 6 )
    __break(0x5512u);
  v8 = (unsigned __int8 *)a4[17];
  v10 = a4[19];
  v11 = a4[22];
  v13 = (unsigned __int8 *)a4[55];
  v14 = *((_WORD *)a2 + 4);
  v15 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL) + 8 * v7 + 328);
  v16 = a2[1];
  v59 = 0;
  v60 = 0;
  *a7 = (__int64)a2;
  *((_DWORD *)a7 + 2) = 0;
  *((_DWORD *)a7 + 3) = v16;
  *((_DWORD *)a7 + 4) = 0;
  *(__int64 *)((char *)a7 + 20) = 0;
  *((_DWORD *)a7 + 7) = v14;
  v17 = *(_DWORD *)(v15 + 16);
  v57 = 0;
  v58 = 0;
  if ( v17 == 3 )
  {
    if ( *a6 < 4u )
    {
      result = 1;
      goto LABEL_22;
    }
    if ( a4[25] && a4[21] )
    {
      if ( v13 && a4[54] )
      {
        v30 = 5;
      }
      else
      {
        v13 = nullptr;
        v30 = 4;
      }
      v31 = ieee80211_chandef_he_6ghz_oper(*(_QWORD *)(a1 + 1616), v11, v13, a7);
      result = v30;
      if ( (v31 & 1) != 0 )
        goto LABEL_22;
      v38 = &unk_BC369;
    }
    else
    {
      v38 = &unk_B8995;
    }
    printk(v38, a1 + 1640, a3, a4);
    result = 1;
    goto LABEL_22;
  }
  if ( v17 == 4 )
  {
    if ( (ieee80211_chandef_s1g_oper(a4[51], a7) & 1) != 0 )
    {
      result = 0;
    }
    else
    {
      printk(&unk_B833C, a1 + 1640, v19, v20);
      v37 = ieee80211_s1g_channel_width(a2);
      result = 0;
      *((_DWORD *)a7 + 2) = v37;
    }
    goto LABEL_22;
  }
  result = 1;
  if ( *a6 >= 2u && v8 && a4[16] )
  {
    *((_DWORD *)a7 + 2) = 1;
    v51 = a3;
    v25 = ieee80211_channel_to_freq_khz(*v8, *a2);
    if ( (a5 & 1) == 0 )
    {
      v26 = a2[1];
      v27 = v25 / 0x3E8uLL;
      if ( (_DWORD)v26 != (_DWORD)v27 )
      {
        printk(&unk_B837E, a1 + 1640, v26, v27);
        result = 1;
        goto LABEL_22;
      }
    }
    ieee80211_chandef_ht_oper(v8, a7);
    if ( *a6 < 3u )
    {
      result = 2;
      goto LABEL_22;
    }
    v32 = a7[1];
    v33 = a7[2];
    v34 = a7[3];
    v57 = *a7;
    v58 = v32;
    v59 = v33;
    v60 = v34;
    if ( !a4[21] || !v11 || (*(_BYTE *)(v11 + 1) & 0x40) == 0 )
    {
      if ( v10 && a4[18] )
      {
        if ( *(_DWORD *)(v15 + 16) )
        {
          if ( (ieee80211_chandef_vht_oper(*(_QWORD *)(a1 + 1616), v51) & 1) == 0 )
          {
            v35 = &unk_BA862;
LABEL_54:
            printk(v35, a1 + 1640, v28, v29);
            result = 2;
            goto LABEL_22;
          }
          goto LABEL_36;
        }
      }
      else if ( *(_DWORD *)(v15 + 16) == 1 )
      {
        v35 = &unk_BA5D1;
        goto LABEL_54;
      }
      v36 = 2;
LABEL_37:
      if ( !cfg80211_chandef_compatible(a7, &v57) )
      {
        v35 = &unk_BCAFB;
        goto LABEL_54;
      }
      v43 = v58;
      *a7 = v57;
      a7[1] = v43;
      v44 = v60;
      a7[2] = v59;
      a7[3] = v44;
      if ( *a6 >= 4u )
      {
        result = v36;
        if ( a4[22] )
        {
          if ( a4[21] )
          {
            result = 4;
            if ( *a6 != 4 && v13 && a4[54] )
            {
              if ( (*v13 & 1) != 0 )
              {
                v53 = v57;
                v54 = v58;
                v55 = v59;
                v56 = v60;
                ieee80211_chandef_eht_oper(v13 + 5, &v53);
                if ( (~*v13 & 3) != 0 )
                  v45 = 0;
                else
                  v45 = *((_WORD *)v13 + 4);
                HIWORD(v56) = v45;
                if ( (cfg80211_chandef_valid(&v53) & 1) != 0 )
                {
                  if ( cfg80211_chandef_compatible(a7, &v53) )
                  {
                    v48 = v54;
                    result = 5;
                    *a7 = v53;
                    a7[1] = v48;
                    v49 = v56;
                    a7[2] = v55;
                    a7[3] = v49;
                    goto LABEL_22;
                  }
                  v50 = &unk_B89CF;
                }
                else
                {
                  v50 = &unk_BB97D;
                }
                printk(v50, a1 + 1640, v46, v47);
                result = 4;
                goto LABEL_22;
              }
              result = 5;
            }
          }
        }
      }
      else
      {
        result = v36;
      }
      goto LABEL_22;
    }
    v39 = *(_BYTE *)(v11 + 8);
    v40 = *(_QWORD *)(a1 + 1616);
    LOWORD(v53) = *(_WORD *)(v11 + 6);
    BYTE2(v53) = v39;
    *(_WORD *)((char *)&v53 + 3) = 0;
    if ( (ieee80211_chandef_vht_oper(v40, v51) & 1) == 0 )
    {
      printk(&unk_BAC48, a1 + 1640, v41, v42);
      result = 3;
      goto LABEL_22;
    }
LABEL_36:
    v36 = 3;
    goto LABEL_37;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
