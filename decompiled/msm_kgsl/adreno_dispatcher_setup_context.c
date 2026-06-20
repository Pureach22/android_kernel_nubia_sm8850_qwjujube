__int64 __fastcall adreno_dispatcher_setup_context(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w8
  int v4; // w9
  unsigned int v5; // w8

  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
  {
    v2 = a1 + 14352;
LABEL_7:
    *(_QWORD *)(a2 + 1536) = v2;
    return 0;
  }
  v3 = *(_DWORD *)(a1 + 19632);
  v4 = *(_DWORD *)(a2 + 8) / v3;
  v5 = v3 - 1;
  if ( v4 < (int)v5 )
    v5 = v4;
  if ( v5 <= 4 )
  {
    v2 = a1 + 1320LL * v5 + 14352;
    goto LABEL_7;
  }
  __break(0x5512u);
  return trace_dispatch_queue_context(a1);
}
