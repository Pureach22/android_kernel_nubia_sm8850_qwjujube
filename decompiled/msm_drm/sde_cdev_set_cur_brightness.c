__int64 __fastcall sde_cdev_set_cur_brightness(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v6; // x1

  v2 = *(_QWORD *)(a1 + 944);
  v3 = *(unsigned int *)(v2 + 96);
  v4 = *(int *)(*(_QWORD *)(v2 + 80) + 4LL);
  if ( (unsigned int)v4 / (unsigned int)v3 < a2 )
    return 4294967274LL;
  v6 = v4 - v3 * a2;
  if ( v6 != *(_QWORD *)(v2 + 88) )
  {
    *(_QWORD *)(v2 + 88) = v6;
    blocking_notifier_call_chain(v2, v6);
  }
  return 0;
}
