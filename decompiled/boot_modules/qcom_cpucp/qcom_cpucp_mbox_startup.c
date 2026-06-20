__int64 __fastcall qcom_cpucp_mbox_startup(_QWORD *a1)
{
  __int64 v1; // x19
  unsigned int *v2; // x20
  __int64 v3; // x21
  __int64 v4; // x0

  v1 = *a1;
  v2 = *(unsigned int **)(*a1 + 152LL);
  if ( *((_BYTE *)v2 + 28) == 1 )
  {
    v3 = a1[30];
    v4 = readq((__int64 *)(*(_QWORD *)(v1 + 168) + *v2));
    writeq(v4 | (1LL << v3), (_QWORD *)(*(_QWORD *)(v1 + 168) + *v2));
  }
  return 0;
}
