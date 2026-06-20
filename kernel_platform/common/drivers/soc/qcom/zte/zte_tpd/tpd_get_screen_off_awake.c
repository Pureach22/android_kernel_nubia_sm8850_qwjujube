__int64 __fastcall tpd_get_screen_off_awake(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 3072);
  *(_DWORD *)(a1 + 1156) = *(_DWORD *)(v1 + 1520);
  return 0;
}
