__int64 __fastcall ieee80211_sta_allocate_link(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x23
  char v6; // w20
  unsigned __int64 v7; // x8
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x23
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 StatusReg; // x24
  __int64 v14; // x25

  v4 = *(_QWORD *)(a1 + 80);
  v6 = a2;
  if ( (*(_QWORD *)(a1 + 216) & 0x100000) != 0 )
  {
    v7 = *(unsigned __int16 *)(a1 + 2872);
    if ( *(_WORD *)(a1 + 2872) )
      goto LABEL_3;
  }
  else
  {
    __break(0x800u);
    v7 = *(unsigned __int16 *)(a1 + 2872);
    if ( *(_WORD *)(a1 + 2872) )
    {
LABEL_3:
      if ( ((v7 >> a2) & 1) != 0 )
      {
LABEL_4:
        __break(0x800u);
        return 4294967280LL;
      }
      if ( a2 >= 0xF )
      {
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v14 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &ieee80211_sta_allocate_link__alloc_tag;
        v9 = _kmalloc_cache_noprof(_cpu_online_mask, 3520, 1192);
        *(_QWORD *)(StatusReg + 80) = v14;
        if ( v9 )
        {
LABEL_8:
          if ( (*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 96LL) & 0x400000000LL) == 0
            || (v10 = v9, v11 = pcpu_alloc_noprof(200, 8, 0, 3264), v9 = v10, (*(_QWORD *)(v10 + 104) = v11) != 0) )
          {
            v12 = jiffies;
            *(_QWORD *)(v9 + 680) = 0;
            *(_QWORD *)(v9 + 312) = 0;
            *(_QWORD *)(v9 + 320) = 0;
            *(_QWORD *)(v9 + 120) = v12;
            *(_QWORD *)(v9 + 928) = a1 + 2688;
            *(_QWORD *)(v9 + 328) = 0;
            *(_QWORD *)(v9 + 336) = 0;
            *(_QWORD *)(v9 + 344) = 0;
            *(_QWORD *)(v9 + 32) = a1;
            *(_BYTE *)(v9 + 6) = v6;
            *(_QWORD *)(v9 + 920) = v9 + 928;
            *(_BYTE *)(v9 + 942) = v6;
            atomic_store(v9, (unsigned __int64 *)(v2 + 8 * v3));
            atomic_store(v9 + 928, (unsigned __int64 *)(a1 + 8 * v3 + 3128));
            *(_DWORD *)(v9 + 944) = 1;
            *(_WORD *)(v9 + 1124) = 4095;
            return 0;
          }
          kfree(v10);
        }
      }
      else
      {
        v3 = a2;
        v2 = a1 + 2568;
        if ( *(_QWORD *)(a1 + 2568 + 8LL * a2) )
          goto LABEL_4;
        v9 = _kmalloc_cache_noprof(_cpu_online_mask, 3520, 1192);
        if ( v9 )
          goto LABEL_8;
      }
      return 4294967284LL;
    }
  }
  __break(0x800u);
  return 4294967274LL;
}
