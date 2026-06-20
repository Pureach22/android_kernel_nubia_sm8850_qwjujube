__int64 __fastcall sub_86844(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { PRFM            #0x1D, 0xEB93C }
  return _traceiter_drv_set_ringparam(a1, a2, a3, a4);
}
