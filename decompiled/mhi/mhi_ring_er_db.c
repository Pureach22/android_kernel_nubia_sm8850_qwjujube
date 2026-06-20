__int64 __fastcall mhi_ring_er_db(__int64 *a1)
{
  __int64 *v1; // x1
  __int64 (__fastcall *v2)(__int64, __int64 *, __int64, __int64); // x10
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x0

  v1 = a1 + 17;
  v2 = (__int64 (__fastcall *)(__int64, __int64 *, __int64, __int64))a1[20];
  v3 = a1[16];
  v4 = *(_QWORD *)a1[7];
  v5 = *a1;
  if ( *((_DWORD *)v2 - 1) != -396405511 )
    __break(0x822Au);
  return v2(v5, v1, v3, v4);
}
