bool __fastcall cqhci_clear_all_tasks(_QWORD *a1)
{
  _QWORD *v2; // x20
  void (__fastcall *v3)(__int64, __int64, __int64); // x8
  _DWORD *v4; // x8
  _DWORD *v5; // x8
  int v6; // w0
  _DWORD *v7; // x8
  _DWORD *v8; // x8
  __int64 i; // x21
  _DWORD *v10; // x8
  __int16 v11; // w0
  bool v12; // zf
  __int64 v13; // x8
  _DWORD *v14; // x8
  _DWORD *v15; // x8
  _DWORD *v16; // x8
  __int16 v17; // w0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v22; // x0
  __int64 v23; // x1
  __int16 v24; // w20
  _QWORD v25[6]; // [xsp+0h] [xbp-30h] BYREF

  v25[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)a1[183];
  v3 = *(void (__fastcall **)(__int64, __int64, __int64))(*v2 + 8LL);
  if ( v3 )
  {
    v22 = a1[183];
    if ( *((_DWORD *)v3 - 1) != -1433747670 )
      __break(0x8228u);
    v3(v22, 8, 20);
  }
  else
  {
    writel_relaxed(8u, (unsigned int *)(v2[1] + 20LL));
  }
  v4 = *(_DWORD **)(*v2 + 8LL);
  if ( v4 )
  {
    if ( *(v4 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64, __int64))v4)(v2, 8, 24);
  }
  else
  {
    writel_relaxed(8u, (unsigned int *)(v2[1] + 24LL));
  }
  v5 = *(_DWORD **)(*v2 + 16LL);
  if ( v5 )
  {
    if ( *(v5 - 1) != 1427797680 )
      __break(0x8228u);
    v6 = ((__int64 (__fastcall *)(_QWORD *, __int64))v5)(v2, 12);
  }
  else
  {
    v6 = readl_relaxed((unsigned int *)(v2[1] + 12LL));
  }
  v7 = *(_DWORD **)(*v2 + 8LL);
  if ( v7 )
  {
    if ( *(v7 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v7)(v2, v6 | 0x100u, 12);
  }
  else
  {
    writel_relaxed(v6 | 0x100, (unsigned int *)(v2[1] + 12LL));
  }
  v8 = *(_DWORD **)(*v2 + 16LL);
  if ( !v8 )
  {
    if ( (readl_relaxed((unsigned int *)(v2[1] + 12LL)) & 0x100) == 0 )
      goto LABEL_27;
    goto LABEL_11;
  }
  if ( *(v8 - 1) != 1427797680 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(_QWORD *, __int64))v8)(v2, 12) & 0x100) != 0 )
  {
LABEL_11:
    memset(v25, 0, 40);
    init_wait_entry(v25, 0);
    for ( i = 6; ; i = schedule_timeout(v13) )
    {
      prepare_to_wait_event(v2 + 20, v25, 2);
      v10 = *(_DWORD **)(*v2 + 16LL);
      if ( v10 )
      {
        if ( *(v10 - 1) != 1427797680 )
          __break(0x8228u);
        v11 = ((__int64 (__fastcall *)(_QWORD *, __int64))v10)(v2, 12);
      }
      else
      {
        v11 = readl_relaxed((unsigned int *)(v2[1] + 12LL));
      }
      v12 = !i && (v11 & 0x100) == 0;
      v13 = v12 ? 1LL : i;
      if ( (v11 & 0x100) == 0 || !v13 )
        break;
    }
    finish_wait(v2 + 20, v25);
  }
LABEL_27:
  v14 = *(_DWORD **)(*v2 + 8LL);
  if ( v14 )
  {
    if ( *(v14 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v14)(v2, 0, 20);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(v2[1] + 20LL));
  }
  v15 = *(_DWORD **)(*v2 + 8LL);
  if ( v15 )
  {
    if ( *(v15 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v15)(v2, 0, 24);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(v2[1] + 24LL));
  }
  v16 = *(_DWORD **)(*v2 + 16LL);
  if ( !v16 )
  {
    v17 = readl_relaxed((unsigned int *)(v2[1] + 12LL));
    if ( (v17 & 0x100) == 0 )
      goto LABEL_33;
    goto LABEL_59;
  }
  if ( *(v16 - 1) != 1427797680 )
    __break(0x8228u);
  v17 = ((__int64 (__fastcall *)(_QWORD *, __int64))v16)(v2, 12);
  if ( (v17 & 0x100) != 0 )
  {
LABEL_59:
    v23 = a1[15];
    v24 = v17;
    if ( !v23 )
      v23 = a1[1];
    printk(&unk_A098, v23, v18, v19, v20);
    v17 = v24;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return (v17 & 0x100) == 0;
}
