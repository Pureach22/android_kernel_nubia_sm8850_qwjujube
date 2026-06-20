__int64 __fastcall sde_lb_display_get_info(__int64 a1, __int64 a2)
{
  if ( !a2 )
    return 4294967274LL;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 144) = 0;
  *(_QWORD *)(a2 + 152) = 0;
  *(_QWORD *)a2 = 0x800000000FLL;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 1;
  *(_BYTE *)(a2 + 24) = 1;
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
  return 0;
}
