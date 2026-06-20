__int64 __fastcall pattern_trig_deactivate(__int64 result, __int64 a2)
{
  void (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x20
  __int64 v4; // x19

  if ( *(_BYTE *)(result + 344) == 1 )
  {
    v2 = *(void (__fastcall **)(__int64, __int64))(result + 72);
    v3 = *(_QWORD *)(result + 336);
    v4 = result;
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 1697309055 )
        __break(0x8228u);
      v2(result, a2);
    }
    timer_shutdown_sync(v3 + 8288);
    hrtimer_cancel(v3 + 8328);
    led_set_brightness(v4, 0);
    result = kfree(v3);
    *(_BYTE *)(v4 + 344) = 0;
  }
  return result;
}
