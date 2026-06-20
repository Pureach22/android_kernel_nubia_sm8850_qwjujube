__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (unsigned int)hdd_driver_load(a1, a2, a3, a4) )
    return 4294967274LL;
  else
    return 0;
}
