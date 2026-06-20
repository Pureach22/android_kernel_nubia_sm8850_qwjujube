__int64 __fastcall rndis_register(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  unsigned int v5; // w21
  __int64 result; // x0

  if ( !a1 )
    return -22;
  v4 = ida_alloc_range(&rndis_ida, 0, 999, 3264);
  if ( (v4 & 0x80000000) != 0 )
    return -19;
  v5 = v4;
  result = _kmalloc_cache_noprof(delayed_work_timer_fn, 3520, 104);
  if ( result )
  {
    *(_DWORD *)result = v5;
    *(_BYTE *)(result + 4) = 1;
    *(_DWORD *)(result + 20) = 1;
    *(_DWORD *)(result + 8) = 0;
    *(_QWORD *)(result + 64) = a1;
    *(_QWORD *)(result + 72) = a2;
    *(_QWORD *)(result + 80) = result + 80;
    *(_QWORD *)(result + 88) = result + 80;
    *(_DWORD *)(result + 96) = 0;
  }
  else
  {
    ida_free(&rndis_ida, v5);
    return -12;
  }
  return result;
}
