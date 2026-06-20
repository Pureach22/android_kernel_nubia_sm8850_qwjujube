__int64 __fastcall cnss_device_crashed(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 v9; // x9

  result = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( result )
  {
    _X8 = (unsigned __int64 *)(result + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 | 0x200, _X8) );
    return queue_work_on(32, system_wq, result + 688);
  }
  return result;
}
