__int64 __fastcall wcd_mbhc_btn_press_handler(__int64 a1, __int64 a2)
{
  _DWORD *v3; // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  int v6; // w0
  int v7; // w8
  __int64 v8; // x9
  void (__fastcall *v9)(__int64, __int64); // x8
  _DWORD *v10; // x8

  complete(a2 + 864);
  mutex_lock(a2 + 744);
  if ( (cancel_delayed_work_sync(a2) & 1) != 0 )
  {
    v3 = *(_DWORD **)(*(_QWORD *)(a2 + 120) + 144LL);
    if ( *(v3 - 1) != 1996337026 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v3)(a2, 0);
  }
  if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 472LL) )
  {
    if ( !((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216)) & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 476LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856) + 477LL)) )
    {
      *(_BYTE *)(a2 + 160) = 1;
      if ( (unsigned int)jiffies_to_msecs(jiffies - *(_QWORD *)(a2 + 368)) >= 0x7D0 && (*(_BYTE *)(a2 + 162) & 1) == 0 )
      {
        v4 = *(_QWORD *)(a2 + 216);
        v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 120) + 136LL);
        if ( *((_DWORD *)v5 - 1) != -725583242 )
          __break(0x8228u);
        v6 = v5(v4);
        v7 = 0;
        if ( v6 > 2 )
        {
          switch ( v6 )
          {
            case 3:
              v7 = 2048;
              break;
            case 4:
              v7 = 1024;
              break;
            case 5:
              v7 = 512;
              break;
          }
        }
        else if ( v6 )
        {
          if ( v6 == 1 )
          {
            v7 = 0x2000;
          }
          else if ( v6 == 2 )
          {
            v7 = 4096;
          }
        }
        else
        {
          *(_BYTE *)(a2 + 208) = 1;
          v7 = 0x4000;
        }
        if ( *(_BYTE *)(a2 + 161) == 1 )
        {
          v8 = *(_QWORD *)(a2 + 120);
          *(_DWORD *)(a2 + 104) |= v7;
          v9 = *(void (__fastcall **)(__int64, __int64))(v8 + 144);
          if ( *((_DWORD *)v9 - 1) != 1996337026 )
            __break(0x8228u);
          v9(a2, 1);
          if ( (queue_delayed_work_on(32, system_wq, a2, 100) & 1) == 0 )
          {
            _warn_printk("Button pressed twice without release event\n");
            __break(0x800u);
            v10 = *(_DWORD **)(*(_QWORD *)(a2 + 120) + 144LL);
            if ( *(v10 - 1) != 1996337026 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD))v10)(a2, 0);
          }
        }
      }
    }
  }
  mutex_unlock(a2 + 744);
  return 1;
}
