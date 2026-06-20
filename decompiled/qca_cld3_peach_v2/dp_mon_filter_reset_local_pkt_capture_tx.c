__int64 __fastcall dp_mon_filter_reset_local_pkt_capture_tx(__int64 result)
{
  __int64 v1; // x8
  __int64 *v2; // x9
  __int64 v3; // x8

  v1 = *(_QWORD *)(result + 96456) + 39328LL;
  v2 = *(__int64 **)v1;
  *(_DWORD *)(v1 + 24) = 0;
  *(_DWORD *)(v1 + 2600) = 0;
  *(_BYTE *)(v1 + 8) = 0;
  v3 = *v2;
  *(_BYTE *)(v3 + 716) = 1;
  *(_DWORD *)(v3 + 712) = 0;
  *(_QWORD *)(v3 + 704) = 0;
  *(_QWORD *)(v3 + 696) = 0;
  *(_QWORD *)(v3 + 688) = 0;
  *(_QWORD *)(v3 + 680) = 0;
  *(_QWORD *)(v3 + 672) = 0;
  *(_QWORD *)(v3 + 664) = 0;
  *(_QWORD *)(v3 + 656) = 0;
  *(_QWORD *)(v3 + 648) = 0;
  *(_QWORD *)(v3 + 640) = 0;
  *(_QWORD *)(v3 + 632) = 0;
  *(_QWORD *)(v3 + 624) = 0;
  *(_QWORD *)(v3 + 616) = 0;
  *(_QWORD *)(v3 + 608) = 0;
  *(_QWORD *)(v3 + 600) = 0;
  *(_QWORD *)(v3 + 592) = 0;
  *(_QWORD *)(v3 + 584) = 0;
  *(_QWORD *)(v3 + 576) = 0;
  *(_WORD *)(v3 + 717) = 0;
  *(_BYTE *)(v3 + 719) = 0;
  return result;
}
