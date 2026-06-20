unsigned __int64 __fastcall kgsl_ioctl_drawctxt_create(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 (*v5)(void); // x8
  unsigned __int64 result; // x0
  unsigned __int64 v7; // x21

  v3 = *a1;
  v5 = *(__int64 (**)(void))(*(_QWORD *)(*a1 + 8752) + 120LL);
  if ( *((_DWORD *)v5 - 1) != 1971271043 )
    __break(0x8228u);
  result = v5();
  v7 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (int)result;
  raw_write_lock(v3 + 11208);
  idr_replace(v3 + 11184, v7, *(unsigned int *)(v7 + 4));
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(v7 + 4);
  raw_write_unlock(v3 + 11208);
  return 0;
}
