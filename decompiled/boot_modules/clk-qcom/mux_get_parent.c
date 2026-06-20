__int64 __fastcall mux_get_parent(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x0
  __int64 v4; // x1
  unsigned __int64 v5; // x20
  __int64 v6; // x1
  unsigned int cfg_index; // w2
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 - 16);
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(unsigned int *)(a1 - 24);
  v9 = 0;
  v5 = 0xFFFFFFFFFFFFFFFFLL >> -(char)v2;
  regmap_read(v3, v4, &v9);
  v6 = *(_QWORD *)(a1 - 8);
  cfg_index = (v9 >> *(_DWORD *)(a1 - 20)) & v5;
  v9 = cfg_index;
  if ( v6 )
    cfg_index = qcom_find_cfg_index(a1);
  _ReadStatusReg(SP_EL0);
  return cfg_index;
}
