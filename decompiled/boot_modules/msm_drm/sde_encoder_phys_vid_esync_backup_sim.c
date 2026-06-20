__int64 __fastcall sde_encoder_phys_vid_esync_backup_sim(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 *v8; // x21
  __int64 v9; // x20
  void (__fastcall *v11)(__int64, __int64 *); // x8
  __int64 v12; // x0
  __int64 v13; // x8
  int v14; // w0
  int v15; // w4
  __int64 v17; // x0
  unsigned __int64 v18; // x20
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x0
  char v21; // [xsp+0h] [xbp+0h]

  v8 = (__int64 *)(a1 - 920);
  v9 = *(_QWORD *)(a1 - 920);
  if ( !v9 )
    return 0;
  v11 = *(void (__fastcall **)(__int64, __int64 *))(a1 - 544);
  if ( !v11 )
  {
    v14 = sde_dbg_base_evtlog;
    v13 = v9;
LABEL_9:
    v15 = *(_DWORD *)(v13 + 24);
    goto LABEL_10;
  }
  v12 = *(_QWORD *)(a1 - 920);
  if ( *((_DWORD *)v11 - 1) != 468003652 )
    __break(0x8228u);
  v11(v12, v8);
  v13 = *v8;
  v14 = sde_dbg_base_evtlog;
  if ( *v8 )
    goto LABEL_9;
  v15 = -1;
LABEL_10:
  v17 = sde_evtlog_log(v14, "sde_encoder_phys_vid_esync_backup_sim", 1351, -1, v15, 8738, -1059143953, a8, v21);
  v18 = ((unsigned __int64)*(unsigned int *)(v9 + 764) + 999999999) / *(unsigned int *)(v9 + 764);
  v19 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 48) + 48LL);
  if ( *((_DWORD *)v19 - 1) != -432005955 )
    __break(0x8228u);
  v20 = v19(v17);
  hrtimer_forward(a1, v20, v18);
  return 1;
}
