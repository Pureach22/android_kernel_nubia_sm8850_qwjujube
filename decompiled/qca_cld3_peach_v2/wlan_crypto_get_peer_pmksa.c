__int64 __fastcall wlan_crypto_get_peer_pmksa(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 v14; // x8
  __int64 result; // x0
  const char *v17; // x2

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      v12 = 0;
      v13 = comp_private_obj + 24;
      while ( 1 )
      {
        v14 = *(_QWORD *)(v13 + v12);
        if ( v14 )
        {
          if ( !*(_BYTE *)(a2 + 87) )
            goto LABEL_14;
          if ( !(unsigned int)qdf_mem_cmp(
                                (const void *)(a2 + 88),
                                (const void *)(v14 + 88),
                                *(unsigned __int8 *)(a2 + 87))
            && !(unsigned int)qdf_mem_cmp((const void *)(a2 + 120), (const void *)(*(_QWORD *)(v13 + v12) + 120LL), 2u) )
          {
            result = *(_QWORD *)(v13 + v12);
            goto LABEL_21;
          }
          if ( !*(_BYTE *)(a2 + 87) )
          {
LABEL_14:
            if ( *(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4) )
            {
              result = *(_QWORD *)(v13 + v12);
              if ( *(_DWORD *)a2 == *(_DWORD *)result
                && *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(result + 4) )
              {
                goto LABEL_21;
              }
            }
          }
        }
        v12 += 8;
        if ( v12 == 128 )
          goto LABEL_20;
      }
    }
    v17 = "%s: crypto_priv NULL";
  }
  else
  {
    v17 = "%s: pmksa is NULL";
  }
  qdf_trace_msg(0x1Cu, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_get_peer_pmksa");
LABEL_20:
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
