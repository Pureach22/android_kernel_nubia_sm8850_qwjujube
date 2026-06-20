__int64 __fastcall fastrpc_setup_service_locator(
        __int64 a1,
        const char *a2,
        const char *a3,
        const char *a4,
        unsigned int a5)
{
  const char **v10; // x24
  unsigned __int64 v11; // x0
  unsigned int v12; // w22
  __int64 v14; // x8

  if ( a5 < 5 )
  {
    v10 = (const char **)(a1 + 56LL * a5 + 51376);
    v11 = pdr_handle_alloc(fastrpc_pdr_cb, v10);
    if ( v11 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_8;
    if ( a5 != 4 )
    {
      v10[1] = a4;
      v10[2] = (const char *)v11;
      *v10 = a2;
      v10[6] = (const char *)a1;
      v11 = pdr_add_lookup();
      if ( v11 <= 0xFFFFFFFFFFFFF000LL )
      {
        dev_info(
          *(_QWORD *)(a1 + 168),
          "%s: pdr_add_lookup enabled for %s (%s, %s)\n",
          "fastrpc_setup_service_locator",
          a3,
          a2,
          a4);
        return 0;
      }
LABEL_8:
      v14 = *(_QWORD *)(a1 + 168);
      v12 = v11;
      dev_err(v14, "%s: failed for %s (%s, %s)with err %d\n", "fastrpc_setup_service_locator", a3, a2, a4, v11);
      return v12;
    }
  }
  __break(0x5512u);
  return fastrpc_pdr_cb();
}
