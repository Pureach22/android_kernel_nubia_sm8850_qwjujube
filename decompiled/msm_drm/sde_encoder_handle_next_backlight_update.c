__int64 __fastcall sde_encoder_handle_next_backlight_update(__int64 a1)
{
  __int64 v1; // x23
  unsigned int v2; // w8
  unsigned int v3; // w9
  unsigned int v4; // w10
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int v7; // w22
  __int64 v8; // x19
  int v9; // w7
  unsigned __int64 v10; // x26
  unsigned __int64 v11; // x27
  signed __int64 v12; // x22
  __int64 v13; // x21
  int v14; // w7
  __int64 v15; // x19
  __int64 v17; // x19
  char v18; // [xsp+0h] [xbp-10h]
  char v19; // [xsp+0h] [xbp-10h]

  if ( !a1 )
    return printk(&unk_223EAA, "sde_encoder_handle_next_backlight_update");
  v1 = *(_QWORD *)(a1 + 328);
  if ( !v1 )
    return printk(&unk_223EAA, "sde_encoder_handle_next_backlight_update");
  v2 = *(_DWORD *)(v1 + 2364);
  v3 = *(_DWORD *)(a1 + 3944);
  if ( !v2 || !v3 || (v4 = *(_DWORD *)(a1 + 4812)) == 0 )
  {
    v17 = a1;
    a1 = printk(&unk_24FDC0, "sde_encoder_handle_next_backlight_update");
    v2 = *(_DWORD *)(v1 + 2364);
    v3 = *(_DWORD *)(v17 + 3944);
    v4 = *(_DWORD *)(v17 + 4812);
  }
  v5 = 0x3B9ACA00 / v3;
  v6 = 1000 * (0x3B9ACA00 / v2);
  v7 = 0x3B9ACA00 / v4;
  v8 = ktime_get(a1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_handle_next_backlight_update",
    6236,
    -1,
    v6,
    v5,
    v7,
    (int)v8 / 1000,
    (char)*(_QWORD *)(v1 + 2376) / -24);
  v10 = *(_QWORD *)(v1 + 2376);
  v11 = v8 + 3000000;
  do
  {
    v12 = v10;
    v10 += v6;
  }
  while ( v10 < v11 );
  v13 = v12 / 1000;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_handle_next_backlight_update",
    6250,
    -1,
    v12 / 1000,
    (__int64)v10 / 1000,
    -1059143953,
    v9,
    v18);
  if ( v12 < v11 )
  {
    do
    {
      if ( v12 + v5 + v5 <= v10 )
        v12 += v5;
      else
        v12 = v10;
    }
    while ( v12 < v11 );
    v13 = v12 / 1000;
  }
  v15 = v12 - v8 - 3000000;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_handle_next_backlight_update",
    6265,
    -1,
    v13,
    v15 / 1000,
    -1059143953,
    v14,
    v19);
  return hrtimer_start_range_ns(v1 + 2616, v15, 0, 1);
}
