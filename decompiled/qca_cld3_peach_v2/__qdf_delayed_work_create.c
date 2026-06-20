__int64 __fastcall _qdf_delayed_work_create(_QWORD *a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8

  v3 = 4;
  if ( a1 && a2 )
  {
    *a1 = 0xFFFFFFFE00000LL;
    a1[1] = a1 + 1;
    a1[2] = a1 + 1;
    a1[3] = _qdf_delayed_work_handler;
    init_timer_key(a1 + 4, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3 = 0;
    a1[13] = a2;
    a1[14] = a3;
  }
  return v3;
}
