__int64 __fastcall sde_hw_lm_setup_color3_v1(__int64 result, unsigned int a2)
{
  unsigned __int8 v2; // w10
  unsigned __int8 *v3; // x13
  __int64 v4; // x19
  __int64 v5; // x22
  __int64 v6; // x23
  unsigned __int64 v7; // x24
  __int64 v8; // x8
  unsigned int v9; // w21
  int v10; // w0

  if ( result )
  {
    v4 = result;
    v5 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 48LL) + 4LL);
    if ( (int)v5 >= 1 )
    {
      v6 = 0;
      v7 = a2;
      while ( 1 )
      {
        v8 = *(_QWORD *)(*(_QWORD *)(v4 + 40) + 48LL);
        if ( v6 + 1 > (unsigned __int64)*(unsigned int *)(v8 + 4) )
        {
LABEL_9:
          __break(0x800u);
          return result;
        }
        if ( v6 == 12 )
          break;
        v9 = *(_DWORD *)(v8 + 4 * v6 + 8);
        if ( (v9 & 0x80000000) != 0 )
          goto LABEL_9;
        v10 = sde_reg_read(v4, v9);
        result = sde_reg_write(
                   v4,
                   v9,
                   v10 & 0xBFFFFFFF | (((v7 >> ((unsigned __int8)v6++ + 1)) & 1) << 30),
                   "LM_BLEND0_OP + stage_off");
        if ( v5 == v6 )
          return result;
      }
      __break(0x5512u);
      __stxr(v2, v3);
      return sde_hw_lm_setup_color3();
    }
  }
  return result;
}
