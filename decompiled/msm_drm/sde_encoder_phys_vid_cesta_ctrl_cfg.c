__int64 __fastcall sde_encoder_phys_vid_cesta_ctrl_cfg(__int64 result, __int64 a2, _BYTE *a3, _BYTE *a4)
{
  __int64 v4; // x8
  int v5; // w10
  __int64 v6; // x8

  v4 = *(_QWORD *)(result + 8);
  if ( v4 )
    LODWORD(v4) = *(_DWORD *)(v4 + 4676) != 0;
  *(_BYTE *)(a2 + 10) = v4;
  *(_BYTE *)a2 = 1;
  v5 = *(_DWORD *)(result + 672);
  *(_BYTE *)(a2 + 11) = 1;
  *(_DWORD *)(a2 + 4) = v5 - 1;
  *(_DWORD *)(a2 + 16) = v4 ^ 1;
  *(_BYTE *)(a2 + 12) = *(_DWORD *)(*(_QWORD *)(result + 512) + 2544LL) == 0;
  if ( (unsigned int)(*(_DWORD *)(result + 664) - 1) <= 1 )
    *(_BYTE *)(a2 + 9) = 1;
  *a3 = v4;
  v6 = *(_QWORD *)(result + 8);
  if ( v6 )
    LOBYTE(v6) = *(_BYTE *)(v6 + 4680);
  *a4 = v6;
  return result;
}
