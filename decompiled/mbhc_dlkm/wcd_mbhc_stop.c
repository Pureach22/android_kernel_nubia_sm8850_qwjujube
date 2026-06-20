__int64 __fastcall wcd_mbhc_stop(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0
  __int64 v5; // x8
  _DWORD *v6; // x8
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x0
  _DWORD *v10; // x8
  __int64 v11; // x1

  v1 = result;
  if ( *(_BYTE *)(result + 161) )
  {
    v2 = *(_QWORD *)(result + 120);
    if ( v2 )
    {
      v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 224);
      if ( v3 )
      {
        v4 = *(_QWORD *)(result + 216);
        if ( *((_DWORD *)v3 - 1) != 933030000 )
          __break(0x8228u);
        result = v3(v4);
      }
    }
  }
  v5 = *(_QWORD *)(v1 + 120);
  *(_BYTE *)(v1 + 161) = 0;
  *(_DWORD *)(v1 + 128) = 0;
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 112);
    if ( v6 )
    {
      v7 = *(_QWORD *)(v1 + 216);
      v8 = *(unsigned int *)(*(_QWORD *)(v1 + 792) + 20LL);
      if ( *(v6 - 1) != 542830841 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v6)(v7, v8, 0);
      v9 = *(_QWORD *)(v1 + 216);
      v10 = *(_DWORD **)(*(_QWORD *)(v1 + 120) + 112LL);
      v11 = *(unsigned int *)(*(_QWORD *)(v1 + 792) + 24LL);
      if ( *(v10 - 1) != 542830841 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(v9, v11, 0);
    }
  }
  if ( *(_QWORD *)(v1 + 328) || *(_QWORD *)(v1 + 336) )
  {
    result = cancel_delayed_work_sync(v1 + 224);
    if ( !*(_QWORD *)(v1 + 336) )
      result = release_firmware(*(_QWORD *)(v1 + 328));
    *(_QWORD *)(v1 + 328) = 0;
    *(_QWORD *)(v1 + 336) = 0;
  }
  if ( *(_DWORD *)(*(_QWORD *)(v1 + 112) + 88LL) )
    return wcd_usbss_unreg_notifier(v1 + 944, *(_QWORD *)(v1 + 936));
  return result;
}
