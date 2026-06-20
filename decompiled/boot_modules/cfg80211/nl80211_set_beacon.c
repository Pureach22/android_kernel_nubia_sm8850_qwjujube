__int64 __fastcall nl80211_set_beacon(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x22
  __int64 v3; // x24
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x23
  int v9; // w9
  bool v10; // zf
  _QWORD *v11; // x21
  int v12; // w0
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 result; // x0
  unsigned int v20; // w19
  unsigned __int64 StatusReg; // x25
  __int64 v22; // x26
  __int64 v23; // x0
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2[4];
  v25 = 0;
  v5 = a2[6];
  v24 = 0;
  v6 = *(_QWORD *)(v4 + 2504);
  if ( v6 )
    LODWORD(v6) = *(unsigned __int8 *)(v6 + 4);
  v7 = a2[7];
  v8 = *(_QWORD *)(v7 + 992);
  v9 = *(_DWORD *)(v8 + 8);
  v10 = v9 == 3 || v9 == 9;
  if ( v10 && *(_QWORD *)(*(_QWORD *)v5 + 120LL) )
  {
    if ( (unsigned int)v6 > 0xE )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v22 = *(_QWORD *)(StatusReg + 80);
      v23 = register_pernet_device;
      *(_QWORD *)(StatusReg + 80) = &nl80211_set_beacon__alloc_tag;
      v11 = (_QWORD *)_kmalloc_cache_noprof(v23, 3520, 240);
      *(_QWORD *)(StatusReg + 80) = v22;
      if ( v11 )
      {
LABEL_12:
        v12 = nl80211_parse_beacon(v5, v2[4], v11, v2[8]);
        if ( !v12 )
        {
          v13 = *(_DWORD *)(v8 + 8);
          v14 = v11[2];
          v15 = v11[13];
          LOBYTE(v25) = 1;
          LODWORD(v24) = v13;
          HIDWORD(v24) = cfg80211_get_6ghz_power_type(v14, v15);
          if ( (cfg80211_reg_check_beaconing(v5 + 992, v3 + 408, (unsigned int *)&v24) & 1) != 0 )
          {
            v16 = v2[4];
            v17 = *(_QWORD *)(v16 + 2352);
            if ( !v17 )
            {
LABEL_17:
              v18 = *(_QWORD *)(v16 + 2360);
              if ( !v18 || (v12 = nl80211_parse_unsol_bcast_probe_resp(v5, v18, v11 + 26)) == 0 )
                v12 = rdev_change_beacon(v5, v7, v11);
              goto LABEL_23;
            }
            v12 = nl80211_parse_fils_discovery(v5, v17, v11 + 22);
            if ( !v12 )
            {
              v16 = v2[4];
              goto LABEL_17;
            }
          }
          else
          {
            v12 = -22;
          }
        }
LABEL_23:
        v20 = v12;
        kfree(v11[9]);
        kfree(v11[10]);
        kfree(v11);
        result = v20;
        goto LABEL_26;
      }
LABEL_25:
      result = 4294967284LL;
      goto LABEL_26;
    }
    v3 = v8 + 72LL * (unsigned int)v6;
    if ( *(_DWORD *)(v3 + 400) )
    {
      v2 = a2;
      v11 = (_QWORD *)_kmalloc_cache_noprof(register_pernet_device, 3520, 240);
      if ( v11 )
        goto LABEL_12;
      goto LABEL_25;
    }
    result = 4294967274LL;
  }
  else
  {
    result = 4294967201LL;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
