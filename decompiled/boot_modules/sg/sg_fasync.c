__int64 __fastcall sg_fasync(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a2 + 32);
  if ( v3 && *(_QWORD *)(v3 + 16) )
    return fasync_helper(a1, a2, a3, v3 + 160);
  else
    return 4294967290LL;
}
