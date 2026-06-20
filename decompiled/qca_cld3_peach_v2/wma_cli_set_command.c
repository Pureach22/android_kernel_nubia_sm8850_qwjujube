__int64 __fastcall wma_cli_set_command(int a1, int a2, int a3, int a4)
{
  _DWORD *v8; // x0
  _DWORD *v9; // x19
  __int64 result; // x0
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v12; // [xsp+10h] [xbp-30h]
  __int64 v13; // [xsp+18h] [xbp-28h]
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = nullptr;
  v8 = (_DWORD *)_qdf_mem_malloc(0x14u, "wma_cli_set2_command", 1044);
  if ( v8 )
  {
    v9 = v8;
    qdf_mem_set(v8, 0x14u, 0);
    v9[2] = 0;
    v9[3] = a1;
    *v9 = a2;
    v9[1] = a3;
    v9[4] = a4;
    LODWORD(v11) = 4291;
    v12 = v9;
    result = scheduler_post_message_debug(
               0x36u,
               0x36u,
               54,
               (unsigned __int16 *)&v11,
               0x425u,
               (__int64)"wma_cli_set2_command");
    if ( (_DWORD)result )
    {
      _qdf_mem_free((__int64)v9);
      result = 4294967291LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
