__int64 __fastcall sde_hw_pp_reset_3d_merge_mode(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 (__fastcall *v5)(__int64, __int64); // x8

  result = *(_QWORD *)(a1 + 56);
  if ( result )
  {
    v4 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v4 >= 3 )
    {
      __break(0x5512u);
      JUMPOUT(0x18FB3C);
    }
    v5 = *(__int64 (__fastcall **)(__int64, __int64))(result + 8 * v4 + 72);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != 166079319 )
        __break(0x8228u);
      return v5(result, a2);
    }
  }
  return result;
}
