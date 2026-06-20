__int64 __fastcall sme_set_thermal_mgmt(__int64 a1, __int16 a2, __int16 a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x22
  unsigned int v9; // w20
  __int64 v10; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v7 = _qdf_mem_malloc(0xCu, "sme_set_thermal_mgmt", 16866);
    if ( v7 )
    {
      v8 = v7;
      *(_WORD *)v7 = a2;
      *(_WORD *)(v7 + 2) = a3;
      *(_BYTE *)(v7 + 4) = 1;
      qdf_mem_set(&v10, 0x30u, 0);
      LODWORD(v10) = 4538;
      v11 = v8;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x34u,
                           0x36u,
                           54,
                           (unsigned __int16 *)&v10,
                           0x41F3u,
                           (__int64)"sme_set_thermal_mgmt") )
      {
        _qdf_mem_free(v8);
        v9 = 16;
      }
      else
      {
        v9 = 0;
      }
    }
    else
    {
      v9 = 2;
    }
    qdf_mutex_release(a1 + 12776);
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
