__int64 __fastcall timeline_fence_enable_signaling(__int64 a1)
{
  unsigned __int64 v1; // x9
  unsigned __int64 v2; // x8
  bool v3; // cc
  int v4; // w8
  unsigned int v5; // w9
  _BOOL4 v6; // w8

  v1 = *(_QWORD *)(a1 + 40);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 64) + 16LL);
  v3 = v1 > v2;
  v4 = v1 - v2;
  v5 = v3;
  v6 = v4 > 0;
  if ( **(_BYTE **)(a1 + 8) )
    return v5;
  else
    return v6;
}
