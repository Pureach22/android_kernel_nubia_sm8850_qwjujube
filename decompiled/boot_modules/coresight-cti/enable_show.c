__int64 __fastcall enable_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x20
  int v5; // w21
  int v6; // w22
  unsigned int v7; // w23
  __int64 v8; // x2

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 56);
  v5 = *(_DWORD *)(v4 + 72);
  v6 = *(unsigned __int8 *)(v4 + 77);
  v7 = *(unsigned __int8 *)(v4 + 76);
  raw_spin_unlock(v4 + 56);
  if ( v6 )
    v8 = v7;
  else
    v8 = v5 != 0;
  return sprintf(a3, "%d\n", v8);
}
