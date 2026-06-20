__int64 __fastcall sde_setup_dspp_ad4(unsigned int *a1, unsigned int *a2)
{
  __int64 v3; // x10
  __int64 v4; // x11
  __int64 v5; // x1
  char *v6; // x9
  __int64 v7; // x2
  __int64 result; // x0
  const void *v9; // x3
  unsigned int v10; // w9
  __int64 (__fastcall *v11)(unsigned int *, unsigned int *); // x12
  int v12; // w9
  int v13; // w1
  int v14; // w4
  int v15; // w2
  int v16; // w3
  int v17; // w2
  unsigned int v18; // w3

  if ( !a1 || !a2 )
  {
    if ( a2 )
    {
      v9 = *((const void **)a2 + 1);
      return _drm_err("invalid dspp %pK cfg %pK hw_cfg %pK\n", a1, a2, v9);
    }
LABEL_12:
    v9 = nullptr;
    return _drm_err("invalid dspp %pK cfg %pK hw_cfg %pK\n", a1, a2, v9);
  }
  v3 = *((_QWORD *)a2 + 1);
  if ( !v3 )
    goto LABEL_12;
  v4 = *(_QWORD *)(v3 + 32);
  if ( !v4 )
    return _drm_err("invalid mixed info\n");
  v5 = a1[16];
  if ( (unsigned int)v5 > 4 )
    return _drm_err("ad4 not supported for dspp idx %d\n");
  if ( ((16 * ((9 * v5) & 0xFFFFFFFFFLL)) | 8uLL) > 0x2D0 )
    goto LABEL_37;
  v6 = (char *)&info + 144 * v5;
  if ( (v6[8] & 1) == 0 )
    return _drm_err("ad4 not supported for dspp idx %d\n");
  v7 = *a2;
  if ( (unsigned int)v7 >= 0xC )
    return _drm_err("invalid prop set %d\n", v7);
  v10 = *(_DWORD *)v6;
  if ( v10 >= 6 )
    return _drm_err("in max state for dspp idx %d\n");
  if ( 8 * v7 + 96 * (unsigned __int64)v10 > 0x23F )
  {
LABEL_37:
    __break(1u);
    JUMPOUT(0x1642E0);
  }
  v11 = (__int64 (__fastcall *)(unsigned int *, unsigned int *))*(&prop_set_func + 12 * v10 + v7);
  if ( !v11 )
    return _drm_err("prop set not implemented for state %d prop %d\n", v10, v7);
  v12 = *(_DWORD *)(v3 + 28);
  if ( (unsigned int)(v12 - 3) <= 0xFFFFFFFD )
    return _drm_err("invalid mixer cnt %d\n", v12);
  v13 = *(_DWORD *)(v4 + 380);
  v14 = *(_DWORD *)(v3 + 40);
  if ( v12 != 1 )
  {
LABEL_28:
    if ( v13 != v14 )
    {
      v17 = *(_DWORD *)(v4 + 376);
      v18 = *(_DWORD *)(v3 + 44);
      if ( v17 != v18 >> 1 )
        return _drm_err("dual_lm lmh %d lmw %d displayh %d displayw %d\n", v13, v17, v18, v14);
    }
    goto LABEL_30;
  }
  if ( v13 != v14 )
  {
    v15 = *(_DWORD *)(v4 + 376);
    v16 = *(_DWORD *)(v3 + 44);
    if ( v15 != v16 )
      return _drm_err("single_lm lmh %d lmw %d displayh %d displayw %d\n", v13, v15, v16, v14);
    goto LABEL_28;
  }
LABEL_30:
  if ( *((_DWORD *)v11 - 1) != -397620331 )
    __break(0x822Cu);
  result = v11(a1, a2);
  if ( (_DWORD)result )
    return _drm_err("op failed %d ret %d\n", *a2, (unsigned int)result);
  return result;
}
