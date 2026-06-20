_QWORD *__fastcall ieee80211_process_tdls_channel_switch(_QWORD *result, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x21
  int v5; // w8
  unsigned int v6; // w8
  int v7; // w10
  unsigned __int8 *v8; // x22
  int v9; // w8
  __int64 v10; // x0
  int v11; // w9
  bool v12; // zf
  bool v13; // zf
  bool v14; // zf
  bool v15; // cc
  _BOOL8 v16; // x1
  int v17; // w8
  _QWORD *v18; // x21
  unsigned __int8 *v19; // x8
  _QWORD *v20; // x20
  int v21; // w8
  unsigned int v22; // w9
  __int64 v23; // x2
  unsigned int v24; // w8
  int v25; // w10
  __int64 v26; // x22
  unsigned __int64 v27; // x0
  int v28; // w9
  unsigned __int64 v29; // x0
  int v30; // w8
  unsigned __int64 v31; // x21
  _QWORD *v32; // x0
  __int64 v33; // x8
  int v34; // w10
  int v35; // w8
  bool v36; // zf
  int v37; // w9
  __int64 v38; // x9
  unsigned int v39; // w8
  __int64 v40; // x0
  char v41; // w8
  __int64 v42; // x9
  int v43; // w10
  int v44; // w9
  bool v45; // zf
  int v46; // w10
  _BYTE *v47; // x9
  int *v48; // x8
  _QWORD v49[4]; // [xsp+8h] [xbp-98h] BYREF
  unsigned __int64 v50; // [xsp+28h] [xbp-78h] BYREF
  _QWORD *v51; // [xsp+30h] [xbp-70h]
  __int64 v52; // [xsp+38h] [xbp-68h]
  int v53; // [xsp+40h] [xbp-60h]
  int v54; // [xsp+44h] [xbp-5Ch]
  __int64 v55; // [xsp+48h] [xbp-58h]
  __int64 v56; // [xsp+50h] [xbp-50h] BYREF
  __int64 v57; // [xsp+58h] [xbp-48h] BYREF
  unsigned __int8 *v58; // [xsp+60h] [xbp-40h]
  __int64 v59; // [xsp+68h] [xbp-38h]
  __int64 v60; // [xsp+70h] [xbp-30h]
  __int64 v61; // [xsp+78h] [xbp-28h]
  __int64 v62; // [xsp+80h] [xbp-20h]
  __int64 v63; // [xsp+88h] [xbp-18h]
  __int64 v64; // [xsp+90h] [xbp-10h]
  __int64 v65; // [xsp+98h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(*(_QWORD *)(result[202] + 72LL) + 111LL) & 0x10) != 0 )
  {
    v3 = (__int64)result;
    v4 = *(_QWORD *)(a2 + 224);
    if ( !*(_DWORD *)(a2 + 116) || (result = (_QWORD *)_pskb_pull_tail(a2)) != nullptr )
    {
      v5 = *(unsigned __int8 *)(v4 + 16);
      if ( v5 == 6 )
      {
        v24 = *(_DWORD *)(a2 + 112);
        v25 = *(_DWORD *)(a2 + 56);
        v26 = *(_QWORD *)(a2 + 224);
        v54 = 0;
        v55 = 0;
        v56 = 0;
        v50 = 0;
        v51 = nullptr;
        v52 = 6;
        v53 = v25;
        if ( v24 >= 0x13 )
        {
          v27 = sta_info_get(v3, (const void *)(v26 + 6));
          if ( !v27 || (*(_QWORD *)(v27 + 216) & 0x1000) == 0 )
          {
            v20 = nullptr;
LABEL_43:
            v29 = v55;
            goto LABEL_44;
          }
          v28 = *(unsigned __int16 *)(v26 + 17);
          v50 = v27 + 2688;
          HIDWORD(v52) = v28;
          if ( v28 )
          {
            v20 = nullptr;
          }
          else
          {
            v30 = *(_DWORD *)(a2 + 112);
            v31 = v27;
            v61 = 0;
            v62 = 0;
            v57 = 5;
            v58 = (unsigned __int8 *)(v26 + 19);
            v59 = (unsigned int)(v30 - 19);
            v60 = 0;
            v63 = 0;
            v64 = 0xFFFFFFFFLL;
            v32 = ieee802_11_parse_elems_full((int *)&v57);
            v20 = v32;
            if ( !v32 )
              goto LABEL_43;
            if ( *((_BYTE *)v32 + 760) )
              goto LABEL_43;
            if ( !v32[4] )
              goto LABEL_43;
            v33 = v32[3];
            if ( !v33 )
              goto LABEL_43;
            v34 = *(_DWORD *)(v33 + 8);
            v35 = *(unsigned __int16 *)(v33 + 12);
            v36 = v34 == *(_DWORD *)(v3 + 5842) && v35 == *(unsigned __int16 *)(v3 + 5846);
            v37 = v36;
            if ( *(unsigned __int8 *)(v31 + 2713) == v37 )
              goto LABEL_43;
            v54 = *(_DWORD *)v32[4];
            v55 = ieee80211_tdls_ch_sw_resp_tmpl_get(v31, &v56);
            if ( !v55 )
              goto LABEL_43;
          }
LABEL_42:
          drv_tdls_recv_channel_switch(*(_QWORD *)(v3 + 1616), v3, &v50);
          goto LABEL_43;
        }
      }
      else if ( v5 == 5 )
      {
        v6 = *(_DWORD *)(a2 + 112);
        v7 = *(_DWORD *)(a2 + 56);
        v8 = *(unsigned __int8 **)(a2 + 224);
        v54 = 0;
        v55 = 0;
        v56 = 0;
        v50 = 0;
        v51 = nullptr;
        v52 = 5;
        v53 = v7;
        if ( v6 >= 0x13 )
        {
          v9 = v8[18];
          v10 = v8[17];
          memset(v49, 0, sizeof(v49));
          v11 = v9 & 0xFE;
          v12 = v9 == 112 || v11 == 2;
          v13 = v12 || v11 == 4;
          v14 = v13 || v9 == 6;
          v15 = v14 || (unsigned int)v10 > 0xD;
          v16 = v15;
          result = (_QWORD *)ieee80211_channel_to_freq_khz(v10, v16);
          if ( (unsigned int)result >= 0x3E8 )
          {
            result = (_QWORD *)ieee80211_get_channel_khz(
                                 *(_QWORD *)(*(_QWORD *)(v3 + 1616) + 72LL),
                                 1000 * ((unsigned int)result / 0x3E8));
            if ( result )
            {
              v17 = *(_DWORD *)(a2 + 112);
              v18 = result;
              v61 = 0;
              v62 = 0;
              v57 = 5;
              v58 = v8 + 19;
              v59 = (unsigned int)(v17 - 19);
              v60 = 0;
              v63 = 0;
              v64 = 0xFFFFFFFFLL;
              result = ieee802_11_parse_elems_full((int *)&v57);
              if ( result )
              {
                if ( *((_BYTE *)result + 760) || !result[4] || !result[3] )
                  goto LABEL_45;
                v19 = (unsigned __int8 *)result[43];
                v20 = result;
                if ( v19 )
                {
                  v21 = *v19;
                  v22 = v21 == 3 ? 2 : 1;
                  v23 = v21 == 1 ? 3LL : v22;
                }
                else
                {
                  v23 = 1;
                }
                cfg80211_chandef_create(v49, v18, v23);
                v38 = *(_QWORD *)(v3 + 1616);
                v39 = *(_DWORD *)(v3 + 24);
                LOBYTE(v58) = 1;
                v40 = *(_QWORD *)(v38 + 72);
                v57 = v39;
                *(_WORD *)((char *)&v58 + 1) = 0;
                BYTE3(v58) = 0;
                v41 = cfg80211_reg_check_beaconing(v40, v49, &v57);
                result = v20;
                if ( (v41 & 1) == 0 )
                  goto LABEL_45;
                v29 = sta_info_get(v3, v8 + 6);
                if ( !v29 )
                {
LABEL_44:
                  dev_kfree_skb_any_reason(v29, 2);
                  result = v20;
LABEL_45:
                  result = (_QWORD *)kfree(result);
                  goto LABEL_46;
                }
                if ( (*(_QWORD *)(v29 + 216) & 0x1000) == 0
                  || ((v42 = v20[3],
                       v50 = v29 + 2688,
                       v43 = *(_DWORD *)(v42 + 8),
                       v44 = *(unsigned __int16 *)(v42 + 12),
                       v43 == *(_DWORD *)(v3 + 5842))
                    ? (v45 = v44 == *(unsigned __int16 *)(v3 + 5846))
                    : (v45 = 0),
                      !v45 ? (v46 = 0) : (v46 = 1),
                      *(unsigned __int8 *)(v29 + 2713) == v46
                   || (*(_BYTE *)(v29 + 2926) & 1) == 0 && (v47 = (_BYTE *)v20[43]) != nullptr && *v47) )
                {
                  v29 = 0;
                  goto LABEL_44;
                }
                v48 = (int *)v20[4];
                v51 = v49;
                v54 = *v48;
                v29 = ieee80211_tdls_ch_sw_resp_tmpl_get(v29, &v56);
                v55 = v29;
                if ( !v29 )
                  goto LABEL_44;
                goto LABEL_42;
              }
            }
          }
        }
      }
      else
      {
        __break(0x800u);
      }
    }
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
