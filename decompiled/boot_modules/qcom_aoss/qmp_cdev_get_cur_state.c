__int64 __fastcall qmp_cdev_get_cur_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = *(unsigned __int8 *)(v2 + 24);
  return 0;
}
