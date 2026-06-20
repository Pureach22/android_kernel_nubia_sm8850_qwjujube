__int64 __fastcall ieee80211_free_hw(__int64 a1)
{
  char v2; // w8

  if ( *(_BYTE *)(a1 + 1360) == 1 )
  {
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 160LL));
    *(_BYTE *)(a1 + 1360) = 0;
  }
  idr_for_each(a1 + 5344, ieee80211_free_ack_frame, 0);
  idr_destroy(a1 + 5344);
  sta_info_stop(a1);
  v2 = *(_BYTE *)(a1 + 1505);
  if ( (v2 & 1) != 0 )
  {
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 328LL));
    v2 = *(_BYTE *)(a1 + 1505);
    if ( (v2 & 2) == 0 )
    {
LABEL_5:
      if ( (v2 & 4) == 0 )
        goto LABEL_6;
      goto LABEL_13;
    }
  }
  else if ( (*(_BYTE *)(a1 + 1505) & 2) == 0 )
  {
    goto LABEL_5;
  }
  kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 336LL));
  v2 = *(_BYTE *)(a1 + 1505);
  if ( (v2 & 4) == 0 )
  {
LABEL_6:
    if ( (v2 & 8) == 0 )
      goto LABEL_7;
    goto LABEL_14;
  }
LABEL_13:
  kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 344LL));
  v2 = *(_BYTE *)(a1 + 1505);
  if ( (v2 & 8) == 0 )
  {
LABEL_7:
    if ( (v2 & 0x10) == 0 )
      goto LABEL_8;
LABEL_15:
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 360LL));
    if ( (*(_BYTE *)(a1 + 1505) & 0x20) == 0 )
      return wiphy_free(*(_QWORD *)(a1 + 72));
    goto LABEL_9;
  }
LABEL_14:
  kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 352LL));
  v2 = *(_BYTE *)(a1 + 1505);
  if ( (v2 & 0x10) != 0 )
    goto LABEL_15;
LABEL_8:
  if ( (v2 & 0x20) != 0 )
LABEL_9:
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 368LL));
  return wiphy_free(*(_QWORD *)(a1 + 72));
}
