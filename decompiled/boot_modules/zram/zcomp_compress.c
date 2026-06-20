__int64 __fastcall zcomp_compress(_QWORD *a1, __int64 a2, _DWORD *a3)
{
  *a3 = 0x2000;
  return crypto_comp_compress(a1[1], a2, 4096, *a1, a3);
}
