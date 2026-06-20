__int64 __fastcall sde_connector_mode_valid(__int64 *a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x9
  __int64 (__fastcall *v10)(__int64 *, __int64, __int64, __int64 *); // x8
  __int64 v11; // x2
  __int64 result; // x0
  void *v13; // x0
  __int64 v14; // [xsp+0h] [xbp-30h] BYREF
  __int64 v15; // [xsp+8h] [xbp-28h]
  __int64 v16; // [xsp+10h] [xbp-20h]
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    printk(&unk_21E0A6, "sde_connector_mode_valid");
    result = 0xFFFFFFFFLL;
    goto LABEL_21;
  }
  v4 = *a1;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  if ( v4 && (v5 = *(_QWORD *)(v4 + 56)) != 0 )
  {
    v6 = *(_QWORD *)(v5 + 8);
    if ( v6 )
    {
      v7 = a1[314];
      if ( !v7 || (v8 = *(_QWORD *)(v7 + 16)) == 0 )
        v8 = a1[284];
      sde_rm_get_resource_info((_QWORD *)(v6 + 2144), v8, (__int64)&v14);
      v9 = *(_QWORD *)(v6 + 152);
      if ( (*(_BYTE *)(v9 + 21612) & 1) != 0 && *((_DWORD *)a1 + 684) == 10 )
        LODWORD(v15) = *(_DWORD *)(v9 + 10392);
      LODWORD(v17) = *(_DWORD *)(v9 + 21576);
      v10 = (__int64 (__fastcall *)(__int64 *, __int64, __int64, __int64 *))a1[365];
      if ( v10 )
        goto LABEL_13;
LABEL_20:
      result = 0;
      goto LABEL_21;
    }
    v13 = &unk_234896;
  }
  else
  {
    v13 = &unk_242658;
  }
  printk(v13, "sde_connector_get_kms");
  printk(&unk_234896, "sde_connector_get_avail_res_info");
  v10 = (__int64 (__fastcall *)(__int64 *, __int64, __int64, __int64 *))a1[365];
  if ( !v10 )
    goto LABEL_20;
LABEL_13:
  v11 = a1[345];
  if ( *((_DWORD *)v10 - 1) != 1636779161 )
    __break(0x8228u);
  result = v10(a1, a2, v11, &v14);
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
