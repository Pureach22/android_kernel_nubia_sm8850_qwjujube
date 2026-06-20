__int64 __fastcall check_aiqe_ssrc_data(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x8
  __int64 v5; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v2 >= 3 )
  {
    __break(0x5512u);
    v5 = MEMORY[0x2597CE8]();
    return set_aiqe_ssrc_config(v5);
  }
  else
  {
    v3 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8 * v2 + 1264);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != 634699744 )
        __break(0x8228u);
      return v3(a1, a2);
    }
    else
    {
      return 0;
    }
  }
}
