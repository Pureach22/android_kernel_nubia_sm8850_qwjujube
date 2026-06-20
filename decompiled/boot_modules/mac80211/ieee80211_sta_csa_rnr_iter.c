__int64 __fastcall ieee80211_sta_csa_rnr_iter(unsigned __int8 *a1, char a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  __int64 result; // x0
  unsigned int *v7; // x21
  __int64 v8; // x0
  __int64 v9; // x19
  unsigned __int8 *v10; // x20
  __int64 v12; // x2
  __int64 v13; // x3
  unsigned int v14; // w0
  __int64 channel_khz; // x8
  __int64 v16; // x8
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  result = 0;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 && a5 >= 0x10u )
  {
    if ( *(unsigned __int8 *)(a4 + 13) == a1[16]
      && (v7 = *(unsigned int **)a1, *(_DWORD *)(*(_QWORD *)a1 + 8LL) == (*(_WORD *)(a4 + 14) & 0xF)) )
    {
      v8 = *(unsigned __int8 *)(a3 + 2);
      v9 = *(_QWORD *)v7;
      v10 = a1;
      v17 = 0;
      if ( (ieee80211_operating_class_to_band(v8, &v17) & 1) != 0 )
      {
        v14 = ieee80211_channel_to_freq_khz(*(unsigned __int8 *)(a3 + 3), v17);
        channel_khz = ieee80211_get_channel_khz(*(_QWORD *)(*(_QWORD *)(v9 + 1616) + 72LL), 1000 * (v14 / 0x3E8));
        result = 1;
        *((_QWORD *)v10 + 1) = channel_khz;
      }
      else
      {
        v16 = *(_QWORD *)v7;
        if ( *(_WORD *)(*(_QWORD *)v7 + 5800LL) )
          printk(&unk_B93A5, v16 + 1640, v7[2], v13);
        else
          printk(&unk_B7DBF, v16 + 1640, v12, v13);
        wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v9 + 1616) + 72LL), v9 + 2432);
        result = 1;
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
