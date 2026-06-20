__int64 __fastcall hif_wlan_enable(__int64 a1)
{
  __int64 target_info_handle; // x20
  int conparam; // w21
  int v4; // w9
  unsigned int v5; // w8
  _DWORD *v6; // x8
  __int64 v7; // x0
  _QWORD *v8; // x1
  char *v9; // x2
  unsigned int v10; // w22
  unsigned int v11; // w21
  __int64 v12; // x22
  __int64 hw_name; // x0
  int v14; // w0
  __int64 v15; // x8
  int v16; // w19
  __int64 result; // x0
  __int64 v18; // [xsp+0h] [xbp-60h] BYREF
  __int64 v19; // [xsp+8h] [xbp-58h]
  __int64 v20; // [xsp+10h] [xbp-50h] BYREF
  __int64 v21; // [xsp+18h] [xbp-48h] BYREF
  __int64 v22; // [xsp+20h] [xbp-40h] BYREF
  void *v23; // [xsp+28h] [xbp-38h] BYREF
  __int64 v24; // [xsp+30h] [xbp-30h] BYREF
  _QWORD v25[2]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v26; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v27[2]; // [xsp+50h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  target_info_handle = hif_get_target_info_handle(a1);
  v26 = 0;
  v27[0] = 0;
  v25[0] = 0;
  v25[1] = 0;
  v23 = nullptr;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  conparam = hif_get_conparam(a1);
  v4 = *(_DWORD *)(a1 + 27408);
  v19 = *(_QWORD *)(a1 + 27392);
  LODWORD(v18) = v4;
  hif_select_service_to_pipe_map(a1, &v21, (int *)&v20);
  if ( &v23 )
    v23 = target_shadow_reg_cfg;
  if ( !&v22 )
    __break(1u);
  LODWORD(v22) = 9;
  LODWORD(v20) = (unsigned int)v20 / 0xC;
  v5 = *(_DWORD *)(target_info_handle + 4);
  LODWORD(v18) = (unsigned int)v18 / 0x18;
  if ( v5 <= 0x2B && ((1LL << v5) & 0xD6480000000LL) != 0 )
  {
    v6 = *(_DWORD **)(*(_QWORD *)(a1 + 30696) + 128LL);
    if ( !v6 )
      goto LABEL_10;
    v7 = a1;
    v8 = v27;
    v9 = (char *)&v26 + 4;
    if ( *(v6 - 1) != -1776167621 )
      __break(0x8228u);
  }
  else
  {
    v7 = a1;
    v8 = v25;
    v9 = (char *)&v24;
    v6 = *(_DWORD **)(*(_QWORD *)(a1 + 30696) + 112LL);
    if ( *(v6 - 1) != -1313209398 )
      __break(0x8228u);
  }
  ((void (__fastcall *)(__int64, _QWORD *, char *))v6)(v7, v8, v9);
LABEL_10:
  qdf_trace_msg(61, 5, "%s: v3: num_config %d", "hif_print_hal_shadow_register_cfg", HIDWORD(v26));
  if ( HIDWORD(v26) )
  {
    v10 = 0;
    do
    {
      qdf_trace_msg(
        61,
        5,
        "%s: i %d, val %x",
        "hif_print_hal_shadow_register_cfg",
        v10,
        *(_DWORD *)(v27[0] + 4LL * (int)v10));
      ++v10;
    }
    while ( v10 < HIDWORD(v26) );
  }
  if ( (unsigned int)(conparam - 5) > 5 )
    v11 = 0;
  else
    v11 = dword_9DD784[conparam - 5];
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL);
  hw_name = hif_get_hw_name(target_info_handle);
  v14 = pld_set_host_param(v12, hw_name);
  v15 = *(_QWORD *)(a1 + 576);
  v16 = v14;
  LODWORD(result) = pld_wlan_enable(*(_QWORD *)(v15 + 40), &v18, v11);
  _ReadStatusReg(SP_EL0);
  if ( v16 | (unsigned int)result )
    return 4294967274LL;
  else
    return (unsigned int)result;
}
