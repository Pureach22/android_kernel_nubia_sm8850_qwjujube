__int64 __fastcall nl80211_set_qos_map(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x22
  __int64 v3; // x19
  _WORD *v4; // x20
  __int64 *v5; // x20
  size_t v6; // x21
  __int16 v7; // t1
  __int64 v8; // x0
  unsigned int v9; // w8
  unsigned int v10; // w23
  _BYTE *v11; // x24
  unsigned int v12; // w25
  __int64 v13; // x9
  __int64 v14; // x9
  unsigned int v15; // w20
  __int64 v16; // x8
  unsigned int v17; // w9
  __int64 v18; // x21
  __int64 (__fastcall *v19)(__int64, __int64, __int64); // x8
  unsigned __int64 StatusReg; // x23
  __int64 v21; // x24
  int (*v22)(timer_t); // x0
  __int64 v24; // [xsp+8h] [xbp-8h]
  unsigned int v25; // [xsp+28h] [xbp+18h]

  v2 = a2[6];
  if ( *(_QWORD *)(*(_QWORD *)v2 + 736LL) )
  {
    v3 = a2[7];
    v4 = *(_WORD **)(a2[4] + 1592LL);
    if ( v4 )
    {
      v7 = *v4;
      v5 = (__int64 *)(v4 + 2);
      LOBYTE(v6) = v7;
      if ( (v7 & 1) != 0 )
        return (unsigned int)-22;
      v8 = _kmalloc_cache_noprof(timer_delete, 3520, 59);
      if ( !v8 )
        return (unsigned int)-12;
      while ( 1 )
      {
        v9 = (((_BYTE)v6 - 4) & 0xFE) + 496;
        v10 = (unsigned __int8)(v9 >> 1);
        if ( !(unsigned __int8)(v9 >> 1) )
          break;
        v6 = (unsigned __int8)(((v6 - 4) & 0xFE) - 16) & 0xFE;
        if ( (v9 & 0xFE) < 0x3B )
        {
          if ( (unsigned int)v6 >= 0x2B && (nl80211_set_qos_map___already_done & 1) == 0 )
          {
            v25 = v9;
            v24 = v8;
            nl80211_set_qos_map___already_done = 1;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v6,
              "field \"qos_map->dscp_exception\" at ../soc-repo/net/wireless/nl80211.c:15542",
              0x2Au);
            v9 = v25;
            v8 = v24;
            __break(0x800u);
          }
          v11 = (_BYTE *)v8;
          v12 = v9 >> 1;
          memcpy((void *)(v8 + 1), v5, v6);
          v8 = (__int64)v11;
          *v11 = v12;
          if ( !v10 )
          {
LABEL_15:
            v5 = (__int64 *)((char *)v5 + v6);
            break;
          }
          v13 = 0;
          while ( v13 != 42 )
          {
            if ( (unsigned __int8)v11[v13 + 2] >= 8u )
            {
              kfree(v11);
              return (unsigned int)-22;
            }
            v13 += 2;
            if ( 2LL * v10 == v13 )
              goto LABEL_15;
          }
          __break(0x5512u);
        }
        _fortify_panic(17, 58);
        StatusReg = _ReadStatusReg(SP_EL0);
        v21 = *(_QWORD *)(StatusReg + 80);
        v22 = timer_delete;
        *(_QWORD *)(StatusReg + 80) = &nl80211_set_qos_map__alloc_tag;
        v8 = _kmalloc_cache_noprof(v22, 3520, 59);
        *(_QWORD *)(StatusReg + 80) = v21;
        if ( !v8 )
          return (unsigned int)-12;
      }
      v14 = *v5;
      *(_QWORD *)(v8 + 51) = v5[1];
      *(_QWORD *)(v8 + 43) = v14;
    }
    else
    {
      v8 = 0;
    }
    v16 = *(_QWORD *)(v3 + 992);
    v15 = -22;
    v17 = *(_DWORD *)(v16 + 8);
    if ( v17 > 0xD )
      goto LABEL_27;
    if ( ((1 << v17) & 0x2C60) != 0 )
      goto LABEL_36;
    if ( ((1 << v17) & 0x104) != 0 )
    {
      if ( (*(_BYTE *)(v16 + 164) & 1) == 0 )
      {
LABEL_34:
        v15 = -67;
        goto LABEL_36;
      }
LABEL_30:
      if ( *(_QWORD *)(*(_QWORD *)v2 + 736LL) )
      {
        v18 = v8;
        v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v2 + 736LL);
        if ( *((_DWORD *)v19 - 1) != -824243271 )
          __break(0x8228u);
        v15 = v19(v2 + 992, v3, v8);
        v8 = v18;
      }
      else
      {
        v15 = -95;
      }
      goto LABEL_36;
    }
    if ( v17 == 12 )
    {
      if ( *(char *)(*(_QWORD *)v16 + 119LL) < 0 )
        goto LABEL_30;
    }
    else
    {
LABEL_27:
      if ( v17 )
      {
        if ( v17 == 1 && !*(_QWORD *)(v16 + 280) )
          goto LABEL_34;
        goto LABEL_30;
      }
    }
LABEL_36:
    kfree(v8);
    return v15;
  }
  return (unsigned int)-95;
}
