__int64 __fastcall dp_connector_add_custom_mode(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  __int64 v6; // [xsp+0h] [xbp-80h] BYREF
  __int64 v7; // [xsp+8h] [xbp-78h]
  __int64 v8; // [xsp+10h] [xbp-70h]
  __int64 v9; // [xsp+18h] [xbp-68h]
  __int64 v10; // [xsp+20h] [xbp-60h]
  __int64 v11; // [xsp+28h] [xbp-58h]
  __int64 v12; // [xsp+30h] [xbp-50h]
  __int64 v13; // [xsp+38h] [xbp-48h]
  __int64 v14; // [xsp+40h] [xbp-40h]
  __int64 v15; // [xsp+48h] [xbp-38h]
  __int64 v16; // [xsp+50h] [xbp-30h]
  __int64 v17; // [xsp+58h] [xbp-28h]
  __int64 v18; // [xsp+60h] [xbp-20h]
  __int64 v19; // [xsp+68h] [xbp-18h]
  __int64 v20; // [xsp+70h] [xbp-10h]
  __int64 v21; // [xsp+78h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  v6 = 0;
  convert_to_drm_mode(a2, (__int64)&v6);
  v3 = drm_mode_duplicate(*(_QWORD *)a1, &v6);
  if ( v3 )
  {
    *(_WORD *)(v3 + 58) = *(_DWORD *)(a1 + 216);
    *(_WORD *)(v3 + 60) = *(_DWORD *)(a1 + 220);
    drm_mode_probed_add(a1, v3);
    result = 1;
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to add mode %ux%u\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      WORD2(v6),
      HIWORD(v7));
    printk(&unk_2764B0, "dp_connector_add_custom_mode");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
