__int64 __fastcall ipa3_skb_recycle(__int64 result)
{
  __int64 v1; // x9
  __int64 v2; // x8

  v1 = *(_QWORD *)(result + 216) + *(unsigned int *)(result + 212);
  *(_QWORD *)(v1 + 16) = 0;
  *(_QWORD *)(v1 + 24) = 0;
  *(_QWORD *)v1 = 0;
  *(_QWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 32) = 1;
  v2 = *(_QWORD *)(result + 216);
  *(_QWORD *)(result + 192) = 0;
  *(_QWORD *)(result + 200) = 0;
  *(_QWORD *)(result + 176) = 0;
  *(_QWORD *)(result + 184) = 0;
  *(_QWORD *)(result + 160) = 0;
  *(_QWORD *)(result + 168) = 0;
  *(_QWORD *)(result + 224) = v2 + 64;
  *(_QWORD *)(result + 144) = 0;
  *(_QWORD *)(result + 152) = 0;
  *(_QWORD *)(result + 128) = 0;
  *(_QWORD *)(result + 136) = 0;
  *(_QWORD *)(result + 112) = 0;
  *(_QWORD *)(result + 120) = 0;
  *(_QWORD *)(result + 96) = 0;
  *(_QWORD *)(result + 104) = 0;
  *(_QWORD *)(result + 80) = 0;
  *(_QWORD *)(result + 88) = 0;
  *(_QWORD *)(result + 64) = 0;
  *(_QWORD *)(result + 72) = 0;
  *(_QWORD *)(result + 48) = 0;
  *(_QWORD *)(result + 56) = 0;
  *(_QWORD *)(result + 32) = 0;
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 16) = 0;
  *(_QWORD *)(result + 24) = 0;
  *(_QWORD *)result = 0;
  *(_QWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 208) = 64;
  return result;
}
