__int64 __fastcall qcom_glink_device_release(__int64 a1)
{
  int v8; // w8

  _X0 = (unsigned int *)(*(_QWORD *)(a1 + 968) + 120LL);
  __asm { PRFM            #0x11, [X0] }
  do
    v8 = __ldxr(_X0);
  while ( __stlxr(v8 - 1, _X0) );
  if ( v8 == 1 )
  {
    __dmb(9u);
    qcom_glink_channel_release((__int64)_X0);
  }
  else if ( v8 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  kfree(*(_QWORD *)(a1 + 952));
  return kfree(a1);
}
