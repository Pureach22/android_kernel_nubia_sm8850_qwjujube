__int64 __fastcall sde_init_scaler_blk(__int64 result, unsigned int a2)
{
  if ( result )
  {
    *(_DWORD *)(result + 32) = a2;
    *(_QWORD *)(result + 36) = 0x200000004LL;
    if ( a2 >> 12 <= 2 )
      *(_DWORD *)(result + 40) = 3;
  }
  return result;
}
