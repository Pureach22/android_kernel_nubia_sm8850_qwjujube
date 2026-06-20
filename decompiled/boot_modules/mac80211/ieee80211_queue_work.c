__int64 __fastcall ieee80211_queue_work(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (*(_BYTE *)(a1 + 1468) & 1) != 0 )
    return printk(&unk_BA7AA, a2, a3, a4);
  a3 = a2;
  if ( *(_BYTE *)(a1 + 1465) == 1 && (*(_BYTE *)(a1 + 1467) & 1) == 0 )
    return printk(&unk_BA7AA, a2, a3, a4);
  else
    return queue_work_on(32, *(_QWORD *)(a1 + 472), a2);
}
