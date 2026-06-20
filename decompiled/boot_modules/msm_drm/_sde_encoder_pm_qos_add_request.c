__int64 __fastcall sde_encoder_pm_qos_add_request(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  unsigned int v3; // w10
  __int64 v4; // x19
  int v5; // w20
  __int64 v6; // x9
  _DWORD *v7; // x23
  __int64 v8; // x8
  char v9; // w8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x22
  unsigned __int64 v18; // x10
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 56LL) + 8LL);
  v2 = *(_QWORD *)(v1 + 152);
  if ( v2 && *(_QWORD *)(v2 + 21848) )
  {
    v3 = *(_DWORD *)(result + 3944);
    v4 = result;
    v5 = *(_DWORD *)(v2 + 21864);
    *(_QWORD *)(result + 3936) = 0;
    if ( v3 >= 0x3D )
    {
      v6 = *(_QWORD *)(v1 + 152);
      v7 = (_DWORD *)(v6 + 21856);
      if ( v6 != -21856 )
        goto LABEL_8;
    }
    if ( !result )
      return printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    if ( *(_DWORD *)(result + 648) == 2 )
    {
      v8 = *(_QWORD *)(v1 + 152);
      v7 = (_DWORD *)(v8 + 21848);
      if ( v8 != -21848 )
      {
LABEL_8:
        v9 = 0;
        do
        {
          v10 = (unsigned int)(-1LL << v9) & *v7;
          if ( !(_DWORD)v10 )
            break;
          v11 = __clz(__rbit64(v10));
          if ( !get_cpu_device((unsigned int)v11) )
            return printk(&unk_276F4E, "_sde_encoder_pm_qos_add_request");
          _X9 = (unsigned __int64 *)(v4 + 3936);
          __asm { PRFM            #0x11, [X9] }
          do
            v18 = __ldxr(_X9);
          while ( __stxr(v18 | (1LL << v11), _X9) );
          dev_pm_qos_add_request();
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "_sde_encoder_pm_qos_add_request",
                     350,
                     4,
                     *(_DWORD *)(v4 + 24),
                     v5,
                     v11,
                     -1059143953,
                     vars0);
          v9 = v11 + 1;
        }
        while ( v11 < 0x1F );
      }
    }
  }
  return result;
}
