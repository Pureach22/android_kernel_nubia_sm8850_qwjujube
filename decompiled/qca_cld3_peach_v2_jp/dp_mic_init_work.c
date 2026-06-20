__int64 __fastcall dp_mic_init_work(__int64 result)
{
  *(_DWORD *)(result + 3464) = 0;
  *(_QWORD *)(result + 3432) = dp_process_mic_error;
  *(_QWORD *)(result + 3400) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(result + 3472) = 0;
  *(_QWORD *)(result + 3440) = result;
  *(_QWORD *)(result + 3408) = result + 3408;
  *(_QWORD *)(result + 3416) = result + 3408;
  *(_QWORD *)(result + 3424) = _qdf_defer_func;
  *(_DWORD *)(result + 3448) = 1;
  *(_QWORD *)(result + 3456) = 0;
  return result;
}
