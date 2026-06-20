__int64 __fastcall dp_audio_enable(__int64 result, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x22
  char v7; // w21
  __int64 v8; // x20
  __int64 v9; // x0
  unsigned __int64 v10; // x22
  char v11; // w21
  void (*v12)(void); // x8
  __int64 (*v13)(void); // x8

  v2 = *(_QWORD *)(result + 208);
  if ( v2 )
  {
    v4 = result;
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = a2;
    ipc_log_string(
      v5,
      "[i][%-4d]: audio_supported = %d, enable = %d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(v2 + 960),
      a2 & 1);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2453D5, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_21FD6A, "dp_audio_enable");
    result = v4;
    a2 = v7;
    if ( *(_BYTE *)(v2 + 960) == 1 )
    {
      if ( (v7 & 1) != 0 )
      {
        *(_DWORD *)(*(_QWORD *)(v2 + 952) + 4LL) = *(_DWORD *)(*(_QWORD *)(v4 + 168) + 132LL);
        **(_DWORD **)(v2 + 952) = *(_DWORD *)(*(_QWORD *)(v4 + 168) + 128LL);
        v12 = *(void (**)(void))(*(_QWORD *)(v2 + 952) + 16LL);
        if ( *((_DWORD *)v12 - 1) != -1116566212 )
          __break(0x8228u);
      }
      else
      {
        v12 = *(void (**)(void))(*(_QWORD *)(v2 + 952) + 24LL);
        if ( *((_DWORD *)v12 - 1) != 91663063 )
          __break(0x8228u);
      }
      v12();
      result = v4;
      a2 = v7;
    }
  }
  v3 = *(_QWORD *)(result + 216);
  if ( v3 )
  {
    v8 = result;
    if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v9 = 0;
    v10 = _ReadStatusReg(SP_EL0);
    v11 = a2;
    ipc_log_string(
      v9,
      "[i][%-4d]: audio_supported = %d, enable = %d\n",
      *(_DWORD *)(v10 + 1800),
      *(unsigned __int8 *)(v3 + 960),
      a2 & 1);
    if ( (_drm_debug & 4) != 0 )
      result = printk(&unk_2453D5, *(unsigned int *)(v10 + 1800));
    else
      result = printk(&unk_21FD6A, "dp_audio_enable");
    if ( *(_BYTE *)(v3 + 960) == 1 )
    {
      if ( (v11 & 1) != 0 )
      {
        *(_DWORD *)(*(_QWORD *)(v3 + 952) + 4LL) = *(_DWORD *)(*(_QWORD *)(v8 + 168) + 132LL);
        **(_DWORD **)(v3 + 952) = *(_DWORD *)(*(_QWORD *)(v8 + 168) + 128LL);
        v13 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 952) + 16LL);
        if ( *((_DWORD *)v13 - 1) != -1116566212 )
          __break(0x8228u);
      }
      else
      {
        v13 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 952) + 24LL);
        if ( *((_DWORD *)v13 - 1) != 91663063 )
          __break(0x8228u);
      }
      return v13();
    }
  }
  return result;
}
