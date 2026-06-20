__int64 __fastcall sde_cdev_get_max_brightness(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2 + 80) + 4LL) / *(_DWORD *)(v2 + 96));
  return 0;
}
