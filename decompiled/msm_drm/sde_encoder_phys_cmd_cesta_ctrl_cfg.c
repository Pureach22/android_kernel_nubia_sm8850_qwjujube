__int64 __fastcall sde_encoder_phys_cmd_cesta_ctrl_cfg(__int64 result, __int64 a2, _BYTE *a3, _BYTE *a4)
{
  __int64 v4; // x8
  char v5; // w9
  char v6; // w10
  int v7; // w11
  char v8; // w9
  __int64 v9; // x9

  v4 = *(_QWORD *)(result + 8);
  if ( v4 )
  {
    v4 = *(_QWORD *)(v4 + 2512);
    if ( v4 )
      LOBYTE(v4) = *(_QWORD *)(v4 + 1440) != 0;
  }
  v5 = *(_BYTE *)(*(_QWORD *)result + 798LL);
  *(_BYTE *)(a2 + 10) = 0;
  *(_BYTE *)a2 = 1;
  v6 = 0;
  v7 = *(_DWORD *)(result + 672);
  *(_BYTE *)(a2 + 11) = v4;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 4) = v7 - 1;
  if ( (v4 & 1) == 0 )
  {
    v8 = v5 ^ 1;
    if ( *(_DWORD *)(*(_QWORD *)(result + 512) + 2544LL) )
      v6 = 0;
    else
      v6 = v8;
  }
  *(_BYTE *)(a2 + 12) = v6;
  if ( (unsigned int)(*(_DWORD *)(result + 664) - 1) <= 1 )
    *(_BYTE *)(a2 + 9) = 1;
  *a3 = 1;
  v9 = *(_QWORD *)(result + 8);
  if ( v9 && (*(_BYTE *)(v9 + 4680) & 1) != 0 )
    LOBYTE(v4) = 1;
  *a4 = v4;
  return result;
}
