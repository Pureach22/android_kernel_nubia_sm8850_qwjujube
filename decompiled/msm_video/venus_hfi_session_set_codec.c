__int64 __fastcall venus_hfi_session_set_codec(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x4
  _QWORD *v4; // x8
  _QWORD *v5; // x9
  void *v6; // x0
  int v7; // w3
  __int64 v8; // x0
  unsigned int v9; // w1
  int v10; // w2
  unsigned int header; // w21
  int hfi_codec; // w0
  int v13; // w6
  unsigned int *v14; // x0
  unsigned int v15; // w1
  int v16; // w6
  unsigned int *v17; // x0
  unsigned int v18; // w1
  __int64 v19; // x20
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  int v25; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 320);
  v25 = 0;
  core_lock(v2);
  if ( !*(_QWORD *)(a1 + 368) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_24;
    v6 = &unk_8DDBA;
    goto LABEL_13;
  }
  if ( (mutex_is_locked(v2 + 3856) & 1) == 0 )
  {
    __break(0x800u);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_session_set_codec");
    goto LABEL_24;
  }
  v4 = (_QWORD *)(v2 + 3528);
  v5 = (_QWORD *)(v2 + 3528);
  do
    v5 = (_QWORD *)*v5;
  while ( v5 != (_QWORD *)a1 && v5 != v4 );
  if ( a1 && v5 == v4 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
LABEL_24:
      header = -22;
      goto LABEL_25;
    }
    v6 = &unk_89648;
LABEL_13:
    printk(v6, "err ", a1 + 340, "venus_hfi_session_set_codec", v3);
    goto LABEL_24;
  }
  if ( v5 == v4 )
    goto LABEL_24;
  v7 = *(_DWORD *)(v2 + 6600);
  v8 = *(_QWORD *)(a1 + 368);
  v9 = *(_DWORD *)(a1 + 376);
  v10 = *(_DWORD *)(a1 + 332);
  *(_DWORD *)(v2 + 6600) = v7 + 1;
  header = hfi_create_header(v8, v9, v10, v7);
  if ( !header )
  {
    hfi_codec = get_hfi_codec(a1);
    v13 = *(_DWORD *)(v2 + 6604);
    v25 = hfi_codec;
    v14 = *(unsigned int **)(a1 + 368);
    v15 = *(_DWORD *)(a1 + 376);
    *(_DWORD *)(v2 + 6604) = v13 + 1;
    header = hfi_create_packet(v14, v15, 50331904, 0, 9, 0, v13, &v25, 4u);
    if ( !header )
    {
      if ( !*(_QWORD *)(a1 + 21320)
        || (v16 = *(_DWORD *)(v2 + 6604),
            v17 = *(unsigned int **)(a1 + 368),
            v18 = *(_DWORD *)(a1 + 376),
            *(_DWORD *)(v2 + 6604) = v16 + 1,
            (header = hfi_create_packet(v17, v18, 50332082, 0, 9, 0, v16, (const void *)(a1 + 21320), 4u)) == 0) )
      {
        v19 = *(_QWORD *)(a1 + 368);
        header = _resume(v2);
        if ( !header )
        {
          header = venus_hfi_queue_cmd_write(v2, v19);
          if ( !header )
            _schedule_power_collapse_work(v2, v20, v21, v22, v23);
        }
      }
    }
  }
LABEL_25:
  core_unlock(v2);
  _ReadStatusReg(SP_EL0);
  return header;
}
