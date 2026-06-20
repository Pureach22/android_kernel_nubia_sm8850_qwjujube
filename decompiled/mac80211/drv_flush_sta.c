__int64 __fastcall drv_flush_sta(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned int v5; // w8
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x2
  __int64 v8; // x1
  __int64 v9; // x10
  __int64 v10; // x9
  __int64 v11; // x20
  __int64 v12; // [xsp+8h] [xbp-8h]

  v3 = result;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 4720) != 4 || (v4 = *(_QWORD *)(a2 + 2032), a2 = v4 - 2264, v4 != 2264) )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
        || (v5 = *(_DWORD *)(a2 + 1624), (v5 & 0x20) != 0)
        || (drv_flush_sta___already_done & 1) != 0 )
      {
        if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
          return result;
      }
      else
      {
        v9 = *(_QWORD *)(a2 + 1608);
        drv_flush_sta___already_done = 1;
        v12 = a2;
        if ( v9 )
          v10 = v9 + 296;
        else
          v10 = a2 + 1640;
        v11 = a3;
        result = _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v10, v5);
        a2 = v12;
        a3 = v11;
        __break(0x800u);
        if ( (*(_BYTE *)(v12 + 1624) & 0x20) == 0 )
          return result;
      }
    }
  }
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v3 + 464) + 440LL);
  if ( v6 )
  {
    v7 = a3 + 2688;
    v8 = a2 + 4720;
    if ( *((_DWORD *)v6 - 1) != -1656504592 )
      __break(0x8228u);
    return v6(v3, v8, v7);
  }
  return result;
}
