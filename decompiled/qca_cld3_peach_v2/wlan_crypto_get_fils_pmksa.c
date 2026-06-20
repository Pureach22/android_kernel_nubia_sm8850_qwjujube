__int64 __fastcall wlan_crypto_get_fils_pmksa(__int64 a1, const void *a2, const void *a3, unsigned __int8 a4)
{
  __int64 comp_private_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  __int64 v17; // x23
  __int64 v18; // x8
  __int64 result; // x0

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
  {
    v16 = 0;
    v17 = comp_private_obj + 24;
    while ( 1 )
    {
      v18 = *(_QWORD *)(v17 + v16);
      if ( v18 )
      {
        if ( !(unsigned int)qdf_mem_cmp(a2, (const void *)(v18 + 120), 2u)
          && !(unsigned int)qdf_mem_cmp(a3, (const void *)(*(_QWORD *)(v17 + v16) + 88LL), a4) )
        {
          result = *(_QWORD *)(v17 + v16);
          if ( *(unsigned __int8 *)(result + 87) == a4 )
            break;
        }
      }
      v16 += 8;
      if ( v16 == 128 )
        return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: crypto_priv NULL", v8, v9, v10, v11, v12, v13, v14, v15, "wlan_crypto_get_fils_pmksa");
    return 0;
  }
  return result;
}
