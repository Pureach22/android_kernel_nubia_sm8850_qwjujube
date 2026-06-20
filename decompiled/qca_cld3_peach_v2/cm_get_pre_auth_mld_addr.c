__int64 __fastcall cm_get_pre_auth_mld_addr(__int64 a1, unsigned __int8 *a2, void *a3)
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
  const void *v14; // x20
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7

  _ReadStatusReg(SP_EL0);
  result = lim_search_pre_auth_list(a1, a2);
  if ( result )
  {
    v14 = (const void *)(result + 601);
    if ( *(_DWORD *)(result + 601) | *(unsigned __int16 *)(result + 605) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Get mld addr from preauth list %02x:%02x:%02x:**:**:%02x",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "cm_get_pre_auth_mld_addr",
        *(unsigned __int8 *)(result + 601),
        *(unsigned __int8 *)(result + 602),
        *(unsigned __int8 *)(result + 603),
        *(unsigned __int8 *)(result + 606));
      result = (__int64)qdf_mem_copy(a3, v14, 6u);
    }
  }
  else
  {
    if ( a2 )
    {
      v15 = *a2;
      v16 = a2[1];
      v17 = a2[2];
      v18 = a2[5];
    }
    else
    {
      v17 = 0;
      v15 = 0;
      v16 = 0;
      v18 = 0;
    }
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Search pre-auth nodes failure %02x:%02x:%02x:**:**:%02x",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "cm_get_pre_auth_mld_addr",
               v15,
               v16,
               v17,
               v18);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
