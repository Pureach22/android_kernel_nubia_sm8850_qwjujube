__int64 __fastcall msm_vidc_queue_buffer_single(__int64 a1, __int64 a2)
{
  __int64 driver_buf; // x0
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v6; // x4
  __int64 v7; // x2
  unsigned int v8; // w19

  driver_buf = msm_vidc_get_driver_buf(a1, a2);
  if ( !driver_buf )
    return 4294967274LL;
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 168);
  if ( *((_DWORD *)v4 - 1) != -249828064 )
    __break(0x8228u);
  result = v4(a1, 8, driver_buf);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v7 = a1 + 340;
    v8 = result;
    printk(&unk_8427F, "err ", v7, "msm_vidc_queue_buffer_single", v6);
    return v8;
  }
  return result;
}
