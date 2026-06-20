__int64 __fastcall msm_ssphy_qmp_notify_connect(_BYTE *a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(*(_QWORD *)a1 + 592LL);
  if ( v1 && (a1[16] & 1) != 0 )
    *(_DWORD *)(v1 + 520) |= 0xCu;
  a1[546] = 1;
  atomic_notifier_call_chain(a1 + 224, 1);
  return 0;
}
