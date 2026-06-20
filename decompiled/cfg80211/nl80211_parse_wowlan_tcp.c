__int64 __fastcall nl80211_parse_wowlan_tcp(unsigned __int64 a1, _WORD *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  unsigned __int64 v5; // x24
  __int64 result; // x0
  __int64 v8; // x8
  size_t v9; // x21
  size_t v10; // x20
  size_t v11; // x19
  unsigned int v12; // w10
  unsigned int v13; // w26
  unsigned int *v14; // x11
  _QWORD *v15; // x27
  int v16; // w8
  __int64 *v17; // x28
  unsigned __int64 v18; // x23
  __int64 v19; // x22
  __int64 v20; // x10
  unsigned __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w24
  unsigned int v24; // w0
  unsigned int v25; // w19
  int port; // w8
  __int64 v27; // x0
  __int64 v28; // x9
  __int16 v29; // w9
  size_t v30; // x1
  __int64 v31; // x9
  size_t v32; // x1
  size_t v33; // x1
  unsigned __int64 v34; // x1
  size_t n; // [xsp+8h] [xbp-78h]
  unsigned __int64 v36; // [xsp+10h] [xbp-70h]
  __int64 v37; // [xsp+10h] [xbp-70h]
  __int64 v38; // [xsp+18h] [xbp-68h] BYREF
  __int64 v39; // [xsp+20h] [xbp-60h]
  __int64 v40; // [xsp+28h] [xbp-58h]
  __int64 v41; // [xsp+30h] [xbp-50h]
  __int64 v42; // [xsp+38h] [xbp-48h]
  __int64 v43; // [xsp+40h] [xbp-40h]
  _WORD *v44; // [xsp+48h] [xbp-38h]
  __int64 v45; // [xsp+50h] [xbp-30h]
  __int64 v46; // [xsp+58h] [xbp-28h]
  __int64 v47; // [xsp+60h] [xbp-20h]
  _WORD *v48; // [xsp+68h] [xbp-18h]
  _WORD *v49; // [xsp+70h] [xbp-10h]
  __int64 v50; // [xsp+78h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 1240);
  v48 = nullptr;
  v49 = nullptr;
  v46 = 0;
  v47 = 0;
  v44 = nullptr;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v4 = *(_QWORD *)(v3 + 24);
  v38 = 0;
  v39 = 0;
  if ( !v4 )
  {
    result = 4294967274LL;
    goto LABEL_25;
  }
  v5 = a1;
  result = _nla_parse(&v38, 11, a2 + 2, (unsigned __int16)(*a2 - 4), &nl80211_wowlan_tcp_policy, 0, 0);
  if ( !(_DWORD)result )
  {
    result = 4294967274LL;
    if ( v39 )
    {
      if ( v40 )
      {
        if ( v41 )
        {
          if ( v43 )
          {
            if ( v44 )
            {
              if ( v47 )
              {
                if ( v48 )
                {
                  if ( v49 )
                  {
                    v8 = *(_QWORD *)(*(_QWORD *)(v5 + 1240) + 24LL);
                    v9 = (unsigned __int16)(*v44 - 4);
                    if ( *(_DWORD *)(v8 + 8) >= (unsigned int)v9
                      && (unsigned int)(*(_DWORD *)(v47 + 4) - 1) < *(_DWORD *)(v8 + 12) )
                    {
                      v10 = (unsigned __int16)(*v48 - 4);
                      if ( *(_DWORD *)(v8 + 16) >= (unsigned int)v10 )
                      {
                        v11 = (unsigned __int16)(*v49 - 4);
                        if ( (_DWORD)v11 == (unsigned int)(v10 + 7) >> 3 )
                        {
                          if ( v46 )
                          {
                            v12 = *(_DWORD *)(v46 + 8);
                            if ( !v12 )
                              goto LABEL_25;
                            v13 = (unsigned __int16)(*(_WORD *)v46 - 4) - 8;
                            if ( v13 % v12 )
                              goto LABEL_25;
                            v14 = *(unsigned int **)v8;
                            if ( !*(_QWORD *)v8 )
                              goto LABEL_25;
                            if ( v12 > v14[1] )
                              goto LABEL_25;
                            if ( v12 < *v14 )
                              goto LABEL_25;
                            if ( v13 > v14[2] )
                              goto LABEL_25;
                            v15 = (_QWORD *)(v46 + 4);
                            if ( *(_DWORD *)(v46 + 4) + v12 > (unsigned int)v9 )
                              goto LABEL_25;
                          }
                          else
                          {
                            v13 = 0;
                            v15 = nullptr;
                          }
                          if ( v45 )
                          {
                            if ( *(_BYTE *)(v8 + 20) != 1 )
                              goto LABEL_25;
                            v16 = *(_DWORD *)(v45 + 12);
                            if ( (unsigned int)(v16 - 5) < 0xFFFFFFFC || *(_DWORD *)(v45 + 8) + v16 > (unsigned int)v9 )
                              goto LABEL_25;
                            v17 = (__int64 *)(v45 + 4);
                          }
                          else
                          {
                            v17 = nullptr;
                          }
                          v18 = (_DWORD)v9 + (_DWORD)v10 + (unsigned int)v11 + v13 + 96;
                          v19 = _kmalloc_noprof(v18, 3520);
                          if ( !v19 )
                          {
LABEL_68:
                            result = 4294967284LL;
                            goto LABEL_25;
                          }
                          while ( 1 )
                          {
                            v20 = v40;
                            v21 = v5;
                            *(_DWORD *)(v19 + 8) = *(_DWORD *)(v39 + 4);
                            *(_DWORD *)(v19 + 12) = *(_DWORD *)(v20 + 4);
                            v22 = v42;
                            LOWORD(v20) = *(_WORD *)(v41 + 8);
                            *(_DWORD *)(v19 + 20) = *(_DWORD *)(v41 + 4);
                            *(_WORD *)(v19 + 24) = v20;
                            if ( v22 )
                              v23 = *(unsigned __int16 *)(v22 + 4);
                            else
                              v23 = 0;
                            v24 = _sock_create(*(_QWORD *)(v21 + 2344), 2, 1, 6, v19, 1);
                            if ( v24 )
                            {
                              v25 = v24;
                              kfree(v19);
                              result = v25;
                              goto LABEL_25;
                            }
                            port = inet_csk_get_port(*(_QWORD *)(*(_QWORD *)v19 + 24LL), v23);
                            v27 = *(_QWORD *)v19;
                            if ( port )
                            {
                              sock_release(v27);
                              kfree(v19);
                              result = 4294967198LL;
                              goto LABEL_25;
                            }
                            v28 = v43;
                            v5 = v13 + 96LL;
                            *(_WORD *)(v19 + 16) = *(_WORD *)(*(_QWORD *)(v27 + 24) + 14LL);
                            v29 = *(_WORD *)(v28 + 4);
                            v30 = v18 >= v5 ? v18 - v5 : 0LL;
                            *(_DWORD *)(v19 + 28) = v9;
                            *(_WORD *)(v19 + 18) = v29;
                            v36 = v5 + v19;
                            *(_QWORD *)(v19 + 32) = v5 + v19;
                            if ( v30 < v9 )
                              break;
                            memcpy(*(void **)(v19 + 32), v44 + 2, v9);
                            if ( v17 )
                            {
                              v31 = *v17;
                              *(_DWORD *)(v19 + 48) = *((_DWORD *)v17 + 2);
                              *(_QWORD *)(v19 + 40) = v31;
                            }
                            v5 += v9;
                            if ( v18 >= v5 )
                              v32 = v18 - v5;
                            else
                              v32 = 0;
                            *(_DWORD *)(v19 + 52) = *(_DWORD *)(v47 + 4);
                            *(_DWORD *)(v19 + 56) = v10;
                            v9 += v36;
                            *(_QWORD *)(v19 + 64) = v9;
                            if ( v32 < v10 )
                              goto LABEL_64;
                            memcpy(*(void **)(v19 + 64), v48 + 2, v10);
                            if ( v18 >= v5 + v10 )
                              v33 = v18 - (v5 + v10);
                            else
                              v33 = 0;
                            *(_QWORD *)(v19 + 72) = v9 + v10;
                            if ( v33 < v11 )
                              goto LABEL_65;
                            memcpy(*(void **)(v19 + 72), v49 + 2, v11);
                            if ( !v15 )
                              goto LABEL_62;
                            *(_DWORD *)(v19 + 80) = v13;
                            if ( v18 - 84 < 8 )
                              goto LABEL_66;
                            if ( v18 >= 0x5C )
                              v34 = v18 - 92;
                            else
                              v34 = 0;
                            *(_QWORD *)(v19 + 84) = *v15;
                            if ( v34 >= v13 )
                            {
                              memcpy((void *)(v19 + 92), v15 + 1, v13);
LABEL_62:
                              result = 0;
                              *(_QWORD *)(a3 + 16) = v19;
                              goto LABEL_25;
                            }
LABEL_67:
                            _fortify_panic(17, v34);
                            n = _ReadStatusReg(SP_EL0);
                            v37 = *(_QWORD *)(n + 80);
                            *(_QWORD *)(n + 80) = &nl80211_parse_wowlan_tcp__alloc_tag;
                            v19 = _kmalloc_noprof(v18, 3520);
                            *(_QWORD *)(n + 80) = v37;
                            if ( !v19 )
                              goto LABEL_68;
                          }
                          _fortify_panic(17, v30);
LABEL_64:
                          _fortify_panic(17, v32);
LABEL_65:
                          _fortify_panic(17, v33);
LABEL_66:
                          __break(1u);
                          goto LABEL_67;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
