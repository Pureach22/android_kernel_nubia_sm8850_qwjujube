__int64 __fastcall cqhci_crypto_program_key(__int64 a1, __int64 a2, int a3)
{
  __int64 (*v5)(void); // x9
  void (*v7)(void); // x8
  __int64 v8; // x22
  unsigned int v9; // w21
  __int64 i; // x23
  __int64 v11; // x0
  __int64 v12; // x2
  _DWORD *v13; // x8
  __int64 v14; // x0
  __int64 v15; // x2
  _DWORD *v16; // x8
  __int64 v17; // x0
  _DWORD *v18; // x8

  v5 = *(__int64 (**)(void))(*(_QWORD *)a1 + 64LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -1128170981 )
      __break(0x8229u);
    return v5();
  }
  else
  {
    v7 = *(void (**)(void))(*(_QWORD *)a1 + 8LL);
    v8 = (unsigned int)(*(_DWORD *)(a1 + 208) + (a3 << 7));
    v9 = v8 + 64;
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -1433747670 )
        __break(0x8228u);
      v7();
    }
    else
    {
      writel_relaxed_0(0, *(_QWORD *)(a1 + 8) + (int)v9);
    }
    for ( i = 0; i != 64; i += 4 )
    {
      v11 = *(unsigned int *)(a2 + i);
      v12 = v8 + i;
      v13 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
      if ( v13 )
      {
        if ( *(v13 - 1) != -1433747670 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v13)(a1, (unsigned int)v11, v12);
      }
      else
      {
        writel_relaxed_0(v11, *(_QWORD *)(a1 + 8) + (int)v12);
      }
    }
    v14 = *(unsigned int *)(a2 + 68);
    v15 = (unsigned int)(v8 + 68);
    v16 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
    if ( v16 )
    {
      if ( *(v16 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v16)(a1, (unsigned int)v14, v15);
    }
    else
    {
      writel_relaxed_0(v14, *(_QWORD *)(a1 + 8) + (int)v15);
    }
    v17 = *(unsigned int *)(a2 + 64);
    v18 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
    if ( v18 )
    {
      if ( *(v18 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v18)(a1, (unsigned int)v17, v9);
    }
    else
    {
      writel_relaxed_0(v17, *(_QWORD *)(a1 + 8) + (int)v9);
    }
    return 0;
  }
}
