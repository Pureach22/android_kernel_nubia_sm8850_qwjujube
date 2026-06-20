__int64 __fastcall ieee80211_set_active_links(__int64 a1, __int64 a2)
{
  int v2; // w22
  __int64 result; // x0
  __int64 v4; // x19
  int v5; // w2
  _DWORD *v6; // x8
  __int64 v7; // x20
  unsigned int v8; // w21
  char v9; // w0
  char v10; // w8
  unsigned int v11; // w19
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x9
  __int64 v15; // x20
  unsigned int v16; // w21
  const char *v17; // x8

  if ( (_WORD)a2 )
  {
    v2 = *(unsigned __int16 *)(a1 + 1082);
    if ( v2 == (unsigned __int16)a2 )
      return 0;
    v4 = *(_QWORD *)(a1 - 3104);
    if ( (*(_BYTE *)(v4 + 1471) & 1) == 0 )
    {
      v5 = *(_DWORD *)(a1 - 3096);
      if ( (v5 & 0x20) == 0 && (drv_can_activate_links___already_done & 1) == 0 )
      {
        v14 = *(_QWORD *)(a1 - 3112);
        drv_can_activate_links___already_done = 1;
        v15 = a1;
        v16 = a2;
        if ( v14 )
          v17 = (const char *)(v14 + 296);
        else
          v17 = (const char *)(a1 - 3080);
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v17, v5);
        a1 = v15;
        a2 = v16;
        __break(0x800u);
      }
    }
    if ( (*(_BYTE *)(a1 - 3096) & 0x20) == 0 )
      return 4294967274LL;
    v6 = *(_DWORD **)(*(_QWORD *)(v4 + 464) + 920LL);
    if ( v6 )
    {
      v7 = a1;
      v8 = a2;
      if ( *(v6 - 1) != -558863956 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v4, a1, (unsigned int)a2);
      a2 = v8;
      v10 = v9;
      a1 = v7;
    }
    else
    {
      v10 = 1;
    }
    if ( (v10 & 1) != 0 )
    {
      if ( (v2 & (unsigned int)a2) != 0 )
      {
        v11 = a2;
        v12 = a1;
        result = ieee80211_set_active_links(a1 - 4720, v2 & (unsigned int)a2);
        if ( (_DWORD)result )
          return result;
        v13 = v12 - 4720;
        a2 = v11;
      }
      else
      {
        v13 = a1 - 4720;
      }
      return ieee80211_set_active_links(v13, a2);
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
}
