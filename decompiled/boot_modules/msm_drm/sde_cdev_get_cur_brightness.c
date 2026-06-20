__int64 __fastcall sde_cdev_get_cur_brightness(__int64 a1, unsigned __int64 *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = (*(int *)(*(_QWORD *)(v2 + 80) + 4LL) - *(_QWORD *)(v2 + 88)) / (unsigned __int64)*(unsigned int *)(v2 + 96);
  return 0;
}
