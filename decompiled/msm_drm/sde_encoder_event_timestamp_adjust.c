signed __int64 __fastcall sde_encoder_event_timestamp_adjust(int a1, unsigned int a2, unsigned __int64 a3)
{
  __int64 (*v5)(void); // x8
  unsigned __int64 v7; // x25
  __int64 v8; // x22
  unsigned __int64 v9; // x21
  unsigned __int64 v10; // x23
  signed __int64 v11; // x26
  __int64 v12; // x22
  __int64 v13; // kr10_8

  v5 = (__int64 (*)(void))arch_timer_read_counter;
  if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
    __break(0x8228u);
  v7 = v5();
  v8 = ktime_get(v7);
  v9 = v7 - a3;
  if ( v7 < a3 )
  {
    v9 += 0xFFFFFFFFFFFFFFLL;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_event_timestamp_adjust",
      175,
      -1,
      a1,
      SHIDWORD(a3),
      a3,
      SHIDWORD(v7),
      v7);
  }
  v10 = (10000 * v9 + 191) / 0xC0;
  if ( v10 <= (a2 + 999999999) / a2 )
  {
    v11 = v8 - v10;
  }
  else
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_event_timestamp_adjust",
      188,
      -1,
      a1,
      SHIDWORD(a3),
      a3,
      SHIDWORD(v7),
      v7);
    v11 = 0;
  }
  if ( (_drm_debug & 4) != 0
    && (_drm_dev_dbg(0, 0, 0, "event_hw_ts:%llu, cur_hw_ts:%llu, hw_diff_ns:%llu", a3, v7, v10), (_drm_debug & 4) != 0) )
  {
    v13 = v8;
    v12 = v11 / 1000;
    _drm_dev_dbg(0, 0, 0, "event_sw_ts:%llu, cur_sw_ts:%llu, event_fps:%d\n", v11 / 1000, v13 / 1000, a2);
  }
  else
  {
    v12 = v11 / 1000;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_event_timestamp_adjust", 200, 4, a1, SHIDWORD(v9), v9, v10, v12);
  return v11;
}
