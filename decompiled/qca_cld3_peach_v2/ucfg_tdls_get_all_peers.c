__int64 __fastcall ucfg_tdls_get_all_peers(__int64 a1, __int64 a2, int a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-38h] BYREF
  __int64 v10; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v11)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v11 = nullptr;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v6 = _qdf_mem_malloc(0x18u, "ucfg_tdls_get_all_peers", 884);
  if ( v6 )
  {
    *(_DWORD *)(v6 + 16) = a3;
    *(_QWORD *)v6 = a1;
    *(_QWORD *)(v6 + 8) = a2;
    v7 = v6;
    v10 = v6;
    v11 = tdls_process_cmd;
    LOWORD(v9) = 19;
    result = scheduler_post_message_debug(
               0x33u,
               0,
               72,
               (unsigned __int16 *)&v9,
               0x381u,
               (__int64)"ucfg_tdls_get_all_peers");
    if ( (_DWORD)result )
    {
      _qdf_mem_free(v7);
      result = 0;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
