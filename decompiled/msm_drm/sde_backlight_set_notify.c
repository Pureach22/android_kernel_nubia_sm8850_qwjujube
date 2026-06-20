__int64 __fastcall sde_backlight_set_notify(__int64 a1, int a2, unsigned int a3)
{
  __int64 v5; // x1
  __int64 v6; // x21
  _DWORD *v7; // x8
  __int64 result; // x0
  int v9; // w7
  char v10; // [xsp+0h] [xbp-20h]
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2;
  v11 = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = *(_QWORD *)a1;
      v11 = 0x480000003LL;
      msm_mode_object_event_notify(a1 + 64, v5, &v11, &v12);
    }
    v6 = *(_QWORD *)(a1 + 2760);
    v7 = *(_DWORD **)(a1 + 2968);
    if ( *(v7 - 1) != 1064465684 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v7)(a1, v6, a3);
    if ( !(_DWORD)result )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_backlight_set_notify",
        175,
        -1,
        *(_DWORD *)(a1 + 64),
        a3,
        -1059143953,
        v9,
        v10);
      if ( *(_DWORD *)(a1 + 4724) )
        *(_DWORD *)(*(_QWORD *)(v6 + 264) + 1492LL) = v12;
      sde_dimming_bl_notify(a1, *(_QWORD *)(v6 + 264) + 1472LL);
      result = 0;
    }
  }
  else
  {
    printk(&unk_242658, "sde_backlight_set_notify");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
