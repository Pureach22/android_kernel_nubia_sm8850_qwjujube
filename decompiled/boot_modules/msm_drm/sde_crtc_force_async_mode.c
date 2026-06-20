__int64 __fastcall sde_crtc_force_async_mode(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x19
  void *v8; // x0
  int v9; // w7
  _DWORD *v10; // x8
  int v11; // w4
  char v12; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return printk(&unk_223EAA, "sde_crtc_force_async_mode");
  if ( !a2 )
    return printk(&unk_223EAA, "sde_crtc_force_async_mode");
  result = *(_QWORD *)(a1 + 80);
  if ( !result )
    return printk(&unk_223EAA, "sde_crtc_force_async_mode");
  if ( !*(_QWORD *)result || (v4 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v8 = &unk_25E167;
LABEL_18:
    printk(v8, "_sde_crtc_get_kms");
    return printk(&unk_223EAA, "sde_crtc_force_async_mode");
  }
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 )
  {
    v8 = &unk_234896;
    goto LABEL_18;
  }
  v6 = *(_QWORD *)(v5 + 152);
  if ( !v6 )
    return printk(&unk_223EAA, "sde_crtc_force_async_mode");
  if ( *(_BYTE *)(a1 + 4936) == 1 && (*(_QWORD *)(v6 + 680) & 0x8000) != 0 )
  {
    v7 = a1;
    sde_crtc_atomic_set_property();
    v10 = *(_DWORD **)(v7 + 80);
    if ( v10 )
      v11 = v10[28];
    else
      v11 = -1;
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_crtc_force_async_mode",
             8115,
             -1,
             v11,
             **(_DWORD **)(*(_QWORD *)v10 + 64LL),
             -1059143953,
             v9,
             v12);
  }
  return result;
}
