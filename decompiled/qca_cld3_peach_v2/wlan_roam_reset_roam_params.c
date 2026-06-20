char *__fastcall wlan_roam_reset_roam_params(
        char *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( (*((_DWORD *)result + 4) & 0xFFFFFFFD) == 0 )
  {
    result = (char *)cm_get_ext_hdl_fl(
                       (__int64)result,
                       (__int64)"wlan_roam_reset_roam_params",
                       0x6D0u,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9);
    if ( result )
    {
      result[1392] = 0;
      return (char *)qdf_mem_set(result + 1393, 0x108u, 0);
    }
  }
  return result;
}
