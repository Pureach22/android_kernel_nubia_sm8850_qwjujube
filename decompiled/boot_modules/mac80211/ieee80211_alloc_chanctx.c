__int64 __fastcall ieee80211_alloc_chanctx(__int64 a1, _QWORD *a2, int a3, int a4)
{
  unsigned __int64 v8; // x23
  __int64 v9; // x21
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v16; // x26

  v8 = *(int *)(a1 + 120) + 264LL;
  v9 = _kmalloc_noprof(v8, 3520);
  if ( v9 )
  {
    while ( 1 )
    {
      *(_QWORD *)(v9 + 32) = v9 + 32;
      *(_QWORD *)(v9 + 40) = v9 + 32;
      *(_QWORD *)(v9 + 48) = v9 + 48;
      *(_QWORD *)(v9 + 56) = v9 + 48;
      v10 = a2[1];
      *(_QWORD *)(v9 + 152) = *a2;
      *(_QWORD *)(v9 + 160) = v10;
      v11 = a2[3];
      *(_QWORD *)(v9 + 168) = a2[2];
      *(_QWORD *)(v9 + 176) = v11;
      v12 = a2[7];
      *(_QWORD *)(v9 + 232) = a2[6];
      *(_QWORD *)(v9 + 240) = v12;
      v13 = a2[5];
      *(_QWORD *)(v9 + 216) = a2[4];
      *(_QWORD *)(v9 + 224) = v13;
      if ( v8 >= 0xFD )
      {
        *(_BYTE *)(v9 + 252) = 1;
        if ( v8 != 253 )
        {
          *(_BYTE *)(v9 + 253) = 1;
          if ( (v8 & 0xFFFFFFFFFFFFFFFCLL) != 0x50 )
          {
            *(_DWORD *)(v9 + 80) = a3;
            if ( v8 != 254 )
            {
              *(_BYTE *)(v9 + 254) = 0;
              if ( (v8 & 0xFFFFFFFFFFFFFFFCLL) != 0xF8 )
              {
                *(_DWORD *)(v9 + 248) = a4;
                if ( v8 >= 0x101 )
                  break;
              }
            }
          }
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ieee80211_alloc_chanctx__alloc_tag;
      v8 = *(int *)(a1 + 120) + 264LL;
      v9 = _kmalloc_noprof(v8, 3520);
      *(_QWORD *)(StatusReg + 80) = v16;
      if ( !v9 )
        return v9;
    }
    *(_BYTE *)(v9 + 256) = 0;
    ieee80211_recalc_chanctx_min_def(a1, v9, nullptr, 0);
  }
  return v9;
}
