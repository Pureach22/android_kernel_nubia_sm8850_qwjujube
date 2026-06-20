__int64 __fastcall hfi_connector_add_base_prop_helper(int a1, __int64 a2, _QWORD *a3, int *a4)
{
  unsigned int v4; // w8
  __int64 v5; // x20
  __int64 v6; // x8
  int v8; // w2
  int v9; // w4
  int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = -22;
  if ( !a2 || !a3 || !a4 )
    goto LABEL_25;
  if ( *(_QWORD *)(a2 + 2512) )
  {
    v4 = -22;
    goto LABEL_25;
  }
  v5 = *(_QWORD *)(a2 + 5136);
  if ( a1 <= 131083 )
  {
    if ( a1 == 131082 )
    {
      v6 = a3[148];
      goto LABEL_17;
    }
    if ( a1 == 131083 )
    {
      v6 = a3[192];
      goto LABEL_17;
    }
LABEL_26:
    printk(&unk_22DD04, "_hfi_connector_add_base_prop_helper");
    v4 = -22;
    goto LABEL_25;
  }
  if ( a1 == 131084 )
  {
    v6 = a3[204];
    goto LABEL_17;
  }
  if ( a1 == 131085 )
  {
    v6 = a3[80];
    goto LABEL_17;
  }
  if ( a1 != 131087 )
    goto LABEL_26;
  v6 = a3[236];
LABEL_17:
  v8 = *(_DWORD *)(a2 + 64);
  src = v6;
  if ( (unsigned int)hfi_util_u32_prop_helper_add_prop_by_obj(a4, a1, v8, 0, &src, 4u) )
    printk(&unk_2205CC, "_hfi_connector_add_base_prop_helper");
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v5 )
      v9 = *(_DWORD *)(*(_QWORD *)v5 + 64LL);
    else
      v9 = -1;
    _drm_dev_dbg(0, 0, 0, "conn%d done adding HFI prop:0x%x\n", v9, a1);
  }
  v4 = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v4;
}
