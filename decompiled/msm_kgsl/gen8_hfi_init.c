unsigned __int64 __fastcall gen8_hfi_init(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v2 = to_gen8_gmu(a1);
  result = *(_QWORD *)(v2 + 48);
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
               a1,
               0,
               13144,
               4,
               0);
    *(_QWORD *)(v2 + 48) = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = *(_QWORD *)(to_gen8_gmu(a1) + 48);
      v5 = *(_QWORD *)(v4 + 8);
      *(_QWORD *)v5 = 0xD200000000LL;
      *(_QWORD *)(v5 + 8) = 0xC00000006LL;
      *(_QWORD *)(v5 + 16) = 0x300000003LL;
      memset((void *)(v5 + 24), 0, 0x330u);
      v6 = *(_DWORD *)(v4 + 184);
      *(_QWORD *)(v5 + 32) = 0x40000000A00LL;
      *(_DWORD *)(v5 + 24) = 1;
      *(_DWORD *)(v5 + 28) = v6 + 848;
      v7 = *(_DWORD *)(v4 + 184);
      *(_QWORD *)(v5 + 80) = 0x40000000A01LL;
      *(_DWORD *)(v5 + 72) = 1;
      *(_DWORD *)(v5 + 76) = v7 + 4944;
      v8 = *(_DWORD *)(v4 + 184);
      *(_QWORD *)(v5 + 128) = 0x40000002802LL;
      *(_DWORD *)(v5 + 120) = 1;
      *(_DWORD *)(v5 + 124) = v8 + 9040;
      result = *(_QWORD *)(v2 + 48);
    }
  }
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 0;
  else
    return (unsigned int)result;
}
