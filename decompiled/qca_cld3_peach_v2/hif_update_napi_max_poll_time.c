__int64 __fastcall hif_update_napi_max_poll_time(_QWORD *a1, __int64 a2, unsigned int a3)
{
  unsigned int v4; // w21
  __int64 result; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x9

  v4 = a2;
  result = sched_clock(a1, a2);
  if ( v4 > 0xB || a3 >= 0x20 )
  {
    __break(0x5512u);
    JUMPOUT(0x71B8E0);
  }
  v7 = *(_QWORD *)(*a1 + 8LL * v4 + 784) + 72LL * a3;
  v8 = result - a1[25];
  if ( v8 > *(_QWORD *)(v7 + 3192) )
    *(_QWORD *)(v7 + 3192) = v8;
  return result;
}
