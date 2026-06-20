__int64 __fastcall wlan_crypto_free_key_by_link_id(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32[3]; // [xsp+8h] [xbp-18h] BYREF

  v32[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v32[1] = (__int64)v32;
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
  if ( result )
  {
    if ( *(_DWORD *)(result + 72) && *(_QWORD *)(result + 80) && *(_DWORD *)(result + 64) )
    {
      v14 = result;
      qdf_mutex_acquire(result);
      v15 = crypto_hash_find_by_linkid_and_macaddr(v14, a3, a2);
      if ( v15 )
      {
        crypto_remove_entry(v14, v15, (__int64)v32, v16, v17, v18, v19, v20, v21, v22, v23);
        crypto_free_list(v14, v32, v24, v25, v26, v27, v28, v29, v30, v31);
      }
      result = qdf_mutex_release(v14);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x1Cu,
               2u,
               "%s: crypto_psoc_obj NULL",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wlan_crypto_free_key_by_link_id");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
