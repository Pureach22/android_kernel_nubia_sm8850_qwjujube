__int64 __fastcall setup_recovery_req(__int64 a1)
{
  __int64 v2; // x22

  v2 = a1 + 69632;
  memset((void *)(a1 + 69776), 0, 0x1A0u);
  sg_init_one(a1 + 69856, a1 + 69776, 64);
  *(_QWORD *)(v2 + 312) = v2 + 472;
  *(_QWORD *)(v2 + 320) = 2;
  *(_QWORD *)(v2 + 408) = a1 + 69840;
  *(_QWORD *)(v2 + 416) = 16;
  *(_DWORD *)(v2 + 288) = 1;
  *(_QWORD *)(v2 + 296) = qce_recovery_complete;
  *(_QWORD *)(v2 + 304) = 0;
  *(_QWORD *)(v2 + 552) = a1;
  *(_QWORD *)(v2 + 488) = a1 + 69856;
  *(_QWORD *)(v2 + 496) = a1 + 69856;
  *(_DWORD *)(v2 + 472) = 64;
  *(_DWORD *)(v2 + 328) = 2;
  *(_QWORD *)(v2 + 400) = 0x500000010LL;
  *(_QWORD *)(v2 + 440) = 2;
  *(_DWORD *)(v2 + 424) = 64;
  *(_BYTE *)(v2 + 448) = 0;
  *(_DWORD *)(v2 + 456) = 0;
  *(_DWORD *)(v2 + 256) = 0;
  return _init_swait_queue_head(a1 + 69896, "&x->wait", &init_completion___key);
}
