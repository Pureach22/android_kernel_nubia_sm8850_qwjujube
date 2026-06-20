unsigned __int64 __fastcall a6xx_hfi_init(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int64 result; // x0
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x20
  int v7; // w21
  int v8; // w22
  unsigned int v9; // w8
  __int64 v10; // x23
  int v11; // w8
  int v12; // w8
  int v13; // w8

  v2 = to_a6xx_gmu(a1);
  result = *(_QWORD *)(v2 + 40);
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
               a1,
               0,
               13144,
               4,
               0);
    *(_QWORD *)(v2 + 40) = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = to_a6xx_gmu(a1);
      v5 = *(_DWORD **)(a1 + 14264);
      v6 = *(_QWORD *)(v4 + 40);
      v7 = 10242;
      v8 = 2561;
      v9 = *v5 - 615;
      if ( v9 <= 0xF && ((1 << v9) & 0x801B) != 0 )
      {
        v7 = 10245;
        v8 = 2564;
      }
      v10 = *(_QWORD *)(v6 + 8);
      *(_QWORD *)v10 = 0xD200000000LL;
      *(_QWORD *)(v10 + 8) = 0xC00000006LL;
      *(_QWORD *)(v10 + 16) = 0x300000003LL;
      memset((void *)(v10 + 24), 0, 0x330u);
      v11 = *(_DWORD *)(v6 + 184);
      *(_QWORD *)(v10 + 32) = 0x40000000A00LL;
      *(_DWORD *)(v10 + 24) = 1;
      *(_DWORD *)(v10 + 28) = v11 + 848;
      v12 = *(_DWORD *)(v6 + 184);
      *(_DWORD *)(v10 + 80) = v8;
      *(_DWORD *)(v10 + 84) = 1024;
      *(_DWORD *)(v10 + 72) = 1;
      *(_DWORD *)(v10 + 76) = v12 + 4944;
      v13 = *(_DWORD *)(v6 + 184);
      *(_DWORD *)(v10 + 128) = v7;
      *(_DWORD *)(v10 + 132) = 1024;
      *(_DWORD *)(v10 + 120) = 1;
      *(_DWORD *)(v10 + 124) = v13 + 9040;
      result = *(_QWORD *)(v2 + 40);
    }
  }
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 0;
  else
    return (unsigned int)result;
}
