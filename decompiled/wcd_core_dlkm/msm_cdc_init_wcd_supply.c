__int64 __fastcall msm_cdc_init_wcd_supply(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 result; // x0
  __int64 device_by_node; // x0
  __int64 v8; // x8

  result = 4294967274LL;
  if ( a1 && a3 )
  {
    device_by_node = of_find_device_by_node(a1);
    if ( device_by_node )
    {
      *a3 = a2;
      a3[1] = device_by_node + 16;
      v8 = snd_soc_lookup_component();
      a3[2] = v8;
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
