__int64 __fastcall rmnet_sch_init(__int64 a1)
{
  __int64 v2; // x10
  unsigned int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  __int64 v7; // x9
  unsigned int v8; // kr0C_4

  v2 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 408) = 0x4000000000008LL;
  v4 = *(_DWORD *)(*(_QWORD *)v2 + 1112LL);
  *(_QWORD *)(a1 + 448) = 0x2000000000006LL;
  v4 /= 0xAu;
  *(_DWORD *)(a1 + 416) = 4 * v4;
  *(_DWORD *)(a1 + 420) = 8 * v4;
  v5 = *(_DWORD *)(*(_QWORD *)v2 + 1112LL);
  *(_QWORD *)(a1 + 488) = 0x1000000000004LL;
  *(_DWORD *)(a1 + 456) = 3 * (v5 / 0xA);
  *(_DWORD *)(a1 + 460) = 6 * (v5 / 0xA);
  v6 = *(_DWORD *)(*(_QWORD *)v2 + 1112LL);
  *(_QWORD *)(a1 + 528) = 0x800000000002LL;
  v6 /= 0xAu;
  *(_DWORD *)(a1 + 496) = 2 * v6;
  *(_DWORD *)(a1 + 500) = 4 * v6;
  v7 = *(_QWORD *)v2;
  LODWORD(v2) = *(_DWORD *)(a1 + 16);
  v8 = *(_DWORD *)(v7 + 1112);
  *(_DWORD *)(a1 + 536) = v8 / 0xA;
  *(_DWORD *)(a1 + 16) = v2 | 4;
  *(_DWORD *)(a1 + 540) = 2 * (v8 / 0xA);
  return 0;
}
