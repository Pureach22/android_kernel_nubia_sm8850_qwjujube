__int64 __fastcall wmi_recovery_notifier_call(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  int v5; // w10
  __int64 v6; // x9
  bool v7; // cf
  int v8; // w10
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned __int64 v11; // x10
  unsigned __int64 v12; // x10
  __int64 v13; // x9
  int v14; // w10
  __int64 v15; // x9
  int v16; // w10
  __int64 v17; // x8
  __int64 v18; // x8
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x10

  if ( a3 )
  {
    v3 = *(_QWORD *)(a1 + 24);
    if ( v3 )
    {
      if ( !*(_DWORD *)(v3 + 480) )
        goto LABEL_22;
      v4 = *(unsigned int *)(a3 + 8);
      if ( (unsigned int)(v4 - 178) < 0xFFFFFF3C )
        goto LABEL_22;
      v5 = **(_DWORD **)(v3 + 488);
      v6 = *(_QWORD *)a3 + v4;
      *(_WORD *)v6 = 1040;
      v7 = v5 != 0;
      v8 = v5 - 1;
      v9 = *(_QWORD *)(v3 + 472);
      if ( !v7 )
        v8 = 0;
      v10 = v9 + 32LL * v8;
      *(_DWORD *)(v6 + 2) = *(_DWORD *)v10;
      v11 = *(_QWORD *)(v10 + 24);
      v12 = 10 * v11 < v11 ? 10 * (v11 / 0xC0) : 10 * v11 / 0xC0;
      *(_QWORD *)(v6 + 10) = (unsigned __int64)((v12 * (unsigned __int128)0x10C6F7A0B5ED8D37uLL) >> 64) >> 16;
      *(_DWORD *)(v6 + 6) = *(_DWORD *)(v10 + 4);
      *(_DWORD *)(a3 + 8) += 18;
      v3 = *(_QWORD *)(a1 + 24);
      if ( v3 )
      {
LABEL_22:
        if ( *(_DWORD *)(v3 + 416) )
        {
          v13 = *(unsigned int *)(a3 + 8);
          if ( (unsigned int)(v13 - 178) >= 0xFFFFFF3C )
          {
            v14 = **(_DWORD **)(v3 + 424);
            v15 = *(_QWORD *)a3 + v13;
            *(_WORD *)v15 = 1296;
            v7 = v14 != 0;
            v16 = v14 - 1;
            v17 = *(_QWORD *)(v3 + 408);
            if ( !v7 )
              v16 = 0;
            v18 = v17 + 32LL * v16;
            *(_DWORD *)(v15 + 2) = *(_DWORD *)v18;
            v19 = *(_QWORD *)(v18 + 24);
            if ( 10 * v19 < v19 )
              v20 = 10 * (v19 / 0xC0);
            else
              v20 = 10 * v19 / 0xC0;
            *(_QWORD *)(v15 + 10) = (unsigned __int64)((v20 * (unsigned __int128)0x10C6F7A0B5ED8D37uLL) >> 64) >> 16;
            *(_DWORD *)(v15 + 6) = *(_DWORD *)(v18 + 4);
            *(_DWORD *)(a3 + 8) += 18;
          }
        }
      }
    }
  }
  return 1;
}
