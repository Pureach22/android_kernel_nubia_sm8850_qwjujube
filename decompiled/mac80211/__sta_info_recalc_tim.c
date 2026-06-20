__int64 __fastcall _sta_info_recalc_tim(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x19
  int v5; // w8
  unsigned __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x23
  _BOOL4 v9; // w20
  __int64 v10; // x9
  __int64 v12; // x9
  int v15; // w9
  char v16; // w10
  char v17; // w11
  char v18; // w9
  void (__fastcall *v19)(__int64, __int64, _BOOL4); // x8
  __int64 v20; // x8

  v2 = *(_QWORD *)(result + 80);
  if ( (unsigned int)(*(_DWORD *)(v2 + 4720) - 3) <= 1 )
  {
    v3 = *(_QWORD *)(v2 + 2032);
    if ( !v3 )
    {
      __break(0x800u);
      return result;
    }
    v4 = *(_QWORD *)(result + 72);
    v5 = *(unsigned __int8 *)(result + 2699);
    v6 = *(unsigned __int16 *)(result + 2694);
    if ( (*(_QWORD *)(v4 + 96) & 0x100000) == 0 || *(_QWORD *)(*(_QWORD *)(v4 + 464) + 144LL) )
    {
      v7 = v3 + 16;
      if ( (*(_BYTE *)(result + 202) & 1) != 0 )
      {
        v8 = result;
        v9 = 0;
LABEL_41:
        raw_spin_lock_bh(v4 + 1604);
        if ( v9 != ((*(unsigned __int8 *)(v7 + (v6 >> 3)) >> (v6 & 7)) & 1) )
        {
          v15 = 1 << (v6 & 7);
          v16 = *(_BYTE *)(v7 + (v6 >> 3));
          v17 = v16 & ~(_BYTE)v15;
          v18 = v16 | v15;
          if ( !v9 )
            v18 = v17;
          *(_BYTE *)(v7 + (v6 >> 3)) = v18;
          if ( *(_QWORD *)(*(_QWORD *)(v4 + 464) + 144LL) )
          {
            if ( *(_BYTE *)(v8 + 202) == 1 )
            {
              __break(0x800u);
            }
            else
            {
              *(_BYTE *)(v4 + 1464) = 1;
              v19 = *(void (__fastcall **)(__int64, __int64, _BOOL4))(*(_QWORD *)(v4 + 464) + 144LL);
              if ( v19 )
              {
                if ( *((_DWORD *)v19 - 1) != -1102993663 )
                  __break(0x8228u);
                v19(v4, v8 + 2688, v9);
              }
              *(_BYTE *)(v4 + 1464) = 0;
            }
          }
        }
        return raw_spin_unlock_bh(v4 + 1604);
      }
      if ( v5 == 15 )
        LOBYTE(v5) = 0;
      if ( (a2 & 1) != 0 )
        LOBYTE(v5) = 15;
      v9 = 0;
      if ( ((unsigned __int8)v5 & ieee80211_ac_to_qos_mask[0]) == 0 )
      {
        if ( *(_QWORD *)(result + 328) != result + 328 || *(_QWORD *)(result + 232) != result + 232 )
          goto LABEL_40;
        v10 = *(_QWORD *)(result + 432) & 0xC0LL;
        if ( (*(_BYTE *)(result + 424) & 0xC0) != 0 )
          ++v10;
        v9 = v10 != 0;
      }
      if ( (v5 & 2) == 0 )
      {
        if ( *(_QWORD *)(result + 352) != result + 352 )
          goto LABEL_40;
        if ( *(_QWORD *)(result + 256) != result + 256 || v9 )
          goto LABEL_40;
        v12 = *(_QWORD *)(result + 432) & 0x30LL;
        if ( (*(_BYTE *)(result + 424) & 0x30) != 0 )
          ++v12;
        v9 = v12 != 0;
      }
      if ( (v5 & 8) == 0 )
      {
        if ( *(_QWORD *)(result + 376) != result + 376 )
          goto LABEL_40;
        if ( *(_QWORD *)(result + 280) != result + 280 || v9 )
          goto LABEL_40;
        v9 = (*(_QWORD *)(result + 432) & 9LL | ((*(_BYTE *)(result + 424) & 9) != 0)) != 0;
      }
      if ( (v5 & 4) != 0 )
      {
        v8 = result;
        goto LABEL_41;
      }
      if ( *(_QWORD *)(result + 400) == result + 400 && *(_QWORD *)(result + 304) == result + 304 && !v9 )
      {
        v8 = result;
        v20 = *(_QWORD *)(result + 432) & 6LL;
        if ( (*(_BYTE *)(result + 424) & 6) != 0 )
          ++v20;
        v9 = v20 != 0;
        goto LABEL_41;
      }
LABEL_40:
      v8 = result;
      v9 = 1;
      goto LABEL_41;
    }
  }
  return result;
}
