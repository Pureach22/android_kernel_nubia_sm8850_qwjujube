__int64 __fastcall haptic_audio_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x22
  _BYTE *v6; // x20
  char v7; // w9
  unsigned __int8 v8; // w10
  char v9; // w11
  char v10; // w8
  char v11; // w9
  char v12; // w8
  __int64 v13; // x0
  int v14; // w9
  _QWORD *v15; // x1
  char v16; // w10
  _QWORD *v17; // x8
  _QWORD *v18; // x2
  _DWORD *v20; // x8
  __int64 v21; // [xsp+10h] [xbp-20h] BYREF
  __int64 v22; // [xsp+18h] [xbp-18h] BYREF
  __int64 v23; // [xsp+20h] [xbp-10h] BYREF
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v22 = 0;
  v23 = 0;
  v21 = 0;
  if ( (*(_BYTE *)(v5 - 162) & 1) != 0 )
  {
    if ( sscanf(s, "%d %d %d %d %d %d", &v21, (char *)&v21 + 4, &v22, (char *)&v22 + 4, &v23, (char *)&v23 + 4) == 6 )
    {
      if ( (_DWORD)v22 )
        printk(&unk_15029, "haptic_hv", 2993, "haptic_audio_store");
      v6 = (_BYTE *)_kmalloc_cache_noprof(_arch_copy_from_user, 3520, 24);
      if ( v6 )
      {
        mutex_lock(v5 + 1096);
        v7 = BYTE4(v21);
        v9 = v23;
        v8 = BYTE4(v23);
        *v6 = v21;
        v6[1] = v7;
        v10 = v22;
        v11 = BYTE4(v22);
        v6[3] = v9;
        v6[2] = v10;
        v6[5] = v11;
        if ( v8 <= 0x80u )
          v12 = v8;
        else
          v12 = 0x80;
        v6[4] = v12;
        v13 = _kmalloc_cache_noprof(_arch_copy_from_user, 3520, 24);
        if ( v13 )
        {
          v14 = *(_DWORD *)(v6 + 1);
          v15 = (_QWORD *)(v5 + 1256);
          v16 = v6[5];
          *(_BYTE *)v13 = *v6;
          v17 = (_QWORD *)(v13 + 8);
          *(_DWORD *)(v13 + 1) = v14;
          *(_BYTE *)(v13 + 5) = v16;
          *(_QWORD *)(v13 + 8) = v13 + 8;
          *(_QWORD *)(v13 + 16) = v13 + 8;
          v18 = *(_QWORD **)(v5 + 1256);
          if ( v18[1] != v5 + 1256 || v17 == v15 || v18 == v17 )
          {
            _list_add_valid_or_report(v13 + 8);
          }
          else
          {
            v18[1] = v17;
            *(_QWORD *)(v13 + 8) = v18;
            *(_QWORD *)(v13 + 16) = v15;
            *v15 = v17;
          }
        }
        if ( (unsigned __int8)v6[1] == 255 )
        {
          printk(&unk_15C16, "haptic_hv", 3018, "haptic_audio_store");
          if ( (hrtimer_active(v5 + 1144) & 1) != 0 )
          {
            printk(&unk_1506F, "haptic_hv", 3020, "haptic_audio_store");
            hrtimer_cancel(v5 + 1144);
            *(_BYTE *)(v5 + 1272) = 0;
            audio_off(v5 - 168);
          }
        }
        else if ( (hrtimer_active(v5 + 1144) & 1) == 0 )
        {
          printk(&unk_15128, "haptic_hv", 3029, "haptic_audio_store");
          v20 = *(_DWORD **)(*(_QWORD *)(v5 + 1312) + 192LL);
          if ( *(v20 - 1) != 2072477285 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v20)(v5 - 168, 1, 0);
          hrtimer_start_range_ns(
            v5 + 1144,
            1000 * (*(_DWORD *)(v5 + 1072) % 1000000) + 1000000000LL * (*(_DWORD *)(v5 + 1072) / 1000000),
            0,
            1);
        }
        mutex_unlock(v5 + 1096);
        kfree(v6);
      }
      else
      {
        printk(&unk_1582A, "haptic_hv", 2999, "haptic_audio_store");
      }
    }
  }
  else
  {
    printk(&unk_16977, "haptic_hv", 2985, "haptic_audio_store");
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
