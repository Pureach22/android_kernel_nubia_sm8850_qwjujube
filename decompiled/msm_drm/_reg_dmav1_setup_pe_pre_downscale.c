__int64 __fastcall reg_dmav1_setup_pe_pre_downscale(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 (__fastcall *v7)(__int64, __int64, __int64); // x9
  unsigned int v8; // w21
  __int64 (__fastcall *v9)(__int64, __int64); // x8

  *(_DWORD *)(a2 + 4) = 0x80000000;
  v4 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v4 >= 3 )
    goto LABEL_14;
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 8 * v4 + 664);
  if ( v7 )
  {
    if ( *((_DWORD *)v7 - 1) != 1276075380 )
      __break(0x8229u);
    v8 = v7(a2, a1, a4);
    if ( v8 )
    {
LABEL_11:
      _drm_err("setting pre downscale params failed ret %d\n", v8);
      return v8;
    }
    LODWORD(v4) = *(_DWORD *)(a1 + 28);
    if ( (unsigned int)v4 > 2 )
    {
LABEL_14:
      __break(0x5512u);
      JUMPOUT(0x156208);
    }
  }
  v9 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8LL * (unsigned int)v4 + 112);
  if ( !v9 )
    return 0;
  if ( *((_DWORD *)v9 - 1) != -1482022988 )
    __break(0x8228u);
  v8 = v9(a2, a1);
  if ( v8 )
    goto LABEL_11;
  return v8;
}
