__int64 *__fastcall nan_release_cmd(
        __int64 *result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v10; // x8
  __int64 *v11; // x19
  __int64 v12; // x4
  __int64 v13; // x0

  if ( result )
  {
    v10 = (unsigned int *)(a2 - 6);
    v11 = result;
    v12 = a2;
    if ( (unsigned int)v10 >= 5 )
    {
      qdf_trace_msg(0x53u, 2u, "%s: invalid req type: %d", a3, a4, a5, a6, a7, a8, a9, a10, "nan_release_cmd", a2);
    }
    else
    {
      v13 = *result;
      if ( *v11 )
      {
        wlan_objmgr_vdev_release_ref(v13, 0x14u, v10, a3, a4, a5, a6, a7, a8, a9, a10);
        return (__int64 *)_qdf_mem_free((__int64)v11);
      }
    }
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_release_cmd", v12);
    return (__int64 *)_qdf_mem_free((__int64)v11);
  }
  return result;
}
