__int64 __fastcall tpd_get_sensibility_level(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 3072);
  *(_BYTE *)(a1 + 64) = *(_DWORD *)(v1 + 1532);
  return 0;
}
