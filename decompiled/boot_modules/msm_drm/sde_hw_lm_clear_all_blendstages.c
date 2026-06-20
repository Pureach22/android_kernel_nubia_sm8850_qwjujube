__int64 __fastcall sde_hw_lm_clear_all_blendstages(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  unsigned __int8 *v4; // x13
  __int64 v5; // x22
  __int64 v6; // x8
  __int64 result; // x0

  if ( a1 )
  {
    v2 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL) + 4LL);
    if ( (v2 & 0x80000000) == 0 )
    {
      v3 = sde_reg_write(a1, 20, 49344, "LM_BG_SRC_SEL_V1");
      if ( !(_DWORD)v2 )
        return 0;
      v5 = 0;
      while ( 1 )
      {
        v6 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL);
        if ( v5 + 1 > (unsigned __int64)*(unsigned int *)(v6 + 4) )
          break;
        if ( v5 == 12 )
        {
          __break(0x5512u);
          __stxr(0xDu, v4);
          return sde_hw_lm_setup_color3_v1(v3);
        }
        result = *(unsigned int *)(v6 + 4 * v5 + 8);
        if ( (result & 0x80000000) != 0 )
          return result;
        v3 = sde_reg_write(a1, (unsigned int)(result + 4), 49344, "LM_BLEND0_FG_SRC_SEL_V1 + stage_off");
        if ( v2 == ++v5 )
          return 0;
      }
    }
  }
  return 4294967274LL;
}
