__int64 __fastcall cnss_get_virt_ramdump_mem(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = cnss_bus_dev_to_plat_priv(a1, (__int64)a2);
  if ( result )
  {
    *a2 = *(_QWORD *)(result + 168);
    return *(_QWORD *)(result + 176);
  }
  return result;
}
