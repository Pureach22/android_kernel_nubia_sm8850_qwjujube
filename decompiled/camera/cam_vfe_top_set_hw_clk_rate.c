__int64 __fastcall cam_vfe_top_set_hw_clk_rate(__int64 a1, unsigned __int64 a2, char a3, __int64 a4)
{
  unsigned int v6; // w22
  __int64 v7; // x24
  __int64 v8; // x20
  unsigned int *v9; // x25
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w23
  int clk_level; // w0
  __int64 v15; // x8
  int v17; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v18; // [xsp+38h] [xbp-18h] BYREF
  __int64 v19; // [xsp+40h] [xbp-10h]
  __int64 v20; // [xsp+48h] [xbp-8h]

  v6 = -1;
  v7 = a2;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 10408);
  v18 = 0;
  v19 = 0;
  v17 = -1;
  v9 = *(unsigned int **)(v8 + 3296);
  if ( *(_BYTE *)(v8 + 3200) == 1 )
  {
    v10 = *(unsigned int *)(v8 + 2872);
    if ( (unsigned int)v10 >= 0xA )
      goto LABEL_18;
    v11 = *(unsigned int *)(v8 + 2796);
    if ( (unsigned int)v11 > 0x1F )
      goto LABEL_18;
    v6 = *(_DWORD *)(a1 + 1068);
    v7 = *(int *)(v8 + (v10 << 7) + 4 * v11 + 1384);
  }
  if ( (debug_mdl & 0x2000008) == 0 || debug_priority )
    goto LABEL_7;
  v15 = *(unsigned int *)(v8 + 2796);
  if ( (unsigned int)v15 > 0x1F )
LABEL_18:
    __break(0x5512u);
  if ( (a3 & 1) != 0 )
    a4 = -1;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, unsigned int, unsigned __int64, __int64, __int64))cam_print_log)(
    3,
    debug_mdl & 0x2000008,
    4,
    "cam_vfe_top_set_hw_clk_rate",
    113,
    "Applying VFE:%d Clock name=%s idx=%d cesta_client_idx:%d req clk[high low]=[%lu %lu] req_id=%ld",
    *(unsigned int *)(a1 + 1068),
    *(_QWORD *)(v8 + 8 * v15 + 872),
    v15,
    v6,
    a2,
    v7,
    a4);
LABEL_7:
  v12 = cam_soc_util_set_src_clk_rate(v8, v6, a2, v7);
  if ( v12 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_set_hw_clk_rate",
      137,
      "VFE:%d cesta_client_idx:%d Failed to set the req clk rate[high low]: [%llu %llu] rc:%d",
      *(_DWORD *)(a1 + 1068),
      v6,
      a2,
      v7,
      v12);
  }
  else
  {
    *(_QWORD *)(a1 + 10416) = a2;
    clk_level = cam_soc_util_get_clk_level((_BYTE *)v8, v7, *(_DWORD *)(v8 + 2796), &v17);
    if ( clk_level )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_vfe_top_set_hw_clk_rate",
        125,
        "Failed to get clk level for %s with clk_rate %lu src_idx %d rc %d",
        *(const char **)(v8 + 24),
        a2,
        *(_DWORD *)(v8 + 2796),
        clk_level);
    }
    else
    {
      LODWORD(v18) = 0;
      LODWORD(v19) = v17;
      cam_cpas_update_ahb_vote(*v9, (__int64)&v18);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
