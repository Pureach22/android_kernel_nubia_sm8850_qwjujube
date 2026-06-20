__int64 __fastcall set_ltm_thresh_feature(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  void (__fastcall *v3)(__int64, __int64); // x9
  __int64 v5; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v2 >= 3 )
  {
    __break(0x5512u);
    v5 = MEMORY[0x2525954]();
    return set_ltm_buffers_feature(v5);
  }
  else
  {
    v3 = *(void (__fastcall **)(__int64, __int64))(a1 + 8 * v2 + 712);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != 1841204718 )
        __break(0x8229u);
      v3(a1, a2);
      return 0;
    }
    else if ( (_DWORD)v2 == 1 )
    {
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
}
