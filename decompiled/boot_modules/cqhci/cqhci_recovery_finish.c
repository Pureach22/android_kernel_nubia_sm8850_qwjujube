__int64 __fastcall cqhci_recovery_finish(__int64 a1)
{
  _QWORD *v1; // x19
  char v3; // w21
  char v4; // w22
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  int v6; // w0
  _DWORD *v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  int v9; // w0
  char v10; // w21
  _DWORD *v11; // x8
  int v12; // w8
  __int64 v13; // x21
  __int64 i; // x22
  int v15; // w9
  __int64 v16; // x9
  __int64 v17; // x1
  __int64 v18; // x8
  int v19; // w8
  int v20; // w9
  __int64 v21; // x0
  void (__fastcall *v22)(__int64, __int64, __int64); // x8
  void (__fastcall *v23)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v24)(__int64, __int64, __int64); // x8

  v1 = *(_QWORD **)(a1 + 1464);
  if ( (*((_BYTE *)v1 + 61) & 1) == 0 )
    __break(0x800u);
  v3 = cqhci_halt(a1, 20);
  v4 = cqhci_clear_all_tasks(a1);
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*v1 + 16LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != 1427797680 )
      __break(0x8228u);
    v6 = v5((__int64)v1, 8);
  }
  else
  {
    v6 = readl_relaxed((unsigned int *)(v1[1] + 8LL));
  }
  v7 = *(_DWORD **)(*v1 + 8LL);
  if ( v7 )
  {
    if ( *(v7 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v7)(v1, v6 & 0xFFFFFFFE, 8);
  }
  else
  {
    writel_relaxed(v6 & 0xFFFFFFFE, (unsigned int *)(v1[1] + 8LL));
  }
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(*v1 + 16LL);
  if ( v8 )
  {
    if ( *((_DWORD *)v8 - 1) != 1427797680 )
      __break(0x8228u);
    v9 = v8((__int64)v1, 8);
  }
  else
  {
    v9 = readl_relaxed((unsigned int *)(v1[1] + 8LL));
  }
  v10 = v3 & v4;
  v11 = *(_DWORD **)(*v1 + 8LL);
  if ( v11 )
  {
    if ( *(v11 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v11)(v1, v9 | 1u, 8);
  }
  else
  {
    writel_relaxed(v9 | 1, (unsigned int *)(v1[1] + 8LL));
  }
  cqhci_halt(a1, 20);
  if ( (v10 & 1) == 0 )
    cqhci_clear_all_tasks(a1);
  v12 = *((_DWORD *)v1 + 9);
  if ( v12 >= 1 )
  {
    v13 = 0;
    for ( i = 0; i < v12; ++i )
    {
      v16 = v1[23];
      v17 = *(_QWORD *)(v16 + v13);
      if ( v17 )
      {
        *(_QWORD *)(v16 + v13) = 0;
        --*((_DWORD *)v1 + 10);
        v18 = *(_QWORD *)(v17 + 16);
        if ( v18 )
        {
          *(_DWORD *)(v18 + 28) = 0;
          v15 = *(_DWORD *)(v16 + v13 + 8);
          if ( v15 )
          {
            if ( (v15 & 4) != 0 )
            {
              v15 = -84;
            }
            else if ( (v15 & 9) != 0 )
            {
              v15 = -110;
            }
            else
            {
              v15 = -5;
            }
          }
          *(_DWORD *)(v18 + 20) = v15;
        }
        else
        {
          v19 = *(_DWORD *)(v16 + v13 + 8);
          if ( v19 )
          {
            if ( (v19 & 9) != 0 )
              v20 = -110;
            else
              v20 = -5;
            if ( (v19 & 4) != 0 )
              v19 = -84;
            else
              v19 = v20;
          }
          *(_DWORD *)(*(_QWORD *)(v17 + 8) + 32LL) = v19;
        }
        mmc_cqe_request_done(v1[2], v17);
        v12 = *((_DWORD *)v1 + 9);
      }
      v13 += 16;
    }
  }
  if ( *((_DWORD *)v1 + 10) )
    __break(0x800u);
  v21 = raw_spin_lock_irqsave(v1 + 3);
  *((_DWORD *)v1 + 10) = 0;
  *((_BYTE *)v1 + 61) = 0;
  *(_BYTE *)(a1 + 1477) = 0;
  raw_spin_unlock_irqrestore(v1 + 3, v21);
  __dsb(0xEu);
  v22 = *(void (__fastcall **)(__int64, __int64, __int64))(*v1 + 8LL);
  if ( v22 )
  {
    if ( *((_DWORD *)v22 - 1) != -1433747670 )
      __break(0x8228u);
    v22((__int64)v1, 9, 16);
  }
  else
  {
    writel_relaxed(9u, (unsigned int *)(v1[1] + 16LL));
  }
  v23 = *(void (__fastcall **)(__int64, __int64, __int64))(*v1 + 8LL);
  if ( v23 )
  {
    if ( *((_DWORD *)v23 - 1) != -1433747670 )
      __break(0x8228u);
    v23((__int64)v1, 54, 20);
  }
  else
  {
    writel_relaxed(0x36u, (unsigned int *)(v1[1] + 20LL));
  }
  v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*v1 + 8LL);
  if ( !v24 )
    return writel_relaxed(0x36u, (unsigned int *)(v1[1] + 24LL));
  if ( *((_DWORD *)v24 - 1) != -1433747670 )
    __break(0x8228u);
  return v24((__int64)v1, 54, 24);
}
