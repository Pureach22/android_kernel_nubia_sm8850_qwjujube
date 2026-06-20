__int64 __fastcall sde_hdcp_2x_clean(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v9; // w5
  __int64 *v10; // x20
  __int64 **v11; // x8
  __int64 *v12; // x9
  __int64 v13; // x1
  unsigned int v20; // w10
  int v21; // w7
  __int64 result; // x0
  char v23; // [xsp+0h] [xbp-40h]
  char v24; // [xsp+0h] [xbp-40h]
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 139);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_hdcp_2x_clean", 364, 8, 4369, v9, -1059143953, a8, v23);
  *(_BYTE *)(a1 + 139) = 0;
  v10 = *(__int64 **)(a1 + 192);
  v26 = *(_QWORD *)(a1 + 144);
  for ( LODWORD(v25) = 4; v10 != (__int64 *)(a1 + 192); v10 = *(__int64 **)(a1 + 192) )
  {
    v11 = (__int64 **)v10[1];
    if ( *v11 == v10 && (v12 = (__int64 *)*v10, *(__int64 **)(*v10 + 8) == v10) )
    {
      v12[1] = (__int64)v11;
      *v11 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(v10);
    }
    v13 = *((unsigned int *)v10 + 5);
    *v10 = 0xDEAD000000000100LL;
    v10[1] = 0xDEAD000000000122LL;
    hdcp2_close_stream(*(_QWORD *)(a1 + 152), v13);
    kfree(v10);
    --*(_BYTE *)(a1 + 208);
  }
  _X8 = (unsigned int *)(a1 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stlxr(1u, _X8) );
  __dmb(0xBu);
  if ( !v20 )
    sde_hdcp_2x_wakeup_client(a1, &v25);
  hdcp2_app_comm(*(_QWORD *)(a1 + 152), 2, a1 + 80);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_hdcp_2x_clean",
             386,
             8,
             8738,
             *(unsigned __int8 *)(a1 + 139),
             -1059143953,
             v21,
             v24);
  _ReadStatusReg(SP_EL0);
  return result;
}
