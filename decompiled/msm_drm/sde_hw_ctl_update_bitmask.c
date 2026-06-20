__int64 __fastcall sde_hw_ctl_update_bitmask(__int64 a1, int a2, int a3, char a4)
{
  int v4; // w10
  unsigned int v5; // w8
  __int64 v6; // x8
  _DWORD *v7; // x9
  _DWORD *v8; // x9
  void *v10; // x0
  const char *v11; // x1

  if ( !a1 )
    return (unsigned int)-22;
  if ( !a2 )
  {
    if ( (unsigned int)(a3 - 5) > 0xFFFFFFFD )
    {
      v6 = *(unsigned int *)(a1 + 96);
      if ( (a4 & 1) != 0 )
      {
        v7 = &wb_tbl;
        goto LABEL_17;
      }
      v8 = &wb_tbl;
LABEL_21:
      LODWORD(v8) = ~(1 << v8[a3]) & v6;
      goto LABEL_22;
    }
    v10 = &unk_26305C;
    v11 = "sde_hw_ctl_update_bitmask_wb";
LABEL_27:
    printk(v10, v11);
    return (unsigned int)-22;
  }
  if ( a2 == 7 )
  {
    if ( (unsigned int)(a3 - 6) > 0xFFFFFFFA )
    {
      v6 = *(unsigned int *)(a1 + 96);
      if ( (a4 & 1) != 0 )
      {
        v7 = &intf_tbl;
LABEL_17:
        v8 = (_DWORD *)((1LL << v7[a3]) | v6);
LABEL_22:
        v5 = 0;
        *(_DWORD *)(a1 + 96) = (_DWORD)v8;
        return v5;
      }
      v8 = &intf_tbl;
      goto LABEL_21;
    }
    v10 = &unk_243B78;
    v11 = "sde_hw_ctl_update_bitmask_intf";
    goto LABEL_27;
  }
  if ( a2 != 4 )
    return 0;
  if ( a3 != 1 )
  {
    v10 = &unk_270E9D;
    v11 = "sde_hw_ctl_update_bitmask_cdm";
    goto LABEL_27;
  }
  if ( (a4 & 1) != 0 )
    v4 = 0x4000000;
  else
    v4 = 0;
  v5 = 0;
  *(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 96) & 0xFBFFFFFF | v4;
  return v5;
}
