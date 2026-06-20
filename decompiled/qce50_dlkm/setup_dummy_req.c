__int64 __fastcall setup_dummy_req(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 result; // x0

  v1 = a1 + 69568;
  qmemcpy(*(void **)(a1 + 70232), "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopqopqrpqrs", 64);
  v3 = a1 + 69664;
  result = sg_init_one(a1 + 69664, *(_QWORD *)(a1 + 70232), 64);
  *(_DWORD *)(v1 + 8) = 0;
  *(_QWORD *)v1 = qce_dummy_complete;
  *(_QWORD *)(v1 + 24) = v3;
  *(_QWORD *)(a1 + 69600) = 0;
  *(_QWORD *)(a1 + 69608) = 0;
  *(_WORD *)(v1 + 68) = 257;
  *(_DWORD *)(v1 + 72) = 64;
  *(_QWORD *)(v1 + 80) = a1 + 69696;
  *(_DWORD *)(v1 + 88) = 0;
  *(_QWORD *)(v1 + 56) = 0;
  *(_QWORD *)(v1 + 184) = v3;
  *(_DWORD *)(v1 + 176) = 64;
  return result;
}
