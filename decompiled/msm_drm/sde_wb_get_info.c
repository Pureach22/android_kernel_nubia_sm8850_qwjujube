__int64 __fastcall sde_wb_get_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  unsigned int *v4; // x9
  unsigned int v5; // w9
  unsigned int v6; // w10
  int v8; // w11

  if ( a2 && a3 )
  {
    v3 = *(_QWORD *)(a3 + 16);
    if ( v3 && (v4 = *(unsigned int **)(v3 + 48)) != nullptr )
    {
      v6 = *v4;
      v5 = v4[1];
      if ( v6 > v5 )
        v5 = v6;
    }
    else
    {
      v5 = 5120;
    }
    *(_QWORD *)a2 = 0;
    *(_QWORD *)(a2 + 8) = 0;
    *(_DWORD *)a2 = 15;
    *(_QWORD *)(a2 + 144) = 0;
    *(_QWORD *)(a2 + 152) = 0;
    *(_QWORD *)(a2 + 128) = 0;
    *(_QWORD *)(a2 + 136) = 0;
    *(_QWORD *)(a2 + 112) = 0;
    *(_QWORD *)(a2 + 120) = 0;
    *(_QWORD *)(a2 + 96) = 0;
    *(_QWORD *)(a2 + 104) = 0;
    *(_QWORD *)(a2 + 80) = 0;
    *(_QWORD *)(a2 + 88) = 0;
    *(_QWORD *)(a2 + 64) = 0;
    *(_QWORD *)(a2 + 72) = 0;
    *(_QWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 56) = 0;
    *(_QWORD *)(a2 + 32) = 0;
    *(_QWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    *(_DWORD *)(a2 + 12) = 1;
    v8 = *(_DWORD *)(a3 + 8);
    *(_BYTE *)(a2 + 24) = 1;
    *(_DWORD *)(a2 + 4) = 12;
    *(_DWORD *)(a2 + 16) = v8;
    *(_DWORD *)(a2 + 36) = v5;
    *(_DWORD *)(a2 + 40) = 5120;
    return 0;
  }
  else
  {
    printk(&unk_2579ED, "sde_wb_get_info");
    return 4294967274LL;
  }
}
