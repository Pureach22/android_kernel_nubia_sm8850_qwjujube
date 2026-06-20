__int64 __fastcall qcom_cpucp_mbox_xlate(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x9
  unsigned __int64 *v4; // x9
  unsigned __int64 v5; // t1

  if ( *(_DWORD *)(a2 + 8) != 1 )
    return -22;
  v2 = *(unsigned int *)(a2 + 12);
  if ( v2 >= *(int *)(a1 + 24) )
    return -22;
  v3 = *(_QWORD *)(a1 + 16) + 248LL * (unsigned int)v2;
  v5 = *(_QWORD *)(v3 + 240);
  v4 = (unsigned __int64 *)(v3 + 240);
  if ( v5 < 0xFFFFFFFFFFFFF001LL )
    return -16;
  *v4 = v2;
  return *(_QWORD *)(a1 + 16) + 248LL * (unsigned int)v2;
}
