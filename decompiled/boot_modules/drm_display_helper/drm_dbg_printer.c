__int64 __usercall drm_dbg_printer@<X0>(__int64 result@<X0>, _QWORD *a2@<X8>)
{
  a2[2] = result;
  *a2 = &_drm_printfn_dbg;
  a2[1] = 0;
  a2[3] = &loc_16070;
  a2[4] = "[dp_mst]";
  a2[5] = 8;
  return result;
}
