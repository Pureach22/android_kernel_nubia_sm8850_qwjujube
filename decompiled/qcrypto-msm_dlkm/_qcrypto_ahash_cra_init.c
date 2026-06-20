__int64 __fastcall qcrypto_ahash_cra_init(__int64 a1)
{
  __int64 v1; // x10
  __int64 v3; // x9
  __int64 v4; // x9

  v1 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(a1 - 8) = 472;
  v3 = *(_QWORD *)(v1 + 840);
  *(_DWORD *)(a1 + 64) = 0;
  *(_QWORD *)(a1 + 144) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = v3;
  v4 = a1 + 32;
  *(_QWORD *)(a1 + 32) = a1 + 32;
  *(_QWORD *)(a1 + 40) = v4;
  return 0;
}
