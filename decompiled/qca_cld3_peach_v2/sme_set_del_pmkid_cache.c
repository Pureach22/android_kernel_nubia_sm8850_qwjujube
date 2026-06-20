__int64 __fastcall sme_set_del_pmkid_cache(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  _DWORD *v8; // x0
  _DWORD *v9; // x19
  size_t v10; // x2
  __int64 result; // x0
  unsigned int v12; // w8
  int v13; // w9
  size_t v14; // x2
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v24; // [xsp+10h] [xbp-30h]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = nullptr;
  v8 = (_DWORD *)_qdf_mem_malloc(0x98u, "sme_set_del_pmkid_cache", 13941);
  if ( v8 )
  {
    v9 = v8;
    qdf_mem_set(v8, 0x98u, 0);
    *(_BYTE *)v9 = a2;
    if ( a3 )
    {
      if ( *(_BYTE *)(a3 + 87) )
      {
        v9[35] = 2;
        v10 = *(unsigned __int8 *)(a3 + 87);
        *((_BYTE *)v9 + 100) = v10;
        qdf_mem_copy((char *)v9 + 101, (const void *)(a3 + 88), v10);
      }
      else
      {
        v9[35] = 1;
        v9[23] = *(_DWORD *)a3;
        v9[24] = *(unsigned __int16 *)(a3 + 4);
      }
      v12 = *(unsigned __int16 *)(a3 + 120);
      if ( (a4 & 1) != 0 )
        v13 = 1;
      else
        v13 = 2;
      v9[36] = v13;
      v9[34] = __rev16(v12);
      v9[18] = 16;
      qdf_mem_copy(v9 + 19, (const void *)(a3 + 6), 0x10u);
      v14 = *(unsigned __int8 *)(a3 + 86);
      v9[1] = v14;
      qdf_mem_copy(v9 + 2, (const void *)(a3 + 22), v14);
    }
    else
    {
      *((_BYTE *)v9 + 148) = 1;
      csr_clear_sae_single_pmk(a1, a2, 0);
    }
    LODWORD(v23) = 4519;
    v24 = v9;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v23,
               0x36A5u,
               (__int64)"sme_set_del_pmkid_cache");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post message to WDA",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_set_del_pmkid_cache");
      qdf_mem_set(v9, 0x98u, 0);
      _qdf_mem_free((__int64)v9);
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
