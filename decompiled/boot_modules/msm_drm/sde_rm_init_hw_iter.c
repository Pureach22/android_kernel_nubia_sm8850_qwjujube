__int64 __fastcall sde_rm_init_hw_iter(__int64 result, int a2, int a3)
{
  *(_QWORD *)result = 0;
  *(_QWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 16) = a2;
  *(_DWORD *)(result + 20) = a3;
  return result;
}
