__int64 __fastcall cvp_dsp_init_hfi_queue_hdr(__int64 result)
{
  __int64 v1; // x9
  __int64 v2; // x9
  __int64 v3; // x9
  _QWORD *v4; // x8
  __int64 v5; // x8
  int v6; // w10
  _DWORD *v7; // x8
  int v8; // w10

  v1 = *(_QWORD *)(result + 320);
  *(_QWORD *)(result + 1600) = v1 + 288;
  *(_DWORD *)(v1 + 288) = 1;
  *(_DWORD *)(v1 + 304) = 0;
  *(_QWORD *)(v1 + 296) = 0x3200001010000LL;
  *(_QWORD *)(v1 + 312) = 0x100000001LL;
  *(_DWORD *)(v1 + 320) = 1;
  *(_QWORD *)(v1 + 324) = 0;
  *(_QWORD *)(v1 + 332) = 0;
  *(_DWORD *)(v1 + 340) = 0;
  v2 = *(_QWORD *)(result + 320);
  *(_QWORD *)(result + 1792) = v2 + 344;
  *(_DWORD *)(v2 + 344) = 1;
  *(_QWORD *)(v2 + 352) = 0x3200001010000LL;
  *(_DWORD *)(v2 + 360) = 0;
  *(_QWORD *)(v2 + 368) = 0x100000001LL;
  *(_DWORD *)(v2 + 376) = 1;
  *(_QWORD *)(v2 + 380) = 0;
  *(_QWORD *)(v2 + 388) = 0;
  *(_DWORD *)(v2 + 396) = 0;
  v3 = *(_QWORD *)(result + 320);
  *(_QWORD *)(result + 1984) = v3 + 400;
  *(_DWORD *)(v3 + 400) = 1;
  *(_QWORD *)(v3 + 408) = 0x3200001010000LL;
  *(_DWORD *)(v3 + 416) = 0;
  *(_QWORD *)(v3 + 424) = 0x100000001LL;
  *(_DWORD *)(v3 + 432) = 1;
  *(_DWORD *)(v3 + 452) = 0;
  *(_QWORD *)(v3 + 436) = 0;
  *(_QWORD *)(v3 + 444) = 0;
  v4 = *(_QWORD **)(result + 320);
  v4[3] = result;
  v4[4] = 0x7076635F6D736DLL;
  *v4 = 0x1C800000000LL;
  v4[1] = 0x3800000120LL;
  v4[2] = 0x300000003LL;
  *(_DWORD *)(*(_QWORD *)(result + 1600) + 4LL) = *(_DWORD *)(result + 1608);
  v5 = *(_QWORD *)(result + 1792);
  v6 = *(_DWORD *)(v5 + 8) | 1;
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(result + 1800);
  *(_DWORD *)(v5 + 8) = v6;
  v7 = *(_DWORD **)(result + 1984);
  LODWORD(v3) = *(_DWORD *)(result + 1992);
  v8 = v7[2];
  v7[8] = 0;
  v7[1] = v3;
  v7[2] = v8 | 2;
  return result;
}
