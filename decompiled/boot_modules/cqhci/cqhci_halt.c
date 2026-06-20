__int64 __fastcall cqhci_halt(_QWORD *a1, unsigned int a2)
{
  _QWORD *v4; // x20
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  _DWORD *v6; // x8
  _DWORD *v7; // x8
  _DWORD *v8; // x8
  int v9; // w0
  _DWORD *v10; // x8
  __int64 v11; // x22
  _DWORD *v12; // x8
  __int64 v13; // x21
  _DWORD *v14; // x8
  char v15; // w0
  __int64 v16; // x8
  _DWORD *v17; // x8
  _DWORD *v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x1
  _QWORD v26[6]; // [xsp+0h] [xbp-30h] BYREF

  v26[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (_QWORD *)a1[183];
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*v4 + 16LL);
  if ( v5 )
  {
    v24 = a1[183];
    if ( *((_DWORD *)v5 - 1) != 1427797680 )
      __break(0x8228u);
    if ( (v5(v24, 12) & 1) != 0 )
      goto LABEL_33;
  }
  else if ( (readl_relaxed((unsigned int *)(v4[1] + 12LL)) & 1) != 0 )
  {
LABEL_33:
    result = 1;
    goto LABEL_34;
  }
  v6 = *(_DWORD **)(*v4 + 8LL);
  if ( v6 )
  {
    if ( *(v6 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64, __int64))v6)(v4, 1, 20);
  }
  else
  {
    writel_relaxed(1u, (unsigned int *)(v4[1] + 20LL));
  }
  v7 = *(_DWORD **)(*v4 + 8LL);
  if ( v7 )
  {
    if ( *(v7 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64, __int64))v7)(v4, 1, 24);
  }
  else
  {
    writel_relaxed(1u, (unsigned int *)(v4[1] + 24LL));
  }
  v8 = *(_DWORD **)(*v4 + 16LL);
  if ( v8 )
  {
    if ( *(v8 - 1) != 1427797680 )
      __break(0x8228u);
    v9 = ((__int64 (__fastcall *)(_QWORD *, __int64))v8)(v4, 12);
  }
  else
  {
    v9 = readl_relaxed((unsigned int *)(v4[1] + 12LL));
  }
  v10 = *(_DWORD **)(*v4 + 8LL);
  if ( v10 )
  {
    if ( *(v10 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v10)(v4, v9 | 1u, 12);
  }
  else
  {
    writel_relaxed(v9 | 1, (unsigned int *)(v4[1] + 12LL));
  }
  v11 = _msecs_to_jiffies(a2);
  v12 = *(_DWORD **)(*v4 + 16LL);
  if ( !v12 )
  {
    if ( (readl_relaxed((unsigned int *)(v4[1] + 12LL)) & 1) != 0 )
      goto LABEL_27;
    goto LABEL_13;
  }
  if ( *(v12 - 1) != 1427797680 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(_QWORD *, __int64))v12)(v4, 12) & 1) == 0 )
  {
LABEL_13:
    if ( v11 != -1 )
    {
      memset(v26, 0, 40);
      v13 = _msecs_to_jiffies(a2) + 1;
      init_wait_entry(v26, 0);
      while ( 1 )
      {
        prepare_to_wait_event(v4 + 20, v26, 2);
        v14 = *(_DWORD **)(*v4 + 16LL);
        if ( v14 )
        {
          if ( *(v14 - 1) != 1427797680 )
            __break(0x8228u);
          v15 = ((__int64 (__fastcall *)(_QWORD *, __int64))v14)(v4, 12);
        }
        else
        {
          v15 = readl_relaxed((unsigned int *)(v4[1] + 12LL));
        }
        v16 = (v15 & 1 & (v13 == 0)) != 0 ? 1LL : v13;
        if ( (v15 & 1) != 0 || !v16 )
          break;
        v13 = schedule_timeout(v16);
      }
      finish_wait(v4 + 20, v26);
    }
  }
LABEL_27:
  v17 = *(_DWORD **)(*v4 + 8LL);
  if ( v17 )
  {
    if ( *(v17 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v17)(v4, 0, 20);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(v4[1] + 20LL));
  }
  v18 = *(_DWORD **)(*v4 + 8LL);
  if ( v18 )
  {
    if ( *(v18 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v18)(v4, 0, 24);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(v4[1] + 24LL));
  }
  v19 = *(_DWORD **)(*v4 + 16LL);
  if ( v19 )
  {
    if ( *(v19 - 1) != 1427797680 )
      __break(0x8228u);
    if ( (((__int64 (__fastcall *)(_QWORD *, __int64))v19)(v4, 12) & 1) != 0 )
      goto LABEL_33;
  }
  else if ( (readl_relaxed((unsigned int *)(v4[1] + 12LL)) & 1) != 0 )
  {
    goto LABEL_33;
  }
  v25 = a1[15];
  if ( !v25 )
    v25 = a1[1];
  printk(&unk_9E17, v25, v20, v21, v22);
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
