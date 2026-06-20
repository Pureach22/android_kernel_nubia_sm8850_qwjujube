__int64 __fastcall sde_vbif_setup_clk_force_ctrl(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x21
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 (*v8)(void); // x8
  char v9; // w20
  int v10; // w4
  __int64 v11; // x0
  __int64 (__fastcall *v12)(_QWORD); // x9

  if ( a2 >= 0x14 )
    goto LABEL_15;
  v3 = a2;
  v5 = a1 + 32LL * a2;
  if ( (*(_QWORD *)(*(_QWORD *)(a1 + 152) + 22008LL) & 0x8000000000LL) == 0 )
  {
    v6 = *(_QWORD *)(a1 + 3528);
    v7 = *(unsigned int *)(v6 + 28);
    if ( (unsigned int)v7 <= 2 )
    {
      v8 = *(__int64 (**)(void))(v6 + 8 * v7 + 152);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != -6776909 )
          __break(0x8228u);
        v9 = v8();
        v10 = 0;
      }
      else
      {
        v10 = 0;
        v9 = 0;
      }
      goto LABEL_12;
    }
LABEL_15:
    __break(0x5512u);
    JUMPOUT(0x13D6EC);
  }
  v11 = *(_QWORD *)(v5 + 2872);
  v12 = *(__int64 (__fastcall **)(_QWORD))(v5 + 2888);
  if ( *((_DWORD *)v12 - 1) != -721445518 )
    __break(0x8229u);
  v9 = v12(v11);
  v10 = 1;
LABEL_12:
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "split_vbif:%d type:%s en:%d rc:%d\n", v10, sde_clk_ctrl_type_s[v3], a3 & 1, v9 & 1);
  return v9 & 1;
}
