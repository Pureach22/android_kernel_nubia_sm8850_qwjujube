__int64 __fastcall sde_kms_sui_misr_ctrl(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x21
  unsigned int v6; // w0
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x1
  unsigned __int64 v10; // x20
  unsigned int v12; // w8
  unsigned int v13; // w20
  unsigned int v20; // w10
  int v21; // w7
  unsigned int v22; // w21
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (a3 & 1) == 0 )
  {
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))sde_vbif_halt_xin_mask)(
                         a1,
                         *(unsigned int *)(*(_QWORD *)(a1 + 152) + 21476LL),
                         0) )
      printk(&unk_257477, "_sde_kms_secure_ctrl_xin_clients");
    sde_crtc_misr_setup(a2, 0, 0);
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), 4);
    return 0;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL);
  v6 = _pm_runtime_resume(v5, 4);
  if ( (v6 & 0x80000000) == 0 )
  {
    sde_crtc_misr_setup(a2, 1, 1);
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
    v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))sde_vbif_halt_xin_mask)(
           a1,
           *(unsigned int *)(*(_QWORD *)(a1 + 152) + 21476LL),
           1);
    if ( (_DWORD)v8 )
    {
      v22 = v8;
      printk(&unk_257477, "_sde_kms_secure_ctrl_xin_clients");
      sde_crtc_misr_setup(a2, 0, 0);
      _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), 4);
      return v22;
    }
    if ( *(_DWORD *)(v7 + 728) )
    {
      v10 = 0;
      while ( v10 != 32 )
      {
        v8 = sde_plane_secure_ctrl_xin_client(*(_QWORD *)(v7 + 736 + 8 * v10++), a2);
        if ( v10 >= *(unsigned int *)(v7 + 728) )
          return 0;
      }
      __break(0x5512u);
      return sde_kms_scm_call(v8, v9);
    }
    return 0;
  }
  v12 = *(_DWORD *)(v5 + 480);
  v13 = v6;
  do
  {
    if ( !v12 )
      break;
    _X12 = (unsigned int *)(v5 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v20 = __ldxr(_X12);
      if ( v20 != v12 )
        break;
      if ( !__stlxr(v12 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v20 == v12;
    v12 = v20;
  }
  while ( !_ZF );
  printk(&unk_24C43E, "_sde_kms_sui_misr_ctrl");
  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_kms_sui_misr_ctrl", 590, -1, v13, 60333, -1059143953, v21, vars0);
  return v13;
}
