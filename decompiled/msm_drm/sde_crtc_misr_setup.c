__int64 __fastcall sde_crtc_misr_setup(__int64 result, char a2, int a3)
{
  __int64 v4; // x19
  unsigned __int64 v5; // x23
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x22
  void *v10; // x0
  const char *v11; // x1
  void *v12; // x0
  __int64 (__fastcall *v13)(_QWORD); // x8
  unsigned __int64 v14; // x8
  __int64 *v15; // x24
  __int64 (*v16)(void); // x9

  if ( !result )
  {
    v12 = &unk_215A31;
    return printk(v12, "sde_crtc_misr_setup");
  }
  v4 = result;
  LOBYTE(v5) = a2 & 1;
  if ( !*(_QWORD *)result )
    goto LABEL_9;
  v6 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v6 )
    goto LABEL_9;
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
  {
    v10 = &unk_234896;
    v11 = "_sde_crtc_get_kms";
    goto LABEL_12;
  }
  v8 = *(_QWORD *)(v7 + 152);
  if ( !v8 || (*(_QWORD *)(v8 + 22008) & 0x8000000000000LL) == 0 )
    goto LABEL_13;
  v9 = *(unsigned int *)(v6 + 5912);
  *(_DWORD *)(result + 7360) = a3;
  *(_BYTE *)(result + 7356) = v5;
  if ( (unsigned int)v9 < 3 )
    goto LABEL_14;
  while ( 1 )
  {
    __break(0x5512u);
LABEL_9:
    v10 = &unk_25E167;
    v11 = "sde_crtc_get_disp_op";
LABEL_12:
    result = printk(v10, v11);
LABEL_13:
    v9 = 0;
    *(_DWORD *)(v4 + 7360) = a3;
    *(_BYTE *)(v4 + 7356) = v5;
LABEL_14:
    v13 = *(__int64 (__fastcall **)(_QWORD))(v4 + 8 * v9 + 8400);
    if ( v13 )
      break;
    v14 = *(unsigned int *)(v4 + 2192);
    if ( !(_DWORD)v14 )
      return result;
    v5 = 0;
    v15 = (__int64 *)(v4 + 2200);
    while ( v5 != 9 )
    {
      result = *v15;
      if ( *v15 )
      {
        v16 = *(__int64 (**)(void))(result + 8 * v9 + 232);
        if ( v16 )
        {
          if ( *((_DWORD *)v16 - 1) != -1095415463 )
            __break(0x8229u);
          result = v16();
          v14 = *(unsigned int *)(v4 + 2192);
        }
      }
      ++v5;
      v15 += 6;
      if ( v5 >= v14 )
        return result;
    }
  }
  if ( *((_DWORD *)v13 - 1) != 877270196 )
    __break(0x8228u);
  result = v13(v4);
  if ( (_DWORD)result )
  {
    v12 = &unk_27D25B;
    return printk(v12, "sde_crtc_misr_setup");
  }
  return result;
}
