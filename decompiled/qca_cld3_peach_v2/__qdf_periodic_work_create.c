__int64 __fastcall _qdf_periodic_work_create(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8

  v3 = 4;
  if ( a1 && a2 )
  {
    *(_QWORD *)a1 = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 8) = a1 + 8;
    *(_QWORD *)(a1 + 16) = a1 + 8;
    *(_QWORD *)(a1 + 24) = _qdf_periodic_work_handler;
    init_timer_key(a1 + 32, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3 = 0;
    *(_QWORD *)(a1 + 104) = a2;
    *(_QWORD *)(a1 + 112) = a3;
    *(_DWORD *)(a1 + 120) = 0;
  }
  return v3;
}
