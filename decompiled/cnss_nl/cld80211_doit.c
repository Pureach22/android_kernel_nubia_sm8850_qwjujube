__int64 __fastcall cld80211_doit(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x8
  __int16 *v3; // x0
  _WORD *v4; // x0
  __int16 v5; // t1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x1

  v2 = *(_DWORD **)(a2 + 48);
  if ( v2 )
  {
    v3 = *(__int16 **)(*(_QWORD *)(a2 + 32) + 8LL);
    if ( v3 )
    {
      v5 = *v3;
      v4 = v3 + 2;
      v6 = *(_QWORD *)(a2 + 56);
      v7 = *(unsigned int *)(a2 + 4);
      v8 = (unsigned __int16)(v5 - 4);
      if ( *(v2 - 1) != -1684918855 )
        __break(0x8228u);
      ((void (__fastcall *)(_WORD *, __int64, __int64, __int64))v2)(v4, v8, v6, v7);
      return 0;
    }
    else
    {
      printk(&unk_7085);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_706A);
    return 4294967201LL;
  }
}
