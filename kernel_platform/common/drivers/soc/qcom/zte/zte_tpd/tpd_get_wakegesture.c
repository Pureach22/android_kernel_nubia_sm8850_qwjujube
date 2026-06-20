__int64 __fastcall tpd_get_wakegesture(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 3072);
  *(_DWORD *)a1 = *(_DWORD *)(v1 + 1476);
  return 0;
}
