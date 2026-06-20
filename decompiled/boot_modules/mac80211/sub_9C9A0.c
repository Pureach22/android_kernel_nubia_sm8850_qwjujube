__int64 __fastcall sub_9C9A0(__int64 a1, int a2)
{
  int v2; // w16
  __int64 v3; // x19

  *(_DWORD *)(v3 + 208) = a2;
  *(_DWORD *)(v3 + 212) = v2;
  return _bpf_trace_drv_set_key();
}
