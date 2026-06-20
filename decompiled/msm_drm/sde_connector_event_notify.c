__int64 __fastcall sde_connector_event_notify(__int64 *a1, int a2, int a3, int a4)
{
  __int64 v6; // x1
  __int64 result; // x0
  _DWORD v9[2]; // [xsp+Ch] [xbp-14h] BYREF
  int v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a4;
  if ( a1 )
  {
    if ( (unsigned int)(a2 + 2147483645) <= 0xD && ((1 << (a2 - 3)) & 0x2419) != 0 )
    {
      v6 = *a1;
      v9[0] = a2;
      v9[1] = a3;
      msm_mode_object_event_notify(a1 + 8, v6, v9, &v10);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_connector_event_notify",
        4601,
        -1,
        *((_DWORD *)a1 + 16),
        a2,
        a3,
        v10,
        239);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "connector:%d hw recovery event(%d) value (%d) notified\n", *((_DWORD *)a1 + 16), a2, v10);
      result = 0;
    }
    else
    {
      printk(&unk_224AAD, "sde_connector_event_notify");
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_242658, "sde_connector_event_notify");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
