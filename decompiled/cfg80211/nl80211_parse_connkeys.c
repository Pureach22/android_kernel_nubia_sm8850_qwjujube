__int64 __fastcall nl80211_parse_connkeys(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x21
  __int16 *v4; // x20
  __int64 v5; // x8
  unsigned int v6; // w8
  __int64 v11; // x0
  __int16 v12; // w8
  int v13; // w25
  int v14; // w27
  __int64 v15; // x26
  unsigned int v16; // w8
  int v17; // w0
  __int64 v18; // x2
  __int64 v19; // x0
  int v20; // w9
  __int64 v21; // x8
  unsigned __int64 v22; // x1
  unsigned int v23; // w9
  size_t v24; // x2
  __int64 v25; // x10
  __int64 v26; // x8
  const char **v27; // x20
  const char *v28; // x19
  __int64 v29; // x19
  int v30; // w8
  unsigned __int64 StatusReg; // x24
  __int64 v32; // x25
  __int64 v33; // x0
  void *src; // [xsp+0h] [xbp-40h] BYREF
  __int64 v35; // [xsp+8h] [xbp-38h]
  size_t n; // [xsp+10h] [xbp-30h]
  __int64 v37; // [xsp+18h] [xbp-28h]
  __int64 v38; // [xsp+20h] [xbp-20h]
  __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 648LL);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  n = 0;
  src = nullptr;
  v4 = (__int16 *)(v3 + 4);
  v5 = 0;
  if ( (unsigned __int16)(*(_WORD *)v3 - 4) >= 4u )
  {
    v6 = (unsigned __int16)*v4;
    if ( v6 >= 4 && v6 <= (unsigned __int16)(*(_WORD *)v3 - 4) )
    {
      v11 = _kmalloc_cache_noprof(register_pernet_device, 3520, 216);
      if ( !v11 )
        goto LABEL_45;
      while ( 1 )
      {
        *(_DWORD *)(v11 + 212) = -1;
        v12 = *(_WORD *)v3;
        v3 = v11;
        v13 = (unsigned __int16)(v12 - 4);
        if ( (unsigned int)v13 < 4 )
          break;
        v14 = 0;
        v15 = v11 + 160;
        while ( 1 )
        {
          v16 = (unsigned __int16)*v4;
          if ( v16 < 4 || v13 < v16 )
          {
LABEL_28:
            if ( (*(_DWORD *)(v3 + 212) & 0x80000000) != 0 )
              goto LABEL_30;
            v5 = v3;
            goto LABEL_5;
          }
          v40 = 0;
          v37 = 0;
          v38 = 0;
          v35 = 0;
          n = 0;
          src = nullptr;
          v39 = 0xFFFFFFFFLL;
          v17 = nl80211_parse_key_new(a2, v4, (__int64)&src);
          if ( v17 )
            goto LABEL_34;
          if ( !src )
          {
            v30 = -22;
LABEL_37:
            v19 = v3;
LABEL_38:
            v29 = v30;
            goto LABEL_39;
          }
          v18 = (unsigned int)v39;
          if ( (unsigned int)v39 >= 4 )
          {
            v27 = *(const char ***)(a2 + 64);
            v28 = "key index out of range [0-3]";
            goto LABEL_31;
          }
          v19 = v3;
          if ( (unsigned __int8)v40 == 1 )
          {
            if ( v14 )
            {
              v27 = *(const char ***)(a2 + 64);
              v28 = "only one key can be default";
              goto LABEL_31;
            }
            v20 = BYTE3(v40);
            *(_DWORD *)(v3 + 212) = v39;
            if ( v20 != 1 || (v40 & 0x100000000LL) == 0 )
            {
LABEL_35:
              v30 = -22;
              goto LABEL_38;
            }
            v21 = a1;
            v14 = 1;
          }
          else
          {
            v21 = a1;
            if ( (v40 & 0x100) != 0 )
              goto LABEL_35;
          }
          v17 = cfg80211_validate_key_settings(v21, &src, v18, 0, 0);
          if ( v17 )
          {
LABEL_34:
            v30 = v17;
            goto LABEL_37;
          }
          if ( (HIDWORD(v37) & 0xFFFFFFFB) != 0xFAC01 )
          {
            v27 = *(const char ***)(a2 + 64);
            v28 = "connect key must be WEP";
            goto LABEL_31;
          }
          v23 = v39;
          if ( (unsigned int)v39 >= 4 )
            break;
          v24 = (int)n;
          v25 = v3 + 40LL * (unsigned int)v39;
          *(_DWORD *)(v25 + 28) = HIDWORD(v37);
          v22 = 216LL - (13 * v23 + 160);
          *(_DWORD *)(v25 + 16) = v24;
          *(_QWORD *)v25 = v15 + 13LL * v23;
          if ( v22 < v24 )
            goto LABEL_44;
          if ( (unsigned int)v39 > 4 )
            break;
          memcpy((void *)(v15 + 13LL * (unsigned int)v39), src, v24);
          if ( a3 )
            *a3 = 1;
          v26 = ((unsigned __int16)*v4 + 3) & 0x1FFFC;
          v13 -= v26;
          v4 = (__int16 *)((char *)v4 + v26);
          if ( v13 <= 3 )
            goto LABEL_28;
        }
        __break(0x5512u);
LABEL_44:
        _fortify_panic(17, v22);
        StatusReg = _ReadStatusReg(SP_EL0);
        v32 = *(_QWORD *)(StatusReg + 80);
        v33 = register_pernet_device;
        *(_QWORD *)(StatusReg + 80) = &nl80211_parse_connkeys__alloc_tag;
        v11 = _kmalloc_cache_noprof(v33, 3520, 216);
        *(_QWORD *)(StatusReg + 80) = v32;
        if ( !v11 )
        {
LABEL_45:
          v5 = -12;
          goto LABEL_5;
        }
      }
LABEL_30:
      v27 = *(const char ***)(a2 + 64);
      v28 = "need a default/TX key";
LABEL_31:
      do_trace_netlink_extack(v28);
      if ( v27 )
        *v27 = v28;
      v29 = -22;
      v19 = v3;
LABEL_39:
      kfree(v19);
      v5 = v29;
    }
    else
    {
      v5 = 0;
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v5;
}
