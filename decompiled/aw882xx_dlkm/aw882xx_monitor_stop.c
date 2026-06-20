__int64 __fastcall aw882xx_monitor_stop(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x1
  int v4; // w8

  v2 = *(__int64 **)(a1 - 560);
  v3 = v2[14];
  if ( !v3 )
    v3 = *v2;
  printk(&unk_26EB3, v3, "aw882xx_monitor_stop");
  v4 = *(unsigned __int8 *)(a1 + 204);
  *(_DWORD *)(a1 - 52) = 0;
  *(_BYTE *)(a1 + 200) = 0;
  if ( !v4 )
    cancel_delayed_work_sync(a1);
  return 0;
}
