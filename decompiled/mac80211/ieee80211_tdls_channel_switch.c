__int64 __fastcall ieee80211_tdls_channel_switch(__int64 a1, __int64 a2, const void *a3, unsigned int a4, _DWORD *a5)
{
  __int64 result; // x0
  __int64 v6; // x19
  unsigned __int64 v10; // x0
  unsigned int v11; // w19
  unsigned int v12; // w8
  int v13; // w9
  char *v14; // x10
  __int64 v15; // x22
  char v16; // w8
  __int64 v17; // x9
  unsigned int v18; // w11
  char v19; // w9
  __int64 v20; // x9
  char v21; // w13
  unsigned __int64 v22; // x24
  __int64 v23; // x0
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x22
  __int64 v26; // x10
  __int64 v27; // x1
  __int64 elem_match; // x0
  int v29; // w25
  int v30; // w10
  __int64 v31; // x8
  __int64 v32; // x6
  _DWORD *v33; // x10
  unsigned int v34; // w0
  __int64 v35; // x11
  __int64 v36; // x1
  unsigned __int64 v43; // x9
  int v44; // [xsp+24h] [xbp-1Ch]
  __int64 v45; // [xsp+28h] [xbp-18h] BYREF
  char v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_WORD *)(*(_QWORD *)a5 + 8LL) )
  {
    v6 = *(_QWORD *)(a2 + 4304);
    v10 = sta_info_get(a2 + 2688, a3);
    if ( v10 )
    {
      if ( (*(_QWORD *)(v10 + 216) & 0x4000) == 0 )
      {
        v10 = 0;
        v11 = -95;
LABEL_24:
        dev_kfree_skb_any_reason(v10, 2);
        result = v11;
        goto LABEL_25;
      }
      v12 = *(unsigned __int16 *)(v10 + 2872);
      v13 = a5[2];
      v14 = (char *)&v45;
      v15 = *(_QWORD *)(v10 + 80);
      v46 = 0;
      v45 = 0;
      v16 = __clz(__rbit32(v12));
      if ( v13 == 2 )
      {
        v17 = *(_QWORD *)a5;
        v18 = a5[3];
        v14 = (char *)&v45 + 3;
        LOWORD(v45) = 318;
        if ( v18 > *(_DWORD *)(v17 + 4) )
          v19 = 1;
        else
          v19 = 3;
        BYTE2(v45) = v19;
        v20 = 9;
      }
      else
      {
        v20 = 6;
      }
      *(_DWORD *)(v14 + 2) = 0;
      v21 = *(_BYTE *)(v10 + 2713);
      *(_WORD *)v14 = 1128;
      v22 = v10;
      v23 = ieee80211_tdls_build_mgmt_packet_data(
              v15,
              v10 + 2688,
              v16 & 0x1F,
              5,
              0,
              0,
              (v21 & 1) == 0,
              &v45,
              v20,
              (_BYTE)a4,
              a5);
      if ( v23 )
      {
        v24 = ieee80211_build_data_template(v15, v23, 0);
        if ( v24 <= 0xFFFFFFFFFFFFF000LL )
        {
          v25 = v24;
          v26 = *(_QWORD *)(v24 + 224);
          v27 = v26 + *(_DWORD *)(v24 + 216) + *(unsigned __int16 *)(v24 + 184) - (int)v26 + 5;
          elem_match = cfg80211_find_elem_match(104, v27, (unsigned int)(*(_DWORD *)(v24 + 112) + v26 - v27), 0, 0, 0);
          if ( elem_match )
          {
            v29 = elem_match;
            v10 = v25;
            if ( v25 )
            {
              v30 = *(_DWORD *)(v25 + 224);
              v31 = a2;
              if ( (*(_BYTE *)(*(_QWORD *)(a2 + 4304) + 1471LL) & 1) == 0
                && (*(_DWORD *)(a2 + 4312) & 0x20) == 0
                && (drv_tdls_channel_switch___already_done & 1) == 0 )
              {
                v35 = *(_QWORD *)(a2 + 4296);
                drv_tdls_channel_switch___already_done = 1;
                if ( v35 )
                  v36 = v35 + 296;
                else
                  v36 = a2 + 4328;
                v44 = v30;
                _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v36);
                v30 = v44;
                v31 = a2;
                v10 = v25;
                __break(0x800u);
              }
              if ( (*(_BYTE *)(v31 + 4312) & 0x20) != 0 )
              {
                if ( *(_QWORD *)(*(_QWORD *)(v6 + 464) + 728LL) )
                {
                  v32 = (unsigned int)(v29 - v30);
                  v33 = *(_DWORD **)(*(_QWORD *)(v6 + 464) + 728LL);
                  if ( *(v33 - 1) != 1760229504 )
                    __break(0x822Au);
                  v34 = ((__int64 (__fastcall *)(__int64, __int64, unsigned __int64, _QWORD, _DWORD *, unsigned __int64, __int64))v33)(
                          v6,
                          v31 + 7408,
                          v22 + 2688,
                          a4,
                          a5,
                          v25,
                          v32);
                  if ( v34 )
                  {
                    v11 = v34;
                    v10 = v25;
                  }
                  else
                  {
                    v10 = v25;
                    _X8 = (unsigned __int64 *)(v22 + 216);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v43 = __ldxr(_X8);
                    while ( __stxr(v43 | 0x8000, _X8) );
                    v11 = 0;
                  }
                }
                else
                {
                  v11 = -95;
                }
              }
              else
              {
                v11 = -5;
              }
              goto LABEL_24;
            }
            goto LABEL_23;
          }
          dev_kfree_skb_any_reason(v25, 2);
        }
      }
      v10 = 0;
    }
LABEL_23:
    v11 = -2;
    goto LABEL_24;
  }
  result = 4294967201LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
