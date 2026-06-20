__int64 __fastcall qdf_mc_timer_init(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  if ( a1 && a3 )
  {
    *(_DWORD *)(a1 + 48) = 0;
    *(_QWORD *)(a1 + 56) = 0;
    init_timer_key(a1, _os_mc_timer_shim, (unsigned __int8)(a2 == 0) << 19, 0, 0);
    *(_QWORD *)(a1 + 64) = a3;
    *(_QWORD *)(a1 + 72) = a4;
    *(_QWORD *)(a1 + 40) = 0x1234123400000000LL;
    *(_DWORD *)(a1 + 144) = a2;
    *(_DWORD *)(a1 + 148) = 19;
    return 0;
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: Null params being passed", "qdf_mc_timer_init");
    return 5;
  }
}
