__int64 __fastcall sde_hw_sspp_setup_scaler3(__int64 result, __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x10

  if ( result )
  {
    if ( a2 )
    {
      if ( a4 )
      {
        v4 = *(_QWORD *)(result + 56);
        if ( v4 )
        {
          v5 = *(_QWORD *)(v4 + 48);
          if ( v5 )
            return sde_hw_setup_scaler3(
                     result,
                     a4,
                     *(_DWORD *)(v5 + 112),
                     *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 100LL),
                     *a2,
                     (*(_QWORD *)(v4 + 32) & 0x200000000LL) != 0);
        }
      }
    }
  }
  return result;
}
