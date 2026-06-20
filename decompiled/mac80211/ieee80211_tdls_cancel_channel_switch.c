unsigned __int64 __fastcall ieee80211_tdls_cancel_channel_switch(__int64 a1, __int64 a2, const void *a3)
{
  __int64 v4; // x19
  unsigned __int64 result; // x0
  int v6; // w2
  __int64 v7; // x1
  unsigned __int64 v8; // x20
  void (__fastcall *v9)(__int64, __int64, unsigned __int64); // x8
  __int64 v10; // x9
  const char *v11; // x1
  unsigned __int64 v12; // x21
  unsigned __int64 v19; // x10

  v4 = *(_QWORD *)(a2 + 4304);
  result = sta_info_get(a2 + 2688, a3);
  if ( result && (*(_QWORD *)(result + 216) & 0x8000) != 0 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 4304) + 1471LL) & 1) == 0 )
    {
      v6 = *(_DWORD *)(a2 + 4312);
      if ( (v6 & 0x20) == 0 && (drv_tdls_cancel_channel_switch___already_done_0 & 1) == 0 )
      {
        v10 = *(_QWORD *)(a2 + 4296);
        drv_tdls_cancel_channel_switch___already_done_0 = 1;
        if ( v10 )
          v11 = (const char *)(v10 + 296);
        else
          v11 = (const char *)(a2 + 4328);
        v12 = result;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11, v6);
        result = v12;
        __break(0x800u);
      }
    }
    if ( (*(_BYTE *)(a2 + 4312) & 0x20) != 0 && *(_QWORD *)(*(_QWORD *)(v4 + 464) + 736LL) )
    {
      v7 = a2 + 7408;
      v8 = result;
      v9 = *(void (__fastcall **)(__int64, __int64, unsigned __int64))(*(_QWORD *)(v4 + 464) + 736LL);
      if ( *((_DWORD *)v9 - 1) != -1656504592 )
        __break(0x8228u);
      v9(v4, v7, result + 2688);
      result = v8;
    }
    _X8 = (unsigned __int64 *)(result + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
  }
  return result;
}
