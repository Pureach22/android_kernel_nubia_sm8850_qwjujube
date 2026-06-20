__int64 __fastcall sde_hw_ctl_reset_post_disable(unsigned int *a1, _DWORD *a2, int a3)
{
  __int64 v3; // d19
  __int64 v4; // d29
  int v6; // w8
  int v8; // w9
  unsigned int v9; // w21
  int v10; // w8
  int v11; // w8
  unsigned int v12; // w22
  int v13; // w8
  int v14; // w9
  __int64 v15; // x8
  void (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w8
  int v19; // w8
  int v20; // w8
  int v21; // w8

  if ( !a1 || !a2 )
  {
    printk(&unk_24A0F9, "sde_hw_ctl_reset_post_disable");
    return 4294967274LL;
  }
  v6 = *a2;
  if ( *a2 )
  {
    if ( (unsigned int)(v6 - 3) < 0xFFFFFFFE )
    {
LABEL_40:
      __break(0x5512u);
      *((_QWORD *)a2 - 47) = v3;
      *((_QWORD *)a2 - 46) = v4;
      return sde_hw_ctl_get_scheduler_status();
    }
    v8 = a2[1];
    if ( v8 )
      v9 = 1LL << ((unsigned __int8)v8 - 1);
    else
      v9 = 0;
    if ( v6 != 1 )
    {
      v10 = a2[2];
      if ( v10 )
        v11 = 1LL << ((unsigned __int8)v10 - 1);
      else
        v11 = 0;
      v9 |= v11;
    }
    v12 = a2[5];
    if ( !v12 )
    {
LABEL_14:
      v13 = a2[24];
      if ( !v13 )
        goto LABEL_15;
      goto LABEL_33;
    }
  }
  else
  {
    v9 = 0;
    v12 = a2[5];
    if ( !v12 )
      goto LABEL_14;
  }
  if ( v12 != 1 )
    goto LABEL_40;
  v19 = a2[6];
  if ( v19 )
    v12 = 1LL << ((unsigned __int8)v19 - 1);
  else
    v12 = 0;
  v13 = a2[24];
  if ( !v13 )
  {
LABEL_15:
    if ( !a3 )
      goto LABEL_17;
    goto LABEL_16;
  }
LABEL_33:
  if ( v13 != 1 )
    goto LABEL_40;
  v20 = a2[25];
  if ( v20 )
    v21 = 1LL << ((unsigned __int8)v20 + 15);
  else
    v21 = 0;
  v12 |= v21;
  if ( a3 )
  {
LABEL_16:
    v14 = a1[24] | 0x800000;
    a1[28] = 1LL << ((unsigned __int8)a3 - 1);
    a1[24] = v14;
    sde_reg_write(a1, 228, 0, "CTL_MERGE_3D_ACTIVE");
  }
LABEL_17:
  v15 = a1[7];
  if ( (unsigned int)v15 > 2 )
    goto LABEL_40;
  v16 = *(void (__fastcall **)(_QWORD))&a1[2 * v15 + 340];
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != 729814110 )
      __break(0x8228u);
    v16(a1);
  }
  if ( *a2 )
  {
    v17 = a1[24] | 0x80000000;
    a1[32] = v9;
    a1[24] = v17;
    sde_reg_write(a1, 244, 0, "CTL_INTF_ACTIVE");
  }
  if ( a2[5] )
  {
    a1[24] |= 0x10000u;
    a1[25] = v12;
    sde_reg_write(a1, 236, 0, "CTL_WB_ACTIVE");
  }
  return 0;
}
