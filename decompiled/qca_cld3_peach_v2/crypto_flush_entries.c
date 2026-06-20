__int64 __fastcall crypto_flush_entries(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  unsigned int v3; // w20
  __int64 v4; // x1
  __int64 v5; // x21
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v6[1] = v6;
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
  if ( result )
  {
    v2 = result;
    if ( *(_DWORD *)(result + 72) )
    {
      if ( *(_QWORD *)(result + 80) && *(_DWORD *)(result + 64) )
      {
        qdf_mutex_acquire(result);
        v3 = 0;
        do
        {
          v4 = *(_QWORD *)(*(_QWORD *)(v2 + 80) + 16LL * v3);
          if ( v4 )
          {
            do
            {
              v5 = *(_QWORD *)(v4 + 152);
              crypto_remove_entry(v2);
              v4 = v5;
            }
            while ( v5 );
          }
          ++v3;
        }
        while ( v3 <= *(_DWORD *)(v2 + 72) );
        crypto_free_list(v2, v6);
        result = qdf_mutex_release(v2);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
