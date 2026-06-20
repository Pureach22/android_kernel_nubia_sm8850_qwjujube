__int64 __fastcall sde_connector_get_mode_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x9
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64, __int64, __int64 *); // x8
  __int64 v14; // x4
  __int64 result; // x0
  void *v16; // x0
  __int64 v17; // [xsp+0h] [xbp-30h] BYREF
  __int64 v18; // [xsp+8h] [xbp-28h]
  __int64 v19; // [xsp+10h] [xbp-20h]
  __int64 v20; // [xsp+18h] [xbp-18h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  if ( !a1 )
  {
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( *(_QWORD *)a1 && (v8 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
  {
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a1 + 2512);
      if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
        v11 = *(_QWORD *)(a1 + 2272);
      sde_rm_get_resource_info((_QWORD *)(v9 + 2144), v11, (__int64)&v17);
      v12 = *(_QWORD *)(v9 + 152);
      if ( (*(_BYTE *)(v12 + 21612) & 1) != 0 && *(_DWORD *)(a1 + 2736) == 10 )
        LODWORD(v18) = *(_DWORD *)(v12 + 10392);
      LODWORD(v20) = *(_DWORD *)(v12 + 21576);
      goto LABEL_12;
    }
    v16 = &unk_234896;
  }
  else
  {
    v16 = &unk_242658;
  }
  printk(v16, "sde_connector_get_kms");
  printk(&unk_234896, "sde_connector_get_avail_res_info");
LABEL_12:
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64 *))(a1 + 2952);
  v14 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v13 - 1) != 1336644395 )
    __break(0x8228u);
  result = v13(a1, a2, a3, a4, v14, &v17);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
