__int64 __fastcall sde_vbif_clk_register(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x11

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = *(unsigned int *)(a2 + 8);
      if ( (unsigned int)(v4 - 1) <= 0x12 )
      {
        v5 = a1 + 32 * v4;
        *(_QWORD *)(v5 + 2872) = *(_QWORD *)a2;
        *(_DWORD *)(v5 + 2880) = v4;
        v6 = *(_QWORD *)(a2 + 16);
        *(_QWORD *)(v5 + 2896) = *(_QWORD *)(a2 + 24);
        *(_QWORD *)(v5 + 2888) = v6;
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "registering hw:%pK clk_ctrl:%s\n", *(const void **)a2, sde_clk_ctrl_type_s[v4]);
        return 0;
      }
    }
  }
  return result;
}
