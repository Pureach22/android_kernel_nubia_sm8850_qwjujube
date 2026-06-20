__int64 __fastcall syna_tcm_clear_command_processing(__int64 result)
{
  __int64 (*v1)(__int64, __int64, __int64); // x8

  if ( result )
  {
    v1 = *(__int64 (**)(__int64, __int64, __int64))(result + 928);
    if ( v1 )
    {
      if ( *((_DWORD *)v1 - 1) != -1686231200 )
        __break(0x8228u);
      return v1(result, 0, 0);
    }
  }
  return result;
}
