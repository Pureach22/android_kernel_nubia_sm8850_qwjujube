__int64 __fastcall sde_encoder_early_ept_hint(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int v10; // w6
  int v11; // w7
  __int64 v12; // x21
  __int64 v13; // x8
  __int64 v14; // x22
  int v15; // w5
  __int64 result; // x0
  __int64 v17; // x8
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  int v22; // w6
  int v23; // w7
  unsigned int v24; // w23
  unsigned int v25; // w26
  __int64 v26; // x22
  int v27; // w6
  int v28; // w7
  __int64 v29; // x9
  __int64 v30; // x23
  void *v31; // x0
  __int64 v32; // x0
  int v33; // w21
  int v34; // w7
  char v35; // [xsp+0h] [xbp-30h]
  char v36; // [xsp+0h] [xbp-30h]

  sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_early_ept_hint", 6285, -1, 4369, -1059143953, a7, a8, v35);
  if ( !a1 )
    return printk(&unk_223EAA, "sde_encoder_early_ept_hint");
  v12 = *(_QWORD *)(a1 + 200);
  if ( !v12 )
    return printk(&unk_223EAA, "sde_encoder_early_ept_hint");
  if ( !*(_QWORD *)a1 )
  {
    v31 = &unk_26FCAB;
    goto LABEL_28;
  }
  v13 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 8)) == 0 )
  {
    v31 = &unk_234896;
LABEL_28:
    printk(v31, "sde_encoder_get_kms");
    return printk(&unk_25E374, "sde_encoder_early_ept_hint");
  }
  v15 = *(_DWORD *)(v14 + 6404);
  if ( v15 || !*(_DWORD *)(*(_QWORD *)(v14 + 152) + 22156LL) )
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_early_ept_hint",
             6300,
             -1,
             13107,
             v15,
             -1059143953,
             v11,
             v36);
  v17 = *(_QWORD *)(a1 + 1360);
  if ( !v17 || *(_DWORD *)(v17 + 160) >= 0x10u )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_early_ept_hint", 6310, -1, 17476, -1059143953, v10, v11, v36);
    return printk(&unk_227256, "sde_encoder_early_ept_hint");
  }
  result = sde_encoder_early_wakeup(a1);
  if ( (unsigned int)*(unsigned __int16 *)(v12 + 2356) - 3 <= 1 )
  {
    result = hrtimer_cancel(v12 + 2480);
    if ( *(_QWORD *)(v12 + 2400) > a3 )
      result = hrtimer_cancel(v12 + 2416);
    if ( *(_WORD *)(v12 + 2356) == 3 )
      *(_WORD *)(v12 + 2356) = 4;
  }
  if ( !*(_DWORD *)(*(_QWORD *)(v14 + 152) + 22152LL)
    || (result = sde_encoder_check_collision((__int64 *)v12, a3, v18, v19, v20, v21, v22, v23),
        !*(_DWORD *)(*(_QWORD *)(v14 + 152) + 22152LL))
    || (result & 1) != 0 )
  {
    v24 = *(_DWORD *)(a1 + 3944);
    v25 = *(_DWORD *)(a1 + 4812);
    v26 = ktime_get(result);
    if ( *(_QWORD *)(v12 + 2568) > v26 )
    {
      hrtimer_cancel(v12 + 2544);
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_early_ept_hint", 6339, -1, 21845, -1059143953, v27, v28, v36);
    }
    if ( (unsigned __int64)(v26 - *(_QWORD *)(v12 + 2376)) < 0x29F6300
      || *(_BYTE *)(*(_QWORD *)(a1 + 1360) + 6040LL) == 1 )
    {
      printk(&unk_23832D, "sde_encoder_early_ept_hint");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_early_ept_hint",
        6350,
        -1,
        HIDWORD(*(_QWORD *)(v12 + 2376)),
        *(_QWORD *)(v12 + 2376),
        -1059143953,
        v34,
        v36);
    }
    else
    {
      v29 = 0x3B9ACA00 / v25 + 0x3B9ACA00 / v24;
      if ( v26 + 1000000 + v29 < a3 )
      {
        v30 = a3 - v26 - v29 - 1000000;
LABEL_31:
        v32 = v12 + 2544;
        v33 = 1;
        hrtimer_start_range_ns(v32, v30, 0, 1);
        return sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "sde_encoder_early_ept_hint",
                 6373,
                 -1,
                 v33,
                 *(_DWORD *)(a1 + 3944),
                 *(_DWORD *)(a1 + 4812),
                 SHIDWORD(v30),
                 v30);
      }
      if ( v26 + (unsigned __int64)(0x3B9ACA00 / v24 + 1000000) < a3 )
      {
        v30 = 0;
        goto LABEL_31;
      }
      printk(&unk_24C7EE, "sde_encoder_early_ept_hint");
    }
    v33 = 0;
    v30 = 0;
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_early_ept_hint",
             6373,
             -1,
             v33,
             *(_DWORD *)(a1 + 3944),
             *(_DWORD *)(a1 + 4812),
             SHIDWORD(v30),
             v30);
  }
  return result;
}
