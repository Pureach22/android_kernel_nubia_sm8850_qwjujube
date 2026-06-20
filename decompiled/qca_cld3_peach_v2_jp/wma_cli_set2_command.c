__int64 __fastcall wma_cli_set2_command(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v10; // x0
  _DWORD *v11; // x20
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v14; // [xsp+10h] [xbp-30h]
  __int64 v15; // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = nullptr;
  v10 = (_DWORD *)_qdf_mem_malloc(0x14u, "wma_cli_set2_command", 1044);
  if ( v10 )
  {
    v11 = v10;
    qdf_mem_set(v10, 0x14u, 0);
    v11[2] = a4;
    v11[3] = a1;
    *v11 = a2;
    v11[1] = a3;
    v11[4] = a5;
    LODWORD(v13) = 4291;
    v14 = v11;
    result = scheduler_post_message_debug(
               0x36u,
               0x36u,
               54,
               (unsigned __int16 *)&v13,
               0x425u,
               (__int64)"wma_cli_set2_command");
    if ( (_DWORD)result )
    {
      _qdf_mem_free((__int64)v11);
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
